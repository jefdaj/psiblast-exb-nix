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
 */

/// @file GCClient_FindBestAssemblyF_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'gencoll_client.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_GENOMECOLL_GCCLIENT_FINDBESTASSEMBLYF_BASE_HPP
#define OBJECTS_GENOMECOLL_GCCLIENT_FINDBESTASSEMBLYF_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

enum EGCClient_FindBestAssemblyFilter {
    eGCClient_FindBestAssemblyFilter_any                    = 0,
    eGCClient_FindBestAssemblyFilter_latest_major_annotated = 0,
    eGCClient_FindBestAssemblyFilter_latest                 = 1,
    eGCClient_FindBestAssemblyFilter_major                  = 2,
    eGCClient_FindBestAssemblyFilter_annotated              = 3,
    eGCClient_FindBestAssemblyFilter_all                    = 4
};

/// Access to EGCClient_FindBestAssemblyFilter's attributes (values, names) as defined in spec
 const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EGCClient_FindBestAssemblyFilter)(void);


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_GENOMECOLL_GCCLIENT_FINDBESTASSEMBLYF_BASE_HPP
