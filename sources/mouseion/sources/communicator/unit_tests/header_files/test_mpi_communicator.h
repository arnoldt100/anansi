#ifndef  test_mpi_communicator_INC
#define  test_mpi_communicator_INC


#define BOOST_TEST_MODULE MPI Communicator Tests

#include <boost/test/included/unit_test.hpp>

#include <iostream>

#include "MPIEnvironment.h"
#include "MPICommunicatorFactory.h"

namespace utf = boost::unit_test;

class MPICommFixture 
{
    public:
        MPICommFixture() :
            argc(utf::framework::master_test_suite().argc),
            argv(utf::framework::master_test_suite().argv),
            aMPIEnvironment(std::make_unique<COMMUNICATOR::MPIEnvironment>(argc,argv))
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

        int argc;
        char** argv;
        std::unique_ptr<COMMUNICATOR::MPIEnvironment> aMPIEnvironment;
};

#endif   // ----- #ifndef test_mpi_communicator_INC  ----- 
