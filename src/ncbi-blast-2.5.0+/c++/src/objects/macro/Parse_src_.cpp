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
 *   'macro.asn'.
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
#include <objects/macro/Parse_src.hpp>
#include <objects/macro/Parse_src_general_id.hpp>
#include <objects/macro/Parse_src_org.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CParse_src_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CParse_src_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Structured_comment:
        m_string.Destruct();
        break;
    case e_Org:
    case e_General_id:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CParse_src_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Org:
        (m_object = new(pool) ncbi::objects::CParse_src_org())->AddReference();
        break;
    case e_General_id:
        (m_object = new(pool) ncbi::objects::CParse_src_general_id())->AddReference();
        break;
    case e_Structured_comment:
        m_string.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CParse_src_Base::sm_SelectionNames[] = {
    "not set",
    "defline",
    "flatfile",
    "local-id",
    "org",
    "comment",
    "bankit-comment",
    "structured-comment",
    "file-id",
    "general-id"
};

NCBI_NS_STD::string CParse_src_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CParse_src_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CParse_src_Base::TOrg& CParse_src_Base::GetOrg(void) const
{
    CheckSelected(e_Org);
    return *static_cast<const TOrg*>(m_object);
}

CParse_src_Base::TOrg& CParse_src_Base::SetOrg(void)
{
    Select(e_Org, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TOrg*>(m_object);
}

void CParse_src_Base::SetOrg(CParse_src_Base::TOrg& value)
{
    TOrg* ptr = &value;
    if ( m_choice != e_Org || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Org;
    }
}

void CParse_src_Base::SetStructured_comment(const CParse_src_Base::TStructured_comment& value)
{
    Select(e_Structured_comment, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

const CParse_src_Base::TGeneral_id& CParse_src_Base::GetGeneral_id(void) const
{
    CheckSelected(e_General_id);
    return *static_cast<const TGeneral_id*>(m_object);
}

CParse_src_Base::TGeneral_id& CParse_src_Base::SetGeneral_id(void)
{
    Select(e_General_id, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGeneral_id*>(m_object);
}

void CParse_src_Base::SetGeneral_id(CParse_src_Base::TGeneral_id& value)
{
    TGeneral_id* ptr = &value;
    if ( m_choice != e_General_id || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_General_id;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Parse-src", CParse_src)
{
    SET_CHOICE_MODULE("NCBI-Macro");
    ADD_NAMED_NULL_CHOICE_VARIANT("defline", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("flatfile", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("local-id", null, ());
    ADD_NAMED_REF_CHOICE_VARIANT("org", m_object, CParse_src_org);
    ADD_NAMED_NULL_CHOICE_VARIANT("comment", null, ());
    ADD_NAMED_NULL_CHOICE_VARIANT("bankit-comment", null, ());
    ADD_NAMED_BUF_CHOICE_VARIANT("structured-comment", m_string, STD, (string));
    ADD_NAMED_NULL_CHOICE_VARIANT("file-id", null, ());
    ADD_NAMED_REF_CHOICE_VARIANT("general-id", m_object, CParse_src_general_id);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CParse_src_Base::CParse_src_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CParse_src_Base::~CParse_src_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

