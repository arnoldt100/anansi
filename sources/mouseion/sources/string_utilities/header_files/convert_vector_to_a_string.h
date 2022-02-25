/*
 * =====================================================================================
 *
 *       Filename:  convert_vector_to_a_string.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/20/18 11:06:15
 *
 *         Author:  Arnold Tharrington (), arnoldt@ornl.gov
 *   Organization:  National Center of Computational Sciences
 *
 * =====================================================================================
 */


#ifndef CONVERT_VECTOR_STRING_TO_A_STRING_INC
#define CONVERT_VECTOR_STRING_TO_A_STRING_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace STRING_UTILITIES 
{
    template<typename T>
    std::string 
    convert_vector_to_a_string(const std::vector<T>& vec)
    {
        std::string my_string;
        typename std::vector<T>::const_iterator it;
        for (it = vec.begin(); it != vec.end(); ++it)
        {
            my_string = my_string + " " + std::to_string(*it); 
        }
        return my_string;
    }

}; /* namespace STRING_UTILITIES */

#endif /* CONVERT_VECTOR_STRING_TO_A_STRING_INC */
