#include "test_mpi_communicator.h"
BOOST_TEST_GLOBAL_FIXTURE( MPICommFixture );

BOOST_AUTO_TEST_SUITE( Test_Suite_MPI_COMMUNICATOR )

BOOST_AUTO_TEST_CASE( test_creation_and_freeing_mpi_communicator )
{
    // Initialize the communicator via its mpi communicator
    // factory.
    COMMUNICATOR::MPICommunicatorFactory a_communicator_factory;
    std::unique_ptr<COMMUNICATOR::Communicator> aMPICommunicator =  a_communicator_factory.createWorldCommunicator();
    
    // Now explicitly free the resources used by the communicator.
    aMPICommunicator->freeCommunicator();
}

BOOST_AUTO_TEST_CASE( test_gather_string )
{
    // Initialize the communicator via its mpi communicator
    // factory.
    COMMUNICATOR::MPICommunicatorFactory a_communicator_factory;
    std::unique_ptr<COMMUNICATOR::Communicator> aMPICommunicator;
    aMPICommunicator = a_communicator_factory.createWorldCommunicator();


    aMPICommunicator->freeCommunicator();
}

BOOST_AUTO_TEST_SUITE_END()

