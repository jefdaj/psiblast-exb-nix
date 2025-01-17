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

/// @file Scaled_real_multi_data_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqtable.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQTABLE_SCALED_REAL_MULTI_DATA_BASE_HPP
#define OBJECTS_SEQTABLE_SCALED_REAL_MULTI_DATA_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CSeqTable_multi_data;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_SEQ_EXPORT CScaled_real_multi_data_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CScaled_real_multi_data_Base(void);
    // destructor
    virtual ~CScaled_real_multi_data_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef double TMul;
    typedef double TAdd;
    typedef CSeqTable_multi_data TData;

    // getters
    // setters

    /// output data[i] = data[i]*mul+add
    /// mandatory
    /// typedef double TMul
    ///  Check whether the Mul data member has been assigned a value.
    bool IsSetMul(void) const;
    /// Check whether it is safe or not to call GetMul method.
    bool CanGetMul(void) const;
    void ResetMul(void);
    TMul GetMul(void) const;
    void SetMul(TMul value);
    TMul& SetMul(void);

    /// mandatory
    /// typedef double TAdd
    ///  Check whether the Add data member has been assigned a value.
    bool IsSetAdd(void) const;
    /// Check whether it is safe or not to call GetAdd method.
    bool CanGetAdd(void) const;
    void ResetAdd(void);
    TAdd GetAdd(void) const;
    void SetAdd(TAdd value);
    TAdd& SetAdd(void);

    /// mandatory
    /// typedef CSeqTable_multi_data TData
    ///  Check whether the Data data member has been assigned a value.
    bool IsSetData(void) const;
    /// Check whether it is safe or not to call GetData method.
    bool CanGetData(void) const;
    void ResetData(void);
    const TData& GetData(void) const;
    void SetData(TData& value);
    TData& SetData(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CScaled_real_multi_data_Base(const CScaled_real_multi_data_Base&);
    CScaled_real_multi_data_Base& operator=(const CScaled_real_multi_data_Base&);

    // data
    Uint4 m_set_State[1];
    double m_Mul;
    double m_Add;
    CRef< TData > m_Data;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CScaled_real_multi_data_Base::IsSetMul(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CScaled_real_multi_data_Base::CanGetMul(void) const
{
    return IsSetMul();
}

inline
void CScaled_real_multi_data_Base::ResetMul(void)
{
    m_Mul = 0;
    m_set_State[0] &= ~0x3;
}

inline
CScaled_real_multi_data_Base::TMul CScaled_real_multi_data_Base::GetMul(void) const
{
    if (!CanGetMul()) {
        ThrowUnassigned(0);
    }
    return m_Mul;
}

inline
void CScaled_real_multi_data_Base::SetMul(CScaled_real_multi_data_Base::TMul value)
{
    m_Mul = value;
    m_set_State[0] |= 0x3;
}

inline
CScaled_real_multi_data_Base::TMul& CScaled_real_multi_data_Base::SetMul(void)
{
#ifdef _DEBUG
    if (!IsSetMul()) {
        memset(&m_Mul,UnassignedByte(),sizeof(m_Mul));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Mul;
}

inline
bool CScaled_real_multi_data_Base::IsSetAdd(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CScaled_real_multi_data_Base::CanGetAdd(void) const
{
    return IsSetAdd();
}

inline
void CScaled_real_multi_data_Base::ResetAdd(void)
{
    m_Add = 0;
    m_set_State[0] &= ~0xc;
}

inline
CScaled_real_multi_data_Base::TAdd CScaled_real_multi_data_Base::GetAdd(void) const
{
    if (!CanGetAdd()) {
        ThrowUnassigned(1);
    }
    return m_Add;
}

inline
void CScaled_real_multi_data_Base::SetAdd(CScaled_real_multi_data_Base::TAdd value)
{
    m_Add = value;
    m_set_State[0] |= 0xc;
}

inline
CScaled_real_multi_data_Base::TAdd& CScaled_real_multi_data_Base::SetAdd(void)
{
#ifdef _DEBUG
    if (!IsSetAdd()) {
        memset(&m_Add,UnassignedByte(),sizeof(m_Add));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Add;
}

inline
bool CScaled_real_multi_data_Base::IsSetData(void) const
{
    return m_Data.NotEmpty();
}

inline
bool CScaled_real_multi_data_Base::CanGetData(void) const
{
    return true;
}

inline
const CScaled_real_multi_data_Base::TData& CScaled_real_multi_data_Base::GetData(void) const
{
    if ( !m_Data ) {
        const_cast<CScaled_real_multi_data_Base*>(this)->ResetData();
    }
    return (*m_Data);
}

inline
CScaled_real_multi_data_Base::TData& CScaled_real_multi_data_Base::SetData(void)
{
    if ( !m_Data ) {
        ResetData();
    }
    return (*m_Data);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQTABLE_SCALED_REAL_MULTI_DATA_BASE_HPP
