/*  $Id: grid_control_thread.cpp 491506 2016-02-05 16:08:02Z sadyrovr $
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
 *   Government have not placed any restriction on its use or reproduction.
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
 * Authors:  Maxim Didenko, Dmitry Kazimirov
 *
 * File Description:
 *    NetSchedule Worker Node implementation
 */

#include <ncbi_pch.hpp>

#include "netschedule_api_impl.hpp"
#include "grid_worker_impl.hpp"
#include "grid_control_thread.hpp"

#include <connect/services/grid_globals.hpp>
#include <connect/services/grid_worker.hpp>

#include <corelib/ncbistre.hpp>
#include <corelib/ncbiapp.hpp>
#include <corelib/ncbi_process.hpp>

#include <math.h>


#define NCBI_USE_ERRCODE_X   ConnServ_WorkerNode

BEGIN_NCBI_SCOPE

/////////////////////////////////////////////////////////////////////////////
//
///@internal

class CGetVersionProcessor : public CWorkerNodeControlServer::IRequestProcessor
{
public:
    virtual void Process(const string& /*request*/,
                         CNcbiOstream& os,
                         CWorkerNodeControlServer* control_server)
    {
        const CVersion& version(control_server->GetWorkerNode().GetAppVersion());
        const CVersionInfo& version_info(version.GetVersionInfo());
        const SBuildInfo& build_info(version.GetBuildInfo());

        os << "OK:version=" << NStr::URLEncode(version_info.Print()) <<
                "&build_date=" << NStr::URLEncode(build_info.date) <<
                "&build_tag=" << NStr::URLEncode(build_info.tag) << "\n";
    }
};

class CAdminCmdProcessor : public CWorkerNodeControlServer::IRequestProcessor
{
public:
    virtual bool Authenticate(const string& host,
                              const string& /*auth*/,
                              const string& queue,
                              CNcbiOstream& os,
                              CWorkerNodeControlServer* control_server)
    {
        m_Host = host;
        size_t pos = m_Host.find_first_of(':');
        if (pos != string::npos) {
            m_Host = m_Host.substr(0, pos);
        }
        if (control_server->GetWorkerNode().IsHostInAdminHostsList(m_Host)) {
            return true;
        }
        os << "ERR:Shutdown access denied.\n";
        LOG_POST_X(10, Warning << "Shutdown access denied for host " << m_Host);
        return false;
    }

protected:
    string m_Host;
};

class CShutdownProcessor : public CAdminCmdProcessor
{
public:
    virtual void Process(const string& request,
                         CNcbiOstream& os,
                         CWorkerNodeControlServer* /*control_server*/)
    {
        if (request.find("SUICIDE") != NPOS) {
            LOG_POST_X(11, Warning <<
                "Shutdown request has been received from host: " << m_Host);
            LOG_POST_X(12, Warning << "Server is shutting down");
            CGridGlobals::GetInstance().KillNode();
        } else {
            CNetScheduleAdmin::EShutdownLevel level =
                CNetScheduleAdmin::eNormalShutdown;
            if (request.find("IMMEDIATE") != NPOS)
                level = CNetScheduleAdmin::eShutdownImmediate;
            os << "OK:\n";
            CGridGlobals::GetInstance().RequestShutdown(level);
            LOG_POST_X(13, "Shutdown request has been received from host " <<
                m_Host);
        }
    }
};

class CSuspendProcessor : public CAdminCmdProcessor
{
public:
    virtual void Process(const string& request, CNcbiOstream& os,
        CWorkerNodeControlServer* control_server)
    {
        bool pullback = NStr::Find(request.c_str(), "pullback") != NPOS;

        unsigned timeout = 0;
        SIZE_TYPE timeout_str = NStr::Find(request.c_str(), "timeout=");
        if (timeout_str != NPOS)
            timeout = NStr::StringToUInt(request.c_str() +
                    timeout_str + sizeof("timeout=") - 1,
                    NStr::fConvErr_NoThrow | NStr::fAllowTrailingSymbols);

        LOG_POST("Received SUSPEND request from " << m_Host <<
                " (pullback=" << (pullback ? "ON" : "OFF") <<
                ", timeout=" << timeout << ')');

        control_server->GetWorkerNode().Suspend(pullback, timeout);

        os << "OK:\n";
    }
};

class CResumeProcessor : public CAdminCmdProcessor
{
public:
    virtual void Process(const string& /*request*/, CNcbiOstream& os,
        CWorkerNodeControlServer* control_server)
    {
        control_server->GetWorkerNode().Resume();
        LOG_POST("Received RESUME request from " << m_Host);
        os << "OK:\n";
    }
};

class CGetStatisticsProcessor :
        public CWorkerNodeControlServer::IRequestProcessor
{
public:
    virtual void Process(const string& /*request*/,
                         CNcbiOstream& os,
                         CWorkerNodeControlServer* control_server)
    {
        CGridWorkerNode node(control_server->GetWorkerNode());
        const CVersion& version(control_server->GetWorkerNode().GetAppVersion());
        const CVersionInfo& version_info(version.GetVersionInfo());
        const SBuildInfo& build_info(version.GetBuildInfo());

        os << "OK:Application: " << node.GetAppName() <<
                "\nVersion: " << version_info.Print() <<
                "\nBuild date: " << build_info.date <<
                "\nBuild tag: " << build_info.tag << "\n";

        {{
            CMutexGuard guard(CNcbiApplication::GetInstanceMutex());
            CNcbiApplication* app = CNcbiApplication::Instance();
            if (app)
                os << "Executable path: " << app->GetProgramExecutablePath()
                        << "\nPID: " << CProcess::GetCurrentPid() << "\n";
        }}

        CNetScheduleAPI ns_api(node.GetNetScheduleAPI());

        os << "Host name: " << CSocketAPI::gethostname() <<
                "\nControl port: " << control_server->GetControlPort() <<
                "\nUser name: " << GetDiagContext().GetUsername() <<
                "\nNetCache client name: " << node.GetNetCacheAPI().
                        GetService()->GetClientName() <<
                "\nNetSchedule client name: " << node->GetClientName() <<
                "\nQueue name: " << node->GetQueueName() <<
                "\nNode ID: " << ns_api->m_ClientNode <<
                "\nNode session: " << ns_api->m_ClientSession <<
                "\nMaximum job threads: " << node.GetMaxThreads() << "\n";

        if (node.IsSuspended())
            os << "The node is suspended\n";

        if (CGridGlobals::GetInstance().IsShuttingDown())
            os << "The node is shutting down\n";

        if (node->IsExclusiveMode())
            os << "The node is processing an exclusive job\n";

        CGridGlobals::GetInstance().GetJobWatcher().Print(os);

        os << "NetSchedule service: " <<
                ns_api.GetService().GetServiceName() << "\n";

        os << "NetSchedule servers:";
        try {
            for (CNetServiceIterator it = ns_api.GetService().
                    Iterate(CNetService::eIncludePenalized); it; ++it)
                os << ' ' << (*it).GetServerAddress();
            os << "\n";
        }
        catch (CNetSrvConnException&) {
            os << " N/A\n";
        }

        os << "Preferred affinities:";
        CNetScheduleExecutor ns_executor(node.GetNSExecutor());
        CFastMutexGuard guard(ns_executor->m_PreferredAffMutex);
        ITERATE(set<string>, aff, ns_executor->m_PreferredAffinities) {
            os << ' ' << *aff;
        }
        os << "\n";

        os << "OK:END\n";
    }
};

class CGetLoadProcessor : public CWorkerNodeControlServer::IRequestProcessor
{
public:
    virtual bool Authenticate(const string& host,
                              const string& auth,
                              const string& queue,
                              CNcbiOstream& os,
                              CWorkerNodeControlServer* control_server)
    {
        CGridWorkerNode node(control_server->GetWorkerNode());

        if (NStr::FindCase(auth, node->GetClientName()) == NPOS) {
            os <<"ERR:Wrong client name. Required: " <<
                    node->GetClientName() << "\n";
            return false;
        }

        CTempString qname, connection_info;
        NStr::SplitInTwo(queue, ";", qname, connection_info);
        if (qname != node->GetQueueName()) {
            os << "ERR:Wrong queue name. Required: " <<
                    node->GetQueueName() << "\n";
            return false;
        }

        return true;
    }

    virtual void Process(const string& /*request*/,
                         CNcbiOstream& os,
                         CWorkerNodeControlServer* control_server)
    {
        int load = control_server->GetWorkerNode().GetMaxThreads() -
            CGridGlobals::GetInstance().GetJobWatcher().GetJobsRunningNumber();
        os << "OK:" << load << "\n";
    }
};

class CUnknownProcessor : public CWorkerNodeControlServer::IRequestProcessor
{
public:
    virtual void Process(const string& request,
                         CNcbiOstream& os,
                         CWorkerNodeControlServer* /*control_server*/)
    {
        os << "ERR:Unknown command -- " << request << "\n";
    }
};

/////////////////////////////////////////////////////////////////////////////
//
///@internal

/* static */
CWorkerNodeControlServer::IRequestProcessor*
    CWorkerNodeControlServer::MakeProcessor(const string& cmd)
{
    if (NStr::StartsWith(cmd, TEMP_STRING_CTOR("VERSION")))
        return new CGetVersionProcessor;

    if (NStr::StartsWith(cmd, TEMP_STRING_CTOR("STAT")))
        return new CGetStatisticsProcessor;

    if (NStr::StartsWith(cmd, TEMP_STRING_CTOR("SHUTDOWN")))
        return new CShutdownProcessor;

    if (NStr::StartsWith(cmd, TEMP_STRING_CTOR("SUSPEND")))
        return new CSuspendProcessor;

    if (NStr::StartsWith(cmd, TEMP_STRING_CTOR("RESUME")))
        return new CResumeProcessor;

    if (NStr::StartsWith(cmd, TEMP_STRING_CTOR("GETLOAD")))
        return new CGetLoadProcessor;

    return new CUnknownProcessor;
}

class CWNCTConnectionFactory : public IServer_ConnectionFactory
{
public:
    CWNCTConnectionFactory(CWorkerNodeControlServer& server,
        unsigned short& start_port, unsigned short end_port)
        : m_Server(server), m_Port(start_port), m_EndPort(end_port)
    {}
    virtual IServer_ConnectionHandler* Create(void) {
        return new CWNCTConnectionHandler(m_Server);
    }
    virtual EListenAction OnFailure(unsigned short* port)
    {
        if (*port >= m_EndPort)
            return eLAFail;
        m_Port = ++(*port);
        return eLARetry;
    }

private:
    CWorkerNodeControlServer& m_Server;
    unsigned short& m_Port;
    unsigned short m_EndPort;
};

static STimeout kAcceptTimeout = {1,0};

CWorkerNodeControlServer::CWorkerNodeControlServer(
    SGridWorkerNodeImpl* worker_node,
    unsigned short start_port,
    unsigned short end_port) :
        m_WorkerNode(worker_node),
        m_ShutdownRequested(false),
        m_Port(start_port)
{
    SServer_Parameters params;
    params.init_threads = 1;
    params.max_threads = 3;
    params.accept_timeout = &kAcceptTimeout;
    SetParameters(params);
    AddListener(new CWNCTConnectionFactory(*this, m_Port, end_port), m_Port);
}

CWorkerNodeControlServer::~CWorkerNodeControlServer()
{
    LOG_POST_X(14, Info << "Control server stopped.");
}
bool CWorkerNodeControlServer::ShutdownRequested(void)
{
    return m_ShutdownRequested;
}

void CWorkerNodeControlServer::ProcessTimeout(void)
{
    CGridGlobals::GetInstance().GetJobWatcher().CheckForInfiniteLoop();
}



////////////////////////////////////////////////
static string s_ReadStrFromBUF(BUF buf)
{
    size_t size = BUF_Size(buf);
    string ret(size, '\0');
    if (size > 0)
        BUF_Read(buf, &ret[0], size);
    return ret;
}

CWNCTConnectionHandler::CWNCTConnectionHandler(CWorkerNodeControlServer& server)
    : m_Server(server)
{}

CWNCTConnectionHandler::~CWNCTConnectionHandler()
{}

void CWNCTConnectionHandler::OnOpen(void)
{
    CSocket& socket = GetSocket();
    socket.DisableOSSendDelay();
    m_ProcessMessage = &CWNCTConnectionHandler::x_ProcessAuth;

}

static void s_HandleError(CSocket& socket, const string& msg)
{
    ERR_POST_X(15, "Exception in the control server: " << msg);
    string err = "ERR:" + NStr::PrintableString(msg);
    socket.Write(&err[0], err.size());
}
void CWNCTConnectionHandler::OnMessage(BUF buffer)
{
    try {
        (this->*m_ProcessMessage)(buffer);
    } catch(exception& ex) {
        s_HandleError(GetSocket(), ex.what());
    } catch(...) {
        s_HandleError(GetSocket(), "Unknown Error");
    }
}

void CWNCTConnectionHandler::x_ProcessAuth(BUF buffer)
{
    m_Auth = s_ReadStrFromBUF(buffer);
    m_ProcessMessage = &CWNCTConnectionHandler::x_ProcessQueue;
}
void CWNCTConnectionHandler::x_ProcessQueue(BUF buffer)
{
    m_Queue = s_ReadStrFromBUF(buffer);
    m_ProcessMessage = &CWNCTConnectionHandler::x_ProcessRequest;
}
void CWNCTConnectionHandler::x_ProcessRequest(BUF buffer)
{
    string request = s_ReadStrFromBUF(buffer);

    CSocket& socket = GetSocket();
    string host = socket.GetPeerAddress();

    CNcbiOstrstream os;

    auto_ptr<CWorkerNodeControlServer::IRequestProcessor>
            processor(m_Server.MakeProcessor(request));

    if (processor->Authenticate(host, m_Auth, m_Queue, os, &m_Server))
        processor->Process(request, os, &m_Server);

    string s = CNcbiOstrstreamToString(os);
    socket.Write(s.data(), s.size());
}

END_NCBI_SCOPE
