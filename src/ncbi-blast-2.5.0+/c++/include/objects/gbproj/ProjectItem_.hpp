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

/// @file ProjectItem_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'gbproj.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_GBPROJ_PROJECTITEM_BASE_HPP
#define OBJECTS_GBPROJ_PROJECTITEM_BASE_HPP

// extra headers
#include <objects/gbproj/gbproj_export.h>

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
class CAbstractProjectItem;
class CAnnotdesc;
class CDummyObsoleteType;
class CSeq_align;
class CSeq_align_set;
class CSeq_annot;
class CSeq_entry;
class CSeq_id;
class CSeq_submit;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_GBPROJ_EXPORT CProjectItem_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CProjectItem_Base(void);
    // destructor
    virtual ~CProjectItem_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /////////////////////////////////////////////////////////////////////////////
    /// the item we represent
    class NCBI_GBPROJ_EXPORT C_Item : public CSerialObject
    {
        typedef CSerialObject Tparent;
    public:
        // constructor
        C_Item(void);
        // destructor
        ~C_Item(void);
    
        // type info
        DECLARE_INTERNAL_TYPE_INFO();
    
    
        /// Choice variants.
        enum E_Choice {
            e_not_set = 0,      ///< No variant selected
            e_Id,               ///< for projects that simply import a far-pointer
            e_Entry,            ///< for projects that contain something else
            e_Annot,            ///< annotation only
            e_Submit,           ///< for submission
            e_Seq_align,        ///< seq-align and seq-align-set as registered items
            e_Seq_align_set,
            e_Obsolete_plugin,  ///< plugin message  This is deprecated. DO NOT USE THIS FIELD.  The original spec is: plugin PluginMessage.  It is intended to be removed, but a complete  removal will cause order shift for the rest of   fields in this choice, and cause deserialization  failure for existing ASN files since this filed is  in the middle of the spec.
            e_Other,            ///< arbitrary object (use with care!)
            e_Pmid,             ///< PubMed ID
            e_Taxid             ///< Taxonomy ID
        };
        /// Maximum+1 value of the choice variant enumerator.
        enum E_ChoiceStopper {
            e_MaxChoice = 11 ///< == e_Taxid+1
        };
    
        /// Reset the whole object
        void Reset(void);
    
        /// Reset the selection (set it to e_not_set).
        void ResetSelection(void);
    
        /// Which variant is currently selected.
        E_Choice Which(void) const;
    
        /// Verify selection, throw exception if it differs from the expected.
        void CheckSelected(E_Choice index) const;
    
        /// Throw 'InvalidSelection' exception.
        NCBI_NORETURN void ThrowInvalidSelection(E_Choice index) const;
    
        /// Retrieve selection name (for diagnostic purposes).
        static string SelectionName(E_Choice index);
    
        /// Select the requested variant if needed.
        void Select(E_Choice index, EResetVariant reset = eDoResetVariant);
        /// Select the requested variant if needed,
        /// allocating CObject variants from memory pool.
        void Select(E_Choice index,
                    EResetVariant reset,
                    CObjectMemoryPool* pool);
    
        // types
        typedef CSeq_id TId;
        typedef CSeq_entry TEntry;
        typedef CSeq_annot TAnnot;
        typedef CSeq_submit TSubmit;
        typedef CSeq_align TSeq_align;
        typedef CSeq_align_set TSeq_align_set;
        typedef CDummyObsoleteType TObsolete_plugin;
        typedef CAbstractProjectItem TOther;
        typedef list< int > TPmid;
        typedef list< int > TTaxid;
    
        // getters
        // setters
    
        // typedef CSeq_id TId
        bool IsId(void) const;
        const TId& GetId(void) const;
        TId& SetId(void);
        void SetId(TId& value);
    
        // typedef CSeq_entry TEntry
        bool IsEntry(void) const;
        const TEntry& GetEntry(void) const;
        TEntry& SetEntry(void);
        void SetEntry(TEntry& value);
    
        // typedef CSeq_annot TAnnot
        bool IsAnnot(void) const;
        const TAnnot& GetAnnot(void) const;
        TAnnot& SetAnnot(void);
        void SetAnnot(TAnnot& value);
    
        // typedef CSeq_submit TSubmit
        bool IsSubmit(void) const;
        const TSubmit& GetSubmit(void) const;
        TSubmit& SetSubmit(void);
        void SetSubmit(TSubmit& value);
    
        // typedef CSeq_align TSeq_align
        bool IsSeq_align(void) const;
        const TSeq_align& GetSeq_align(void) const;
        TSeq_align& SetSeq_align(void);
        void SetSeq_align(TSeq_align& value);
    
        // typedef CSeq_align_set TSeq_align_set
        bool IsSeq_align_set(void) const;
        const TSeq_align_set& GetSeq_align_set(void) const;
        TSeq_align_set& SetSeq_align_set(void);
        void SetSeq_align_set(TSeq_align_set& value);
    
        // typedef CDummyObsoleteType TObsolete_plugin
        bool IsObsolete_plugin(void) const;
        const TObsolete_plugin& GetObsolete_plugin(void) const;
        TObsolete_plugin& SetObsolete_plugin(void);
        void SetObsolete_plugin(TObsolete_plugin& value);
    
        // typedef CAbstractProjectItem TOther
        bool IsOther(void) const;
        const TOther& GetOther(void) const;
        TOther& SetOther(void);
        void SetOther(TOther& value);
    
        // typedef list< int > TPmid
        bool IsPmid(void) const;
        const TPmid& GetPmid(void) const;
        TPmid& SetPmid(void);
    
        // typedef list< int > TTaxid
        bool IsTaxid(void) const;
        const TTaxid& GetTaxid(void) const;
        TTaxid& SetTaxid(void);
    
    
    private:
        // copy constructor and assignment operator
        C_Item(const C_Item& );
        C_Item& operator=(const C_Item& );
        // choice state
        E_Choice m_choice;
        // helper methods
        void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);
    
        static const char* const sm_SelectionNames[];
        // data
        union {
            NCBI_NS_NCBI::CUnionBuffer<TPmid> m_Pmid;
            NCBI_NS_NCBI::CUnionBuffer<TTaxid> m_Taxid;
            NCBI_NS_NCBI::CSerialObject *m_object;
        };
    };
    // types
    typedef int TId;
    typedef string TLabel;
    typedef list< CRef< CAnnotdesc > > TDescr;
    typedef C_Item TItem;
    typedef string TData_plugin;
    typedef bool TDisabled;

    // getters
    // setters

    /// serial number - must be unique in a project (GBProject)
    /// mandatory
    /// typedef int TId
    ///  Check whether the Id data member has been assigned a value.
    bool IsSetId(void) const;
    /// Check whether it is safe or not to call GetId method.
    bool CanGetId(void) const;
    void ResetId(void);
    TId GetId(void) const;
    void SetId(TId value);
    TId& SetId(void);

    /// user-defined label
    /// optional
    /// typedef string TLabel
    ///  Check whether the Label data member has been assigned a value.
    bool IsSetLabel(void) const;
    /// Check whether it is safe or not to call GetLabel method.
    bool CanGetLabel(void) const;
    void ResetLabel(void);
    const TLabel& GetLabel(void) const;
    void SetLabel(const TLabel& value);
    TLabel& SetLabel(void);

    /// user-defined descriptors
    /// optional
    /// typedef list< CRef< CAnnotdesc > > TDescr
    ///  Check whether the Descr data member has been assigned a value.
    bool IsSetDescr(void) const;
    /// Check whether it is safe or not to call GetDescr method.
    bool CanGetDescr(void) const;
    void ResetDescr(void);
    const TDescr& GetDescr(void) const;
    TDescr& SetDescr(void);

    /// mandatory
    /// typedef C_Item TItem
    ///  Check whether the Item data member has been assigned a value.
    bool IsSetItem(void) const;
    /// Check whether it is safe or not to call GetItem method.
    bool CanGetItem(void) const;
    void ResetItem(void);
    const TItem& GetItem(void) const;
    void SetItem(TItem& value);
    TItem& SetItem(void);

    ///name of the plugin that can handle External Data for the project
    /// optional
    /// typedef string TData_plugin
    ///  Check whether the Data_plugin data member has been assigned a value.
    bool IsSetData_plugin(void) const;
    /// Check whether it is safe or not to call GetData_plugin method.
    bool CanGetData_plugin(void) const;
    void ResetData_plugin(void);
    const TData_plugin& GetData_plugin(void) const;
    void SetData_plugin(const TData_plugin& value);
    TData_plugin& SetData_plugin(void);

    /// "folder open" state
    /// optional
    /// typedef bool TDisabled
    ///  Check whether the Disabled data member has been assigned a value.
    bool IsSetDisabled(void) const;
    /// Check whether it is safe or not to call GetDisabled method.
    bool CanGetDisabled(void) const;
    void ResetDisabled(void);
    TDisabled GetDisabled(void) const;
    void SetDisabled(TDisabled value);
    TDisabled& SetDisabled(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CProjectItem_Base(const CProjectItem_Base&);
    CProjectItem_Base& operator=(const CProjectItem_Base&);

    // data
    Uint4 m_set_State[1];
    int m_Id;
    string m_Label;
    list< CRef< CAnnotdesc > > m_Descr;
    CRef< TItem > m_Item;
    string m_Data_plugin;
    bool m_Disabled;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CProjectItem_Base::C_Item::E_Choice CProjectItem_Base::C_Item::Which(void) const
{
    return m_choice;
}

inline
void CProjectItem_Base::C_Item::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CProjectItem_Base::C_Item::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CProjectItem_Base::C_Item::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CProjectItem_Base::C_Item::IsId(void) const
{
    return m_choice == e_Id;
}

inline
bool CProjectItem_Base::C_Item::IsEntry(void) const
{
    return m_choice == e_Entry;
}

inline
bool CProjectItem_Base::C_Item::IsAnnot(void) const
{
    return m_choice == e_Annot;
}

inline
bool CProjectItem_Base::C_Item::IsSubmit(void) const
{
    return m_choice == e_Submit;
}

inline
bool CProjectItem_Base::C_Item::IsSeq_align(void) const
{
    return m_choice == e_Seq_align;
}

inline
bool CProjectItem_Base::C_Item::IsSeq_align_set(void) const
{
    return m_choice == e_Seq_align_set;
}

inline
bool CProjectItem_Base::C_Item::IsObsolete_plugin(void) const
{
    return m_choice == e_Obsolete_plugin;
}

inline
bool CProjectItem_Base::C_Item::IsOther(void) const
{
    return m_choice == e_Other;
}

inline
bool CProjectItem_Base::C_Item::IsPmid(void) const
{
    return m_choice == e_Pmid;
}

inline
const CProjectItem_Base::C_Item::TPmid& CProjectItem_Base::C_Item::GetPmid(void) const
{
    CheckSelected(e_Pmid);
    return *m_Pmid;
}

inline
CProjectItem_Base::C_Item::TPmid& CProjectItem_Base::C_Item::SetPmid(void)
{
    Select(e_Pmid, NCBI_NS_NCBI::eDoNotResetVariant);
    return *m_Pmid;
}

inline
bool CProjectItem_Base::C_Item::IsTaxid(void) const
{
    return m_choice == e_Taxid;
}

inline
const CProjectItem_Base::C_Item::TTaxid& CProjectItem_Base::C_Item::GetTaxid(void) const
{
    CheckSelected(e_Taxid);
    return *m_Taxid;
}

inline
CProjectItem_Base::C_Item::TTaxid& CProjectItem_Base::C_Item::SetTaxid(void)
{
    Select(e_Taxid, NCBI_NS_NCBI::eDoNotResetVariant);
    return *m_Taxid;
}

inline
bool CProjectItem_Base::IsSetId(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CProjectItem_Base::CanGetId(void) const
{
    return IsSetId();
}

inline
void CProjectItem_Base::ResetId(void)
{
    m_Id = 0;
    m_set_State[0] &= ~0x3;
}

inline
CProjectItem_Base::TId CProjectItem_Base::GetId(void) const
{
    if (!CanGetId()) {
        ThrowUnassigned(0);
    }
    return m_Id;
}

inline
void CProjectItem_Base::SetId(CProjectItem_Base::TId value)
{
    m_Id = value;
    m_set_State[0] |= 0x3;
}

inline
CProjectItem_Base::TId& CProjectItem_Base::SetId(void)
{
#ifdef _DEBUG
    if (!IsSetId()) {
        memset(&m_Id,UnassignedByte(),sizeof(m_Id));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Id;
}

inline
bool CProjectItem_Base::IsSetLabel(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CProjectItem_Base::CanGetLabel(void) const
{
    return IsSetLabel();
}

inline
const CProjectItem_Base::TLabel& CProjectItem_Base::GetLabel(void) const
{
    if (!CanGetLabel()) {
        ThrowUnassigned(1);
    }
    return m_Label;
}

inline
void CProjectItem_Base::SetLabel(const CProjectItem_Base::TLabel& value)
{
    m_Label = value;
    m_set_State[0] |= 0xc;
}

inline
CProjectItem_Base::TLabel& CProjectItem_Base::SetLabel(void)
{
#ifdef _DEBUG
    if (!IsSetLabel()) {
        m_Label = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Label;
}

inline
bool CProjectItem_Base::IsSetDescr(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CProjectItem_Base::CanGetDescr(void) const
{
    return true;
}

inline
const CProjectItem_Base::TDescr& CProjectItem_Base::GetDescr(void) const
{
    return m_Descr;
}

inline
CProjectItem_Base::TDescr& CProjectItem_Base::SetDescr(void)
{
    m_set_State[0] |= 0x10;
    return m_Descr;
}

inline
bool CProjectItem_Base::IsSetItem(void) const
{
    return m_Item.NotEmpty();
}

inline
bool CProjectItem_Base::CanGetItem(void) const
{
    return true;
}

inline
const CProjectItem_Base::TItem& CProjectItem_Base::GetItem(void) const
{
    if ( !m_Item ) {
        const_cast<CProjectItem_Base*>(this)->ResetItem();
    }
    return (*m_Item);
}

inline
CProjectItem_Base::TItem& CProjectItem_Base::SetItem(void)
{
    if ( !m_Item ) {
        ResetItem();
    }
    return (*m_Item);
}

inline
bool CProjectItem_Base::IsSetData_plugin(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CProjectItem_Base::CanGetData_plugin(void) const
{
    return IsSetData_plugin();
}

inline
const CProjectItem_Base::TData_plugin& CProjectItem_Base::GetData_plugin(void) const
{
    if (!CanGetData_plugin()) {
        ThrowUnassigned(4);
    }
    return m_Data_plugin;
}

inline
void CProjectItem_Base::SetData_plugin(const CProjectItem_Base::TData_plugin& value)
{
    m_Data_plugin = value;
    m_set_State[0] |= 0x300;
}

inline
CProjectItem_Base::TData_plugin& CProjectItem_Base::SetData_plugin(void)
{
#ifdef _DEBUG
    if (!IsSetData_plugin()) {
        m_Data_plugin = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Data_plugin;
}

inline
bool CProjectItem_Base::IsSetDisabled(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CProjectItem_Base::CanGetDisabled(void) const
{
    return IsSetDisabled();
}

inline
void CProjectItem_Base::ResetDisabled(void)
{
    m_Disabled = 0;
    m_set_State[0] &= ~0xc00;
}

inline
CProjectItem_Base::TDisabled CProjectItem_Base::GetDisabled(void) const
{
    if (!CanGetDisabled()) {
        ThrowUnassigned(5);
    }
    return m_Disabled;
}

inline
void CProjectItem_Base::SetDisabled(CProjectItem_Base::TDisabled value)
{
    m_Disabled = value;
    m_set_State[0] |= 0xc00;
}

inline
CProjectItem_Base::TDisabled& CProjectItem_Base::SetDisabled(void)
{
#ifdef _DEBUG
    if (!IsSetDisabled()) {
        memset(&m_Disabled,UnassignedByte(),sizeof(m_Disabled));
    }
#endif
    m_set_State[0] |= 0x400;
    return m_Disabled;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_GBPROJ_PROJECTITEM_BASE_HPP