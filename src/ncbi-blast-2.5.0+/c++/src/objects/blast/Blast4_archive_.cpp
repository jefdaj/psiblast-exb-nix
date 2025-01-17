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
#include <objects/blast/Blast4_archive.hpp>
#include <objects/blast/Blas_get_searc_resul_reply.hpp>
#include <objects/blast/Blast4_error.hpp>
#include <objects/blast/Blast4_request.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBlast4_archive_Base::ResetRequest(void)
{
    if ( !m_Request ) {
        m_Request.Reset(new TRequest());
        return;
    }
    (*m_Request).Reset();
}

void CBlast4_archive_Base::SetRequest(CBlast4_archive_Base::TRequest& value)
{
    m_Request.Reset(&value);
}

void CBlast4_archive_Base::ResetResults(void)
{
    if ( !m_Results ) {
        m_Results.Reset(new TResults());
        return;
    }
    (*m_Results).Reset();
}

void CBlast4_archive_Base::SetResults(CBlast4_archive_Base::TResults& value)
{
    m_Results.Reset(&value);
}

void CBlast4_archive_Base::ResetMessages(void)
{
    m_Messages.clear();
    m_set_State[0] &= ~0x30;
}

void CBlast4_archive_Base::Reset(void)
{
    ResetRequest();
    ResetResults();
    ResetMessages();
}

BEGIN_NAMED_BASE_CLASS_INFO("Blast4-archive", CBlast4_archive)
{
    SET_CLASS_MODULE("NCBI-Blast4");
    ADD_NAMED_REF_MEMBER("request", m_Request, CBlast4_request);
    ADD_NAMED_REF_MEMBER("results", m_Results, CBlast4_get_search_results_reply);
    ADD_NAMED_MEMBER("messages", m_Messages, STL_list, (STL_CRef, (CLASS, (CBlast4_error))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CBlast4_archive_Base::CBlast4_archive_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetRequest();
        ResetResults();
    }
}

// destructor
CBlast4_archive_Base::~CBlast4_archive_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

