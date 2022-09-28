#ifndef  test___target___INC
#define  test___target___INC


#define BOOST_TEST_MODULE __testmodulename__

#include <boost/test/included/unit_test.hpp>
#include <iostream>

namespace utf = boost::unit_test;

class __classname__Fixture 
{
    public:
        __classname__Fixture()
        {
           return; 
        }

        ~__classname__Fixture()
        {
           return; 
        }

        void setup()
        {
            std::cout << "setup of __classname__Fixture." << std::endl;
        }

        void teardown()
        {
            std::cout << "teardown of __classname__Fixture." << std::endl;
        }
};

#endif   // ----- #ifndef test___target___INC  ----- 
