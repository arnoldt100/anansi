#include "test_file_parsers_core.h"

BOOST_AUTO_TEST_SUITE( Test_Suite_FileParsersCore )

BOOST_FIXTURE_TEST_CASE( FindNodeKeys, FileParsersCoreFixture )
{
    // Loop over all keys in "FileParsersCoreFixture.keys" and verify they
    // exist.
    for (const auto & tmpkey : keys  )
    {
        std::cout << "Testing key " << tmpkey.c_str() << std::endl;
        bool found_key = does_key_exist(nodeKeys,tmpkey);
    }
    BOOST_TEST( 2 < 1, "The NodeKeys::find is incorrect" );
}

BOOST_FIXTURE_TEST_CASE( pickling_boost_property_tree, FileParsersCoreFixture )
{
  BOOST_TEST( 2 < 1, "The test pickling_boost_property_tree is incorrect" );
}

BOOST_FIXTURE_TEST_CASE( unpickling_boost_property_tree, FileParsersCoreFixture )
{
  BOOST_TEST(2 < 1, "The test unpickling_boost_property_tree is incorrect.");
}

BOOST_AUTO_TEST_SUITE_END()

