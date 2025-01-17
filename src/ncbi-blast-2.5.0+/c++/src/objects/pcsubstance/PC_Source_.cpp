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
 *   'pcsubstance.asn'.
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
#include <objects/pcsubstance/PC_Source.hpp>
#include <objects/pcsubstance/PC_DBTracking.hpp>
#include <objects/pcsubstance/PC_MMDBSource.hpp>
#include <objects/pub/Pub.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPC_Source_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CPC_Source_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Individual:
    case e_Db:
    case e_Mmdb:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CPC_Source_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Individual:
        (m_object = new(pool) ncbi::objects::CPub())->AddReference();
        break;
    case e_Db:
        (m_object = new(pool) ncbi::objects::CPC_DBTracking())->AddReference();
        break;
    case e_Mmdb:
        (m_object = new(pool) ncbi::objects::CPC_MMDBSource())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CPC_Source_Base::sm_SelectionNames[] = {
    "not set",
    "individual",
    "db",
    "mmdb"
};

NCBI_NS_STD::string CPC_Source_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CPC_Source_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CPC_Source_Base::TIndividual& CPC_Source_Base::GetIndividual(void) const
{
    CheckSelected(e_Individual);
    return *static_cast<const TIndividual*>(m_object);
}

CPC_Source_Base::TIndividual& CPC_Source_Base::SetIndividual(void)
{
    Select(e_Individual, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TIndividual*>(m_object);
}

void CPC_Source_Base::SetIndividual(CPC_Source_Base::TIndividual& value)
{
    TIndividual* ptr = &value;
    if ( m_choice != e_Individual || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Individual;
    }
}

const CPC_Source_Base::TDb& CPC_Source_Base::GetDb(void) const
{
    CheckSelected(e_Db);
    return *static_cast<const TDb*>(m_object);
}

CPC_Source_Base::TDb& CPC_Source_Base::SetDb(void)
{
    Select(e_Db, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TDb*>(m_object);
}

void CPC_Source_Base::SetDb(CPC_Source_Base::TDb& value)
{
    TDb* ptr = &value;
    if ( m_choice != e_Db || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Db;
    }
}

const CPC_Source_Base::TMmdb& CPC_Source_Base::GetMmdb(void) const
{
    CheckSelected(e_Mmdb);
    return *static_cast<const TMmdb*>(m_object);
}

CPC_Source_Base::TMmdb& CPC_Source_Base::SetMmdb(void)
{
    Select(e_Mmdb, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TMmdb*>(m_object);
}

void CPC_Source_Base::SetMmdb(CPC_Source_Base::TMmdb& value)
{
    TMmdb* ptr = &value;
    if ( m_choice != e_Mmdb || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Mmdb;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("PC-Source", CPC_Source)
{
    SET_CHOICE_MODULE("NCBI-PCSubstance");
    ADD_NAMED_REF_CHOICE_VARIANT("individual", m_object, CPub);
    ADD_NAMED_REF_CHOICE_VARIANT("db", m_object, CPC_DBTracking);
    ADD_NAMED_REF_CHOICE_VARIANT("mmdb", m_object, CPC_MMDBSource);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CPC_Source_Base::CPC_Source_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CPC_Source_Base::~CPC_Source_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

