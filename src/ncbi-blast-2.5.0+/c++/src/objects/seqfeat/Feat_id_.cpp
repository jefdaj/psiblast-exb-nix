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
 *   'seqfeat.asn'.
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
#include <objects/seqfeat/Feat_id.hpp>
#include <objects/general/Dbtag.hpp>
#include <objects/general/Object_id.hpp>
#include <objects/seqloc/Giimport_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CFeat_id_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CFeat_id_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Giim:
    case e_Local:
    case e_General:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CFeat_id_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Gibb:
        m_Gibb = 0;
        break;
    case e_Giim:
        (m_object = new(pool) ncbi::objects::CGiimport_id())->AddReference();
        break;
    case e_Local:
        (m_object = new(pool) ncbi::objects::CObject_id())->AddReference();
        break;
    case e_General:
        (m_object = new(pool) ncbi::objects::CDbtag())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CFeat_id_Base::sm_SelectionNames[] = {
    "not set",
    "gibb",
    "giim",
    "local",
    "general"
};

NCBI_NS_STD::string CFeat_id_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CFeat_id_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CFeat_id_Base::TGiim& CFeat_id_Base::GetGiim(void) const
{
    CheckSelected(e_Giim);
    return *static_cast<const TGiim*>(m_object);
}

CFeat_id_Base::TGiim& CFeat_id_Base::SetGiim(void)
{
    Select(e_Giim, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGiim*>(m_object);
}

void CFeat_id_Base::SetGiim(CFeat_id_Base::TGiim& value)
{
    TGiim* ptr = &value;
    if ( m_choice != e_Giim || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Giim;
    }
}

const CFeat_id_Base::TLocal& CFeat_id_Base::GetLocal(void) const
{
    CheckSelected(e_Local);
    return *static_cast<const TLocal*>(m_object);
}

CFeat_id_Base::TLocal& CFeat_id_Base::SetLocal(void)
{
    Select(e_Local, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TLocal*>(m_object);
}

void CFeat_id_Base::SetLocal(CFeat_id_Base::TLocal& value)
{
    TLocal* ptr = &value;
    if ( m_choice != e_Local || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Local;
    }
}

const CFeat_id_Base::TGeneral& CFeat_id_Base::GetGeneral(void) const
{
    CheckSelected(e_General);
    return *static_cast<const TGeneral*>(m_object);
}

CFeat_id_Base::TGeneral& CFeat_id_Base::SetGeneral(void)
{
    Select(e_General, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGeneral*>(m_object);
}

void CFeat_id_Base::SetGeneral(CFeat_id_Base::TGeneral& value)
{
    TGeneral* ptr = &value;
    if ( m_choice != e_General || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_General;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Feat-id", CFeat_id)
{
    SET_CHOICE_MODULE("NCBI-Seqfeat");
    ADD_NAMED_STD_CHOICE_VARIANT("gibb", m_Gibb);
    ADD_NAMED_REF_CHOICE_VARIANT("giim", m_object, CGiimport_id);
    ADD_NAMED_REF_CHOICE_VARIANT("local", m_object, CObject_id);
    ADD_NAMED_REF_CHOICE_VARIANT("general", m_object, CDbtag);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CFeat_id_Base::CFeat_id_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CFeat_id_Base::~CFeat_id_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

