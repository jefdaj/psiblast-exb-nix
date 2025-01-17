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
 *   'blastxml.asn'.
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
#include <objects/blastxml/BlastOutput.hpp>
#include <objects/blastxml/Iteration.hpp>
#include <objects/blastxml/Parameters.hpp>
#include <objects/blastxml/Statistics.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBlastOutput_Base::ResetProgram(void)
{
    m_Program.erase();
    m_set_State[0] &= ~0x3;
}

void CBlastOutput_Base::ResetVersion(void)
{
    m_Version.erase();
    m_set_State[0] &= ~0xc;
}

void CBlastOutput_Base::ResetReference(void)
{
    m_Reference.erase();
    m_set_State[0] &= ~0x30;
}

void CBlastOutput_Base::ResetDb(void)
{
    m_Db.erase();
    m_set_State[0] &= ~0xc0;
}

void CBlastOutput_Base::ResetQuery_ID(void)
{
    m_Query_ID.erase();
    m_set_State[0] &= ~0x300;
}

void CBlastOutput_Base::ResetQuery_def(void)
{
    m_Query_def.erase();
    m_set_State[0] &= ~0xc00;
}

void CBlastOutput_Base::ResetQuery_seq(void)
{
    m_Query_seq.erase();
    m_set_State[0] &= ~0xc000;
}

void CBlastOutput_Base::ResetParam(void)
{
    if ( !m_Param ) {
        m_Param.Reset(new TParam());
        return;
    }
    (*m_Param).Reset();
}

void CBlastOutput_Base::SetParam(CBlastOutput_Base::TParam& value)
{
    m_Param.Reset(&value);
}

void CBlastOutput_Base::ResetIterations(void)
{
    m_Iterations.clear();
    m_set_State[0] &= ~0xc0000;
}

void CBlastOutput_Base::ResetMbstat(void)
{
    m_Mbstat.Reset();
}

void CBlastOutput_Base::SetMbstat(CBlastOutput_Base::TMbstat& value)
{
    m_Mbstat.Reset(&value);
}

CBlastOutput_Base::TMbstat& CBlastOutput_Base::SetMbstat(void)
{
    if ( !m_Mbstat )
        m_Mbstat.Reset(new ncbi::objects::CStatistics());
    return (*m_Mbstat);
}

void CBlastOutput_Base::Reset(void)
{
    ResetProgram();
    ResetVersion();
    ResetReference();
    ResetDb();
    ResetQuery_ID();
    ResetQuery_def();
    ResetQuery_len();
    ResetQuery_seq();
    ResetParam();
    ResetIterations();
    ResetMbstat();
}

BEGIN_NAMED_BASE_CLASS_INFO("BlastOutput", CBlastOutput)
{
    SET_CLASS_MODULE("NCBI-BlastOutput");
    ADD_NAMED_STD_MEMBER("program", m_Program)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("version", m_Version)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("reference", m_Reference)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("db", m_Db)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("query-ID", m_Query_ID)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("query-def", m_Query_def)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("query-len", m_Query_len)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("query-seq", m_Query_seq)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("param", m_Param, CParameters);
    ADD_NAMED_MEMBER("iterations", m_Iterations, STL_list, (STL_CRef, (CLASS, (CIteration))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("mbstat", m_Mbstat, CStatistics)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CBlastOutput_Base::CBlastOutput_Base(void)
    : m_Query_len(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetParam();
    }
}

// destructor
CBlastOutput_Base::~CBlastOutput_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

