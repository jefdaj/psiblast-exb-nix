/* $Id$
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
 * File Description:
 *   This code was generated by application DATATOOL
 *   using the following specifications:
 *   'id2.asn'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

// standard includes
#include <ncbi_pch.hpp>
#include <serial/serialimpl.hpp>

// generated includes
#include <objects/id2/ID2_Request.hpp>
#include <objects/id2/ID2S_Request_Get_Chunks.hpp>
#include <objects/id2/ID2_Params.hpp>
#include <objects/id2/ID2_Request_Get_Blob_Id.hpp>
#include <objects/id2/ID2_Request_Get_Blob_Info.hpp>
#include <objects/id2/ID2_Request_Get_Packages.hpp>
#include <objects/id2/ID2_Request_Get_Seq_id.hpp>
#include <objects/id2/ID2_Request_ReGet_Blob.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CID2_Request_Base::C_Request::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CID2_Request_Base::C_Request::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Get_packages:
    case e_Get_seq_id:
    case e_Get_blob_id:
    case e_Get_blob_info:
    case e_Reget_blob:
    case e_Get_chunks:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CID2_Request_Base::C_Request::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Get_packages:
        (m_object = new(pool) ncbi::objects::CID2_Request_Get_Packages())->AddReference();
        break;
    case e_Get_seq_id:
        (m_object = new(pool) ncbi::objects::CID2_Request_Get_Seq_id())->AddReference();
        break;
    case e_Get_blob_id:
        (m_object = new(pool) ncbi::objects::CID2_Request_Get_Blob_Id())->AddReference();
        break;
    case e_Get_blob_info:
        (m_object = new(pool) ncbi::objects::CID2_Request_Get_Blob_Info())->AddReference();
        break;
    case e_Reget_blob:
        (m_object = new(pool) ncbi::objects::CID2_Request_ReGet_Blob())->AddReference();
        break;
    case e_Get_chunks:
        (m_object = new(pool) ncbi::objects::CID2S_Request_Get_Chunks())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CID2_Request_Base::C_Request::sm_SelectionNames[] = {
    "not set",
    "init",
    "get-packages",
    "get-seq-id",
    "get-blob-id",
    "get-blob-info",
    "reget-blob",
    "get-chunks"
};

NCBI_NS_STD::string CID2_Request_Base::C_Request::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CID2_Request_Base::C_Request::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CID2_Request_Base::C_Request::TGet_packages& CID2_Request_Base::C_Request::GetGet_packages(void) const
{
    CheckSelected(e_Get_packages);
    return *static_cast<const TGet_packages*>(m_object);
}

CID2_Request_Base::C_Request::TGet_packages& CID2_Request_Base::C_Request::SetGet_packages(void)
{
    Select(e_Get_packages, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGet_packages*>(m_object);
}

void CID2_Request_Base::C_Request::SetGet_packages(CID2_Request_Base::C_Request::TGet_packages& value)
{
    TGet_packages* ptr = &value;
    if ( m_choice != e_Get_packages || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Get_packages;
    }
}

const CID2_Request_Base::C_Request::TGet_seq_id& CID2_Request_Base::C_Request::GetGet_seq_id(void) const
{
    CheckSelected(e_Get_seq_id);
    return *static_cast<const TGet_seq_id*>(m_object);
}

CID2_Request_Base::C_Request::TGet_seq_id& CID2_Request_Base::C_Request::SetGet_seq_id(void)
{
    Select(e_Get_seq_id, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGet_seq_id*>(m_object);
}

void CID2_Request_Base::C_Request::SetGet_seq_id(CID2_Request_Base::C_Request::TGet_seq_id& value)
{
    TGet_seq_id* ptr = &value;
    if ( m_choice != e_Get_seq_id || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Get_seq_id;
    }
}

const CID2_Request_Base::C_Request::TGet_blob_id& CID2_Request_Base::C_Request::GetGet_blob_id(void) const
{
    CheckSelected(e_Get_blob_id);
    return *static_cast<const TGet_blob_id*>(m_object);
}

CID2_Request_Base::C_Request::TGet_blob_id& CID2_Request_Base::C_Request::SetGet_blob_id(void)
{
    Select(e_Get_blob_id, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGet_blob_id*>(m_object);
}

void CID2_Request_Base::C_Request::SetGet_blob_id(CID2_Request_Base::C_Request::TGet_blob_id& value)
{
    TGet_blob_id* ptr = &value;
    if ( m_choice != e_Get_blob_id || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Get_blob_id;
    }
}

const CID2_Request_Base::C_Request::TGet_blob_info& CID2_Request_Base::C_Request::GetGet_blob_info(void) const
{
    CheckSelected(e_Get_blob_info);
    return *static_cast<const TGet_blob_info*>(m_object);
}

CID2_Request_Base::C_Request::TGet_blob_info& CID2_Request_Base::C_Request::SetGet_blob_info(void)
{
    Select(e_Get_blob_info, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGet_blob_info*>(m_object);
}

void CID2_Request_Base::C_Request::SetGet_blob_info(CID2_Request_Base::C_Request::TGet_blob_info& value)
{
    TGet_blob_info* ptr = &value;
    if ( m_choice != e_Get_blob_info || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Get_blob_info;
    }
}

const CID2_Request_Base::C_Request::TReget_blob& CID2_Request_Base::C_Request::GetReget_blob(void) const
{
    CheckSelected(e_Reget_blob);
    return *static_cast<const TReget_blob*>(m_object);
}

CID2_Request_Base::C_Request::TReget_blob& CID2_Request_Base::C_Request::SetReget_blob(void)
{
    Select(e_Reget_blob, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TReget_blob*>(m_object);
}

void CID2_Request_Base::C_Request::SetReget_blob(CID2_Request_Base::C_Request::TReget_blob& value)
{
    TReget_blob* ptr = &value;
    if ( m_choice != e_Reget_blob || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Reget_blob;
    }
}

const CID2_Request_Base::C_Request::TGet_chunks& CID2_Request_Base::C_Request::GetGet_chunks(void) const
{
    CheckSelected(e_Get_chunks);
    return *static_cast<const TGet_chunks*>(m_object);
}

CID2_Request_Base::C_Request::TGet_chunks& CID2_Request_Base::C_Request::SetGet_chunks(void)
{
    Select(e_Get_chunks, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGet_chunks*>(m_object);
}

void CID2_Request_Base::C_Request::SetGet_chunks(CID2_Request_Base::C_Request::TGet_chunks& value)
{
    TGet_chunks* ptr = &value;
    if ( m_choice != e_Get_chunks || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Get_chunks;
    }
}

// helper methods

// type info
BEGIN_NAMED_CHOICE_INFO("", CID2_Request_Base::C_Request)
{
    SET_INTERNAL_NAME("ID2-Request", "request");
    SET_CHOICE_MODULE("NCBI-ID2Access");
    ADD_NAMED_NULL_CHOICE_VARIANT("init", null, ());
    ADD_NAMED_REF_CHOICE_VARIANT("get-packages", m_object, CID2_Request_Get_Packages);
    ADD_NAMED_REF_CHOICE_VARIANT("get-seq-id", m_object, CID2_Request_Get_Seq_id);
    ADD_NAMED_REF_CHOICE_VARIANT("get-blob-id", m_object, CID2_Request_Get_Blob_Id);
    ADD_NAMED_REF_CHOICE_VARIANT("get-blob-info", m_object, CID2_Request_Get_Blob_Info);
    ADD_NAMED_REF_CHOICE_VARIANT("reget-blob", m_object, CID2_Request_ReGet_Blob);
    ADD_NAMED_REF_CHOICE_VARIANT("get-chunks", m_object, CID2S_Request_Get_Chunks);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CID2_Request_Base::C_Request::C_Request(void)
    : m_choice(e_not_set)
{
}

// destructor
CID2_Request_Base::C_Request::~C_Request(void)
{
    Reset();
}


void CID2_Request_Base::ResetParams(void)
{
    m_Params.Reset();
}

void CID2_Request_Base::SetParams(CID2_Request_Base::TParams& value)
{
    m_Params.Reset(&value);
}

CID2_Request_Base::TParams& CID2_Request_Base::SetParams(void)
{
    if ( !m_Params )
        m_Params.Reset(new ncbi::objects::CID2_Params());
    return (*m_Params);
}

void CID2_Request_Base::ResetRequest(void)
{
    if ( !m_Request ) {
        m_Request.Reset(new TRequest());
        return;
    }
    (*m_Request).Reset();
}

void CID2_Request_Base::SetRequest(CID2_Request_Base::TRequest& value)
{
    m_Request.Reset(&value);
}

void CID2_Request_Base::Reset(void)
{
    ResetSerial_number();
    ResetParams();
    ResetRequest();
}

BEGIN_NAMED_BASE_CLASS_INFO("ID2-Request", CID2_Request)
{
    SET_CLASS_MODULE("NCBI-ID2Access");
    ADD_NAMED_STD_MEMBER("serial-number", m_Serial_number)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("params", m_Params, CID2_Params)->SetOptional();
    ADD_NAMED_REF_MEMBER("request", m_Request, C_Request);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CID2_Request_Base::CID2_Request_Base(void)
    : m_Serial_number(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetRequest();
    }
}

// destructor
CID2_Request_Base::~CID2_Request_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

