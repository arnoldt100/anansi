#ifndef  test_string_utilities_unit_tests_INC
#define  test_string_utilities_unit_tests_INC


#define BOOST_TEST_MODULE STRING UTILITIES UNIT TESTS

#include <boost/test/included/unit_test.hpp>
#include <iostream>

namespace utf = boost::unit_test;

class StringUtilitiesFixture 
{
    public:
        StringUtilitiesFixture()
        {
           return; 
        }

        ~StringUtilitiesFixture()
        {
           return; 
        }

        void setup()
        {
            std::cout << "setup of StringUtilitiesFixture." << std::endl;
        }

        void teardown()
        {
            std::cout << "teardown of StringUtilitiesFixture." << std::endl;
        }
};

#endif   // ----- #ifndef test_string_utilities_unit_tests_INC  ----- 
