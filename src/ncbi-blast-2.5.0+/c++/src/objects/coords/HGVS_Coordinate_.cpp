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
 *   'objcoords.asn'.
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
#include <objects/coords/HGVS_Coordinate.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CHGVS_Coordinate_Base::ResetTitle(void)
{
    m_Title.erase();
    m_set_State[0] &= ~0xc;
}

void CHGVS_Coordinate_Base::ResetObject_id(void)
{
    m_Object_id.erase();
    m_set_State[0] &= ~0x30;
}

void CHGVS_Coordinate_Base::ResetHgvs_position(void)
{
    m_Hgvs_position.erase();
    m_set_State[0] &= ~0x300;
}

void CHGVS_Coordinate_Base::ResetSequence(void)
{
    m_Sequence.erase();
    m_set_State[0] &= ~0xc00;
}

void CHGVS_Coordinate_Base::Reset(void)
{
    ResetMarker_pos();
    ResetTitle();
    ResetObject_id();
    ResetPos_mapped();
    ResetHgvs_position();
    ResetSequence();
}

BEGIN_NAMED_BASE_CLASS_INFO("HGVS-Coordinate", CHGVS_Coordinate)
{
    SET_CLASS_MODULE("NCBI-HGVSCoordinate");
    ADD_NAMED_STD_MEMBER("marker-pos", m_Marker_pos)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("title", m_Title)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("object-id", m_Object_id)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("pos-mapped", m_Pos_mapped)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("hgvs-position", m_Hgvs_position)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("sequence", m_Sequence)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CHGVS_Coordinate_Base::CHGVS_Coordinate_Base(void)
    : m_Marker_pos(0), m_Pos_mapped(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CHGVS_Coordinate_Base::~CHGVS_Coordinate_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

