//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "test_mpi_communicator.h"
#include "BroadcastVectorStringCache.h"
#include "FixtureBroadcastVectorStringCache.h"
#include "verify_VectorStringCacheBroadcast.h"


BOOST_AUTO_TEST_SUITE( Test_Suite_MPI_Communicator )

BOOST_FIXTURE_TEST_CASE( mpi_communicator_test, FixtureBroadcastVectorStringCache )
{
    int mpi_error = MPI_Init(&boost::unit_test::framework::master_test_suite().argc,
                             &boost::unit_test::framework::master_test_suite().argv);
    int my_rank;
    mpi_error = MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);

    std::string message;
    bool status;

    std::tie(status,message) = verify_VectorStringCacheBroadcast(experimentalVecStringCache1);

    BOOST_TEST(status, message.c_str());

    mpi_error = MPI_Finalize();
}

BOOST_AUTO_TEST_SUITE_END()


