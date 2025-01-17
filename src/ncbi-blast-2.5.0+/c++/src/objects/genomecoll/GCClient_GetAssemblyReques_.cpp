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
#include <objects/genomecoll/GCClient_GetAssemblyReques.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CGCClient_GetAssemblyRequest_Base::, ELevel, true)
{
    SET_ENUM_INTERNAL_NAME("GCClient-GetAssemblyRequest", "level");
    SET_ENUM_MODULE("NCBI-GencollClient");
    ADD_ENUM_VALUE("assembly", eLevel_assembly);
    ADD_ENUM_VALUE("replicon", eLevel_replicon);
    ADD_ENUM_VALUE("scaffold", eLevel_scaffold);
    ADD_ENUM_VALUE("component", eLevel_component);
}
END_ENUM_INFO

void CGCClient_GetAssemblyRequest_Base::ResetAccession(void)
{
    m_Accession.erase();
    m_set_State[0] &= ~0x3;
}

void CGCClient_GetAssemblyRequest_Base::Reset(void)
{
    ResetAccession();
    ResetRelease_id();
    ResetLevel();
    ResetAssm_flags();
    ResetChrom_flags();
    ResetScaf_flags();
    ResetComponent_flags();
}

BEGIN_NAMED_BASE_CLASS_INFO("GCClient-GetAssemblyRequest", CGCClient_GetAssemblyRequest)
{
    SET_CLASS_MODULE("NCBI-GencollClient");
    ADD_NAMED_STD_MEMBER("accession", m_Accession)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("release-id", m_Release_id)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("level", m_Level, ELevel)->SetDefault(new TLevel(eLevel_scaffold))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("assm-flags", m_Assm_flags, EGCClient_AttributeFlags)->SetDefault(new TAssm_flags(eGCClient_AttributeFlags_none))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("chrom-flags", m_Chrom_flags, EGCClient_AttributeFlags)->SetDefault(new TChrom_flags(eGCClient_AttributeFlags_biosource))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("scaf-flags", m_Scaf_flags, EGCClient_AttributeFlags)->SetDefault(new TScaf_flags(eGCClient_AttributeFlags_none))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("component-flags", m_Component_flags, EGCClient_AttributeFlags)->SetDefault(new TComponent_flags(eGCClient_AttributeFlags_none))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CGCClient_GetAssemblyRequest_Base::CGCClient_GetAssemblyRequest_Base(void)
    : m_Release_id(0), m_Level(eLevel_scaffold), m_Assm_flags(eGCClient_AttributeFlags_none), m_Chrom_flags(eGCClient_AttributeFlags_biosource), m_Scaf_flags(eGCClient_AttributeFlags_none), m_Component_flags(eGCClient_AttributeFlags_none)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CGCClient_GetAssemblyRequest_Base::~CGCClient_GetAssemblyRequest_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

