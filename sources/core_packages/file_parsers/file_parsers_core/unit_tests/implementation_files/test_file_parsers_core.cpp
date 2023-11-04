//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <boost/format.hpp>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "test_file_parsers_core.h"

BOOST_AUTO_TEST_SUITE( Test_Suite_FileParsersCore )

BOOST_AUTO_TEST_CASE( FindNodeKey)
{
    FileParsersCoreFixture f;

    boost::format frmter_found("Testing key %1%, Key status : %2%.\n");
    boost::format frmter_not_found("Warning, key not found! Testing key %1%, Key status : %2%.\n");

    // Loop over all keys in "FileParsersCoreFixture.keys" and verify they
    // exist in "nodeKeys."
    std::string message;
    bool all_keys_found = true;
    for (const auto & tmpkey : f.keys  )
    {
        bool found_key = does_key_exist(f.nodeKeys,tmpkey);
        if ( found_key) 
        {
            frmter_found % tmpkey.c_str() % found_key ;
            message += frmter_found.str();
        }
        else
        {
            frmter_not_found % tmpkey.c_str() % found_key ;
            message += frmter_not_found.str();
            all_keys_found = false;
        }
    }
    BOOST_TEST(all_keys_found, message);
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

