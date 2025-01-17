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
 *   'trackmgr.asn'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

#include <ncbi_pch.hpp>
#include <objects/trackmgr/NCBI_TrackManager_module.hpp>
#include <objects/trackmgr/TMgr_AnnotCounts.hpp>
#include <objects/trackmgr/TMgr_Assembly.hpp>
#include <objects/trackmgr/TMgr_AssemblySpec.hpp>
#include <objects/trackmgr/TMgr_AttrReply.hpp>
#include <objects/trackmgr/TMgr_AttrRequest.hpp>
#include <objects/trackmgr/TMgr_AttrSpec.hpp>
#include <objects/trackmgr/TMgr_AttrValueReply.hpp>
#include <objects/trackmgr/TMgr_Attribute.hpp>
#include <objects/trackmgr/TMgr_BlastQuerySeq.hpp>
#include <objects/trackmgr/TMgr_BlastRIDDetail.hpp>
#include <objects/trackmgr/TMgr_BlastRIDReply.hpp>
#include <objects/trackmgr/TMgr_BlastRIDRequest.hpp>
#include <objects/trackmgr/TMgr_ClientInfo.hpp>
#include <objects/trackmgr/TMgr_CreateTracksetReply.hpp>
#include <objects/trackmgr/TMgr_CreateTracksetRequest.hpp>
#include <objects/trackmgr/TMgr_CreateUserDataItem.hpp>
#include <objects/trackmgr/TMgr_CreateUserTrackReply.hpp>
#include <objects/trackmgr/TMgr_CreateUserTrackReques.hpp>
#include <objects/trackmgr/TMgr_DatasetItem.hpp>
#include <objects/trackmgr/TMgr_DatasetItemSeq.hpp>
#include <objects/trackmgr/TMgr_DisplayTrack.hpp>
#include <objects/trackmgr/TMgr_DisplayTrackChoice.hpp>
#include <objects/trackmgr/TMgr_DisplayTrackReply.hpp>
#include <objects/trackmgr/TMgr_DisplayTrackRequest.hpp>
#include <objects/trackmgr/TMgr_GenomeContext.hpp>
#include <objects/trackmgr/TMgr_Identity.hpp>
#include <objects/trackmgr/TMgr_IdentityId.hpp>
#include <objects/trackmgr/TMgr_ItemResolverReply.hpp>
#include <objects/trackmgr/TMgr_ItemResolverRequest.hpp>
#include <objects/trackmgr/TMgr_LengthStats.hpp>
#include <objects/trackmgr/TMgr_Message.hpp>
#include <objects/trackmgr/TMgr_PositionStats.hpp>
#include <objects/trackmgr/TMgr_RemoveUserTrackReply.hpp>
#include <objects/trackmgr/TMgr_RemoveUserTrackReques.hpp>
#include <objects/trackmgr/TMgr_RenameMyNCBICollectio.hpp>
#include <objects/trackmgr/TMgr_Reply.hpp>
#include <objects/trackmgr/TMgr_Request.hpp>
#include <objects/trackmgr/TMgr_RetrieveTracksetReply.hpp>
#include <objects/trackmgr/TMgr_RetrieveTracksetReque.hpp>
#include <objects/trackmgr/TMgr_SupportedAssembliesRe.hpp>
#include <objects/trackmgr/TMgr_SwitchTrackContextRep.hpp>
#include <objects/trackmgr/TMgr_SwitchTrackContextReq.hpp>
#include <objects/trackmgr/TMgr_SwitchTrackException.hpp>
#include <objects/trackmgr/TMgr_TrackACL_Authorizatio.hpp>
#include <objects/trackmgr/TMgr_TrackACL_Permission.hpp>
#include <objects/trackmgr/TMgr_TrackAttrValueReply.hpp>
#include <objects/trackmgr/TMgr_TrackAttrValueRequest.hpp>
#include <objects/trackmgr/TMgr_TrackAttributes.hpp>
#include <objects/trackmgr/TMgr_TrackItems.hpp>
#include <objects/trackmgr/TMgr_TrackSet.hpp>
#include <objects/trackmgr/TMgr_TypeStat.hpp>
#include <objects/trackmgr/TMgr_ValueRequest.hpp>


BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

void NCBI_TrackManager_RegisterModuleClasses(void)
{
    ncbi::objects::CTMgr_AnnotCounts::GetTypeInfo();
    ncbi::objects::CTMgr_Assembly::GetTypeInfo();
    ncbi::objects::CTMgr_AssemblySpec::GetTypeInfo();
    ncbi::objects::CTMgr_AttrReply::GetTypeInfo();
    ncbi::objects::CTMgr_AttrRequest::GetTypeInfo();
    ncbi::objects::CTMgr_AttrSpec::GetTypeInfo();
    ncbi::objects::CTMgr_AttrValueReply::GetTypeInfo();
    ncbi::objects::CTMgr_Attribute::GetTypeInfo();
    ncbi::objects::CTMgr_BlastQuerySeq::GetTypeInfo();
    ncbi::objects::CTMgr_BlastRIDDetail::GetTypeInfo();
    ncbi::objects::CTMgr_BlastRIDReply::GetTypeInfo();
    ncbi::objects::CTMgr_BlastRIDRequest::GetTypeInfo();
    ncbi::objects::CTMgr_ClientInfo::GetTypeInfo();
    ncbi::objects::CTMgr_CreateTracksetReply::GetTypeInfo();
    ncbi::objects::CTMgr_CreateTracksetRequest::GetTypeInfo();
    ncbi::objects::CTMgr_CreateUserDataItem::GetTypeInfo();
    ncbi::objects::CTMgr_CreateUserTrackReply::GetTypeInfo();
    ncbi::objects::CTMgr_CreateUserTrackRequest::GetTypeInfo();
    ncbi::objects::CTMgr_DatasetItem::GetTypeInfo();
    ncbi::objects::CTMgr_DatasetItemSeq::GetTypeInfo();
    ncbi::objects::CTMgr_DisplayTrack::GetTypeInfo();
    ncbi::objects::CTMgr_DisplayTrackChoice::GetTypeInfo();
    ncbi::objects::CTMgr_DisplayTrackReply::GetTypeInfo();
    ncbi::objects::CTMgr_DisplayTrackRequest::GetTypeInfo();
    ncbi::objects::CTMgr_GenomeContext::GetTypeInfo();
    ncbi::objects::CTMgr_Identity::GetTypeInfo();
    ncbi::objects::CTMgr_IdentityId::GetTypeInfo();
    ncbi::objects::CTMgr_ItemResolverReply::GetTypeInfo();
    ncbi::objects::CTMgr_ItemResolverRequest::GetTypeInfo();
    ncbi::objects::CTMgr_LengthStats::GetTypeInfo();
    ncbi::objects::CTMgr_Message::GetTypeInfo();
    ncbi::objects::CTMgr_PositionStats::GetTypeInfo();
    ncbi::objects::CTMgr_RemoveUserTrackReply::GetTypeInfo();
    ncbi::objects::CTMgr_RemoveUserTrackRequest::GetTypeInfo();
    ncbi::objects::CTMgr_RenameMyNCBICollectionRequest::GetTypeInfo();
    ncbi::objects::CTMgr_RenameMyNCBICollectionReply::GetTypeInfo();
    ncbi::objects::CTMgr_Reply::GetTypeInfo();
    ncbi::objects::CTMgr_Request::GetTypeInfo();
    ncbi::objects::CTMgr_RetrieveTracksetReply::GetTypeInfo();
    ncbi::objects::CTMgr_RetrieveTracksetRequest::GetTypeInfo();
    ncbi::objects::CTMgr_SupportedAssembliesRequest::GetTypeInfo();
    ncbi::objects::CTMgr_SupportedAssembliesReply::GetTypeInfo();
    ncbi::objects::CTMgr_SwitchTrackContextReply::GetTypeInfo();
    ncbi::objects::CTMgr_SwitchTrackContextRequest::GetTypeInfo();
    ncbi::objects::CTMgr_SwitchTrackException::GetTypeInfo();
    ncbi::objects::CTMgr_TrackACL_Authorization::GetTypeInfo();
    ncbi::objects::CTMgr_TrackACL_Permission::GetTypeInfo();
    ncbi::objects::CTMgr_TrackAttrValueReply::GetTypeInfo();
    ncbi::objects::CTMgr_TrackAttrValueRequest::GetTypeInfo();
    ncbi::objects::CTMgr_TrackAttributes::GetTypeInfo();
    ncbi::objects::CTMgr_TrackItems::GetTypeInfo();
    ncbi::objects::CTMgr_TrackSet::GetTypeInfo();
    ncbi::objects::CTMgr_TypeStat::GetTypeInfo();
    ncbi::objects::CTMgr_ValueRequest::GetTypeInfo();
}

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

