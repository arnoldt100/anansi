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
    template<typename TypeList>
    void verify_index_at_front()
    {
        using front_type = MPL::mpl_front<TypeList>;
        IndexOfLabel<TypeList,front_type::value> MyIndexOf;

        BOOST_TEST( 1 == 2, "Stud test for front receiver package.");
    }
    
    template<typename TypeList>
    void verify_index_at_middle()
    {

        using nm_types = MPL::mpl_size<TypeList>; 
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
