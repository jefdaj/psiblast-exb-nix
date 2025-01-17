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
 *   'homologene.asn'.
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
#include <objects/homologene/HG_Node_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CHG_Node_id_Base::, EId_type, false)
{
    SET_ENUM_INTERNAL_NAME("HG-Node-id", "id-type");
    SET_ENUM_MODULE("HomoloGene");
    ADD_ENUM_VALUE("none", eId_type_none);
    ADD_ENUM_VALUE("geneid", eId_type_geneid);
    ADD_ENUM_VALUE("hid", eId_type_hid);
}
END_ENUM_INFO

void CHG_Node_id_Base::Reset(void)
{
    ResetId();
    ResetId_type();
}

BEGIN_NAMED_BASE_CLASS_INFO("HG-Node-id", CHG_Node_id)
{
    SET_CLASS_MODULE("HomoloGene");
    ADD_NAMED_STD_MEMBER("id", m_Id)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("id-type", m_Id_type, EId_type)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CHG_Node_id_Base::CHG_Node_id_Base(void)
    : m_Id(0), m_Id_type((EId_type)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CHG_Node_id_Base::~CHG_Node_id_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

