/*
 * =====================================================================================
 *
 *       Filename:  convert_commandline_to_2d_char_array.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/18 11:05:52
 *
 *         Author:  Arnold Tharrington (), arnoldt@ornl.gov
 *   Organization:  National Center of Computational Sciences
 *
 * =====================================================================================
 */

#include "convert_commandline_to_2d_char_array.h"
#include "Array1d.hpp"
#include <sstream>
#include <vector>
#include <cstring>

void STRING_UTILITIES::convert_commandline_to_2d_char_array(
        std::string const & my_string,
        std::size_t & length,
        char** & my_array_ptr)
{
    // Split the command line string by whiteespace
    std::istringstream iss(my_string);
    std::string temp_arg;
    std::vector<std::string> arguments;
    for( std::string s; iss >> temp_arg;)
    {
        arguments.push_back(temp_arg);
    }
    
    // Allocate a char** array and fill with the command line arguments.
    MEMORY_MANAGEMENT::Array1d<char> my_char_array_factory;
    MEMORY_MANAGEMENT::Array1d<char*> my_char_ptr_array_factory;

    length = arguments.size();
    std::size_t nm_elements = arguments.size();
    my_array_ptr = my_char_ptr_array_factory.createArray(nm_elements);
    for ( std::size_t counter=0; counter < nm_elements; ++counter )
    {
        std::string temp_string = arguments[counter];
        std::size_t nm_chars = temp_string.length() + 1;
        my_array_ptr[counter] = my_char_array_factory.createArray(nm_chars);

        char const * tmp_argument_ptr = temp_string.c_str();
        std::strcpy(my_array_ptr[counter],tmp_argument_ptr);
    }

    return;
}
