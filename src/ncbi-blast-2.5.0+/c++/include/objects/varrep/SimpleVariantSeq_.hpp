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

/// @file SimpleVariantSeq_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'varrep.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_VARREP_SIMPLEVARIANTSEQ_BASE_HPP
#define OBJECTS_VARREP_SIMPLEVARIANTSEQ_BASE_HPP

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
class CSimpleVariant;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// SimpleVarSeq is deprecated and should go
class CSimpleVariantSeq_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CSimpleVariantSeq_Base(void);
    // destructor
    virtual ~CSimpleVariantSeq_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef list< CRef< CSimpleVariant > > TVariants;
    typedef bool TSisters;
    typedef bool TFuzzy;

    // getters
    // setters

    /// mandatory
    /// typedef list< CRef< CSimpleVariant > > TVariants
    ///  Check whether the Variants data member has been assigned a value.
    bool IsSetVariants(void) const;
    /// Check whether it is safe or not to call GetVariants method.
    bool CanGetVariants(void) const;
    void ResetVariants(void);
    const TVariants& GetVariants(void) const;
    TVariants& SetVariants(void);

    /// optional with default false
    /// typedef bool TSisters
    ///  Check whether the Sisters data member has been assigned a value.
    bool IsSetSisters(void) const;
    /// Check whether it is safe or not to call GetSisters method.
    bool CanGetSisters(void) const;
    void ResetSisters(void);
    void SetDefaultSisters(void);
    TSisters GetSisters(void) const;
    void SetSisters(TSisters value);
    TSisters& SetSisters(void);

    /// optional with default false
    /// typedef bool TFuzzy
    ///  Check whether the Fuzzy data member has been assigned a value.
    bool IsSetFuzzy(void) const;
    /// Check whether it is safe or not to call GetFuzzy method.
    bool CanGetFuzzy(void) const;
    void ResetFuzzy(void);
    void SetDefaultFuzzy(void);
    TFuzzy GetFuzzy(void) const;
    void SetFuzzy(TFuzzy value);
    TFuzzy& SetFuzzy(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CSimpleVariantSeq_Base(const CSimpleVariantSeq_Base&);
    CSimpleVariantSeq_Base& operator=(const CSimpleVariantSeq_Base&);

    // data
    Uint4 m_set_State[1];
    list< CRef< CSimpleVariant > > m_Variants;
    bool m_Sisters;
    bool m_Fuzzy;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CSimpleVariantSeq_Base::IsSetVariants(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CSimpleVariantSeq_Base::CanGetVariants(void) const
{
    return true;
}

inline
const CSimpleVariantSeq_Base::TVariants& CSimpleVariantSeq_Base::GetVariants(void) const
{
    return m_Variants;
}

inline
CSimpleVariantSeq_Base::TVariants& CSimpleVariantSeq_Base::SetVariants(void)
{
    m_set_State[0] |= 0x1;
    return m_Variants;
}

inline
bool CSimpleVariantSeq_Base::IsSetSisters(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CSimpleVariantSeq_Base::CanGetSisters(void) const
{
    return true;
}

inline
void CSimpleVariantSeq_Base::ResetSisters(void)
{
    m_Sisters = false;
    m_set_State[0] &= ~0xc;
}

inline
void CSimpleVariantSeq_Base::SetDefaultSisters(void)
{
    ResetSisters();
}

inline
CSimpleVariantSeq_Base::TSisters CSimpleVariantSeq_Base::GetSisters(void) const
{
    return m_Sisters;
}

inline
void CSimpleVariantSeq_Base::SetSisters(CSimpleVariantSeq_Base::TSisters value)
{
    m_Sisters = value;
    m_set_State[0] |= 0xc;
}

inline
CSimpleVariantSeq_Base::TSisters& CSimpleVariantSeq_Base::SetSisters(void)
{
#ifdef _DEBUG
    if (!IsSetSisters()) {
        memset(&m_Sisters,UnassignedByte(),sizeof(m_Sisters));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Sisters;
}

inline
bool CSimpleVariantSeq_Base::IsSetFuzzy(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CSimpleVariantSeq_Base::CanGetFuzzy(void) const
{
    return true;
}

inline
void CSimpleVariantSeq_Base::ResetFuzzy(void)
{
    m_Fuzzy = false;
    m_set_State[0] &= ~0x30;
}

inline
void CSimpleVariantSeq_Base::SetDefaultFuzzy(void)
{
    ResetFuzzy();
}

inline
CSimpleVariantSeq_Base::TFuzzy CSimpleVariantSeq_Base::GetFuzzy(void) const
{
    return m_Fuzzy;
}

inline
void CSimpleVariantSeq_Base::SetFuzzy(CSimpleVariantSeq_Base::TFuzzy value)
{
    m_Fuzzy = value;
    m_set_State[0] |= 0x30;
}

inline
CSimpleVariantSeq_Base::TFuzzy& CSimpleVariantSeq_Base::SetFuzzy(void)
{
#ifdef _DEBUG
    if (!IsSetFuzzy()) {
        memset(&m_Fuzzy,UnassignedByte(),sizeof(m_Fuzzy));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Fuzzy;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_VARREP_SIMPLEVARIANTSEQ_BASE_HPP