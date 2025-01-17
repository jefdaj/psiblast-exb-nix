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
 *   'pcsubstance.asn'.
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
#include <objects/pcsubstance/PC_Conformer.hpp>
#include <objects/pcsubstance/PC_DrawAnnotations.hpp>
#include <objects/pcsubstance/PC_InfoData.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPC_Conformer_Base::ResetX(void)
{
    m_X.clear();
    m_set_State[0] &= ~0x3;
}

void CPC_Conformer_Base::ResetY(void)
{
    m_Y.clear();
    m_set_State[0] &= ~0xc;
}

void CPC_Conformer_Base::ResetZ(void)
{
    m_Z.clear();
    m_set_State[0] &= ~0x30;
}

void CPC_Conformer_Base::ResetStyle(void)
{
    m_Style.Reset();
}

void CPC_Conformer_Base::SetStyle(CPC_Conformer_Base::TStyle& value)
{
    m_Style.Reset(&value);
}

CPC_Conformer_Base::TStyle& CPC_Conformer_Base::SetStyle(void)
{
    if ( !m_Style )
        m_Style.Reset(new ncbi::objects::CPC_DrawAnnotations());
    return (*m_Style);
}

void CPC_Conformer_Base::ResetData(void)
{
    m_Data.clear();
    m_set_State[0] &= ~0x300;
}

void CPC_Conformer_Base::Reset(void)
{
    ResetX();
    ResetY();
    ResetZ();
    ResetStyle();
    ResetData();
}

BEGIN_NAMED_BASE_CLASS_INFO("PC-Conformer", CPC_Conformer)
{
    SET_CLASS_MODULE("NCBI-PCSubstance");
    ADD_NAMED_MEMBER("x", m_X, STL_vector, (STD, (double)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("y", m_Y, STL_vector, (STD, (double)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("z", m_Z, STL_vector, (STD, (double)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("style", m_Style, CPC_DrawAnnotations)->SetOptional();
    ADD_NAMED_MEMBER("data", m_Data, STL_list, (STL_CRef, (CLASS, (CPC_InfoData))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CPC_Conformer_Base::CPC_Conformer_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CPC_Conformer_Base::~CPC_Conformer_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

