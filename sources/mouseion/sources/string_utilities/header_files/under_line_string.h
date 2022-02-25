/*
 * =====================================================================================
 *
 *       Filename:  under_line_string.h
 *
 *         Author:  Arnold Tharrington (), arnoldt@ornl.gov
 *   Organization:  National Center of Computational Sciences
 *
 * =====================================================================================
 */
#ifndef  under_line_string_INC
#define  under_line_string_INC

#include <string>

namespace STRING_UTILITIES 
{

std::string underline_string(const std::size_t nm, 
                             const char underline_char = '='); 

}; /* -----  end of namespace STRING_UTILITIES  ----- */

#endif /* ----- #ifndef under_line_string_INC  ----- */
