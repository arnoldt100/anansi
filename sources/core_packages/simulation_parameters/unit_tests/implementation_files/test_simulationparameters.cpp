#include "test_simulationparameters.h"

BOOST_AUTO_TEST_SUITE( Test_Suite_Simulation_Parameters )

BOOST_FIXTURE_TEST_CASE( test_stud_1, SimulationParametersFixture )
{
  BOOST_TEST( 2 < 1, "The test test_stud_1 is incorrect" );
}

BOOST_FIXTURE_TEST_CASE( test_stud_2, SimulationParametersFixture )
{
  BOOST_TEST(2 < 1, "The test test_stud_2 is incorrect.");
}


BOOST_AUTO_TEST_SUITE_END()
