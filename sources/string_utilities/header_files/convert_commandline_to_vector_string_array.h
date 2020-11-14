/*
 * =====================================================================================
 *
 *       Filename:  convert_commandline_to_vector_string_array.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/18 14:57:59
 *
 *         Author:  Arnold Tharrington (), arnoldt@ornl.gov
 *   Organization:  National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef CONVERT_COMMANDLINE_TO_VECTOR_STRING_ARRAY_H_
#define CONVERT_COMMANDLINE_TO_VECTOR_STRING_ARRAY_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <sstream>
#include <string>
#include <vector>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace STRING_UTILITIES 
{

    std::vector<std::string> 
    convert_commandline_to_vector_string_array(std::string const & my_string);

} /* namespace STRING_UTILITIES */

#endif /* CONVERT_COMMANDLINE_TO_VECTOR_STRING_ARRAY_H_ */
