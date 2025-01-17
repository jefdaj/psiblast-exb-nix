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
#include <objects/seqfeat/VariantProperties.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CVariantProperties_Base::, EResource_link, true)
{
    SET_ENUM_INTERNAL_NAME("VariantProperties", "resource-link");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("preserved", eResource_link_preserved);
    ADD_ENUM_VALUE("provisional", eResource_link_provisional);
    ADD_ENUM_VALUE("has3D", eResource_link_has3D);
    ADD_ENUM_VALUE("submitterLinkout", eResource_link_submitterLinkout);
    ADD_ENUM_VALUE("clinical", eResource_link_clinical);
    ADD_ENUM_VALUE("genotypeKit", eResource_link_genotypeKit);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CVariantProperties_Base::, EGene_location, true)
{
    SET_ENUM_INTERNAL_NAME("VariantProperties", "gene-location");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("in-gene", eGene_location_in_gene);
    ADD_ENUM_VALUE("near-gene-5", eGene_location_near_gene_5);
    ADD_ENUM_VALUE("near-gene-3", eGene_location_near_gene_3);
    ADD_ENUM_VALUE("intron", eGene_location_intron);
    ADD_ENUM_VALUE("donor", eGene_location_donor);
    ADD_ENUM_VALUE("acceptor", eGene_location_acceptor);
    ADD_ENUM_VALUE("utr-5", eGene_location_utr_5);
    ADD_ENUM_VALUE("utr-3", eGene_location_utr_3);
    ADD_ENUM_VALUE("in-start-codon", eGene_location_in_start_codon);
    ADD_ENUM_VALUE("in-stop-codon", eGene_location_in_stop_codon);
    ADD_ENUM_VALUE("intergenic", eGene_location_intergenic);
    ADD_ENUM_VALUE("conserved-noncoding", eGene_location_conserved_noncoding);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CVariantProperties_Base::, EEffect, true)
{
    SET_ENUM_INTERNAL_NAME("VariantProperties", "effect");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("no-change", eEffect_no_change);
    ADD_ENUM_VALUE("synonymous", eEffect_synonymous);
    ADD_ENUM_VALUE("nonsense", eEffect_nonsense);
    ADD_ENUM_VALUE("missense", eEffect_missense);
    ADD_ENUM_VALUE("frameshift", eEffect_frameshift);
    ADD_ENUM_VALUE("up-regulator", eEffect_up_regulator);
    ADD_ENUM_VALUE("down-regulator", eEffect_down_regulator);
    ADD_ENUM_VALUE("methylation", eEffect_methylation);
    ADD_ENUM_VALUE("stop-gain", eEffect_stop_gain);
    ADD_ENUM_VALUE("stop-loss", eEffect_stop_loss);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CVariantProperties_Base::, EMapping, true)
{
    SET_ENUM_INTERNAL_NAME("VariantProperties", "mapping");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("has-other-snp", eMapping_has_other_snp);
    ADD_ENUM_VALUE("has-assembly-conflict", eMapping_has_assembly_conflict);
    ADD_ENUM_VALUE("is-assembly-specific", eMapping_is_assembly_specific);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CVariantProperties_Base::, EMap_weight, true)
{
    SET_ENUM_INTERNAL_NAME("VariantProperties", "map-weight");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("is-uniquely-placed", eMap_weight_is_uniquely_placed);
    ADD_ENUM_VALUE("placed-twice-on-same-chrom", eMap_weight_placed_twice_on_same_chrom);
    ADD_ENUM_VALUE("placed-twice-on-diff-chrom", eMap_weight_placed_twice_on_diff_chrom);
    ADD_ENUM_VALUE("many-placements", eMap_weight_many_placements);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CVariantProperties_Base::, EFrequency_based_validation, true)
{
    SET_ENUM_INTERNAL_NAME("VariantProperties", "frequency-based-validation");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("is-mutation", eFrequency_based_validation_is_mutation);
    ADD_ENUM_VALUE("above-5pct-all", eFrequency_based_validation_above_5pct_all);
    ADD_ENUM_VALUE("above-5pct-1plus", eFrequency_based_validation_above_5pct_1plus);
    ADD_ENUM_VALUE("validated", eFrequency_based_validation_validated);
    ADD_ENUM_VALUE("above-1pct-all", eFrequency_based_validation_above_1pct_all);
    ADD_ENUM_VALUE("above-1pct-1plus", eFrequency_based_validation_above_1pct_1plus);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CVariantProperties_Base::, EGenotype, true)
{
    SET_ENUM_INTERNAL_NAME("VariantProperties", "genotype");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("in-haplotype-set", eGenotype_in_haplotype_set);
    ADD_ENUM_VALUE("has-genotypes", eGenotype_has_genotypes);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CVariantProperties_Base::, EQuality_check, true)
{
    SET_ENUM_INTERNAL_NAME("VariantProperties", "quality-check");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("contig-allele-missing", eQuality_check_contig_allele_missing);
    ADD_ENUM_VALUE("withdrawn-by-submitter", eQuality_check_withdrawn_by_submitter);
    ADD_ENUM_VALUE("non-overlapping-alleles", eQuality_check_non_overlapping_alleles);
    ADD_ENUM_VALUE("strain-specific", eQuality_check_strain_specific);
    ADD_ENUM_VALUE("genotype-conflict", eQuality_check_genotype_conflict);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CVariantProperties_Base::, EConfidence, true)
{
    SET_ENUM_INTERNAL_NAME("VariantProperties", "confidence");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("unknown", eConfidence_unknown);
    ADD_ENUM_VALUE("likely-artifact", eConfidence_likely_artifact);
    ADD_ENUM_VALUE("other", eConfidence_other);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CVariantProperties_Base::, EAllele_origin, true)
{
    SET_ENUM_INTERNAL_NAME("VariantProperties", "allele-origin");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("unknown", eAllele_origin_unknown);
    ADD_ENUM_VALUE("germline", eAllele_origin_germline);
    ADD_ENUM_VALUE("somatic", eAllele_origin_somatic);
    ADD_ENUM_VALUE("inherited", eAllele_origin_inherited);
    ADD_ENUM_VALUE("paternal", eAllele_origin_paternal);
    ADD_ENUM_VALUE("maternal", eAllele_origin_maternal);
    ADD_ENUM_VALUE("de-novo", eAllele_origin_de_novo);
    ADD_ENUM_VALUE("biparental", eAllele_origin_biparental);
    ADD_ENUM_VALUE("uniparental", eAllele_origin_uniparental);
    ADD_ENUM_VALUE("not-tested", eAllele_origin_not_tested);
    ADD_ENUM_VALUE("tested-inconclusive", eAllele_origin_tested_inconclusive);
    ADD_ENUM_VALUE("not-reported", eAllele_origin_not_reported);
    ADD_ENUM_VALUE("other", eAllele_origin_other);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CVariantProperties_Base::, EAllele_state, true)
{
    SET_ENUM_INTERNAL_NAME("VariantProperties", "allele-state");
    SET_ENUM_MODULE("NCBI-Variation");
    ADD_ENUM_VALUE("unknown", eAllele_state_unknown);
    ADD_ENUM_VALUE("homozygous", eAllele_state_homozygous);
    ADD_ENUM_VALUE("heterozygous", eAllele_state_heterozygous);
    ADD_ENUM_VALUE("hemizygous", eAllele_state_hemizygous);
    ADD_ENUM_VALUE("nullizygous", eAllele_state_nullizygous);
    ADD_ENUM_VALUE("other", eAllele_state_other);
}
END_ENUM_INFO

void CVariantProperties_Base::ResetProject_data(void)
{
    m_Project_data.clear();
    m_set_State[0] &= ~0x30000;
}

void CVariantProperties_Base::Reset(void)
{
    ResetVersion();
    ResetResource_link();
    ResetGene_location();
    ResetEffect();
    ResetMapping();
    ResetMap_weight();
    ResetFrequency_based_validation();
    ResetGenotype();
    ResetProject_data();
    ResetQuality_check();
    ResetConfidence();
    ResetOther_validation();
    ResetAllele_origin();
    ResetAllele_state();
    ResetAllele_frequency();
    ResetIs_ancestral_allele();
}

BEGIN_NAMED_BASE_CLASS_INFO("VariantProperties", CVariantProperties)
{
    SET_CLASS_MODULE("NCBI-Variation");
    ADD_NAMED_STD_MEMBER("version", m_Version)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("resource-link", m_Resource_link, EResource_link)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("gene-location", m_Gene_location, EGene_location)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("effect", m_Effect, EEffect)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("mapping", m_Mapping, EMapping)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("map-weight", m_Map_weight, EMap_weight)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("frequency-based-validation", m_Frequency_based_validation, EFrequency_based_validation)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("genotype", m_Genotype, EGenotype)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("project-data", m_Project_data, STL_list_set, (STD, (int)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("quality-check", m_Quality_check, EQuality_check)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("confidence", m_Confidence, EConfidence)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("other-validation", m_Other_validation)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("allele-origin", m_Allele_origin, EAllele_origin)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("allele-state", m_Allele_state, EAllele_state)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("allele-frequency", m_Allele_frequency)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("is-ancestral-allele", m_Is_ancestral_allele)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CVariantProperties_Base::CVariantProperties_Base(void)
    : m_Version(0), m_Resource_link((EResource_link)(0)), m_Gene_location((EGene_location)(0)), m_Effect((EEffect)(0)), m_Mapping((EMapping)(0)), m_Map_weight((EMap_weight)(0)), m_Frequency_based_validation((EFrequency_based_validation)(0)), m_Genotype((EGenotype)(0)), m_Quality_check((EQuality_check)(0)), m_Confidence((EConfidence)(0)), m_Other_validation(0), m_Allele_origin((EAllele_origin)(0)), m_Allele_state((EAllele_state)(0)), m_Allele_frequency(0), m_Is_ancestral_allele(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CVariantProperties_Base::~CVariantProperties_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

