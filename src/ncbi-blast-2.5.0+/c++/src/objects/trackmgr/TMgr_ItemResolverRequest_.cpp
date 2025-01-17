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
#include <objects/trackmgr/TMgr_ItemResolverRequest.hpp>
#include <objects/seqloc/Seq_id.hpp>
#include <objects/trackmgr/TMgr_AttrSpec.hpp>
#include <objects/trackmgr/TMgr_ClientInfo.hpp>
#include <objects/trackmgr/TMgr_DTrackId.hpp>
#include <objects/trackmgr/TMgr_GenomeContext.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CTMgr_ItemResolverRequest_Base::C_Flags::Reset(void)
{
    ResetInclude_stats();
}

BEGIN_NAMED_CLASS_INFO("", CTMgr_ItemResolverRequest_Base::C_Flags)
{
    SET_INTERNAL_NAME("TMgr-ItemResolverRequest", "flags");
    SET_CLASS_MODULE("NCBI-TrackManager");
    ADD_NAMED_STD_MEMBER("include-stats", m_Include_stats)->SetDefault(new TInclude_stats(false))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CTMgr_ItemResolverRequest_Base::C_Flags::C_Flags(void)
    : m_Include_stats(false)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CTMgr_ItemResolverRequest_Base::C_Flags::~C_Flags(void)
{
}


void CTMgr_ItemResolverRequest_Base::ResetDtrack_ids(void)
{
    m_Dtrack_ids.clear();
    m_set_State[0] &= ~0x3;
}

void CTMgr_ItemResolverRequest_Base::ResetClient(void)
{
    if ( !m_Client ) {
        m_Client.Reset(new TClient());
        return;
    }
    (*m_Client).Reset();
}

void CTMgr_ItemResolverRequest_Base::SetClient(CTMgr_ItemResolverRequest_Base::TClient& value)
{
    m_Client.Reset(&value);
}

void CTMgr_ItemResolverRequest_Base::ResetGenome_context(void)
{
    if ( !m_Genome_context ) {
        m_Genome_context.Reset(new TGenome_context());
        return;
    }
    (*m_Genome_context).Reset();
}

void CTMgr_ItemResolverRequest_Base::SetGenome_context(CTMgr_ItemResolverRequest_Base::TGenome_context& value)
{
    m_Genome_context.Reset(&value);
}

void CTMgr_ItemResolverRequest_Base::ResetAttrs(void)
{
    m_Attrs.clear();
    m_set_State[0] &= ~0xc0;
}

void CTMgr_ItemResolverRequest_Base::ResetSequence(void)
{
    m_Sequence.Reset();
}

void CTMgr_ItemResolverRequest_Base::SetSequence(CTMgr_ItemResolverRequest_Base::TSequence& value)
{
    m_Sequence.Reset(&value);
}

CTMgr_ItemResolverRequest_Base::TSequence& CTMgr_ItemResolverRequest_Base::SetSequence(void)
{
    if ( !m_Sequence )
        m_Sequence.Reset(new ncbi::objects::CSeq_id());
    return (*m_Sequence);
}

void CTMgr_ItemResolverRequest_Base::ResetFlags(void)
{
    m_Flags.Reset();
}

void CTMgr_ItemResolverRequest_Base::SetFlags(CTMgr_ItemResolverRequest_Base::TFlags& value)
{
    m_Flags.Reset(&value);
}

CTMgr_ItemResolverRequest_Base::TFlags& CTMgr_ItemResolverRequest_Base::SetFlags(void)
{
    if ( !m_Flags )
        m_Flags.Reset(new C_Flags());
    return (*m_Flags);
}

void CTMgr_ItemResolverRequest_Base::Reset(void)
{
    ResetDtrack_ids();
    ResetClient();
    ResetGenome_context();
    ResetAttrs();
    ResetSequence();
    ResetFlags();
}

BEGIN_NAMED_BASE_CLASS_INFO("TMgr-ItemResolverRequest", CTMgr_ItemResolverRequest)
{
    SET_CLASS_MODULE("NCBI-TrackManager");
    ADD_NAMED_MEMBER("dtrack-ids", m_Dtrack_ids, STL_list_set, (STL_CRef, (CLASS, (CTMgr_DTrackId))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("client", m_Client, CTMgr_ClientInfo);
    ADD_NAMED_REF_MEMBER("genome-context", m_Genome_context, CTMgr_GenomeContext);
    ADD_NAMED_MEMBER("attrs", m_Attrs, STL_list_set, (STL_CRef, (CLASS, (CTMgr_AttrSpec))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("sequence", m_Sequence, CSeq_id)->SetOptional();
    ADD_NAMED_REF_MEMBER("flags", m_Flags, C_Flags)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CTMgr_ItemResolverRequest_Base::CTMgr_ItemResolverRequest_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetClient();
        ResetGenome_context();
    }
}

// destructor
CTMgr_ItemResolverRequest_Base::~CTMgr_ItemResolverRequest_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

