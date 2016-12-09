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

/// @file Update_sequences_action_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MACRO_UPDATE_SEQUENCES_ACTION_BASE_HPP
#define OBJECTS_MACRO_UPDATE_SEQUENCES_ACTION_BASE_HPP

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


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CUpdate_sequences_action_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CUpdate_sequences_action_Base(void);
    // destructor
    virtual ~CUpdate_sequences_action_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TFilename;
    typedef bool TAdd_cit_subs;

    // getters
    // setters

    /// mandatory
    /// typedef string TFilename
    ///  Check whether the Filename data member has been assigned a value.
    bool IsSetFilename(void) const;
    /// Check whether it is safe or not to call GetFilename method.
    bool CanGetFilename(void) const;
    void ResetFilename(void);
    const TFilename& GetFilename(void) const;
    void SetFilename(const TFilename& value);
    TFilename& SetFilename(void);

    /// optional with default false
    /// typedef bool TAdd_cit_subs
    ///  Check whether the Add_cit_subs data member has been assigned a value.
    bool IsSetAdd_cit_subs(void) const;
    /// Check whether it is safe or not to call GetAdd_cit_subs method.
    bool CanGetAdd_cit_subs(void) const;
    void ResetAdd_cit_subs(void);
    void SetDefaultAdd_cit_subs(void);
    TAdd_cit_subs GetAdd_cit_subs(void) const;
    void SetAdd_cit_subs(TAdd_cit_subs value);
    TAdd_cit_subs& SetAdd_cit_subs(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CUpdate_sequences_action_Base(const CUpdate_sequences_action_Base&);
    CUpdate_sequences_action_Base& operator=(const CUpdate_sequences_action_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Filename;
    bool m_Add_cit_subs;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CUpdate_sequences_action_Base::IsSetFilename(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CUpdate_sequences_action_Base::CanGetFilename(void) const
{
    return IsSetFilename();
}

inline
const CUpdate_sequences_action_Base::TFilename& CUpdate_sequences_action_Base::GetFilename(void) const
{
    if (!CanGetFilename()) {
        ThrowUnassigned(0);
    }
    return m_Filename;
}

inline
void CUpdate_sequences_action_Base::SetFilename(const CUpdate_sequences_action_Base::TFilename& value)
{
    m_Filename = value;
    m_set_State[0] |= 0x3;
}

inline
CUpdate_sequences_action_Base::TFilename& CUpdate_sequences_action_Base::SetFilename(void)
{
#ifdef _DEBUG
    if (!IsSetFilename()) {
        m_Filename = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Filename;
}

inline
bool CUpdate_sequences_action_Base::IsSetAdd_cit_subs(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CUpdate_sequences_action_Base::CanGetAdd_cit_subs(void) const
{
    return true;
}

inline
void CUpdate_sequences_action_Base::ResetAdd_cit_subs(void)
{
    m_Add_cit_subs = false;
    m_set_State[0] &= ~0xc;
}

inline
void CUpdate_sequences_action_Base::SetDefaultAdd_cit_subs(void)
{
    ResetAdd_cit_subs();
}

inline
CUpdate_sequences_action_Base::TAdd_cit_subs CUpdate_sequences_action_Base::GetAdd_cit_subs(void) const
{
    return m_Add_cit_subs;
}

inline
void CUpdate_sequences_action_Base::SetAdd_cit_subs(CUpdate_sequences_action_Base::TAdd_cit_subs value)
{
    m_Add_cit_subs = value;
    m_set_State[0] |= 0xc;
}

inline
CUpdate_sequences_action_Base::TAdd_cit_subs& CUpdate_sequences_action_Base::SetAdd_cit_subs(void)
{
#ifdef _DEBUG
    if (!IsSetAdd_cit_subs()) {
        memset(&m_Add_cit_subs,UnassignedByte(),sizeof(m_Add_cit_subs));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Add_cit_subs;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_UPDATE_SEQUENCES_ACTION_BASE_HPP