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

/// @file Biostruc_seqs_aligns_cdd_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'ncbimime.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_NCBIMIME_BIOSTRUC_SEQS_ALIGNS_CDD_BASE_HPP
#define OBJECTS_NCBIMIME_BIOSTRUC_SEQS_ALIGNS_CDD_BASE_HPP

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
class CBiostruc;
class CBundle_seqs_aligns;
class CCdd;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_NCBIMIME_EXPORT CBiostruc_seqs_aligns_cdd_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CBiostruc_seqs_aligns_cdd_Base(void);
    // destructor
    virtual ~CBiostruc_seqs_aligns_cdd_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /////////////////////////////////////////////////////////////////////////////
    class NCBI_NCBIMIME_EXPORT C_Seq_align_data : public CSerialObject
    {
        typedef CSerialObject Tparent;
    public:
        // constructor
        C_Seq_align_data(void);
        // destructor
        ~C_Seq_align_data(void);
    
        // type info
        DECLARE_INTERNAL_TYPE_INFO();
    
    
        /// Choice variants.
        enum E_Choice {
            e_not_set = 0,  ///< No variant selected
            e_Bundle,       ///< either seqs + alignments
            e_Cdd           ///< or CDD (which contains these)
        };
        /// Maximum+1 value of the choice variant enumerator.
        enum E_ChoiceStopper {
            e_MaxChoice = 3 ///< == e_Cdd+1
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
        typedef CBundle_seqs_aligns TBundle;
        typedef CCdd TCdd;
    
        // getters
        // setters
    
        // typedef CBundle_seqs_aligns TBundle
        bool IsBundle(void) const;
        const TBundle& GetBundle(void) const;
        TBundle& SetBundle(void);
        void SetBundle(TBundle& value);
    
        // typedef CCdd TCdd
        bool IsCdd(void) const;
        const TCdd& GetCdd(void) const;
        TCdd& SetCdd(void);
        void SetCdd(TCdd& value);
    
    
    private:
        // copy constructor and assignment operator
        C_Seq_align_data(const C_Seq_align_data& );
        C_Seq_align_data& operator=(const C_Seq_align_data& );
        // choice state
        E_Choice m_choice;
        // helper methods
        void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);
    
        static const char* const sm_SelectionNames[];
        // data
        NCBI_NS_NCBI::CSerialObject *m_object;
    };
    /// type of structures to load if
    enum EStructure_type {
        eStructure_type_ncbi_backbone = 2,  ///< not present; meanings and
        eStructure_type_ncbi_all_atom = 3,  ///< values are same as MMDB's
        eStructure_type_pdb_model     = 4  ///< Model-type
    };
    
    /// Access to EStructure_type's attributes (values, names) as defined in spec
    static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EStructure_type)(void);
    
    // types
    typedef C_Seq_align_data TSeq_align_data;
    typedef list< CRef< CBiostruc > > TStructures;
    typedef EStructure_type TStructure_type;

    // getters
    // setters

    /// mandatory
    /// typedef C_Seq_align_data TSeq_align_data
    ///  Check whether the Seq_align_data data member has been assigned a value.
    bool IsSetSeq_align_data(void) const;
    /// Check whether it is safe or not to call GetSeq_align_data method.
    bool CanGetSeq_align_data(void) const;
    void ResetSeq_align_data(void);
    const TSeq_align_data& GetSeq_align_data(void) const;
    void SetSeq_align_data(TSeq_align_data& value);
    TSeq_align_data& SetSeq_align_data(void);

    /// structures
    /// optional
    /// typedef list< CRef< CBiostruc > > TStructures
    ///  Check whether the Structures data member has been assigned a value.
    bool IsSetStructures(void) const;
    /// Check whether it is safe or not to call GetStructures method.
    bool CanGetStructures(void) const;
    void ResetStructures(void);
    const TStructures& GetStructures(void) const;
    TStructures& SetStructures(void);

    /// optional
    /// typedef EStructure_type TStructure_type
    ///  Check whether the Structure_type data member has been assigned a value.
    bool IsSetStructure_type(void) const;
    /// Check whether it is safe or not to call GetStructure_type method.
    bool CanGetStructure_type(void) const;
    void ResetStructure_type(void);
    TStructure_type GetStructure_type(void) const;
    void SetStructure_type(TStructure_type value);
    TStructure_type& SetStructure_type(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CBiostruc_seqs_aligns_cdd_Base(const CBiostruc_seqs_aligns_cdd_Base&);
    CBiostruc_seqs_aligns_cdd_Base& operator=(const CBiostruc_seqs_aligns_cdd_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TSeq_align_data > m_Seq_align_data;
    list< CRef< CBiostruc > > m_Structures;
    EStructure_type m_Structure_type;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CBiostruc_seqs_aligns_cdd_Base::C_Seq_align_data::E_Choice CBiostruc_seqs_aligns_cdd_Base::C_Seq_align_data::Which(void) const
{
    return m_choice;
}

inline
void CBiostruc_seqs_aligns_cdd_Base::C_Seq_align_data::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CBiostruc_seqs_aligns_cdd_Base::C_Seq_align_data::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CBiostruc_seqs_aligns_cdd_Base::C_Seq_align_data::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CBiostruc_seqs_aligns_cdd_Base::C_Seq_align_data::IsBundle(void) const
{
    return m_choice == e_Bundle;
}

inline
bool CBiostruc_seqs_aligns_cdd_Base::C_Seq_align_data::IsCdd(void) const
{
    return m_choice == e_Cdd;
}

inline
bool CBiostruc_seqs_aligns_cdd_Base::IsSetSeq_align_data(void) const
{
    return m_Seq_align_data.NotEmpty();
}

inline
bool CBiostruc_seqs_aligns_cdd_Base::CanGetSeq_align_data(void) const
{
    return true;
}

inline
const CBiostruc_seqs_aligns_cdd_Base::TSeq_align_data& CBiostruc_seqs_aligns_cdd_Base::GetSeq_align_data(void) const
{
    if ( !m_Seq_align_data ) {
        const_cast<CBiostruc_seqs_aligns_cdd_Base*>(this)->ResetSeq_align_data();
    }
    return (*m_Seq_align_data);
}

inline
CBiostruc_seqs_aligns_cdd_Base::TSeq_align_data& CBiostruc_seqs_aligns_cdd_Base::SetSeq_align_data(void)
{
    if ( !m_Seq_align_data ) {
        ResetSeq_align_data();
    }
    return (*m_Seq_align_data);
}

inline
bool CBiostruc_seqs_aligns_cdd_Base::IsSetStructures(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CBiostruc_seqs_aligns_cdd_Base::CanGetStructures(void) const
{
    return true;
}

inline
const CBiostruc_seqs_aligns_cdd_Base::TStructures& CBiostruc_seqs_aligns_cdd_Base::GetStructures(void) const
{
    return m_Structures;
}

inline
CBiostruc_seqs_aligns_cdd_Base::TStructures& CBiostruc_seqs_aligns_cdd_Base::SetStructures(void)
{
    m_set_State[0] |= 0x4;
    return m_Structures;
}

inline
bool CBiostruc_seqs_aligns_cdd_Base::IsSetStructure_type(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CBiostruc_seqs_aligns_cdd_Base::CanGetStructure_type(void) const
{
    return IsSetStructure_type();
}

inline
void CBiostruc_seqs_aligns_cdd_Base::ResetStructure_type(void)
{
    m_Structure_type = (EStructure_type)(0);
    m_set_State[0] &= ~0x30;
}

inline
CBiostruc_seqs_aligns_cdd_Base::TStructure_type CBiostruc_seqs_aligns_cdd_Base::GetStructure_type(void) const
{
    if (!CanGetStructure_type()) {
        ThrowUnassigned(2);
    }
    return m_Structure_type;
}

inline
void CBiostruc_seqs_aligns_cdd_Base::SetStructure_type(CBiostruc_seqs_aligns_cdd_Base::TStructure_type value)
{
    m_Structure_type = value;
    m_set_State[0] |= 0x30;
}

inline
CBiostruc_seqs_aligns_cdd_Base::TStructure_type& CBiostruc_seqs_aligns_cdd_Base::SetStructure_type(void)
{
#ifdef _DEBUG
    if (!IsSetStructure_type()) {
        memset(&m_Structure_type,UnassignedByte(),sizeof(m_Structure_type));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Structure_type;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_NCBIMIME_BIOSTRUC_SEQS_ALIGNS_CDD_BASE_HPP