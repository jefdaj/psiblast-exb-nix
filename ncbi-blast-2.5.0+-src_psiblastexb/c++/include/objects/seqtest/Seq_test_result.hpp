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

/// @file Seq_test_result.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'seqtest.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Seq_test_result_.hpp


#ifndef OBJECTS_SEQTEST_SEQ_TEST_RESULT_HPP
#define OBJECTS_SEQTEST_SEQ_TEST_RESULT_HPP


// generated includes
#include <objects/seqtest/Seq_test_result_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_SEQTEST_EXPORT CSeq_test_result : public CSeq_test_result_Base
{
    typedef CSeq_test_result_Base Tparent;
public:
    // constructor
    CSeq_test_result(void);
    // destructor
    ~CSeq_test_result(void);

private:
    // Prohibit copy constructor and assignment operator
    CSeq_test_result(const CSeq_test_result& value);
    CSeq_test_result& operator=(const CSeq_test_result& value);

};

/////////////////// CSeq_test_result inline methods

// constructor
inline
CSeq_test_result::CSeq_test_result(void)
{
}


/////////////////// end of CSeq_test_result inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQTEST_SEQ_TEST_RESULT_HPP
/* Original file checksum: lines: 86, chars: 2530, CRC32: acc2629 */