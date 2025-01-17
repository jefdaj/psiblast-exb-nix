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
 *   'macro.asn'.
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
#include <objects/macro/Add_descriptor_list_action.hpp>
#include <objects/macro/Add_file_action.hpp>
#include <objects/macro/Constraint_choice_set.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CAdd_descriptor_list_action_Base::ResetDescriptor_list(void)
{
    if ( !m_Descriptor_list ) {
        m_Descriptor_list.Reset(new TDescriptor_list());
        return;
    }
    (*m_Descriptor_list).Reset();
}

void CAdd_descriptor_list_action_Base::SetDescriptor_list(CAdd_descriptor_list_action_Base::TDescriptor_list& value)
{
    m_Descriptor_list.Reset(&value);
}

void CAdd_descriptor_list_action_Base::ResetConstraint(void)
{
    m_Constraint.Reset();
}

void CAdd_descriptor_list_action_Base::SetConstraint(CAdd_descriptor_list_action_Base::TConstraint& value)
{
    m_Constraint.Reset(&value);
}

CAdd_descriptor_list_action_Base::TConstraint& CAdd_descriptor_list_action_Base::SetConstraint(void)
{
    if ( !m_Constraint )
        m_Constraint.Reset(new ncbi::objects::CConstraint_choice_set());
    return (*m_Constraint);
}

void CAdd_descriptor_list_action_Base::Reset(void)
{
    ResetDescriptor_list();
    ResetConstraint();
}

BEGIN_NAMED_BASE_CLASS_INFO("Add-descriptor-list-action", CAdd_descriptor_list_action)
{
    SET_CLASS_MODULE("NCBI-Macro");
    ADD_NAMED_REF_MEMBER("descriptor-list", m_Descriptor_list, CAdd_file_action);
    ADD_NAMED_REF_MEMBER("constraint", m_Constraint, CConstraint_choice_set)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CAdd_descriptor_list_action_Base::CAdd_descriptor_list_action_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetDescriptor_list();
    }
}

// destructor
CAdd_descriptor_list_action_Base::~CAdd_descriptor_list_action_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

