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
 *   'proj.asn'.
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
#include <objects/proj/Project.hpp>
#include <objects/proj/Project_descr.hpp>
#include <objects/proj/Project_item.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CProject_Base::ResetDescr(void)
{
    m_Descr.Reset();
}

void CProject_Base::SetDescr(CProject_Base::TDescr& value)
{
    m_Descr.Reset(&value);
}

CProject_Base::TDescr& CProject_Base::SetDescr(void)
{
    if ( !m_Descr )
        m_Descr.Reset(new ncbi::objects::CProject_descr());
    return (*m_Descr);
}

void CProject_Base::ResetData(void)
{
    if ( !m_Data ) {
        m_Data.Reset(new TData());
        return;
    }
    (*m_Data).Reset();
}

void CProject_Base::SetData(CProject_Base::TData& value)
{
    m_Data.Reset(&value);
}

void CProject_Base::Reset(void)
{
    ResetDescr();
    ResetData();
}

BEGIN_NAMED_BASE_CLASS_INFO("Project", CProject)
{
    SET_CLASS_MODULE("NCBI-Project");
    ADD_NAMED_REF_MEMBER("descr", m_Descr, CProject_descr)->SetOptional();
    ADD_NAMED_REF_MEMBER("data", m_Data, CProject_item);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CProject_Base::CProject_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetData();
    }
}

// destructor
CProject_Base::~CProject_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

