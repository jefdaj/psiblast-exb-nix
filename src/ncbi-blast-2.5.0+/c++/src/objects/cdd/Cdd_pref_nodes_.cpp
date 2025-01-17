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
 *   'cdd.asn'.
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
#include <objects/cdd/Cdd_pref_nodes.hpp>
#include <objects/cdd/Cdd_org_ref_set.hpp>
#include <objects/cdd/Cdd_pref_node_descr_set.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CCdd_pref_nodes_Base::ResetPreferred_nodes(void)
{
    if ( !m_Preferred_nodes ) {
        m_Preferred_nodes.Reset(new TPreferred_nodes());
        return;
    }
    (*m_Preferred_nodes).Reset();
}

void CCdd_pref_nodes_Base::SetPreferred_nodes(CCdd_pref_nodes_Base::TPreferred_nodes& value)
{
    m_Preferred_nodes.Reset(&value);
}

void CCdd_pref_nodes_Base::ResetModel_organisms(void)
{
    m_Model_organisms.Reset();
}

void CCdd_pref_nodes_Base::SetModel_organisms(CCdd_pref_nodes_Base::TModel_organisms& value)
{
    m_Model_organisms.Reset(&value);
}

CCdd_pref_nodes_Base::TModel_organisms& CCdd_pref_nodes_Base::SetModel_organisms(void)
{
    if ( !m_Model_organisms )
        m_Model_organisms.Reset(new ncbi::objects::CCdd_org_ref_set());
    return (*m_Model_organisms);
}

void CCdd_pref_nodes_Base::ResetOptional_nodes(void)
{
    m_Optional_nodes.Reset();
}

void CCdd_pref_nodes_Base::SetOptional_nodes(CCdd_pref_nodes_Base::TOptional_nodes& value)
{
    m_Optional_nodes.Reset(&value);
}

CCdd_pref_nodes_Base::TOptional_nodes& CCdd_pref_nodes_Base::SetOptional_nodes(void)
{
    if ( !m_Optional_nodes )
        m_Optional_nodes.Reset(new ncbi::objects::CCdd_org_ref_set());
    return (*m_Optional_nodes);
}

void CCdd_pref_nodes_Base::ResetDescription(void)
{
    m_Description.Reset();
}

void CCdd_pref_nodes_Base::SetDescription(CCdd_pref_nodes_Base::TDescription& value)
{
    m_Description.Reset(&value);
}

CCdd_pref_nodes_Base::TDescription& CCdd_pref_nodes_Base::SetDescription(void)
{
    if ( !m_Description )
        m_Description.Reset(new ncbi::objects::CCdd_pref_node_descr_set());
    return (*m_Description);
}

void CCdd_pref_nodes_Base::Reset(void)
{
    ResetPreferred_nodes();
    ResetModel_organisms();
    ResetOptional_nodes();
    ResetDescription();
}

BEGIN_NAMED_BASE_CLASS_INFO("Cdd-pref-nodes", CCdd_pref_nodes)
{
    SET_CLASS_MODULE("NCBI-Cdd");
    ADD_NAMED_REF_MEMBER("preferred-nodes", m_Preferred_nodes, CCdd_org_ref_set);
    ADD_NAMED_REF_MEMBER("model-organisms", m_Model_organisms, CCdd_org_ref_set)->SetOptional();
    ADD_NAMED_REF_MEMBER("optional-nodes", m_Optional_nodes, CCdd_org_ref_set)->SetOptional();
    ADD_NAMED_REF_MEMBER("description", m_Description, CCdd_pref_node_descr_set)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CCdd_pref_nodes_Base::CCdd_pref_nodes_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetPreferred_nodes();
    }
}

// destructor
CCdd_pref_nodes_Base::~CCdd_pref_nodes_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

