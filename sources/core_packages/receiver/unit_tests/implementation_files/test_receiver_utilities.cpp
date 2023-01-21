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

    template<>
    void verify_index_at_front<MPL::mpl_typelist<>>()
    {
    //     // auto const correct_index = -1;
    //     // using front_type = TaskLabelContainerFixture::ConcreteA;
    //     // using empty_typelist = MPL::mpl_typelist<>;
    //     // IndexOfLabel<empty_typelist,front_type::value> MyIndexOf;
    //     // auto const computed_index = MyIndexOf.value;
    //     // std::string message = error_message(computed_index,correct_index);
    //     // BOOST_TEST( correct_index == computed_index, message.c_str());
         // return;
     }

} // namespace RECEIVER
