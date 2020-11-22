#include "test_mpi_communicator.h"

BOOST_AUTO_TEST_SUITE( Test_Suite_MPI_COMMUNICATOR )

BOOST_FIXTURE_TEST_CASE( test_stud_1, MPICommFixture )
{
  BOOST_TEST( 2 < 1, "The test test_stud_1 is incorrect" );
}

BOOST_FIXTURE_TEST_CASE( test_stud_2, MPICommFixture )
{
  BOOST_TEST(2 < 1, "The test test_stud_2 is incorrect.");
}

BOOST_AUTO_TEST_SUITE_END()

