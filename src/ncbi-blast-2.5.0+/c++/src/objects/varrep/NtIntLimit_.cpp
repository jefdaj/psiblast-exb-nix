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
 *   'varrep.asn'.
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
#include <objects/varrep/NtIntLimit.hpp>
#include <objects/varrep/NtSite.hpp>
#include <objects/varrep/NtSiteRange.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CNtIntLimit_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CNtIntLimit_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Site:
    case e_Range:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CNtIntLimit_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Site:
        (m_object = new(pool) ncbi::objects::CNtSite())->AddReference();
        break;
    case e_Range:
        (m_object = new(pool) ncbi::objects::CNtSiteRange())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CNtIntLimit_Base::sm_SelectionNames[] = {
    "not set",
    "site",
    "range"
};

NCBI_NS_STD::string CNtIntLimit_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CNtIntLimit_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CNtIntLimit_Base::TSite& CNtIntLimit_Base::GetSite(void) const
{
    CheckSelected(e_Site);
    return *static_cast<const TSite*>(m_object);
}

CNtIntLimit_Base::TSite& CNtIntLimit_Base::SetSite(void)
{
    Select(e_Site, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TSite*>(m_object);
}

void CNtIntLimit_Base::SetSite(CNtIntLimit_Base::TSite& value)
{
    TSite* ptr = &value;
    if ( m_choice != e_Site || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Site;
    }
}

const CNtIntLimit_Base::TRange& CNtIntLimit_Base::GetRange(void) const
{
    CheckSelected(e_Range);
    return *static_cast<const TRange*>(m_object);
}

CNtIntLimit_Base::TRange& CNtIntLimit_Base::SetRange(void)
{
    Select(e_Range, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TRange*>(m_object);
}

void CNtIntLimit_Base::SetRange(CNtIntLimit_Base::TRange& value)
{
    TRange* ptr = &value;
    if ( m_choice != e_Range || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Range;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("NtIntLimit", CNtIntLimit)
{
    SET_CHOICE_MODULE("NCBI-VariationIRep");
    ADD_NAMED_REF_CHOICE_VARIANT("site", m_object, CNtSite);
    ADD_NAMED_REF_CHOICE_VARIANT("range", m_object, CNtSiteRange);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CNtIntLimit_Base::CNtIntLimit_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CNtIntLimit_Base::~CNtIntLimit_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

