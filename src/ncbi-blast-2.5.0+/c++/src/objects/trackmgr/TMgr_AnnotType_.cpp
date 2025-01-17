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
 *   'trackmgr.asn'.
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
#include <objects/trackmgr/TMgr_AnnotType.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_INFO("TMgr-AnnotType", ETMgr_AnnotType, true)
{
    SET_ENUM_MODULE("NCBI-TrackManager");
    ADD_ENUM_VALUE("total", eTMgr_AnnotType_total);
    ADD_ENUM_VALUE("feat", eTMgr_AnnotType_feat);
    ADD_ENUM_VALUE("feat-gene", eTMgr_AnnotType_feat_gene);
    ADD_ENUM_VALUE("feat-cdregion", eTMgr_AnnotType_feat_cdregion);
    ADD_ENUM_VALUE("feat-prot", eTMgr_AnnotType_feat_prot);
    ADD_ENUM_VALUE("feat-rna", eTMgr_AnnotType_feat_rna);
    ADD_ENUM_VALUE("feat-imp", eTMgr_AnnotType_feat_imp);
    ADD_ENUM_VALUE("feat-region", eTMgr_AnnotType_feat_region);
    ADD_ENUM_VALUE("feat-clone", eTMgr_AnnotType_feat_clone);
    ADD_ENUM_VALUE("feat-variation", eTMgr_AnnotType_feat_variation);
    ADD_ENUM_VALUE("feat-user", eTMgr_AnnotType_feat_user);
    ADD_ENUM_VALUE("seq-table", eTMgr_AnnotType_seq_table);
    ADD_ENUM_VALUE("graph", eTMgr_AnnotType_graph);
    ADD_ENUM_VALUE("align", eTMgr_AnnotType_align);
    ADD_ENUM_VALUE("ids", eTMgr_AnnotType_ids);
    ADD_ENUM_VALUE("locs", eTMgr_AnnotType_locs);
}
END_ENUM_INFO


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

