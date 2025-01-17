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
 *   'pub.asn'.
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
#include <objects/pub/Pub.hpp>
#include <objects/biblio/Cit_art.hpp>
#include <objects/biblio/Cit_book.hpp>
#include <objects/biblio/Cit_gen.hpp>
#include <objects/biblio/Cit_jour.hpp>
#include <objects/biblio/Cit_let.hpp>
#include <objects/biblio/Cit_pat.hpp>
#include <objects/biblio/Cit_proc.hpp>
#include <objects/biblio/Cit_sub.hpp>
#include <objects/biblio/Id_pat.hpp>
#include <objects/medline/Medline_entry.hpp>
#include <objects/pub/Pub_equiv.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPub_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CPub_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Pmid:
        m_Pmid.Destruct();
        break;
    case e_Gen:
    case e_Sub:
    case e_Medline:
    case e_Article:
    case e_Journal:
    case e_Book:
    case e_Proc:
    case e_Patent:
    case e_Pat_id:
    case e_Man:
    case e_Equiv:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CPub_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Gen:
        (m_object = new(pool) ncbi::objects::CCit_gen())->AddReference();
        break;
    case e_Sub:
        (m_object = new(pool) ncbi::objects::CCit_sub())->AddReference();
        break;
    case e_Medline:
        (m_object = new(pool) ncbi::objects::CMedline_entry())->AddReference();
        break;
    case e_Muid:
        m_Muid = 0;
        break;
    case e_Article:
        (m_object = new(pool) ncbi::objects::CCit_art())->AddReference();
        break;
    case e_Journal:
        (m_object = new(pool) ncbi::objects::CCit_jour())->AddReference();
        break;
    case e_Book:
        (m_object = new(pool) ncbi::objects::CCit_book())->AddReference();
        break;
    case e_Proc:
        (m_object = new(pool) ncbi::objects::CCit_proc())->AddReference();
        break;
    case e_Patent:
        (m_object = new(pool) ncbi::objects::CCit_pat())->AddReference();
        break;
    case e_Pat_id:
        (m_object = new(pool) ncbi::objects::CId_pat())->AddReference();
        break;
    case e_Man:
        (m_object = new(pool) ncbi::objects::CCit_let())->AddReference();
        break;
    case e_Equiv:
        (m_object = new(pool) ncbi::objects::CPub_equiv())->AddReference();
        break;
    case e_Pmid:
        m_Pmid.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CPub_Base::sm_SelectionNames[] = {
    "not set",
    "gen",
    "sub",
    "medline",
    "muid",
    "article",
    "journal",
    "book",
    "proc",
    "patent",
    "pat-id",
    "man",
    "equiv",
    "pmid"
};

NCBI_NS_STD::string CPub_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CPub_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CPub_Base::TGen& CPub_Base::GetGen(void) const
{
    CheckSelected(e_Gen);
    return *static_cast<const TGen*>(m_object);
}

CPub_Base::TGen& CPub_Base::SetGen(void)
{
    Select(e_Gen, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGen*>(m_object);
}

void CPub_Base::SetGen(CPub_Base::TGen& value)
{
    TGen* ptr = &value;
    if ( m_choice != e_Gen || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Gen;
    }
}

const CPub_Base::TSub& CPub_Base::GetSub(void) const
{
    CheckSelected(e_Sub);
    return *static_cast<const TSub*>(m_object);
}

CPub_Base::TSub& CPub_Base::SetSub(void)
{
    Select(e_Sub, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TSub*>(m_object);
}

void CPub_Base::SetSub(CPub_Base::TSub& value)
{
    TSub* ptr = &value;
    if ( m_choice != e_Sub || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Sub;
    }
}

const CPub_Base::TMedline& CPub_Base::GetMedline(void) const
{
    CheckSelected(e_Medline);
    return *static_cast<const TMedline*>(m_object);
}

CPub_Base::TMedline& CPub_Base::SetMedline(void)
{
    Select(e_Medline, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TMedline*>(m_object);
}

void CPub_Base::SetMedline(CPub_Base::TMedline& value)
{
    TMedline* ptr = &value;
    if ( m_choice != e_Medline || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Medline;
    }
}

const CPub_Base::TArticle& CPub_Base::GetArticle(void) const
{
    CheckSelected(e_Article);
    return *static_cast<const TArticle*>(m_object);
}

CPub_Base::TArticle& CPub_Base::SetArticle(void)
{
    Select(e_Article, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TArticle*>(m_object);
}

void CPub_Base::SetArticle(CPub_Base::TArticle& value)
{
    TArticle* ptr = &value;
    if ( m_choice != e_Article || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Article;
    }
}

const CPub_Base::TJournal& CPub_Base::GetJournal(void) const
{
    CheckSelected(e_Journal);
    return *static_cast<const TJournal*>(m_object);
}

CPub_Base::TJournal& CPub_Base::SetJournal(void)
{
    Select(e_Journal, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TJournal*>(m_object);
}

void CPub_Base::SetJournal(CPub_Base::TJournal& value)
{
    TJournal* ptr = &value;
    if ( m_choice != e_Journal || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Journal;
    }
}

const CPub_Base::TBook& CPub_Base::GetBook(void) const
{
    CheckSelected(e_Book);
    return *static_cast<const TBook*>(m_object);
}

CPub_Base::TBook& CPub_Base::SetBook(void)
{
    Select(e_Book, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TBook*>(m_object);
}

void CPub_Base::SetBook(CPub_Base::TBook& value)
{
    TBook* ptr = &value;
    if ( m_choice != e_Book || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Book;
    }
}

const CPub_Base::TProc& CPub_Base::GetProc(void) const
{
    CheckSelected(e_Proc);
    return *static_cast<const TProc*>(m_object);
}

CPub_Base::TProc& CPub_Base::SetProc(void)
{
    Select(e_Proc, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TProc*>(m_object);
}

void CPub_Base::SetProc(CPub_Base::TProc& value)
{
    TProc* ptr = &value;
    if ( m_choice != e_Proc || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Proc;
    }
}

const CPub_Base::TPatent& CPub_Base::GetPatent(void) const
{
    CheckSelected(e_Patent);
    return *static_cast<const TPatent*>(m_object);
}

CPub_Base::TPatent& CPub_Base::SetPatent(void)
{
    Select(e_Patent, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TPatent*>(m_object);
}

void CPub_Base::SetPatent(CPub_Base::TPatent& value)
{
    TPatent* ptr = &value;
    if ( m_choice != e_Patent || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Patent;
    }
}

const CPub_Base::TPat_id& CPub_Base::GetPat_id(void) const
{
    CheckSelected(e_Pat_id);
    return *static_cast<const TPat_id*>(m_object);
}

CPub_Base::TPat_id& CPub_Base::SetPat_id(void)
{
    Select(e_Pat_id, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TPat_id*>(m_object);
}

void CPub_Base::SetPat_id(CPub_Base::TPat_id& value)
{
    TPat_id* ptr = &value;
    if ( m_choice != e_Pat_id || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Pat_id;
    }
}

const CPub_Base::TMan& CPub_Base::GetMan(void) const
{
    CheckSelected(e_Man);
    return *static_cast<const TMan*>(m_object);
}

CPub_Base::TMan& CPub_Base::SetMan(void)
{
    Select(e_Man, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TMan*>(m_object);
}

void CPub_Base::SetMan(CPub_Base::TMan& value)
{
    TMan* ptr = &value;
    if ( m_choice != e_Man || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Man;
    }
}

const CPub_Base::TEquiv& CPub_Base::GetEquiv(void) const
{
    CheckSelected(e_Equiv);
    return *static_cast<const TEquiv*>(m_object);
}

CPub_Base::TEquiv& CPub_Base::SetEquiv(void)
{
    Select(e_Equiv, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TEquiv*>(m_object);
}

void CPub_Base::SetEquiv(CPub_Base::TEquiv& value)
{
    TEquiv* ptr = &value;
    if ( m_choice != e_Equiv || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Equiv;
    }
}

void CPub_Base::SetPmid(const CPub_Base::TPmid& value)
{
    Select(e_Pmid, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Pmid = value;
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Pub", CPub)
{
    SET_CHOICE_MODULE("NCBI-Pub");
    ADD_NAMED_REF_CHOICE_VARIANT("gen", m_object, CCit_gen);
    ADD_NAMED_REF_CHOICE_VARIANT("sub", m_object, CCit_sub);
    ADD_NAMED_REF_CHOICE_VARIANT("medline", m_object, CMedline_entry);
    ADD_NAMED_STD_CHOICE_VARIANT("muid", m_Muid);
    ADD_NAMED_REF_CHOICE_VARIANT("article", m_object, CCit_art);
    ADD_NAMED_REF_CHOICE_VARIANT("journal", m_object, CCit_jour);
    ADD_NAMED_REF_CHOICE_VARIANT("book", m_object, CCit_book);
    ADD_NAMED_REF_CHOICE_VARIANT("proc", m_object, CCit_proc);
    ADD_NAMED_REF_CHOICE_VARIANT("patent", m_object, CCit_pat);
    ADD_NAMED_REF_CHOICE_VARIANT("pat-id", m_object, CId_pat);
    ADD_NAMED_REF_CHOICE_VARIANT("man", m_object, CCit_let);
    ADD_NAMED_REF_CHOICE_VARIANT("equiv", m_object, CPub_equiv);
    ADD_NAMED_BUF_CHOICE_VARIANT("pmid", m_Pmid, CLASS, (CPubMedId));
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CPub_Base::CPub_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CPub_Base::~CPub_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

