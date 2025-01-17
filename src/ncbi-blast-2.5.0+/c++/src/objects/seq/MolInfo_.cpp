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
 *   'seq.asn'.
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
#include <objects/seq/MolInfo.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CMolInfo_Base::, EBiomol, true)
{
    SET_ENUM_INTERNAL_NAME("MolInfo", "biomol");
    SET_ENUM_MODULE("NCBI-Sequence");
    ADD_ENUM_VALUE("unknown", eBiomol_unknown);
    ADD_ENUM_VALUE("genomic", eBiomol_genomic);
    ADD_ENUM_VALUE("pre-RNA", eBiomol_pre_RNA);
    ADD_ENUM_VALUE("mRNA", eBiomol_mRNA);
    ADD_ENUM_VALUE("rRNA", eBiomol_rRNA);
    ADD_ENUM_VALUE("tRNA", eBiomol_tRNA);
    ADD_ENUM_VALUE("snRNA", eBiomol_snRNA);
    ADD_ENUM_VALUE("scRNA", eBiomol_scRNA);
    ADD_ENUM_VALUE("peptide", eBiomol_peptide);
    ADD_ENUM_VALUE("other-genetic", eBiomol_other_genetic);
    ADD_ENUM_VALUE("genomic-mRNA", eBiomol_genomic_mRNA);
    ADD_ENUM_VALUE("cRNA", eBiomol_cRNA);
    ADD_ENUM_VALUE("snoRNA", eBiomol_snoRNA);
    ADD_ENUM_VALUE("transcribed-RNA", eBiomol_transcribed_RNA);
    ADD_ENUM_VALUE("ncRNA", eBiomol_ncRNA);
    ADD_ENUM_VALUE("tmRNA", eBiomol_tmRNA);
    ADD_ENUM_VALUE("other", eBiomol_other);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CMolInfo_Base::, ETech, true)
{
    SET_ENUM_INTERNAL_NAME("MolInfo", "tech");
    SET_ENUM_MODULE("NCBI-Sequence");
    ADD_ENUM_VALUE("unknown", eTech_unknown);
    ADD_ENUM_VALUE("standard", eTech_standard);
    ADD_ENUM_VALUE("est", eTech_est);
    ADD_ENUM_VALUE("sts", eTech_sts);
    ADD_ENUM_VALUE("survey", eTech_survey);
    ADD_ENUM_VALUE("genemap", eTech_genemap);
    ADD_ENUM_VALUE("physmap", eTech_physmap);
    ADD_ENUM_VALUE("derived", eTech_derived);
    ADD_ENUM_VALUE("concept-trans", eTech_concept_trans);
    ADD_ENUM_VALUE("seq-pept", eTech_seq_pept);
    ADD_ENUM_VALUE("both", eTech_both);
    ADD_ENUM_VALUE("seq-pept-overlap", eTech_seq_pept_overlap);
    ADD_ENUM_VALUE("seq-pept-homol", eTech_seq_pept_homol);
    ADD_ENUM_VALUE("concept-trans-a", eTech_concept_trans_a);
    ADD_ENUM_VALUE("htgs-1", eTech_htgs_1);
    ADD_ENUM_VALUE("htgs-2", eTech_htgs_2);
    ADD_ENUM_VALUE("htgs-3", eTech_htgs_3);
    ADD_ENUM_VALUE("fli-cdna", eTech_fli_cdna);
    ADD_ENUM_VALUE("htgs-0", eTech_htgs_0);
    ADD_ENUM_VALUE("htc", eTech_htc);
    ADD_ENUM_VALUE("wgs", eTech_wgs);
    ADD_ENUM_VALUE("barcode", eTech_barcode);
    ADD_ENUM_VALUE("composite-wgs-htgs", eTech_composite_wgs_htgs);
    ADD_ENUM_VALUE("tsa", eTech_tsa);
    ADD_ENUM_VALUE("targeted", eTech_targeted);
    ADD_ENUM_VALUE("other", eTech_other);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CMolInfo_Base::, ECompleteness, true)
{
    SET_ENUM_INTERNAL_NAME("MolInfo", "completeness");
    SET_ENUM_MODULE("NCBI-Sequence");
    ADD_ENUM_VALUE("unknown", eCompleteness_unknown);
    ADD_ENUM_VALUE("complete", eCompleteness_complete);
    ADD_ENUM_VALUE("partial", eCompleteness_partial);
    ADD_ENUM_VALUE("no-left", eCompleteness_no_left);
    ADD_ENUM_VALUE("no-right", eCompleteness_no_right);
    ADD_ENUM_VALUE("no-ends", eCompleteness_no_ends);
    ADD_ENUM_VALUE("has-left", eCompleteness_has_left);
    ADD_ENUM_VALUE("has-right", eCompleteness_has_right);
    ADD_ENUM_VALUE("other", eCompleteness_other);
}
END_ENUM_INFO

void CMolInfo_Base::ResetTechexp(void)
{
    m_Techexp.erase();
    m_set_State[0] &= ~0x30;
}

void CMolInfo_Base::ResetGbmoltype(void)
{
    m_Gbmoltype.erase();
    m_set_State[0] &= ~0x300;
}

void CMolInfo_Base::Reset(void)
{
    ResetBiomol();
    ResetTech();
    ResetTechexp();
    ResetCompleteness();
    ResetGbmoltype();
}

BEGIN_NAMED_BASE_CLASS_INFO("MolInfo", CMolInfo)
{
    SET_CLASS_MODULE("NCBI-Sequence");
    ADD_NAMED_ENUM_MEMBER("biomol", m_Biomol, EBiomol)->SetDefault(new TBiomol(eBiomol_unknown))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("tech", m_Tech, ETech)->SetDefault(new TTech(eTech_unknown))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("techexp", m_Techexp)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("completeness", m_Completeness, ECompleteness)->SetDefault(new TCompleteness(eCompleteness_unknown))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("gbmoltype", m_Gbmoltype)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CMolInfo_Base::CMolInfo_Base(void)
    : m_Biomol(eBiomol_unknown), m_Tech(eTech_unknown), m_Completeness(eCompleteness_unknown)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CMolInfo_Base::~CMolInfo_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

