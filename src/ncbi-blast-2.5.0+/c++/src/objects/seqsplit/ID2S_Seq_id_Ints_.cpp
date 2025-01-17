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
#include <objects/seqsplit/ID2S_Seq_id_Ints.hpp>
#include <objects/seqloc/Seq_id.hpp>
#include <objects/seqsplit/ID2S_Interval.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CID2S_Seq_id_Ints_Base::ResetSeq_id(void)
{
    if ( !m_Seq_id ) {
        m_Seq_id.Reset(new TSeq_id());
        return;
    }
    (*m_Seq_id).Reset();
}

void CID2S_Seq_id_Ints_Base::SetSeq_id(CID2S_Seq_id_Ints_Base::TSeq_id& value)
{
    m_Seq_id.Reset(&value);
}

void CID2S_Seq_id_Ints_Base::ResetInts(void)
{
    m_Ints.clear();
    m_set_State[0] &= ~0xc;
}

void CID2S_Seq_id_Ints_Base::Reset(void)
{
    ResetSeq_id();
    ResetInts();
}

BEGIN_NAMED_BASE_CLASS_INFO("ID2S-Seq-id-Ints", CID2S_Seq_id_Ints)
{
    SET_CLASS_MODULE("NCBI-Seq-split");
    ADD_NAMED_REF_MEMBER("seq-id", m_Seq_id, CSeq_id);
    ADD_NAMED_MEMBER("ints", m_Ints, STL_list_set, (STL_CRef, (CLASS, (CID2S_Interval))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CID2S_Seq_id_Ints_Base::CID2S_Seq_id_Ints_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetSeq_id();
    }
}

// destructor
CID2S_Seq_id_Ints_Base::~CID2S_Seq_id_Ints_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

