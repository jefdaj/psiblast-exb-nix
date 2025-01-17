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

/// @file Gene_track_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'entrezgene.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_ENTREZGENE_GENE_TRACK_BASE_HPP
#define OBJECTS_ENTREZGENE_GENE_TRACK_BASE_HPP

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
class CDate;
class CDbtag;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_ENTREZGENE_EXPORT CGene_track_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CGene_track_Base(void);
    // destructor
    virtual ~CGene_track_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    enum EStatus {
        eStatus_live         = 0,
        eStatus_secondary    = 1,  ///< synonym with merged
        eStatus_discontinued = 2  ///< 'deleted', still index and display to public
    };
    
    /// Access to EStatus's attributes (values, names) as defined in spec
    static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EStatus)(void);
    
    // types
    typedef int TGeneid;
    typedef int TStatus;
    typedef list< CRef< CDbtag > > TCurrent_id;
    typedef CDate TCreate_date;
    typedef CDate TUpdate_date;
    typedef CDate TDiscontinue_date;

    // getters
    // setters

    /// required unique document id 
    /// mandatory
    /// typedef int TGeneid
    ///  Check whether the Geneid data member has been assigned a value.
    bool IsSetGeneid(void) const;
    /// Check whether it is safe or not to call GetGeneid method.
    bool CanGetGeneid(void) const;
    void ResetGeneid(void);
    TGeneid GetGeneid(void) const;
    void SetGeneid(TGeneid value);
    TGeneid& SetGeneid(void);

    /// optional with default eStatus_live
    /// typedef int TStatus
    ///  Check whether the Status data member has been assigned a value.
    bool IsSetStatus(void) const;
    /// Check whether it is safe or not to call GetStatus method.
    bool CanGetStatus(void) const;
    void ResetStatus(void);
    void SetDefaultStatus(void);
    TStatus GetStatus(void) const;
    void SetStatus(TStatus value);
    TStatus& SetStatus(void);

    /// see note 1 below
    /// optional
    /// typedef list< CRef< CDbtag > > TCurrent_id
    ///  Check whether the Current_id data member has been assigned a value.
    bool IsSetCurrent_id(void) const;
    /// Check whether it is safe or not to call GetCurrent_id method.
    bool CanGetCurrent_id(void) const;
    void ResetCurrent_id(void);
    const TCurrent_id& GetCurrent_id(void) const;
    TCurrent_id& SetCurrent_id(void);

    /// date created in Entrez 
    /// mandatory
    /// typedef CDate TCreate_date
    ///  Check whether the Create_date data member has been assigned a value.
    bool IsSetCreate_date(void) const;
    /// Check whether it is safe or not to call GetCreate_date method.
    bool CanGetCreate_date(void) const;
    void ResetCreate_date(void);
    const TCreate_date& GetCreate_date(void) const;
    void SetCreate_date(TCreate_date& value);
    TCreate_date& SetCreate_date(void);

    /// last date updated in Entrez 
    /// mandatory
    /// typedef CDate TUpdate_date
    ///  Check whether the Update_date data member has been assigned a value.
    bool IsSetUpdate_date(void) const;
    /// Check whether it is safe or not to call GetUpdate_date method.
    bool CanGetUpdate_date(void) const;
    void ResetUpdate_date(void);
    const TUpdate_date& GetUpdate_date(void) const;
    void SetUpdate_date(TUpdate_date& value);
    TUpdate_date& SetUpdate_date(void);

    ///
    /// optional
    /// typedef CDate TDiscontinue_date
    ///  Check whether the Discontinue_date data member has been assigned a value.
    bool IsSetDiscontinue_date(void) const;
    /// Check whether it is safe or not to call GetDiscontinue_date method.
    bool CanGetDiscontinue_date(void) const;
    void ResetDiscontinue_date(void);
    const TDiscontinue_date& GetDiscontinue_date(void) const;
    void SetDiscontinue_date(TDiscontinue_date& value);
    TDiscontinue_date& SetDiscontinue_date(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CGene_track_Base(const CGene_track_Base&);
    CGene_track_Base& operator=(const CGene_track_Base&);

    // data
    Uint4 m_set_State[1];
    int m_Geneid;
    int m_Status;
    list< CRef< CDbtag > > m_Current_id;
    CRef< TCreate_date > m_Create_date;
    CRef< TUpdate_date > m_Update_date;
    CRef< TDiscontinue_date > m_Discontinue_date;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CGene_track_Base::IsSetGeneid(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CGene_track_Base::CanGetGeneid(void) const
{
    return IsSetGeneid();
}

inline
void CGene_track_Base::ResetGeneid(void)
{
    m_Geneid = 0;
    m_set_State[0] &= ~0x3;
}

inline
CGene_track_Base::TGeneid CGene_track_Base::GetGeneid(void) const
{
    if (!CanGetGeneid()) {
        ThrowUnassigned(0);
    }
    return m_Geneid;
}

inline
void CGene_track_Base::SetGeneid(CGene_track_Base::TGeneid value)
{
    m_Geneid = value;
    m_set_State[0] |= 0x3;
}

inline
CGene_track_Base::TGeneid& CGene_track_Base::SetGeneid(void)
{
#ifdef _DEBUG
    if (!IsSetGeneid()) {
        memset(&m_Geneid,UnassignedByte(),sizeof(m_Geneid));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Geneid;
}

inline
bool CGene_track_Base::IsSetStatus(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CGene_track_Base::CanGetStatus(void) const
{
    return true;
}

inline
void CGene_track_Base::ResetStatus(void)
{
    m_Status = eStatus_live;
    m_set_State[0] &= ~0xc;
}

inline
void CGene_track_Base::SetDefaultStatus(void)
{
    ResetStatus();
}

inline
CGene_track_Base::TStatus CGene_track_Base::GetStatus(void) const
{
    return m_Status;
}

inline
void CGene_track_Base::SetStatus(CGene_track_Base::TStatus value)
{
    m_Status = value;
    m_set_State[0] |= 0xc;
}

inline
CGene_track_Base::TStatus& CGene_track_Base::SetStatus(void)
{
#ifdef _DEBUG
    if (!IsSetStatus()) {
        memset(&m_Status,UnassignedByte(),sizeof(m_Status));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Status;
}

inline
bool CGene_track_Base::IsSetCurrent_id(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CGene_track_Base::CanGetCurrent_id(void) const
{
    return true;
}

inline
const CGene_track_Base::TCurrent_id& CGene_track_Base::GetCurrent_id(void) const
{
    return m_Current_id;
}

inline
CGene_track_Base::TCurrent_id& CGene_track_Base::SetCurrent_id(void)
{
    m_set_State[0] |= 0x10;
    return m_Current_id;
}

inline
bool CGene_track_Base::IsSetCreate_date(void) const
{
    return m_Create_date.NotEmpty();
}

inline
bool CGene_track_Base::CanGetCreate_date(void) const
{
    return true;
}

inline
const CGene_track_Base::TCreate_date& CGene_track_Base::GetCreate_date(void) const
{
    if ( !m_Create_date ) {
        const_cast<CGene_track_Base*>(this)->ResetCreate_date();
    }
    return (*m_Create_date);
}

inline
CGene_track_Base::TCreate_date& CGene_track_Base::SetCreate_date(void)
{
    if ( !m_Create_date ) {
        ResetCreate_date();
    }
    return (*m_Create_date);
}

inline
bool CGene_track_Base::IsSetUpdate_date(void) const
{
    return m_Update_date.NotEmpty();
}

inline
bool CGene_track_Base::CanGetUpdate_date(void) const
{
    return true;
}

inline
const CGene_track_Base::TUpdate_date& CGene_track_Base::GetUpdate_date(void) const
{
    if ( !m_Update_date ) {
        const_cast<CGene_track_Base*>(this)->ResetUpdate_date();
    }
    return (*m_Update_date);
}

inline
CGene_track_Base::TUpdate_date& CGene_track_Base::SetUpdate_date(void)
{
    if ( !m_Update_date ) {
        ResetUpdate_date();
    }
    return (*m_Update_date);
}

inline
bool CGene_track_Base::IsSetDiscontinue_date(void) const
{
    return m_Discontinue_date.NotEmpty();
}

inline
bool CGene_track_Base::CanGetDiscontinue_date(void) const
{
    return IsSetDiscontinue_date();
}

inline
const CGene_track_Base::TDiscontinue_date& CGene_track_Base::GetDiscontinue_date(void) const
{
    if (!CanGetDiscontinue_date()) {
        ThrowUnassigned(5);
    }
    return (*m_Discontinue_date);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ENTREZGENE_GENE_TRACK_BASE_HPP
