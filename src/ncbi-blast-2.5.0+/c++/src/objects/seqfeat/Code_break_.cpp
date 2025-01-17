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
 *   'seqfeat.asn'.
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
#include <objects/seqfeat/Code_break.hpp>
#include <objects/seqloc/Seq_loc.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CCode_break_Base::C_Aa::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CCode_break_Base::C_Aa::ResetSelection(void)
{
    m_choice = e_not_set;
}

void CCode_break_Base::C_Aa::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* )
{
    switch ( index ) {
    case e_Ncbieaa:
        m_Ncbieaa = 0;
        break;
    case e_Ncbi8aa:
        m_Ncbi8aa = 0;
        break;
    case e_Ncbistdaa:
        m_Ncbistdaa = 0;
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CCode_break_Base::C_Aa::sm_SelectionNames[] = {
    "not set",
    "ncbieaa",
    "ncbi8aa",
    "ncbistdaa"
};

NCBI_NS_STD::string CCode_break_Base::C_Aa::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CCode_break_Base::C_Aa::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

// helper methods

// type info
BEGIN_NAMED_CHOICE_INFO("", CCode_break_Base::C_Aa)
{
    SET_INTERNAL_NAME("Code-break", "aa");
    SET_CHOICE_MODULE("NCBI-Seqfeat");
    ADD_NAMED_STD_CHOICE_VARIANT("ncbieaa", m_Ncbieaa);
    ADD_NAMED_STD_CHOICE_VARIANT("ncbi8aa", m_Ncbi8aa);
    ADD_NAMED_STD_CHOICE_VARIANT("ncbistdaa", m_Ncbistdaa);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CCode_break_Base::C_Aa::C_Aa(void)
    : m_choice(e_not_set)
{
}

// destructor
CCode_break_Base::C_Aa::~C_Aa(void)
{
    Reset();
}


void CCode_break_Base::ResetLoc(void)
{
    if ( !m_Loc ) {
        m_Loc.Reset(new TLoc());
        return;
    }
    (*m_Loc).Reset();
}

void CCode_break_Base::SetLoc(CCode_break_Base::TLoc& value)
{
    m_Loc.Reset(&value);
}

void CCode_break_Base::ResetAa(void)
{
    if ( !m_Aa ) {
        m_Aa.Reset(new TAa());
        return;
    }
    (*m_Aa).Reset();
}

void CCode_break_Base::SetAa(CCode_break_Base::TAa& value)
{
    m_Aa.Reset(&value);
}

void CCode_break_Base::Reset(void)
{
    ResetLoc();
    ResetAa();
}

BEGIN_NAMED_BASE_CLASS_INFO("Code-break", CCode_break)
{
    SET_CLASS_MODULE("NCBI-Seqfeat");
    ADD_NAMED_REF_MEMBER("loc", m_Loc, CSeq_loc);
    ADD_NAMED_REF_MEMBER("aa", m_Aa, C_Aa);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CCode_break_Base::CCode_break_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetLoc();
        ResetAa();
    }
}

// destructor
CCode_break_Base::~CCode_break_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

