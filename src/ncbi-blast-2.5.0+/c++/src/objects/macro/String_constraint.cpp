/* $Id: String_constraint.cpp 510214 2016-08-11 15:06:21Z ivanov $
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
 * Author:  J. Chen
 *
 * File Description:
 *   Evaluate if a string and an object match to CString_constraint
 *
 * Remark:
 *   This code was originally generated by application DATATOOL
 *   using the following specifications:
 *   'macro.asn'.
 */

// standard includes
#include <ncbi_pch.hpp>

// generated includes
#include <objects/macro/String_constraint.hpp>
#include <objects/seqfeat/Seq_feat.hpp>
#include <objects/seqfeat/Imp_feat.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

// destructor
CString_constraint::~CString_constraint(void)
{
}

bool CString_constraint :: Empty() const
{
   if (GetIs_all_caps() ||
       GetIs_all_lower() ||
       GetIs_all_punct() ||
       GetIs_first_cap() ||
       GetIs_first_each_cap()) {
      return false;
   } else if (!CanGetMatch_text() || GetMatch_text().empty()) {
        return true;
   }

   return false;
}

bool CString_constraint :: x_IsAllCaps(const string& str) const
{
  string up_str(str);
  NStr::ToUpper(up_str);
  return NStr::EqualCase(up_str, str);
}

bool CString_constraint :: x_IsAllLowerCase(const string& str) const
{
  string low_str(str);
  NStr::ToLower(low_str);
  return NStr::EqualCase(low_str, str);
}

bool CString_constraint :: x_IsAllPunctuation(const string& str) const
{
   for (unsigned i=0; i< str.size(); i++) {
     if (!ispunct(Uint1(str[i]))) return false;
   }
   return true;
}

bool CString_constraint::x_IsSkippable(const char ch) const
{
    if (ispunct(ch) && GetIgnore_punct()) {
        return true;
    } else if (isspace(ch) && GetIgnore_space()) {
        return true;
    } else {
        return false;
    }
}

bool CString_constraint::x_IsAllSkippable(const string& str) const
{
    for (unsigned i = 0; i < str.size(); i++) {
        if (!x_IsSkippable(Uint1(str[i]))) {
            return false;
        }
    }
    return true;
}

bool CString_constraint :: x_IsFirstCap(const string& str) const
{
    // ignore punctuation and spaces at the beginning of the phrase
    string::const_iterator it = str.begin();
    while (it != str.end() && !isalpha((unsigned char) (*it))) {
    if (isdigit( (unsigned char) (*it))) {
        return false;
    }
        ++it;
    }

    if (it != str.end()) {
        return isalpha((unsigned char) (*it)) && isupper((unsigned char) (*it));
    }
    return false;
}

bool CString_constraint :: x_IsFirstEachCap(const string& str) const
{
    bool first(true);
    bool rval(true);
    for (size_t i = 0; i < str.size() && rval; ++i) {
        if (isalpha( (unsigned char) str[i])) {
            if (first) {
                rval = rval && isupper( (unsigned char) str[i] );
                first = false;
            } 
        } else if ( str[i] == '-' ){
            // hyphenated words are considered as one composed word
            if ((i > 0 && !isalpha( (unsigned char) str[i - 1])) || 
                (i + 1 < str.size() && !isalpha( (unsigned char) str[i + 1] ))) 
                first = true;
        } else if (isdigit( (unsigned char) str[i])){
            if (i + 1 < str.size() && isalpha( (unsigned char) str[i + 1])) {
                rval = false;
            }
        } else {
            first = true;
        }
    }
    return rval;
}


static const char* weasels[] = {
  "candidate",
  "hypothetical",
  "novel",
  "possible",
  "potential",
  "predicted",
  "probable",
  "putative",
  "candidate",
  "uncharacterized",
  "unique"
};

bool CString_constraint::x_IsWeasel(const string& str) const
{
    size_t n = ArraySize(weasels);
    for (size_t i = 0; i < n; i++) {
        if (str == weasels[i]) {
            return true;
        }
    }
    return false;
};

string CString_constraint :: x_SkipWeasel(const string& str) const
{
  if (str.empty()) {
    return kEmptyStr;
  }
  string ret_str;
  vector<string> arr;
  arr = NStr::Tokenize(str, " ", arr);

  bool found = false;
  while (!arr.empty() && x_IsWeasel(arr[0])) {
     arr.erase(arr.begin());
     found = true;
  }
  
  ret_str = found ? NStr::Join(arr, " ") : str;

  return ret_str;
};

bool CString_constraint :: x_CaseNCompareEqual(string str1, string str2, size_t len1, bool case_sensitive) const
{
   if (!len1) return false;
   string comp_str1, comp_str2;
   comp_str1 = CTempString(str1).substr(0, len1);
   comp_str2 = CTempString(str2).substr(0, len1);
   if (case_sensitive) {
       return (comp_str1 == comp_str2);
   }
   else {
     return (NStr::EqualNocase(comp_str1, 0, len1, comp_str2));
   }
};

string CString_constraint :: x_StripUnimportantCharacters(const string& str, bool strip_space, bool strip_punct) const
{
   if (str.empty()) {
      return kEmptyStr;
   }
   string result;
   result.reserve(str.size());
   string::const_iterator it = str.begin();
   do {
      if ((strip_space && isspace(Uint1(*it))) || (strip_punct && ispunct(Uint1(*it))));
      else result += *it;
   } while (++it != str.end());

   return result;
};

bool CString_constraint :: x_DisallowCharacter(const char ch, bool disallow_slash) const
{
  if (isalpha (Uint1(ch)) || isdigit (Uint1(ch)) || ch == '_' || ch == '-') return true;
  else if (disallow_slash && ch == '/') return true;
  else return false;
};

bool CString_constraint :: x_IsWholeWordMatch(const string& start, size_t found, size_t match_len, bool disallow_slash) const
{
  size_t after_idx;

  if (!match_len) return true;
  else if (start.empty() || found == string::npos) return false;
  else
  {
    if (found) {
      if (x_DisallowCharacter (start[found-1], disallow_slash)) {
         return false;
      }
    }
    after_idx = found + match_len;
    if ( after_idx < start.size()
              && x_DisallowCharacter(start[after_idx], disallow_slash)) {
       return false;
    }
  }
  return true;
};


bool CString_constraint :: x_PartialCompare(const string& str, const string& pattern, char prev_char, size_t & match_len) const
{
    // check for synonyms to skip
    if (IsSetIgnore_words()) {
        ITERATE(CWord_substitution_set::Tdata, word, GetIgnore_words().Get()) {
            vector<size_t> match_lens = (*word)->GetMatchLens(str, pattern, prev_char);
            if (match_lens.size() > 0) {
                size_t word_len = (*word)->GetWord().length();
                ITERATE(vector<size_t>, len, match_lens) {
                    size_t this_match = 0;
                    char this_prev_char = 0;
                    if (*len > 0) {
                        this_prev_char = str.c_str()[(*len) - 1];
                    } else {
                        this_prev_char = prev_char;
                    }
                    bool require_end = false;
                    if (GetMatch_location() == eString_location_equals || GetMatch_location() == eString_location_ends) {
                        require_end = true;
                    }
                    if (x_PartialCompare(str.substr(*len), pattern.substr(word_len), this_prev_char, this_match) &&
                        (!require_end || this_match == str.substr(*len).length())) {
                        match_len += *len;
                        match_len += this_match;                        
                        return true;
                    }
                }
            }
        }
    }

    if (pattern.length() == 0) {
        return true;
    }

    if (str.length() == 0) {
        if (x_IsAllSkippable(pattern)) {
            return true;
        }
        // special case: can continue if the next character is a space, might have words to ignore
        if (isspace(pattern[0])) {
            return x_PartialCompare(str, pattern.substr(1), ' ', match_len);
        } else {
            return false;
        }
    }
    if (GetIgnore_space()) {
        if (isspace(Uint1(str[0]))) {
            match_len++;
            return x_PartialCompare(str.substr(1), pattern, str[0], match_len);
        } else if (isspace(Uint1(pattern[0]))) {
            return x_PartialCompare(str, pattern.substr(1), prev_char, match_len);
        }
    }
    if (GetIgnore_punct()) {
        if (ispunct(Uint1(str[0]))) {
            match_len++;
            return x_PartialCompare(str.substr(1), pattern, str[0], match_len);
        } else if (ispunct(Uint1(pattern[0]))) {
            return x_PartialCompare(str, pattern.substr(1), prev_char, match_len);
        }
    }
    if (str[0] == pattern[0]) {
        match_len++;
        return x_PartialCompare(str.substr(1), pattern.substr(1), str[0], match_len);
    } else if ((!IsSetCase_sensitive() || !GetCase_sensitive()) &&
               tolower(Uint1(str[0])) == tolower(Uint1(pattern[0]))) {
        match_len++;
        return x_PartialCompare(str.substr(1), pattern.substr(1), str[0], match_len);
    }
        
    return false;
}


bool CString_constraint :: x_AdvancedStringCompare(const string& str, const string& str_match, const char prev_char, size_t * ini_target_match_len)  const
{
    bool rval = false;
    size_t match_len = 0;
    if (x_PartialCompare(str, str_match, prev_char, match_len)) {
        if (ini_target_match_len != NULL) {
            *ini_target_match_len = match_len;
        }
        rval = true;
    }

    return rval;
};

bool CString_constraint :: x_AdvancedStringMatch(const string& str, const string& tmp_match) const
{
  bool rval = false;
  string
    match_text = CanGetMatch_text() ? tmp_match : kEmptyStr;

  size_t match_len = 0;

  if (x_AdvancedStringCompare (str, match_text, 0, &match_len) &&
      (GetMatch_location() != eString_location_equals || match_len == str.length())) {
       return true;
  }
  else if (GetMatch_location() == eString_location_starts
                || GetMatch_location() == eString_location_equals) {
           return false;
  }
  else {
    size_t pos = 1;
    size_t len = str.size();
    while (!rval && pos < len) {
      if (GetWhole_word()) {
          while (pos < len && isalpha (Uint1(str[pos-1]))) pos++;
      }
      if (pos < len) {
        if (x_AdvancedStringCompare (CTempString(str).substr(pos),
                                      match_text,
                                      0)) {
            rval = true;
        }
        else {
            pos++;
        }
      }
    }
  }
  return rval;
};

bool CString_constraint :: x_GetSpanFromHyphenInString(const string& str, size_t hyphen, string& first, string& second) const
{
   if (!hyphen) return false;

   /* find range start */
   size_t cp = str.substr(0, hyphen-1).find_last_not_of(' ');   
   if (cp != string::npos) {
      cp = str.substr(0, cp).find_last_not_of(" ,;"); 
   }
   if (cp == string::npos) {
     cp = 0;
   }

   size_t len = hyphen - cp;
   first = CTempString(str).substr(cp, len);
   NStr::TruncateSpacesInPlace(first);
 
   /* find range end */
   cp = str.find_first_not_of(' ', hyphen+1);
   if (cp != string::npos) {
      cp = str.find_first_not_of(" ,;");
   }
   if (cp == string::npos) {
      cp = str.size() -1;   
   }

   len = cp - hyphen;
   if (!isspace (Uint1(str[cp]))) {
     len--;
   }
   second = CTempString(str).substr(hyphen+1, len);
   NStr::TruncateSpacesInPlace(second);

   bool rval = true;
   if (first.empty() || second.empty()) {
      rval = false;
   }
   else if (!isdigit (Uint1(first[first.size() - 1])) 
                 || !isdigit (Uint1(second[second.size() - 1]))) {
      /* if this is a span, then neither end point can end with anything other than a number */
      rval = false;
   }
   if (!rval) {
      first = second = kEmptyStr;
   }
   return rval;
};

bool CString_constraint :: x_StringIsPositiveAllDigits(const string& str) const
{
   if (str.find_first_not_of(m_digit_str) != string::npos) {
      return false;
   }

   return true;
}

bool CString_constraint :: x_IsStringInSpan(const string& str, const string& first, const string& second) const
{
  string new_first, new_second, new_str;
  if (str.empty()) return false;
  else if (str == first || str == second) return true;
  else if (first.empty() || second.empty()) return false;

  int str_num, first_num, second_num;
  str_num = first_num = second_num = 0;
  bool rval = false;
  size_t prefix_len;
  string comp_str1, comp_str2;
  if (x_StringIsPositiveAllDigits (first)) {
    if (x_StringIsPositiveAllDigits (str) 
             && x_StringIsPositiveAllDigits (second)) {
      str_num = NStr::StringToUInt (str);
      first_num = NStr::StringToUInt (first);
      second_num = NStr::StringToUInt (second);
      if ( (str_num > first_num && str_num < second_num)
               || (str_num > second_num && str_num < first_num) ) {
          rval = true;
      }
    }
  } 
  else if (x_StringIsPositiveAllDigits(second)) {
    prefix_len = first.find_first_of(m_digit_str) + 1;

    new_str = CTempString(str).substr(prefix_len - 1);
    new_first = CTempString(first).substr(prefix_len - 1);
    comp_str1 = CTempString(str).substr(0, prefix_len);
    comp_str2 = CTempString(first).substr(0, prefix_len);
    if (comp_str1 == comp_str2
          && x_StringIsPositiveAllDigits (new_str)
          && x_StringIsPositiveAllDigits (new_first)) {
      first_num = NStr::StringToUInt(new_first);
      second_num = NStr::StringToUInt (second);
      str_num = NStr::StringToUInt (str);
      if ( (str_num > first_num && str_num < second_num)
               || (str_num > second_num && str_num < first_num) ) {
        rval = true;
      }
    }
  } 
  else {
    /* determine length of prefix */
    prefix_len = 0;
    while ( prefix_len < first.size() 
               && prefix_len < second.size() 
               && first[prefix_len] == second[prefix_len]) {
       prefix_len ++;
    }
    prefix_len ++;

    comp_str1 = CTempString(str).substr(0, prefix_len);
    comp_str2 = CTempString(first).substr(0, prefix_len);
    if (prefix_len <= first.size() 
           && prefix_len <= second.size()
           && isdigit (Uint1(first[prefix_len-1])) 
           && isdigit (Uint1(second[prefix_len-1]))
           && comp_str1 == comp_str2) {
      new_first = CTempString(first).substr(prefix_len);
      new_second = CTempString(second).substr(prefix_len);
      new_str = CTempString(str).substr(prefix_len);
      if (x_StringIsPositiveAllDigits (new_first) 
            && x_StringIsPositiveAllDigits (new_second) 
            && x_StringIsPositiveAllDigits (new_str)) {
        first_num = NStr::StringToUInt(new_first);
        second_num = NStr::StringToUInt (new_second);
        str_num = NStr::StringToUInt (new_str);
        if ( (str_num > first_num && str_num < second_num)
                || (str_num > second_num && str_num < first_num) ) {
          rval = true;
        }
      } else {
        /* determine whether there is a suffix */
        size_t idx1, idx2, idx_str;
        string suf1, suf2, sub_str;
        idx1 = first.find_first_not_of(m_digit_str);
        suf1 = CTempString(first).substr(prefix_len + idx1);
        idx2 = second.find_first_not_of(m_digit_str);
        suf2 = CTempString(second).substr(prefix_len + idx2);
        idx_str = str.find_first_not_of(m_digit_str);
        sub_str = CTempString(str).substr(prefix_len + idx_str);
        if (suf1 == suf2 && suf1 == sub_str) {
          /* suffixes match */
          first_num 
            = NStr::StringToUInt(CTempString(first).substr(prefix_len, idx1));
          second_num 
            =NStr::StringToUInt(CTempString(second).substr(prefix_len, idx2));
          str_num 
            =NStr::StringToUInt(CTempString(str).substr(prefix_len, idx_str));
          if ( (str_num > first_num && str_num < second_num)
                   || (str_num > second_num && str_num < first_num) ) {
            rval = true;
          }
        }
      }
    }
  }
  return rval;
};

bool CString_constraint :: x_IsStringInSpanInList (const string& str, const string& list) const
{
  if (list.empty() || str.empty()) {
      return false;
  }

  size_t idx = str.find_first_not_of(m_alpha_str);
  if (idx == string::npos) {
     return false;
  }

  idx = CTempString(str).substr(idx).find_first_not_of(m_digit_str);

  /* find ranges */
  size_t hyphen = list.find('-');
  bool rval = false;
  string range_start, range_end;
  while (hyphen != string::npos && !rval) {
    if (!hyphen) {
       hyphen = CTempString(list).substr(1).find('-');
    }
    else {
      if (x_GetSpanFromHyphenInString (list, hyphen, range_start, range_end)){
        if (x_IsStringInSpan (str, range_start, range_end)) rval = true;
      }
      hyphen = list.find('-', hyphen + 1);
    }
  }
  return rval;
};

bool CString_constraint :: x_DoesSingleStringMatchConstraint(const string& str) const
{
    if (str.empty()) {
        return false;
    }

    bool rval(false);
    if (Empty()) {
        rval = true;
    }
    
    string this_str(str);
    if (GetIgnore_weasel()) {
        this_str = x_SkipWeasel(str);
    }
    if (GetIs_all_caps() && !x_IsAllCaps(this_str)) {
        rval = false;
    } else if (GetIs_all_lower() && !x_IsAllLowerCase(this_str)) {
        rval = false;
    } else if (GetIs_all_punct() && !x_IsAllPunctuation(this_str)) {
        rval = false;
    } else if (GetIs_first_cap() && !x_IsFirstCap(this_str)) {
        rval = false;
    } else if (GetIs_first_each_cap() && !x_IsFirstEachCap(this_str)) {
        rval = false;
    } else {
      
        string tmp_match = CanGetMatch_text() ? GetMatch_text() : kEmptyStr;
        if (GetIgnore_weasel()) {
            tmp_match = x_SkipWeasel(tmp_match);
        }
        if (GetMatch_location() != eString_location_inlist && CanGetIgnore_words()){
            rval = x_AdvancedStringMatch(str, tmp_match);
        } else {
            string search(this_str), pattern(tmp_match);
            if ( GetMatch_location() != eString_location_inlist && (GetIgnore_space() || GetIgnore_punct())) {
              search = x_StripUnimportantCharacters(search, GetIgnore_space(), GetIgnore_punct());
              pattern = x_StripUnimportantCharacters(pattern, GetIgnore_space(), GetIgnore_punct());
            } 
            
            NStr::ECase case_sens = GetCase_sensitive() ? NStr::eCase : NStr::eNocase;
            SIZE_TYPE pFound;
            if (pattern.empty()) {
                pFound = 0;
            } else {
                pFound = NStr::Find(search, pattern, 0, NPOS, NStr::eFirst, case_sens);
            }

            switch (GetMatch_location()) {
            case eString_location_contains:
                if (pFound == NPOS) {
                    rval = false;
                } else if (GetWhole_word()) {
                    rval = x_IsWholeWordMatch (search, pFound, pattern.size());
                    while (!rval && pFound != NPOS) {
                        pFound = NStr::Find(search, pattern, pFound + 1, NPOS, NStr::eFirst, case_sens);
                        rval = (pFound != NPOS) ? x_IsWholeWordMatch(search, pFound, pattern.size()) : false;
                    }
                } else {
                    rval = true;
                }
                break;
            case eString_location_starts:
                if (!pFound) {
                    rval = GetWhole_word() ? x_IsWholeWordMatch (search, pFound, pattern.size()) : true;
                }
                break;
            case eString_location_ends:
                while (pFound != NPOS && !rval) {
                    if ( (pFound + pattern.size()) == search.size()) {
                        rval = GetWhole_word() ? x_IsWholeWordMatch (search, pFound, pattern.size()) : true;
                        /* stop the search, we're at the end of the string */
                        pFound = NPOS;
                    } else {
                        pFound = NStr::Find(search, pattern, pFound + 1, NPOS, NStr::eFirst, case_sens);
                    }
                }
                break;
            case eString_location_equals:
                rval = NStr::Equal(search, pattern, case_sens);
                break;
            case eString_location_inlist:
                pFound = NStr::Find(pattern, search, 0, NPOS, NStr::eFirst, case_sens);
                if (pFound == NPOS) {
                    rval = false;
                } else {
                    rval = x_IsWholeWordMatch(pattern, pFound, search.size(), true);
                    while (!rval && pFound != NPOS) {
                        pFound = NStr::Find(pattern.substr(pFound + 1), search, 0, NPOS, NStr::eFirst, case_sens);
                        if (pFound != NPOS) {
                            rval = x_IsWholeWordMatch(pattern, pFound, str.size(), true);
                        }
                    }
                }
                if (!rval) {
                /* look for spans */
                rval = x_IsStringInSpanInList (search, pattern);
                }
            break;
            }
        }
    }

    return rval;
}

bool CString_constraint :: Match(const string& str) const
{
    bool rval = x_DoesSingleStringMatchConstraint (str);
    return GetNot_present() ? (!rval) : rval;
}

bool CString_constraint::x_ReplaceContains(string& val, const string& replace) const
{
    bool rval = false;

    size_t offset = 0;
    while (offset < val.length()) {
        size_t match_len = 0;
        if (x_AdvancedStringCompare(val.substr(offset), GetMatch_text(),
                                    offset == 0 ? 0 : val.c_str()[offset - 1],
                                    &match_len)) {
            val = val.substr(0, offset) + replace + val.substr(offset + match_len);
            rval = true;
            offset += replace.length();
        } else {
            offset++;
        }
    }
    return rval;
}


bool CString_constraint::ReplaceStringConstraintPortionInString(string& val, const string& replace) const
{
    bool rval = false;
    
    if (val.empty()) {
        if (Empty() || (IsSetNot_present() && GetNot_present())) {
            val = replace;
            rval = true;
        }
    } else if (Empty()) {
        val = replace;
        rval = true;
    } else {
        if (IsSetMatch_location()) {
            switch (GetMatch_location()) {
                case eString_location_inlist:
                case eString_location_equals:
                    val = replace;
                    rval = true;
                    break;
                case eString_location_starts:
                    {{
                       size_t match_len = 0;
                       if (x_AdvancedStringCompare(val, GetMatch_text(), 0, &match_len)) {
                           val = replace + val.substr(match_len);
                           rval = true;
                       }
                    }}
                    break;
                case eString_location_contains:
                    rval = x_ReplaceContains(val, replace);
                    break;
                case eString_location_ends:
                    {{
                        size_t offset = 0;
                        while (!rval && offset < val.length()) {
                            size_t match_len = 0;
                            if (x_AdvancedStringCompare(val.substr(offset), 
                                                         GetMatch_text(),
                                                         (offset == 0 ? 0 : val.c_str()[offset - 1]), 
                                                          &match_len)
                                && offset + match_len == val.length()) {
                                val = val.substr(0, offset) + replace;
                                rval = true;
                            } else {
                                offset++;
                            }
                        }
                    }}
                    break;
            } 
        } else {
            rval = x_ReplaceContains(val, replace);                    
        }
    }
    return rval;
}

END_objects_SCOPE // namespace ncbi::objects::
END_NCBI_SCOPE

/* Original file checksum: lines: 57, chars: 1744, CRC32: 7f791d1c */
