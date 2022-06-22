#ifndef  test_file_parsers_INC
#define  test_file_parsers_INC


#define BOOST_TEST_MODULE File Parsers

#include <boost/test/included/unit_test.hpp>
#include <iostream>

namespace utf = boost::unit_test;

class FileParsersFixture 
{
    public:
        FileParsersFixture()
        {
           return; 
        }

        ~FileParsersFixture()
        {
           return; 
        }

        void setup()
        {
            std::cout << "setup of FileParsersFixture." << std::endl;
        }

        void teardown()
        {
            std::cout << "teardown of FileParsersFixture." << std::endl;
        }
};

#endif   // ----- #ifndef test_file_parsers_INC  ----- 
