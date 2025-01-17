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
 *   'biblio.asn'.
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
#include <objects/biblio/Id_pat.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CId_pat_Base::C_Id::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CId_pat_Base::C_Id::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Number:
    case e_App_number:
        m_string.Destruct();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CId_pat_Base::C_Id::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* )
{
    switch ( index ) {
    case e_Number:
    case e_App_number:
        m_string.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CId_pat_Base::C_Id::sm_SelectionNames[] = {
    "not set",
    "number",
    "app-number"
};

NCBI_NS_STD::string CId_pat_Base::C_Id::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CId_pat_Base::C_Id::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CId_pat_Base::C_Id::SetNumber(const CId_pat_Base::C_Id::TNumber& value)
{
    Select(e_Number, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

void CId_pat_Base::C_Id::SetApp_number(const CId_pat_Base::C_Id::TApp_number& value)
{
    Select(e_App_number, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

// helper methods

// type info
BEGIN_NAMED_CHOICE_INFO("", CId_pat_Base::C_Id)
{
    SET_INTERNAL_NAME("Id-pat", "id");
    SET_CHOICE_MODULE("NCBI-Biblio");
    ADD_NAMED_BUF_CHOICE_VARIANT("number", m_string, STD, (string));
    ADD_NAMED_BUF_CHOICE_VARIANT("app-number", m_string, STD, (string));
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CId_pat_Base::C_Id::C_Id(void)
    : m_choice(e_not_set)
{
}

// destructor
CId_pat_Base::C_Id::~C_Id(void)
{
    Reset();
}


void CId_pat_Base::ResetCountry(void)
{
    m_Country.erase();
    m_set_State[0] &= ~0x3;
}

void CId_pat_Base::ResetId(void)
{
    if ( !m_Id ) {
        m_Id.Reset(new TId());
        return;
    }
    (*m_Id).Reset();
}

void CId_pat_Base::SetId(CId_pat_Base::TId& value)
{
    m_Id.Reset(&value);
}

void CId_pat_Base::ResetDoc_type(void)
{
    m_Doc_type.erase();
    m_set_State[0] &= ~0x30;
}

void CId_pat_Base::Reset(void)
{
    ResetCountry();
    ResetId();
    ResetDoc_type();
}

BEGIN_NAMED_BASE_CLASS_INFO("Id-pat", CId_pat)
{
    SET_CLASS_MODULE("NCBI-Biblio");
    ADD_NAMED_STD_MEMBER("country", m_Country)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("id", m_Id, C_Id);
    ADD_NAMED_STD_MEMBER("doc-type", m_Doc_type)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CId_pat_Base::CId_pat_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetId();
    }
}

// destructor
CId_pat_Base::~CId_pat_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

