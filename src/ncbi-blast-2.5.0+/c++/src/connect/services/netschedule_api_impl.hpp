#ifndef CONN_SERVICES___NETSCHEDULE_API_IMPL__HPP
#define CONN_SERVICES___NETSCHEDULE_API_IMPL__HPP

/*  $Id: netschedule_api_impl.hpp 507304 2016-07-18 16:15:49Z sadyrovr $
 * ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 * Authors:  Anatoliy Kuznetsov, Maxim Didenko, Victor Joukov, Dmitry Kazimirov
 *
 * File Description:
 *   NetSchedule client API implementation details.
 *
 */

#include "netservice_api_impl.hpp"
#include "netschedule_api_getjob.hpp"

#include <corelib/request_ctx.hpp>

#include <connect/services/netschedule_api.hpp>
#include <connect/services/error_codes.hpp>

#include <list>
#include <map>
#include <vector>


BEGIN_NCBI_SCOPE


////////////////////////////////////////////////////////////////////////////////
//

#define SERVER_PARAMS_ASK_MAX_COUNT 100

inline
void g_AppendHitID(string& cmd, const string& sub_hit_id =
        CDiagContext::GetRequestContext().GetCurrentSubHitID())
{
    cmd += " ncbi_phid=\"";
    cmd += sub_hit_id;
    cmd += '"';
}

inline
bool g_AppendClientIPAndSessionID(string& cmd,
    const CRequestContext& req = CDiagContext::GetRequestContext())
{
    if (req.IsSetClientIP()) {
        cmd += " ip=\"";
        cmd += req.GetClientIP();
        cmd += '"';
    }

    if (req.IsSetSessionID()) {
        cmd += " sid=\"";
        cmd += NStr::PrintableString(req.GetSessionID());
        cmd += '"';
        return true;
    }

    return false;
}


bool g_ParseGetJobResponse(CNetScheduleJob& job, const string& response);

inline string g_MakeBaseCmd(const string& cmd_name, const string& job_key)
{
    string cmd(cmd_name);
    cmd += ' ';
    cmd += job_key;
    return cmd;
}

struct SNetScheduleServerProperties : public INetServerProperties
{
    SNetScheduleServerProperties() :
        affs_synced(false)
    {
    }

    string ns_node;
    string ns_session;

    // Warning:
    // Version is not set until we execute a command on a server.
    // Therefore, if that command is version dependent,
    // old version of the command will be sent to the server at first.
    CVersionInfo version;

    bool affs_synced;
};

class CNetScheduleConfigLoader
{
    class CErrorSuppressor;

public:
    CNetScheduleConfigLoader(
            const CTempString& prefix,
            const CTempString& section);

    CConfig* Get(SNetScheduleAPIImpl* impl, CConfig* config, string& section);

protected:
    virtual bool Transform(const CTempString& prefix, string& name);

private:
    typedef CNetScheduleAPI::TQueueParams TParams;
    CConfig* Parse(const TParams& params, const CTempString& prefix);

    const CTempString m_Prefix;
    const CTempString m_Section;
};

class CNetScheduleOwnConfigLoader : public CNetScheduleConfigLoader
{
public:
    CNetScheduleOwnConfigLoader();

protected:
    bool Transform(const CTempString& prefix, string& name);
};

class CNetScheduleServerListener : public INetServerConnectionListener
{
private:
    enum EMode {
        fWnCompatible       = (0 << 0),
        fNonWnCompatible    = (1 << 0),
        fConfigLoading      = (1 << 1) | fNonWnCompatible,
    };
    typedef int TMode;

public:
    CNetScheduleServerListener() :
        m_ClientType(CNetScheduleAPI::eCT_Auto),
        m_Mode(fConfigLoading)
    {
    }

    CNetScheduleServerListener(bool wn_compatible) :
        m_ClientType(CNetScheduleAPI::eCT_Auto),
        m_Mode(wn_compatible ? fWnCompatible : fNonWnCompatible)
    {
    }

    void SetAuthString(SNetScheduleAPIImpl* impl);

    bool NeedToSubmitAffinities(SNetServerImpl* server_impl);
    void SetAffinitiesSynced(SNetServerImpl* server_impl, bool affs_synced);

    static CRef<SNetScheduleServerProperties> x_GetServerProperties(
            SNetServerImpl* server_impl);

    virtual CRef<INetServerProperties> AllocServerProperties();

    virtual void OnInit(CObject* api_impl,
        CConfig* config, const string& config_section);
    virtual void OnConnected(CNetServerConnection& connection);
    virtual void OnError(const string& err_msg, CNetServer& server);
    virtual void OnWarning(const string& warn_msg, CNetServer& server);

    string m_Auth;
    CRef<INetEventHandler> m_EventHandler;

    CFastMutex m_ServerByNodeMutex;
    typedef map<string, SNetServerInPool*> TServerByNode;
    TServerByNode m_ServerByNode;

    // Make sure the worker node does not attempt to submit its
    // preferred affinities from two threads.
    CFastMutex m_AffinitySubmissionMutex;

    CNetScheduleAPI::EClientType m_ClientType;

private:
    const TMode m_Mode;
    string m_Scope;
};

// Structure that governs NetSchedule server notifications.
struct SServerNotifications
{
    SServerNotifications() :
        m_NotificationSemaphore(0, 1),
        m_Interrupted(false)
    {
    }

    bool Wait(const CDeadline& deadline)
    {
        return m_NotificationSemaphore.TryWait(deadline.GetRemainingTime());
    }

    void InterruptWait();

    void RegisterServer(const string& ns_node);

    bool GetNextNotification(string* ns_node);

private:
    void x_ClearInterruptFlag()
    {
        if (m_Interrupted) {
            m_Interrupted = false;
            m_NotificationSemaphore.TryWait();
        }
    }
    // Semaphore that the worker node or the job reader can wait on.
    // If count=0 then m_ReadyServers is empty and m_Interrupted=false;
    // if count=1 then at least one server is ready or m_Interrupted=true.
    CSemaphore m_NotificationSemaphore;
    // Protection against concurrent access to m_ReadyServers.
    CFastMutex m_Mutex;
    // A set of NetSchedule node IDs of the servers that are ready.
    // (i.e. the servers have sent notifications).
    typedef set<string> TReadyServers;
    TReadyServers m_ReadyServers;
    // This flag is set when the wait must be interrupted.
    bool m_Interrupted;
};

struct SNetScheduleNotificationThread : public CThread
{
    SNetScheduleNotificationThread(SNetScheduleAPIImpl* ns_api);

    enum ENotificationType {
        eNT_GetNotification,
        eNT_ReadNotification,
        eNT_Unknown,
    };
    ENotificationType CheckNotification(string* ns_node);

    virtual void* Main();

    unsigned short GetPort() const {return m_UDPPort;}

    const string& GetMessage() const {return m_Message;}

    void PrintPortNumber();

    void CmdAppendPortAndTimeout(string* cmd, unsigned remaining_seconds);

    SNetScheduleAPIImpl* m_API;

    CDatagramSocket m_UDPSocket;
    unsigned short m_UDPPort;

    char m_Buffer[1024];
    string m_Message;

    bool m_StopThread;

    SServerNotifications m_GetNotifications;
    SServerNotifications m_ReadNotifications;
};

struct SNetScheduleAPIImpl : public CObject
{
    SNetScheduleAPIImpl(CConfig* config, const string& section,
        const string& service_name, const string& client_name,
        const string& queue_name);

    SNetScheduleAPIImpl(const string& service_name, const string& client_name,
        const string& queue_name, bool wn_compatible);

    // Special constructor for CNetScheduleAPI::GetServer().
    SNetScheduleAPIImpl(SNetServerInPool* server, SNetScheduleAPIImpl* parent);

    ~SNetScheduleAPIImpl();

    CNetScheduleServerListener* GetListener()
    {
        return static_cast<CNetScheduleServerListener*>(
                m_Service->m_Listener.GetPointer());
    }

    string x_ExecOnce(const string& cmd_name, const CNetScheduleJob& job)
    {
        string cmd(g_MakeBaseCmd(cmd_name, job.job_id));
        g_AppendClientIPSessionIDHitID(cmd);

        CNetServer::SExecResult exec_result;

        GetServer(job)->ConnectAndExec(cmd, false, exec_result);

        return exec_result.response;
    }

    CNetScheduleAPI::EJobStatus GetJobStatus(const string& cmd,
            const CNetScheduleJob& job, time_t* job_exptime,
            ENetScheduleQueuePauseMode* pause_mode);

    const CNetScheduleAPI::SServerParams& GetServerParams();

    typedef CNetScheduleAPI::TQueueParams TQueueParams;
    void GetQueueParams(const string& queue_name, TQueueParams& queue_params);
    void GetQueueParams(TQueueParams& queue_params);

    CNetServer GetServer(const string& job_key)
    {
        CNetScheduleKey nskey(job_key, m_CompoundIDPool);
        return m_Service.GetServer(nskey.host, nskey.port);
    }

    CNetServer GetServer(const CNetScheduleJob& job)
    {
        return job.server != NULL ? job.server : GetServer(job.job_id);
    }

    bool GetServerByNode(const string& ns_node, CNetServer* server);

    static void VerifyJobGroupAlphabet(const string& job_group)
    {
        g_VerifyAlphabet(job_group, "job group name", eCC_BASE64_PI);
    }

    static void VerifyAuthTokenAlphabet(const string& auth_token)
    {
        g_VerifyAlphabet(auth_token, "security token", eCC_BASE64_PI);
    }

    static void VerifyAffinityAlphabet(const string& affinity)
    {
        g_VerifyAlphabet(affinity, "affinity token", eCC_BASE64_PI);
    }

    static void VerifyQueueNameAlphabet(const string& queue_name);

    void AllocNotificationThread();
    void StartNotificationThread();

    // Unregister client-listener. After this call, the
    // server will not try to send any notification messages or
    // maintain job affinity for the client.
    void x_ClearNode();

    void UpdateAuthString();
    void UseOldStyleAuth();
    void SetAuthParam(const string& param_name, const string& param_value);
    CCompoundIDPool GetCompoundIDPool() { return m_CompoundIDPool; }

    CNetService m_Service;

    string m_Queue;
    string m_ProgramVersion;
    string m_ClientNode;
    string m_ClientSession;

    typedef map<string, string> TAuthParams;
    TAuthParams m_AuthParams;

    auto_ptr<CNetScheduleAPI::SServerParams> m_ServerParams;
    long m_ServerParamsAskCount;
    CFastMutex m_FastMutex;

    CNetScheduleExecutor::EJobAffinityPreference m_AffinityPreference;
    list<string> m_AffinityList;

    CNetScheduleGetJob::TAffinityLadder m_AffinityLadder;

    string m_JobGroup;
    unsigned m_JobTtl;

    bool m_UseEmbeddedStorage;

    CCompoundIDPool m_CompoundIDPool;

    CFastMutex m_NotificationThreadMutex;
    CRef<SNetScheduleNotificationThread> m_NotificationThread;
    CAtomicCounter_WithAutoInit m_NotificationThreadStartStopCounter;
};


struct SNetScheduleSubmitterImpl : public CObject
{
    SNetScheduleSubmitterImpl(CNetScheduleAPI::TInstance ns_api_impl);

    string SubmitJobImpl(CNetScheduleNewJob& job, unsigned short udp_port,
            unsigned wait_time, CNetServer* server = NULL);

    void FinalizeRead(const char* cmd_start,
        const char* cmd_name,
        const string& job_id,
        const string& auth_token,
        const string& error_message);

    CNetScheduleAPI::EJobStatus SubmitJobAndWait(CNetScheduleJob& job,
            unsigned wait_time, time_t* job_exptime = NULL);

    CNetScheduleAPI m_API;

    SUseNextSubHitID m_UseNextSubHitID;
};

inline SNetScheduleSubmitterImpl::SNetScheduleSubmitterImpl(
    CNetScheduleAPI::TInstance ns_api_impl) :
    m_API(ns_api_impl)
{
}

struct SNetScheduleExecutorImpl : public CObject
{
    SNetScheduleExecutorImpl(CNetScheduleAPI::TInstance ns_api_impl) :
        m_API(ns_api_impl),
        m_AffinityPreference(ns_api_impl->m_AffinityPreference),
        m_JobGroup(ns_api_impl->m_JobGroup),
        m_WorkerNodeMode(false)
    {
        copy(ns_api_impl->m_AffinityList.begin(),
             ns_api_impl->m_AffinityList.end(),
             inserter(m_PreferredAffinities, m_PreferredAffinities.end()));
    }

    void ClaimNewPreferredAffinity(CNetServer orig_server,
        const string& affinity);
    string MkSETAFFCmd();
    bool ExecGET(SNetServerImpl* server,
            const string& get_cmd, CNetScheduleJob& job);
    bool x_GetJobWithAffinityList(SNetServerImpl* server,
            const CDeadline* timeout,
            CNetScheduleJob& job,
            CNetScheduleExecutor::EJobAffinityPreference affinity_preference,
            const string& affinity_list);
    bool x_GetJobWithAffinityLadder(SNetServerImpl* server,
            const CDeadline& timeout,
            const string& prio_aff_list,
            CNetScheduleJob& job);

    void ExecWithOrWithoutRetry(const CNetScheduleJob& job, const string& cmd);
    void ReturnJob(const CNetScheduleJob& job, bool blacklist = true);

    enum EChangeAffAction {
        eAddAffs,
        eDeleteAffs
    };
    int AppendAffinityTokens(string& cmd,
            const vector<string>* affs, EChangeAffAction action);

    CNetScheduleAPI m_API;

    CNetScheduleExecutor::EJobAffinityPreference m_AffinityPreference;

    CNetScheduleNotificationHandler m_NotificationHandler;

    CFastMutex m_PreferredAffMutex;
    set<string> m_PreferredAffinities;

    string m_JobGroup;

    // True when this object is used by a real
    // worker node application (CGridWorkerNode).
    bool m_WorkerNodeMode;
};

class CNetScheduleGETCmdListener : public INetServerExecListener
{
public:
    CNetScheduleGETCmdListener(SNetScheduleExecutorImpl* executor) :
        m_Executor(executor)
    {
    }

    virtual void OnExec(CNetServerConnection::TInstance conn_impl,
            const string& cmd);

    SNetScheduleExecutorImpl* m_Executor;
};

const unsigned s_Timeout = 10;

struct SNetScheduleJobReaderImpl : public CObject
{
    SNetScheduleJobReaderImpl(CNetScheduleAPI::TInstance ns_api_impl,
            const string& group, const string& affinity) :
        m_Impl(ns_api_impl, group, affinity),
        m_Timeline(m_Impl)
    {
    }

    void x_StartNotificationThread()
    {
        m_Impl.m_API->StartNotificationThread();
    }

    void SetJobGroup(const string& group_name);
    void SetAffinity(const string& affinity);
    CNetScheduleJobReader::EReadNextJobResult ReadNextJob(
        CNetScheduleJob* job,
        CNetScheduleAPI::EJobStatus* job_status,
        const CTimeout* timeout);
    void InterruptReading();

private:
    class CImpl : public CNetScheduleGetJob
    {
    public:
        CImpl(CNetScheduleAPI::TInstance ns_api_impl,
                const string& group, const string& affinity) :
            m_API(ns_api_impl),
            m_Timeout(s_Timeout),
            m_JobGroup(group),
            m_Affinity(affinity),
            m_MoreJobs(false)
        {
            SNetScheduleAPIImpl::VerifyJobGroupAlphabet(group);
            SNetScheduleAPIImpl::VerifyAffinityAlphabet(affinity);
        }

        EState CheckState();
        CNetServer ReadNotifications();
        CNetServer WaitForNotifications(const CDeadline& deadline);
        bool MoreJobs(const SEntry& entry);
        bool CheckEntry(
                SEntry& entry,
                const string& prio_aff_list,
                CNetScheduleJob& job,
                CNetScheduleAPI::EJobStatus* job_status);
        void ReturnJob(CNetScheduleJob& job);

        CNetScheduleAPI m_API;
        const unsigned m_Timeout;
        string m_JobGroup;
        string m_Affinity;

    private:
        bool m_MoreJobs;
    };

    CImpl m_Impl;
    CNetScheduleGetJobImpl<CImpl> m_Timeline;
};

struct SNetScheduleAdminImpl : public CObject
{
    SNetScheduleAdminImpl(CNetScheduleAPI::TInstance ns_api_impl) :
        m_API(ns_api_impl)
    {
    }

    CNetScheduleAPI m_API;
};

END_NCBI_SCOPE


#endif  /* CONN_SERVICES___NETSCHEDULE_API_IMPL__HPP */
