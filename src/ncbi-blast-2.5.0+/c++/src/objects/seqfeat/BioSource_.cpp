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
#include <objects/seqfeat/BioSource.hpp>
#include <objects/seqfeat/Org_ref.hpp>
#include <objects/seqfeat/PCRReactionSet.hpp>
#include <objects/seqfeat/SubSource.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CBioSource_Base::, EGenome, true)
{
    SET_ENUM_INTERNAL_NAME("BioSource", "genome");
    SET_ENUM_MODULE("NCBI-BioSource");
    ADD_ENUM_VALUE("unknown", eGenome_unknown);
    ADD_ENUM_VALUE("genomic", eGenome_genomic);
    ADD_ENUM_VALUE("chloroplast", eGenome_chloroplast);
    ADD_ENUM_VALUE("chromoplast", eGenome_chromoplast);
    ADD_ENUM_VALUE("kinetoplast", eGenome_kinetoplast);
    ADD_ENUM_VALUE("mitochondrion", eGenome_mitochondrion);
    ADD_ENUM_VALUE("plastid", eGenome_plastid);
    ADD_ENUM_VALUE("macronuclear", eGenome_macronuclear);
    ADD_ENUM_VALUE("extrachrom", eGenome_extrachrom);
    ADD_ENUM_VALUE("plasmid", eGenome_plasmid);
    ADD_ENUM_VALUE("transposon", eGenome_transposon);
    ADD_ENUM_VALUE("insertion-seq", eGenome_insertion_seq);
    ADD_ENUM_VALUE("cyanelle", eGenome_cyanelle);
    ADD_ENUM_VALUE("proviral", eGenome_proviral);
    ADD_ENUM_VALUE("virion", eGenome_virion);
    ADD_ENUM_VALUE("nucleomorph", eGenome_nucleomorph);
    ADD_ENUM_VALUE("apicoplast", eGenome_apicoplast);
    ADD_ENUM_VALUE("leucoplast", eGenome_leucoplast);
    ADD_ENUM_VALUE("proplastid", eGenome_proplastid);
    ADD_ENUM_VALUE("endogenous-virus", eGenome_endogenous_virus);
    ADD_ENUM_VALUE("hydrogenosome", eGenome_hydrogenosome);
    ADD_ENUM_VALUE("chromosome", eGenome_chromosome);
    ADD_ENUM_VALUE("chromatophore", eGenome_chromatophore);
    ADD_ENUM_VALUE("plasmid-in-mitochondrion", eGenome_plasmid_in_mitochondrion);
    ADD_ENUM_VALUE("plasmid-in-plastid", eGenome_plasmid_in_plastid);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CBioSource_Base::, EOrigin, true)
{
    SET_ENUM_INTERNAL_NAME("BioSource", "origin");
    SET_ENUM_MODULE("NCBI-BioSource");
    ADD_ENUM_VALUE("unknown", eOrigin_unknown);
    ADD_ENUM_VALUE("natural", eOrigin_natural);
    ADD_ENUM_VALUE("natmut", eOrigin_natmut);
    ADD_ENUM_VALUE("mut", eOrigin_mut);
    ADD_ENUM_VALUE("artificial", eOrigin_artificial);
    ADD_ENUM_VALUE("synthetic", eOrigin_synthetic);
    ADD_ENUM_VALUE("other", eOrigin_other);
}
END_ENUM_INFO

void CBioSource_Base::ResetOrg(void)
{
    if ( !m_Org ) {
        m_Org.Reset(new TOrg());
        return;
    }
    (*m_Org).Reset();
}

void CBioSource_Base::SetOrg(CBioSource_Base::TOrg& value)
{
    m_Org.Reset(&value);
}

void CBioSource_Base::ResetSubtype(void)
{
    m_Subtype.clear();
    m_set_State[0] &= ~0xc0;
}

void CBioSource_Base::ResetPcr_primers(void)
{
    m_Pcr_primers.Reset();
}

void CBioSource_Base::SetPcr_primers(CBioSource_Base::TPcr_primers& value)
{
    m_Pcr_primers.Reset(&value);
}

CBioSource_Base::TPcr_primers& CBioSource_Base::SetPcr_primers(void)
{
    if ( !m_Pcr_primers )
        m_Pcr_primers.Reset(new ncbi::objects::CPCRReactionSet());
    return (*m_Pcr_primers);
}

void CBioSource_Base::Reset(void)
{
    ResetGenome();
    ResetOrigin();
    ResetOrg();
    ResetSubtype();
    ResetIs_focus();
    ResetPcr_primers();
}

BEGIN_NAMED_BASE_CLASS_INFO("BioSource", CBioSource)
{
    SET_CLASS_MODULE("NCBI-BioSource");
    ADD_NAMED_ENUM_MEMBER("genome", m_Genome, EGenome)->SetDefault(new TGenome(eGenome_unknown))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("origin", m_Origin, EOrigin)->SetDefault(new TOrigin(eOrigin_unknown))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("org", m_Org, COrg_ref);
    ADD_NAMED_MEMBER("subtype", m_Subtype, STL_list, (STL_CRef, (CLASS, (CSubSource))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_NULL_MEMBER("is-focus", null, ())->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("pcr-primers", m_Pcr_primers, CPCRReactionSet)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CBioSource_Base::CBioSource_Base(void)
    : m_Genome(eGenome_unknown), m_Origin(eOrigin_unknown)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetOrg();
    }
}

// destructor
CBioSource_Base::~CBioSource_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

