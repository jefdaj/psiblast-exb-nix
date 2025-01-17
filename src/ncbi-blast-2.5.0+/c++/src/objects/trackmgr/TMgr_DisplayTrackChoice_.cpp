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
#include <objects/trackmgr/TMgr_DisplayTrackChoice.hpp>
#include <objects/trackmgr/TMgr_DisplayTrack.hpp>
#include <objects/trackmgr/TMgr_SwitchTrackException.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CTMgr_DisplayTrackChoice_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CTMgr_DisplayTrackChoice_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Track:
    case e_Switch_exception:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CTMgr_DisplayTrackChoice_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Track:
        (m_object = new(pool) ncbi::objects::CTMgr_DisplayTrack())->AddReference();
        break;
    case e_Switch_exception:
        (m_object = new(pool) ncbi::objects::CTMgr_SwitchTrackException())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CTMgr_DisplayTrackChoice_Base::sm_SelectionNames[] = {
    "not set",
    "track",
    "switch-exception"
};

NCBI_NS_STD::string CTMgr_DisplayTrackChoice_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CTMgr_DisplayTrackChoice_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CTMgr_DisplayTrackChoice_Base::TTrack& CTMgr_DisplayTrackChoice_Base::GetTrack(void) const
{
    CheckSelected(e_Track);
    return *static_cast<const TTrack*>(m_object);
}

CTMgr_DisplayTrackChoice_Base::TTrack& CTMgr_DisplayTrackChoice_Base::SetTrack(void)
{
    Select(e_Track, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TTrack*>(m_object);
}

void CTMgr_DisplayTrackChoice_Base::SetTrack(CTMgr_DisplayTrackChoice_Base::TTrack& value)
{
    TTrack* ptr = &value;
    if ( m_choice != e_Track || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Track;
    }
}

const CTMgr_DisplayTrackChoice_Base::TSwitch_exception& CTMgr_DisplayTrackChoice_Base::GetSwitch_exception(void) const
{
    CheckSelected(e_Switch_exception);
    return *static_cast<const TSwitch_exception*>(m_object);
}

CTMgr_DisplayTrackChoice_Base::TSwitch_exception& CTMgr_DisplayTrackChoice_Base::SetSwitch_exception(void)
{
    Select(e_Switch_exception, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TSwitch_exception*>(m_object);
}

void CTMgr_DisplayTrackChoice_Base::SetSwitch_exception(CTMgr_DisplayTrackChoice_Base::TSwitch_exception& value)
{
    TSwitch_exception* ptr = &value;
    if ( m_choice != e_Switch_exception || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Switch_exception;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("TMgr-DisplayTrackChoice", CTMgr_DisplayTrackChoice)
{
    SET_CHOICE_MODULE("NCBI-TrackManager");
    ADD_NAMED_REF_CHOICE_VARIANT("track", m_object, CTMgr_DisplayTrack);
    ADD_NAMED_REF_CHOICE_VARIANT("switch-exception", m_object, CTMgr_SwitchTrackException);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CTMgr_DisplayTrackChoice_Base::CTMgr_DisplayTrackChoice_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CTMgr_DisplayTrackChoice_Base::~CTMgr_DisplayTrackChoice_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

