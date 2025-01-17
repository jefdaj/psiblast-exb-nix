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

/// @file TMgr_TrackAttributes_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'trackmgr.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_TRACKMGR_TMGR_TRACKATTRIBUTES_BASE_HPP
#define OBJECTS_TRACKMGR_TMGR_TRACKATTRIBUTES_BASE_HPP

// extra headers
#include <objects/trackmgr/trackmgr_export.h>

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_TRACKMGR_EXPORT CTMgr_TrackAttributes_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CTMgr_TrackAttributes_Base(void);
    // destructor
    virtual ~CTMgr_TrackAttributes_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TTrack_name;
    typedef list< string > TAttributes;

    // getters
    // setters

    /// track type name
    /// mandatory
    /// typedef string TTrack_name
    ///  Check whether the Track_name data member has been assigned a value.
    bool IsSetTrack_name(void) const;
    /// Check whether it is safe or not to call GetTrack_name method.
    bool CanGetTrack_name(void) const;
    void ResetTrack_name(void);
    const TTrack_name& GetTrack_name(void) const;
    void SetTrack_name(const TTrack_name& value);
    TTrack_name& SetTrack_name(void);

    /// list of attributes associated with track type name
    /// mandatory
    /// typedef list< string > TAttributes
    ///  Check whether the Attributes data member has been assigned a value.
    bool IsSetAttributes(void) const;
    /// Check whether it is safe or not to call GetAttributes method.
    bool CanGetAttributes(void) const;
    void ResetAttributes(void);
    const TAttributes& GetAttributes(void) const;
    TAttributes& SetAttributes(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CTMgr_TrackAttributes_Base(const CTMgr_TrackAttributes_Base&);
    CTMgr_TrackAttributes_Base& operator=(const CTMgr_TrackAttributes_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Track_name;
    list< string > m_Attributes;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CTMgr_TrackAttributes_Base::IsSetTrack_name(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CTMgr_TrackAttributes_Base::CanGetTrack_name(void) const
{
    return IsSetTrack_name();
}

inline
const CTMgr_TrackAttributes_Base::TTrack_name& CTMgr_TrackAttributes_Base::GetTrack_name(void) const
{
    if (!CanGetTrack_name()) {
        ThrowUnassigned(0);
    }
    return m_Track_name;
}

inline
void CTMgr_TrackAttributes_Base::SetTrack_name(const CTMgr_TrackAttributes_Base::TTrack_name& value)
{
    m_Track_name = value;
    m_set_State[0] |= 0x3;
}

inline
CTMgr_TrackAttributes_Base::TTrack_name& CTMgr_TrackAttributes_Base::SetTrack_name(void)
{
#ifdef _DEBUG
    if (!IsSetTrack_name()) {
        m_Track_name = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Track_name;
}

inline
bool CTMgr_TrackAttributes_Base::IsSetAttributes(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CTMgr_TrackAttributes_Base::CanGetAttributes(void) const
{
    return true;
}

inline
const CTMgr_TrackAttributes_Base::TAttributes& CTMgr_TrackAttributes_Base::GetAttributes(void) const
{
    return m_Attributes;
}

inline
CTMgr_TrackAttributes_Base::TAttributes& CTMgr_TrackAttributes_Base::SetAttributes(void)
{
    m_set_State[0] |= 0x4;
    return m_Attributes;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_TRACKMGR_TMGR_TRACKATTRIBUTES_BASE_HPP
