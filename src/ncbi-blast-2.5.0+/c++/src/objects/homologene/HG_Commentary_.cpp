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
 *   'homologene.asn'.
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
#include <objects/homologene/HG_Commentary.hpp>
#include <objects/homologene/HG_Link.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CHG_Commentary_Base::ResetLink(void)
{
    if ( !m_Link ) {
        m_Link.Reset(new TLink());
        return;
    }
    (*m_Link).Reset();
}

void CHG_Commentary_Base::SetLink(CHG_Commentary_Base::TLink& value)
{
    m_Link.Reset(&value);
}

void CHG_Commentary_Base::ResetDescription(void)
{
    m_Description.erase();
    m_set_State[0] &= ~0xc;
}

void CHG_Commentary_Base::ResetCaption(void)
{
    m_Caption.erase();
    m_set_State[0] &= ~0x30;
}

void CHG_Commentary_Base::ResetProvider(void)
{
    m_Provider.erase();
    m_set_State[0] &= ~0xc0;
}

void CHG_Commentary_Base::ResetOther_links(void)
{
    m_Other_links.clear();
    m_set_State[0] &= ~0x300;
}

void CHG_Commentary_Base::ResetOther_commentaries(void)
{
    m_Other_commentaries.clear();
    m_set_State[0] &= ~0xc00;
}

void CHG_Commentary_Base::Reset(void)
{
    ResetLink();
    ResetDescription();
    ResetCaption();
    ResetProvider();
    ResetOther_links();
    ResetOther_commentaries();
    ResetTaxid();
    ResetGeneid();
}

BEGIN_NAMED_BASE_CLASS_INFO("HG-Commentary", CHG_Commentary)
{
    SET_CLASS_MODULE("HomoloGene");
    ADD_NAMED_REF_MEMBER("link", m_Link, CHG_Link);
    ADD_NAMED_STD_MEMBER("description", m_Description)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("caption", m_Caption)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("provider", m_Provider)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("other-links", m_Other_links, STL_list_set, (STL_CRef, (CLASS, (CHG_Link))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("other-commentaries", m_Other_commentaries, STL_list_set, (STL_CRef, (CLASS, (CHG_Commentary))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("taxid", m_Taxid)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("geneid", m_Geneid)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CHG_Commentary_Base::CHG_Commentary_Base(void)
    : m_Taxid(0), m_Geneid(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetLink();
    }
}

// destructor
CHG_Commentary_Base::~CHG_Commentary_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

