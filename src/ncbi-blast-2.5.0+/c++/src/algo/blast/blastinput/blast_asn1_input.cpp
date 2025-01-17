/*  $Id: blast_asn1_input.cpp 504861 2016-06-20 15:45:40Z boratyng $
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
 * Author:  Greg Boratyn
 *
 */

/** @file blast_asn1_input.cpp
 * Convert ASN1-formatted files into blast sequence input
 */

#include <ncbi_pch.hpp>
#include <objmgr/util/sequence.hpp>

#include <objects/seq/Bioseq.hpp>
#include <objects/seq/Seq_descr.hpp>
#include <objects/general/User_object.hpp>

#include <algo/blast/blastinput/blast_input_aux.hpp>
#include <algo/blast/blastinput/blast_asn1_input.hpp>
#include <util/sequtil/sequtil_convert.hpp>

BEGIN_NCBI_SCOPE
BEGIN_SCOPE(blast)
USING_SCOPE(objects);


CASN1InputSourceOMF::CASN1InputSourceOMF(CNcbiIstream& infile,
                                         TSeqPos num_seqs,
                                         bool is_bin,
                                         bool is_paired,
                                         bool validate)
    : m_NumSeqsInBatch(num_seqs),
      m_InputStream(&infile),
      m_SecondInputStream(NULL),
      m_IsPaired(is_paired),
      m_Validate(validate),
      m_IsBinary(is_bin)
{}

CASN1InputSourceOMF::CASN1InputSourceOMF(CNcbiIstream& infile1,
                                         CNcbiIstream& infile2,
                                         TSeqPos num_seqs,
                                         bool is_bin,
                                         bool validate)
    : m_NumSeqsInBatch(num_seqs),
      m_InputStream(&infile1),
      m_SecondInputStream(&infile2),
      m_IsPaired(true),
      m_Validate(validate),
      m_IsBinary(is_bin)
{}


void
CASN1InputSourceOMF::GetNextNumSequences(CBioseq_set& bioseq_set,
                                         TSeqPos /* num_seqs */)
{
    // preallocate memory for sequences to be read
    m_Entries.clear();

    // +1 in case we need to read one more sequence so that a pair is not
    // broken
    m_Entries.resize(m_NumSeqsInBatch + 1);

    if (m_SecondInputStream) {
        x_ReadFromTwoFiles(bioseq_set);
    }
    else {
        x_ReadFromSingleFile(bioseq_set);
    }

    // detach CRefs in m_Entries from objects in bioseq_set for thread safety
    m_Entries.clear();
}


int
CASN1InputSourceOMF::x_ReadOneSeq(CNcbiIstream& instream)
{
    CTempString line;
    CTempString id;
    int retval = -1;

    CRef<CSeq_entry> seq_entry(new CSeq_entry);
    try {
        if (m_IsBinary) {
            instream >> MSerial_AsnBinary >> *seq_entry;
        }
        else {
            instream >> MSerial_AsnText >> *seq_entry;
        }
    }
    catch (...) {
        if (instream.eof()) {
            return -1;
        }

        NCBI_THROW(CInputException, eInvalidInput, "Problem reading ASN1 entry");
    }

    if (!m_Validate ||
        x_ValidateSequence(seq_entry->GetSeq().GetInst().GetSeq_data(),
                           seq_entry->GetSeq().GetInst().GetLength())) {

        m_Entries[m_Index] = seq_entry;
        retval = m_Index;
        m_Index++;
    }

    return retval;
}


bool
CASN1InputSourceOMF::x_ReadFromSingleFile(CBioseq_set& bioseq_set)
{
    int current_read = 0;
    bool first_added = false;

    CRef<CSeqdesc> seqdesc(new CSeqdesc);
    seqdesc->SetUser().SetType().SetStr("Mapping");
    seqdesc->SetUser().AddField("has_pair", true);

    m_Index = 0;
    while (m_Index < (int)m_NumSeqsInBatch && !m_InputStream->eof()) {
        int index = x_ReadOneSeq(*m_InputStream);

        if (index >= 0) {

            if (m_IsPaired && (current_read & 1) == 0) {
                first_added = true;
            }

            if (m_IsPaired && (current_read & 1) == 1) {
                if (first_added) {
                    bioseq_set.SetSeq_set().back()->SetSeq().SetDescr().Set().push_back(seqdesc);
                }
                first_added = false;
            }

            bioseq_set.SetSeq_set().push_back(m_Entries[index]);
        }
        else {
            first_added = false;
        }
        current_read++;
    }

    return true;
}


bool
CASN1InputSourceOMF::x_ReadFromTwoFiles(CBioseq_set& bioseq_set)
{
    CRef<CSeqdesc> seqdesc(new CSeqdesc);
    seqdesc->SetUser().SetType().SetStr("Mapping");
    seqdesc->SetUser().AddField("has_pair", true);

    int index1;
    int index2;
    m_Index = 0;
    while (m_Index < (int)m_NumSeqsInBatch && !m_InputStream->eof() &&
           !m_SecondInputStream->eof()) {

        index1 = x_ReadOneSeq(*m_InputStream); 
        index2 = x_ReadOneSeq(*m_SecondInputStream);

        // if both sequences were read, set mark the pair in the first one
        if (index1 >= 0 && index2 >= 0) {
            CBioseq& bioseq = m_Entries[index1]->SetSeq();
            bioseq.SetDescr().Set().push_back(seqdesc);
        }

        if (index1 >= 0) {
            bioseq_set.SetSeq_set().push_back(m_Entries[index1]);
        }

        if (index2 >= 0) {
            bioseq_set.SetSeq_set().push_back(m_Entries[index2]);
        }
    }

    return true;
}


bool CASN1InputSourceOMF::x_ValidateSequence(const CSeq_data& seq_data,
                                             int length)
{
    string sequence;
    int entropy;

    switch (seq_data.Which()) {

    case CSeq_data::e_Ncbi2na:
        // Ncbi2na format does not have ambiguous bases, hence only compute
        // entropy and exit
        entropy = x_FindDimerEntropy2NA(seq_data.GetNcbi2na().Get(), length);
        return entropy > 16;


    case CSeq_data::e_Ncbi4na:
        // convert sequence to Iupac
        CSeqConvert::Convert(seq_data.GetNcbi4na().Get(),
                             CSeqUtil::e_Ncbi4na, 0, length,
                             sequence, CSeqUtil::e_Iupacna);
        break;
            
    case CSeq_data::e_Ncbi8na:
        // convert sequence to Iupac
        CSeqConvert::Convert(seq_data.GetNcbi8na().Get(),
                             CSeqUtil::e_Ncbi8na, 0, length,
                             sequence, CSeqUtil::e_Iupacna);
        break;

    case CSeq_data::e_Iupacna:
        sequence.resize(length);
        memcpy(&sequence[0], seq_data.GetIupacna().Get().c_str(),
               length * sizeof(Uint1));
        break;

    default:
        NCBI_THROW(CInputException, eInvalidInput, "Encoding not handled "
                   "for input sequences");

    };

    // find number of ambiguous bases
    const char* s = sequence.c_str();
    const int kNBase = (int)'N';
    const double kMaxFractionAmbiguousBases = 0.5;
    int num = 0;
    for (int i=0;i < length;i++) {
        num += (toupper((int)s[i]) == kNBase);
    }

    if ((double)num / length > kMaxFractionAmbiguousBases) {
        return false;
    }

    // find dimer entropy
    entropy = FindDimerEntropy(sequence.c_str(), length);
    return entropy > 16;
}


int CASN1InputSourceOMF::x_FindDimerEntropy2NA(const vector<char>& sequence,
                                               int length)
{
    const int kNumDimers = 1 << 4;
    int counts[kNumDimers];
    memset(counts, 0, kNumDimers * sizeof(int));
    int num = 0;
    Uint1 mask = 0xc0;
    Uint1 base;
    int dimer;
    int k = 0;
    int i = 0;

    // count dimers
    dimer = (sequence[i] & (mask >> k)) >> (2*(3 - k));
    k++;
    num++;
    while (num < length) {
        _ASSERT(i < (int)sequence.size());
        for (;k < 4;k++) {
            base = (sequence[i] & (mask >> k)) >> (2*(3 - k));
            dimer = ((dimer << 2) | base) & 0xf;
            counts[dimer]++;
            num++;
        }
        k = 0;
        i++;
    }

    // compute amount of information in the sequence
    double sum = 0.0;
    for (int i=0;i < kNumDimers;i++) {
        if (counts[i]) {
            sum += (double)counts[i] * log((double)counts[i] / num);
        }
    }

    return -sum * (1.0 /(log(16.0))) + 0.5;
}


END_SCOPE(blast)
END_NCBI_SCOPE
