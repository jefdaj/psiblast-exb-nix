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

/// @file TMgr_RemoveUserTrackReques_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'trackmgr.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_TRACKMGR_TMGR_REMOVEUSERTRACKREQUES_BASE_HPP
#define OBJECTS_TRACKMGR_TMGR_REMOVEUSERTRACKREQUES_BASE_HPP

// extra headers
#include <objects/trackmgr/trackmgr_export.h>

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CTMgr_DTrackId;
class CTMgr_Identity;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_TRACKMGR_EXPORT CTMgr_RemoveUserTrackRequest_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CTMgr_RemoveUserTrackRequest_Base(void);
    // destructor
    virtual ~CTMgr_RemoveUserTrackRequest_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CTMgr_Identity TIdentity;
    typedef list< CRef< CTMgr_DTrackId > > TDtrack_ids;

    // getters
    // setters

    /// mandatory
    /// typedef CTMgr_Identity TIdentity
    ///  Check whether the Identity data member has been assigned a value.
    bool IsSetIdentity(void) const;
    /// Check whether it is safe or not to call GetIdentity method.
    bool CanGetIdentity(void) const;
    void ResetIdentity(void);
    const TIdentity& GetIdentity(void) const;
    void SetIdentity(TIdentity& value);
    TIdentity& SetIdentity(void);

    /// mandatory
    /// typedef list< CRef< CTMgr_DTrackId > > TDtrack_ids
    ///  Check whether the Dtrack_ids data member has been assigned a value.
    bool IsSetDtrack_ids(void) const;
    /// Check whether it is safe or not to call GetDtrack_ids method.
    bool CanGetDtrack_ids(void) const;
    void ResetDtrack_ids(void);
    const TDtrack_ids& GetDtrack_ids(void) const;
    TDtrack_ids& SetDtrack_ids(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CTMgr_RemoveUserTrackRequest_Base(const CTMgr_RemoveUserTrackRequest_Base&);
    CTMgr_RemoveUserTrackRequest_Base& operator=(const CTMgr_RemoveUserTrackRequest_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TIdentity > m_Identity;
    list< CRef< CTMgr_DTrackId > > m_Dtrack_ids;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CTMgr_RemoveUserTrackRequest_Base::IsSetIdentity(void) const
{
    return m_Identity.NotEmpty();
}

inline
bool CTMgr_RemoveUserTrackRequest_Base::CanGetIdentity(void) const
{
    return true;
}

inline
const CTMgr_RemoveUserTrackRequest_Base::TIdentity& CTMgr_RemoveUserTrackRequest_Base::GetIdentity(void) const
{
    if ( !m_Identity ) {
        const_cast<CTMgr_RemoveUserTrackRequest_Base*>(this)->ResetIdentity();
    }
    return (*m_Identity);
}

inline
CTMgr_RemoveUserTrackRequest_Base::TIdentity& CTMgr_RemoveUserTrackRequest_Base::SetIdentity(void)
{
    if ( !m_Identity ) {
        ResetIdentity();
    }
    return (*m_Identity);
}

inline
bool CTMgr_RemoveUserTrackRequest_Base::IsSetDtrack_ids(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CTMgr_RemoveUserTrackRequest_Base::CanGetDtrack_ids(void) const
{
    return true;
}

inline
const CTMgr_RemoveUserTrackRequest_Base::TDtrack_ids& CTMgr_RemoveUserTrackRequest_Base::GetDtrack_ids(void) const
{
    return m_Dtrack_ids;
}

inline
CTMgr_RemoveUserTrackRequest_Base::TDtrack_ids& CTMgr_RemoveUserTrackRequest_Base::SetDtrack_ids(void)
{
    m_set_State[0] |= 0x4;
    return m_Dtrack_ids;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_TRACKMGR_TMGR_REMOVEUSERTRACKREQUES_BASE_HPP
