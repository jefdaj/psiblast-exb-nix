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
 *   'id1.asn'.
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
#include <objects/id1/ID1server_back.hpp>
#include <objects/id1/ID1SeqEntry_info.hpp>
#include <objects/id1/ID1Seq_hist.hpp>
#include <objects/id1/ID1blob_info.hpp>
#include <objects/seqloc/Seq_id.hpp>
#include <objects/seqset/Seq_entry.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CID1server_back_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CID1server_back_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Ids:
        m_Ids.Destruct();
        break;
    case e_Gihist:
        m_Gihist.Destruct();
        break;
    case e_Girevhist:
        m_Girevhist.Destruct();
        break;
    case e_Gotseqentry:
    case e_Gotdeadseqentry:
    case e_Gotsewithinfo:
    case e_Gotblobinfo:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CID1server_back_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Error:
        m_Error = 0;
        break;
    case e_Gotgi:
        m_Gotgi = 0;
        break;
    case e_Gotseqentry:
        (m_object = new(pool) ncbi::objects::CSeq_entry())->AddReference();
        break;
    case e_Gotdeadseqentry:
        (m_object = new(pool) ncbi::objects::CSeq_entry())->AddReference();
        break;
    case e_Gistate:
        m_Gistate = 0;
        break;
    case e_Ids:
        m_Ids.Construct();
        break;
    case e_Gihist:
        m_Gihist.Construct();
        break;
    case e_Girevhist:
        m_Girevhist.Construct();
        break;
    case e_Gotsewithinfo:
        (m_object = new(pool) ncbi::objects::CID1SeqEntry_info())->AddReference();
        break;
    case e_Gotblobinfo:
        (m_object = new(pool) ncbi::objects::CID1blob_info())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CID1server_back_Base::sm_SelectionNames[] = {
    "not set",
    "init",
    "error",
    "gotgi",
    "gotseqentry",
    "gotdeadseqentry",
    "fini",
    "gistate",
    "ids",
    "gihist",
    "girevhist",
    "gotsewithinfo",
    "gotblobinfo"
};

NCBI_NS_STD::string CID1server_back_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CID1server_back_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CID1server_back_Base::TGotseqentry& CID1server_back_Base::GetGotseqentry(void) const
{
    CheckSelected(e_Gotseqentry);
    return *static_cast<const TGotseqentry*>(m_object);
}

CID1server_back_Base::TGotseqentry& CID1server_back_Base::SetGotseqentry(void)
{
    Select(e_Gotseqentry, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGotseqentry*>(m_object);
}

void CID1server_back_Base::SetGotseqentry(CID1server_back_Base::TGotseqentry& value)
{
    TGotseqentry* ptr = &value;
    if ( m_choice != e_Gotseqentry || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Gotseqentry;
    }
}

const CID1server_back_Base::TGotdeadseqentry& CID1server_back_Base::GetGotdeadseqentry(void) const
{
    CheckSelected(e_Gotdeadseqentry);
    return *static_cast<const TGotdeadseqentry*>(m_object);
}

CID1server_back_Base::TGotdeadseqentry& CID1server_back_Base::SetGotdeadseqentry(void)
{
    Select(e_Gotdeadseqentry, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGotdeadseqentry*>(m_object);
}

void CID1server_back_Base::SetGotdeadseqentry(CID1server_back_Base::TGotdeadseqentry& value)
{
    TGotdeadseqentry* ptr = &value;
    if ( m_choice != e_Gotdeadseqentry || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Gotdeadseqentry;
    }
}

const CID1server_back_Base::TGotsewithinfo& CID1server_back_Base::GetGotsewithinfo(void) const
{
    CheckSelected(e_Gotsewithinfo);
    return *static_cast<const TGotsewithinfo*>(m_object);
}

CID1server_back_Base::TGotsewithinfo& CID1server_back_Base::SetGotsewithinfo(void)
{
    Select(e_Gotsewithinfo, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGotsewithinfo*>(m_object);
}

void CID1server_back_Base::SetGotsewithinfo(CID1server_back_Base::TGotsewithinfo& value)
{
    TGotsewithinfo* ptr = &value;
    if ( m_choice != e_Gotsewithinfo || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Gotsewithinfo;
    }
}

const CID1server_back_Base::TGotblobinfo& CID1server_back_Base::GetGotblobinfo(void) const
{
    CheckSelected(e_Gotblobinfo);
    return *static_cast<const TGotblobinfo*>(m_object);
}

CID1server_back_Base::TGotblobinfo& CID1server_back_Base::SetGotblobinfo(void)
{
    Select(e_Gotblobinfo, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGotblobinfo*>(m_object);
}

void CID1server_back_Base::SetGotblobinfo(CID1server_back_Base::TGotblobinfo& value)
{
    TGotblobinfo* ptr = &value;
    if ( m_choice != e_Gotblobinfo || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Gotblobinfo;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("ID1server-back", CID1server_back)
{
    SET_CHOICE_MODULE("NCBI-ID1Access");
    ADD_NAMED_NULL_CHOICE_VARIANT("init", null, ());
    ADD_NAMED_STD_CHOICE_VARIANT("error", m_Error);
    ADD_NAMED_STD_CHOICE_VARIANT("gotgi", m_Gotgi);
    ADD_NAMED_REF_CHOICE_VARIANT("gotseqentry", m_object, CSeq_entry);
    ADD_NAMED_REF_CHOICE_VARIANT("gotdeadseqentry", m_object, CSeq_entry);
    ADD_NAMED_NULL_CHOICE_VARIANT("fini", null, ());
    ADD_NAMED_STD_CHOICE_VARIANT("gistate", m_Gistate);
    ADD_NAMED_BUF_CHOICE_VARIANT("ids", m_Ids, STL_list_set, (STL_CRef, (CLASS, (CSeq_id))));
    ADD_NAMED_BUF_CHOICE_VARIANT("gihist", m_Gihist, STL_list_set, (STL_CRef, (CLASS, (CID1Seq_hist))));
    ADD_NAMED_BUF_CHOICE_VARIANT("girevhist", m_Girevhist, STL_list_set, (STL_CRef, (CLASS, (CID1Seq_hist))));
    ADD_NAMED_REF_CHOICE_VARIANT("gotsewithinfo", m_object, CID1SeqEntry_info);
    ADD_NAMED_REF_CHOICE_VARIANT("gotblobinfo", m_object, CID1blob_info);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CID1server_back_Base::CID1server_back_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CID1server_back_Base::~CID1server_back_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

