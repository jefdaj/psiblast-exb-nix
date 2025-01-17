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
#include <objects/biblio/Affil.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CAffil_Base::C_Std::ResetAffil(void)
{
    m_Affil.erase();
    m_set_State[0] &= ~0x3;
}

void CAffil_Base::C_Std::ResetDiv(void)
{
    m_Div.erase();
    m_set_State[0] &= ~0xc;
}

void CAffil_Base::C_Std::ResetCity(void)
{
    m_City.erase();
    m_set_State[0] &= ~0x30;
}

void CAffil_Base::C_Std::ResetSub(void)
{
    m_Sub.erase();
    m_set_State[0] &= ~0xc0;
}

void CAffil_Base::C_Std::ResetCountry(void)
{
    m_Country.erase();
    m_set_State[0] &= ~0x300;
}

void CAffil_Base::C_Std::ResetStreet(void)
{
    m_Street.erase();
    m_set_State[0] &= ~0xc00;
}

void CAffil_Base::C_Std::ResetEmail(void)
{
    m_Email.erase();
    m_set_State[0] &= ~0x3000;
}

void CAffil_Base::C_Std::ResetFax(void)
{
    m_Fax.erase();
    m_set_State[0] &= ~0xc000;
}

void CAffil_Base::C_Std::ResetPhone(void)
{
    m_Phone.erase();
    m_set_State[0] &= ~0x30000;
}

void CAffil_Base::C_Std::ResetPostal_code(void)
{
    m_Postal_code.erase();
    m_set_State[0] &= ~0xc0000;
}

void CAffil_Base::C_Std::Reset(void)
{
    ResetAffil();
    ResetDiv();
    ResetCity();
    ResetSub();
    ResetCountry();
    ResetStreet();
    ResetEmail();
    ResetFax();
    ResetPhone();
    ResetPostal_code();
}

BEGIN_NAMED_CLASS_INFO("", CAffil_Base::C_Std)
{
    SET_INTERNAL_NAME("Affil", "std");
    SET_CLASS_MODULE("NCBI-Biblio");
    ADD_NAMED_STD_MEMBER("affil", m_Affil)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("div", m_Div)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("city", m_City)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("sub", m_Sub)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("country", m_Country)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("street", m_Street)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("email", m_Email)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("fax", m_Fax)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("phone", m_Phone)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("postal-code", m_Postal_code)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CAffil_Base::C_Std::C_Std(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CAffil_Base::C_Std::~C_Std(void)
{
}


void CAffil_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CAffil_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Str:
        m_string.Destruct();
        break;
    case e_Std:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CAffil_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Std:
        (m_object = new(pool) C_Std())->AddReference();
        break;
    case e_Str:
        m_string.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CAffil_Base::sm_SelectionNames[] = {
    "not set",
    "str",
    "std"
};

NCBI_NS_STD::string CAffil_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CAffil_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CAffil_Base::SetStr(const CAffil_Base::TStr& value)
{
    Select(e_Str, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

const CAffil_Base::TStd& CAffil_Base::GetStd(void) const
{
    CheckSelected(e_Std);
    return *static_cast<const TStd*>(m_object);
}

CAffil_Base::TStd& CAffil_Base::SetStd(void)
{
    Select(e_Std, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TStd*>(m_object);
}

void CAffil_Base::SetStd(CAffil_Base::TStd& value)
{
    TStd* ptr = &value;
    if ( m_choice != e_Std || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Std;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Affil", CAffil)
{
    SET_CHOICE_MODULE("NCBI-Biblio");
    ADD_NAMED_BUF_CHOICE_VARIANT("str", m_string, STD, (string));
    ADD_NAMED_REF_CHOICE_VARIANT("std", m_object, C_Std);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CAffil_Base::CAffil_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CAffil_Base::~CAffil_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

