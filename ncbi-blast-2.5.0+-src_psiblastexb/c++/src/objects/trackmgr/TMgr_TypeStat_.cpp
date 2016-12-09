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
#include <objects/trackmgr/TMgr_TypeStat.hpp>
#include <objects/trackmgr/TMgr_LengthStats.hpp>
#include <objects/trackmgr/TMgr_PositionStats.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CTMgr_TypeStat_Base::ResetLength_stats(void)
{
    m_Length_stats.Reset();
}

void CTMgr_TypeStat_Base::SetLength_stats(CTMgr_TypeStat_Base::TLength_stats& value)
{
    m_Length_stats.Reset(&value);
}

CTMgr_TypeStat_Base::TLength_stats& CTMgr_TypeStat_Base::SetLength_stats(void)
{
    if ( !m_Length_stats )
        m_Length_stats.Reset(new ncbi::objects::CTMgr_LengthStats());
    return (*m_Length_stats);
}

void CTMgr_TypeStat_Base::ResetPosition_stats(void)
{
    m_Position_stats.Reset();
}

void CTMgr_TypeStat_Base::SetPosition_stats(CTMgr_TypeStat_Base::TPosition_stats& value)
{
    m_Position_stats.Reset(&value);
}

CTMgr_TypeStat_Base::TPosition_stats& CTMgr_TypeStat_Base::SetPosition_stats(void)
{
    if ( !m_Position_stats )
        m_Position_stats.Reset(new ncbi::objects::CTMgr_PositionStats());
    return (*m_Position_stats);
}

void CTMgr_TypeStat_Base::Reset(void)
{
    ResetType();
    ResetCount();
    ResetLength_stats();
    ResetPosition_stats();
}

BEGIN_NAMED_BASE_CLASS_INFO("TMgr-TypeStat", CTMgr_TypeStat)
{
    SET_CLASS_MODULE("NCBI-TrackManager");
    ADD_NAMED_ENUM_MEMBER("type", m_Type, ETMgr_AnnotType)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("count", m_Count)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("length-stats", m_Length_stats, CTMgr_LengthStats)->SetOptional();
    ADD_NAMED_REF_MEMBER("position-stats", m_Position_stats, CTMgr_PositionStats)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CTMgr_TypeStat_Base::CTMgr_TypeStat_Base(void)
    : m_Type((int)(0)), m_Count(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CTMgr_TypeStat_Base::~CTMgr_TypeStat_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
