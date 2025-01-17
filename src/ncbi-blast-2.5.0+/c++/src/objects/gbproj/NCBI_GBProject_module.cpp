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
 *   'gbproj.asn'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

#include <ncbi_pch.hpp>
#include <objects/gbproj/NCBI_GBProject_module.hpp>
#include <objects/gbproj/AbstractProjectItem.hpp>
#include <objects/gbproj/DummyObsoleteType.hpp>
#include <objects/gbproj/FolderInfo.hpp>
#include <objects/gbproj/GBProject_ver2.hpp>
#include <objects/gbproj/LoaderDescriptor.hpp>
#include <objects/gbproj/ProjectAnnot.hpp>
#include <objects/gbproj/ProjectDescr.hpp>
#include <objects/gbproj/ProjectFolder.hpp>
#include <objects/gbproj/ProjectHistoryItem.hpp>
#include <objects/gbproj/ProjectItem.hpp>
#include <objects/gbproj/ViewDataLink.hpp>
#include <objects/gbproj/ViewDescriptor.hpp>
#include <objects/gbproj/ViewMemento.hpp>


BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

void NCBI_GBProject_RegisterModuleClasses(void)
{
    ncbi::objects::CAbstractProjectItem::GetTypeInfo();
    ncbi::objects::CDummyObsoleteType::GetTypeInfo();
    ncbi::objects::CFolderInfo::GetTypeInfo();
    ncbi::objects::CGBProject_ver2::GetTypeInfo();
    ncbi::objects::CLoaderDescriptor::GetTypeInfo();
    ncbi::objects::CProjectAnnot::GetTypeInfo();
    ncbi::objects::CProjectDescr::GetTypeInfo();
    ncbi::objects::CProjectFolder::GetTypeInfo();
    ncbi::objects::CProjectHistoryItem::GetTypeInfo();
    ncbi::objects::CProjectItem::GetTypeInfo();
    ncbi::objects::CViewDataLink::GetTypeInfo();
    ncbi::objects::CViewDescriptor::GetTypeInfo();
    ncbi::objects::CViewMemento::GetTypeInfo();
}

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

