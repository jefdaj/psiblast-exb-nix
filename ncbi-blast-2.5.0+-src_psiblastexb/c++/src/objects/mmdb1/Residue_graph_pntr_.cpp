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
 *   'mmdb1.asn'.
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
#include <objects/mmdb1/Residue_graph_pntr.hpp>
#include <objects/mmdb1/Biost_resid_graph_set_pntr.hpp>
#include <objects/mmdb1/Biostruc_graph_pntr.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CResidue_graph_pntr_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CResidue_graph_pntr_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Local:
        m_Local.Destruct();
        break;
    case e_Biostruc:
    case e_Standard:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CResidue_graph_pntr_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Local:
        m_Local.Construct();
        break;
    case e_Biostruc:
        (m_object = new(pool) ncbi::objects::CBiostruc_graph_pntr())->AddReference();
        break;
    case e_Standard:
        (m_object = new(pool) ncbi::objects::CBiostruc_residue_graph_set_pntr())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CResidue_graph_pntr_Base::sm_SelectionNames[] = {
    "not set",
    "local",
    "biostruc",
    "standard"
};

NCBI_NS_STD::string CResidue_graph_pntr_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CResidue_graph_pntr_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CResidue_graph_pntr_Base::SetLocal(const CResidue_graph_pntr_Base::TLocal& value)
{
    Select(e_Local, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_Local = value;
}

const CResidue_graph_pntr_Base::TBiostruc& CResidue_graph_pntr_Base::GetBiostruc(void) const
{
    CheckSelected(e_Biostruc);
    return *static_cast<const TBiostruc*>(m_object);
}

CResidue_graph_pntr_Base::TBiostruc& CResidue_graph_pntr_Base::SetBiostruc(void)
{
    Select(e_Biostruc, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TBiostruc*>(m_object);
}

void CResidue_graph_pntr_Base::SetBiostruc(CResidue_graph_pntr_Base::TBiostruc& value)
{
    TBiostruc* ptr = &value;
    if ( m_choice != e_Biostruc || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Biostruc;
    }
}

const CResidue_graph_pntr_Base::TStandard& CResidue_graph_pntr_Base::GetStandard(void) const
{
    CheckSelected(e_Standard);
    return *static_cast<const TStandard*>(m_object);
}

CResidue_graph_pntr_Base::TStandard& CResidue_graph_pntr_Base::SetStandard(void)
{
    Select(e_Standard, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TStandard*>(m_object);
}

void CResidue_graph_pntr_Base::SetStandard(CResidue_graph_pntr_Base::TStandard& value)
{
    TStandard* ptr = &value;
    if ( m_choice != e_Standard || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Standard;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Residue-graph-pntr", CResidue_graph_pntr)
{
    SET_CHOICE_MODULE("MMDB-Chemical-graph");
    ADD_NAMED_BUF_CHOICE_VARIANT("local", m_Local, CLASS, (CResidue_graph_id));
    ADD_NAMED_REF_CHOICE_VARIANT("biostruc", m_object, CBiostruc_graph_pntr);
    ADD_NAMED_REF_CHOICE_VARIANT("standard", m_object, CBiostruc_residue_graph_set_pntr);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CResidue_graph_pntr_Base::CResidue_graph_pntr_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CResidue_graph_pntr_Base::~CResidue_graph_pntr_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
