//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "test_stringliteraltraits.h"
#include "StringLiteralTraits.hpp"
namespace ANANSI
{

void verify_valid_char_array_size ()
{
    // StringLiteralTraits::MAX_NM_CHARS sets the the char array size of
    // variable that stores the name of the task command. It needs to be set to
    // value > 0.
    BOOST_TEST(STRINGLITERAL::StringLiteralTraits::MAX_NM_CHARS > 0,"STRINGLITERALStringLiteralTraits::MAX_NM_CHARS <= 0 is not valid." );
    return;
}   /* -----  end of function verify_valid_char_array_size ----- */


}; /* namespace ANANSI */

