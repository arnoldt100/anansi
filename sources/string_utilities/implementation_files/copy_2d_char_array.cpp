//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cstring>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "copy_2d_char_array.h"
#include "Array1d.hpp"

namespace STRING_UTILITIES
{

void copy_2d_char_array ( std::size_t const dim1, char * const * const in_ptr, char** & out_ptr)
{
    // Allocate a char** array and fill with the command line arguments.
    MEMORY_MANAGEMENT::Array1d<char> my_char_array_factory;
    MEMORY_MANAGEMENT::Array1d<char*> my_char_ptr_array_factory;

    out_ptr = my_char_ptr_array_factory.createArray(dim1);
    for ( std::size_t counter=0; counter < dim1; ++counter )
    {
        std::size_t const length = std::strlen(in_ptr[counter])+1;
        out_ptr[counter] = my_char_array_factory.createArray(length);
        std::strcpy(out_ptr[counter],in_ptr[counter]);
    }

    return;
}   /* -----  end of function copy_2d_char_array  ----- */


}; /* namespace STRING_UTILITIES */

