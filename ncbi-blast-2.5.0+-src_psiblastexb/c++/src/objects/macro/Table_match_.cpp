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
 *   'macro.asn'.
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
#include <objects/macro/Table_match.hpp>
#include <objects/macro/Table_match_type.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CTable_match_Base::ResetMatch_type(void)
{
    if ( !m_Match_type ) {
        m_Match_type.Reset(new TMatch_type());
        return;
    }
    (*m_Match_type).Reset();
}

void CTable_match_Base::SetMatch_type(CTable_match_Base::TMatch_type& value)
{
    m_Match_type.Reset(&value);
}

void CTable_match_Base::Reset(void)
{
    ResetMatch_type();
    ResetMatch_location();
}

BEGIN_NAMED_BASE_CLASS_INFO("Table-match", CTable_match)
{
    SET_CLASS_MODULE("NCBI-Macro");
    ADD_NAMED_REF_MEMBER("match-type", m_Match_type, CTable_match_type);
    ADD_NAMED_ENUM_MEMBER("match-location", m_Match_location, EString_location)->SetDefault(new TMatch_location(eString_location_equals))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CTable_match_Base::CTable_match_Base(void)
    : m_Match_location(eString_location_equals)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetMatch_type();
    }
}

// destructor
CTable_match_Base::~CTable_match_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
