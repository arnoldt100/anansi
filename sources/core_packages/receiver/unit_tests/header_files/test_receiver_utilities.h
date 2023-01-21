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

namespace RECEIVER 
{
    //! Returns an error message for an incorrect computed index from IndexOfLabel.
    //! 
    //! @param[in] computed_index The index computed by the IndexOfLabel.
    //! @param[in] correct_index The correct index the IndexOfLabel should compute.
    //! @return An error message.
    std::string error_message(int const computed_index, int const correct_index);

    //! Verifies IndexOfLabel computes for type located at front.
    //! 
    //! If the TypeList is an empty typelist, then the computed index should be
    //! -!, otherwise the computed index should be 0.
    //!
    //! tparam TypeList A typelist of TaskLabelContainer.
    template<typename TypeList>
    void verify_index_at_front()
    {
        auto const correct_index = ( MPL::mpl_empty<TypeList>::value) ? -1 : 0;

        if constexpr ( ! MPL::mpl_empty<TypeList>::value)
        {
            using front_type = MPL::mpl_front<TypeList>;
        }
        else
        {
            using front_type = MPL::mpl_typelist<>;
        }
        IndexOfLabel<TypeList,front_type::value> MyIndexOf;
        auto const computed_index = MyIndexOf.value;
    template<typename TypeList>
    void verify_index_at_front()
        std::string message = error_message(computed_index,correct_index);
        BOOST_TEST( correct_index == computed_index, message.c_str());
    }
    template<typename TypeList>
    void verify_index_at_front<>()
    {

    }
    
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
        // using nm_types = MPL::mpl_size<TypeList>; 
        // using middle_index = MPL::mpl_int<(nm_types::value - 1)/2>; 
        // auto const correct_index = ( MPL::mpl_empty<TypeList>::value) ? -1 : middle_index::value;

        // using middle_type = MPL::mpl_at_c<TypeList,middle_index::value>;

        // IndexOfLabel<TypeList,middle_type::value> MyIndexOf;
        BOOST_TEST( 1 == 2, "Stud test for middle receiver package.");
    }

    template<typename TypeList>
    void verify_index_at_end()
    {
        using nm_types = MPL::mpl_size<TypeList>; 
        BOOST_TEST( 1 == 2, "Stud test for end receiver package.");
    }

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

};

#endif // test_receiver_utilities_INC
