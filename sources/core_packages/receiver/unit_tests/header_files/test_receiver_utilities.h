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
    void verify_index_of()
    {
        BOOST_TEST( 1 == 2, "Stud test for receiver package.");
    }
};

#endif // test_receiver_utilities_INC
