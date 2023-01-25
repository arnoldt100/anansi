#ifndef test_receiver_utilities_INC
#define test_receiver_utilities_INC

//! @file test_receiver_utilities.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/test/unit_test.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReceiverUtilities.hpp"
#include "TaskLabelContainerFixture.h"

namespace RECEIVER 
{

    //! Returns an error message for an incorrect computed index from IndexOfLabel.
    //! 
    //! @param[in] computed_index The index computed by the IndexOfLabel.
    //! @param[in] correct_index The correct index the IndexOfLabel should compute.
    //! @param[in] test_description The description of the test.
    //! @param[in] typelist_description The desciption of the typelist used for the test.
    //! @return An error message.
    std::string index_of_label_error_message(int const computed_index, 
                              int const correct_index,
                              const std::string test_description,
                              const std::string typelist_description);

    //! Verifies IndexOfLabel computes for type located at front.
    //! 
    //! This is the primary template which handles the case for a non-empty TypeList.
    //!
    //! tparam TypeList A typelist of TaskLabelContainer.
    template<typename TypeList>
    void verify_index_at_front()
    {
        // Providing a short description ot test and typelist.
        std::string typelist_size = std::to_string( MPL::mpl_size<TypeList>::value ); 
        std::string test_description = std::string("Verifies that IndexOfLabel can find front element in typelist.");
        std::string typelist_description = std::string("Typelist with ") + typelist_size + " element(s).";

        // The variable correct_index  is the location in the typelist where
        // the type should be located. If the list is empty, then the correct
        // location is -1, othewise the location should be 0.
        auto const correct_index = 
            ( MPL::mpl_empty<TypeList>::value) ? TaskLabelContainerFixture::correct_index_empty_typelist : TaskLabelContainerFixture::correct_index_at_front_tests;

        // Get the front type in the typelist.
        using front_type = MPL::mpl_front<TypeList>;

        // Compute the location of the front_type with 
        // IndexOfLabel.
        IndexOfLabel<TypeList,front_type::value> MyIndexOf;
        auto const computed_index = MyIndexOf.value;

        // Run the Boost test to check the location.
        std::string message = index_of_label_error_message(computed_index,correct_index,test_description,typelist_description);
        BOOST_TEST( correct_index == computed_index, message.c_str());
        return;
    }

    //! Verifies IndexOfLabel computes for type located at front.
    //!
    //! This is the specializtion template which handles the case for a empty TypeList.
    //! tparam TypeList An empty typelist of TaskLabelContainer.
    template <>
    void verify_index_at_front<MPL::mpl_typelist<>>();
    
    //! Verifies IndexOfLabel computes for type located between the front and end.
    //! 
    //! If the TypeList is an empty typelist, then the computed index should be
    //! -!, otherwise the computed index should for a type located in the middle of the
    //! of the typelist.
    //!
    //! tparam TypeList A typelist of TaskLabelContainer.
    template<typename TypeList>
    void verify_index_at_middle()
    {
        // Providing a short description ot test and typelist.
        std::string typelist_size = std::to_string( MPL::mpl_size<TypeList>::value ); 
        std::string test_description = std::string("Verifies that IndexOfLabel can find the middle element in typelist.");
        std::string typelist_description = std::string("Typelist with ") + typelist_size + " element(s).";

        // Define the variable 'midpoint'.
        constexpr auto midpoint = MPL::mpl_size<TypeList>::value/2;

        // The variable 'correct_index' is the location in the typelist where
        // the type should be located. If the list is empty, then the correct
        // location is -1, othewise the location should be the MPL::mp_size<TypeList>::value/2.
        auto const correct_middle_index = midpoint;

        // Get the middle type in the typelist.
        using middle_type = MPL::mpl_at_c<TypeList,midpoint>;

        // Compute the location of the middle_type with 
        // IndexOfLabel.
        IndexOfLabel<TypeList,middle_type::value> MyIndexOf;
        auto const computed_middle_index = MyIndexOf.value;

        // Run the Boost test to check the location.
        std::string message = index_of_label_error_message(computed_middle_index,correct_middle_index,test_description,typelist_description);
        BOOST_TEST( correct_middle_index == computed_middle_index, message.c_str());
        return;
    }

    //! Verifies IndexOfLabel computes for type located between the front and end.
    //! 
    //! This specialized template handles the case for an empty typelist.
    //! If the TypeList is an empty typelist, then the computed index should be
    //! -!, otherwise the computed index should for a type located in the middle of the
    //! of the typelist.
    //!
    //! tparam TypeList A typelist of TaskLabelContainer.
    template<>
    void verify_index_at_middle<MPL::mpl_typelist<>>();

    template<typename TypeList>
    void verify_index_for_no_match()
    {
        using nm_types = MPL::mpl_size<TypeList>; 
        BOOST_TEST( 1 == 2, "Stud test for no match receiver package.");
    }

    template<typename TypeList>
    void verify_index_for_empty_list()
    {
        using nm_types = MPL::mpl_size<TypeList>; 
        BOOST_TEST( 1 == 2, "Stud test for no match receiver package.");
    }

    template<typename TypeList>
    void verify_index_at_end()
    {
        BOOST_TEST( 1 == 2, "Stud test for end receiver package.");
    }

    template<>
    void verify_index_at_end<MPL::mpl_typelist<>>();
};

#endif // test_receiver_utilities_INC
