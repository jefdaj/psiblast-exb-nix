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
 *   'mla.asn'.
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
#include <objects/mla/Mla_request.hpp>
#include <objects/medline/Medline_si.hpp>
#include <objects/mla/Title_msg.hpp>
#include <objects/pub/Pub.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CMla_request_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CMla_request_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Pmidtouid:
        m_Pmidtouid.Destruct();
        break;
    case e_Getmlepmid:
        m_Getmlepmid.Destruct();
        break;
    case e_Getpubpmid:
        m_Getpubpmid.Destruct();
        break;
    case e_Getmlrpmid:
        m_Getmlrpmid.Destruct();
        break;
    case e_Gettitle:
    case e_Citmatch:
    case e_Getaccuids:
    case e_Citmatchpmid:
    case e_Getaccpmids:
    case e_Citlstpmids:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CMla_request_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Getmle:
        m_Getmle = 0;
        break;
    case e_Getpub:
        m_Getpub = 0;
        break;
    case e_Gettitle:
        (m_object = new(pool) ncbi::objects::CTitle_msg())->AddReference();
        break;
    case e_Citmatch:
        (m_object = new(pool) ncbi::objects::CPub())->AddReference();
        break;
    case e_Getmriuids:
        m_Getmriuids = 0;
        break;
    case e_Getaccuids:
        (m_object = new(pool) ncbi::objects::CMedline_si())->AddReference();
        break;
    case e_Uidtopmid:
        m_Uidtopmid = 0;
        break;
    case e_Pmidtouid:
        m_Pmidtouid.Construct();
        break;
    case e_Getmlepmid:
        m_Getmlepmid.Construct();
        break;
    case e_Getpubpmid:
        m_Getpubpmid.Construct();
        break;
    case e_Citmatchpmid:
        (m_object = new(pool) ncbi::objects::CPub())->AddReference();
        break;
    case e_Getmripmids:
        m_Getmripmids = 0;
        break;
    case e_Getaccpmids:
        (m_object = new(pool) ncbi::objects::CMedline_si())->AddReference();
        break;
    case e_Citlstpmids:
        (m_object = new(pool) ncbi::objects::CPub())->AddReference();
        break;
    case e_Getmleuid:
        m_Getmleuid = 0;
        break;
    case e_Getmlrpmid:
        m_Getmlrpmid.Construct();
        break;
    case e_Getmlruid:
        m_Getmlruid = 0;
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CMla_request_Base::sm_SelectionNames[] = {
    "not set",
    "init",
    "getmle",
    "getpub",
    "gettitle",
    "citmatch",
    "fini",
    "getmriuids",
    "getaccuids",
    "uidtopmid",
    "pmidtouid",
    "getmlepmid",
    "getpubpmid",
    "citmatchpmid",
    "getmripmids",
    "getaccpmids",
    "citlstpmids",
    "getmleuid",
    "getmlrpmid",
    "getmlruid"
};

NCBI_NS_STD::string CMla_request_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CMla_request_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CMla_request_Base::TGettitle& CMla_request_Base::GetGettitle(void) const
{
    CheckSelected(e_Gettitle);
    return *static_cast<const TGettitle*>(m_object);
}

CMla_request_Base::TGettitle& CMla_request_Base::SetGettitle(void)
{
    Select(e_Gettitle, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGettitle*>(m_object);
}

void CMla_request_Base::SetGettitle(CMla_request_Base::TGettitle& value)
{
    TGettitle* ptr = &value;
    if ( m_choice != e_Gettitle || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Gettitle;
    }
}

const CMla_request_Base::TCitmatch& CMla_request_Base::GetCitmatch(void) const
{
    CheckSelected(e_Citmatch);
    return *static_cast<const TCitmatch*>(m_object);
}

CMla_request_Base::TCitmatch& CMla_request_Base::SetCitmatch(void)
{
    Select(e_Citmatch, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TCitmatch*>(m_object);
}

void CMla_request_Base::SetCitmatch(CMla_request_Base::TCitmatch& value)
{
    TCitmatch* ptr = &value;
    if ( m_choice != e_Citmatch || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Citmatch;
    }
}

const CMla_request_Base::TGetaccuids& CMla_request_Base::GetGetaccuids(void) const
{
    CheckSelected(e_Getaccuids);
    return *static_cast<const TGetaccuids*>(m_object);
}

CMla_request_Base::TGetaccuids& CMla_request_Base::SetGetaccuids(void)
{
    Select(e_Getaccuids, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGetaccuids*>(m_object);
}

void CMla_request_Base::SetGetaccuids(CMla_request_Base::TGetaccuids& value)
{
    TGetaccuids* ptr = &value;
    if ( m_choice != e_Getaccuids || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Getaccuids;
    }
}

void CMla_request_Base::SetPmidtouid(const CMla_request_Base::TPmidtouid& value)
{
    Select(e_Pmidtouid, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Pmidtouid = value;
}

void CMla_request_Base::SetGetmlepmid(const CMla_request_Base::TGetmlepmid& value)
{
    Select(e_Getmlepmid, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Getmlepmid = value;
}

void CMla_request_Base::SetGetpubpmid(const CMla_request_Base::TGetpubpmid& value)
{
    Select(e_Getpubpmid, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Getpubpmid = value;
}

const CMla_request_Base::TCitmatchpmid& CMla_request_Base::GetCitmatchpmid(void) const
{
    CheckSelected(e_Citmatchpmid);
    return *static_cast<const TCitmatchpmid*>(m_object);
}

CMla_request_Base::TCitmatchpmid& CMla_request_Base::SetCitmatchpmid(void)
{
    Select(e_Citmatchpmid, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TCitmatchpmid*>(m_object);
}

void CMla_request_Base::SetCitmatchpmid(CMla_request_Base::TCitmatchpmid& value)
{
    TCitmatchpmid* ptr = &value;
    if ( m_choice != e_Citmatchpmid || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Citmatchpmid;
    }
}

const CMla_request_Base::TGetaccpmids& CMla_request_Base::GetGetaccpmids(void) const
{
    CheckSelected(e_Getaccpmids);
    return *static_cast<const TGetaccpmids*>(m_object);
}

CMla_request_Base::TGetaccpmids& CMla_request_Base::SetGetaccpmids(void)
{
    Select(e_Getaccpmids, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGetaccpmids*>(m_object);
}

void CMla_request_Base::SetGetaccpmids(CMla_request_Base::TGetaccpmids& value)
{
    TGetaccpmids* ptr = &value;
    if ( m_choice != e_Getaccpmids || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Getaccpmids;
    }
}

const CMla_request_Base::TCitlstpmids& CMla_request_Base::GetCitlstpmids(void) const
{
    CheckSelected(e_Citlstpmids);
    return *static_cast<const TCitlstpmids*>(m_object);
}

CMla_request_Base::TCitlstpmids& CMla_request_Base::SetCitlstpmids(void)
{
    Select(e_Citlstpmids, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TCitlstpmids*>(m_object);
}

void CMla_request_Base::SetCitlstpmids(CMla_request_Base::TCitlstpmids& value)
{
    TCitlstpmids* ptr = &value;
    if ( m_choice != e_Citlstpmids || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Citlstpmids;
    }
}

void CMla_request_Base::SetGetmlrpmid(const CMla_request_Base::TGetmlrpmid& value)
{
    Select(e_Getmlrpmid, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Getmlrpmid = value;
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Mla-request", CMla_request)
{
    SET_CHOICE_MODULE("NCBI-MedArchive");
    ADD_NAMED_NULL_CHOICE_VARIANT("init", null, ())->GetId().SetTag(0);
    ADD_NAMED_STD_CHOICE_VARIANT("getmle", m_Getmle)->GetId().SetTag(1);
    ADD_NAMED_STD_CHOICE_VARIANT("getpub", m_Getpub)->GetId().SetTag(2);
    ADD_NAMED_REF_CHOICE_VARIANT("gettitle", m_object, CTitle_msg)->GetId().SetTag(3);
    ADD_NAMED_REF_CHOICE_VARIANT("citmatch", m_object, CPub)->GetId().SetTag(4);
    ADD_NAMED_NULL_CHOICE_VARIANT("fini", null, ())->GetId().SetTag(5);
    ADD_NAMED_STD_CHOICE_VARIANT("getmriuids", m_Getmriuids)->GetId().SetTag(6);
    ADD_NAMED_REF_CHOICE_VARIANT("getaccuids", m_object, CMedline_si)->GetId().SetTag(7);
    ADD_NAMED_STD_CHOICE_VARIANT("uidtopmid", m_Uidtopmid)->GetId().SetTag(8);
    ADD_NAMED_BUF_CHOICE_VARIANT("pmidtouid", m_Pmidtouid, CLASS, (CPubMedId))->GetId().SetTag(9);
    ADD_NAMED_BUF_CHOICE_VARIANT("getmlepmid", m_Getmlepmid, CLASS, (CPubMedId))->GetId().SetTag(10);
    ADD_NAMED_BUF_CHOICE_VARIANT("getpubpmid", m_Getpubpmid, CLASS, (CPubMedId))->GetId().SetTag(11);
    ADD_NAMED_REF_CHOICE_VARIANT("citmatchpmid", m_object, CPub)->GetId().SetTag(12);
    ADD_NAMED_STD_CHOICE_VARIANT("getmripmids", m_Getmripmids)->GetId().SetTag(13);
    ADD_NAMED_REF_CHOICE_VARIANT("getaccpmids", m_object, CMedline_si)->GetId().SetTag(14);
    ADD_NAMED_REF_CHOICE_VARIANT("citlstpmids", m_object, CPub)->GetId().SetTag(15);
    ADD_NAMED_STD_CHOICE_VARIANT("getmleuid", m_Getmleuid)->GetId().SetTag(16);
    ADD_NAMED_BUF_CHOICE_VARIANT("getmlrpmid", m_Getmlrpmid, CLASS, (CPubMedId))->GetId().SetTag(17);
    ADD_NAMED_STD_CHOICE_VARIANT("getmlruid", m_Getmlruid)->GetId().SetTag(18);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CMla_request_Base::CMla_request_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CMla_request_Base::~CMla_request_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

