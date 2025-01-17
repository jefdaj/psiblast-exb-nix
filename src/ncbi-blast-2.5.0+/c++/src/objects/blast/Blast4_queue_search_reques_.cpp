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
#include <objects/blast/Blast4_queue_search_reques.hpp>
#include <objects/blast/Blast4_parameters.hpp>
#include <objects/blast/Blast4_queries.hpp>
#include <objects/blast/Blast4_subject.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBlast4_queue_search_request_Base::ResetProgram(void)
{
    m_Program.erase();
    m_set_State[0] &= ~0x3;
}

void CBlast4_queue_search_request_Base::ResetService(void)
{
    m_Service.erase();
    m_set_State[0] &= ~0xc;
}

void CBlast4_queue_search_request_Base::ResetQueries(void)
{
    if ( !m_Queries ) {
        m_Queries.Reset(new TQueries());
        return;
    }
    (*m_Queries).Reset();
}

void CBlast4_queue_search_request_Base::SetQueries(CBlast4_queue_search_request_Base::TQueries& value)
{
    m_Queries.Reset(&value);
}

void CBlast4_queue_search_request_Base::ResetSubject(void)
{
    if ( !m_Subject ) {
        m_Subject.Reset(new TSubject());
        return;
    }
    (*m_Subject).Reset();
}

void CBlast4_queue_search_request_Base::SetSubject(CBlast4_queue_search_request_Base::TSubject& value)
{
    m_Subject.Reset(&value);
}

void CBlast4_queue_search_request_Base::ResetParamset(void)
{
    m_Paramset.erase();
    m_set_State[0] &= ~0x300;
}

void CBlast4_queue_search_request_Base::ResetAlgorithm_options(void)
{
    m_Algorithm_options.Reset();
}

void CBlast4_queue_search_request_Base::SetAlgorithm_options(CBlast4_queue_search_request_Base::TAlgorithm_options& value)
{
    m_Algorithm_options.Reset(&value);
}

CBlast4_queue_search_request_Base::TAlgorithm_options& CBlast4_queue_search_request_Base::SetAlgorithm_options(void)
{
    if ( !m_Algorithm_options )
        m_Algorithm_options.Reset(new ncbi::objects::CBlast4_parameters());
    return (*m_Algorithm_options);
}

void CBlast4_queue_search_request_Base::ResetProgram_options(void)
{
    m_Program_options.Reset();
}

void CBlast4_queue_search_request_Base::SetProgram_options(CBlast4_queue_search_request_Base::TProgram_options& value)
{
    m_Program_options.Reset(&value);
}

CBlast4_queue_search_request_Base::TProgram_options& CBlast4_queue_search_request_Base::SetProgram_options(void)
{
    if ( !m_Program_options )
        m_Program_options.Reset(new ncbi::objects::CBlast4_parameters());
    return (*m_Program_options);
}

void CBlast4_queue_search_request_Base::ResetFormat_options(void)
{
    m_Format_options.Reset();
}

void CBlast4_queue_search_request_Base::SetFormat_options(CBlast4_queue_search_request_Base::TFormat_options& value)
{
    m_Format_options.Reset(&value);
}

CBlast4_queue_search_request_Base::TFormat_options& CBlast4_queue_search_request_Base::SetFormat_options(void)
{
    if ( !m_Format_options )
        m_Format_options.Reset(new ncbi::objects::CBlast4_parameters());
    return (*m_Format_options);
}

void CBlast4_queue_search_request_Base::Reset(void)
{
    ResetProgram();
    ResetService();
    ResetQueries();
    ResetSubject();
    ResetParamset();
    ResetAlgorithm_options();
    ResetProgram_options();
    ResetFormat_options();
}

BEGIN_NAMED_BASE_CLASS_INFO("Blast4-queue-search-request", CBlast4_queue_search_request)
{
    SET_CLASS_MODULE("NCBI-Blast4");
    ADD_NAMED_STD_MEMBER("program", m_Program)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("service", m_Service)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("queries", m_Queries, CBlast4_queries);
    ADD_NAMED_REF_MEMBER("subject", m_Subject, CBlast4_subject);
    ADD_NAMED_STD_MEMBER("paramset", m_Paramset)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("algorithm-options", m_Algorithm_options, CBlast4_parameters)->SetOptional();
    ADD_NAMED_REF_MEMBER("program-options", m_Program_options, CBlast4_parameters)->SetOptional();
    ADD_NAMED_REF_MEMBER("format-options", m_Format_options, CBlast4_parameters)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CBlast4_queue_search_request_Base::CBlast4_queue_search_request_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetQueries();
        ResetSubject();
    }
}

// destructor
CBlast4_queue_search_request_Base::~CBlast4_queue_search_request_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

