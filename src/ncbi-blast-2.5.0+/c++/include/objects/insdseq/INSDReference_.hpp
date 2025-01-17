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

/// @file INSDReference_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'insdseq.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_INSDSEQ_INSDREFERENCE_BASE_HPP
#define OBJECTS_INSDSEQ_INSDREFERENCE_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>
#include <objects/insdseq/INSDAuthor.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CINSDXref;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// INSDReference_position contains a string value indicating the
/// basepair span(s) to which a reference applies. The allowable
/// formats are:
///
///   X..Y  : Where X and Y are integers separated by two periods,
///           X >= 1 , Y <= sequence length, and X <= Y 
///
///           Multiple basepair spans can exist, separated by a
///           semi-colon and a space. For example : 10..20; 100..500
///             
///   sites : The string literal 'sites', indicating that a reference
///           provides sequence annotation information, but the specific
///           basepair spans are either not captured, or were too numerous
///           to record.
///
///           The 'sites' literal string is singly occuring, and
///            cannot be used in conjunction with any X..Y basepair spans.
///
///           'sites' is a convention utilized by GenBank, and might
///           not be presented in XML provided by EMBL and DDBJ.
///
///   References that lack an INSDReference_position element are not
///   attributed to any particular region of the sequence.
class NCBI_INSDSEQ_EXPORT CINSDReference_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CINSDReference_Base(void);
    // destructor
    virtual ~CINSDReference_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TReference;
    typedef string TPosition;
    typedef list< CINSDAuthor > TAuthors;
    typedef string TConsortium;
    typedef string TTitle;
    typedef string TJournal;
    typedef list< CRef< CINSDXref > > TXref;
    typedef int TPubmed;
    typedef string TRemark;

    // getters
    // setters

    /// mandatory
    /// typedef string TReference
    ///  Check whether the Reference data member has been assigned a value.
    bool IsSetReference(void) const;
    /// Check whether it is safe or not to call GetReference method.
    bool CanGetReference(void) const;
    void ResetReference(void);
    const TReference& GetReference(void) const;
    void SetReference(const TReference& value);
    TReference& SetReference(void);

    /// optional
    /// typedef string TPosition
    ///  Check whether the Position data member has been assigned a value.
    bool IsSetPosition(void) const;
    /// Check whether it is safe or not to call GetPosition method.
    bool CanGetPosition(void) const;
    void ResetPosition(void);
    const TPosition& GetPosition(void) const;
    void SetPosition(const TPosition& value);
    TPosition& SetPosition(void);

    /// optional
    /// typedef list< CINSDAuthor > TAuthors
    ///  Check whether the Authors data member has been assigned a value.
    bool IsSetAuthors(void) const;
    /// Check whether it is safe or not to call GetAuthors method.
    bool CanGetAuthors(void) const;
    void ResetAuthors(void);
    const TAuthors& GetAuthors(void) const;
    TAuthors& SetAuthors(void);

    /// optional
    /// typedef string TConsortium
    ///  Check whether the Consortium data member has been assigned a value.
    bool IsSetConsortium(void) const;
    /// Check whether it is safe or not to call GetConsortium method.
    bool CanGetConsortium(void) const;
    void ResetConsortium(void);
    const TConsortium& GetConsortium(void) const;
    void SetConsortium(const TConsortium& value);
    TConsortium& SetConsortium(void);

    /// optional
    /// typedef string TTitle
    ///  Check whether the Title data member has been assigned a value.
    bool IsSetTitle(void) const;
    /// Check whether it is safe or not to call GetTitle method.
    bool CanGetTitle(void) const;
    void ResetTitle(void);
    const TTitle& GetTitle(void) const;
    void SetTitle(const TTitle& value);
    TTitle& SetTitle(void);

    /// mandatory
    /// typedef string TJournal
    ///  Check whether the Journal data member has been assigned a value.
    bool IsSetJournal(void) const;
    /// Check whether it is safe or not to call GetJournal method.
    bool CanGetJournal(void) const;
    void ResetJournal(void);
    const TJournal& GetJournal(void) const;
    void SetJournal(const TJournal& value);
    TJournal& SetJournal(void);

    /// optional
    /// typedef list< CRef< CINSDXref > > TXref
    ///  Check whether the Xref data member has been assigned a value.
    bool IsSetXref(void) const;
    /// Check whether it is safe or not to call GetXref method.
    bool CanGetXref(void) const;
    void ResetXref(void);
    const TXref& GetXref(void) const;
    TXref& SetXref(void);

    /// optional
    /// typedef int TPubmed
    ///  Check whether the Pubmed data member has been assigned a value.
    bool IsSetPubmed(void) const;
    /// Check whether it is safe or not to call GetPubmed method.
    bool CanGetPubmed(void) const;
    void ResetPubmed(void);
    TPubmed GetPubmed(void) const;
    void SetPubmed(TPubmed value);
    TPubmed& SetPubmed(void);

    /// optional
    /// typedef string TRemark
    ///  Check whether the Remark data member has been assigned a value.
    bool IsSetRemark(void) const;
    /// Check whether it is safe or not to call GetRemark method.
    bool CanGetRemark(void) const;
    void ResetRemark(void);
    const TRemark& GetRemark(void) const;
    void SetRemark(const TRemark& value);
    TRemark& SetRemark(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CINSDReference_Base(const CINSDReference_Base&);
    CINSDReference_Base& operator=(const CINSDReference_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Reference;
    string m_Position;
    list< CINSDAuthor > m_Authors;
    string m_Consortium;
    string m_Title;
    string m_Journal;
    list< CRef< CINSDXref > > m_Xref;
    int m_Pubmed;
    string m_Remark;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CINSDReference_Base::IsSetReference(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CINSDReference_Base::CanGetReference(void) const
{
    return IsSetReference();
}

inline
const CINSDReference_Base::TReference& CINSDReference_Base::GetReference(void) const
{
    if (!CanGetReference()) {
        ThrowUnassigned(0);
    }
    return m_Reference;
}

inline
void CINSDReference_Base::SetReference(const CINSDReference_Base::TReference& value)
{
    m_Reference = value;
    m_set_State[0] |= 0x3;
}

inline
CINSDReference_Base::TReference& CINSDReference_Base::SetReference(void)
{
#ifdef _DEBUG
    if (!IsSetReference()) {
        m_Reference = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Reference;
}

inline
bool CINSDReference_Base::IsSetPosition(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CINSDReference_Base::CanGetPosition(void) const
{
    return IsSetPosition();
}

inline
const CINSDReference_Base::TPosition& CINSDReference_Base::GetPosition(void) const
{
    if (!CanGetPosition()) {
        ThrowUnassigned(1);
    }
    return m_Position;
}

inline
void CINSDReference_Base::SetPosition(const CINSDReference_Base::TPosition& value)
{
    m_Position = value;
    m_set_State[0] |= 0xc;
}

inline
CINSDReference_Base::TPosition& CINSDReference_Base::SetPosition(void)
{
#ifdef _DEBUG
    if (!IsSetPosition()) {
        m_Position = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Position;
}

inline
bool CINSDReference_Base::IsSetAuthors(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CINSDReference_Base::CanGetAuthors(void) const
{
    return true;
}

inline
const CINSDReference_Base::TAuthors& CINSDReference_Base::GetAuthors(void) const
{
    return m_Authors;
}

inline
CINSDReference_Base::TAuthors& CINSDReference_Base::SetAuthors(void)
{
    m_set_State[0] |= 0x10;
    return m_Authors;
}

inline
bool CINSDReference_Base::IsSetConsortium(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CINSDReference_Base::CanGetConsortium(void) const
{
    return IsSetConsortium();
}

inline
const CINSDReference_Base::TConsortium& CINSDReference_Base::GetConsortium(void) const
{
    if (!CanGetConsortium()) {
        ThrowUnassigned(3);
    }
    return m_Consortium;
}

inline
void CINSDReference_Base::SetConsortium(const CINSDReference_Base::TConsortium& value)
{
    m_Consortium = value;
    m_set_State[0] |= 0xc0;
}

inline
CINSDReference_Base::TConsortium& CINSDReference_Base::SetConsortium(void)
{
#ifdef _DEBUG
    if (!IsSetConsortium()) {
        m_Consortium = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Consortium;
}

inline
bool CINSDReference_Base::IsSetTitle(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CINSDReference_Base::CanGetTitle(void) const
{
    return IsSetTitle();
}

inline
const CINSDReference_Base::TTitle& CINSDReference_Base::GetTitle(void) const
{
    if (!CanGetTitle()) {
        ThrowUnassigned(4);
    }
    return m_Title;
}

inline
void CINSDReference_Base::SetTitle(const CINSDReference_Base::TTitle& value)
{
    m_Title = value;
    m_set_State[0] |= 0x300;
}

inline
CINSDReference_Base::TTitle& CINSDReference_Base::SetTitle(void)
{
#ifdef _DEBUG
    if (!IsSetTitle()) {
        m_Title = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Title;
}

inline
bool CINSDReference_Base::IsSetJournal(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CINSDReference_Base::CanGetJournal(void) const
{
    return IsSetJournal();
}

inline
const CINSDReference_Base::TJournal& CINSDReference_Base::GetJournal(void) const
{
    if (!CanGetJournal()) {
        ThrowUnassigned(5);
    }
    return m_Journal;
}

inline
void CINSDReference_Base::SetJournal(const CINSDReference_Base::TJournal& value)
{
    m_Journal = value;
    m_set_State[0] |= 0xc00;
}

inline
CINSDReference_Base::TJournal& CINSDReference_Base::SetJournal(void)
{
#ifdef _DEBUG
    if (!IsSetJournal()) {
        m_Journal = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x400;
    return m_Journal;
}

inline
bool CINSDReference_Base::IsSetXref(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CINSDReference_Base::CanGetXref(void) const
{
    return true;
}

inline
const CINSDReference_Base::TXref& CINSDReference_Base::GetXref(void) const
{
    return m_Xref;
}

inline
CINSDReference_Base::TXref& CINSDReference_Base::SetXref(void)
{
    m_set_State[0] |= 0x1000;
    return m_Xref;
}

inline
bool CINSDReference_Base::IsSetPubmed(void) const
{
    return ((m_set_State[0] & 0xc000) != 0);
}

inline
bool CINSDReference_Base::CanGetPubmed(void) const
{
    return IsSetPubmed();
}

inline
void CINSDReference_Base::ResetPubmed(void)
{
    m_Pubmed = 0;
    m_set_State[0] &= ~0xc000;
}

inline
CINSDReference_Base::TPubmed CINSDReference_Base::GetPubmed(void) const
{
    if (!CanGetPubmed()) {
        ThrowUnassigned(7);
    }
    return m_Pubmed;
}

inline
void CINSDReference_Base::SetPubmed(CINSDReference_Base::TPubmed value)
{
    m_Pubmed = value;
    m_set_State[0] |= 0xc000;
}

inline
CINSDReference_Base::TPubmed& CINSDReference_Base::SetPubmed(void)
{
#ifdef _DEBUG
    if (!IsSetPubmed()) {
        memset(&m_Pubmed,UnassignedByte(),sizeof(m_Pubmed));
    }
#endif
    m_set_State[0] |= 0x4000;
    return m_Pubmed;
}

inline
bool CINSDReference_Base::IsSetRemark(void) const
{
    return ((m_set_State[0] & 0x30000) != 0);
}

inline
bool CINSDReference_Base::CanGetRemark(void) const
{
    return IsSetRemark();
}

inline
const CINSDReference_Base::TRemark& CINSDReference_Base::GetRemark(void) const
{
    if (!CanGetRemark()) {
        ThrowUnassigned(8);
    }
    return m_Remark;
}

inline
void CINSDReference_Base::SetRemark(const CINSDReference_Base::TRemark& value)
{
    m_Remark = value;
    m_set_State[0] |= 0x30000;
}

inline
CINSDReference_Base::TRemark& CINSDReference_Base::SetRemark(void)
{
#ifdef _DEBUG
    if (!IsSetRemark()) {
        m_Remark = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10000;
    return m_Remark;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_INSDSEQ_INSDREFERENCE_BASE_HPP
