#ifndef CGI___NCBICGIR__HPP
#define CGI___NCBICGIR__HPP

/*  $Id: ncbicgir.hpp 500790 2016-05-09 11:30:33Z ivanov $
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
 * Authors:  Eugene Vasilchenko, Denis Vakatov
 *
 * File Description:
 *   CCgiResponse  -- CGI response generator class
 *
 */

#include <cgi/ncbicgi.hpp>
#include <corelib/ncbitime.hpp>
#include <util/retry_ctx.hpp>
#include <map>


/** @addtogroup CGIReqRes
 *
 * @{
 */


BEGIN_NCBI_SCOPE

class CCgiSession;
class CCgiStreamWrapper;

class NCBI_XCGI_EXPORT CCgiResponse
{
public:
    /// @note
    ///  By default set output stream to "cout" and file descr to STDOUT_FILENO
    CCgiResponse(CNcbiOstream* os = NULL, int ofd = -1);
    //
    ~CCgiResponse(void);

    // Set/get the "raw CGI" response type
    void SetRawCgi(bool is_raw);
    bool IsRawCgi(void) const;

    // Set response status.
    // NOTE:  use this method rather than SetHeaderValue("Status", ...)
    //        as it is safer and it works for the "raw CGI" response type, too.
    void SetStatus(unsigned int code, const string& reason = kEmptyStr);

    // Header setters
    void SetHeaderValue   (const string& name, const string&    value);
    void SetHeaderValue   (const string& name, const struct tm& value);
    void SetHeaderValue   (const string& name, const CTime&     value);
    void RemoveHeaderValue(const string& name);

    // Header getter
    string GetHeaderValue (const string& name) const;
    bool   HaveHeaderValue(const string& name) const;

    /// Set content type (text/html by default if not provided)
    void   SetContentType(const string& type);

    /// Get content type
    string GetContentType(void) const;

    // Set filename for undisplayable content; please include an
    // appropriate extension, and don't bother with directory
    // components (which clients generally discard).  Add a size
    // parameter if the corresponding (optional) argument is nonzero.
    void   SetFilename(const string& name, size_t size = 0);

    /// Set the "Location:" HTTP header
    void   SetLocation(const CUrl& url, const IUrlEncoder* encoder = 0);

    // Various styles of multipart responses, none of which is
    // universally supported. :-/
    enum EMultipartMode
    {
        eMultipart_none, // default (just a single part)
        eMultipart_mixed,
        eMultipart_related,
        eMultipart_replace // push-style refreshing
    };
    void           SetMultipartMode(EMultipartMode mode = eMultipart_mixed);
    EMultipartMode GetMultipartMode(void);

    void BeginPart  (const string& name, const string& type, size_t size = 0);
    void EndPart    (void);
    void EndLastPart(void);

    void BeginPart  (const string& name, const string& type, CNcbiOstream& os,
                     size_t size = 0);
    void EndPart    (CNcbiOstream& os);
    void EndLastPart(CNcbiOstream& os);

    // Get cookies set
    const CCgiCookies& Cookies(void) const;
    CCgiCookies&       Cookies(void);

    /// Set output stream (NULL here means "no output stream").
    /// This does not flush the previous stream (if any), so some
    /// data may be lost.
    void SetOutput(CNcbiOstream* os, int fd = -1);

    /// Get output stream (NULL here means "no output stream").
    /// 
    /// @attention
    ///  If the output stream is in a "bad" state and the
    ///  SetThrowOnBadOutput() is set to TRUE, then:
    ///   - a warning will be posted
    ///   - SetThrowOnBadOutput(false) will be called 
    CNcbiOstream* GetOutput(void) const;

    /// Get file descriptor of the output stream (-1 if not applicable)
    int GetOutputFD(void) const;

    /// Get output stream.  Throw exception if GetOutput() is NULL.
    CNcbiOstream& out(void) const;

    /// Flush output stream
    void Flush(void) const;

    /// Write HTTP response header to the output stream
    CNcbiOstream& WriteHeader(void)             const;
    CNcbiOstream& WriteHeader(CNcbiOstream& os) const;
    bool          IsHeaderWritten()             const;
    /// Define if WriteHeader() must be called or can be skipped.
    /// @param require
    ///   true -  report (to application log) if WriteHeader has not
    ///           been called by the end of ProcessRequest();
    ///   false - allow to skip WriteHeader call (e.g when the user
    ///           writes custom HTTP header directly to the output
    ///           stream).
    ///   The default setting is 'true'.
    void RequireWriteHeader(bool require);

    void SetTrackingCookie(const string& name,   const string& value,
                           const string& domain, const string& path,
                           const CTime&  exp_time = CTime());

    void DisableTrackingCookie(void);

    /// If set to TRUE then the writes to a "bad" output stream
    /// will throw exceptions of type std::ios_base::failure.
    /// @sa GetOutput()
    void SetThrowOnBadOutput(bool throw_on_bad_output);

    // If enabled, HEAD request will cause the application to exit
    // immediately after writing headers. For this option to work
    // correctly ProcessRequest must allow CCgiHeadException to
    // be caught by CCgiApplication::Run().
    // If the option is disabled, no exception is thrown and the application
    // continues to run, but the output stream is blocked so that no more data
    // can be sent to the client.
    void SetExceptionAfterHEAD(bool expt_after_head);

    /// Check if 'Accept-Ranges' header is set to 'bytes'.
    bool AcceptRangesBytes(void) const;

    /// Check if 'Content-Range' header is set.
    bool HaveContentRange(void) const;

    /// This method is called automatically by CCgiContext.
    /// Initialize cross-origin resource sharing (CORS) headers.
    /// @param origin
    ///  Must match allowed origins for the CORS to be enabled.
    /// @param jquery_callback
    ///  Used to enable JQuery JSONP hack to allow cross-origin resource
    ///  sharing for browsers that don't support CORS (e.g. IE versions
    ///  earlier than 11). For more info about this (hopefully temporary) hack
    ///  see the sources.
    /// @deprecated Use CCgiContext::ProcessCORSRequest
    NCBI_DEPRECATED
    void InitCORSHeaders(const string& origin,
                         const string& jquery_callback = kEmptyStr);

    /// Set HTTP request method.
    void SetRequestMethod(CCgiRequest::ERequestMethod method);

    /// Called by the CGI framework after a ProcessRequest(), unless the
    /// latter threw an exception.
    /// @note  It still gets called if ProcessRequest() returns non-zero code.
    /// @attention
    ///  Do not call it directly from the user code!
    void Finalize(void) const;

    /// Set retry headers from the context.
    void SetRetryContext(const CRetryContext& ctx);

    void SetCgiRequest(const CCgiRequest& request);

    /// Check/change chunked transfer encoding status. This flag is used only
    /// if CGI_CHUNKED_TRANSFER is not set.
    bool GetChunkedTransferEnabled(void) const;
    void SetChunkedTransferEnabled(bool value);

    static size_t GetChunkSize(void);

    /// Finish chunked transfer, append zero chunk and trailers, if any.
    /// All trailers must be set before calling this method.
    void FinishChunkedTransfer(void);
    /// Abort chunked transfer, block any writes to the output stream.
    void AbortChunkedTransfer(void);

    /// Check if trailer can be sent: chunked transfer must be enabled
    /// and the request's TE header must include 'trailers'.
    /// All trailer getters/setters are no-op if this condition is false.
    /// This will always return false after FinishChunkedTransfer() has been
    /// called.
    bool CanSendTrailer(void) const;
    /// Prepare to send trailer. This must be called before WriteHeader()
    /// to allow the trailer value to be set later.
    /// Some fields are not allowed to be sent as trailers - see RFC7230:
    /// https://tools.ietf.org/html/rfc7230#section-4.1.2
    void AddTrailer(const string& name);
    /// Remove trailer. Must be called before WriteHeader().
    void RemoveTrailer(const string& name);
    /// Check if trailer has been added and its value can be set.
    bool   HaveTrailer(const string& name) const;
    /// Get current trailer value.
    string GetTrailerValue(const string& name) const;
    /// Set trailer value. The trailer should have been added using
    /// AddTrailer().
    void SetTrailerValue(const string& name, const string& value);

public:
    void x_SetSession(const CCgiSession& session);

protected:
    static const char* sm_ContentTypeName;     // Content type header name
    static const char* sm_LocationName;        // Location header name
    static const char* sm_ContentTypeDefault;  // Dflt content type: text/html
    static const char* sm_ContentTypeMixed;    // multipart/mixed
    static const char* sm_ContentTypeRelated;  // multipart/related
    static const char* sm_ContentTypeXMR;      // multipart/x-mixed-replace
    static const char* sm_ContentDispoName;    // Content-Disposition
    static const char* sm_FilenamePrefix;      // Syntax preceding the fname
    static const char* sm_HTTPStatusName;      // Status header name:   Status
    static const char* sm_HTTPStatusDefault;   // Default HTTP status:  200 OK
    static const char* sm_BoundaryPrefix;      // Start of multipart boundary
    static const char* sm_CacheControl;        // Cache-Control
    static const char* sm_AcceptRanges;        // Accept-Ranges
    static const char* sm_AcceptRangesBytes;   // bytes
    static const char* sm_ContentRange;        // Content-Range

    typedef map<string, string, PNocase> TMap;

    bool           m_IsRawCgi;          // The "raw CGI" flag
    EMultipartMode m_IsMultipart;       // (Three-way) multipart flag
    bool           m_BetweenParts;      // Did we already print the boundary?
    string         m_Boundary;          // Multipart boundary
    TMap           m_HeaderValues;      // Header lines in alphabetical order
    TMap           m_TrailerValues;     // Trailer lines (for chunked transfers)
    CCgiCookies    m_Cookies;           // Cookies
    CNcbiOstream*  m_Output;            // Default output stream
    int            m_OutputFD;          // Output file descriptor, if available
    mutable bool   m_HeaderWritten;     // Did we already complete the header?
    bool           m_RequireWriteHeader; // Check if WriteHeader was called?
    CNcbiOstream::iostate m_OutputExpt; // Original output exceptions
    CCgiRequest::ERequestMethod m_RequestMethod; // Request method from CCgiRequest

    // Prohibit copy constructor and assignment operator
    CCgiResponse(const CCgiResponse&);
    CCgiResponse& operator= (const CCgiResponse&);

private:
    void x_RestoreOutputExceptions(void);
    bool x_ValidateHeader(const string& name, const string& value) const;

    static bool x_ClientSupportsChunkedTransfer(const CNcbiEnvironment& env);

    const CCgiSession*   m_Session;
    auto_ptr<CCgiCookie> m_TrackingCookie;
    bool                 m_DisableTrackingCookie;

    NCBI_PARAM_DECL(bool, CGI, ThrowOnBadOutput);
    typedef NCBI_PARAM_TYPE(CGI, ThrowOnBadOutput) TCGI_ThrowOnBadOutput;
    TCGI_ThrowOnBadOutput m_ThrowOnBadOutput;

    NCBI_PARAM_DECL(bool, CGI, ExceptionAfterHEAD);
    typedef NCBI_PARAM_TYPE(CGI, ExceptionAfterHEAD) TCGI_ExceptionAfterHEAD;
    TCGI_ExceptionAfterHEAD m_ExceptionAfterHEAD;

    const CCgiRequest* m_Request;
    bool m_ChunkedTransfer;
    mutable auto_ptr<bool> m_TrailerEnabled;

    friend class CCgiContext; // to set m_JQuery_Callback
    friend class CCgiApplication; // need x_ClientSupportsChunkedTransfer()

    string m_JQuery_Callback;
};



/* @} */




/////////////////////////////////////////////////////////////////////////////
//  IMPLEMENTATION of INLINE functions
/////////////////////////////////////////////////////////////////////////////


inline void CCgiResponse::SetRawCgi(bool is_raw)
{
    m_IsRawCgi = is_raw;
}

inline bool CCgiResponse::IsRawCgi(void) const
{
    return m_IsRawCgi;
}

inline void CCgiResponse::SetContentType(const string& type)
{
    SetHeaderValue(sm_ContentTypeName, type);
}

inline string CCgiResponse::GetContentType(void) const
{
    return GetHeaderValue(sm_ContentTypeName);
}

inline void CCgiResponse::SetLocation(const CUrl&        url,
                                      const IUrlEncoder* encoder)
{
    SetHeaderValue(sm_LocationName,
                   url.ComposeUrl(CUrlArgs::eAmp_Char, encoder));
}

inline void CCgiResponse::SetMultipartMode(EMultipartMode mode)
{
    m_IsMultipart = mode;
    m_Boundary    = sm_BoundaryPrefix + GetDiagContext().GetStringUID();
}

inline CCgiResponse::EMultipartMode CCgiResponse::GetMultipartMode(void)
{
    return m_IsMultipart;
}

inline void CCgiResponse::BeginPart(const string& name, const string& type,
                                    size_t /*size*/)
{
    BeginPart(name, type, out());
}

inline void CCgiResponse::EndPart(void)
{
    EndPart(out());
}

inline void CCgiResponse::EndLastPart(void)
{
    EndLastPart(out());
}

inline const CCgiCookies& CCgiResponse::Cookies(void) const
{
    return m_Cookies;
}

inline CCgiCookies& CCgiResponse::Cookies(void)
{
    return m_Cookies;
}

inline int CCgiResponse::GetOutputFD(void) const
{
    return m_OutputFD;
}

inline CNcbiOstream& CCgiResponse::WriteHeader(void) const
{
    return WriteHeader(out());
}

inline void CCgiResponse::RequireWriteHeader(bool require)
{
    m_RequireWriteHeader = require;
}

inline bool CCgiResponse::IsHeaderWritten(void) const
{
    return m_HeaderWritten;
}

inline void CCgiResponse::SetCgiRequest(const CCgiRequest& request)
{
    m_Request = &request;
}

inline void CCgiResponse::x_SetSession(const CCgiSession& session)
{
    m_Session = &session;
}


inline void CCgiResponse::SetRequestMethod(CCgiRequest::ERequestMethod method)
{
    m_RequestMethod = method;
}


END_NCBI_SCOPE

#endif  /* CGI___NCBICGIR__HPP */
