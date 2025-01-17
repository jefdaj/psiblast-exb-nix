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
 *   'valid.asn'.
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
#include <objects/valid/Comment_rule.hpp>
#include <objects/valid/Dependent_field_set.hpp>
#include <objects/valid/Field_set.hpp>
#include <objects/valid/Phrase_list.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CComment_rule_Base::ResetPrefix(void)
{
    m_Prefix.erase();
    m_set_State[0] &= ~0x3;
}

void CComment_rule_Base::ResetFields(void)
{
    if ( !m_Fields ) {
        m_Fields.Reset(new TFields());
        return;
    }
    (*m_Fields).Reset();
}

void CComment_rule_Base::SetFields(CComment_rule_Base::TFields& value)
{
    m_Fields.Reset(&value);
}

void CComment_rule_Base::ResetDependent_rules(void)
{
    m_Dependent_rules.Reset();
}

void CComment_rule_Base::SetDependent_rules(CComment_rule_Base::TDependent_rules& value)
{
    m_Dependent_rules.Reset(&value);
}

CComment_rule_Base::TDependent_rules& CComment_rule_Base::SetDependent_rules(void)
{
    if ( !m_Dependent_rules )
        m_Dependent_rules.Reset(new ncbi::objects::CDependent_field_set());
    return (*m_Dependent_rules);
}

void CComment_rule_Base::ResetForbidden_phrases(void)
{
    m_Forbidden_phrases.Reset();
}

void CComment_rule_Base::SetForbidden_phrases(CComment_rule_Base::TForbidden_phrases& value)
{
    m_Forbidden_phrases.Reset(&value);
}

CComment_rule_Base::TForbidden_phrases& CComment_rule_Base::SetForbidden_phrases(void)
{
    if ( !m_Forbidden_phrases )
        m_Forbidden_phrases.Reset(new ncbi::objects::CPhrase_list());
    return (*m_Forbidden_phrases);
}

void CComment_rule_Base::Reset(void)
{
    ResetPrefix();
    ResetUpdated();
    ResetFields();
    ResetRequire_order();
    ResetAllow_unlisted();
    ResetDependent_rules();
    ResetForbidden_phrases();
}

BEGIN_NAMED_BASE_CLASS_INFO("Comment-rule", CComment_rule)
{
    SET_CLASS_MODULE("NCBI-Structured-comment-validation");
    ADD_NAMED_STD_MEMBER("prefix", m_Prefix)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("updated", m_Updated)->SetDefault(new TUpdated(false))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("fields", m_Fields, CField_set);
    ADD_NAMED_STD_MEMBER("require-order", m_Require_order)->SetDefault(new TRequire_order(true))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("allow-unlisted", m_Allow_unlisted)->SetDefault(new TAllow_unlisted(false))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("dependent-rules", m_Dependent_rules, CDependent_field_set)->SetOptional();
    ADD_NAMED_REF_MEMBER("forbidden-phrases", m_Forbidden_phrases, CPhrase_list)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CComment_rule_Base::CComment_rule_Base(void)
    : m_Updated(false), m_Require_order(true), m_Allow_unlisted(false)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetFields();
    }
}

// destructor
CComment_rule_Base::~CComment_rule_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

