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

BOOST_AUTO_TEST_SUITE( Test_Suite_MPI_Communicator )

BOOST_FIXTURE_TEST_CASE( mpi_communicator_test, FixtureBroadcastVectorStringCache )
{
    std::string message;
    bool status=false;

    BOOST_TEST(status, message.c_str());
}

BOOST_AUTO_TEST_SUITE_END()


