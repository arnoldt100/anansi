/*
 * =====================================================================================
 *
 *       Filename:  get_maximum_width_of_vector_string.cpp
 *
 *    Description:  
 *
 *         Author:  Arnold Tharrington (), arnoldt@ornl.gov
 *   Organization:  National Center of Computational Sciences
 *
 * =====================================================================================
 */

#include "get_maximum_width_of_vector_string.h"

std::size_t STRING_UTILITIES::get_maximum_width_of_vector_string(std::vector<std::string> & someStrings)
{
    std::size_t maximum_string_width = 0;
    for (const auto tmp_string : someStrings)
    {
        std::size_t string_size = tmp_string.size();
        maximum_string_width = ( string_size > maximum_string_width ? string_size : maximum_string_width );
    }
    return maximum_string_width;
}

