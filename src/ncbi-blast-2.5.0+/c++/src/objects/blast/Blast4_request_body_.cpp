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
 *   'blast.asn'.
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
#include <objects/blast/Blast4_request_body.hpp>
#include <objects/blast/Blas_get_searc_resul_reque.hpp>
#include <objects/blast/Blast4_get_sequenc_request.hpp>
#include <objects/blast/Blast4_queue_search_reques.hpp>
#include <objects/blast/Blast_finish_params_reques.hpp>
#include <objects/blast/Blast_get_databa_ex_reques.hpp>
#include <objects/blast/Blast_get_proto_info_reque.hpp>
#include <objects/blast/Blast_get_reque_info_reque.hpp>
#include <objects/blast/Blast_get_searc_info_reque.hpp>
#include <objects/blast/Blast_get_seq_parts_reques.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBlast4_request_body_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CBlast4_request_body_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Finish_params:
    case e_Get_search_results:
    case e_Get_sequences:
    case e_Queue_search:
    case e_Get_request_info:
    case e_Get_sequence_parts:
    case e_Get_protocol_info:
    case e_Get_search_info:
    case e_Get_databases_ex:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CBlast4_request_body_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Finish_params:
        (m_object = new(pool) ncbi::objects::CBlast4_finish_params_request())->AddReference();
        break;
    case e_Get_search_results:
        (m_object = new(pool) ncbi::objects::CBlast4_get_search_results_request())->AddReference();
        break;
    case e_Get_sequences:
        (m_object = new(pool) ncbi::objects::CBlast4_get_sequences_request())->AddReference();
        break;
    case e_Queue_search:
        (m_object = new(pool) ncbi::objects::CBlast4_queue_search_request())->AddReference();
        break;
    case e_Get_request_info:
        (m_object = new(pool) ncbi::objects::CBlast4_get_request_info_request())->AddReference();
        break;
    case e_Get_sequence_parts:
        (m_object = new(pool) ncbi::objects::CBlast4_get_seq_parts_request())->AddReference();
        break;
    case e_Get_protocol_info:
        (m_object = new(pool) ncbi::objects::CBlast4_get_protocol_info_request())->AddReference();
        break;
    case e_Get_search_info:
        (m_object = new(pool) ncbi::objects::CBlast4_get_search_info_request())->AddReference();
        break;
    case e_Get_databases_ex:
        (m_object = new(pool) ncbi::objects::CBlast4_get_databases_ex_request())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CBlast4_request_body_Base::sm_SelectionNames[] = {
    "not set",
    "finish-params",
    "get-databases",
    "get-matrices",
    "get-parameters",
    "get-paramsets",
    "get-programs",
    "get-search-results",
    "get-sequences",
    "queue-search",
    "get-request-info",
    "get-sequence-parts",
    "get-windowmasked-taxids",
    "get-protocol-info",
    "get-search-info",
    "get-databases-ex"
};

NCBI_NS_STD::string CBlast4_request_body_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CBlast4_request_body_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CBlast4_request_body_Base::TFinish_params& CBlast4_request_body_Base::GetFinish_params(void) const
{
    CheckSelected(e_Finish_params);
    return *static_cast<const TFinish_params*>(m_object);
}

CBlast4_request_body_Base::TFinish_params& CBlast4_request_body_Base::SetFinish_params(void)
{
    Select(e_Finish_params, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TFinish_params*>(m_object);
}

void CBlast4_request_body_Base::SetFinish_params(CBlast4_request_body_Base::TFinish_params& value)
{
    TFinish_params* ptr = &value;
    if ( m_choice != e_Finish_params || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Finish_params;
    }
}

const CBlast4_request_body_Base::TGet_search_results& CBlast4_request_body_Base::GetGet_search_results(void) const
{
    CheckSelected(e_Get_search_results);
    return *static_cast<const TGet_search_results*>(m_object);
}

CBlast4_request_body_Base::TGet_search_results& CBlast4_request_body_Base::SetGet_search_results(void)
{
    Select(e_Get_search_results, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGet_search_results*>(m_object);
}

void CBlast4_request_body_Base::SetGet_search_results(CBlast4_request_body_Base::TGet_search_results& value)
{
    TGet_search_results* ptr = &value;
    if ( m_choice != e_Get_search_results || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Get_search_results;
    }
}

const CBlast4_request_body_Base::TGet_sequences& CBlast4_request_body_Base::GetGet_sequences(void) const
{
    CheckSelected(e_Get_sequences);
    return *static_cast<const TGet_sequences*>(m_object);
}

CBlast4_request_body_Base::TGet_sequences& CBlast4_request_body_Base::SetGet_sequences(void)
{
    Select(e_Get_sequences, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGet_sequences*>(m_object);
}

void CBlast4_request_body_Base::SetGet_sequences(CBlast4_request_body_Base::TGet_sequences& value)
{
    TGet_sequences* ptr = &value;
    if ( m_choice != e_Get_sequences || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Get_sequences;
    }
}

const CBlast4_request_body_Base::TQueue_search& CBlast4_request_body_Base::GetQueue_search(void) const
{
    CheckSelected(e_Queue_search);
    return *static_cast<const TQueue_search*>(m_object);
}

CBlast4_request_body_Base::TQueue_search& CBlast4_request_body_Base::SetQueue_search(void)
{
    Select(e_Queue_search, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TQueue_search*>(m_object);
}

void CBlast4_request_body_Base::SetQueue_search(CBlast4_request_body_Base::TQueue_search& value)
{
    TQueue_search* ptr = &value;
    if ( m_choice != e_Queue_search || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Queue_search;
    }
}

const CBlast4_request_body_Base::TGet_request_info& CBlast4_request_body_Base::GetGet_request_info(void) const
{
    CheckSelected(e_Get_request_info);
    return *static_cast<const TGet_request_info*>(m_object);
}

CBlast4_request_body_Base::TGet_request_info& CBlast4_request_body_Base::SetGet_request_info(void)
{
    Select(e_Get_request_info, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGet_request_info*>(m_object);
}

void CBlast4_request_body_Base::SetGet_request_info(CBlast4_request_body_Base::TGet_request_info& value)
{
    TGet_request_info* ptr = &value;
    if ( m_choice != e_Get_request_info || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Get_request_info;
    }
}

const CBlast4_request_body_Base::TGet_sequence_parts& CBlast4_request_body_Base::GetGet_sequence_parts(void) const
{
    CheckSelected(e_Get_sequence_parts);
    return *static_cast<const TGet_sequence_parts*>(m_object);
}

CBlast4_request_body_Base::TGet_sequence_parts& CBlast4_request_body_Base::SetGet_sequence_parts(void)
{
    Select(e_Get_sequence_parts, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGet_sequence_parts*>(m_object);
}

void CBlast4_request_body_Base::SetGet_sequence_parts(CBlast4_request_body_Base::TGet_sequence_parts& value)
{
    TGet_sequence_parts* ptr = &value;
    if ( m_choice != e_Get_sequence_parts || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Get_sequence_parts;
    }
}

const CBlast4_request_body_Base::TGet_protocol_info& CBlast4_request_body_Base::GetGet_protocol_info(void) const
{
    CheckSelected(e_Get_protocol_info);
    return *static_cast<const TGet_protocol_info*>(m_object);
}

CBlast4_request_body_Base::TGet_protocol_info& CBlast4_request_body_Base::SetGet_protocol_info(void)
{
    Select(e_Get_protocol_info, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGet_protocol_info*>(m_object);
}

void CBlast4_request_body_Base::SetGet_protocol_info(CBlast4_request_body_Base::TGet_protocol_info& value)
{
    TGet_protocol_info* ptr = &value;
    if ( m_choice != e_Get_protocol_info || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Get_protocol_info;
    }
}

const CBlast4_request_body_Base::TGet_search_info& CBlast4_request_body_Base::GetGet_search_info(void) const
{
    CheckSelected(e_Get_search_info);
    return *static_cast<const TGet_search_info*>(m_object);
}

CBlast4_request_body_Base::TGet_search_info& CBlast4_request_body_Base::SetGet_search_info(void)
{
    Select(e_Get_search_info, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGet_search_info*>(m_object);
}

void CBlast4_request_body_Base::SetGet_search_info(CBlast4_request_body_Base::TGet_search_info& value)
{
    TGet_search_info* ptr = &value;
    if ( m_choice != e_Get_search_info || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Get_search_info;
    }
}

const CBlast4_request_body_Base::TGet_databases_ex& CBlast4_request_body_Base::GetGet_databases_ex(void) const
{
    CheckSelected(e_Get_databases_ex);
    return *static_cast<const TGet_databases_ex*>(m_object);
}

CBlast4_request_body_Base::TGet_databases_ex& CBlast4_request_body_Base::SetGet_databases_ex(void)
{
    Select(e_Get_databases_ex, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGet_databases_ex*>(m_object);
}

void CBlast4_request_body_Base::SetGet_databases_ex(CBlast4_request_body_Base::TGet_databases_ex& value)
{
    TGet_databases_ex* ptr = &value;
    if ( m_choice != e_Get_databases_ex || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Get_databases_ex;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Blast4-request-body", CBlast4_request_body)
{
    SET_CHOICE_MODULE("NCBI-Blast4");
    ADD_NAMED_REF_CHOICE_VARIANT("finish-params", m_object, CBlast4_finish_params_request);
    ADD_NAMED_NULL_CHOICE_VARIANT("get-databases", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("get-matrices", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("get-parameters", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("get-paramsets", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("get-programs", null, ());
    ADD_NAMED_REF_CHOICE_VARIANT("get-search-results", m_object, CBlast4_get_search_results_request);
    ADD_NAMED_REF_CHOICE_VARIANT("get-sequences", m_object, CBlast4_get_sequences_request);
    ADD_NAMED_REF_CHOICE_VARIANT("queue-search", m_object, CBlast4_queue_search_request);
    ADD_NAMED_REF_CHOICE_VARIANT("get-request-info", m_object, CBlast4_get_request_info_request);
    ADD_NAMED_REF_CHOICE_VARIANT("get-sequence-parts", m_object, CBlast4_get_seq_parts_request);
    ADD_NAMED_NULL_CHOICE_VARIANT("get-windowmasked-taxids", null, ());
    ADD_NAMED_REF_CHOICE_VARIANT("get-protocol-info", m_object, CBlast4_get_protocol_info_request);
    ADD_NAMED_REF_CHOICE_VARIANT("get-search-info", m_object, CBlast4_get_search_info_request);
    ADD_NAMED_REF_CHOICE_VARIANT("get-databases-ex", m_object, CBlast4_get_databases_ex_request);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CBlast4_request_body_Base::CBlast4_request_body_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CBlast4_request_body_Base::~CBlast4_request_body_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

