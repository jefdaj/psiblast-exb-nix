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
#include <objects/seqfeat/Gene_nomenclature.hpp>
#include <objects/general/Dbtag.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CGene_nomenclature_Base::, EStatus, false)
{
    SET_ENUM_INTERNAL_NAME("Gene-nomenclature", "status");
    SET_ENUM_MODULE("NCBI-Gene");
    ADD_ENUM_VALUE("unknown", eStatus_unknown);
    ADD_ENUM_VALUE("official", eStatus_official);
    ADD_ENUM_VALUE("interim", eStatus_interim);
}
END_ENUM_INFO

void CGene_nomenclature_Base::ResetSymbol(void)
{
    m_Symbol.erase();
    m_set_State[0] &= ~0xc;
}

void CGene_nomenclature_Base::ResetName(void)
{
    m_Name.erase();
    m_set_State[0] &= ~0x30;
}

void CGene_nomenclature_Base::ResetSource(void)
{
    m_Source.Reset();
}

void CGene_nomenclature_Base::SetSource(CGene_nomenclature_Base::TSource& value)
{
    m_Source.Reset(&value);
}

CGene_nomenclature_Base::TSource& CGene_nomenclature_Base::SetSource(void)
{
    if ( !m_Source )
        m_Source.Reset(new ncbi::objects::CDbtag());
    return (*m_Source);
}

void CGene_nomenclature_Base::Reset(void)
{
    ResetStatus();
    ResetSymbol();
    ResetName();
    ResetSource();
}

BEGIN_NAMED_BASE_CLASS_INFO("Gene-nomenclature", CGene_nomenclature)
{
    SET_CLASS_MODULE("NCBI-Gene");
    ADD_NAMED_ENUM_MEMBER("status", m_Status, EStatus)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("symbol", m_Symbol)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("name", m_Name)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("source", m_Source, CDbtag)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CGene_nomenclature_Base::CGene_nomenclature_Base(void)
    : m_Status((EStatus)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CGene_nomenclature_Base::~CGene_nomenclature_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
