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
                              const std::string test_description,
                              const std::string typelist_description)
    {
        auto error_message = "\n" + std::string("Test description: ") + test_description + "\n";
            error_message += std::string("Typelist description: ") + typelist_description  + "\n";
            error_message += std::string("Comment: ") ;
            error_message += std::string("The computed index=") + std::to_string(computed_index) + 
                           " is incorrect but should be index=" + std::to_string(correct_index) + "\n"; 
        return error_message; 
    }

    template<>
    void verify_index_at_front<MPL::mpl_typelist<>>()
    {
        // Providing a short description ot test and typelist.
        std::string test_description = std::string("Verifies that IndexOfLabel can find front element in typelist.");
        std::string typelist_description = std::string("Empty typeList");

        // The location in the typelist where the type should be located.
        // If the list is empty, then the correct location is -1.
        auto const correct_index = -1;

        // Create a dummy type to search for.
        using front_type = TaskLabelContainerFixture::ConcreteA;

        // Create an empty typelist.
        using empty_typelist = MPL::mpl_typelist<>;

        // Compute the location of the front_type with 
        // IndexOfLabel.
        IndexOfLabel<empty_typelist,front_type::value> MyIndexOf;
        auto const computed_index = MyIndexOf.value;

        // Run the Boost test to check the location.
        std::string message = error_message(computed_index,correct_index,test_description,typelist_description);
        BOOST_TEST( correct_index == computed_index, message.c_str());
        return;
     }

} // namespace RECEIVER
