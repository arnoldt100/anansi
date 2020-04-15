#ifndef  test_command_line_arguments_INC
#define  test_command_line_arguments_INC


#define BOOST_TEST_MODULE Command Line Arguments

#include <boost/test/included/unit_test.hpp>
#include <iostream>
namespace utf = boost::unit_test;

class CLAFixture 
{
    public:
        CLAFixture()
        {
           return; 
        }

        ~CLAFixture()
        {
           return; 
        }

        void setup()
        {
            std::cout << "setup of CLAFixture." << std::endl;
        }

        void teardown()
        {
            std::cout << "teardown of CLAFixture." << std::endl;
        }
};

#endif   // ----- #ifndef test_command_line_arguments_INC  ----- 
