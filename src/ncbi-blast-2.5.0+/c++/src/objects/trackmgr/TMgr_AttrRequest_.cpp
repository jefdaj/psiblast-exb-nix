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
#include <objects/trackmgr/TMgr_AttrRequest.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CTMgr_AttrRequest_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CTMgr_AttrRequest_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Track_type_list:
        m_Track_type_list.Destruct();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CTMgr_AttrRequest_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* )
{
    switch ( index ) {
    case e_Track_type_list:
        m_Track_type_list.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CTMgr_AttrRequest_Base::sm_SelectionNames[] = {
    "not set",
    "all-attrs",
    "track-type-list"
};

NCBI_NS_STD::string CTMgr_AttrRequest_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CTMgr_AttrRequest_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("TMgr-AttrRequest", CTMgr_AttrRequest)
{
    SET_CHOICE_MODULE("NCBI-TrackManager");
    ADD_NAMED_NULL_CHOICE_VARIANT("all-attrs", null, ());
    ADD_NAMED_BUF_CHOICE_VARIANT("track-type-list", m_Track_type_list, STL_list_set, (STD, (string)));
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CTMgr_AttrRequest_Base::CTMgr_AttrRequest_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CTMgr_AttrRequest_Base::~CTMgr_AttrRequest_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

