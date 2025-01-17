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
#include <objects/seqfeat/Population_data.hpp>
#include <objects/general/Object_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CPopulation_data_Base::, EFlags, true)
{
    SET_ENUM_INTERNAL_NAME("Population-data", "flags");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("is-default-population", eFlags_is_default_population);
    ADD_ENUM_VALUE("is-minor-allele", eFlags_is_minor_allele);
    ADD_ENUM_VALUE("is-rare-allele", eFlags_is_rare_allele);
}
END_ENUM_INFO

void CPopulation_data_Base::ResetPopulation(void)
{
    m_Population.erase();
    m_set_State[0] &= ~0x3;
}

void CPopulation_data_Base::ResetSample_ids(void)
{
    m_Sample_ids.clear();
    m_set_State[0] &= ~0xc0;
}

void CPopulation_data_Base::Reset(void)
{
    ResetPopulation();
    ResetGenotype_frequency();
    ResetChromosomes_tested();
    ResetSample_ids();
    ResetAllele_frequency();
    ResetFlags();
}

BEGIN_NAMED_BASE_CLASS_INFO("Population-data", CPopulation_data)
{
    SET_CLASS_MODULE("NCBI-Variation");
    ADD_NAMED_STD_MEMBER("population", m_Population)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("genotype-frequency", m_Genotype_frequency)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("chromosomes-tested", m_Chromosomes_tested)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("sample-ids", m_Sample_ids, STL_list_set, (STL_CRef, (CLASS, (CObject_id))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("allele-frequency", m_Allele_frequency)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("flags", m_Flags, EFlags)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CPopulation_data_Base::CPopulation_data_Base(void)
    : m_Genotype_frequency(0), m_Chromosomes_tested(0), m_Allele_frequency(0), m_Flags((EFlags)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CPopulation_data_Base::~CPopulation_data_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

