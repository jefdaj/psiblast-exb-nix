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

/// @file CDSGenePro_qual_constraint_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MACRO_CDSGENEPRO_QUAL_CONSTRAINT_BASE_HPP
#define OBJECTS_MACRO_CDSGENEPRO_QUAL_CONSTRAINT_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CCDSGeneProt_constraint_field;
class CString_constraint;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CCDSGeneProt_qual_constraint_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CCDSGeneProt_qual_constraint_Base(void);
    // destructor
    virtual ~CCDSGeneProt_qual_constraint_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CCDSGeneProt_constraint_field TField1;
    typedef CCDSGeneProt_constraint_field TField2;
    typedef CString_constraint TConstraint;

    // getters
    // setters

    /// optional
    /// typedef CCDSGeneProt_constraint_field TField1
    ///  Check whether the Field1 data member has been assigned a value.
    bool IsSetField1(void) const;
    /// Check whether it is safe or not to call GetField1 method.
    bool CanGetField1(void) const;
    void ResetField1(void);
    const TField1& GetField1(void) const;
    void SetField1(TField1& value);
    TField1& SetField1(void);

    /// optional
    /// typedef CCDSGeneProt_constraint_field TField2
    ///  Check whether the Field2 data member has been assigned a value.
    bool IsSetField2(void) const;
    /// Check whether it is safe or not to call GetField2 method.
    bool CanGetField2(void) const;
    void ResetField2(void);
    const TField2& GetField2(void) const;
    void SetField2(TField2& value);
    TField2& SetField2(void);

    /// optional
    /// typedef CString_constraint TConstraint
    ///  Check whether the Constraint data member has been assigned a value.
    bool IsSetConstraint(void) const;
    /// Check whether it is safe or not to call GetConstraint method.
    bool CanGetConstraint(void) const;
    void ResetConstraint(void);
    const TConstraint& GetConstraint(void) const;
    void SetConstraint(TConstraint& value);
    TConstraint& SetConstraint(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CCDSGeneProt_qual_constraint_Base(const CCDSGeneProt_qual_constraint_Base&);
    CCDSGeneProt_qual_constraint_Base& operator=(const CCDSGeneProt_qual_constraint_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TField1 > m_Field1;
    CRef< TField2 > m_Field2;
    CRef< TConstraint > m_Constraint;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CCDSGeneProt_qual_constraint_Base::IsSetField1(void) const
{
    return m_Field1.NotEmpty();
}

inline
bool CCDSGeneProt_qual_constraint_Base::CanGetField1(void) const
{
    return IsSetField1();
}

inline
const CCDSGeneProt_qual_constraint_Base::TField1& CCDSGeneProt_qual_constraint_Base::GetField1(void) const
{
    if (!CanGetField1()) {
        ThrowUnassigned(0);
    }
    return (*m_Field1);
}

inline
bool CCDSGeneProt_qual_constraint_Base::IsSetField2(void) const
{
    return m_Field2.NotEmpty();
}

inline
bool CCDSGeneProt_qual_constraint_Base::CanGetField2(void) const
{
    return IsSetField2();
}

inline
const CCDSGeneProt_qual_constraint_Base::TField2& CCDSGeneProt_qual_constraint_Base::GetField2(void) const
{
    if (!CanGetField2()) {
        ThrowUnassigned(1);
    }
    return (*m_Field2);
}

inline
bool CCDSGeneProt_qual_constraint_Base::IsSetConstraint(void) const
{
    return m_Constraint.NotEmpty();
}

inline
bool CCDSGeneProt_qual_constraint_Base::CanGetConstraint(void) const
{
    return IsSetConstraint();
}

inline
const CCDSGeneProt_qual_constraint_Base::TConstraint& CCDSGeneProt_qual_constraint_Base::GetConstraint(void) const
{
    if (!CanGetConstraint()) {
        ThrowUnassigned(2);
    }
    return (*m_Constraint);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_CDSGENEPRO_QUAL_CONSTRAINT_BASE_HPP