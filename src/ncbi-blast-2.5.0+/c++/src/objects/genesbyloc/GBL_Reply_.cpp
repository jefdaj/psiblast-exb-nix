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
 *   'genesbyloc.asn'.
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
#include <objects/genesbyloc/GBL_Reply.hpp>
#include <objects/genesbyloc/GBL_Data.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CGBL_Reply_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CGBL_Reply_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Error:
        m_string.Destruct();
        break;
    case e_Data:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CGBL_Reply_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Data:
        (m_object = new(pool) ncbi::objects::CGBL_Data())->AddReference();
        break;
    case e_Error:
        m_string.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CGBL_Reply_Base::sm_SelectionNames[] = {
    "not set",
    "data",
    "error"
};

NCBI_NS_STD::string CGBL_Reply_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CGBL_Reply_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CGBL_Reply_Base::TData& CGBL_Reply_Base::GetData(void) const
{
    CheckSelected(e_Data);
    return *static_cast<const TData*>(m_object);
}

CGBL_Reply_Base::TData& CGBL_Reply_Base::SetData(void)
{
    Select(e_Data, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TData*>(m_object);
}

void CGBL_Reply_Base::SetData(CGBL_Reply_Base::TData& value)
{
    TData* ptr = &value;
    if ( m_choice != e_Data || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Data;
    }
}

void CGBL_Reply_Base::SetError(const CGBL_Reply_Base::TError& value)
{
    Select(e_Error, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("GBL-Reply", CGBL_Reply)
{
    SET_CHOICE_MODULE("NCBI-GenesByLoc");
    ADD_NAMED_REF_CHOICE_VARIANT("data", m_object, CGBL_Data);
    ADD_NAMED_BUF_CHOICE_VARIANT("error", m_string, STD, (string));
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CGBL_Reply_Base::CGBL_Reply_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CGBL_Reply_Base::~CGBL_Reply_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

