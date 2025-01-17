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

/// @file Dependent_field_rule_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'valid.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_VALID_DEPENDENT_FIELD_RULE_BASE_HPP
#define OBJECTS_VALID_DEPENDENT_FIELD_RULE_BASE_HPP

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
class CField_set;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_VALID_EXPORT CDependent_field_rule_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CDependent_field_rule_Base(void);
    // destructor
    virtual ~CDependent_field_rule_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TMatch_name;
    typedef string TValue_constraint;
    typedef bool TInvert_match;
    typedef CField_set TOther_fields;
    typedef CField_set TDisallowed_fields;

    // getters
    // setters

    /// mandatory
    /// typedef string TMatch_name
    ///  Check whether the Match_name data member has been assigned a value.
    bool IsSetMatch_name(void) const;
    /// Check whether it is safe or not to call GetMatch_name method.
    bool CanGetMatch_name(void) const;
    void ResetMatch_name(void);
    const TMatch_name& GetMatch_name(void) const;
    void SetMatch_name(const TMatch_name& value);
    TMatch_name& SetMatch_name(void);

    /// optional
    /// typedef string TValue_constraint
    ///  Check whether the Value_constraint data member has been assigned a value.
    bool IsSetValue_constraint(void) const;
    /// Check whether it is safe or not to call GetValue_constraint method.
    bool CanGetValue_constraint(void) const;
    void ResetValue_constraint(void);
    const TValue_constraint& GetValue_constraint(void) const;
    void SetValue_constraint(const TValue_constraint& value);
    TValue_constraint& SetValue_constraint(void);

    /// optional with default false
    /// typedef bool TInvert_match
    ///  Check whether the Invert_match data member has been assigned a value.
    bool IsSetInvert_match(void) const;
    /// Check whether it is safe or not to call GetInvert_match method.
    bool CanGetInvert_match(void) const;
    void ResetInvert_match(void);
    void SetDefaultInvert_match(void);
    TInvert_match GetInvert_match(void) const;
    void SetInvert_match(TInvert_match value);
    TInvert_match& SetInvert_match(void);

    /// optional
    /// typedef CField_set TOther_fields
    ///  Check whether the Other_fields data member has been assigned a value.
    bool IsSetOther_fields(void) const;
    /// Check whether it is safe or not to call GetOther_fields method.
    bool CanGetOther_fields(void) const;
    void ResetOther_fields(void);
    const TOther_fields& GetOther_fields(void) const;
    void SetOther_fields(TOther_fields& value);
    TOther_fields& SetOther_fields(void);

    /// optional
    /// typedef CField_set TDisallowed_fields
    ///  Check whether the Disallowed_fields data member has been assigned a value.
    bool IsSetDisallowed_fields(void) const;
    /// Check whether it is safe or not to call GetDisallowed_fields method.
    bool CanGetDisallowed_fields(void) const;
    void ResetDisallowed_fields(void);
    const TDisallowed_fields& GetDisallowed_fields(void) const;
    void SetDisallowed_fields(TDisallowed_fields& value);
    TDisallowed_fields& SetDisallowed_fields(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CDependent_field_rule_Base(const CDependent_field_rule_Base&);
    CDependent_field_rule_Base& operator=(const CDependent_field_rule_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Match_name;
    string m_Value_constraint;
    bool m_Invert_match;
    CRef< TOther_fields > m_Other_fields;
    CRef< TDisallowed_fields > m_Disallowed_fields;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CDependent_field_rule_Base::IsSetMatch_name(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CDependent_field_rule_Base::CanGetMatch_name(void) const
{
    return IsSetMatch_name();
}

inline
const CDependent_field_rule_Base::TMatch_name& CDependent_field_rule_Base::GetMatch_name(void) const
{
    if (!CanGetMatch_name()) {
        ThrowUnassigned(0);
    }
    return m_Match_name;
}

inline
void CDependent_field_rule_Base::SetMatch_name(const CDependent_field_rule_Base::TMatch_name& value)
{
    m_Match_name = value;
    m_set_State[0] |= 0x3;
}

inline
CDependent_field_rule_Base::TMatch_name& CDependent_field_rule_Base::SetMatch_name(void)
{
#ifdef _DEBUG
    if (!IsSetMatch_name()) {
        m_Match_name = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Match_name;
}

inline
bool CDependent_field_rule_Base::IsSetValue_constraint(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CDependent_field_rule_Base::CanGetValue_constraint(void) const
{
    return IsSetValue_constraint();
}

inline
const CDependent_field_rule_Base::TValue_constraint& CDependent_field_rule_Base::GetValue_constraint(void) const
{
    if (!CanGetValue_constraint()) {
        ThrowUnassigned(1);
    }
    return m_Value_constraint;
}

inline
void CDependent_field_rule_Base::SetValue_constraint(const CDependent_field_rule_Base::TValue_constraint& value)
{
    m_Value_constraint = value;
    m_set_State[0] |= 0xc;
}

inline
CDependent_field_rule_Base::TValue_constraint& CDependent_field_rule_Base::SetValue_constraint(void)
{
#ifdef _DEBUG
    if (!IsSetValue_constraint()) {
        m_Value_constraint = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Value_constraint;
}

inline
bool CDependent_field_rule_Base::IsSetInvert_match(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CDependent_field_rule_Base::CanGetInvert_match(void) const
{
    return true;
}

inline
void CDependent_field_rule_Base::ResetInvert_match(void)
{
    m_Invert_match = false;
    m_set_State[0] &= ~0x30;
}

inline
void CDependent_field_rule_Base::SetDefaultInvert_match(void)
{
    ResetInvert_match();
}

inline
CDependent_field_rule_Base::TInvert_match CDependent_field_rule_Base::GetInvert_match(void) const
{
    return m_Invert_match;
}

inline
void CDependent_field_rule_Base::SetInvert_match(CDependent_field_rule_Base::TInvert_match value)
{
    m_Invert_match = value;
    m_set_State[0] |= 0x30;
}

inline
CDependent_field_rule_Base::TInvert_match& CDependent_field_rule_Base::SetInvert_match(void)
{
#ifdef _DEBUG
    if (!IsSetInvert_match()) {
        memset(&m_Invert_match,UnassignedByte(),sizeof(m_Invert_match));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Invert_match;
}

inline
bool CDependent_field_rule_Base::IsSetOther_fields(void) const
{
    return m_Other_fields.NotEmpty();
}

inline
bool CDependent_field_rule_Base::CanGetOther_fields(void) const
{
    return IsSetOther_fields();
}

inline
const CDependent_field_rule_Base::TOther_fields& CDependent_field_rule_Base::GetOther_fields(void) const
{
    if (!CanGetOther_fields()) {
        ThrowUnassigned(3);
    }
    return (*m_Other_fields);
}

inline
bool CDependent_field_rule_Base::IsSetDisallowed_fields(void) const
{
    return m_Disallowed_fields.NotEmpty();
}

inline
bool CDependent_field_rule_Base::CanGetDisallowed_fields(void) const
{
    return IsSetDisallowed_fields();
}

inline
const CDependent_field_rule_Base::TDisallowed_fields& CDependent_field_rule_Base::GetDisallowed_fields(void) const
{
    if (!CanGetDisallowed_fields()) {
        ThrowUnassigned(4);
    }
    return (*m_Disallowed_fields);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_VALID_DEPENDENT_FIELD_RULE_BASE_HPP
