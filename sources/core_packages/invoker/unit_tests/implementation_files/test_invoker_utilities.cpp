//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "test_invoker_utilities.h"

namespace ANANSI 
{
    std::string index_of_label_error_message(int const computed_index, 
                              int const correct_index,
                              const std::string test_description,
                              const std::string typelist_description)
    {
        auto index_of_label_error_message = "\n" + std::string("Test description: ") + test_description + "\n";
            index_of_label_error_message += std::string("Typelist description: ") + typelist_description  + "\n";
            index_of_label_error_message += std::string("Comment: ") ;
            index_of_label_error_message += std::string("The computed index=") + std::to_string(computed_index) + 
                           " is incorrect but should be index=" + std::to_string(correct_index) + "\n"; 
        return index_of_label_error_message; 
    }

    template<>
    void verify_index_at_front<MPL::mpl_typelist<>>()
    {
        // Providing a short description of test and typelist.
        std::string test_description = std::string("Verifies that IndexOfLabel can find front element in typelist.");
        std::string typelist_description = std::string("Empty typeList");

        // The location in the typelist where the type should be located.
        // Since the list is empty, then the correct location is -1.
        auto const correct_index = TaskLabelContainerFixture::correct_index_empty_typelist;

        // Create a dummy type to search for.
        using front_type = TaskLabelContainerFixture::ConcreteA;

        // Create an empty typelist.
        using empty_typelist = MPL::mpl_typelist<>;

        // Compute the location of the front_type with 
        // IndexOfLabel.
        IndexOfLabel<empty_typelist,front_type::value> MyIndexOf;
        auto const computed_index = MyIndexOf.value;

        // Run the Boost test to check the location.
        std::string message = index_of_label_error_message(computed_index,correct_index,test_description,typelist_description);
        BOOST_TEST( correct_index == computed_index, message.c_str());
        return;
     }

    template<>
    void verify_index_at_middle<MPL::mpl_typelist<>>()
    {
        // Providing a short description of test and typelist.
        std::string typelist_size = std::to_string( MPL::mpl_size<MPL::mpl_typelist<>>::value ); 
        std::string test_description = std::string("Verifies that IndexOfLabel can find the middle element in typelist.");
        std::string typelist_description = std::string("Typelist with ") + typelist_size + " element(s).";

        // The variable correct_index  is the location in the typelist where
        // the type should be located. Since the list is empty, then the correct
        // location is -1.
        auto const correct_middle_index = TaskLabelContainerFixture::correct_index_empty_typelist;

        // Create a dummy type to search for.
        using middle_type = TaskLabelContainerFixture::ConcreteB;

        // Compute the location of the middle_type with 
        // IndexOfLabel.
        IndexOfLabel<MPL::mpl_typelist<>,middle_type::value> MyIndexOf;
        auto const computed_middle_index = MyIndexOf.value;

        // Run the Boost test to check the location.
        std::string message = index_of_label_error_message(computed_middle_index,correct_middle_index,test_description,typelist_description);
        BOOST_TEST( correct_middle_index == computed_middle_index, message.c_str());
        return;
    }

    template<>
    void verify_index_at_end<MPL::mpl_typelist<>>()
    {
        using nm_types = MPL::mpl_size<MPL::mpl_typelist<>>; 
        
        // Providing a short description of test and typelist.
        std::string typelist_size = 
            std::to_string( MPL::mpl_size<MPL::mpl_typelist<>>::value ); 
        std::string test_description = 
            std::string("Verifies that IndexOfLabel can find end element in typelist.");
        std::string typelist_description = 
            std::string("Typelist with ") + typelist_size + " element(s).";

        // The variable correct_end_index is the location in the typelist where
        // the type should be located. If the list is empty, then the correct
        // location is -1, otherwise the location should be at the end.
        auto constexpr correct_end_index = TaskLabelContainerFixture::correct_index_empty_typelist;

        // Create a dummy type to search for.
        using end_type = TaskLabelContainerFixture::ConcreteB;

        // Compute the location of the end_type with 
        // IndexOfLabel.
        IndexOfLabel<MPL::mpl_typelist<>,end_type::value> MyIndexOf;
        auto const computed_end_index = MyIndexOf.value;

        // Run the Boost test to check the location.
        std::string message = index_of_label_error_message(computed_end_index,correct_end_index,test_description,typelist_description);
        BOOST_TEST( correct_end_index == computed_end_index, message.c_str());

        return;
    }


} // namespace ANANSI
