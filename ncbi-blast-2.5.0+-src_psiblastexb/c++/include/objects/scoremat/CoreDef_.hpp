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

/// @file CoreDef_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'scoremat.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SCOREMAT_COREDEF_BASE_HPP
#define OBJECTS_SCOREMAT_COREDEF_BASE_HPP

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
class CCoreBlock;
class CLoopConstraint;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_SCOREMAT_EXPORT CCoreDef_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CCoreDef_Base(void);
    // destructor
    virtual ~CCoreDef_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef int TNblocks;
    typedef list< CRef< CCoreBlock > > TBlocks;
    typedef list< CRef< CLoopConstraint > > TLoops;
    typedef bool TIsDiscontinuous;
    typedef list< int > TInsertions;

    // getters
    // setters

    /// number of core elements/blocks
    /// mandatory
    /// typedef int TNblocks
    ///  Check whether the Nblocks data member has been assigned a value.
    bool IsSetNblocks(void) const;
    /// Check whether it is safe or not to call GetNblocks method.
    bool CanGetNblocks(void) const;
    void ResetNblocks(void);
    TNblocks GetNblocks(void) const;
    void SetNblocks(TNblocks value);
    TNblocks& SetNblocks(void);

    /// nblocks locations
    /// mandatory
    /// typedef list< CRef< CCoreBlock > > TBlocks
    ///  Check whether the Blocks data member has been assigned a value.
    bool IsSetBlocks(void) const;
    /// Check whether it is safe or not to call GetBlocks method.
    bool CanGetBlocks(void) const;
    void ResetBlocks(void);
    const TBlocks& GetBlocks(void) const;
    TBlocks& SetBlocks(void);

    /// (nblocks+1) constraints
    /// mandatory
    /// typedef list< CRef< CLoopConstraint > > TLoops
    ///  Check whether the Loops data member has been assigned a value.
    bool IsSetLoops(void) const;
    /// Check whether it is safe or not to call GetLoops method.
    bool CanGetLoops(void) const;
    void ResetLoops(void);
    const TLoops& GetLoops(void) const;
    TLoops& SetLoops(void);

    /// is it a discontinuous domain
    /// optional
    /// typedef bool TIsDiscontinuous
    ///  Check whether the IsDiscontinuous data member has been assigned a value.
    bool IsSetIsDiscontinuous(void) const;
    /// Check whether it is safe or not to call GetIsDiscontinuous method.
    bool CanGetIsDiscontinuous(void) const;
    void ResetIsDiscontinuous(void);
    TIsDiscontinuous GetIsDiscontinuous(void) const;
    void SetIsDiscontinuous(TIsDiscontinuous value);
    TIsDiscontinuous& SetIsDiscontinuous(void);

    /// positions of long insertions
    /// optional
    /// typedef list< int > TInsertions
    ///  Check whether the Insertions data member has been assigned a value.
    bool IsSetInsertions(void) const;
    /// Check whether it is safe or not to call GetInsertions method.
    bool CanGetInsertions(void) const;
    void ResetInsertions(void);
    const TInsertions& GetInsertions(void) const;
    TInsertions& SetInsertions(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CCoreDef_Base(const CCoreDef_Base&);
    CCoreDef_Base& operator=(const CCoreDef_Base&);

    // data
    Uint4 m_set_State[1];
    int m_Nblocks;
    list< CRef< CCoreBlock > > m_Blocks;
    list< CRef< CLoopConstraint > > m_Loops;
    bool m_IsDiscontinuous;
    list< int > m_Insertions;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CCoreDef_Base::IsSetNblocks(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CCoreDef_Base::CanGetNblocks(void) const
{
    return IsSetNblocks();
}

inline
void CCoreDef_Base::ResetNblocks(void)
{
    m_Nblocks = 0;
    m_set_State[0] &= ~0x3;
}

inline
CCoreDef_Base::TNblocks CCoreDef_Base::GetNblocks(void) const
{
    if (!CanGetNblocks()) {
        ThrowUnassigned(0);
    }
    return m_Nblocks;
}

inline
void CCoreDef_Base::SetNblocks(CCoreDef_Base::TNblocks value)
{
    m_Nblocks = value;
    m_set_State[0] |= 0x3;
}

inline
CCoreDef_Base::TNblocks& CCoreDef_Base::SetNblocks(void)
{
#ifdef _DEBUG
    if (!IsSetNblocks()) {
        memset(&m_Nblocks,UnassignedByte(),sizeof(m_Nblocks));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Nblocks;
}

inline
bool CCoreDef_Base::IsSetBlocks(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CCoreDef_Base::CanGetBlocks(void) const
{
    return true;
}

inline
const CCoreDef_Base::TBlocks& CCoreDef_Base::GetBlocks(void) const
{
    return m_Blocks;
}

inline
CCoreDef_Base::TBlocks& CCoreDef_Base::SetBlocks(void)
{
    m_set_State[0] |= 0x4;
    return m_Blocks;
}

inline
bool CCoreDef_Base::IsSetLoops(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CCoreDef_Base::CanGetLoops(void) const
{
    return true;
}

inline
const CCoreDef_Base::TLoops& CCoreDef_Base::GetLoops(void) const
{
    return m_Loops;
}

inline
CCoreDef_Base::TLoops& CCoreDef_Base::SetLoops(void)
{
    m_set_State[0] |= 0x10;
    return m_Loops;
}

inline
bool CCoreDef_Base::IsSetIsDiscontinuous(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CCoreDef_Base::CanGetIsDiscontinuous(void) const
{
    return IsSetIsDiscontinuous();
}

inline
void CCoreDef_Base::ResetIsDiscontinuous(void)
{
    m_IsDiscontinuous = 0;
    m_set_State[0] &= ~0xc0;
}

inline
CCoreDef_Base::TIsDiscontinuous CCoreDef_Base::GetIsDiscontinuous(void) const
{
    if (!CanGetIsDiscontinuous()) {
        ThrowUnassigned(3);
    }
    return m_IsDiscontinuous;
}

inline
void CCoreDef_Base::SetIsDiscontinuous(CCoreDef_Base::TIsDiscontinuous value)
{
    m_IsDiscontinuous = value;
    m_set_State[0] |= 0xc0;
}

inline
CCoreDef_Base::TIsDiscontinuous& CCoreDef_Base::SetIsDiscontinuous(void)
{
#ifdef _DEBUG
    if (!IsSetIsDiscontinuous()) {
        memset(&m_IsDiscontinuous,UnassignedByte(),sizeof(m_IsDiscontinuous));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_IsDiscontinuous;
}

inline
bool CCoreDef_Base::IsSetInsertions(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CCoreDef_Base::CanGetInsertions(void) const
{
    return true;
}

inline
const CCoreDef_Base::TInsertions& CCoreDef_Base::GetInsertions(void) const
{
    return m_Insertions;
}

inline
CCoreDef_Base::TInsertions& CCoreDef_Base::SetInsertions(void)
{
    m_set_State[0] |= 0x100;
    return m_Insertions;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SCOREMAT_COREDEF_BASE_HPP