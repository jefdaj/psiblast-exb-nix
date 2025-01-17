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
#include <objects/cdd/Update_align.hpp>
#include <objects/cdd/Update_comment.hpp>
#include <objects/seq/Seq_annot.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CUpdate_align_Base::, EType, true)
{
    SET_ENUM_INTERNAL_NAME("Update-align", "type");
    SET_ENUM_MODULE("NCBI-Cdd");
    ADD_ENUM_VALUE("unassigned", eType_unassigned);
    ADD_ENUM_VALUE("update", eType_update);
    ADD_ENUM_VALUE("update-3d", eType_update_3d);
    ADD_ENUM_VALUE("demoted", eType_demoted);
    ADD_ENUM_VALUE("demoted-3d", eType_demoted_3d);
    ADD_ENUM_VALUE("other", eType_other);
}
END_ENUM_INFO

void CUpdate_align_Base::ResetDescription(void)
{
    m_Description.clear();
    m_set_State[0] &= ~0x3;
}

void CUpdate_align_Base::ResetSeqannot(void)
{
    m_Seqannot.Reset();
}

void CUpdate_align_Base::SetSeqannot(CUpdate_align_Base::TSeqannot& value)
{
    m_Seqannot.Reset(&value);
}

CUpdate_align_Base::TSeqannot& CUpdate_align_Base::SetSeqannot(void)
{
    if ( !m_Seqannot )
        m_Seqannot.Reset(new ncbi::objects::CSeq_annot());
    return (*m_Seqannot);
}

void CUpdate_align_Base::Reset(void)
{
    ResetDescription();
    ResetSeqannot();
    ResetType();
}

BEGIN_NAMED_BASE_CLASS_INFO("Update-align", CUpdate_align)
{
    SET_CLASS_MODULE("NCBI-Cdd");
    ADD_NAMED_MEMBER("description", m_Description, STL_list, (STL_CRef, (CLASS, (CUpdate_comment))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("seqannot", m_Seqannot, CSeq_annot)->SetOptional();
    ADD_NAMED_ENUM_MEMBER("type", m_Type, EType)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CUpdate_align_Base::CUpdate_align_Base(void)
    : m_Type((EType)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CUpdate_align_Base::~CUpdate_align_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

