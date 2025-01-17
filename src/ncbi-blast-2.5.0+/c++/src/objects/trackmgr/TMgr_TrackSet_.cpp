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
#include <objects/trackmgr/TMgr_TrackSet.hpp>
#include <objects/trackmgr/TMgr_DisplayTrack.hpp>
#include <objects/trackmgr/TMgr_GenomeContext.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CTMgr_TrackSet_Base::ResetId(void)
{
    m_Id.erase();
    m_set_State[0] &= ~0xc;
}

void CTMgr_TrackSet_Base::ResetGenome_context(void)
{
    if ( !m_Genome_context ) {
        m_Genome_context.Reset(new TGenome_context());
        return;
    }
    (*m_Genome_context).Reset();
}

void CTMgr_TrackSet_Base::SetGenome_context(CTMgr_TrackSet_Base::TGenome_context& value)
{
    m_Genome_context.Reset(&value);
}

void CTMgr_TrackSet_Base::ResetName(void)
{
    m_Name.erase();
    m_set_State[0] &= ~0xc0;
}

void CTMgr_TrackSet_Base::ResetDescription(void)
{
    m_Description.erase();
    m_set_State[0] &= ~0x300;
}

void CTMgr_TrackSet_Base::ResetTracks(void)
{
    m_Tracks.clear();
    m_set_State[0] &= ~0xc00;
}

void CTMgr_TrackSet_Base::Reset(void)
{
    ResetType();
    ResetId();
    ResetGenome_context();
    ResetName();
    ResetDescription();
    ResetTracks();
}

BEGIN_NAMED_BASE_CLASS_INFO("TMgr-TrackSet", CTMgr_TrackSet)
{
    SET_CLASS_MODULE("NCBI-TrackManager");
    ADD_NAMED_ENUM_MEMBER("type", m_Type, ETMgr_TrackSetType)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("id", m_Id)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("genome-context", m_Genome_context, CTMgr_GenomeContext);
    ADD_NAMED_MEMBER("name", m_Name, CStringUTF8, ())->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("description", m_Description, CStringUTF8, ())->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("tracks", m_Tracks, STL_list, (STL_CRef, (CLASS, (CTMgr_DisplayTrack))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CTMgr_TrackSet_Base::CTMgr_TrackSet_Base(void)
    : m_Type((int)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetGenome_context();
    }
}

// destructor
CTMgr_TrackSet_Base::~CTMgr_TrackSet_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

