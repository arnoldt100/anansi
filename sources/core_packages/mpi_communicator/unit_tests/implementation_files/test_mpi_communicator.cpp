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

BOOST_AUTO_TEST_SUITE( Test_Suite_MPI_Communicator )

BOOST_AUTO_TEST_CASE( mpi_communicator_test )
{
    std::string message("Stud test for target 'mpi_communicator' which intentionally fails as the default behavior.");
    bool status=false;
    BOOST_TEST(status, message.c_str());
}
BOOST_AUTO_TEST_SUITE_END()


