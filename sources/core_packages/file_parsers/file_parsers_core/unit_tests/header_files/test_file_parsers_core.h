#ifndef  test_file_parsers_core_INC
#define  test_file_parsers_core_INC


#define BOOST_TEST_MODULE File Parsers Core

#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include "NodeKeys.h"

namespace utf = boost::unit_test;

class FileParsersCoreFixture 
{
    public:
        FileParsersCoreFixture()
        {
           return; 
        }

        ~FileParsersCoreFixture()
        {
           return; 
        }

        void setup()
        {
            std::cout << "setup of FileParsersCoreFixture." << std::endl;
        }

        void teardown()
        {
            std::cout << "teardown of FileParsersCoreFixture." << std::endl;
        }
};

#endif   // ----- #ifndef test_file_parsers_core_INC  ----- 
