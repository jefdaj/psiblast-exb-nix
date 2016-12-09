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

/// @file Entrez2_link_set_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'entrez2.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_ENTREZ2_ENTREZ2_LINK_SET_BASE_HPP
#define OBJECTS_ENTREZ2_ENTREZ2_LINK_SET_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <vector>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CEntrez2_id_list;


// generated classes

/////////////////////////////////////////////////////////////////////////////
///*******************************************
/// Links are returned in sets also using OCTET STRINGS
///*******************************************
/// set of links
class NCBI_ENTREZ2_EXPORT CEntrez2_link_set_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CEntrez2_link_set_Base(void);
    // destructor
    virtual ~CEntrez2_link_set_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CEntrez2_id_list TIds;
    typedef int TData_size;
    typedef vector< char > TData;

    // getters
    // setters

    /// mandatory
    /// typedef CEntrez2_id_list TIds
    ///  Check whether the Ids data member has been assigned a value.
    bool IsSetIds(void) const;
    /// Check whether it is safe or not to call GetIds method.
    bool CanGetIds(void) const;
    void ResetIds(void);
    const TIds& GetIds(void) const;
    void SetIds(TIds& value);
    TIds& SetIds(void);

    /// size of data elements
    /// optional
    /// typedef int TData_size
    ///  Check whether the Data_size data member has been assigned a value.
    bool IsSetData_size(void) const;
    /// Check whether it is safe or not to call GetData_size method.
    bool CanGetData_size(void) const;
    void ResetData_size(void);
    TData_size GetData_size(void) const;
    void SetData_size(TData_size value);
    TData_size& SetData_size(void);

    /// coded scores
    /// optional
    /// typedef vector< char > TData
    ///  Check whether the Data data member has been assigned a value.
    bool IsSetData(void) const;
    /// Check whether it is safe or not to call GetData method.
    bool CanGetData(void) const;
    void ResetData(void);
    const TData& GetData(void) const;
    TData& SetData(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CEntrez2_link_set_Base(const CEntrez2_link_set_Base&);
    CEntrez2_link_set_Base& operator=(const CEntrez2_link_set_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TIds > m_Ids;
    int m_Data_size;
    vector< char > m_Data;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CEntrez2_link_set_Base::IsSetIds(void) const
{
    return m_Ids.NotEmpty();
}

inline
bool CEntrez2_link_set_Base::CanGetIds(void) const
{
    return true;
}

inline
const CEntrez2_link_set_Base::TIds& CEntrez2_link_set_Base::GetIds(void) const
{
    if ( !m_Ids ) {
        const_cast<CEntrez2_link_set_Base*>(this)->ResetIds();
    }
    return (*m_Ids);
}

inline
CEntrez2_link_set_Base::TIds& CEntrez2_link_set_Base::SetIds(void)
{
    if ( !m_Ids ) {
        ResetIds();
    }
    return (*m_Ids);
}

inline
bool CEntrez2_link_set_Base::IsSetData_size(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CEntrez2_link_set_Base::CanGetData_size(void) const
{
    return IsSetData_size();
}

inline
void CEntrez2_link_set_Base::ResetData_size(void)
{
    m_Data_size = 0;
    m_set_State[0] &= ~0xc;
}

inline
CEntrez2_link_set_Base::TData_size CEntrez2_link_set_Base::GetData_size(void) const
{
    if (!CanGetData_size()) {
        ThrowUnassigned(1);
    }
    return m_Data_size;
}

inline
void CEntrez2_link_set_Base::SetData_size(CEntrez2_link_set_Base::TData_size value)
{
    m_Data_size = value;
    m_set_State[0] |= 0xc;
}

inline
CEntrez2_link_set_Base::TData_size& CEntrez2_link_set_Base::SetData_size(void)
{
#ifdef _DEBUG
    if (!IsSetData_size()) {
        memset(&m_Data_size,UnassignedByte(),sizeof(m_Data_size));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Data_size;
}

inline
bool CEntrez2_link_set_Base::IsSetData(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CEntrez2_link_set_Base::CanGetData(void) const
{
    return IsSetData();
}

inline
const CEntrez2_link_set_Base::TData& CEntrez2_link_set_Base::GetData(void) const
{
    if (!CanGetData()) {
        ThrowUnassigned(2);
    }
    return m_Data;
}

inline
CEntrez2_link_set_Base::TData& CEntrez2_link_set_Base::SetData(void)
{
    m_set_State[0] |= 0x10;
    return m_Data;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ENTREZ2_ENTREZ2_LINK_SET_BASE_HPP