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
 *   'gencoll_client.asn'.
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
#include <objects/genomecoll/GCClient_Error.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CGCClient_Error_Base::, EError_id, true)
{
    SET_ENUM_INTERNAL_NAME("GCClient-Error", "error-id");
    SET_ENUM_MODULE("NCBI-GencollClient");
    ADD_ENUM_VALUE("assembly-not-found", eError_id_assembly_not_found);
    ADD_ENUM_VALUE("other", eError_id_other);
}
END_ENUM_INFO

void CGCClient_Error_Base::ResetDescription(void)
{
    m_Description.erase();
    m_set_State[0] &= ~0xc;
}

void CGCClient_Error_Base::Reset(void)
{
    ResetError_id();
    ResetDescription();
}

BEGIN_NAMED_BASE_CLASS_INFO("GCClient-Error", CGCClient_Error)
{
    SET_CLASS_MODULE("NCBI-GencollClient");
    ADD_NAMED_ENUM_MEMBER("error-id", m_Error_id, EError_id)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("description", m_Description)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CGCClient_Error_Base::CGCClient_Error_Base(void)
    : m_Error_id((EError_id)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CGCClient_Error_Base::~CGCClient_Error_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

