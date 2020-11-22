#ifndef  test_mpi_communicator_INC
#define  test_mpi_communicator_INC


#define BOOST_TEST_MODULE Command Line Arguments

#include <boost/test/included/unit_test.hpp>
#include <iostream>
namespace utf = boost::unit_test;

class MPICommFixture 
{
    public:
        MPICommFixture()
        {
           return; 
        }

        ~MPICommFixture()
        {
           return; 
        }

        void setup()
        {
            std::cout << "setup of MPICommFixture." << std::endl;
        }

        void teardown()
        {
            std::cout << "teardown of MPICommFixture." << std::endl;
        }
};

#endif   // ----- #ifndef test_mpi_communicator_INC  ----- 
