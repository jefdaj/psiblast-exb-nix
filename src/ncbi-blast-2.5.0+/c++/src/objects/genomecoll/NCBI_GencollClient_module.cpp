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
 *   'gencoll_client.asn'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

#include <ncbi_pch.hpp>
#include <objects/genomecoll/NCBI_GencollClient_module.hpp>
#include <objects/genomecoll/GCClientRequest.hpp>
#include <objects/genomecoll/GCClientResponse.hpp>
#include <objects/genomecoll/GCClient_AssembliesForSequ.hpp>
#include <objects/genomecoll/GCClient_AssemblyInfo.hpp>
#include <objects/genomecoll/GCClient_AssemblySequenceI.hpp>
#include <objects/genomecoll/GCClient_EquivalentAssembl.hpp>
#include <objects/genomecoll/GCClient_Error.hpp>
#include <objects/genomecoll/GCClient_FindBestAssemblyR.hpp>
#include <objects/genomecoll/GCClient_GetAssemblyBlobRe.hpp>
#include <objects/genomecoll/GCClient_GetAssemblyBySequ.hpp>
#include <objects/genomecoll/GCClient_GetAssemblyReques.hpp>
#include <objects/genomecoll/GCClient_GetEquivalentAsse.hpp>
#include <objects/genomecoll/GCClient_ValidateChrTypeLo.hpp>


BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

void NCBI_GencollClient_RegisterModuleClasses(void)
{
    ncbi::objects::CGCClientRequest::GetTypeInfo();
    ncbi::objects::CGCClientResponse::GetTypeInfo();
    ncbi::objects::CGCClient_AssembliesForSequences::GetTypeInfo();
    ncbi::objects::CGCClient_AssemblyInfo::GetTypeInfo();
    ncbi::objects::CGCClient_AssemblySequenceInfo::GetTypeInfo();
    ncbi::objects::CGCClient_EquivalentAssemblies::GetTypeInfo();
    ncbi::objects::CGCClient_Error::GetTypeInfo();
    ncbi::objects::CGCClient_FindBestAssemblyRequest::GetTypeInfo();
    ncbi::objects::CGCClient_GetAssemblyBlobRequest::GetTypeInfo();
    ncbi::objects::CGCClient_GetAssemblyBySequenceRequest::GetTypeInfo();
    ncbi::objects::CGCClient_GetAssemblyRequest::GetTypeInfo();
    ncbi::objects::CGCClient_GetEquivalentAssembliesRequest::GetTypeInfo();
    ncbi::objects::CGCClient_ValidateChrTypeLocResponse::GetTypeInfo();
    ncbi::objects::CGCClient_ValidateChrTypeLocRequest::GetTypeInfo();
}

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

