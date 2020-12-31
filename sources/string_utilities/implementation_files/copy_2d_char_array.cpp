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

void copy_2d_char_array ( std::size_t const dim1, char const * const * const source_ptr, char** & destination_ptr)
{
    // Allocate a char** array and fill with the command line arguments.
    MEMORY_MANAGEMENT::Array1d<char> my_char_array_factory;
    MEMORY_MANAGEMENT::Array1d<char*> my_char_ptr_array_factory;

    destination_ptr = my_char_ptr_array_factory.createArray(dim1);
    for ( std::size_t ip=0; ip < dim1; ++ip )
    {
        std::size_t const length = std::strlen(source_ptr[ip])+1;
        destination_ptr[ip] = my_char_array_factory.createArray(length);
        std::strcpy(destination_ptr[ip],source_ptr[ip]);
    }

    return;
}   /* -----  end of function copy_2d_char_array  ----- */


}; /* namespace STRING_UTILITIES */

