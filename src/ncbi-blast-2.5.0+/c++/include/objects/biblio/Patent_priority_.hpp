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

/// @file Patent_priority_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'biblio.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_BIBLIO_PATENT_PRIORITY_BASE_HPP
#define OBJECTS_BIBLIO_PATENT_PRIORITY_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CDate;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_BIBLIO_EXPORT CPatent_priority_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CPatent_priority_Base(void);
    // destructor
    virtual ~CPatent_priority_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TCountry;
    typedef string TNumber;
    typedef CDate TDate;

    // getters
    // setters

    /// Patent country code
    /// mandatory
    /// typedef string TCountry
    ///  Check whether the Country data member has been assigned a value.
    bool IsSetCountry(void) const;
    /// Check whether it is safe or not to call GetCountry method.
    bool CanGetCountry(void) const;
    void ResetCountry(void);
    const TCountry& GetCountry(void) const;
    void SetCountry(const TCountry& value);
    TCountry& SetCountry(void);

    /// number assigned in that country
    /// mandatory
    /// typedef string TNumber
    ///  Check whether the Number data member has been assigned a value.
    bool IsSetNumber(void) const;
    /// Check whether it is safe or not to call GetNumber method.
    bool CanGetNumber(void) const;
    void ResetNumber(void);
    const TNumber& GetNumber(void) const;
    void SetNumber(const TNumber& value);
    TNumber& SetNumber(void);

    /// date of application
    /// mandatory
    /// typedef CDate TDate
    ///  Check whether the Date data member has been assigned a value.
    bool IsSetDate(void) const;
    /// Check whether it is safe or not to call GetDate method.
    bool CanGetDate(void) const;
    void ResetDate(void);
    const TDate& GetDate(void) const;
    void SetDate(TDate& value);
    TDate& SetDate(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CPatent_priority_Base(const CPatent_priority_Base&);
    CPatent_priority_Base& operator=(const CPatent_priority_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Country;
    string m_Number;
    CRef< TDate > m_Date;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CPatent_priority_Base::IsSetCountry(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CPatent_priority_Base::CanGetCountry(void) const
{
    return IsSetCountry();
}

inline
const CPatent_priority_Base::TCountry& CPatent_priority_Base::GetCountry(void) const
{
    if (!CanGetCountry()) {
        ThrowUnassigned(0);
    }
    return m_Country;
}

inline
void CPatent_priority_Base::SetCountry(const CPatent_priority_Base::TCountry& value)
{
    m_Country = value;
    m_set_State[0] |= 0x3;
}

inline
CPatent_priority_Base::TCountry& CPatent_priority_Base::SetCountry(void)
{
#ifdef _DEBUG
    if (!IsSetCountry()) {
        m_Country = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Country;
}

inline
bool CPatent_priority_Base::IsSetNumber(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CPatent_priority_Base::CanGetNumber(void) const
{
    return IsSetNumber();
}

inline
const CPatent_priority_Base::TNumber& CPatent_priority_Base::GetNumber(void) const
{
    if (!CanGetNumber()) {
        ThrowUnassigned(1);
    }
    return m_Number;
}

inline
void CPatent_priority_Base::SetNumber(const CPatent_priority_Base::TNumber& value)
{
    m_Number = value;
    m_set_State[0] |= 0xc;
}

inline
CPatent_priority_Base::TNumber& CPatent_priority_Base::SetNumber(void)
{
#ifdef _DEBUG
    if (!IsSetNumber()) {
        m_Number = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Number;
}

inline
bool CPatent_priority_Base::IsSetDate(void) const
{
    return m_Date.NotEmpty();
}

inline
bool CPatent_priority_Base::CanGetDate(void) const
{
    return true;
}

inline
const CPatent_priority_Base::TDate& CPatent_priority_Base::GetDate(void) const
{
    if ( !m_Date ) {
        const_cast<CPatent_priority_Base*>(this)->ResetDate();
    }
    return (*m_Date);
}

inline
CPatent_priority_Base::TDate& CPatent_priority_Base::SetDate(void)
{
    if ( !m_Date ) {
        ResetDate();
    }
    return (*m_Date);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_BIBLIO_PATENT_PRIORITY_BASE_HPP