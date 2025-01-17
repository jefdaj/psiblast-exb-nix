/* $Id: ValidErrItem.hpp 512605 2016-09-01 16:57:10Z ivanov $
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

/// @file ValidErrItem.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'valerr.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: ValidErrItem_.hpp


#ifndef OBJECTS_VALERR_VALIDERRITEM_HPP
#define OBJECTS_VALERR_VALIDERRITEM_HPP

#include <corelib/ncbistd.hpp>
#include <corelib/ncbidiag.hpp>
#include <objects/seqset/Seq_entry.hpp>

// generated includes
#include <objects/valerr/ValidErrItem_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

// ===========================  Internal error types  ==========================

#define ERR_CODE_BEGIN(x)  x##BEGIN
#define ERR_CODE_END(x) x##END

/*
    Validation errors can be saved as data objects.  So we must
    take care that these error code numbers do not change.
    Only add new codes at the ends of groups. (right before ERR_CODE_END(...)).
    Only add new groups of error codes at the end of enums, (right before eErr_Max).
    Do not change the initialization constants (e.g. = 1000 )
    eErr_Max must always be the last.
*/
enum EErrType {
    eErr_ALL = 0,
    eErr_UNKNOWN,

    ERR_CODE_BEGIN(SEQ_INST),
    eErr_SEQ_INST_ExtNotAllowed,
    eErr_SEQ_INST_ExtBadOrMissing,
    eErr_SEQ_INST_SeqDataNotFound,
    eErr_SEQ_INST_SeqDataNotAllowed,
    eErr_SEQ_INST_ReprInvalid,
    eErr_SEQ_INST_CircularProtein,
    eErr_SEQ_INST_DSProtein,
    eErr_SEQ_INST_MolNotSet,
    eErr_SEQ_INST_MolOther,
    eErr_SEQ_INST_FuzzyLen,
    eErr_SEQ_INST_InvalidLen,
    eErr_SEQ_INST_InvalidAlphabet,
    eErr_SEQ_INST_SeqDataLenWrong,
    eErr_SEQ_INST_SeqPortFail,
    eErr_SEQ_INST_InvalidResidue,
    eErr_SEQ_INST_StopInProtein,
    eErr_SEQ_INST_PartialInconsistent,
    eErr_SEQ_INST_ShortSeq,
    eErr_SEQ_INST_NoIdOnBioseq,
    eErr_SEQ_INST_BadDeltaSeq,
    eErr_SEQ_INST_LongHtgsSequence,
    eErr_SEQ_INST_LongLiteralSequence,
    eErr_SEQ_INST_SequenceExceeds350kbp,
    eErr_SEQ_INST_ConflictingIdsOnBioseq,
    eErr_SEQ_INST_MolNuclAcid,
    eErr_SEQ_INST_ConflictingBiomolTech,
    eErr_SEQ_INST_SeqIdNameHasSpace,
    eErr_SEQ_INST_IdOnMultipleBioseqs,
    eErr_SEQ_INST_DuplicateSegmentReferences,
    eErr_SEQ_INST_TrailingX,
    eErr_SEQ_INST_BadSeqIdFormat,
    eErr_SEQ_INST_PartsOutOfOrder,
    eErr_SEQ_INST_BadSecondaryAccn,
    eErr_SEQ_INST_ZeroGiNumber,
    eErr_SEQ_INST_RnaDnaConflict,
    eErr_SEQ_INST_HistoryGiCollision,
    eErr_SEQ_INST_GiWithoutAccession,
    eErr_SEQ_INST_MultipleAccessions,
    eErr_SEQ_INST_HistAssemblyMissing,
    eErr_SEQ_INST_TerminalNs,
    eErr_SEQ_INST_UnexpectedIdentifierChange,
    eErr_SEQ_INST_InternalNsInSeqLit,
    eErr_SEQ_INST_SeqLitGapLength0,
    eErr_SEQ_INST_TpaAssmeblyProblem,
    eErr_SEQ_INST_SeqLocLength,
    eErr_SEQ_INST_MissingGaps,
    eErr_SEQ_INST_CompleteTitleProblem,
    eErr_SEQ_INST_CompleteCircleProblem,
    eErr_SEQ_INST_BadHTGSeq,
    eErr_SEQ_INST_GapInProtein,
    eErr_SEQ_INST_BadProteinStart,
    eErr_SEQ_INST_TerminalGap,
    eErr_SEQ_INST_OverlappingDeltaRange,
    eErr_SEQ_INST_LeadingX,
    eErr_SEQ_INST_InternalNsInSeqRaw,
    eErr_SEQ_INST_InternalNsAdjacentToGap,
    eErr_SEQ_INST_CaseDifferenceInSeqID,
    eErr_SEQ_INST_DeltaComponentIsGi0,
    eErr_SEQ_INST_FarFetchFailure,
    eErr_SEQ_INST_InternalGapsInSeqRaw,
    eErr_SEQ_INST_SelfReferentialSequence,
    eErr_SEQ_INST_WholeComponent,
    eErr_SEQ_INST_TSAHistAssemblyMissing,
    eErr_SEQ_INST_ProteinsHaveGeneralID,
    eErr_SEQ_INST_HighNContent,
    eErr_SEQ_INST_SeqLitDataLength0,
    eErr_SEQ_INST_DSmRNA,
    eErr_SEQ_INST_HighNContentStretch,
    eErr_SEQ_INST_HighNContentPercent,
    eErr_SEQ_INST_SeqLitGapFuzzNot100,
    eErr_SEQ_INST_SeqGapProblem,
    eErr_SEQ_INST_WGSMasterLacksStrucComm,
    eErr_SEQ_INST_TSAMasterLacksStrucComm,
    eErr_SEQ_INST_AllNs,
    ERR_CODE_END(SEQ_INST),

    ERR_CODE_BEGIN(SEQ_DESCR) = 1000,
    eErr_SEQ_DESCR_BioSourceMissing,
    eErr_SEQ_DESCR_InvalidForType,
    eErr_SEQ_DESCR_FileOpenCollision,
    eErr_SEQ_DESCR_Unknown,
    eErr_SEQ_DESCR_NoPubFound,
    eErr_SEQ_DESCR_NoOrgFound,
    eErr_SEQ_DESCR_MultipleBioSources,
    eErr_SEQ_DESCR_NoMolInfoFound,
    eErr_SEQ_DESCR_BadCountryCode,
    eErr_SEQ_DESCR_NoTaxonID,
    eErr_SEQ_DESCR_InconsistentBioSources,
    eErr_SEQ_DESCR_MissingLineage,
    eErr_SEQ_DESCR_SerialInComment,
    eErr_SEQ_DESCR_BioSourceNeedsFocus,
    eErr_SEQ_DESCR_BadOrganelle,
    eErr_SEQ_DESCR_MultipleChromosomes,
    eErr_SEQ_DESCR_BadSubSource,
    eErr_SEQ_DESCR_BadOrgMod,
    eErr_SEQ_DESCR_InconsistentProteinTitle,
    eErr_SEQ_DESCR_Inconsistent,
    eErr_SEQ_DESCR_ObsoleteSourceLocation,
    eErr_SEQ_DESCR_ObsoleteSourceQual,
    eErr_SEQ_DESCR_StructuredSourceNote,
    eErr_SEQ_DESCR_UnnecessaryBioSourceFocus,
    eErr_SEQ_DESCR_RefGeneTrackingWithoutStatus,
    eErr_SEQ_DESCR_UnwantedCompleteFlag,
    eErr_SEQ_DESCR_CollidingPublications,
    eErr_SEQ_DESCR_TransgenicProblem,
    eErr_SEQ_DESCR_TaxonomyLookupProblem,
    eErr_SEQ_DESCR_MultipleTitles,
    eErr_SEQ_DESCR_RefGeneTrackingOnNonRefSeq,
    eErr_SEQ_DESCR_BioSourceInconsistency,
    eErr_SEQ_DESCR_FastaBracketTitle,
    eErr_SEQ_DESCR_MissingText,
    eErr_SEQ_DESCR_BadCollectionDate,
    eErr_SEQ_DESCR_BadPCRPrimerSequence,
    eErr_SEQ_DESCR_BadPunctuation,
    eErr_SEQ_DESCR_BadPCRPrimerName,
    eErr_SEQ_DESCR_BioSourceOnProtein,
    eErr_SEQ_DESCR_BioSourceDbTagConflict,
    eErr_SEQ_DESCR_DuplicatePCRPrimerSequence,
    eErr_SEQ_DESCR_MultipleNames,
    eErr_SEQ_DESCR_MultipleComments,
    eErr_SEQ_DESCR_LatLonProblem,
    eErr_SEQ_DESCR_LatLonFormat,
    eErr_SEQ_DESCR_LatLonRange,
    eErr_SEQ_DESCR_LatLonValue,
    eErr_SEQ_DESCR_LatLonCountry,
    eErr_SEQ_DESCR_LatLonState,
    eErr_SEQ_DESCR_BadSpecificHost,
    eErr_SEQ_DESCR_RefGeneTrackingIllegalStatus,
    eErr_SEQ_DESCR_ReplacedCountryCode,
    eErr_SEQ_DESCR_BadInstitutionCode,
    eErr_SEQ_DESCR_BadCollectionCode,
    eErr_SEQ_DESCR_BadVoucherID,
    eErr_SEQ_DESCR_UnstructuredVoucher,
    eErr_SEQ_DESCR_ChromosomeLocation,
    eErr_SEQ_DESCR_MultipleSourceQualifiers,
    eErr_SEQ_DESCR_UnbalancedParentheses,
    eErr_SEQ_DESCR_MultipleSourceVouchers,
    eErr_SEQ_DESCR_BadCountryCapitalization,
    eErr_SEQ_DESCR_WrongVoucherType,
    eErr_SEQ_DESCR_UserObjectProblem,
    eErr_SEQ_DESCR_TitleHasPMID,
    eErr_SEQ_DESCR_BadKeyword,
    eErr_SEQ_DESCR_NoOrganismInTitle,
    eErr_SEQ_DESCR_MissingChromosome,
    eErr_SEQ_DESCR_LatLonAdjacent,
    eErr_SEQ_DESCR_BadStrucCommInvalidFieldName,
    eErr_SEQ_DESCR_BadStrucCommInvalidFieldValue,
    eErr_SEQ_DESCR_BadStrucCommMissingField,
    eErr_SEQ_DESCR_BadStrucCommFieldOutOfOrder,
    eErr_SEQ_DESCR_BadStrucCommMultipleFields,
    eErr_SEQ_DESCR_BioSourceNeedsChromosome,
    eErr_SEQ_DESCR_MolInfoConflictsWithBioSource,
    eErr_SEQ_DESCR_MissingKeyword,
    eErr_SEQ_DESCR_FakeStructuredComment,
    eErr_SEQ_DESCR_StructuredCommentPrefixOrSuffixMissing,
    eErr_SEQ_DESCR_LatLonWater,
    eErr_SEQ_DESCR_LatLonOffshore,
    eErr_SEQ_DESCR_MissingPersonalCollectionName,
    eErr_SEQ_DESCR_LatLonPrecision,
    eErr_SEQ_DESCR_DBLinkProblem,
    eErr_SEQ_DESCR_FinishedStatusForWGS,
    eErr_SEQ_DESCR_BadTentativeName,
    eErr_SEQ_DESCR_OrganismNotFound,
    eErr_SEQ_DESCR_TaxonomyIsSpeciesProblem,
    eErr_SEQ_DESCR_TaxonomyConsultRequired,
    eErr_SEQ_DESCR_TaxonomyNucleomorphProblem,
    eErr_SEQ_DESCR_InconsistentMolTypeBiomol,
    eErr_SEQ_DESCR_BadInstitutionCountry,
    eErr_SEQ_DESCR_AmbiguousSpecificHost,
    eErr_SEQ_DESCR_BadAltitude,
    eErr_SEQ_DESCR_RefGeneTrackingOnNucProtSet,
    eErr_SEQ_DESCR_InconsistentDates,
    eErr_SEQ_DESCR_MultipleTaxonIDs,
    eErr_SEQ_DESCR_ScaffoldLacksBioProject,
    eErr_SEQ_DESCR_CompleteGenomeLacksBioProject,
    eErr_SEQ_DESCR_TaxonomyPlastidsProblem,
    eErr_SEQ_DESCR_OrganismIsUndefinedSpecies,
    eErr_SEQ_DESCR_SuspectedContaminatedCellLine,
    eErr_SEQ_DESCR_WrongBiomolForTechnique,
    eErr_SEQ_DESCR_WrongOrganismFor16SrRNA,
    eErr_SEQ_DESCR_InconsistentWGSFlags,
    ERR_CODE_END(SEQ_DESCR),


    ERR_CODE_BEGIN(GENERIC) = 2000,
    eErr_GENERIC_NonAsciiAsn,
    eErr_GENERIC_Spell,
    eErr_GENERIC_AuthorListHasEtAl,
    eErr_GENERIC_MissingPubInfo,
    eErr_GENERIC_UnnecessaryPubEquiv,
    eErr_GENERIC_BadPageNumbering,
    eErr_GENERIC_MedlineEntryPub,
    eErr_GENERIC_BadDate,
    eErr_GENERIC_StructuredCitGenCit,
    eErr_GENERIC_CollidingSerialNumbers,
    eErr_GENERIC_EmbeddedScript,
    eErr_GENERIC_PublicationInconsistency,
    eErr_GENERIC_SgmlPresentInText,
    eErr_GENERIC_UnexpectedPubStatusComment,
    eErr_GENERIC_PastReleaseDate,
    eErr_GENERIC_MissingISOJTA,
    eErr_GENERIC_MissingVolume,
    eErr_GENERIC_MissingVolumeEpub,
    eErr_GENERIC_MissingPages,
    eErr_GENERIC_MissingPagesEpub,
    ERR_CODE_END(GENERIC),

    ERR_CODE_BEGIN(SEQ_PKG) = 3000,
    eErr_SEQ_PKG_NoCdRegionPtr,
    eErr_SEQ_PKG_NucProtProblem,
    eErr_SEQ_PKG_SegSetProblem,
    eErr_SEQ_PKG_EmptySet,
    eErr_SEQ_PKG_NucProtNotSegSet,
    eErr_SEQ_PKG_SegSetNotParts,
    eErr_SEQ_PKG_SegSetMixedBioseqs,
    eErr_SEQ_PKG_PartsSetMixedBioseqs,
    eErr_SEQ_PKG_PartsSetHasSets,
    eErr_SEQ_PKG_FeaturePackagingProblem,
    eErr_SEQ_PKG_GenomicProductPackagingProblem,
    eErr_SEQ_PKG_InconsistentMolInfoBiomols,
    eErr_SEQ_PKG_ArchaicFeatureLocation,
    eErr_SEQ_PKG_ArchaicFeatureProduct,
    eErr_SEQ_PKG_GraphPackagingProblem,
    eErr_SEQ_PKG_InternalGenBankSet,
    eErr_SEQ_PKG_ConSetProblem,
    eErr_SEQ_PKG_NoBioseqFound,
    eErr_SEQ_PKG_INSDRefSeqPackaging,
    eErr_SEQ_PKG_GPSnonGPSPackaging,
    eErr_SEQ_PKG_RefSeqPopSet,
      eErr_SEQ_PKG_BioseqSetClassNotSet,
    eErr_SEQ_PKG_OrphanedProtein,
    eErr_SEQ_PKG_MissingSetTitle,
    eErr_SEQ_PKG_NucProtSetHasTitle,
    eErr_SEQ_PKG_ComponentMissingTitle,
    eErr_SEQ_PKG_SingleItemSet,
    eErr_SEQ_PKG_MisplacedMolInfo,
    eErr_SEQ_PKG_ImproperlyNestedSets,
    eErr_SEQ_PKG_SeqSubmitWithWgsSet,
    ERR_CODE_END(SEQ_PKG),

    ERR_CODE_BEGIN(SEQ_FEAT) = 4000,
    eErr_SEQ_FEAT_InvalidForType,
    eErr_SEQ_FEAT_PartialProblem,
    eErr_SEQ_FEAT_InvalidType,
    eErr_SEQ_FEAT_Range,
    eErr_SEQ_FEAT_MixedStrand,
    eErr_SEQ_FEAT_SeqLocOrder,
    eErr_SEQ_FEAT_CdTransFail,
    eErr_SEQ_FEAT_StartCodon,
    eErr_SEQ_FEAT_InternalStop,
    eErr_SEQ_FEAT_NoProtein,
    eErr_SEQ_FEAT_MisMatchAA,
    eErr_SEQ_FEAT_TransLen,
    eErr_SEQ_FEAT_NoStop,
    eErr_SEQ_FEAT_TranslExcept,
    eErr_SEQ_FEAT_NoProtRefFound,
    eErr_SEQ_FEAT_NotSpliceConsensus,
    eErr_SEQ_FEAT_OrfCdsHasProduct,
    eErr_SEQ_FEAT_GeneRefHasNoData,
    eErr_SEQ_FEAT_ExceptInconsistent,
    eErr_SEQ_FEAT_ProtRefHasNoData,
    eErr_SEQ_FEAT_GenCodeMismatch,
    eErr_SEQ_FEAT_RNAtype0,
    eErr_SEQ_FEAT_UnknownImpFeatKey,
    eErr_SEQ_FEAT_UnknownImpFeatQual,
    eErr_SEQ_FEAT_WrongQualOnImpFeat,
    eErr_SEQ_FEAT_MissingQualOnImpFeat,
    eErr_SEQ_FEAT_PseudoCdsHasProduct,
    eErr_SEQ_FEAT_IllegalDbXref,
    eErr_SEQ_FEAT_FarLocation,
    eErr_SEQ_FEAT_DuplicateFeat,
    eErr_SEQ_FEAT_UnnecessaryGeneXref,
    eErr_SEQ_FEAT_TranslExceptPhase,
    eErr_SEQ_FEAT_TrnaCodonWrong,
    eErr_SEQ_FEAT_BothStrands,
    eErr_SEQ_FEAT_CDSgeneRange,
    eErr_SEQ_FEAT_CDSmRNArange,
    eErr_SEQ_FEAT_OverlappingPeptideFeat,
    eErr_SEQ_FEAT_SerialInComment,
    eErr_SEQ_FEAT_MultipleCDSproducts,
    eErr_SEQ_FEAT_FocusOnBioSourceFeature,
    eErr_SEQ_FEAT_PeptideFeatOutOfFrame,
    eErr_SEQ_FEAT_InvalidQualifierValue,
    eErr_SEQ_FEAT_MultipleMRNAproducts,
    eErr_SEQ_FEAT_mRNAgeneRange,
    eErr_SEQ_FEAT_TranscriptLen,
    eErr_SEQ_FEAT_TranscriptMismatches,
    eErr_SEQ_FEAT_CDSproductPackagingProblem,
    eErr_SEQ_FEAT_DuplicateInterval,
    eErr_SEQ_FEAT_PolyAsiteNotPoint,
    eErr_SEQ_FEAT_ImpFeatBadLoc,
    eErr_SEQ_FEAT_LocOnSegmentedBioseq,
    eErr_SEQ_FEAT_UnnecessaryCitPubEquiv,
    eErr_SEQ_FEAT_ImpCDShasTranslation,
    eErr_SEQ_FEAT_ImpCDSnotPseudo,
    eErr_SEQ_FEAT_MissingMRNAproduct,
    eErr_SEQ_FEAT_AbuttingIntervals,
    eErr_SEQ_FEAT_CollidingGeneNames,
    eErr_SEQ_FEAT_MultiIntervalGene,
    eErr_SEQ_FEAT_FeatContentDup,
    eErr_SEQ_FEAT_BadProductSeqId,
    eErr_SEQ_FEAT_RnaProductMismatch,
    eErr_SEQ_FEAT_MissingCDSproduct,
    eErr_SEQ_FEAT_BadTrnaCodon,
    eErr_SEQ_FEAT_BadTrnaAA,
    eErr_SEQ_FEAT_OnlyGeneXrefs,
    eErr_SEQ_FEAT_UTRdoesNotAbutCDS,
    eErr_SEQ_FEAT_BadConflictFlag,
    eErr_SEQ_FEAT_ConflictFlagSet,
    eErr_SEQ_FEAT_LocusTagProblem,
    eErr_SEQ_FEAT_CollidingLocusTags,
    eErr_SEQ_FEAT_AltStartCodon,
    eErr_SEQ_FEAT_PartialsInconsistent,
    eErr_SEQ_FEAT_GenesInconsistent,
    eErr_SEQ_FEAT_DuplicateTranslExcept,
    eErr_SEQ_FEAT_TranslExceptAndRnaEditing,
    eErr_SEQ_FEAT_NoNameForProtein,
    eErr_SEQ_FEAT_TaxonDbxrefOnFeature,
    eErr_SEQ_FEAT_UnindexedFeature,
    eErr_SEQ_FEAT_CDSmRNAmismatch,
    eErr_SEQ_FEAT_UnnecessaryException,
    eErr_SEQ_FEAT_LocusTagProductMismatch,
    eErr_SEQ_FEAT_MrnaTransFail,
    eErr_SEQ_FEAT_PseudoCdsViaGeneHasProduct,
    eErr_SEQ_FEAT_MissingGeneXref,
    eErr_SEQ_FEAT_FeatureCitationProblem,
    eErr_SEQ_FEAT_NestedSeqLocMix,
    eErr_SEQ_FEAT_WrongQualOnFeature,
    eErr_SEQ_FEAT_MissingQualOnFeature,
    eErr_SEQ_FEAT_CodonQualifierUsed,
    eErr_SEQ_FEAT_UnknownFeatureQual,
    eErr_SEQ_FEAT_BadCharInAuthorName,
    eErr_SEQ_FEAT_PolyATail,
    eErr_SEQ_FEAT_ProteinNameEndsInBracket,
    eErr_SEQ_FEAT_CDSwithMultipleMRNAs,
    eErr_SEQ_FEAT_MultipleEquivBioSources,
    eErr_SEQ_FEAT_MultipleEquivPublications,
    eErr_SEQ_FEAT_BadFullLengthFeature,
    eErr_SEQ_FEAT_RedundantFields,
    eErr_SEQ_FEAT_CDSwithNoMRNAOverlap,
    eErr_SEQ_FEAT_CDSwithNoMRNA,
    eErr_SEQ_FEAT_FeatureProductInconsistency,
    eErr_SEQ_FEAT_ImproperBondLocation,
    eErr_SEQ_FEAT_GeneXrefWithoutGene,
    eErr_SEQ_FEAT_SeqFeatXrefProblem,
    eErr_SEQ_FEAT_ProductFetchFailure,
    eErr_SEQ_FEAT_SuspiciousGeneXref,
    eErr_SEQ_FEAT_MissingTrnaAA,
    eErr_SEQ_FEAT_CollidingFeatureIDs,
    eErr_SEQ_FEAT_ExceptionProblem,
    eErr_SEQ_FEAT_PolyAsignalNotRange,
    eErr_SEQ_FEAT_OldLocusTagMismtach,
    eErr_SEQ_FEAT_DuplicateGeneOntologyTerm,
    eErr_SEQ_FEAT_InvalidInferenceValue,
    eErr_SEQ_FEAT_HpotheticalProteinMismatch,
    eErr_SEQ_FEAT_FeatureRefersToAccession,
    eErr_SEQ_FEAT_SelfReferentialProduct,
    eErr_SEQ_FEAT_ITSdoesNotAbutRRNA,
    eErr_SEQ_FEAT_FeatureSeqIDCaseDifference,
    eErr_SEQ_FEAT_FeatureLocationIsGi0,
    eErr_SEQ_FEAT_GapFeatureProblem,
    eErr_SEQ_FEAT_PseudoCdsHasProtXref,
    eErr_SEQ_FEAT_ErroneousException,
    eErr_SEQ_FEAT_SegmentedGeneProblem,
    eErr_SEQ_FEAT_WholeLocation,
    eErr_SEQ_FEAT_BadEcNumberFormat,
    eErr_SEQ_FEAT_BadEcNumberValue,
    eErr_SEQ_FEAT_EcNumberProblem,
    eErr_SEQ_FEAT_VectorContamination,
    eErr_SEQ_FEAT_MinusStrandProtein,
    eErr_SEQ_FEAT_BadProteinName,
    eErr_SEQ_FEAT_GeneXrefWithoutLocus,
    eErr_SEQ_FEAT_UTRdoesNotExtendToEnd,
    eErr_SEQ_FEAT_CDShasTooManyXs,
    eErr_SEQ_FEAT_SuspiciousFrame,
    eErr_SEQ_FEAT_TerminalXDiscrepancy,
    eErr_SEQ_FEAT_UnnecessaryTranslExcept,
    eErr_SEQ_FEAT_SuspiciousQualifierValue,
    eErr_SEQ_FEAT_NotSpliceConsensusDonor,
    eErr_SEQ_FEAT_NotSpliceConsensusAcceptor,
    eErr_SEQ_FEAT_RareSpliceConsensusDonor,
    eErr_SEQ_FEAT_SeqFeatXrefNotReciprocal,
    eErr_SEQ_FEAT_SeqFeatXrefFeatureMissing,
    eErr_SEQ_FEAT_FeatureInsideGap,
    eErr_SEQ_FEAT_FeatureCrossesGap,
    eErr_SEQ_FEAT_BadAuthorSuffix,
    eErr_SEQ_FEAT_BadAnticodonAA,
    eErr_SEQ_FEAT_BadAnticodonCodon,
    eErr_SEQ_FEAT_BadAnticodonStrand,
    eErr_SEQ_FEAT_UndesiredGeneSynonym,
    eErr_SEQ_FEAT_UndesiredProteinName,
    eErr_SEQ_FEAT_FeatureBeginsOrEndsInGap,
    eErr_SEQ_FEAT_GeneOntologyTermMissingGOID,
    eErr_SEQ_FEAT_PseudoRnaHasProduct,
    eErr_SEQ_FEAT_PseudoRnaViaGeneHasProduct,
    eErr_SEQ_FEAT_BadRRNAcomponentOrder,
    eErr_SEQ_FEAT_BadRRNAcomponentOverlap,
    eErr_SEQ_FEAT_MissingGeneLocusTag,
    eErr_SEQ_FEAT_MultipleProtRefs,
    eErr_SEQ_FEAT_BadInternalCharacter,
    eErr_SEQ_FEAT_BadTrailingCharacter,
    eErr_SEQ_FEAT_BadTrailingHyphen,
    eErr_SEQ_FEAT_MultipleGeneOverlap,
    eErr_SEQ_FEAT_BadCharInAuthorLastName,
    eErr_SEQ_FEAT_PseudoCDSmRNArange,
    eErr_SEQ_FEAT_ExtendablePartialProblem,
    eErr_SEQ_FEAT_GeneXrefNeeded,
    eErr_SEQ_FEAT_RubiscoProblem,
    eErr_SEQ_FEAT_UnqualifiedException,
    eErr_SEQ_FEAT_ProteinNameHasPMID,
    eErr_SEQ_FEAT_BadGeneOntologyFormat,
    eErr_SEQ_FEAT_InconsistentGeneOntologyTermAndId,
    eErr_SEQ_FEAT_MultiplyAnnotatedGenes,
    eErr_SEQ_FEAT_ReplicatedGeneSequence,
    eErr_SEQ_FEAT_ShortIntron,
    eErr_SEQ_FEAT_GeneXrefStrandProblem,
    eErr_SEQ_FEAT_CDSmRNAXrefLocationProblem,
    eErr_SEQ_FEAT_LocusCollidesWithLocusTag,
    eErr_SEQ_FEAT_IdenticalGeneSymbolAndSynonym,
    eErr_SEQ_FEAT_NeedsNote,
    eErr_SEQ_FEAT_RptUnitRangeProblem,
    eErr_SEQ_FEAT_TooManyInferenceAccessions,
    eErr_SEQ_FEAT_SgmlPresentInText,
    eErr_SEQ_FEAT_MissingLocation,
    eErr_SEQ_FEAT_MultipleBioseqs,
    eErr_SEQ_FEAT_DifferntIdTypesInSeqLoc,
    eErr_SEQ_FEAT_IntervalBeginsOrEndsInGap,
    eErr_SEQ_FEAT_InconsistentRRNAstrands,
    eErr_SEQ_FEAT_CDSonMinusStrandMRNA,
    eErr_SEQ_FEAT_tRNAmRNAmixup,
    eErr_SEQ_FEAT_ProductLength,
    eErr_SEQ_FEAT_InconsistentPseudogeneCounts,
    eErr_SEQ_FEAT_DeletedEcNumber,
    eErr_SEQ_FEAT_ReplacedEcNumber,
    eErr_SEQ_FEAT_SplitEcNumber,
    eErr_SEQ_FEAT_PeptideFeatureLacksCDS,
    eErr_SEQ_FEAT_EcNumberDataMissing,
    eErr_SEQ_FEAT_CDSnotBetweenUTRs,
    eErr_SEQ_FEAT_ShortExon,
    eErr_SEQ_FEAT_ExtraProteinFeature,
    eErr_SEQ_FEAT_AssemblyGapAdjacentToNs,
    eErr_SEQ_FEAT_AssemblyGapCoversSequence,
    eErr_SEQ_FEAT_FeatureBeginsOrEndsWithN,
    eErr_SEQ_FEAT_FeatureIsMostlyNs,
    eErr_SEQ_FEAT_CDSonMinusStrandTranscribedRNA,
    eErr_SEQ_FEAT_MultipleGenCodes,
    eErr_SEQ_FEAT_InvalidFuzz,
    eErr_SEQ_FEAT_BadComment,
    eErr_SEQ_FEAT_NonsenseIntron,
    eErr_SEQ_FEAT_InconsistentPseudogeneValue,
    eErr_SEQ_FEAT_MultiIntervalIntron,
    eErr_SEQ_FEAT_SeqLocTypeProblem,
    eErr_SEQ_FEAT_RefSeqInText,
    eErr_SEQ_FEAT_ColdShockProteinProblem,
    eErr_SEQ_FEAT_BadLocation,
    ERR_CODE_END(SEQ_FEAT),

    ERR_CODE_BEGIN(SEQ_ALIGN) = 5000,
    eErr_SEQ_ALIGN_SeqIdProblem,
    eErr_SEQ_ALIGN_StrandRev,
    eErr_SEQ_ALIGN_DensegLenStart,
    eErr_SEQ_ALIGN_StartLessthanZero,
    eErr_SEQ_ALIGN_StartMorethanBiolen,
    eErr_SEQ_ALIGN_EndLessthanZero,
    eErr_SEQ_ALIGN_EndMorethanBiolen,
    eErr_SEQ_ALIGN_LenLessthanZero,
    eErr_SEQ_ALIGN_LenMorethanBiolen,
    eErr_SEQ_ALIGN_SumLenStart,
    eErr_SEQ_ALIGN_AlignDimSeqIdNotMatch,
    eErr_SEQ_ALIGN_SegsDimSeqIdNotMatch,
    eErr_SEQ_ALIGN_FastaLike,
    eErr_SEQ_ALIGN_NullSegs,
    eErr_SEQ_ALIGN_SegmentGap,
    eErr_SEQ_ALIGN_SegsDimOne,
    eErr_SEQ_ALIGN_AlignDimOne,
    eErr_SEQ_ALIGN_Segtype,
    eErr_SEQ_ALIGN_BlastAligns,
    eErr_SEQ_ALIGN_PercentIdentity,
    eErr_SEQ_ALIGN_ShortAln,
    eErr_SEQ_ALIGN_UnexpectedAlignmentType,
    eErr_SEQ_ALIGN_SegsDimMismatch,
    eErr_SEQ_ALIGN_SegsNumsegMismatch,
    eErr_SEQ_ALIGN_SegsStartsMismatch,
    eErr_SEQ_ALIGN_SegsPresentMismatch,
    eErr_SEQ_ALIGN_SegsPresentStartsMismatch,
    eErr_SEQ_ALIGN_SegsPresentStrandsMismatch,
    
    ERR_CODE_END(SEQ_ALIGN),

    ERR_CODE_BEGIN(SEQ_GRAPH) = 6000,
    eErr_SEQ_GRAPH_GraphMin,
    eErr_SEQ_GRAPH_GraphMax,
    eErr_SEQ_GRAPH_GraphBelow,
    eErr_SEQ_GRAPH_GraphAbove,
    eErr_SEQ_GRAPH_GraphByteLen,
    eErr_SEQ_GRAPH_GraphOutOfOrder,
    eErr_SEQ_GRAPH_GraphBioseqLen,
    eErr_SEQ_GRAPH_GraphSeqLitLen,
    eErr_SEQ_GRAPH_GraphSeqLocLen,
    eErr_SEQ_GRAPH_GraphStartPhase,
    eErr_SEQ_GRAPH_GraphStopPhase,
    eErr_SEQ_GRAPH_GraphDiffNumber,
    eErr_SEQ_GRAPH_GraphACGTScore,
    eErr_SEQ_GRAPH_GraphNScore,
    eErr_SEQ_GRAPH_GraphGapScore,
    eErr_SEQ_GRAPH_GraphOverlap,
    eErr_SEQ_GRAPH_GraphBioseqId,
    eErr_SEQ_GRAPH_GraphACGTScoreMany,
    eErr_SEQ_GRAPH_GraphNScoreMany,
    eErr_SEQ_GRAPH_GraphLocInvalid,
    ERR_CODE_END(SEQ_GRAPH),

    ERR_CODE_BEGIN(SEQ_ANNOT) = 7000,
    eErr_SEQ_ANNOT_AnnotIDs,
    eErr_SEQ_ANNOT_AnnotLOCs,
    ERR_CODE_END(SEQ_ANNOT),

    ERR_CODE_BEGIN(INTERNAL) = 8000,
    eErr_INTERNAL_Exception,
    ERR_CODE_END(INTERNAL),

    eErr_MAX
};

/////////////////////////////////////////////////////////////////////////////
class NCBI_VALERR_EXPORT CValidErrItem : public CValidErrItem_Base
{
    typedef CValidErrItem_Base Tparent;
public:

    // destructor
    CValidErrItem(void);
    ~CValidErrItem(void);

    // severity with proper type.
    EDiagSev                GetSeverity  (void) const;
    // Error code
    const string            GetErrCode  (void) const;
    static unsigned int     GetErrCount(void);
    // Error group (SEQ_FEAT, SEQ_INST etc.)
    const string            GetErrGroup (void) const;
    // Verbose message
    const string            GetVerbose  (void) const;
    // Offending object
    const CSerialObject&    GetObject   (void) const;
    bool                    IsSetObject (void) const;

    // Convert Severity from enum to a string representation
    static const string    ConvertSeverity(EDiagSev sev);
    static const string    ConvertErrCode(unsigned int);
    static const string    ConvertErrGroup(unsigned int);

    // Convert error code from string to unsigned int
    static unsigned int    ConvertToErrCode(const string& str);

    bool IsSetContext(void) const;
    const CSeq_entry& GetContext(void) const;
    
private:
    friend class CValidError;

    // constructor
    CValidErrItem(EDiagSev             sev,       // severity
                  unsigned int         ec,        // error code
                  const string&        msg,       // message
                  const string&        obj_desc,  // object description
                  const CSerialObject& obj,       // offending object
                  const string&        acc,       // accession
                  const int            ver,       // version of object.
                  const int            seq_offset = 0); // sequence offset

    CValidErrItem(EDiagSev             sev,       // severity
                  unsigned int         ec,        // error code
                  const string&        msg,       // message
                  const string&        obj_desc,  // object description
                  const CSerialObject& obj,       // offending object
                  const string&        acc,       // accession
                  const int            ver,       // version of object.
                  const string&        feature_id, // feature ID
                  const int            seq_offset = 0); // sequence offset

    // constructor
    CValidErrItem(EDiagSev             sev,       // severity
                  unsigned int         ec,        // error code
                  const string&        msg,       // message
                  const string&        obj_desc,  // object description
                  const CSerialObject& obj,       // offending object
                  const CSeq_entry&    context,   // desc's context.
                  const string&        acc,       // accession
                  const int            ver,       // version of object.
                  const int            seq_offset = 0); // sequence offset

    // Prohibit default & copy constructor and assignment operator
    CValidErrItem(const CValidErrItem& value);
    CValidErrItem& operator=(const CValidErrItem& value);

    // member data values that are not serialized.
    CConstRef<CSerialObject>        m_Object;     // offending object
    CConstRef<CSeq_entry>           m_Ctx; // currently used for Seqdesc objects only

    static const string sm_Terse[];
    static const string sm_Verbose[];
};

/////////////////// CValidErrItem inline methods

// constructor
inline
CValidErrItem::CValidErrItem(void)
{
}


inline
EDiagSev CValidErrItem::GetSeverity(void) const
{
    // convert from internal integer to external enum type.
    return static_cast<EDiagSev>(GetSev());
}


inline
bool CValidErrItem::IsSetContext(void) const 
{ 
    return m_Ctx.NotEmpty(); 
}

inline
const CSeq_entry& CValidErrItem::GetContext(void) const 
{ 
    return *m_Ctx; 
}


/////////////////// end of CValidErrItem inline methods



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

#endif // OBJECTS_VALERR_VALIDERRITEM_HPP
/* Original file checksum: lines: 94, chars: 2634, CRC32: d01b90f9 */
