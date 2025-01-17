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
 *   'pcsubstance.asn'.
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
#include <objects/pcsubstance/PC_StereoCenter.hpp>
#include <objects/pcsubstance/PC_StereoOctahedral.hpp>
#include <objects/pcsubstance/PC_StereoPentagonalBiPyram.hpp>
#include <objects/pcsubstance/PC_StereoPlanar.hpp>
#include <objects/pcsubstance/PC_StereoSquarePlanar.hpp>
#include <objects/pcsubstance/PC_StereoTShape.hpp>
#include <objects/pcsubstance/PC_StereoTetrahedral.hpp>
#include <objects/pcsubstance/PC_StereoTrigonalBiPyramid.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPC_StereoCenter_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CPC_StereoCenter_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Tetrahedral:
    case e_Planar:
    case e_Squareplanar:
    case e_Octahedral:
    case e_Bipyramid:
    case e_Tshape:
    case e_Pentagonal:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CPC_StereoCenter_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Tetrahedral:
        (m_object = new(pool) ncbi::objects::CPC_StereoTetrahedral())->AddReference();
        break;
    case e_Planar:
        (m_object = new(pool) ncbi::objects::CPC_StereoPlanar())->AddReference();
        break;
    case e_Squareplanar:
        (m_object = new(pool) ncbi::objects::CPC_StereoSquarePlanar())->AddReference();
        break;
    case e_Octahedral:
        (m_object = new(pool) ncbi::objects::CPC_StereoOctahedral())->AddReference();
        break;
    case e_Bipyramid:
        (m_object = new(pool) ncbi::objects::CPC_StereoTrigonalBiPyramid())->AddReference();
        break;
    case e_Tshape:
        (m_object = new(pool) ncbi::objects::CPC_StereoTShape())->AddReference();
        break;
    case e_Pentagonal:
        (m_object = new(pool) ncbi::objects::CPC_StereoPentagonalBiPyramid())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CPC_StereoCenter_Base::sm_SelectionNames[] = {
    "not set",
    "tetrahedral",
    "planar",
    "squareplanar",
    "octahedral",
    "bipyramid",
    "tshape",
    "pentagonal"
};

NCBI_NS_STD::string CPC_StereoCenter_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CPC_StereoCenter_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CPC_StereoCenter_Base::TTetrahedral& CPC_StereoCenter_Base::GetTetrahedral(void) const
{
    CheckSelected(e_Tetrahedral);
    return *static_cast<const TTetrahedral*>(m_object);
}

CPC_StereoCenter_Base::TTetrahedral& CPC_StereoCenter_Base::SetTetrahedral(void)
{
    Select(e_Tetrahedral, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TTetrahedral*>(m_object);
}

void CPC_StereoCenter_Base::SetTetrahedral(CPC_StereoCenter_Base::TTetrahedral& value)
{
    TTetrahedral* ptr = &value;
    if ( m_choice != e_Tetrahedral || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Tetrahedral;
    }
}

const CPC_StereoCenter_Base::TPlanar& CPC_StereoCenter_Base::GetPlanar(void) const
{
    CheckSelected(e_Planar);
    return *static_cast<const TPlanar*>(m_object);
}

CPC_StereoCenter_Base::TPlanar& CPC_StereoCenter_Base::SetPlanar(void)
{
    Select(e_Planar, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TPlanar*>(m_object);
}

void CPC_StereoCenter_Base::SetPlanar(CPC_StereoCenter_Base::TPlanar& value)
{
    TPlanar* ptr = &value;
    if ( m_choice != e_Planar || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Planar;
    }
}

const CPC_StereoCenter_Base::TSquareplanar& CPC_StereoCenter_Base::GetSquareplanar(void) const
{
    CheckSelected(e_Squareplanar);
    return *static_cast<const TSquareplanar*>(m_object);
}

CPC_StereoCenter_Base::TSquareplanar& CPC_StereoCenter_Base::SetSquareplanar(void)
{
    Select(e_Squareplanar, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TSquareplanar*>(m_object);
}

void CPC_StereoCenter_Base::SetSquareplanar(CPC_StereoCenter_Base::TSquareplanar& value)
{
    TSquareplanar* ptr = &value;
    if ( m_choice != e_Squareplanar || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Squareplanar;
    }
}

const CPC_StereoCenter_Base::TOctahedral& CPC_StereoCenter_Base::GetOctahedral(void) const
{
    CheckSelected(e_Octahedral);
    return *static_cast<const TOctahedral*>(m_object);
}

CPC_StereoCenter_Base::TOctahedral& CPC_StereoCenter_Base::SetOctahedral(void)
{
    Select(e_Octahedral, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TOctahedral*>(m_object);
}

void CPC_StereoCenter_Base::SetOctahedral(CPC_StereoCenter_Base::TOctahedral& value)
{
    TOctahedral* ptr = &value;
    if ( m_choice != e_Octahedral || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Octahedral;
    }
}

const CPC_StereoCenter_Base::TBipyramid& CPC_StereoCenter_Base::GetBipyramid(void) const
{
    CheckSelected(e_Bipyramid);
    return *static_cast<const TBipyramid*>(m_object);
}

CPC_StereoCenter_Base::TBipyramid& CPC_StereoCenter_Base::SetBipyramid(void)
{
    Select(e_Bipyramid, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TBipyramid*>(m_object);
}

void CPC_StereoCenter_Base::SetBipyramid(CPC_StereoCenter_Base::TBipyramid& value)
{
    TBipyramid* ptr = &value;
    if ( m_choice != e_Bipyramid || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Bipyramid;
    }
}

const CPC_StereoCenter_Base::TTshape& CPC_StereoCenter_Base::GetTshape(void) const
{
    CheckSelected(e_Tshape);
    return *static_cast<const TTshape*>(m_object);
}

CPC_StereoCenter_Base::TTshape& CPC_StereoCenter_Base::SetTshape(void)
{
    Select(e_Tshape, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TTshape*>(m_object);
}

void CPC_StereoCenter_Base::SetTshape(CPC_StereoCenter_Base::TTshape& value)
{
    TTshape* ptr = &value;
    if ( m_choice != e_Tshape || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Tshape;
    }
}

const CPC_StereoCenter_Base::TPentagonal& CPC_StereoCenter_Base::GetPentagonal(void) const
{
    CheckSelected(e_Pentagonal);
    return *static_cast<const TPentagonal*>(m_object);
}

CPC_StereoCenter_Base::TPentagonal& CPC_StereoCenter_Base::SetPentagonal(void)
{
    Select(e_Pentagonal, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TPentagonal*>(m_object);
}

void CPC_StereoCenter_Base::SetPentagonal(CPC_StereoCenter_Base::TPentagonal& value)
{
    TPentagonal* ptr = &value;
    if ( m_choice != e_Pentagonal || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Pentagonal;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("PC-StereoCenter", CPC_StereoCenter)
{
    SET_CHOICE_MODULE("NCBI-PCSubstance");
    ADD_NAMED_REF_CHOICE_VARIANT("tetrahedral", m_object, CPC_StereoTetrahedral);
    ADD_NAMED_REF_CHOICE_VARIANT("planar", m_object, CPC_StereoPlanar);
    ADD_NAMED_REF_CHOICE_VARIANT("squareplanar", m_object, CPC_StereoSquarePlanar);
    ADD_NAMED_REF_CHOICE_VARIANT("octahedral", m_object, CPC_StereoOctahedral);
    ADD_NAMED_REF_CHOICE_VARIANT("bipyramid", m_object, CPC_StereoTrigonalBiPyramid);
    ADD_NAMED_REF_CHOICE_VARIANT("tshape", m_object, CPC_StereoTShape);
    ADD_NAMED_REF_CHOICE_VARIANT("pentagonal", m_object, CPC_StereoPentagonalBiPyramid);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CPC_StereoCenter_Base::CPC_StereoCenter_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CPC_StereoCenter_Base::~CPC_StereoCenter_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

