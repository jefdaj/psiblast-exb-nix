#ifndef READER_INTERFACE__HPP_INCLUDED
#define READER_INTERFACE__HPP_INCLUDED
/*  $Id: reader_interface.hpp 493171 2016-02-24 19:31:13Z vasilche $
* ===========================================================================
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
* ===========================================================================
*
*  Author:  Eugene Vasilchenko
*
*  File Description: Base data reader interface
*
*/

#include <corelib/plugin_manager.hpp>

BEGIN_NCBI_SCOPE
BEGIN_SCOPE(objects)

class CReader;

END_SCOPE(objects)

NCBI_DECLARE_INTERFACE_VERSION(objects::CReader,  "xreader", 6, 1, 0);

template<>
class CDllResolver_Getter<objects::CReader>
{
public:
    CPluginManager_DllResolver* operator()(void)
    {
        CPluginManager_DllResolver* resolver =
            new CPluginManager_DllResolver
            (CInterfaceVersion<objects::CReader>::GetName(),
             kEmptyStr,
             CVersionInfo::kAny,
             CDll::eAutoUnload);
        resolver->SetDllNamePrefix("ncbi");
        return resolver;
    }
};

END_NCBI_SCOPE

#endif//READER_INTERFACE__HPP_INCLUDED
