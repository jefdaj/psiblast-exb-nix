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

/// @file NaIdentity_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'varrep.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_VARREP_NAIDENTITY_BASE_HPP
#define OBJECTS_VARREP_NAIDENTITY_BASE_HPP

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
class CNtLocation;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CNaIdentity_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CNaIdentity_Base(void);
    // destructor
    virtual ~CNaIdentity_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CNtLocation TLoc;
    typedef string TNucleotide;

    // getters
    // setters

    /// mandatory
    /// typedef CNtLocation TLoc
    ///  Check whether the Loc data member has been assigned a value.
    bool IsSetLoc(void) const;
    /// Check whether it is safe or not to call GetLoc method.
    bool CanGetLoc(void) const;
    void ResetLoc(void);
    const TLoc& GetLoc(void) const;
    void SetLoc(TLoc& value);
    TLoc& SetLoc(void);

    /// optional
    /// typedef string TNucleotide
    ///  Check whether the Nucleotide data member has been assigned a value.
    bool IsSetNucleotide(void) const;
    /// Check whether it is safe or not to call GetNucleotide method.
    bool CanGetNucleotide(void) const;
    void ResetNucleotide(void);
    const TNucleotide& GetNucleotide(void) const;
    void SetNucleotide(const TNucleotide& value);
    TNucleotide& SetNucleotide(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CNaIdentity_Base(const CNaIdentity_Base&);
    CNaIdentity_Base& operator=(const CNaIdentity_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TLoc > m_Loc;
    string m_Nucleotide;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CNaIdentity_Base::IsSetLoc(void) const
{
    return m_Loc.NotEmpty();
}

inline
bool CNaIdentity_Base::CanGetLoc(void) const
{
    return true;
}

inline
const CNaIdentity_Base::TLoc& CNaIdentity_Base::GetLoc(void) const
{
    if ( !m_Loc ) {
        const_cast<CNaIdentity_Base*>(this)->ResetLoc();
    }
    return (*m_Loc);
}

inline
CNaIdentity_Base::TLoc& CNaIdentity_Base::SetLoc(void)
{
    if ( !m_Loc ) {
        ResetLoc();
    }
    return (*m_Loc);
}

inline
bool CNaIdentity_Base::IsSetNucleotide(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CNaIdentity_Base::CanGetNucleotide(void) const
{
    return IsSetNucleotide();
}

inline
const CNaIdentity_Base::TNucleotide& CNaIdentity_Base::GetNucleotide(void) const
{
    if (!CanGetNucleotide()) {
        ThrowUnassigned(1);
    }
    return m_Nucleotide;
}

inline
void CNaIdentity_Base::SetNucleotide(const CNaIdentity_Base::TNucleotide& value)
{
    m_Nucleotide = value;
    m_set_State[0] |= 0xc;
}

inline
CNaIdentity_Base::TNucleotide& CNaIdentity_Base::SetNucleotide(void)
{
#ifdef _DEBUG
    if (!IsSetNucleotide()) {
        m_Nucleotide = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Nucleotide;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_VARREP_NAIDENTITY_BASE_HPP
