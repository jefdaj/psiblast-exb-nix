/* $Id: rwstreambuf.cpp 463752 2015-04-01 14:15:52Z lavr $
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
 * Author:  Anton Lavrentiev
 *
 * File Description:
 *   Reader-writer based stream buffer
 *
 */

#include <ncbi_pch.hpp>
#include <corelib/ncbidbg.hpp>
#include <corelib/ncbiexpt.hpp>
#include <corelib/ncbi_limits.hpp>
#include <corelib/reader_writer.hpp>
#include <corelib/rwstream.hpp>
#include <corelib/error_codes.hpp>

#define NCBI_USE_ERRCODE_X   Corelib_StreamBuf


#define RWSTREAMBUF_HANDLE_EXCEPTIONS(call, subcode, message, action)   \
  switch (m_Flags & (fLogExceptions | fLeakExceptions)) {               \
  case fLeakExceptions:                                                 \
      call;                                                             \
      break;                                                            \
  case 0: /* Invoke 'action' only if exception was (silently) caught */ \
      try {                                                             \
          call;                                                         \
          break;                                                        \
      }                                                                 \
      catch (...) {                                                     \
      }                                                                 \
      action;                                                           \
      break;                                                            \
  default: /* Exception logging (and maybe re-throwing) */              \
      try {                                                             \
          call;                                                         \
          break;                                                        \
      }                                                                 \
      catch (CException& e) {                                           \
          try {                                                         \
              NCBI_REPORT_EXCEPTION_X(subcode, message, e);             \
          } catch (...) {                                               \
          }                                                             \
          if (m_Flags & fLeakExceptions)                                \
              throw;                                                    \
      }                                                                 \
      catch (exception& e) {                                            \
          try {                                                         \
              ERR_POST_X(subcode, Error                                 \
                         << "[" << message                              \
                         << "] Exception: " << e.what());               \
          } catch (...) {                                               \
          }                                                             \
          if (m_Flags & fLeakExceptions)                                \
              throw;                                                    \
      }                                                                 \
      catch (...) {                                                     \
          try {                                                         \
              ERR_POST_X(subcode, Error                                 \
                         << "[" << message << "] Unknown exception");   \
          } catch (...) {                                               \
          }                                                             \
          if (m_Flags & fLeakExceptions)                                \
              throw;                                                    \
      }                                                                 \
      action;                                                           \
      break;                                                            \
  }


BEGIN_NCBI_SCOPE


const char* g_RW_ResultToString(ERW_Result result)
{
    static const char* const kResultStr[eRW_Eof - eRW_NotImplemented + 1] = {
        "eRW_NotImplemented",
        "eRW_Success",
        "eRW_Timeout",
        "eRW_Error",
        "eRW_Eof"
    };

    _ASSERT(eRW_NotImplemented <= result  &&  result <= eRW_Eof);
    return kResultStr[result - eRW_NotImplemented];
}

static const streamsize kDefaultBufSize = 4096;


static inline EOwnership x_IfToOwnReader(const IReader* r, const IWriter* w,
                                         CRWStreambuf::TFlags f)
{
    const IReaderWriter* rw = dynamic_cast<const IReaderWriter*> (r);
    if (!rw  ||  rw != dynamic_cast<const IReaderWriter*> (w)) {
        if (f & CRWStreambuf::fOwnReader)
            return eTakeOwnership;
    } else {
        if ((f & CRWStreambuf::fOwnAll) == CRWStreambuf::fOwnAll)
            return eTakeOwnership;
    }
    return eNoOwnership;
}


static inline EOwnership x_IfToOwnWriter(const IReader* r, const IWriter* w,
                                         CRWStreambuf::TFlags f)
{
    const IReaderWriter* rw = dynamic_cast<const IReaderWriter*> (w);
    if (!rw  ||  rw != dynamic_cast<const IReaderWriter*> (r)) {
        if (f & CRWStreambuf::fOwnWriter)
            return eTakeOwnership;
    } /* else IReader sets the ownership */
    return eNoOwnership;
}


CRWStreambuf::CRWStreambuf(IReaderWriter*       rw,
                           streamsize           n,
                           CT_CHAR_TYPE*        s,
                           CRWStreambuf::TFlags f)
    : m_Flags(f),
      m_Reader(rw, x_IfToOwnReader(rw, rw, f)),
      m_Writer(rw, x_IfToOwnWriter(rw, rw, f)), m_pBuf(0),
      x_GPos((CT_OFF_TYPE) 0), x_PPos((CT_OFF_TYPE) 0),
      x_Err(false), x_ErrPos((CT_OFF_TYPE) 0)
{
    setbuf(n  &&  s ? s : 0, n ? n : kDefaultBufSize << 1);
}


CRWStreambuf::CRWStreambuf(IReader*             r,
                           IWriter*             w,
                           streamsize           n,
                           CT_CHAR_TYPE*        s,
                           CRWStreambuf::TFlags f)
    : m_Flags(f),
      m_Reader(r, x_IfToOwnReader(r, w, f)),
      m_Writer(w, x_IfToOwnWriter(r, w, f)), m_pBuf(0),
      x_GPos((CT_OFF_TYPE) 0), x_PPos((CT_OFF_TYPE) 0),
      x_Err(false), x_ErrPos((CT_OFF_TYPE) 0)
{
    setbuf(n  &&  s ? s : 0,
           n        ? n : kDefaultBufSize << (m_Reader  &&  m_Writer ? 1 : 0));
}


ERW_Result CRWStreambuf::x_pushback(void)
{
    if ( !m_Reader ) {
        _ASSERT(!gptr()  &&  !egptr());
        return eRW_Success;
    }

    ERW_Result result;
    const CT_CHAR_TYPE* ptr = gptr();
    size_t count = (size_t)(egptr() - ptr);
    setg(0, 0, 0);
    if ( !count )
        result = eRW_Success;
    else if ((result = m_Reader->Pushback(ptr, count, m_pBuf)) == eRW_Success)
        m_pBuf = 0;
    return result;
}


CRWStreambuf::~CRWStreambuf()
{
    try {
        // Flush only if data pending and no error
        if (!x_Err  ||  x_ErrPos != x_GetPPos())
            x_sync();
        setp(0, 0);
    } NCBI_CATCH_ALL_X(2,  "Exception in ~CRWStreambuf() [IGNORED]");
    try {
        // Push any data still unred in the buffer back to the device
        ERW_Result result = x_pushback();
        if (result != eRW_Success  &&  result != eRW_NotImplemented) {
            ERR_POST_X(13,
                       Critical << "CRWStreambuf::~CRWStreambuf():"
                       " Read data pending");
        }
    } NCBI_CATCH_ALL_X(14, "Exception in ~CRWStreambuf() [IGNORED]");

    delete[] m_pBuf;
}


CNcbiStreambuf* CRWStreambuf::setbuf(CT_CHAR_TYPE* s, streamsize m)
{
    if (!s  &&  !m)
        return this;

    if (x_pushback() != eRW_Success)
        ERR_POST_X(3,Critical << "CRWStreambuf::setbuf(): Read data pending");
    if (x_sync() != 0)
        ERR_POST_X(4,Critical << "CRWStreambuf::setbuf(): Write data pending");
    setp(0, 0);

    delete[] m_pBuf;
    m_pBuf = 0;

    size_t n = (size_t) m;
    if ( !n ) {
        s = 0/*setbuf(s, 0)?!*/;
        _ASSERT(kDefaultBufSize > 1);
        n = (size_t) kDefaultBufSize << (m_Reader  &&  m_Writer ? 1 : 0);
    }
    if ( !s )
        s          = n == 1 ? &x_Buf : (m_pBuf = new CT_CHAR_TYPE[n]);

    if ( m_Reader ) {
        m_BufSize  = n == 1 ? 1      : n >> (m_Reader  &&  m_Writer ? 1 : 0);
        m_ReadBuf  = s;
    } else {
        m_BufSize  = 0;
        m_ReadBuf  = 0;
    }
    setg(m_ReadBuf, m_ReadBuf, m_ReadBuf);

    if ( m_Writer )
        m_WriteBuf = n == 1 ? 0      : s + m_BufSize;
    else
        m_WriteBuf = 0;
    setp(m_WriteBuf, m_WriteBuf + (m_WriteBuf ? n - m_BufSize : 0));

    return this;
}


CT_INT_TYPE CRWStreambuf::overflow(CT_INT_TYPE c)
{
    if ( !m_Writer )
        return CT_EOF;

    size_t n_written;
    size_t n_towrite = (size_t)(pptr() - pbase());

    ERW_Result result;
    if ( n_towrite ) {
        // send buffer
        do {
            n_written = 0;
            RWSTREAMBUF_HANDLE_EXCEPTIONS(
                result = m_Writer->Write(pbase(), n_towrite, &n_written),
                5, "CRWStreambuf::overflow(): IWriter::Write()",
                (n_written = 0, result = eRW_Error));
            _ASSERT(n_written <= n_towrite);
            if ( !n_written ) {
                _ASSERT(result != eRW_Success);
                break;
            }
            // update buffer content (get rid of the data just sent)
            memmove(pbase(), pbase() + n_written, n_towrite - n_written);
            x_PPos += (CT_OFF_TYPE) n_written;
            pbump(-int(n_written));

            // store char
            if ( !CT_EQ_INT_TYPE(c, CT_EOF) ) {
                x_Err = false;
                return sputc(CT_TO_CHAR_TYPE(c));
            }
            n_towrite -= n_written;
        } while (n_towrite  &&  result == eRW_Success);
        if ( n_towrite ) {
            _ASSERT(result != eRW_Success);
            x_Err    = true;
            x_ErrPos = x_GetPPos();
            return CT_EOF;
        }
    } else if ( !CT_EQ_INT_TYPE(c, CT_EOF) ) {
        // send char
        n_written = 0;
        CT_CHAR_TYPE b = CT_TO_CHAR_TYPE(c);
        RWSTREAMBUF_HANDLE_EXCEPTIONS(
            m_Writer->Write(&b, 1, &n_written),
            6, "CRWStreambuf::overflow(): IWriter::Write(1)",
            n_written = 0);
        _ASSERT(n_written <= 1);
        if ( !n_written ) {
            x_Err    = true;
            x_ErrPos = x_GetPPos();
            return CT_EOF;
        }
        x_PPos += (CT_OFF_TYPE) 1;
        x_Err = false;
        return c;
    }

    _ASSERT(CT_EQ_INT_TYPE(c, CT_EOF));
    RWSTREAMBUF_HANDLE_EXCEPTIONS(
        result = m_Writer->Flush(),
        7, "CRWStreambuf::overflow(): IWriter::Flush()",
        result = eRW_Error);
    switch (result) {
    case eRW_Error:
    case eRW_Eof:
        x_Err    = true;
        x_ErrPos = x_GetPPos();
        return CT_EOF;
    default:
        break;
    }
    x_Err = false;
    return CT_NOT_EOF(CT_EOF);
}


streamsize CRWStreambuf::xsputn(const CT_CHAR_TYPE* buf, streamsize m)
{
    if (!m_Writer  ||  m < 0)
        return 0;

    _ASSERT((Uint8) m < numeric_limits<size_t>::max());
    ERW_Result result = eRW_Success;
    size_t n = (size_t) m;
    size_t n_written = 0;
    size_t x_written;
    x_Err = false;

    do {
        if (pbase()) {
            if (n  &&  pbase() + n < epptr()) {
                // Would entirely fit into the buffer not causing an overflow
                x_written = (size_t)(epptr() - pptr());
                if (x_written > n)
                    x_written = n;
                if ( x_written ) {
                    memcpy(pptr(), buf, x_written);
                    pbump(int(x_written));
                    n_written += x_written;
                    n         -= x_written;
                    if ( !n )
                        return (streamsize) n_written;
                    buf       += x_written;
                }
            }

            size_t x_towrite = (size_t)(pptr() - pbase());
            if ( x_towrite ) {
                x_written = 0;
                RWSTREAMBUF_HANDLE_EXCEPTIONS(
                    result = m_Writer->Write(pbase(), x_towrite, &x_written),
                    8, "CRWStreambuf::xsputn(): IWriter::Write()",
                    x_written = 0);
                _ASSERT(x_written <= x_towrite);
                if ( !x_written ) {
                    x_Err    = true;
                    x_ErrPos = x_GetPPos();
                    break;
                }
                memmove(pbase(), pbase() + x_written, x_towrite - x_written);
                x_PPos += (CT_OFF_TYPE) x_written;
                pbump(-int(x_written));
                continue;
            }
        }

        x_written = 0;
        _ASSERT(result == eRW_Success);
        RWSTREAMBUF_HANDLE_EXCEPTIONS(
            result = m_Writer->Write(buf, n, &x_written),
            9, "CRWStreambuf::xsputn(): IWriter::Write()",
            x_written = 0);
        _ASSERT(x_written <= n);
        if (!x_written  &&  n) {
            x_Err    = true;
            x_ErrPos = x_GetPPos();
            break;
        }
        x_PPos    += (CT_OFF_TYPE) x_written;
        n_written += x_written;
        n         -= x_written;
        if ( !n )
            return (streamsize) n_written;
        buf       += x_written;
    } while (result == eRW_Success);

    _ASSERT(n  &&  x_Err);
    if ( pbase() ) {
        x_written = (size_t)(epptr() - pptr());
        if ( x_written ) {
            if (x_written > n)
                x_written = n;
            memcpy(pptr(), buf, x_written);
            n_written += x_written;
            pbump(int(x_written));
        }
    }
    return (streamsize) n_written;
}


CT_INT_TYPE CRWStreambuf::underflow(void)
{
    _ASSERT(gptr() >= egptr());

    if ( !m_Reader )
        return CT_EOF;

    // flush output buffer, if tied up to it
    if (!(m_Flags & fUntie)  &&  x_sync() != 0)
        return CT_EOF;

#ifdef NCBI_COMPILER_MIPSPRO
    if (m_MIPSPRO_ReadsomeGptrSetLevel  &&  m_MIPSPRO_ReadsomeGptr != gptr())
        return CT_EOF;
    m_MIPSPRO_ReadsomeGptr = (CT_CHAR_TYPE*)(-1L);
#endif /*NCBI_COMPILER_MIPSPRO*/

    // read from device
    size_t n_read = 0;
    RWSTREAMBUF_HANDLE_EXCEPTIONS(
        m_Reader->Read(m_ReadBuf, m_BufSize, &n_read),
        10, "CRWStreambuf::underflow(): IReader::Read()",
        n_read = 0);
    _ASSERT(n_read <= m_BufSize);
    if ( !n_read )
        return CT_EOF;

    // update input buffer with the data just read
    x_GPos += (CT_OFF_TYPE) n_read;
    setg(m_ReadBuf, m_ReadBuf, m_ReadBuf + n_read);

    return CT_TO_INT_TYPE(*m_ReadBuf);
}


streamsize CRWStreambuf::xsgetn(CT_CHAR_TYPE* buf, streamsize m)
{
    if ( !m_Reader )
        return 0;

    // flush output buffer, if tied up to it
    if (!(m_Flags & fUntie)  &&  x_sync() != 0)
        return 0;

    if (m < 0)
        return 0;

    _ASSERT((Uint8) m < numeric_limits<size_t>::max());
    size_t n = (size_t) m;
    size_t n_read;

    if ( n ) {
        // first, read from the memory buffer
        n_read = (size_t)(egptr() - gptr());
        if (n_read > n)
            n_read = n;
        memcpy(buf, gptr(), n_read);
        gbump(int(n_read));
        n   -= n_read;
        if ( !n )
            return (streamsize) n_read;
        buf += n_read;
    } else
        n_read = 0;

    do {
        // next, read directly from the device
        size_t     x_toread = n  &&  n < m_BufSize ? m_BufSize : n;
        CT_CHAR_TYPE* x_buf =        n < m_BufSize ? m_ReadBuf : buf;
        ERW_Result   result = eRW_Success;
        size_t       x_read = 0;

        RWSTREAMBUF_HANDLE_EXCEPTIONS(
            result = m_Reader->Read(x_buf, x_toread, &x_read),
            11, "CRWStreambuf::xsgetn(): IReader::Read()",
            x_read = 0);
        _ASSERT(x_read <= x_toread);
        if ( !x_read )
            break;
        x_GPos += (CT_OFF_TYPE) x_read;
        // satisfy "usual backup condition", see standard: 27.5.2.4.3.13
        if (x_buf == m_ReadBuf) {
            size_t xx_read = x_read;
            if (x_read > n)
                x_read = n;
            memcpy(buf, m_ReadBuf, x_read);
            setg(m_ReadBuf, m_ReadBuf + x_read, m_ReadBuf + xx_read);
        } else {
            _ASSERT(x_read <= n);
            size_t xx_read = x_read > m_BufSize ? m_BufSize : x_read;
            memcpy(m_ReadBuf, buf + x_read - xx_read, xx_read);
            setg(m_ReadBuf, m_ReadBuf + xx_read, m_ReadBuf + xx_read);
        }
        n_read += x_read;
        if (result != eRW_Success)
            break;
        buf    += x_read;
        n      -= x_read;
    } while ( n );

    return (streamsize) n_read;
}


streamsize CRWStreambuf::showmanyc(void)
{
    _ASSERT(gptr() >= egptr());

    if ( !m_Reader )
        return -1L;

    // flush output buffer, if tied up to it
    if (!(m_Flags & fUntie))
        x_sync();

    size_t count = 0;
    ERW_Result result;
    RWSTREAMBUF_HANDLE_EXCEPTIONS(
        result = m_Reader->PendingCount(&count),
        12, "CRWStreambuf::showmanyc(): IReader::PendingCount()",
        result = eRW_Error);
    switch (result) {
    case eRW_NotImplemented:
        return 0;
    case eRW_Success:
        return count;
    default:
        break;
    }
    return -1L;
}


int CRWStreambuf::sync(void)
{
    if (CT_EQ_INT_TYPE(overflow(CT_EOF), CT_EOF))
        return -1;
    _ASSERT(pbase() == pptr());
    return 0;
}


CT_POS_TYPE CRWStreambuf::seekoff(CT_OFF_TYPE off, IOS_BASE::seekdir whence,
                                  IOS_BASE::openmode which)
{
    if (off == 0  &&  whence == IOS_BASE::cur) {
        switch (which) {
        case IOS_BASE::out:
            return x_GetPPos();
        case IOS_BASE::in:
            return x_GetGPos();
        default:
            break;
        }
    }
    return (CT_POS_TYPE)((CT_OFF_TYPE)(-1L));
}


END_NCBI_SCOPE
