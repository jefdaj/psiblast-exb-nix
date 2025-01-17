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
#include <objects/seqfeat/SubSource.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CSubSource_Base::, ESubtype, true)
{
    SET_ENUM_INTERNAL_NAME("SubSource", "subtype");
    SET_ENUM_MODULE("NCBI-BioSource");
    ADD_ENUM_VALUE("chromosome", eSubtype_chromosome);
    ADD_ENUM_VALUE("map", eSubtype_map);
    ADD_ENUM_VALUE("clone", eSubtype_clone);
    ADD_ENUM_VALUE("subclone", eSubtype_subclone);
    ADD_ENUM_VALUE("haplotype", eSubtype_haplotype);
    ADD_ENUM_VALUE("genotype", eSubtype_genotype);
    ADD_ENUM_VALUE("sex", eSubtype_sex);
    ADD_ENUM_VALUE("cell-line", eSubtype_cell_line);
    ADD_ENUM_VALUE("cell-type", eSubtype_cell_type);
    ADD_ENUM_VALUE("tissue-type", eSubtype_tissue_type);
    ADD_ENUM_VALUE("clone-lib", eSubtype_clone_lib);
    ADD_ENUM_VALUE("dev-stage", eSubtype_dev_stage);
    ADD_ENUM_VALUE("frequency", eSubtype_frequency);
    ADD_ENUM_VALUE("germline", eSubtype_germline);
    ADD_ENUM_VALUE("rearranged", eSubtype_rearranged);
    ADD_ENUM_VALUE("lab-host", eSubtype_lab_host);
    ADD_ENUM_VALUE("pop-variant", eSubtype_pop_variant);
    ADD_ENUM_VALUE("tissue-lib", eSubtype_tissue_lib);
    ADD_ENUM_VALUE("plasmid-name", eSubtype_plasmid_name);
    ADD_ENUM_VALUE("transposon-name", eSubtype_transposon_name);
    ADD_ENUM_VALUE("insertion-seq-name", eSubtype_insertion_seq_name);
    ADD_ENUM_VALUE("plastid-name", eSubtype_plastid_name);
    ADD_ENUM_VALUE("country", eSubtype_country);
    ADD_ENUM_VALUE("segment", eSubtype_segment);
    ADD_ENUM_VALUE("endogenous-virus-name", eSubtype_endogenous_virus_name);
    ADD_ENUM_VALUE("transgenic", eSubtype_transgenic);
    ADD_ENUM_VALUE("environmental-sample", eSubtype_environmental_sample);
    ADD_ENUM_VALUE("isolation-source", eSubtype_isolation_source);
    ADD_ENUM_VALUE("lat-lon", eSubtype_lat_lon);
    ADD_ENUM_VALUE("collection-date", eSubtype_collection_date);
    ADD_ENUM_VALUE("collected-by", eSubtype_collected_by);
    ADD_ENUM_VALUE("identified-by", eSubtype_identified_by);
    ADD_ENUM_VALUE("fwd-primer-seq", eSubtype_fwd_primer_seq);
    ADD_ENUM_VALUE("rev-primer-seq", eSubtype_rev_primer_seq);
    ADD_ENUM_VALUE("fwd-primer-name", eSubtype_fwd_primer_name);
    ADD_ENUM_VALUE("rev-primer-name", eSubtype_rev_primer_name);
    ADD_ENUM_VALUE("metagenomic", eSubtype_metagenomic);
    ADD_ENUM_VALUE("mating-type", eSubtype_mating_type);
    ADD_ENUM_VALUE("linkage-group", eSubtype_linkage_group);
    ADD_ENUM_VALUE("haplogroup", eSubtype_haplogroup);
    ADD_ENUM_VALUE("whole-replicon", eSubtype_whole_replicon);
    ADD_ENUM_VALUE("phenotype", eSubtype_phenotype);
    ADD_ENUM_VALUE("altitude", eSubtype_altitude);
    ADD_ENUM_VALUE("other", eSubtype_other);
}
END_ENUM_INFO

void CSubSource_Base::ResetName(void)
{
    m_Name.erase();
    m_set_State[0] &= ~0xc;
}

void CSubSource_Base::ResetAttrib(void)
{
    m_Attrib.erase();
    m_set_State[0] &= ~0x30;
}

void CSubSource_Base::Reset(void)
{
    ResetSubtype();
    ResetName();
    ResetAttrib();
}

BEGIN_NAMED_BASE_CLASS_INFO("SubSource", CSubSource)
{
    SET_CLASS_MODULE("NCBI-BioSource");
    ADD_NAMED_ENUM_MEMBER("subtype", m_Subtype, ESubtype)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("name", m_Name)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("attrib", m_Attrib)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CSubSource_Base::CSubSource_Base(void)
    : m_Subtype((ESubtype)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CSubSource_Base::~CSubSource_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

