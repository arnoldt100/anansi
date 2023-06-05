//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "test_tasklabeltraits.h"
#include "TaskLabelTraits.hpp"
namespace RECEIVER
{

void verify_valid_char_array_size ()
{
    // TaskLabelTraits::MAX_NM_CHARS sets the the char array size of
    // variable that stores the name of the task command. It needs to be set to
    // value > 0.
    BOOST_TEST(ANANSI::TaskLabelTraits::MAX_NM_CHARS > 0,"ANANSI::TaskLabelTraits::MAX_NM_CHARS <= 0 is not valid." );
    return;
}   /* -----  end of function verify_valid_char_array_size ----- */


}; /* namespace RECEIVER */

