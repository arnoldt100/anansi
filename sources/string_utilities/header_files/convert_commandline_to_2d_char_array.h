/*
 * =====================================================================================
 *
 *       Filename:  convert_commandline_to_2d_char_array.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/18 11:03:53
 *
 *         Author:  Arnold Tharrington (), arnoldt@ornl.gov
 *   Organization:  National Center of Computational Sciences
 *
 * =====================================================================================
 */


#ifndef  CONVERT_COMMANDLINE_TO_2D_CHAR_ARRAY_INC
#define  CONVERT_COMMANDLINE_TO_2D_CHAR_ARRAY_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <sstream>
#include <vector>
#include <cstring>


//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Array1d.hpp"

namespace STRING_UTILITIES
{
    void convert_commandline_to_2d_char_array(
        std::string const & my_string,
        std::size_t & length,
        char** & my_array_ptr);
};

#endif   /* ----- #ifndef CONVERT_COMMANDLINE_TO_2D_CHAR_ARRAY_INC  ----- */
