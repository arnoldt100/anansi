#include "test___target__.h"

BOOST_AUTO_TEST_SUITE( __testsuitename__ )

BOOST_FIXTURE_TEST_CASE( test_stud_1, __clasname__Fixture )
{
  BOOST_TEST( 2 < 1, "The test test_stud_1 is incorrect" );
}

BOOST_FIXTURE_TEST_CASE( test_stud_2, __clasname__Fixture )
{
  BOOST_TEST(2 < 1, "The test test_stud_2 is incorrect.");
}

BOOST_AUTO_TEST_SUITE_END()
