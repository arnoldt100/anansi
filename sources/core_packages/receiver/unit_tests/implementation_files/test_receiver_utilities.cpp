//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "test_receiver_utilities.h"

namespace RECEIVER 
{
    std::string error_message(int const computed_index, int const correct_index)
    {
        auto error_message = "The computed index=" + std::to_string(computed_index) + 
                           " is incorrect but should be index=" + std::to_string(correct_index); 
        return error_message; 
    }


} // namespace RECEIVER
