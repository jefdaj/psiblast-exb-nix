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

/// @file TMgr_ClientInfo_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'trackmgr.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_TRACKMGR_TMGR_CLIENTINFO_BASE_HPP
#define OBJECTS_TRACKMGR_TMGR_CLIENTINFO_BASE_HPP

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


// forward declarations
class CTMgr_AttrSpec;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_TRACKMGR_EXPORT CTMgr_ClientInfo_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CTMgr_ClientInfo_Base(void);
    // destructor
    virtual ~CTMgr_ClientInfo_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TClient_name;
    typedef string TContext;
    typedef bool TInhouse;
    typedef list< CRef< CTMgr_AttrSpec > > TContext_attrs;

    // getters
    // setters

    /// mandatory
    /// typedef string TClient_name
    ///  Check whether the Client_name data member has been assigned a value.
    bool IsSetClient_name(void) const;
    /// Check whether it is safe or not to call GetClient_name method.
    bool CanGetClient_name(void) const;
    void ResetClient_name(void);
    const TClient_name& GetClient_name(void) const;
    void SetClient_name(const TClient_name& value);
    TClient_name& SetClient_name(void);

    /// optional
    /// typedef string TContext
    ///  Check whether the Context data member has been assigned a value.
    bool IsSetContext(void) const;
    /// Check whether it is safe or not to call GetContext method.
    bool CanGetContext(void) const;
    void ResetContext(void);
    const TContext& GetContext(void) const;
    void SetContext(const TContext& value);
    TContext& SetContext(void);

    /// optional with default false
    /// typedef bool TInhouse
    ///  Check whether the Inhouse data member has been assigned a value.
    bool IsSetInhouse(void) const;
    /// Check whether it is safe or not to call GetInhouse method.
    bool CanGetInhouse(void) const;
    void ResetInhouse(void);
    void SetDefaultInhouse(void);
    TInhouse GetInhouse(void) const;
    void SetInhouse(TInhouse value);
    TInhouse& SetInhouse(void);

    ///permission keys etc
    /// optional
    /// typedef list< CRef< CTMgr_AttrSpec > > TContext_attrs
    ///  Check whether the Context_attrs data member has been assigned a value.
    bool IsSetContext_attrs(void) const;
    /// Check whether it is safe or not to call GetContext_attrs method.
    bool CanGetContext_attrs(void) const;
    void ResetContext_attrs(void);
    const TContext_attrs& GetContext_attrs(void) const;
    TContext_attrs& SetContext_attrs(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CTMgr_ClientInfo_Base(const CTMgr_ClientInfo_Base&);
    CTMgr_ClientInfo_Base& operator=(const CTMgr_ClientInfo_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Client_name;
    string m_Context;
    bool m_Inhouse;
    list< CRef< CTMgr_AttrSpec > > m_Context_attrs;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CTMgr_ClientInfo_Base::IsSetClient_name(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CTMgr_ClientInfo_Base::CanGetClient_name(void) const
{
    return IsSetClient_name();
}

inline
const CTMgr_ClientInfo_Base::TClient_name& CTMgr_ClientInfo_Base::GetClient_name(void) const
{
    if (!CanGetClient_name()) {
        ThrowUnassigned(0);
    }
    return m_Client_name;
}

inline
void CTMgr_ClientInfo_Base::SetClient_name(const CTMgr_ClientInfo_Base::TClient_name& value)
{
    m_Client_name = value;
    m_set_State[0] |= 0x3;
}

inline
CTMgr_ClientInfo_Base::TClient_name& CTMgr_ClientInfo_Base::SetClient_name(void)
{
#ifdef _DEBUG
    if (!IsSetClient_name()) {
        m_Client_name = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Client_name;
}

inline
bool CTMgr_ClientInfo_Base::IsSetContext(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CTMgr_ClientInfo_Base::CanGetContext(void) const
{
    return IsSetContext();
}

inline
const CTMgr_ClientInfo_Base::TContext& CTMgr_ClientInfo_Base::GetContext(void) const
{
    if (!CanGetContext()) {
        ThrowUnassigned(1);
    }
    return m_Context;
}

inline
void CTMgr_ClientInfo_Base::SetContext(const CTMgr_ClientInfo_Base::TContext& value)
{
    m_Context = value;
    m_set_State[0] |= 0xc;
}

inline
CTMgr_ClientInfo_Base::TContext& CTMgr_ClientInfo_Base::SetContext(void)
{
#ifdef _DEBUG
    if (!IsSetContext()) {
        m_Context = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Context;
}

inline
bool CTMgr_ClientInfo_Base::IsSetInhouse(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CTMgr_ClientInfo_Base::CanGetInhouse(void) const
{
    return true;
}

inline
void CTMgr_ClientInfo_Base::ResetInhouse(void)
{
    m_Inhouse = false;
    m_set_State[0] &= ~0x30;
}

inline
void CTMgr_ClientInfo_Base::SetDefaultInhouse(void)
{
    ResetInhouse();
}

inline
CTMgr_ClientInfo_Base::TInhouse CTMgr_ClientInfo_Base::GetInhouse(void) const
{
    return m_Inhouse;
}

inline
void CTMgr_ClientInfo_Base::SetInhouse(CTMgr_ClientInfo_Base::TInhouse value)
{
    m_Inhouse = value;
    m_set_State[0] |= 0x30;
}

inline
CTMgr_ClientInfo_Base::TInhouse& CTMgr_ClientInfo_Base::SetInhouse(void)
{
#ifdef _DEBUG
    if (!IsSetInhouse()) {
        memset(&m_Inhouse,UnassignedByte(),sizeof(m_Inhouse));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Inhouse;
}

inline
bool CTMgr_ClientInfo_Base::IsSetContext_attrs(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CTMgr_ClientInfo_Base::CanGetContext_attrs(void) const
{
    return true;
}

inline
const CTMgr_ClientInfo_Base::TContext_attrs& CTMgr_ClientInfo_Base::GetContext_attrs(void) const
{
    return m_Context_attrs;
}

inline
CTMgr_ClientInfo_Base::TContext_attrs& CTMgr_ClientInfo_Base::SetContext_attrs(void)
{
    m_set_State[0] |= 0x40;
    return m_Context_attrs;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_TRACKMGR_TMGR_CLIENTINFO_BASE_HPP
