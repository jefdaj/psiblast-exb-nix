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
 *   'trackmgr.asn'.
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
#include <objects/trackmgr/TMgr_SwitchTrackContextReq.hpp>
#include <objects/trackmgr/TMgr_ClientInfo.hpp>
#include <objects/trackmgr/TMgr_DTrackId.hpp>
#include <objects/trackmgr/TMgr_GenomeContext.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CTMgr_SwitchTrackContextRequest_Base::ResetClient(void)
{
    if ( !m_Client ) {
        m_Client.Reset(new TClient());
        return;
    }
    (*m_Client).Reset();
}

void CTMgr_SwitchTrackContextRequest_Base::SetClient(CTMgr_SwitchTrackContextRequest_Base::TClient& value)
{
    m_Client.Reset(&value);
}

void CTMgr_SwitchTrackContextRequest_Base::ResetNew_genome_context(void)
{
    if ( !m_New_genome_context ) {
        m_New_genome_context.Reset(new TNew_genome_context());
        return;
    }
    (*m_New_genome_context).Reset();
}

void CTMgr_SwitchTrackContextRequest_Base::SetNew_genome_context(CTMgr_SwitchTrackContextRequest_Base::TNew_genome_context& value)
{
    m_New_genome_context.Reset(&value);
}

void CTMgr_SwitchTrackContextRequest_Base::ResetCurrent_dtrack_ids(void)
{
    m_Current_dtrack_ids.clear();
    m_set_State[0] &= ~0x30;
}

void CTMgr_SwitchTrackContextRequest_Base::Reset(void)
{
    ResetClient();
    ResetNew_genome_context();
    ResetCurrent_dtrack_ids();
    ResetAnnotation_release_number();
}

BEGIN_NAMED_BASE_CLASS_INFO("TMgr-SwitchTrackContextRequest", CTMgr_SwitchTrackContextRequest)
{
    SET_CLASS_MODULE("NCBI-TrackManager");
    ADD_NAMED_REF_MEMBER("client", m_Client, CTMgr_ClientInfo);
    ADD_NAMED_REF_MEMBER("new-genome-context", m_New_genome_context, CTMgr_GenomeContext);
    ADD_NAMED_MEMBER("current-dtrack-ids", m_Current_dtrack_ids, STL_list_set, (STL_CRef, (CLASS, (CTMgr_DTrackId))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("annotation-release-number", m_Annotation_release_number)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CTMgr_SwitchTrackContextRequest_Base::CTMgr_SwitchTrackContextRequest_Base(void)
    : m_Annotation_release_number(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetClient();
        ResetNew_genome_context();
    }
}

// destructor
CTMgr_SwitchTrackContextRequest_Base::~CTMgr_SwitchTrackContextRequest_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
