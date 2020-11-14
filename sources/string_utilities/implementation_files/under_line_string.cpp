/*
 * =====================================================================================
 *
 *       Filename:  under_line_string.cpp
 *
 *         Author:  Arnold Tharrington (), arnoldt@ornl.gov
 *   Organization:  National Center of Computational Sciences
 *
 * =====================================================================================
 */

#include "under_line_string.h"

std::string STRING_UTILITIES::underline_string(
    const std::size_t nm, 
    const char underline_char) 
{
    char single_character = underline_char;
    std::string aString(nm,single_character);
    return aString; 
}; 
