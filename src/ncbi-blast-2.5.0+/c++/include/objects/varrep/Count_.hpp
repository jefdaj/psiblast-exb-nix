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

/// @file Count_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'varrep.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_VARREP_COUNT_BASE_HPP
#define OBJECTS_VARREP_COUNT_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CCount_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CCount_Base(void);
    // destructor
    virtual ~CCount_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /////////////////////////////////////////////////////////////////////////////
    class C_Range : public CSerialObject
    {
        typedef CSerialObject Tparent;
    public:
        // constructor
        C_Range(void);
        // destructor
        ~C_Range(void);
    
        // type info
        DECLARE_INTERNAL_TYPE_INFO();
    
        /////////////////////////////////////////////////////////////////////////////
        class C_Start : public CSerialObject
        {
            typedef CSerialObject Tparent;
        public:
            // constructor
            C_Start(void);
            // destructor
            ~C_Start(void);
        
            // type info
            DECLARE_INTERNAL_TYPE_INFO();
        
        
            /// Choice variants.
            enum E_Choice {
                e_not_set = 0,  ///< No variant selected
                e_Val,
                e_Unknown
            };
            /// Maximum+1 value of the choice variant enumerator.
            enum E_ChoiceStopper {
                e_MaxChoice = 3 ///< == e_Unknown+1
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
            typedef TSeqPos TVal;
        
            // getters
            // setters
        
            // typedef TSeqPos TVal
            bool IsVal(void) const;
            TVal GetVal(void) const;
            TVal& SetVal(void);
            void SetVal(TVal value);
        
        
            bool IsUnknown(void) const;
            void SetUnknown(void);
        
        
        private:
            // copy constructor and assignment operator
            C_Start(const C_Start& );
            C_Start& operator=(const C_Start& );
            // choice state
            E_Choice m_choice;
            // helper methods
            void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);
        
            static const char* const sm_SelectionNames[];
            // data
            union {
                TVal m_Val;
            };
        };
        /////////////////////////////////////////////////////////////////////////////
        class C_Stop : public CSerialObject
        {
            typedef CSerialObject Tparent;
        public:
            // constructor
            C_Stop(void);
            // destructor
            ~C_Stop(void);
        
            // type info
            DECLARE_INTERNAL_TYPE_INFO();
        
        
            /// Choice variants.
            enum E_Choice {
                e_not_set = 0,  ///< No variant selected
                e_Val,
                e_Unknown
            };
            /// Maximum+1 value of the choice variant enumerator.
            enum E_ChoiceStopper {
                e_MaxChoice = 3 ///< == e_Unknown+1
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
            typedef TSeqPos TVal;
        
            // getters
            // setters
        
            // typedef TSeqPos TVal
            bool IsVal(void) const;
            TVal GetVal(void) const;
            TVal& SetVal(void);
            void SetVal(TVal value);
        
        
            bool IsUnknown(void) const;
            void SetUnknown(void);
        
        
        private:
            // copy constructor and assignment operator
            C_Stop(const C_Stop& );
            C_Stop& operator=(const C_Stop& );
            // choice state
            E_Choice m_choice;
            // helper methods
            void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);
        
            static const char* const sm_SelectionNames[];
            // data
            union {
                TVal m_Val;
            };
        };
        // types
        typedef C_Start TStart;
        typedef C_Stop TStop;
    
        // getters
        // setters
    
        /// mandatory
        /// typedef C_Start TStart
        ///  Check whether the Start data member has been assigned a value.
        bool IsSetStart(void) const;
        /// Check whether it is safe or not to call GetStart method.
        bool CanGetStart(void) const;
        void ResetStart(void);
        const TStart& GetStart(void) const;
        void SetStart(TStart& value);
        TStart& SetStart(void);
    
        /// mandatory
        /// typedef C_Stop TStop
        ///  Check whether the Stop data member has been assigned a value.
        bool IsSetStop(void) const;
        /// Check whether it is safe or not to call GetStop method.
        bool CanGetStop(void) const;
        void ResetStop(void);
        const TStop& GetStop(void) const;
        void SetStop(TStop& value);
        TStop& SetStop(void);
    
        /// Reset the whole object
        void Reset(void);
    
    
    private:
        // Prohibit copy constructor and assignment operator
        C_Range(const C_Range&);
        C_Range& operator=(const C_Range&);
    
        // data
        Uint4 m_set_State[1];
        CRef< TStart > m_Start;
        CRef< TStop > m_Stop;
    };

    /// Choice variants.
    enum E_Choice {
        e_not_set = 0,  ///< No variant selected
        e_Unknown,
        e_Val,
        e_Fuzzy_val,
        e_Range
    };
    /// Maximum+1 value of the choice variant enumerator.
    enum E_ChoiceStopper {
        e_MaxChoice = 5 ///< == e_Range+1
    };

    /// Reset the whole object
    virtual void Reset(void);

    /// Reset the selection (set it to e_not_set).
    virtual void ResetSelection(void);

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
    typedef TSeqPos TVal;
    typedef TSeqPos TFuzzy_val;
    typedef C_Range TRange;

    // getters
    // setters


    bool IsUnknown(void) const;
    void SetUnknown(void);

    // typedef TSeqPos TVal
    bool IsVal(void) const;
    TVal GetVal(void) const;
    TVal& SetVal(void);
    void SetVal(TVal value);

    // typedef TSeqPos TFuzzy_val
    bool IsFuzzy_val(void) const;
    TFuzzy_val GetFuzzy_val(void) const;
    TFuzzy_val& SetFuzzy_val(void);
    void SetFuzzy_val(TFuzzy_val value);

    // typedef C_Range TRange
    bool IsRange(void) const;
    const TRange& GetRange(void) const;
    TRange& SetRange(void);
    void SetRange(TRange& value);


private:
    // copy constructor and assignment operator
    CCount_Base(const CCount_Base& );
    CCount_Base& operator=(const CCount_Base& );
    // choice state
    E_Choice m_choice;
    // helper methods
    void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);

    static const char* const sm_SelectionNames[];
    // data
    union {
        TVal m_Val;
        TFuzzy_val m_Fuzzy_val;
        NCBI_NS_NCBI::CSerialObject *m_object;
    };
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CCount_Base::C_Range::C_Start::E_Choice CCount_Base::C_Range::C_Start::Which(void) const
{
    return m_choice;
}

inline
void CCount_Base::C_Range::C_Start::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CCount_Base::C_Range::C_Start::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CCount_Base::C_Range::C_Start::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CCount_Base::C_Range::C_Start::IsVal(void) const
{
    return m_choice == e_Val;
}

inline
CCount_Base::C_Range::C_Start::TVal CCount_Base::C_Range::C_Start::GetVal(void) const
{
    CheckSelected(e_Val);
    return m_Val;
}

inline
CCount_Base::C_Range::C_Start::TVal& CCount_Base::C_Range::C_Start::SetVal(void)
{
    Select(e_Val, NCBI_NS_NCBI::eDoNotResetVariant);
    return m_Val;
}

inline
void CCount_Base::C_Range::C_Start::SetVal(CCount_Base::C_Range::C_Start::TVal value)
{
    Select(e_Val, NCBI_NS_NCBI::eDoNotResetVariant);
    m_Val = value;
}

inline
bool CCount_Base::C_Range::C_Start::IsUnknown(void) const
{
    return m_choice == e_Unknown;
}

inline
void CCount_Base::C_Range::C_Start::SetUnknown(void)
{
    Select(e_Unknown, NCBI_NS_NCBI::eDoNotResetVariant);
}

inline
CCount_Base::C_Range::C_Stop::E_Choice CCount_Base::C_Range::C_Stop::Which(void) const
{
    return m_choice;
}

inline
void CCount_Base::C_Range::C_Stop::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CCount_Base::C_Range::C_Stop::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CCount_Base::C_Range::C_Stop::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CCount_Base::C_Range::C_Stop::IsVal(void) const
{
    return m_choice == e_Val;
}

inline
CCount_Base::C_Range::C_Stop::TVal CCount_Base::C_Range::C_Stop::GetVal(void) const
{
    CheckSelected(e_Val);
    return m_Val;
}

inline
CCount_Base::C_Range::C_Stop::TVal& CCount_Base::C_Range::C_Stop::SetVal(void)
{
    Select(e_Val, NCBI_NS_NCBI::eDoNotResetVariant);
    return m_Val;
}

inline
void CCount_Base::C_Range::C_Stop::SetVal(CCount_Base::C_Range::C_Stop::TVal value)
{
    Select(e_Val, NCBI_NS_NCBI::eDoNotResetVariant);
    m_Val = value;
}

inline
bool CCount_Base::C_Range::C_Stop::IsUnknown(void) const
{
    return m_choice == e_Unknown;
}

inline
void CCount_Base::C_Range::C_Stop::SetUnknown(void)
{
    Select(e_Unknown, NCBI_NS_NCBI::eDoNotResetVariant);
}

inline
bool CCount_Base::C_Range::IsSetStart(void) const
{
    return m_Start.NotEmpty();
}

inline
bool CCount_Base::C_Range::CanGetStart(void) const
{
    return true;
}

inline
const CCount_Base::C_Range::TStart& CCount_Base::C_Range::GetStart(void) const
{
    if ( !m_Start ) {
        const_cast<C_Range*>(this)->ResetStart();
    }
    return (*m_Start);
}

inline
CCount_Base::C_Range::TStart& CCount_Base::C_Range::SetStart(void)
{
    if ( !m_Start ) {
        ResetStart();
    }
    return (*m_Start);
}

inline
bool CCount_Base::C_Range::IsSetStop(void) const
{
    return m_Stop.NotEmpty();
}

inline
bool CCount_Base::C_Range::CanGetStop(void) const
{
    return true;
}

inline
const CCount_Base::C_Range::TStop& CCount_Base::C_Range::GetStop(void) const
{
    if ( !m_Stop ) {
        const_cast<C_Range*>(this)->ResetStop();
    }
    return (*m_Stop);
}

inline
CCount_Base::C_Range::TStop& CCount_Base::C_Range::SetStop(void)
{
    if ( !m_Stop ) {
        ResetStop();
    }
    return (*m_Stop);
}

inline
CCount_Base::E_Choice CCount_Base::Which(void) const
{
    return m_choice;
}

inline
void CCount_Base::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CCount_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CCount_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CCount_Base::IsUnknown(void) const
{
    return m_choice == e_Unknown;
}

inline
void CCount_Base::SetUnknown(void)
{
    Select(e_Unknown, NCBI_NS_NCBI::eDoNotResetVariant);
}

inline
bool CCount_Base::IsVal(void) const
{
    return m_choice == e_Val;
}

inline
CCount_Base::TVal CCount_Base::GetVal(void) const
{
    CheckSelected(e_Val);
    return m_Val;
}

inline
CCount_Base::TVal& CCount_Base::SetVal(void)
{
    Select(e_Val, NCBI_NS_NCBI::eDoNotResetVariant);
    return m_Val;
}

inline
void CCount_Base::SetVal(CCount_Base::TVal value)
{
    Select(e_Val, NCBI_NS_NCBI::eDoNotResetVariant);
    m_Val = value;
}

inline
bool CCount_Base::IsFuzzy_val(void) const
{
    return m_choice == e_Fuzzy_val;
}

inline
CCount_Base::TFuzzy_val CCount_Base::GetFuzzy_val(void) const
{
    CheckSelected(e_Fuzzy_val);
    return m_Fuzzy_val;
}

inline
CCount_Base::TFuzzy_val& CCount_Base::SetFuzzy_val(void)
{
    Select(e_Fuzzy_val, NCBI_NS_NCBI::eDoNotResetVariant);
    return m_Fuzzy_val;
}

inline
void CCount_Base::SetFuzzy_val(CCount_Base::TFuzzy_val value)
{
    Select(e_Fuzzy_val, NCBI_NS_NCBI::eDoNotResetVariant);
    m_Fuzzy_val = value;
}

inline
bool CCount_Base::IsRange(void) const
{
    return m_choice == e_Range;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_VARREP_COUNT_BASE_HPP
