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
 *   'seqsplit.asn'.
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
#include <objects/seqsplit/ID2S_Bioseq_place_Info.hpp>
#include <objects/seqsplit/ID2S_Bioseq_Ids.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CID2S_Bioseq_place_Info_Base::ResetSeq_ids(void)
{
    if ( !m_Seq_ids ) {
        m_Seq_ids.Reset(new TSeq_ids());
        return;
    }
    (*m_Seq_ids).Reset();
}

void CID2S_Bioseq_place_Info_Base::SetSeq_ids(CID2S_Bioseq_place_Info_Base::TSeq_ids& value)
{
    m_Seq_ids.Reset(&value);
}

void CID2S_Bioseq_place_Info_Base::Reset(void)
{
    ResetBioseq_set();
    ResetSeq_ids();
}

BEGIN_NAMED_BASE_CLASS_INFO("ID2S-Bioseq-place-Info", CID2S_Bioseq_place_Info)
{
    SET_CLASS_MODULE("NCBI-Seq-split");
    ADD_NAMED_STD_MEMBER("bioseq-set", m_Bioseq_set)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("seq-ids", m_Seq_ids, CID2S_Bioseq_Ids);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CID2S_Bioseq_place_Info_Base::CID2S_Bioseq_place_Info_Base(void)
    : m_Bioseq_set(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetSeq_ids();
    }
}

// destructor
CID2S_Bioseq_place_Info_Base::~CID2S_Bioseq_place_Info_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
