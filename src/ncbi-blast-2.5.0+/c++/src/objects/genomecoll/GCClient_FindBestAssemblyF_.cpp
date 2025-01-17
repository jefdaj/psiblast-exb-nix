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

// standard includes
#include <ncbi_pch.hpp>
#include <serial/serialimpl.hpp>

// generated includes
#include <objects/genomecoll/GCClient_FindBestAssemblyF.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_INFO("GCClient-FindBestAssemblyFilter", EGCClient_FindBestAssemblyFilter, true)
{
    SET_ENUM_MODULE("NCBI-GencollClient");
    ADD_ENUM_VALUE("any", eGCClient_FindBestAssemblyFilter_any);
    ADD_ENUM_VALUE("latest-major-annotated", eGCClient_FindBestAssemblyFilter_latest_major_annotated);
    ADD_ENUM_VALUE("latest", eGCClient_FindBestAssemblyFilter_latest);
    ADD_ENUM_VALUE("major", eGCClient_FindBestAssemblyFilter_major);
    ADD_ENUM_VALUE("annotated", eGCClient_FindBestAssemblyFilter_annotated);
    ADD_ENUM_VALUE("all", eGCClient_FindBestAssemblyFilter_all);
}
END_ENUM_INFO


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

