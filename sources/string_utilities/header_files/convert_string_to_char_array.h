#ifndef  convert_string_char_array_INC
#define  convert_string_char_array_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Array1dChar.hpp"
#include "PointerInitializationTraits.hpp"
#include "ExceptionLengthOfCharPointerIsTooSmall.h"

namespace STRING_UTILITIES 
{
        /*--------------------------------------------------------------------------------------
         *       Class:  Array1d
         *      Method:  convert_string_char_array
         * Description: Creates a pointer array of type T with "dim1" number of elements.
         *
         * Return: T*  
         *
         * Arguments: aString; type std::string; The string to be copied to a char*.
         *            length; type std::size_t; The number of characeters in char*.
         *
         *--------------------------------------------------------------------------------------
         */
        char* convert_string_char_array( std::string const & aString, std::size_t const & length );

} /* namespace STRING_UTILITIES */

#endif   // ----- #ifndef convert_string_char_array_INC  ----- 
