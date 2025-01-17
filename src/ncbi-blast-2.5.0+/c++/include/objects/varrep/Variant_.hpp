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

/// @file Variant_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'varrep.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_VARREP_VARIANT_BASE_HPP
#define OBJECTS_VARREP_VARIANT_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <objects/varrep/SpecialVariant.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CSimpleVariant;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CVariant_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CVariant_Base(void);
    // destructor
    virtual ~CVariant_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();


    /// Choice variants.
    enum E_Choice {
        e_not_set = 0,  ///< No variant selected
        e_Simple,
        e_Special
    };
    /// Maximum+1 value of the choice variant enumerator.
    enum E_ChoiceStopper {
        e_MaxChoice = 3 ///< == e_Special+1
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
    typedef CSimpleVariant TSimple;
    typedef int TSpecial;

    // getters
    // setters

    // typedef CSimpleVariant TSimple
    bool IsSimple(void) const;
    const TSimple& GetSimple(void) const;
    TSimple& SetSimple(void);
    void SetSimple(TSimple& value);

    // typedef int TSpecial
    bool IsSpecial(void) const;
    TSpecial GetSpecial(void) const;
    TSpecial& SetSpecial(void);
    void SetSpecial(TSpecial value);


private:
    // copy constructor and assignment operator
    CVariant_Base(const CVariant_Base& );
    CVariant_Base& operator=(const CVariant_Base& );
    // choice state
    E_Choice m_choice;
    // helper methods
    void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);

    static const char* const sm_SelectionNames[];
    // data
    union {
        TSpecial m_Special;
        NCBI_NS_NCBI::CSerialObject *m_object;
    };
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CVariant_Base::E_Choice CVariant_Base::Which(void) const
{
    return m_choice;
}

inline
void CVariant_Base::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CVariant_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CVariant_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CVariant_Base::IsSimple(void) const
{
    return m_choice == e_Simple;
}

inline
bool CVariant_Base::IsSpecial(void) const
{
    return m_choice == e_Special;
}

inline
CVariant_Base::TSpecial CVariant_Base::GetSpecial(void) const
{
    CheckSelected(e_Special);
    return m_Special;
}

inline
CVariant_Base::TSpecial& CVariant_Base::SetSpecial(void)
{
    Select(e_Special, NCBI_NS_NCBI::eDoNotResetVariant);
    return m_Special;
}

inline
void CVariant_Base::SetSpecial(CVariant_Base::TSpecial value)
{
    Select(e_Special, NCBI_NS_NCBI::eDoNotResetVariant);
    m_Special = value;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_VARREP_VARIANT_BASE_HPP
