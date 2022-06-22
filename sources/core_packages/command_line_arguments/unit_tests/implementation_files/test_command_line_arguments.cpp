
#include "test_command_line_arguments.h"

// Create a fixture for initializing a
// CommandLineArguments class

BOOST_AUTO_TEST_SUITE( Test_Suite_CommandLineArguments )

BOOST_FIXTURE_TEST_CASE( test_number_of_arguments,CLAFixture )
{
  BOOST_TEST( 2 < 1, "The number of test arguments is incorrect" );
}

BOOST_FIXTURE_TEST_CASE( test_arguments,CLAFixture )
{
  BOOST_TEST(2 < 1, "The arguments are incorrect.");
}

BOOST_AUTO_TEST_SUITE_END()

