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

/// @file Entrez2_hier_query_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'entrez2.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_ENTREZ2_ENTREZ2_HIER_QUERY_BASE_HPP
#define OBJECTS_ENTREZ2_ENTREZ2_HIER_QUERY_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>
#include <objects/entrez2/Entrez2_db_id.hpp>
#include <objects/entrez2/Entrez2_field_id.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_ENTREZ2_EXPORT CEntrez2_hier_query_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CEntrez2_hier_query_Base(void);
    // destructor
    virtual ~CEntrez2_hier_query_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CEntrez2_db_id TDb;
    typedef CEntrez2_field_id TField;
    typedef string TTerm;
    typedef NCBI_NS_NCBI::TEntrezId TTxid;

    // getters
    // setters

    /// mandatory
    /// typedef CEntrez2_db_id TDb
    ///  Check whether the Db data member has been assigned a value.
    bool IsSetDb(void) const;
    /// Check whether it is safe or not to call GetDb method.
    bool CanGetDb(void) const;
    void ResetDb(void);
    const TDb& GetDb(void) const;
    void SetDb(const TDb& value);
    TDb& SetDb(void);

    /// mandatory
    /// typedef CEntrez2_field_id TField
    ///  Check whether the Field data member has been assigned a value.
    bool IsSetField(void) const;
    /// Check whether it is safe or not to call GetField method.
    bool CanGetField(void) const;
    void ResetField(void);
    const TField& GetField(void) const;
    void SetField(const TField& value);
    TField& SetField(void);

    /// query with either term
    /// optional
    /// typedef string TTerm
    ///  Check whether the Term data member has been assigned a value.
    bool IsSetTerm(void) const;
    /// Check whether it is safe or not to call GetTerm method.
    bool CanGetTerm(void) const;
    void ResetTerm(void);
    const TTerm& GetTerm(void) const;
    void SetTerm(const TTerm& value);
    TTerm& SetTerm(void);

    /// or Taxonomy ID
    /// optional
    /// typedef NCBI_NS_NCBI::TEntrezId TTxid
    ///  Check whether the Txid data member has been assigned a value.
    bool IsSetTxid(void) const;
    /// Check whether it is safe or not to call GetTxid method.
    bool CanGetTxid(void) const;
    void ResetTxid(void);
    TTxid GetTxid(void) const;
    void SetTxid(TTxid value);
    TTxid& SetTxid(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CEntrez2_hier_query_Base(const CEntrez2_hier_query_Base&);
    CEntrez2_hier_query_Base& operator=(const CEntrez2_hier_query_Base&);

    // data
    Uint4 m_set_State[1];
    CEntrez2_db_id m_Db;
    CEntrez2_field_id m_Field;
    string m_Term;
    ncbi::TIntId m_Txid;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CEntrez2_hier_query_Base::IsSetDb(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CEntrez2_hier_query_Base::CanGetDb(void) const
{
    return IsSetDb();
}

inline
const CEntrez2_hier_query_Base::TDb& CEntrez2_hier_query_Base::GetDb(void) const
{
    if (!CanGetDb()) {
        ThrowUnassigned(0);
    }
    return m_Db;
}

inline
void CEntrez2_hier_query_Base::SetDb(const CEntrez2_hier_query_Base::TDb& value)
{
    m_Db = value;
    m_set_State[0] |= 0x3;
}

inline
CEntrez2_hier_query_Base::TDb& CEntrez2_hier_query_Base::SetDb(void)
{
    m_set_State[0] |= 0x1;
    return m_Db;
}

inline
bool CEntrez2_hier_query_Base::IsSetField(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CEntrez2_hier_query_Base::CanGetField(void) const
{
    return IsSetField();
}

inline
const CEntrez2_hier_query_Base::TField& CEntrez2_hier_query_Base::GetField(void) const
{
    if (!CanGetField()) {
        ThrowUnassigned(1);
    }
    return m_Field;
}

inline
void CEntrez2_hier_query_Base::SetField(const CEntrez2_hier_query_Base::TField& value)
{
    m_Field = value;
    m_set_State[0] |= 0xc;
}

inline
CEntrez2_hier_query_Base::TField& CEntrez2_hier_query_Base::SetField(void)
{
    m_set_State[0] |= 0x4;
    return m_Field;
}

inline
bool CEntrez2_hier_query_Base::IsSetTerm(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CEntrez2_hier_query_Base::CanGetTerm(void) const
{
    return IsSetTerm();
}

inline
const CEntrez2_hier_query_Base::TTerm& CEntrez2_hier_query_Base::GetTerm(void) const
{
    if (!CanGetTerm()) {
        ThrowUnassigned(2);
    }
    return m_Term;
}

inline
void CEntrez2_hier_query_Base::SetTerm(const CEntrez2_hier_query_Base::TTerm& value)
{
    m_Term = value;
    m_set_State[0] |= 0x30;
}

inline
CEntrez2_hier_query_Base::TTerm& CEntrez2_hier_query_Base::SetTerm(void)
{
#ifdef _DEBUG
    if (!IsSetTerm()) {
        m_Term = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Term;
}

inline
bool CEntrez2_hier_query_Base::IsSetTxid(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CEntrez2_hier_query_Base::CanGetTxid(void) const
{
    return IsSetTxid();
}

inline
void CEntrez2_hier_query_Base::ResetTxid(void)
{
    m_Txid = 0;
    m_set_State[0] &= ~0xc0;
}

inline
CEntrez2_hier_query_Base::TTxid CEntrez2_hier_query_Base::GetTxid(void) const
{
    if (!CanGetTxid()) {
        ThrowUnassigned(3);
    }
    return reinterpret_cast<const TTxid&>(m_Txid);
}

inline
void CEntrez2_hier_query_Base::SetTxid(CEntrez2_hier_query_Base::TTxid value)
{
    reinterpret_cast<TTxid&>(m_Txid) = value;
    m_set_State[0] |= 0xc0;
}

inline
CEntrez2_hier_query_Base::TTxid& CEntrez2_hier_query_Base::SetTxid(void)
{
#ifdef _DEBUG
    if (!IsSetTxid()) {
        memset(&m_Txid,UnassignedByte(),sizeof(m_Txid));
    }
#endif
    m_set_State[0] |= 0x40;
    return reinterpret_cast<TTxid&>(m_Txid);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ENTREZ2_ENTREZ2_HIER_QUERY_BASE_HPP