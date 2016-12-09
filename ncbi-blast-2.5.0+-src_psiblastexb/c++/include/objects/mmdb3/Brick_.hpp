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

/// @file Brick_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'mmdb3.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MMDB3_BRICK_BASE_HPP
#define OBJECTS_MMDB3_BRICK_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CModel_space_point;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// A brick is defined by the coordinates of eight corners.  These are assumed
/// to appear in the order 000, 001, 010, 011, 100, 101, 110, 111, where the 
/// digits 0 and 1 refer to respectively to the x, y and z axes of a unit cube.
/// Opposite edges are assumed to be parallel. 
class NCBI_MMDB3_EXPORT CBrick_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CBrick_Base(void);
    // destructor
    virtual ~CBrick_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CModel_space_point TCorner_000;
    typedef CModel_space_point TCorner_001;
    typedef CModel_space_point TCorner_010;
    typedef CModel_space_point TCorner_011;
    typedef CModel_space_point TCorner_100;
    typedef CModel_space_point TCorner_101;
    typedef CModel_space_point TCorner_110;
    typedef CModel_space_point TCorner_111;

    // getters
    // setters

    /// mandatory
    /// typedef CModel_space_point TCorner_000
    ///  Check whether the Corner_000 data member has been assigned a value.
    bool IsSetCorner_000(void) const;
    /// Check whether it is safe or not to call GetCorner_000 method.
    bool CanGetCorner_000(void) const;
    void ResetCorner_000(void);
    const TCorner_000& GetCorner_000(void) const;
    void SetCorner_000(TCorner_000& value);
    TCorner_000& SetCorner_000(void);

    /// mandatory
    /// typedef CModel_space_point TCorner_001
    ///  Check whether the Corner_001 data member has been assigned a value.
    bool IsSetCorner_001(void) const;
    /// Check whether it is safe or not to call GetCorner_001 method.
    bool CanGetCorner_001(void) const;
    void ResetCorner_001(void);
    const TCorner_001& GetCorner_001(void) const;
    void SetCorner_001(TCorner_001& value);
    TCorner_001& SetCorner_001(void);

    /// mandatory
    /// typedef CModel_space_point TCorner_010
    ///  Check whether the Corner_010 data member has been assigned a value.
    bool IsSetCorner_010(void) const;
    /// Check whether it is safe or not to call GetCorner_010 method.
    bool CanGetCorner_010(void) const;
    void ResetCorner_010(void);
    const TCorner_010& GetCorner_010(void) const;
    void SetCorner_010(TCorner_010& value);
    TCorner_010& SetCorner_010(void);

    /// mandatory
    /// typedef CModel_space_point TCorner_011
    ///  Check whether the Corner_011 data member has been assigned a value.
    bool IsSetCorner_011(void) const;
    /// Check whether it is safe or not to call GetCorner_011 method.
    bool CanGetCorner_011(void) const;
    void ResetCorner_011(void);
    const TCorner_011& GetCorner_011(void) const;
    void SetCorner_011(TCorner_011& value);
    TCorner_011& SetCorner_011(void);

    /// mandatory
    /// typedef CModel_space_point TCorner_100
    ///  Check whether the Corner_100 data member has been assigned a value.
    bool IsSetCorner_100(void) const;
    /// Check whether it is safe or not to call GetCorner_100 method.
    bool CanGetCorner_100(void) const;
    void ResetCorner_100(void);
    const TCorner_100& GetCorner_100(void) const;
    void SetCorner_100(TCorner_100& value);
    TCorner_100& SetCorner_100(void);

    /// mandatory
    /// typedef CModel_space_point TCorner_101
    ///  Check whether the Corner_101 data member has been assigned a value.
    bool IsSetCorner_101(void) const;
    /// Check whether it is safe or not to call GetCorner_101 method.
    bool CanGetCorner_101(void) const;
    void ResetCorner_101(void);
    const TCorner_101& GetCorner_101(void) const;
    void SetCorner_101(TCorner_101& value);
    TCorner_101& SetCorner_101(void);

    /// mandatory
    /// typedef CModel_space_point TCorner_110
    ///  Check whether the Corner_110 data member has been assigned a value.
    bool IsSetCorner_110(void) const;
    /// Check whether it is safe or not to call GetCorner_110 method.
    bool CanGetCorner_110(void) const;
    void ResetCorner_110(void);
    const TCorner_110& GetCorner_110(void) const;
    void SetCorner_110(TCorner_110& value);
    TCorner_110& SetCorner_110(void);

    /// mandatory
    /// typedef CModel_space_point TCorner_111
    ///  Check whether the Corner_111 data member has been assigned a value.
    bool IsSetCorner_111(void) const;
    /// Check whether it is safe or not to call GetCorner_111 method.
    bool CanGetCorner_111(void) const;
    void ResetCorner_111(void);
    const TCorner_111& GetCorner_111(void) const;
    void SetCorner_111(TCorner_111& value);
    TCorner_111& SetCorner_111(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CBrick_Base(const CBrick_Base&);
    CBrick_Base& operator=(const CBrick_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TCorner_000 > m_Corner_000;
    CRef< TCorner_001 > m_Corner_001;
    CRef< TCorner_010 > m_Corner_010;
    CRef< TCorner_011 > m_Corner_011;
    CRef< TCorner_100 > m_Corner_100;
    CRef< TCorner_101 > m_Corner_101;
    CRef< TCorner_110 > m_Corner_110;
    CRef< TCorner_111 > m_Corner_111;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CBrick_Base::IsSetCorner_000(void) const
{
    return m_Corner_000.NotEmpty();
}

inline
bool CBrick_Base::CanGetCorner_000(void) const
{
    return true;
}

inline
const CBrick_Base::TCorner_000& CBrick_Base::GetCorner_000(void) const
{
    if ( !m_Corner_000 ) {
        const_cast<CBrick_Base*>(this)->ResetCorner_000();
    }
    return (*m_Corner_000);
}

inline
CBrick_Base::TCorner_000& CBrick_Base::SetCorner_000(void)
{
    if ( !m_Corner_000 ) {
        ResetCorner_000();
    }
    return (*m_Corner_000);
}

inline
bool CBrick_Base::IsSetCorner_001(void) const
{
    return m_Corner_001.NotEmpty();
}

inline
bool CBrick_Base::CanGetCorner_001(void) const
{
    return true;
}

inline
const CBrick_Base::TCorner_001& CBrick_Base::GetCorner_001(void) const
{
    if ( !m_Corner_001 ) {
        const_cast<CBrick_Base*>(this)->ResetCorner_001();
    }
    return (*m_Corner_001);
}

inline
CBrick_Base::TCorner_001& CBrick_Base::SetCorner_001(void)
{
    if ( !m_Corner_001 ) {
        ResetCorner_001();
    }
    return (*m_Corner_001);
}

inline
bool CBrick_Base::IsSetCorner_010(void) const
{
    return m_Corner_010.NotEmpty();
}

inline
bool CBrick_Base::CanGetCorner_010(void) const
{
    return true;
}

inline
const CBrick_Base::TCorner_010& CBrick_Base::GetCorner_010(void) const
{
    if ( !m_Corner_010 ) {
        const_cast<CBrick_Base*>(this)->ResetCorner_010();
    }
    return (*m_Corner_010);
}

inline
CBrick_Base::TCorner_010& CBrick_Base::SetCorner_010(void)
{
    if ( !m_Corner_010 ) {
        ResetCorner_010();
    }
    return (*m_Corner_010);
}

inline
bool CBrick_Base::IsSetCorner_011(void) const
{
    return m_Corner_011.NotEmpty();
}

inline
bool CBrick_Base::CanGetCorner_011(void) const
{
    return true;
}

inline
const CBrick_Base::TCorner_011& CBrick_Base::GetCorner_011(void) const
{
    if ( !m_Corner_011 ) {
        const_cast<CBrick_Base*>(this)->ResetCorner_011();
    }
    return (*m_Corner_011);
}

inline
CBrick_Base::TCorner_011& CBrick_Base::SetCorner_011(void)
{
    if ( !m_Corner_011 ) {
        ResetCorner_011();
    }
    return (*m_Corner_011);
}

inline
bool CBrick_Base::IsSetCorner_100(void) const
{
    return m_Corner_100.NotEmpty();
}

inline
bool CBrick_Base::CanGetCorner_100(void) const
{
    return true;
}

inline
const CBrick_Base::TCorner_100& CBrick_Base::GetCorner_100(void) const
{
    if ( !m_Corner_100 ) {
        const_cast<CBrick_Base*>(this)->ResetCorner_100();
    }
    return (*m_Corner_100);
}

inline
CBrick_Base::TCorner_100& CBrick_Base::SetCorner_100(void)
{
    if ( !m_Corner_100 ) {
        ResetCorner_100();
    }
    return (*m_Corner_100);
}

inline
bool CBrick_Base::IsSetCorner_101(void) const
{
    return m_Corner_101.NotEmpty();
}

inline
bool CBrick_Base::CanGetCorner_101(void) const
{
    return true;
}

inline
const CBrick_Base::TCorner_101& CBrick_Base::GetCorner_101(void) const
{
    if ( !m_Corner_101 ) {
        const_cast<CBrick_Base*>(this)->ResetCorner_101();
    }
    return (*m_Corner_101);
}

inline
CBrick_Base::TCorner_101& CBrick_Base::SetCorner_101(void)
{
    if ( !m_Corner_101 ) {
        ResetCorner_101();
    }
    return (*m_Corner_101);
}

inline
bool CBrick_Base::IsSetCorner_110(void) const
{
    return m_Corner_110.NotEmpty();
}

inline
bool CBrick_Base::CanGetCorner_110(void) const
{
    return true;
}

inline
const CBrick_Base::TCorner_110& CBrick_Base::GetCorner_110(void) const
{
    if ( !m_Corner_110 ) {
        const_cast<CBrick_Base*>(this)->ResetCorner_110();
    }
    return (*m_Corner_110);
}

inline
CBrick_Base::TCorner_110& CBrick_Base::SetCorner_110(void)
{
    if ( !m_Corner_110 ) {
        ResetCorner_110();
    }
    return (*m_Corner_110);
}

inline
bool CBrick_Base::IsSetCorner_111(void) const
{
    return m_Corner_111.NotEmpty();
}

inline
bool CBrick_Base::CanGetCorner_111(void) const
{
    return true;
}

inline
const CBrick_Base::TCorner_111& CBrick_Base::GetCorner_111(void) const
{
    if ( !m_Corner_111 ) {
        const_cast<CBrick_Base*>(this)->ResetCorner_111();
    }
    return (*m_Corner_111);
}

inline
CBrick_Base::TCorner_111& CBrick_Base::SetCorner_111(void)
{
    if ( !m_Corner_111 ) {
        ResetCorner_111();
    }
    return (*m_Corner_111);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MMDB3_BRICK_BASE_HPP