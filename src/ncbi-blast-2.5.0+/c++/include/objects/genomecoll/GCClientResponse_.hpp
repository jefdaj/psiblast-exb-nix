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

/// @file GCClientResponse_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'gencoll_client.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_GENOMECOLL_GCCLIENTRESPONSE_BASE_HPP
#define OBJECTS_GENOMECOLL_GCCLIENTRESPONSE_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>
#include <vector>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CGCClient_AssembliesForSequences;
class CGCClient_EquivalentAssemblies;
class CGCClient_Error;
class CGC_Assembly;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CGCClientResponse_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CGCClientResponse_Base(void);
    // destructor
    virtual ~CGCClientResponse_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();


    /// Choice variants.
    enum E_Choice {
        e_not_set = 0,                ///< No variant selected
        e_Get_assembly,
        e_Get_chrtype_valid,
        e_Get_best_assembly,
        e_Get_equivalent_assemblies,
        e_Srvr_error,                 ///<  errors encountered at the server side.
        e_Get_assembly_blob,
        e_Get_assembly_by_sequence
    };
    /// Maximum+1 value of the choice variant enumerator.
    enum E_ChoiceStopper {
        e_MaxChoice = 8 ///< == e_Get_assembly_by_sequence+1
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
    typedef CGC_Assembly TGet_assembly;
    typedef string TGet_chrtype_valid;
    typedef CGCClient_AssembliesForSequences TGet_best_assembly;
    typedef CGCClient_EquivalentAssemblies TGet_equivalent_assemblies;
    typedef CGCClient_Error TSrvr_error;
    typedef vector< char > TGet_assembly_blob;
    typedef CGCClient_AssembliesForSequences TGet_assembly_by_sequence;

    // getters
    // setters

    // typedef CGC_Assembly TGet_assembly
    bool IsGet_assembly(void) const;
    const TGet_assembly& GetGet_assembly(void) const;
    TGet_assembly& SetGet_assembly(void);
    void SetGet_assembly(TGet_assembly& value);

    // typedef string TGet_chrtype_valid
    bool IsGet_chrtype_valid(void) const;
    const TGet_chrtype_valid& GetGet_chrtype_valid(void) const;
    TGet_chrtype_valid& SetGet_chrtype_valid(void);
    void SetGet_chrtype_valid(const TGet_chrtype_valid& value);

    // typedef CGCClient_AssembliesForSequences TGet_best_assembly
    bool IsGet_best_assembly(void) const;
    const TGet_best_assembly& GetGet_best_assembly(void) const;
    TGet_best_assembly& SetGet_best_assembly(void);
    void SetGet_best_assembly(TGet_best_assembly& value);

    // typedef CGCClient_EquivalentAssemblies TGet_equivalent_assemblies
    bool IsGet_equivalent_assemblies(void) const;
    const TGet_equivalent_assemblies& GetGet_equivalent_assemblies(void) const;
    TGet_equivalent_assemblies& SetGet_equivalent_assemblies(void);
    void SetGet_equivalent_assemblies(TGet_equivalent_assemblies& value);

    // typedef CGCClient_Error TSrvr_error
    bool IsSrvr_error(void) const;
    const TSrvr_error& GetSrvr_error(void) const;
    TSrvr_error& SetSrvr_error(void);
    void SetSrvr_error(TSrvr_error& value);

    // typedef vector< char > TGet_assembly_blob
    bool IsGet_assembly_blob(void) const;
    const TGet_assembly_blob& GetGet_assembly_blob(void) const;
    TGet_assembly_blob& SetGet_assembly_blob(void);

    // typedef CGCClient_AssembliesForSequences TGet_assembly_by_sequence
    bool IsGet_assembly_by_sequence(void) const;
    const TGet_assembly_by_sequence& GetGet_assembly_by_sequence(void) const;
    TGet_assembly_by_sequence& SetGet_assembly_by_sequence(void);
    void SetGet_assembly_by_sequence(TGet_assembly_by_sequence& value);


private:
    // copy constructor and assignment operator
    CGCClientResponse_Base(const CGCClientResponse_Base& );
    CGCClientResponse_Base& operator=(const CGCClientResponse_Base& );
    // choice state
    E_Choice m_choice;
    // helper methods
    void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);

    static const char* const sm_SelectionNames[];
    // data
    union {
        NCBI_NS_NCBI::CUnionBuffer<TGet_assembly_blob> m_Get_assembly_blob;
        NCBI_NS_NCBI::CUnionBuffer<NCBI_NS_STD::string> m_string;
        NCBI_NS_NCBI::CSerialObject *m_object;
    };
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CGCClientResponse_Base::E_Choice CGCClientResponse_Base::Which(void) const
{
    return m_choice;
}

inline
void CGCClientResponse_Base::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CGCClientResponse_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CGCClientResponse_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CGCClientResponse_Base::IsGet_assembly(void) const
{
    return m_choice == e_Get_assembly;
}

inline
bool CGCClientResponse_Base::IsGet_chrtype_valid(void) const
{
    return m_choice == e_Get_chrtype_valid;
}

inline
const CGCClientResponse_Base::TGet_chrtype_valid& CGCClientResponse_Base::GetGet_chrtype_valid(void) const
{
    CheckSelected(e_Get_chrtype_valid);
    return *m_string;
}

inline
CGCClientResponse_Base::TGet_chrtype_valid& CGCClientResponse_Base::SetGet_chrtype_valid(void)
{
    Select(e_Get_chrtype_valid, NCBI_NS_NCBI::eDoNotResetVariant);
    return *m_string;
}

inline
bool CGCClientResponse_Base::IsGet_best_assembly(void) const
{
    return m_choice == e_Get_best_assembly;
}

inline
bool CGCClientResponse_Base::IsGet_equivalent_assemblies(void) const
{
    return m_choice == e_Get_equivalent_assemblies;
}

inline
bool CGCClientResponse_Base::IsSrvr_error(void) const
{
    return m_choice == e_Srvr_error;
}

inline
bool CGCClientResponse_Base::IsGet_assembly_blob(void) const
{
    return m_choice == e_Get_assembly_blob;
}

inline
const CGCClientResponse_Base::TGet_assembly_blob& CGCClientResponse_Base::GetGet_assembly_blob(void) const
{
    CheckSelected(e_Get_assembly_blob);
    return *m_Get_assembly_blob;
}

inline
CGCClientResponse_Base::TGet_assembly_blob& CGCClientResponse_Base::SetGet_assembly_blob(void)
{
    Select(e_Get_assembly_blob, NCBI_NS_NCBI::eDoNotResetVariant);
    return *m_Get_assembly_blob;
}

inline
bool CGCClientResponse_Base::IsGet_assembly_by_sequence(void) const
{
    return m_choice == e_Get_assembly_by_sequence;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_GENOMECOLL_GCCLIENTRESPONSE_BASE_HPP
