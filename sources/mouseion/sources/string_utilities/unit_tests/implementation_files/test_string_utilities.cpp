#include "test_string_utilities.h"

BOOST_AUTO_TEST_SUITE( String_Utilities_Unit_Tests )

BOOST_FIXTURE_TEST_CASE( test_stud_1, StringUtilitiesFixture )
{
    BOOST_TEST( 2 < 1, "The test test_stud_1 is incorrect.");
}

BOOST_FIXTURE_TEST_CASE( test_stud_2, StringUtilitiesFixture )
{
    BOOST_TEST(2 < 1, "The test test_stud_2 is incorrect.");
}

BOOST_AUTO_TEST_SUITE_END()
