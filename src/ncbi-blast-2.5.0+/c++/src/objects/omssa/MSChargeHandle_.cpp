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
 *   'omssa.asn'.
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
#include <objects/omssa/MSChargeHandle.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CMSChargeHandle_Base::Reset(void)
{
    ResetCalcplusone();
    ResetCalccharge();
    ResetMincharge();
    ResetMaxcharge();
    ResetConsidermult();
    ResetPlusone();
    ResetMaxproductcharge();
    ResetProdlesspre();
    ResetNegative();
}

BEGIN_NAMED_BASE_CLASS_INFO("MSChargeHandle", CMSChargeHandle)
{
    SET_CLASS_MODULE("OMSSA");
    ADD_NAMED_ENUM_MEMBER("calcplusone", m_Calcplusone, EMSCalcPlusOne)->SetDefault(new TCalcplusone(1))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("calccharge", m_Calccharge, EMSCalcCharge)->SetDefault(new TCalccharge(2))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("mincharge", m_Mincharge)->SetDefault(new TMincharge(2))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("maxcharge", m_Maxcharge)->SetDefault(new TMaxcharge(3))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("considermult", m_Considermult)->SetDefault(new TConsidermult(3))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("plusone", m_Plusone)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("maxproductcharge", m_Maxproductcharge)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("prodlesspre", m_Prodlesspre)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("negative", m_Negative)->SetDefault(new TNegative(1))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CMSChargeHandle_Base::CMSChargeHandle_Base(void)
    : m_Calcplusone(1), m_Calccharge(2), m_Mincharge(2), m_Maxcharge(3), m_Considermult(3), m_Plusone(0), m_Maxproductcharge(0), m_Prodlesspre(0), m_Negative(1)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CMSChargeHandle_Base::~CMSChargeHandle_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

