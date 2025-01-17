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

/// @file Prot_ref_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqfeat.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQFEAT_PROT_REF_BASE_HPP
#define OBJECTS_SEQFEAT_PROT_REF_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>
#include <vector>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CDbtag;


// generated classes

/////////////////////////////////////////////////////////////////////////////
///*** Prot-ref ***********************************************
///*
///*  Reference to a protein name
///*
class NCBI_SEQFEAT_EXPORT CProt_ref_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CProt_ref_Base(void);
    // destructor
    virtual ~CProt_ref_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /// processing status
    enum EProcessed {
        eProcessed_not_set         = 0,
        eProcessed_preprotein      = 1,
        eProcessed_mature          = 2,
        eProcessed_signal_peptide  = 3,
        eProcessed_transit_peptide = 4,
        eProcessed_propeptide      = 5
    };
    
    /// Access to EProcessed's attributes (values, names) as defined in spec
    static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EProcessed)(void);
    
    // types
    typedef list< string > TName;
    typedef string TDesc;
    typedef list< string > TEc;
    typedef list< string > TActivity;
    typedef vector< CRef< CDbtag > > TDb;
    typedef EProcessed TProcessed;

    // getters
    // setters

    /// protein name
    /// optional
    /// typedef list< string > TName
    ///  Check whether the Name data member has been assigned a value.
    bool IsSetName(void) const;
    /// Check whether it is safe or not to call GetName method.
    bool CanGetName(void) const;
    void ResetName(void);
    const TName& GetName(void) const;
    TName& SetName(void);

    /// description (instead of name)
    /// optional
    /// typedef string TDesc
    ///  Check whether the Desc data member has been assigned a value.
    bool IsSetDesc(void) const;
    /// Check whether it is safe or not to call GetDesc method.
    bool CanGetDesc(void) const;
    void ResetDesc(void);
    const TDesc& GetDesc(void) const;
    void SetDesc(const TDesc& value);
    TDesc& SetDesc(void);

    /// E.C. number(s)
    /// optional
    /// typedef list< string > TEc
    ///  Check whether the Ec data member has been assigned a value.
    bool IsSetEc(void) const;
    /// Check whether it is safe or not to call GetEc method.
    bool CanGetEc(void) const;
    void ResetEc(void);
    const TEc& GetEc(void) const;
    TEc& SetEc(void);

    /// activities
    /// optional
    /// typedef list< string > TActivity
    ///  Check whether the Activity data member has been assigned a value.
    bool IsSetActivity(void) const;
    /// Check whether it is safe or not to call GetActivity method.
    bool CanGetActivity(void) const;
    void ResetActivity(void);
    const TActivity& GetActivity(void) const;
    TActivity& SetActivity(void);

    /// ids in other dbases
    /// optional
    /// typedef vector< CRef< CDbtag > > TDb
    ///  Check whether the Db data member has been assigned a value.
    bool IsSetDb(void) const;
    /// Check whether it is safe or not to call GetDb method.
    bool CanGetDb(void) const;
    void ResetDb(void);
    const TDb& GetDb(void) const;
    TDb& SetDb(void);

    /// optional with default eProcessed_not_set
    /// typedef EProcessed TProcessed
    ///  Check whether the Processed data member has been assigned a value.
    bool IsSetProcessed(void) const;
    /// Check whether it is safe or not to call GetProcessed method.
    bool CanGetProcessed(void) const;
    void ResetProcessed(void);
    void SetDefaultProcessed(void);
    TProcessed GetProcessed(void) const;
    void SetProcessed(TProcessed value);
    TProcessed& SetProcessed(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CProt_ref_Base(const CProt_ref_Base&);
    CProt_ref_Base& operator=(const CProt_ref_Base&);

    // data
    Uint4 m_set_State[1];
    list< string > m_Name;
    string m_Desc;
    list< string > m_Ec;
    list< string > m_Activity;
    vector< CRef< CDbtag > > m_Db;
    EProcessed m_Processed;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CProt_ref_Base::IsSetName(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CProt_ref_Base::CanGetName(void) const
{
    return true;
}

inline
const CProt_ref_Base::TName& CProt_ref_Base::GetName(void) const
{
    return m_Name;
}

inline
CProt_ref_Base::TName& CProt_ref_Base::SetName(void)
{
    m_set_State[0] |= 0x1;
    return m_Name;
}

inline
bool CProt_ref_Base::IsSetDesc(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CProt_ref_Base::CanGetDesc(void) const
{
    return IsSetDesc();
}

inline
const CProt_ref_Base::TDesc& CProt_ref_Base::GetDesc(void) const
{
    if (!CanGetDesc()) {
        ThrowUnassigned(1);
    }
    return m_Desc;
}

inline
void CProt_ref_Base::SetDesc(const CProt_ref_Base::TDesc& value)
{
    m_Desc = value;
    m_set_State[0] |= 0xc;
}

inline
CProt_ref_Base::TDesc& CProt_ref_Base::SetDesc(void)
{
#ifdef _DEBUG
    if (!IsSetDesc()) {
        m_Desc = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Desc;
}

inline
bool CProt_ref_Base::IsSetEc(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CProt_ref_Base::CanGetEc(void) const
{
    return true;
}

inline
const CProt_ref_Base::TEc& CProt_ref_Base::GetEc(void) const
{
    return m_Ec;
}

inline
CProt_ref_Base::TEc& CProt_ref_Base::SetEc(void)
{
    m_set_State[0] |= 0x10;
    return m_Ec;
}

inline
bool CProt_ref_Base::IsSetActivity(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CProt_ref_Base::CanGetActivity(void) const
{
    return true;
}

inline
const CProt_ref_Base::TActivity& CProt_ref_Base::GetActivity(void) const
{
    return m_Activity;
}

inline
CProt_ref_Base::TActivity& CProt_ref_Base::SetActivity(void)
{
    m_set_State[0] |= 0x40;
    return m_Activity;
}

inline
bool CProt_ref_Base::IsSetDb(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CProt_ref_Base::CanGetDb(void) const
{
    return true;
}

inline
const CProt_ref_Base::TDb& CProt_ref_Base::GetDb(void) const
{
    return m_Db;
}

inline
CProt_ref_Base::TDb& CProt_ref_Base::SetDb(void)
{
    m_set_State[0] |= 0x100;
    return m_Db;
}

inline
bool CProt_ref_Base::IsSetProcessed(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CProt_ref_Base::CanGetProcessed(void) const
{
    return true;
}

inline
void CProt_ref_Base::ResetProcessed(void)
{
    m_Processed = eProcessed_not_set;
    m_set_State[0] &= ~0xc00;
}

inline
void CProt_ref_Base::SetDefaultProcessed(void)
{
    ResetProcessed();
}

inline
CProt_ref_Base::TProcessed CProt_ref_Base::GetProcessed(void) const
{
    return m_Processed;
}

inline
void CProt_ref_Base::SetProcessed(CProt_ref_Base::TProcessed value)
{
    m_Processed = value;
    m_set_State[0] |= 0xc00;
}

inline
CProt_ref_Base::TProcessed& CProt_ref_Base::SetProcessed(void)
{
#ifdef _DEBUG
    if (!IsSetProcessed()) {
        memset(&m_Processed,UnassignedByte(),sizeof(m_Processed));
    }
#endif
    m_set_State[0] |= 0x400;
    return m_Processed;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQFEAT_PROT_REF_BASE_HPP
