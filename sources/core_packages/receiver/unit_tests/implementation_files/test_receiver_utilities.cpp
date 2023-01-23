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
#include "TaskLabelContainerFixture.h"

namespace RECEIVER 
{
    std::string error_message(int const computed_index, 
                              int const correct_index,
                              const std::string_view test_description,
                              const std::string_view typelist_description)
    {
        auto error_message = "\n" + std::string("Test description: ") + std::to_string(computed_index) + "\n";
            error_message += std::string("Typelist description: ")  + "\n";
            error_message += std::string("Comment: ") ;
            error_message += std::string("The computed index=") + std::to_string(computed_index) + 
                           " is incorrect but should be index=" + std::to_string(correct_index) + "\n"; 
        return error_message; 
    }

    template<>
    void verify_index_at_front<MPL::mpl_typelist<>>()
    {
        std::string_view test_description = std::string_view("Verifies that IndexOfLabel can find front element in typelist.");
        std::string_view typelist_description = std::string_view("Empyy typeList");
        auto const correct_index = -1;
        using empty_typelist = MPL::mpl_typelist<>;
        using front_type = TaskLabelContainerFixture::ConcreteA;
        IndexOfLabel<empty_typelist,front_type::value> MyIndexOf;
        auto const computed_index = MyIndexOf.value;
        std::string message = error_message(computed_index,correct_index,test_description,typelist_description);
        BOOST_TEST( correct_index == computed_index, message.c_str());
        return;
     }

} // namespace RECEIVER
