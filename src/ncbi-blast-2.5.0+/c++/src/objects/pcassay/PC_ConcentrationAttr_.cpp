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
 *   'pcassay.asn'.
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
#include <objects/pcassay/PC_ConcentrationAttr.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CPC_ConcentrationAttr_Base::, EUnit, true)
{
    SET_ENUM_INTERNAL_NAME("PC-ConcentrationAttr", "unit");
    SET_ENUM_MODULE("NCBI-PCAssay");
    ADD_ENUM_VALUE("um", eUnit_um);
}
END_ENUM_INFO

void CPC_ConcentrationAttr_Base::Reset(void)
{
    ResetConcentration();
    ResetUnit();
    ResetDr_id();
}

BEGIN_NAMED_BASE_CLASS_INFO("PC-ConcentrationAttr", CPC_ConcentrationAttr)
{
    SET_CLASS_MODULE("NCBI-PCAssay");
    ADD_NAMED_STD_MEMBER("concentration", m_Concentration)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("unit", m_Unit, EUnit)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("dr-id", m_Dr_id)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CPC_ConcentrationAttr_Base::CPC_ConcentrationAttr_Base(void)
    : m_Concentration(0), m_Unit((EUnit)(0)), m_Dr_id(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CPC_ConcentrationAttr_Base::~CPC_ConcentrationAttr_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

