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
 *   'cdd.asn'.
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
#include <objects/cdd/Cdd_Viewer.hpp>
#include <objects/cdd/Cdd_Viewer_Rect.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CCdd_Viewer_Base::, ECtrl, true)
{
    SET_ENUM_INTERNAL_NAME("Cdd-Viewer", "ctrl");
    SET_ENUM_MODULE("NCBI-Cdd");
    ADD_ENUM_VALUE("unassigned", eCtrl_unassigned);
    ADD_ENUM_VALUE("cd-info", eCtrl_cd_info);
    ADD_ENUM_VALUE("align-annot", eCtrl_align_annot);
    ADD_ENUM_VALUE("seq-list", eCtrl_seq_list);
    ADD_ENUM_VALUE("seq-tree", eCtrl_seq_tree);
    ADD_ENUM_VALUE("merge-preview", eCtrl_merge_preview);
    ADD_ENUM_VALUE("cross-hits", eCtrl_cross_hits);
    ADD_ENUM_VALUE("notes", eCtrl_notes);
    ADD_ENUM_VALUE("tax-tree", eCtrl_tax_tree);
    ADD_ENUM_VALUE("dart", eCtrl_dart);
    ADD_ENUM_VALUE("dart-selected-rows", eCtrl_dart_selected_rows);
    ADD_ENUM_VALUE("other", eCtrl_other);
}
END_ENUM_INFO

void CCdd_Viewer_Base::ResetRect(void)
{
    m_Rect.Reset();
}

void CCdd_Viewer_Base::SetRect(CCdd_Viewer_Base::TRect& value)
{
    m_Rect.Reset(&value);
}

CCdd_Viewer_Base::TRect& CCdd_Viewer_Base::SetRect(void)
{
    if ( !m_Rect )
        m_Rect.Reset(new ncbi::objects::CCdd_Viewer_Rect());
    return (*m_Rect);
}

void CCdd_Viewer_Base::ResetAccessions(void)
{
    m_Accessions.clear();
    m_set_State[0] &= ~0x30;
}

void CCdd_Viewer_Base::Reset(void)
{
    ResetCtrl();
    ResetRect();
    ResetAccessions();
}

BEGIN_NAMED_BASE_CLASS_INFO("Cdd-Viewer", CCdd_Viewer)
{
    SET_CLASS_MODULE("NCBI-Cdd");
    ADD_NAMED_ENUM_MEMBER("ctrl", m_Ctrl, ECtrl)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("rect", m_Rect, CCdd_Viewer_Rect)->SetOptional();
    ADD_NAMED_MEMBER("accessions", m_Accessions, STL_list, (STD, (string)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CCdd_Viewer_Base::CCdd_Viewer_Base(void)
    : m_Ctrl((ECtrl)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CCdd_Viewer_Base::~CCdd_Viewer_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

