#ifndef  CONVERT_COMMANDLINE_TO_2D_CHAR_ARRAY_INC
#define  CONVERT_COMMANDLINE_TO_2D_CHAR_ARRAY_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace STRING_UTILITIES
{
    void convert_commandline_to_2d_char_array(
        std::string const & my_string,
        std::size_t & length,
        char** & my_array_ptr);
};

#endif   /* ----- #ifndef CONVERT_COMMANDLINE_TO_2D_CHAR_ARRAY_INC  ----- */
