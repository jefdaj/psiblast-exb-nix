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
 *   'pcassay.asn'.
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
#include <objects/pcassay/PC_AssayDRAttr.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CPC_AssayDRAttr_Base::, EType, true)
{
    SET_ENUM_INTERNAL_NAME("PC-AssayDRAttr", "type");
    SET_ENUM_MODULE("NCBI-PCAssay");
    ADD_ENUM_VALUE("experimental", eType_experimental);
    ADD_ENUM_VALUE("calculated", eType_calculated);
}
END_ENUM_INFO

void CPC_AssayDRAttr_Base::ResetDescr(void)
{
    m_Descr.erase();
    m_set_State[0] &= ~0xc;
}

void CPC_AssayDRAttr_Base::ResetDn(void)
{
    m_Dn.erase();
    m_set_State[0] &= ~0x30;
}

void CPC_AssayDRAttr_Base::ResetRn(void)
{
    m_Rn.erase();
    m_set_State[0] &= ~0xc0;
}

void CPC_AssayDRAttr_Base::Reset(void)
{
    ResetId();
    ResetDescr();
    ResetDn();
    ResetRn();
    ResetType();
}

BEGIN_NAMED_BASE_CLASS_INFO("PC-AssayDRAttr", CPC_AssayDRAttr)
{
    SET_CLASS_MODULE("NCBI-PCAssay");
    ADD_NAMED_STD_MEMBER("id", m_Id)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("descr", m_Descr)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("dn", m_Dn)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("rn", m_Rn)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("type", m_Type, EType)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CPC_AssayDRAttr_Base::CPC_AssayDRAttr_Base(void)
    : m_Id(0), m_Type((EType)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CPC_AssayDRAttr_Base::~CPC_AssayDRAttr_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

