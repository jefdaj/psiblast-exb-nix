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
 *   'seqedit.asn'.
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
#include <objects/seqedit/SeqEdit_Cmd_ChangeSetAttr.hpp>
#include <objects/general/Date.hpp>
#include <objects/general/Dbtag.hpp>
#include <objects/general/Object_id.hpp>
#include <objects/seqedit/SeqEdit_Id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Release:
        m_string.Destruct();
        break;
    case e_Id:
    case e_Coll:
    case e_Date:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Id:
        (m_object = new(pool) ncbi::objects::CObject_id())->AddReference();
        break;
    case e_Coll:
        (m_object = new(pool) ncbi::objects::CDbtag())->AddReference();
        break;
    case e_Level:
        m_Level = 0;
        break;
    case e_Class:
        m_Class = 0;
        break;
    case e_Date:
        (m_object = new(pool) ncbi::objects::CDate())->AddReference();
        break;
    case e_Release:
        m_string.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::sm_SelectionNames[] = {
    "not set",
    "id",
    "coll",
    "level",
    "class",
    "release",
    "date"
};

NCBI_NS_STD::string CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::TId& CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::GetId(void) const
{
    CheckSelected(e_Id);
    return *static_cast<const TId*>(m_object);
}

CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::TId& CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::SetId(void)
{
    Select(e_Id, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TId*>(m_object);
}

void CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::SetId(CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::TId& value)
{
    TId* ptr = &value;
    if ( m_choice != e_Id || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Id;
    }
}

const CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::TColl& CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::GetColl(void) const
{
    CheckSelected(e_Coll);
    return *static_cast<const TColl*>(m_object);
}

CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::TColl& CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::SetColl(void)
{
    Select(e_Coll, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TColl*>(m_object);
}

void CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::SetColl(CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::TColl& value)
{
    TColl* ptr = &value;
    if ( m_choice != e_Coll || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Coll;
    }
}

void CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::SetRelease(const CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::TRelease& value)
{
    Select(e_Release, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

const CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::TDate& CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::GetDate(void) const
{
    CheckSelected(e_Date);
    return *static_cast<const TDate*>(m_object);
}

CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::TDate& CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::SetDate(void)
{
    Select(e_Date, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TDate*>(m_object);
}

void CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::SetDate(CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::TDate& value)
{
    TDate* ptr = &value;
    if ( m_choice != e_Date || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Date;
    }
}

// helper methods

// type info
BEGIN_NAMED_CHOICE_INFO("", CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data)
{
    SET_INTERNAL_NAME("SeqEdit-Cmd-ChangeSetAttr", "data");
    SET_CHOICE_MODULE("NCBI-SeqEdit");
    ADD_NAMED_REF_CHOICE_VARIANT("id", m_object, CObject_id);
    ADD_NAMED_REF_CHOICE_VARIANT("coll", m_object, CDbtag);
    ADD_NAMED_STD_CHOICE_VARIANT("level", m_Level);
    ADD_NAMED_STD_CHOICE_VARIANT("class", m_Class);
    ADD_NAMED_BUF_CHOICE_VARIANT("release", m_string, STD, (string));
    ADD_NAMED_REF_CHOICE_VARIANT("date", m_object, CDate);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::C_Data(void)
    : m_choice(e_not_set)
{
}

// destructor
CSeqEdit_Cmd_ChangeSetAttr_Base::C_Data::~C_Data(void)
{
    Reset();
}


void CSeqEdit_Cmd_ChangeSetAttr_Base::ResetId(void)
{
    if ( !m_Id ) {
        m_Id.Reset(new TId());
        return;
    }
    (*m_Id).Reset();
}

void CSeqEdit_Cmd_ChangeSetAttr_Base::SetId(CSeqEdit_Cmd_ChangeSetAttr_Base::TId& value)
{
    m_Id.Reset(&value);
}

void CSeqEdit_Cmd_ChangeSetAttr_Base::ResetData(void)
{
    if ( !m_Data ) {
        m_Data.Reset(new TData());
        return;
    }
    (*m_Data).Reset();
}

void CSeqEdit_Cmd_ChangeSetAttr_Base::SetData(CSeqEdit_Cmd_ChangeSetAttr_Base::TData& value)
{
    m_Data.Reset(&value);
}

void CSeqEdit_Cmd_ChangeSetAttr_Base::Reset(void)
{
    ResetId();
    ResetData();
}

BEGIN_NAMED_BASE_CLASS_INFO("SeqEdit-Cmd-ChangeSetAttr", CSeqEdit_Cmd_ChangeSetAttr)
{
    SET_CLASS_MODULE("NCBI-SeqEdit");
    ADD_NAMED_REF_MEMBER("id", m_Id, CSeqEdit_Id);
    ADD_NAMED_REF_MEMBER("data", m_Data, C_Data);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CSeqEdit_Cmd_ChangeSetAttr_Base::CSeqEdit_Cmd_ChangeSetAttr_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetId();
        ResetData();
    }
}

// destructor
CSeqEdit_Cmd_ChangeSetAttr_Base::~CSeqEdit_Cmd_ChangeSetAttr_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

