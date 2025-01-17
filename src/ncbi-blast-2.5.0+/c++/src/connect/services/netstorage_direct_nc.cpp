/*  $Id: netstorage_direct_nc.cpp 504524 2016-06-15 23:50:37Z sadyrovr $
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
 *   Direct access to NetCache servers through NetStorage API (implementation).
 *
 */

#include <ncbi_pch.hpp>

#include "netstorage_direct_nc.hpp"
#include "netcache_api_impl.hpp"

#include <connect/services/error_codes.hpp>

#include <util/ncbi_url.hpp>

#include <corelib/request_ctx.hpp>

#define NCBI_USE_ERRCODE_X  NetStorage_RPC

BEGIN_NCBI_SCOPE

string SNetStorage_NetCacheBlob::GetLoc()
{
    return m_BlobKey;
}

void SNetStorage_NetCacheBlob::x_InitReader()
{
    if (m_State == eWriting) {
        NCBI_THROW_FMT(CNetStorageException, eInvalidArg,
                "Cannot read a NetCache blob while writing to it");
    }

    try {
        m_NetCacheReader.reset(m_NetCacheAPI->GetPartReader(
                m_BlobKey, 0, 0, &m_BlobSize, NULL));
    }
    NETSTORAGE_CONVERT_NETCACHEEXCEPTION("on reading " + m_BlobKey)

    m_State = eReading;
}

ERW_Result SNetStorage_NetCacheBlob::Read(void* buffer, size_t buf_size,
        size_t* bytes_read)
{
    if (m_State != eReading)
        x_InitReader();

    try {
        return g_ReadFromNetCache(m_NetCacheReader.get(),
                reinterpret_cast<char*>(buffer), buf_size, bytes_read);
    }
    NETSTORAGE_CONVERT_NETCACHEEXCEPTION("on reading " + m_BlobKey)
    return eRW_Error; // Not reached
}

ERW_Result SNetStorage_NetCacheBlob::PendingCount(size_t* count)
{
    if (m_State != eReading) {
        *count = 0;
        return eRW_Success;
    }
    return m_NetCacheReader->PendingCount(count);
}

void SNetStorage_NetCacheBlob::Read(string* data)
{
    try {
        m_NetCacheAPI.ReadData(m_BlobKey, *data);
    }
    NETSTORAGE_CONVERT_NETCACHEEXCEPTION("on reading " + m_BlobKey)
}

bool SNetStorage_NetCacheBlob::Eof()
{
    switch (m_State) {
    case eReady:
        return false;

    case eReading:
        return m_NetCacheReader->Eof();

    default: /* case eWriting: */
        NCBI_THROW_FMT(CNetStorageException, eInvalidArg,
            "Cannot read a NetCache blob while writing");
    }
}

void SNetStorage_NetCacheBlob::x_InitWriter()
{
    if (m_State == eReading) {
        NCBI_THROW_FMT(CNetStorageException, eInvalidArg,
                "Cannot write a NetCache blob while reading");
    }

    try {
        m_NetCacheWriter.reset(m_NetCacheAPI.PutData(&m_BlobKey));
    }
    NETSTORAGE_CONVERT_NETCACHEEXCEPTION("on writing " + m_BlobKey)

    m_State = eWriting;
}

ERW_Result SNetStorage_NetCacheBlob::Write(const void* buf_pos, size_t buf_size,
        size_t* bytes_written)
{
    if (m_State != eWriting)
        x_InitWriter();

    try {
        return m_NetCacheWriter->Write(buf_pos, buf_size, bytes_written);
    }
    NETSTORAGE_CONVERT_NETCACHEEXCEPTION("on writing " + m_BlobKey)
    return eRW_Error; // Not reached
}

ERW_Result SNetStorage_NetCacheBlob::Flush()
{
    return m_State != eWriting ? eRW_Success : m_NetCacheWriter->Flush();
}

Uint8 SNetStorage_NetCacheBlob::GetSize()
{
    try {
        if (m_State != eReading)
            return m_NetCacheAPI.GetBlobSize(m_BlobKey);
        else
            return m_NetCacheReader->GetBlobSize();
    }
    NETSTORAGE_CONVERT_NETCACHEEXCEPTION("on accessing " + m_BlobKey)
    return 0; // Not reached
}

list<string> SNetStorage_NetCacheBlob::GetAttributeList() const
{
    NCBI_THROW_FMT(CNetStorageException, eNotSupported, m_BlobKey <<
            ": attribute retrieval is not implemented for NetCache blobs");
}

string SNetStorage_NetCacheBlob::GetAttribute(const string& /*attr_name*/) const
{
    NCBI_THROW_FMT(CNetStorageException, eNotSupported, m_BlobKey <<
            ": attribute retrieval is not implemented for NetCache blobs");
}

void SNetStorage_NetCacheBlob::SetAttribute(const string& /*attr_name*/,
        const string& /*attr_value*/)
{
    NCBI_THROW_FMT(CNetStorageException, eNotSupported, m_BlobKey <<
            ": attribute setting for NetCache blobs is not implemented");
}

CNetStorageObjectInfo SNetStorage_NetCacheBlob::GetInfo()
{
    try {
        try {
            CNetServerMultilineCmdOutput output(
                    m_NetCacheAPI.GetBlobInfo(m_BlobKey));

            CJsonNode blob_info = CJsonNode::NewObjectNode();
            string line, key, val;

            while (output.ReadLine(line))
                if (NStr::SplitInTwo(line, ": ",
                        key, val, NStr::fSplit_ByPattern))
                    blob_info.SetByKey(key, CJsonNode::GuessType(val));

            CJsonNode size_node(blob_info.GetByKeyOrNull("Size"));

            Uint8 blob_size = size_node && size_node.IsInteger() ?
                    (Uint8) size_node.AsInteger() :
                    m_NetCacheAPI.GetBlobSize(m_BlobKey);

            if (m_NetCacheAPI.HasBlob(m_BlobKey)) {
                return g_CreateNetStorageObjectInfo(m_BlobKey,
                        eNFL_NetCache, NULL, blob_size, blob_info);
            }
        }
        NETSTORAGE_CONVERT_NETCACHEEXCEPTION("on accessing " + m_BlobKey)
    }
    catch (CNetStorageException& e) {
        if (e.GetErrCode() != CNetStorageException::eNotExists)
            throw;
    }

    return g_CreateNetStorageObjectInfo(m_BlobKey,
            eNFL_NotFound, NULL, 0, NULL);
}

void SNetStorage_NetCacheBlob::SetExpiration(const CTimeout& ttl)
{
    if (!ttl.IsFinite()) {
        NCBI_THROW_FMT(CNetStorageException, eNotSupported, m_BlobKey <<
            ": infinite ttl for NetCache blobs is not implemented");
    }

    try {
        m_NetCacheAPI.ProlongBlobLifetime(m_BlobKey, (unsigned)ttl.GetAsDouble());
    }
    NETSTORAGE_CONVERT_NETCACHEEXCEPTION("on setting ttl " + m_BlobKey)
}

string SNetStorage_NetCacheBlob::FileTrack_Path()
{
    NCBI_THROW_FMT(CNetStorageException, eInvalidArg, m_BlobKey <<
            ": not a FileTrack object");
}

void SNetStorage_NetCacheBlob::Close()
{
    switch (m_State) {
    case eReading:
        m_State = eReady;
        m_NetCacheReader.reset();
        break;

    case eWriting:
        m_State = eReady;
        m_NetCacheWriter->Close();
        m_NetCacheWriter.reset();
        break;

    default:
        break;
    }
}

void SNetStorage_NetCacheBlob::Abort()
{
    switch (m_State) {
    case eReading:
        m_State = eReady;
        m_NetCacheReader.reset();
        break;

    case eWriting:
        m_State = eReady;
        m_NetCacheWriter->Abort();
        m_NetCacheWriter.reset();
        break;

    default:
        break;
    }
}

CNetStorageObject CDNCNetStorage::Create(CNetCacheAPI::TInstance nc_api)
{
    auto_ptr<SNetStorage_NetCacheBlob> result(
            new SNetStorage_NetCacheBlob(nc_api, kEmptyStr));
    result->x_InitWriter();
    return result.release();
}

CNetStorageObject CDNCNetStorage::Open(CNetCacheAPI::TInstance nc_api,
        const string& blob_key)
{
    return new SNetStorage_NetCacheBlob(nc_api, blob_key);
}

END_NCBI_SCOPE
