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

/// @file Entrezgene_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'entrezgene.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_ENTREZGENE_ENTREZGENE_BASE_HPP
#define OBJECTS_ENTREZGENE_ENTREZGENE_BASE_HPP

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
class CBioSource;
class CDbtag;
class CGene_commentary;
class CGene_ref;
class CGene_source;
class CGene_track;
class CMaps;
class CProt_ref;
class CRNA_ref;
class CXtra_Terms;


// generated classes

/////////////////////////////////////////////////////////////////////////////
///******************************************** 
/// Entrezgene is the "document" indexed in Entrez 
///  and presented in the full display 
/// It also contains the Entrez ID and date information 
///******************************************* 
class NCBI_ENTREZGENE_EXPORT CEntrezgene_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CEntrezgene_Base(void);
    // destructor
    virtual ~CEntrezgene_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /// type of Gene
    enum EType {
        eType_unknown           =   0,
        eType_tRNA              =   1,
        eType_rRNA              =   2,
        eType_snRNA             =   3,
        eType_scRNA             =   4,
        eType_snoRNA            =   5,
        eType_protein_coding    =   6,
        eType_pseudo            =   7,
        eType_transposon        =   8,
        eType_miscRNA           =   9,
        eType_ncRNA             =  10,
        eType_biological_region =  11,
        eType_other             = 255
    };
    
    /// Access to EType's attributes (values, names) as defined in spec
    static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EType)(void);
    
    // types
    typedef CGene_track TTrack_info;
    typedef int TType;
    typedef CBioSource TSource;
    typedef CGene_ref TGene;
    typedef CProt_ref TProt;
    typedef CRNA_ref TRna;
    typedef string TSummary;
    typedef list< CRef< CMaps > > TLocation;
    typedef CGene_source TGene_source;
    typedef list< CRef< CGene_commentary > > TLocus;
    typedef list< CRef< CGene_commentary > > TProperties;
    typedef list< CRef< CGene_commentary > > TRefgene;
    typedef list< CRef< CGene_commentary > > THomology;
    typedef list< CRef< CGene_commentary > > TComments;
    typedef list< CRef< CDbtag > > TUnique_keys;
    typedef list< string > TXtra_index_terms;
    typedef list< CRef< CXtra_Terms > > TXtra_properties;
    typedef list< CRef< CXtra_Terms > > TXtra_iq;
    typedef list< CRef< CDbtag > > TNon_unique_keys;

    // getters
    // setters

    /// not in submission, but in retrieval 
    /// optional
    /// typedef CGene_track TTrack_info
    ///  Check whether the Track_info data member has been assigned a value.
    bool IsSetTrack_info(void) const;
    /// Check whether it is safe or not to call GetTrack_info method.
    bool CanGetTrack_info(void) const;
    void ResetTrack_info(void);
    const TTrack_info& GetTrack_info(void) const;
    void SetTrack_info(TTrack_info& value);
    TTrack_info& SetTrack_info(void);

    /// mandatory
    /// typedef int TType
    ///  Check whether the Type data member has been assigned a value.
    bool IsSetType(void) const;
    /// Check whether it is safe or not to call GetType method.
    bool CanGetType(void) const;
    void ResetType(void);
    TType GetType(void) const;
    void SetType(TType value);
    TType& SetType(void);

    /// mandatory
    /// typedef CBioSource TSource
    ///  Check whether the Source data member has been assigned a value.
    bool IsSetSource(void) const;
    /// Check whether it is safe or not to call GetSource method.
    bool CanGetSource(void) const;
    void ResetSource(void);
    const TSource& GetSource(void) const;
    void SetSource(TSource& value);
    TSource& SetSource(void);

    /// for locus-tag see note 3
    /// mandatory
    /// typedef CGene_ref TGene
    ///  Check whether the Gene data member has been assigned a value.
    bool IsSetGene(void) const;
    /// Check whether it is safe or not to call GetGene method.
    bool CanGetGene(void) const;
    void ResetGene(void);
    const TGene& GetGene(void) const;
    void SetGene(TGene& value);
    TGene& SetGene(void);

    /// optional
    /// typedef CProt_ref TProt
    ///  Check whether the Prot data member has been assigned a value.
    bool IsSetProt(void) const;
    /// Check whether it is safe or not to call GetProt method.
    bool CanGetProt(void) const;
    void ResetProt(void);
    const TProt& GetProt(void) const;
    void SetProt(TProt& value);
    TProt& SetProt(void);

    /// optional
    /// typedef CRNA_ref TRna
    ///  Check whether the Rna data member has been assigned a value.
    bool IsSetRna(void) const;
    /// Check whether it is safe or not to call GetRna method.
    bool CanGetRna(void) const;
    void ResetRna(void);
    const TRna& GetRna(void) const;
    void SetRna(TRna& value);
    TRna& SetRna(void);

    /// short summary 
    /// optional
    /// typedef string TSummary
    ///  Check whether the Summary data member has been assigned a value.
    bool IsSetSummary(void) const;
    /// Check whether it is safe or not to call GetSummary method.
    bool CanGetSummary(void) const;
    void ResetSummary(void);
    const TSummary& GetSummary(void) const;
    void SetSummary(const TSummary& value);
    TSummary& SetSummary(void);

    /// optional
    /// typedef list< CRef< CMaps > > TLocation
    ///  Check whether the Location data member has been assigned a value.
    bool IsSetLocation(void) const;
    /// Check whether it is safe or not to call GetLocation method.
    bool CanGetLocation(void) const;
    void ResetLocation(void);
    const TLocation& GetLocation(void) const;
    TLocation& SetLocation(void);

    /// NCBI source to Entrez 
    /// optional
    /// typedef CGene_source TGene_source
    ///  Check whether the Gene_source data member has been assigned a value.
    bool IsSetGene_source(void) const;
    /// Check whether it is safe or not to call GetGene_source method.
    bool CanGetGene_source(void) const;
    void ResetGene_source(void);
    const TGene_source& GetGene_source(void) const;
    void SetGene_source(TGene_source& value);
    TGene_source& SetGene_source(void);

    /// location of gene on chromosome (if known)
    /// and all information about products
    /// (mRNA, proteins and so on)
    /// optional
    /// typedef list< CRef< CGene_commentary > > TLocus
    ///  Check whether the Locus data member has been assigned a value.
    bool IsSetLocus(void) const;
    /// Check whether it is safe or not to call GetLocus method.
    bool CanGetLocus(void) const;
    void ResetLocus(void);
    const TLocus& GetLocus(void) const;
    TLocus& SetLocus(void);

    /// optional
    /// typedef list< CRef< CGene_commentary > > TProperties
    ///  Check whether the Properties data member has been assigned a value.
    bool IsSetProperties(void) const;
    /// Check whether it is safe or not to call GetProperties method.
    bool CanGetProperties(void) const;
    void ResetProperties(void);
    const TProperties& GetProperties(void) const;
    TProperties& SetProperties(void);

    /// NG for this? 
    /// optional
    /// typedef list< CRef< CGene_commentary > > TRefgene
    ///  Check whether the Refgene data member has been assigned a value.
    bool IsSetRefgene(void) const;
    /// Check whether it is safe or not to call GetRefgene method.
    bool CanGetRefgene(void) const;
    void ResetRefgene(void);
    const TRefgene& GetRefgene(void) const;
    TRefgene& SetRefgene(void);

    /// optional
    /// typedef list< CRef< CGene_commentary > > THomology
    ///  Check whether the Homology data member has been assigned a value.
    bool IsSetHomology(void) const;
    /// Check whether it is safe or not to call GetHomology method.
    bool CanGetHomology(void) const;
    void ResetHomology(void);
    const THomology& GetHomology(void) const;
    THomology& SetHomology(void);

    /// optional
    /// typedef list< CRef< CGene_commentary > > TComments
    ///  Check whether the Comments data member has been assigned a value.
    bool IsSetComments(void) const;
    /// Check whether it is safe or not to call GetComments method.
    bool CanGetComments(void) const;
    void ResetComments(void);
    const TComments& GetComments(void) const;
    TComments& SetComments(void);

    /// see note 3
    /// optional
    /// typedef list< CRef< CDbtag > > TUnique_keys
    ///  Check whether the Unique_keys data member has been assigned a value.
    bool IsSetUnique_keys(void) const;
    /// Check whether it is safe or not to call GetUnique_keys method.
    bool CanGetUnique_keys(void) const;
    void ResetUnique_keys(void);
    const TUnique_keys& GetUnique_keys(void) const;
    TUnique_keys& SetUnique_keys(void);

    /// see note 2
    /// optional
    /// typedef list< string > TXtra_index_terms
    ///  Check whether the Xtra_index_terms data member has been assigned a value.
    bool IsSetXtra_index_terms(void) const;
    /// Check whether it is safe or not to call GetXtra_index_terms method.
    bool CanGetXtra_index_terms(void) const;
    void ResetXtra_index_terms(void);
    const TXtra_index_terms& GetXtra_index_terms(void) const;
    TXtra_index_terms& SetXtra_index_terms(void);

    /// see note 2
    /// optional
    /// typedef list< CRef< CXtra_Terms > > TXtra_properties
    ///  Check whether the Xtra_properties data member has been assigned a value.
    bool IsSetXtra_properties(void) const;
    /// Check whether it is safe or not to call GetXtra_properties method.
    bool CanGetXtra_properties(void) const;
    void ResetXtra_properties(void);
    const TXtra_properties& GetXtra_properties(void) const;
    TXtra_properties& SetXtra_properties(void);

    /// see note 2
    /// optional
    /// typedef list< CRef< CXtra_Terms > > TXtra_iq
    ///  Check whether the Xtra_iq data member has been assigned a value.
    bool IsSetXtra_iq(void) const;
    /// Check whether it is safe or not to call GetXtra_iq method.
    bool CanGetXtra_iq(void) const;
    void ResetXtra_iq(void);
    const TXtra_iq& GetXtra_iq(void) const;
    TXtra_iq& SetXtra_iq(void);

    /// optional
    /// typedef list< CRef< CDbtag > > TNon_unique_keys
    ///  Check whether the Non_unique_keys data member has been assigned a value.
    bool IsSetNon_unique_keys(void) const;
    /// Check whether it is safe or not to call GetNon_unique_keys method.
    bool CanGetNon_unique_keys(void) const;
    void ResetNon_unique_keys(void);
    const TNon_unique_keys& GetNon_unique_keys(void) const;
    TNon_unique_keys& SetNon_unique_keys(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CEntrezgene_Base(const CEntrezgene_Base&);
    CEntrezgene_Base& operator=(const CEntrezgene_Base&);

    // data
    Uint4 m_set_State[2];
    CRef< TTrack_info > m_Track_info;
    int m_Type;
    CRef< TSource > m_Source;
    CRef< TGene > m_Gene;
    CRef< TProt > m_Prot;
    CRef< TRna > m_Rna;
    string m_Summary;
    list< CRef< CMaps > > m_Location;
    CRef< TGene_source > m_Gene_source;
    list< CRef< CGene_commentary > > m_Locus;
    list< CRef< CGene_commentary > > m_Properties;
    list< CRef< CGene_commentary > > m_Refgene;
    list< CRef< CGene_commentary > > m_Homology;
    list< CRef< CGene_commentary > > m_Comments;
    list< CRef< CDbtag > > m_Unique_keys;
    list< string > m_Xtra_index_terms;
    list< CRef< CXtra_Terms > > m_Xtra_properties;
    list< CRef< CXtra_Terms > > m_Xtra_iq;
    list< CRef< CDbtag > > m_Non_unique_keys;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CEntrezgene_Base::IsSetTrack_info(void) const
{
    return m_Track_info.NotEmpty();
}

inline
bool CEntrezgene_Base::CanGetTrack_info(void) const
{
    return IsSetTrack_info();
}

inline
const CEntrezgene_Base::TTrack_info& CEntrezgene_Base::GetTrack_info(void) const
{
    if (!CanGetTrack_info()) {
        ThrowUnassigned(0);
    }
    return (*m_Track_info);
}

inline
bool CEntrezgene_Base::IsSetType(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CEntrezgene_Base::CanGetType(void) const
{
    return IsSetType();
}

inline
void CEntrezgene_Base::ResetType(void)
{
    m_Type = (EType)(0);
    m_set_State[0] &= ~0xc;
}

inline
CEntrezgene_Base::TType CEntrezgene_Base::GetType(void) const
{
    if (!CanGetType()) {
        ThrowUnassigned(1);
    }
    return m_Type;
}

inline
void CEntrezgene_Base::SetType(CEntrezgene_Base::TType value)
{
    m_Type = value;
    m_set_State[0] |= 0xc;
}

inline
CEntrezgene_Base::TType& CEntrezgene_Base::SetType(void)
{
#ifdef _DEBUG
    if (!IsSetType()) {
        memset(&m_Type,UnassignedByte(),sizeof(m_Type));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Type;
}

inline
bool CEntrezgene_Base::IsSetSource(void) const
{
    return m_Source.NotEmpty();
}

inline
bool CEntrezgene_Base::CanGetSource(void) const
{
    return true;
}

inline
const CEntrezgene_Base::TSource& CEntrezgene_Base::GetSource(void) const
{
    if ( !m_Source ) {
        const_cast<CEntrezgene_Base*>(this)->ResetSource();
    }
    return (*m_Source);
}

inline
CEntrezgene_Base::TSource& CEntrezgene_Base::SetSource(void)
{
    if ( !m_Source ) {
        ResetSource();
    }
    return (*m_Source);
}

inline
bool CEntrezgene_Base::IsSetGene(void) const
{
    return m_Gene.NotEmpty();
}

inline
bool CEntrezgene_Base::CanGetGene(void) const
{
    return true;
}

inline
const CEntrezgene_Base::TGene& CEntrezgene_Base::GetGene(void) const
{
    if ( !m_Gene ) {
        const_cast<CEntrezgene_Base*>(this)->ResetGene();
    }
    return (*m_Gene);
}

inline
CEntrezgene_Base::TGene& CEntrezgene_Base::SetGene(void)
{
    if ( !m_Gene ) {
        ResetGene();
    }
    return (*m_Gene);
}

inline
bool CEntrezgene_Base::IsSetProt(void) const
{
    return m_Prot.NotEmpty();
}

inline
bool CEntrezgene_Base::CanGetProt(void) const
{
    return IsSetProt();
}

inline
const CEntrezgene_Base::TProt& CEntrezgene_Base::GetProt(void) const
{
    if (!CanGetProt()) {
        ThrowUnassigned(4);
    }
    return (*m_Prot);
}

inline
bool CEntrezgene_Base::IsSetRna(void) const
{
    return m_Rna.NotEmpty();
}

inline
bool CEntrezgene_Base::CanGetRna(void) const
{
    return IsSetRna();
}

inline
const CEntrezgene_Base::TRna& CEntrezgene_Base::GetRna(void) const
{
    if (!CanGetRna()) {
        ThrowUnassigned(5);
    }
    return (*m_Rna);
}

inline
bool CEntrezgene_Base::IsSetSummary(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CEntrezgene_Base::CanGetSummary(void) const
{
    return IsSetSummary();
}

inline
const CEntrezgene_Base::TSummary& CEntrezgene_Base::GetSummary(void) const
{
    if (!CanGetSummary()) {
        ThrowUnassigned(6);
    }
    return m_Summary;
}

inline
void CEntrezgene_Base::SetSummary(const CEntrezgene_Base::TSummary& value)
{
    m_Summary = value;
    m_set_State[0] |= 0x3000;
}

inline
CEntrezgene_Base::TSummary& CEntrezgene_Base::SetSummary(void)
{
#ifdef _DEBUG
    if (!IsSetSummary()) {
        m_Summary = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1000;
    return m_Summary;
}

inline
bool CEntrezgene_Base::IsSetLocation(void) const
{
    return ((m_set_State[0] & 0xc000) != 0);
}

inline
bool CEntrezgene_Base::CanGetLocation(void) const
{
    return true;
}

inline
const CEntrezgene_Base::TLocation& CEntrezgene_Base::GetLocation(void) const
{
    return m_Location;
}

inline
CEntrezgene_Base::TLocation& CEntrezgene_Base::SetLocation(void)
{
    m_set_State[0] |= 0x4000;
    return m_Location;
}

inline
bool CEntrezgene_Base::IsSetGene_source(void) const
{
    return m_Gene_source.NotEmpty();
}

inline
bool CEntrezgene_Base::CanGetGene_source(void) const
{
    return IsSetGene_source();
}

inline
const CEntrezgene_Base::TGene_source& CEntrezgene_Base::GetGene_source(void) const
{
    if (!CanGetGene_source()) {
        ThrowUnassigned(8);
    }
    return (*m_Gene_source);
}

inline
bool CEntrezgene_Base::IsSetLocus(void) const
{
    return ((m_set_State[0] & 0xc0000) != 0);
}

inline
bool CEntrezgene_Base::CanGetLocus(void) const
{
    return true;
}

inline
const CEntrezgene_Base::TLocus& CEntrezgene_Base::GetLocus(void) const
{
    return m_Locus;
}

inline
CEntrezgene_Base::TLocus& CEntrezgene_Base::SetLocus(void)
{
    m_set_State[0] |= 0x40000;
    return m_Locus;
}

inline
bool CEntrezgene_Base::IsSetProperties(void) const
{
    return ((m_set_State[0] & 0x300000) != 0);
}

inline
bool CEntrezgene_Base::CanGetProperties(void) const
{
    return true;
}

inline
const CEntrezgene_Base::TProperties& CEntrezgene_Base::GetProperties(void) const
{
    return m_Properties;
}

inline
CEntrezgene_Base::TProperties& CEntrezgene_Base::SetProperties(void)
{
    m_set_State[0] |= 0x100000;
    return m_Properties;
}

inline
bool CEntrezgene_Base::IsSetRefgene(void) const
{
    return ((m_set_State[0] & 0xc00000) != 0);
}

inline
bool CEntrezgene_Base::CanGetRefgene(void) const
{
    return true;
}

inline
const CEntrezgene_Base::TRefgene& CEntrezgene_Base::GetRefgene(void) const
{
    return m_Refgene;
}

inline
CEntrezgene_Base::TRefgene& CEntrezgene_Base::SetRefgene(void)
{
    m_set_State[0] |= 0x400000;
    return m_Refgene;
}

inline
bool CEntrezgene_Base::IsSetHomology(void) const
{
    return ((m_set_State[0] & 0x3000000) != 0);
}

inline
bool CEntrezgene_Base::CanGetHomology(void) const
{
    return true;
}

inline
const CEntrezgene_Base::THomology& CEntrezgene_Base::GetHomology(void) const
{
    return m_Homology;
}

inline
CEntrezgene_Base::THomology& CEntrezgene_Base::SetHomology(void)
{
    m_set_State[0] |= 0x1000000;
    return m_Homology;
}

inline
bool CEntrezgene_Base::IsSetComments(void) const
{
    return ((m_set_State[0] & 0xc000000) != 0);
}

inline
bool CEntrezgene_Base::CanGetComments(void) const
{
    return true;
}

inline
const CEntrezgene_Base::TComments& CEntrezgene_Base::GetComments(void) const
{
    return m_Comments;
}

inline
CEntrezgene_Base::TComments& CEntrezgene_Base::SetComments(void)
{
    m_set_State[0] |= 0x4000000;
    return m_Comments;
}

inline
bool CEntrezgene_Base::IsSetUnique_keys(void) const
{
    return ((m_set_State[0] & 0x30000000) != 0);
}

inline
bool CEntrezgene_Base::CanGetUnique_keys(void) const
{
    return true;
}

inline
const CEntrezgene_Base::TUnique_keys& CEntrezgene_Base::GetUnique_keys(void) const
{
    return m_Unique_keys;
}

inline
CEntrezgene_Base::TUnique_keys& CEntrezgene_Base::SetUnique_keys(void)
{
    m_set_State[0] |= 0x10000000;
    return m_Unique_keys;
}

inline
bool CEntrezgene_Base::IsSetXtra_index_terms(void) const
{
    return ((m_set_State[0] & 0xc0000000) != 0);
}

inline
bool CEntrezgene_Base::CanGetXtra_index_terms(void) const
{
    return true;
}

inline
const CEntrezgene_Base::TXtra_index_terms& CEntrezgene_Base::GetXtra_index_terms(void) const
{
    return m_Xtra_index_terms;
}

inline
CEntrezgene_Base::TXtra_index_terms& CEntrezgene_Base::SetXtra_index_terms(void)
{
    m_set_State[0] |= 0x40000000;
    return m_Xtra_index_terms;
}

inline
bool CEntrezgene_Base::IsSetXtra_properties(void) const
{
    return ((m_set_State[1] & 0x3) != 0);
}

inline
bool CEntrezgene_Base::CanGetXtra_properties(void) const
{
    return true;
}

inline
const CEntrezgene_Base::TXtra_properties& CEntrezgene_Base::GetXtra_properties(void) const
{
    return m_Xtra_properties;
}

inline
CEntrezgene_Base::TXtra_properties& CEntrezgene_Base::SetXtra_properties(void)
{
    m_set_State[1] |= 0x1;
    return m_Xtra_properties;
}

inline
bool CEntrezgene_Base::IsSetXtra_iq(void) const
{
    return ((m_set_State[1] & 0xc) != 0);
}

inline
bool CEntrezgene_Base::CanGetXtra_iq(void) const
{
    return true;
}

inline
const CEntrezgene_Base::TXtra_iq& CEntrezgene_Base::GetXtra_iq(void) const
{
    return m_Xtra_iq;
}

inline
CEntrezgene_Base::TXtra_iq& CEntrezgene_Base::SetXtra_iq(void)
{
    m_set_State[1] |= 0x4;
    return m_Xtra_iq;
}

inline
bool CEntrezgene_Base::IsSetNon_unique_keys(void) const
{
    return ((m_set_State[1] & 0x30) != 0);
}

inline
bool CEntrezgene_Base::CanGetNon_unique_keys(void) const
{
    return true;
}

inline
const CEntrezgene_Base::TNon_unique_keys& CEntrezgene_Base::GetNon_unique_keys(void) const
{
    return m_Non_unique_keys;
}

inline
CEntrezgene_Base::TNon_unique_keys& CEntrezgene_Base::SetNon_unique_keys(void)
{
    m_set_State[1] |= 0x10;
    return m_Non_unique_keys;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ENTREZGENE_ENTREZGENE_BASE_HPP
