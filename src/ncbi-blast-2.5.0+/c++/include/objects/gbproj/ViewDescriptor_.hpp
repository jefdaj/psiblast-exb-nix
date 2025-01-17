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

/// @file ViewDescriptor_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'gbproj.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_GBPROJ_VIEWDESCRIPTOR_BASE_HPP
#define OBJECTS_GBPROJ_VIEWDESCRIPTOR_BASE_HPP

// extra headers
#include <objects/gbproj/gbproj_export.h>

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
class CProjectItem;
class CViewDataLink;
class CViewMemento;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_GBPROJ_EXPORT CViewDescriptor_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CViewDescriptor_Base(void);
    // destructor
    virtual ~CViewDescriptor_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /////////////////////////////////////////////////////////////////////////////
    ///- data for view opening
    class NCBI_GBPROJ_EXPORT C_Data : public CSerialObject
    {
        typedef CSerialObject Tparent;
    public:
        // constructor
        C_Data(void);
        // destructor
        ~C_Data(void);
    
        // type info
        DECLARE_INTERNAL_TYPE_INFO();
    
    
        /// Choice variants.
        enum E_Choice {
            e_not_set = 0,  ///< No variant selected
            e_Link,         ///<- link to retrieve data
            e_Item          ///<- virtual project item, if link cannot be created
        };
        /// Maximum+1 value of the choice variant enumerator.
        enum E_ChoiceStopper {
            e_MaxChoice = 3 ///< == e_Item+1
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
        typedef CViewDataLink TLink;
        typedef CProjectItem TItem;
    
        // getters
        // setters
    
        // typedef CViewDataLink TLink
        bool IsLink(void) const;
        const TLink& GetLink(void) const;
        TLink& SetLink(void);
        void SetLink(TLink& value);
    
        // typedef CProjectItem TItem
        bool IsItem(void) const;
        const TItem& GetItem(void) const;
        TItem& SetItem(void);
        void SetItem(TItem& value);
    
    
    private:
        // copy constructor and assignment operator
        C_Data(const C_Data& );
        C_Data& operator=(const C_Data& );
        // choice state
        E_Choice m_choice;
        // helper methods
        void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);
    
        static const char* const sm_SelectionNames[];
        // data
        NCBI_NS_NCBI::CSerialObject *m_object;
    };
    // types
    typedef C_Data TData;
    typedef string TView_plugin;
    typedef int TView_id;
    typedef CViewMemento TView_memento;

    // getters
    // setters

    /// mandatory
    /// typedef C_Data TData
    ///  Check whether the Data data member has been assigned a value.
    bool IsSetData(void) const;
    /// Check whether it is safe or not to call GetData method.
    bool CanGetData(void) const;
    void ResetData(void);
    const TData& GetData(void) const;
    void SetData(TData& value);
    TData& SetData(void);

    ///- plugin name of saved view
    /// mandatory
    /// typedef string TView_plugin
    ///  Check whether the View_plugin data member has been assigned a value.
    bool IsSetView_plugin(void) const;
    /// Check whether it is safe or not to call GetView_plugin method.
    bool CanGetView_plugin(void) const;
    void ResetView_plugin(void);
    const TView_plugin& GetView_plugin(void) const;
    void SetView_plugin(const TView_plugin& value);
    TView_plugin& SetView_plugin(void);

    ///- view id
    /// mandatory
    /// typedef int TView_id
    ///  Check whether the View_id data member has been assigned a value.
    bool IsSetView_id(void) const;
    /// Check whether it is safe or not to call GetView_id method.
    bool CanGetView_id(void) const;
    void ResetView_id(void);
    TView_id GetView_id(void) const;
    void SetView_id(TView_id value);
    TView_id& SetView_id(void);

    ///- optional settings, requered to open view
    /// optional
    /// typedef CViewMemento TView_memento
    ///  Check whether the View_memento data member has been assigned a value.
    bool IsSetView_memento(void) const;
    /// Check whether it is safe or not to call GetView_memento method.
    bool CanGetView_memento(void) const;
    void ResetView_memento(void);
    const TView_memento& GetView_memento(void) const;
    void SetView_memento(TView_memento& value);
    TView_memento& SetView_memento(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CViewDescriptor_Base(const CViewDescriptor_Base&);
    CViewDescriptor_Base& operator=(const CViewDescriptor_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TData > m_Data;
    string m_View_plugin;
    int m_View_id;
    CRef< TView_memento > m_View_memento;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CViewDescriptor_Base::C_Data::E_Choice CViewDescriptor_Base::C_Data::Which(void) const
{
    return m_choice;
}

inline
void CViewDescriptor_Base::C_Data::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CViewDescriptor_Base::C_Data::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CViewDescriptor_Base::C_Data::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CViewDescriptor_Base::C_Data::IsLink(void) const
{
    return m_choice == e_Link;
}

inline
bool CViewDescriptor_Base::C_Data::IsItem(void) const
{
    return m_choice == e_Item;
}

inline
bool CViewDescriptor_Base::IsSetData(void) const
{
    return m_Data.NotEmpty();
}

inline
bool CViewDescriptor_Base::CanGetData(void) const
{
    return true;
}

inline
const CViewDescriptor_Base::TData& CViewDescriptor_Base::GetData(void) const
{
    if ( !m_Data ) {
        const_cast<CViewDescriptor_Base*>(this)->ResetData();
    }
    return (*m_Data);
}

inline
CViewDescriptor_Base::TData& CViewDescriptor_Base::SetData(void)
{
    if ( !m_Data ) {
        ResetData();
    }
    return (*m_Data);
}

inline
bool CViewDescriptor_Base::IsSetView_plugin(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CViewDescriptor_Base::CanGetView_plugin(void) const
{
    return IsSetView_plugin();
}

inline
const CViewDescriptor_Base::TView_plugin& CViewDescriptor_Base::GetView_plugin(void) const
{
    if (!CanGetView_plugin()) {
        ThrowUnassigned(1);
    }
    return m_View_plugin;
}

inline
void CViewDescriptor_Base::SetView_plugin(const CViewDescriptor_Base::TView_plugin& value)
{
    m_View_plugin = value;
    m_set_State[0] |= 0xc;
}

inline
CViewDescriptor_Base::TView_plugin& CViewDescriptor_Base::SetView_plugin(void)
{
#ifdef _DEBUG
    if (!IsSetView_plugin()) {
        m_View_plugin = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_View_plugin;
}

inline
bool CViewDescriptor_Base::IsSetView_id(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CViewDescriptor_Base::CanGetView_id(void) const
{
    return IsSetView_id();
}

inline
void CViewDescriptor_Base::ResetView_id(void)
{
    m_View_id = 0;
    m_set_State[0] &= ~0x30;
}

inline
CViewDescriptor_Base::TView_id CViewDescriptor_Base::GetView_id(void) const
{
    if (!CanGetView_id()) {
        ThrowUnassigned(2);
    }
    return m_View_id;
}

inline
void CViewDescriptor_Base::SetView_id(CViewDescriptor_Base::TView_id value)
{
    m_View_id = value;
    m_set_State[0] |= 0x30;
}

inline
CViewDescriptor_Base::TView_id& CViewDescriptor_Base::SetView_id(void)
{
#ifdef _DEBUG
    if (!IsSetView_id()) {
        memset(&m_View_id,UnassignedByte(),sizeof(m_View_id));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_View_id;
}

inline
bool CViewDescriptor_Base::IsSetView_memento(void) const
{
    return m_View_memento.NotEmpty();
}

inline
bool CViewDescriptor_Base::CanGetView_memento(void) const
{
    return IsSetView_memento();
}

inline
const CViewDescriptor_Base::TView_memento& CViewDescriptor_Base::GetView_memento(void) const
{
    if (!CanGetView_memento()) {
        ThrowUnassigned(3);
    }
    return (*m_View_memento);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_GBPROJ_VIEWDESCRIPTOR_BASE_HPP
