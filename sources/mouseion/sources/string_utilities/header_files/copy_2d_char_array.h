#ifndef  copy_2d_char_array_INC
#define  copy_2d_char_array_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cstddef>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace STRING_UTILITIES
{

void copy_2d_char_array ( const std::size_t dim1, char const * const * const in_ptr, char** & out_ptr);

}; /* namespace STRING_UTILITIES */

#endif   /* ----- #ifndef copy_2d_char_array_INC  ----- */
