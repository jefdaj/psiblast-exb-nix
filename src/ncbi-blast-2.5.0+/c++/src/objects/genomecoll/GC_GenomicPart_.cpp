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
 *   'genome_collection.asn'.
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
#include <objects/genomecoll/GC_GenomicPart.hpp>
#include <objects/genomecoll/GC_Assembly.hpp>
#include <objects/genomecoll/GC_Replicon.hpp>
#include <objects/genomecoll/GC_Sequence.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CGC_GenomicPart_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CGC_GenomicPart_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Assembly:
    case e_Mol:
    case e_Seqs:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CGC_GenomicPart_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Assembly:
        (m_object = new(pool) ncbi::objects::CGC_Assembly())->AddReference();
        break;
    case e_Mol:
        (m_object = new(pool) ncbi::objects::CGC_Replicon())->AddReference();
        break;
    case e_Seqs:
        (m_object = new(pool) ncbi::objects::CGC_Sequence())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CGC_GenomicPart_Base::sm_SelectionNames[] = {
    "not set",
    "assembly",
    "mol",
    "seqs"
};

NCBI_NS_STD::string CGC_GenomicPart_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CGC_GenomicPart_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CGC_GenomicPart_Base::TAssembly& CGC_GenomicPart_Base::GetAssembly(void) const
{
    CheckSelected(e_Assembly);
    return *static_cast<const TAssembly*>(m_object);
}

CGC_GenomicPart_Base::TAssembly& CGC_GenomicPart_Base::SetAssembly(void)
{
    Select(e_Assembly, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TAssembly*>(m_object);
}

void CGC_GenomicPart_Base::SetAssembly(CGC_GenomicPart_Base::TAssembly& value)
{
    TAssembly* ptr = &value;
    if ( m_choice != e_Assembly || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Assembly;
    }
}

const CGC_GenomicPart_Base::TMol& CGC_GenomicPart_Base::GetMol(void) const
{
    CheckSelected(e_Mol);
    return *static_cast<const TMol*>(m_object);
}

CGC_GenomicPart_Base::TMol& CGC_GenomicPart_Base::SetMol(void)
{
    Select(e_Mol, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TMol*>(m_object);
}

void CGC_GenomicPart_Base::SetMol(CGC_GenomicPart_Base::TMol& value)
{
    TMol* ptr = &value;
    if ( m_choice != e_Mol || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Mol;
    }
}

const CGC_GenomicPart_Base::TSeqs& CGC_GenomicPart_Base::GetSeqs(void) const
{
    CheckSelected(e_Seqs);
    return *static_cast<const TSeqs*>(m_object);
}

CGC_GenomicPart_Base::TSeqs& CGC_GenomicPart_Base::SetSeqs(void)
{
    Select(e_Seqs, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TSeqs*>(m_object);
}

void CGC_GenomicPart_Base::SetSeqs(CGC_GenomicPart_Base::TSeqs& value)
{
    TSeqs* ptr = &value;
    if ( m_choice != e_Seqs || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Seqs;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("GC-GenomicPart", CGC_GenomicPart)
{
    SET_CHOICE_MODULE("NCBI-GenomeCollection");
    ADD_NAMED_REF_CHOICE_VARIANT("assembly", m_object, CGC_Assembly);
    ADD_NAMED_REF_CHOICE_VARIANT("mol", m_object, CGC_Replicon);
    ADD_NAMED_REF_CHOICE_VARIANT("seqs", m_object, CGC_Sequence);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CGC_GenomicPart_Base::CGC_GenomicPart_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CGC_GenomicPart_Base::~CGC_GenomicPart_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

