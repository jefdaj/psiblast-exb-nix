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
#include <objects/homologene/HG_Entry.hpp>
#include <objects/general/Date.hpp>
#include <objects/homologene/HG_CommentarySet.hpp>
#include <objects/homologene/HG_Gene.hpp>
#include <objects/homologene/HG_Node.hpp>
#include <objects/homologene/HG_Stats.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CHG_Entry_Base::ResetTitle(void)
{
    m_Title.erase();
    m_set_State[0] &= ~0x30;
}

void CHG_Entry_Base::ResetCaption(void)
{
    m_Caption.erase();
    m_set_State[0] &= ~0xc0;
}

void CHG_Entry_Base::ResetGenes(void)
{
    m_Genes.clear();
    m_set_State[0] &= ~0xc00;
}

void CHG_Entry_Base::ResetCr_date(void)
{
    m_Cr_date.Reset();
}

void CHG_Entry_Base::SetCr_date(CHG_Entry_Base::TCr_date& value)
{
    m_Cr_date.Reset(&value);
}

CHG_Entry_Base::TCr_date& CHG_Entry_Base::SetCr_date(void)
{
    if ( !m_Cr_date )
        m_Cr_date.Reset(new ncbi::objects::CDate());
    return (*m_Cr_date);
}

void CHG_Entry_Base::ResetUp_date(void)
{
    m_Up_date.Reset();
}

void CHG_Entry_Base::SetUp_date(CHG_Entry_Base::TUp_date& value)
{
    m_Up_date.Reset(&value);
}

CHG_Entry_Base::TUp_date& CHG_Entry_Base::SetUp_date(void)
{
    if ( !m_Up_date )
        m_Up_date.Reset(new ncbi::objects::CDate());
    return (*m_Up_date);
}

void CHG_Entry_Base::ResetDistances(void)
{
    m_Distances.clear();
    m_set_State[0] &= ~0x30000;
}

void CHG_Entry_Base::ResetCommentaries(void)
{
    m_Commentaries.clear();
    m_set_State[0] &= ~0xc0000;
}

void CHG_Entry_Base::ResetWarnings(void)
{
    m_Warnings.clear();
    m_set_State[0] &= ~0x300000;
}

void CHG_Entry_Base::ResetNode(void)
{
    m_Node.Reset();
}

void CHG_Entry_Base::SetNode(CHG_Entry_Base::TNode& value)
{
    m_Node.Reset(&value);
}

CHG_Entry_Base::TNode& CHG_Entry_Base::SetNode(void)
{
    if ( !m_Node )
        m_Node.Reset(new ncbi::objects::CHG_Node());
    return (*m_Node);
}

void CHG_Entry_Base::Reset(void)
{
    ResetHg_id();
    ResetVersion();
    ResetTitle();
    ResetCaption();
    ResetTaxid();
    ResetGenes();
    ResetCr_date();
    ResetUp_date();
    ResetDistances();
    ResetCommentaries();
    ResetWarnings();
    ResetNode();
}

BEGIN_NAMED_BASE_CLASS_INFO("HG-Entry", CHG_Entry)
{
    SET_CLASS_MODULE("HomoloGene");
    ADD_NAMED_STD_MEMBER("hg-id", m_Hg_id)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("version", m_Version)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("title", m_Title)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("caption", m_Caption)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("taxid", m_Taxid)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("genes", m_Genes, STL_list_set, (STL_CRef, (CLASS, (CHG_Gene))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("cr-date", m_Cr_date, CDate)->SetOptional();
    ADD_NAMED_REF_MEMBER("up-date", m_Up_date, CDate)->SetOptional();
    ADD_NAMED_MEMBER("distances", m_Distances, STL_list_set, (STL_CRef, (CLASS, (CHG_Stats))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("commentaries", m_Commentaries, STL_list_set, (STL_CRef, (CLASS, (CHG_CommentarySet))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("warnings", m_Warnings, STL_list_set, (STD, (string)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("node", m_Node, CHG_Node)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CHG_Entry_Base::CHG_Entry_Base(void)
    : m_Hg_id(0), m_Version(0), m_Taxid(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CHG_Entry_Base::~CHG_Entry_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

