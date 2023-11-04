#include "test_file_parsers_core.h"

BOOST_AUTO_TEST_SUITE( Test_Suite_FileParsersCore )

BOOST_FIXTURE_TEST_CASE( pickling_boost_property_tree, FileParsersCoreFixture )
{
  BOOST_TEST( 2 < 1, "The test pickling_boost_property_tree is incorrect" );
}

BOOST_FIXTURE_TEST_CASE( unpickling_boost_property_tree, FileParsersCoreFixture )
{
  BOOST_TEST(2 < 1, "The test unpickling_boost_property_tree is incorrect.");
}

BOOST_AUTO_TEST_SUITE_END()

