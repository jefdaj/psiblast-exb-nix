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
 *   'seqloc.asn'.
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
#include <objects/seqloc/Seq_interval.hpp>
#include <objects/general/Int_fuzz.hpp>
#include <objects/seqloc/Seq_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CSeq_interval_Base::ResetId(void)
{
    if ( !m_Id ) {
        m_Id.Reset(new TId());
        return;
    }
    (*m_Id).Reset();
}

void CSeq_interval_Base::SetId(CSeq_interval_Base::TId& value)
{
    m_Id.Reset(&value);
}

void CSeq_interval_Base::ResetFuzz_from(void)
{
    m_Fuzz_from.Reset();
}

void CSeq_interval_Base::SetFuzz_from(CSeq_interval_Base::TFuzz_from& value)
{
    m_Fuzz_from.Reset(&value);
}

CSeq_interval_Base::TFuzz_from& CSeq_interval_Base::SetFuzz_from(void)
{
    if ( !m_Fuzz_from )
        m_Fuzz_from.Reset(new ncbi::objects::CInt_fuzz());
    return (*m_Fuzz_from);
}

void CSeq_interval_Base::ResetFuzz_to(void)
{
    m_Fuzz_to.Reset();
}

void CSeq_interval_Base::SetFuzz_to(CSeq_interval_Base::TFuzz_to& value)
{
    m_Fuzz_to.Reset(&value);
}

CSeq_interval_Base::TFuzz_to& CSeq_interval_Base::SetFuzz_to(void)
{
    if ( !m_Fuzz_to )
        m_Fuzz_to.Reset(new ncbi::objects::CInt_fuzz());
    return (*m_Fuzz_to);
}

void CSeq_interval_Base::Reset(void)
{
    ResetFrom();
    ResetTo();
    ResetStrand();
    ResetId();
    ResetFuzz_from();
    ResetFuzz_to();
}

BEGIN_NAMED_BASE_CLASS_INFO("Seq-interval", CSeq_interval)
{
    SET_CLASS_MODULE("NCBI-Seqloc");
    ADD_NAMED_STD_MEMBER("from", m_From)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("to", m_To)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("strand", m_Strand, ENa_strand)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("id", m_Id, CSeq_id);
    ADD_NAMED_REF_MEMBER("fuzz-from", m_Fuzz_from, CInt_fuzz)->SetOptional();
    ADD_NAMED_REF_MEMBER("fuzz-to", m_Fuzz_to, CInt_fuzz)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CSeq_interval_Base::CSeq_interval_Base(void)
    : m_From(0), m_To(0), m_Strand((ncbi::objects::ENa_strand)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetId();
    }
}

// destructor
CSeq_interval_Base::~CSeq_interval_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
