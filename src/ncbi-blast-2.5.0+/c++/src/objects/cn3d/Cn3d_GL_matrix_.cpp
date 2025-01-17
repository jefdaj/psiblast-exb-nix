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
 *   'cn3d.asn'.
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
#include <objects/cn3d/Cn3d_GL_matrix.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CCn3d_GL_matrix_Base::Reset(void)
{
    ResetM0();
    ResetM1();
    ResetM2();
    ResetM3();
    ResetM4();
    ResetM5();
    ResetM6();
    ResetM7();
    ResetM8();
    ResetM9();
    ResetM10();
    ResetM11();
    ResetM12();
    ResetM13();
    ResetM14();
    ResetM15();
}

BEGIN_NAMED_BASE_CLASS_INFO("Cn3d-GL-matrix", CCn3d_GL_matrix)
{
    SET_CLASS_MODULE("NCBI-Cn3d");
    ADD_NAMED_STD_MEMBER("m0", m_M0)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m1", m_M1)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m2", m_M2)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m3", m_M3)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m4", m_M4)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m5", m_M5)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m6", m_M6)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m7", m_M7)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m8", m_M8)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m9", m_M9)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m10", m_M10)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m11", m_M11)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m12", m_M12)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m13", m_M13)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m14", m_M14)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("m15", m_M15)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CCn3d_GL_matrix_Base::CCn3d_GL_matrix_Base(void)
    : m_M0(0), m_M1(0), m_M2(0), m_M3(0), m_M4(0), m_M5(0), m_M6(0), m_M7(0), m_M8(0), m_M9(0), m_M10(0), m_M11(0), m_M12(0), m_M13(0), m_M14(0), m_M15(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CCn3d_GL_matrix_Base::~CCn3d_GL_matrix_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

