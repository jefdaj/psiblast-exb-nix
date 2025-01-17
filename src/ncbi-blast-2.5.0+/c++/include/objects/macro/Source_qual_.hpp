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
 */

/// @file Source_qual_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MACRO_SOURCE_QUAL_BASE_HPP
#define OBJECTS_MACRO_SOURCE_QUAL_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

enum ESource_qual {
    eSource_qual_acronym                   =   1,
    eSource_qual_anamorph                  =   2,
    eSource_qual_authority                 =   3,
    eSource_qual_bio_material              =   4,
    eSource_qual_biotype                   =   5,
    eSource_qual_biovar                    =   6,
    eSource_qual_breed                     =   7,
    eSource_qual_cell_line                 =   8,
    eSource_qual_cell_type                 =   9,
    eSource_qual_chemovar                  =  10,
    eSource_qual_chromosome                =  11,
    eSource_qual_clone                     =  12,
    eSource_qual_clone_lib                 =  13,
    eSource_qual_collected_by              =  14,
    eSource_qual_collection_date           =  15,
    eSource_qual_common                    =  16,
    eSource_qual_common_name               =  17,
    eSource_qual_country                   =  18,
    eSource_qual_cultivar                  =  19,
    eSource_qual_culture_collection        =  20,
    eSource_qual_dev_stage                 =  21,
    eSource_qual_division                  =  22,
    eSource_qual_dosage                    =  23,
    eSource_qual_ecotype                   =  24,
    eSource_qual_endogenous_virus_name     =  25,
    eSource_qual_environmental_sample      =  26,
    eSource_qual_forma                     =  27,
    eSource_qual_forma_specialis           =  28,
    eSource_qual_frequency                 =  29,
    eSource_qual_fwd_primer_name           =  30,
    eSource_qual_fwd_primer_seq            =  31,
    eSource_qual_gb_acronym                =  32,
    eSource_qual_gb_anamorph               =  33,
    eSource_qual_gb_synonym                =  34,
    eSource_qual_genotype                  =  35,
    eSource_qual_germline                  =  36,
    eSource_qual_group                     =  37,
    eSource_qual_haplotype                 =  38,
    eSource_qual_identified_by             =  39,
    eSource_qual_insertion_seq_name        =  40,
    eSource_qual_isolate                   =  41,
    eSource_qual_isolation_source          =  42,
    eSource_qual_lab_host                  =  43,
    eSource_qual_lat_lon                   =  44,
    eSource_qual_lineage                   =  45,
    eSource_qual_map                       =  46,
    eSource_qual_metagenome_source         =  47,
    eSource_qual_metagenomic               =  48,
    eSource_qual_old_lineage               =  49,
    eSource_qual_old_name                  =  50,
    eSource_qual_orgmod_note               =  51,
    eSource_qual_nat_host                  =  52,
    eSource_qual_pathovar                  =  53,
    eSource_qual_plasmid_name              =  54,
    eSource_qual_plastid_name              =  55,
    eSource_qual_pop_variant               =  56,
    eSource_qual_rearranged                =  57,
    eSource_qual_rev_primer_name           =  58,
    eSource_qual_rev_primer_seq            =  59,
    eSource_qual_segment                   =  60,
    eSource_qual_serogroup                 =  61,
    eSource_qual_serotype                  =  62,
    eSource_qual_serovar                   =  63,
    eSource_qual_sex                       =  64,
    eSource_qual_specimen_voucher          =  65,
    eSource_qual_strain                    =  66,
    eSource_qual_subclone                  =  67,
    eSource_qual_subgroup                  =  68,
    eSource_qual_subsource_note            =  69,
    eSource_qual_sub_species               =  70,
    eSource_qual_substrain                 =  71,
    eSource_qual_subtype                   =  72,
    eSource_qual_synonym                   =  73,
    eSource_qual_taxname                   =  74,
    eSource_qual_teleomorph                =  75,
    eSource_qual_tissue_lib                =  76,
    eSource_qual_tissue_type               =  77,
    eSource_qual_transgenic                =  78,
    eSource_qual_transposon_name           =  79,
    eSource_qual_type                      =  80,
    eSource_qual_variety                   =  81,
    eSource_qual_specimen_voucher_INST     =  82,
    eSource_qual_specimen_voucher_COLL     =  83,
    eSource_qual_specimen_voucher_SpecID   =  84,
    eSource_qual_culture_collection_INST   =  85,
    eSource_qual_culture_collection_COLL   =  86,
    eSource_qual_culture_collection_SpecID =  87,
    eSource_qual_bio_material_INST         =  88,
    eSource_qual_bio_material_COLL         =  89,
    eSource_qual_bio_material_SpecID       =  90,
    eSource_qual_all_notes                 =  91,
    eSource_qual_mating_type               =  92,
    eSource_qual_linkage_group             =  93,
    eSource_qual_haplogroup                =  94,
    eSource_qual_all_quals                 =  95,
    eSource_qual_dbxref                    =  96,
    eSource_qual_taxid                     =  97,
    eSource_qual_all_primers               =  98,
    eSource_qual_altitude                  =  99,
    eSource_qual_type_material             = 100
};

/// Access to ESource_qual's attributes (values, names) as defined in spec
 const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(ESource_qual)(void);


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_SOURCE_QUAL_BASE_HPP
