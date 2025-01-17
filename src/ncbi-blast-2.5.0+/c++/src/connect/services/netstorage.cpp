/*  $Id: netstorage.cpp 505978 2016-06-30 15:57:38Z sadyrovr $
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
 * Author:  Dmitry Kazimirov
 *
 * File Description:
 *   NetStorage implementation declarations.
 *
 */

#include <ncbi_pch.hpp>
#include <corelib/rwstream.hpp>
#include <connect/services/impl/netstorage_impl.hpp>
#include <connect/services/netstorage_ft.hpp>

BEGIN_NCBI_SCOPE


struct SNetStorageObjectRWStream : public CRWStream
{
    SNetStorageObjectRWStream(SNetStorageObjectImpl* nst_object) :
        CRWStream(nst_object, nst_object, /*buf_size*/ 0, /*buf*/ NULL,
                  CRWStreambuf::fLeakExceptions),
        m_NetStorageObject(nst_object)
    {
    }

    virtual ~SNetStorageObjectRWStream() { flush(); }

    CNetStorageObject m_NetStorageObject;
};

string CNetStorageObject::GetLoc()
{
    return m_Impl->GetLoc();
}

size_t CNetStorageObject::Read(void* buffer, size_t buf_size)
{
    size_t bytes_read;
    m_Impl->Read(buffer, buf_size, &bytes_read);
    return bytes_read;
}

void CNetStorageObject::Read(string* data)
{
    m_Impl->Read(data);
}

IReader& CNetStorageObject::GetReader()
{
    return m_Impl->GetReader();
}

bool CNetStorageObject::Eof()
{
    return m_Impl->Eof();
}

void CNetStorageObject::Write(const void* buffer, size_t buf_size)
{
    m_Impl->Write(buffer, buf_size, NULL);
}

void CNetStorageObject::Write(const string& data)
{
    m_Impl->Write(data.data(), data.length(), NULL);
}

IEmbeddedStreamWriter& CNetStorageObject::GetWriter()
{
    return m_Impl->GetWriter();
}

CNcbiIostream* CNetStorageObject::GetRWStream()
{
    return new SNetStorageObjectRWStream(m_Impl);
}

Uint8 CNetStorageObject::GetSize()
{
    return m_Impl->GetSize();
}

CNetStorageObject::TAttributeList CNetStorageObject::GetAttributeList() const
{
    return m_Impl->GetAttributeList();
}

string CNetStorageObject::GetAttribute(const string& attr_name) const
{
    return m_Impl->GetAttribute(attr_name);
}

void CNetStorageObject::SetAttribute(const string& attr_name,
        const string& attr_value)
{
    m_Impl->SetAttribute(attr_name, attr_value);
}

CNetStorageObjectInfo CNetStorageObject::GetInfo()
{
    return m_Impl->GetInfo();
}

void CNetStorageObject::SetExpiration(const CTimeout& ttl)
{
    m_Impl->SetExpiration(ttl);
}

void CNetStorageObject::Close()
{
    m_Impl->Close();
}

CNetStorage::CNetStorage(const string& init_string,
        TNetStorageFlags default_flags) :
    m_Impl(SNetStorage::CreateImpl(
                SNetStorage::SConfig::Build(init_string), default_flags))
{
}

CNetStorageObject CNetStorage::Create(TNetStorageFlags flags)
{
    return m_Impl->Create(flags);
}

CNetStorageObject CNetStorage::Open(const string& object_loc)
{
    return m_Impl->Open(object_loc);
}

CNetStorageObject CNetStorage::Open(const string& object_loc,
        TNetStorageFlags /*flags*/)
{
    return m_Impl->Open(object_loc);
}

string CNetStorage::Relocate(const string& object_loc,
        TNetStorageFlags flags, TNetStorageProgressCb cb)
{
    return m_Impl->Relocate(object_loc, flags, cb);
}

bool CNetStorage::Exists(const string& object_loc)
{
    return m_Impl->Exists(object_loc);
}

ENetStorageRemoveResult CNetStorage::Remove(const string& object_loc)
{
    return m_Impl->Remove(object_loc);
}

CNetStorageByKey::CNetStorageByKey(const string& init_string,
        TNetStorageFlags default_flags) :
    m_Impl(SNetStorage::CreateByKeyImpl(
                SNetStorage::SConfig::Build(init_string), default_flags))
{
}

CNetStorageObject CNetStorageByKey::Open(const string& unique_key,
        TNetStorageFlags flags)
{
    SNetStorage::SLimits::Check<SNetStorage::SLimits::SUserKey>(unique_key);
    return m_Impl->Open(unique_key, flags);
}

string CNetStorageByKey::Relocate(const string& unique_key,
        TNetStorageFlags flags, TNetStorageFlags old_flags,
        TNetStorageProgressCb cb)
{
    SNetStorage::SLimits::Check<SNetStorage::SLimits::SUserKey>(unique_key);
    return m_Impl->Relocate(unique_key, flags, old_flags, cb);
}

bool CNetStorageByKey::Exists(const string& key, TNetStorageFlags flags)
{
    SNetStorage::SLimits::Check<SNetStorage::SLimits::SUserKey>(key);
    return m_Impl->Exists(key, flags);
}

ENetStorageRemoveResult CNetStorageByKey::Remove(const string& key,
        TNetStorageFlags flags)
{
    SNetStorage::SLimits::Check<SNetStorage::SLimits::SUserKey>(key);
    return m_Impl->Remove(key, flags);
}

#ifdef NCBI_GRID_XSITE_CONN_SUPPORT
void g_AllowXSiteConnections(CNetStorage& netstorage)
{
    netstorage->AllowXSiteConnections();
}

void g_AllowXSiteConnections(CNetStorageByKey& netstorage)
{
    netstorage->AllowXSiteConnections();
}
#endif

inline 
CNetStorageException::EErrCode ConvertErrCode(CNetCacheException::TErrCode code)
{
    switch (code) {
    case CNetCacheException::eAuthenticationError:
    case CNetCacheException::eAccessDenied:
        return CNetStorageException::eAuthError;

    case CNetCacheException::eBlobNotFound:
        return CNetStorageException::eNotExists;

    case CNetCacheException::eKeyFormatError:
        return CNetStorageException::eInvalidArg;

    case CNetCacheException::eNotImplemented:
        return CNetStorageException::eNotSupported;

    case CNetCacheException::eServerError:
    case CNetCacheException::eUnknownCommand:
    case CNetCacheException::eInvalidServerResponse:
        return CNetStorageException::eServerError;

    case CNetCacheException::eBlobClipped:
        return CNetStorageException::eIOError;
    }

    return CNetStorageException::eUnknown;
}

void g_ThrowNetStorageException(const CDiagCompileInfo& compile_info,
        const CNetCacheException& prev_exception, const string& message)
{
    CNetStorageException::EErrCode err_code =
        ConvertErrCode(prev_exception.GetErrCode());
    throw CNetStorageException(compile_info, &prev_exception, err_code, message);
}

CNetStorageObject_FileTrack_Path::CNetStorageObject_FileTrack_Path(
        CNetStorageObject object)
    : m_Path(object->FileTrack_Path())
{
}

void SNetStorage::SLimits::ThrowTooLong(const string& name, size_t max_length)
{
    NCBI_THROW_FMT(CNetStorageException, eInvalidArg,
            name << " exceeds maximum allowed length of " <<
            max_length << " characters.");
}

void SNetStorage::SLimits::ThrowIllegalChars(const string& name,
        const string& value)
{
    NCBI_THROW_FMT(CNetStorageException, eInvalidArg,
            name << " contains illegal characters: " <<
            NStr::PrintableString(value));
}

END_NCBI_SCOPE
