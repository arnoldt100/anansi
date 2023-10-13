#ifndef ANANSI_check_string_for_separator_char_INC
#define ANANSI_check_string_for_separator_char_INC

//! \file check_string_for_separator_char.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

//! \brief Checks for the XML path separator character in string a_string.
//!
//! \detail If the path separator char, stored in the template parameter trait
//! class PathSeparator_t, is found in string a_string, then true is returned. Otherwise
//! false is returned.
//!
//! \param a_string[in] The string to be searched.
//! \tparam PathSeparator_t A trait class that stores the character to search for.
template<typename PathSeparator_t>
bool check_string_for_separator_char (const std::string & a_string)
{
    bool found_sep_char = false;
    if (auto pos = a_string.find(PathSeparator_t::separator_char[0]); pos == std::string::npos)
    {
        found_sep_char = true;
    }
    return found_sep_char;
}


}; // namespace ANANSI

#endif // ANANSI_check_string_for_separator_char_INC
