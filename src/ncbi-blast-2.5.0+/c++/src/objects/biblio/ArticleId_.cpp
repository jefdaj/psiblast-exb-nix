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
 *   'biblio.asn'.
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
#include <objects/biblio/ArticleId.hpp>
#include <objects/general/Dbtag.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CArticleId_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CArticleId_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Pubmed:
        m_Pubmed.Destruct();
        break;
    case e_Medline:
        m_Medline.Destruct();
        break;
    case e_Doi:
        m_Doi.Destruct();
        break;
    case e_Pii:
        m_Pii.Destruct();
        break;
    case e_Pmcid:
        m_Pmcid.Destruct();
        break;
    case e_Pmcpid:
        m_Pmcpid.Destruct();
        break;
    case e_Pmpid:
        m_Pmpid.Destruct();
        break;
    case e_Other:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CArticleId_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Pubmed:
        m_Pubmed.Construct();
        break;
    case e_Medline:
        m_Medline.Construct();
        break;
    case e_Doi:
        m_Doi.Construct();
        break;
    case e_Pii:
        m_Pii.Construct();
        break;
    case e_Pmcid:
        m_Pmcid.Construct();
        break;
    case e_Pmcpid:
        m_Pmcpid.Construct();
        break;
    case e_Pmpid:
        m_Pmpid.Construct();
        break;
    case e_Other:
        (m_object = new(pool) ncbi::objects::CDbtag())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CArticleId_Base::sm_SelectionNames[] = {
    "not set",
    "pubmed",
    "medline",
    "doi",
    "pii",
    "pmcid",
    "pmcpid",
    "pmpid",
    "other"
};

NCBI_NS_STD::string CArticleId_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CArticleId_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CArticleId_Base::SetPubmed(const CArticleId_Base::TPubmed& value)
{
    Select(e_Pubmed, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Pubmed = value;
}

void CArticleId_Base::SetMedline(const CArticleId_Base::TMedline& value)
{
    Select(e_Medline, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Medline = value;
}

void CArticleId_Base::SetDoi(const CArticleId_Base::TDoi& value)
{
    Select(e_Doi, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Doi = value;
}

void CArticleId_Base::SetPii(const CArticleId_Base::TPii& value)
{
    Select(e_Pii, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Pii = value;
}

void CArticleId_Base::SetPmcid(const CArticleId_Base::TPmcid& value)
{
    Select(e_Pmcid, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Pmcid = value;
}

void CArticleId_Base::SetPmcpid(const CArticleId_Base::TPmcpid& value)
{
    Select(e_Pmcpid, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Pmcpid = value;
}

void CArticleId_Base::SetPmpid(const CArticleId_Base::TPmpid& value)
{
    Select(e_Pmpid, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Pmpid = value;
}

const CArticleId_Base::TOther& CArticleId_Base::GetOther(void) const
{
    CheckSelected(e_Other);
    return *static_cast<const TOther*>(m_object);
}

CArticleId_Base::TOther& CArticleId_Base::SetOther(void)
{
    Select(e_Other, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TOther*>(m_object);
}

void CArticleId_Base::SetOther(CArticleId_Base::TOther& value)
{
    TOther* ptr = &value;
    if ( m_choice != e_Other || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Other;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("ArticleId", CArticleId)
{
    SET_CHOICE_MODULE("NCBI-Biblio");
    ADD_NAMED_BUF_CHOICE_VARIANT("pubmed", m_Pubmed, CLASS, (CPubMedId));
    ADD_NAMED_BUF_CHOICE_VARIANT("medline", m_Medline, CLASS, (CMedlineUID));
    ADD_NAMED_BUF_CHOICE_VARIANT("doi", m_Doi, CLASS, (CDOI));
    ADD_NAMED_BUF_CHOICE_VARIANT("pii", m_Pii, CLASS, (CPII));
    ADD_NAMED_BUF_CHOICE_VARIANT("pmcid", m_Pmcid, CLASS, (CPmcID));
    ADD_NAMED_BUF_CHOICE_VARIANT("pmcpid", m_Pmcpid, CLASS, (CPmcPid));
    ADD_NAMED_BUF_CHOICE_VARIANT("pmpid", m_Pmpid, CLASS, (CPmPid));
    ADD_NAMED_REF_CHOICE_VARIANT("other", m_object, CDbtag);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CArticleId_Base::CArticleId_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CArticleId_Base::~CArticleId_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

