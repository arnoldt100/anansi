//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <boost/format.hpp>
#include <boost/filesystem.hpp>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "test_file_parsers_core.h"
#include "PathToDataFilesFileParserCore.h"
#include "XMLFileReader.h"
#include "FilePicklerPropertyTreeMap.hpp"

BOOST_AUTO_TEST_SUITE( Test_Suite_FileParsersCore )

BOOST_AUTO_TEST_CASE( FindNodeKey)
{
    ANANSI::NodeKeysFixture f;

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

BOOST_AUTO_TEST_CASE( pickling_boost_property_tree)
{
    ANANSI::NodeKeysFixture my_node_keys_fixture;
    ANANSI::XMLReaderFixture my_xml_reader_fixture;

    // Pickle the property tree that comes from the xml file. We use ANANSI::FilePickler
    // to do the pickling to std::map<std::string,std::string>
    boost::property_tree::ptree my_ptree = my_xml_reader_fixture.getPropertyTree();
    ANANSI::FilePickler<boost::property_tree::ptree, std::map<std::string,std::string>> my_pickler;
    std::map<std::string,std::string> pickled_file = my_pickler.pickle<ANANSI::XMLNodeKeys>(my_ptree);

    // Verify the pickled xml file (which is the generated std::map) is correct.
    std::map<std::string,std::string> correct_pickled_file = my_node_keys_fixture.getMap();

    bool xml_pickled_correctly = false;
    BOOST_TEST( xml_pickled_correctly, "The test pickling_boost_property_tree failed." );
}

BOOST_AUTO_TEST_CASE( unpickling_boost_property_tree )
{
    ANANSI::XMLReaderFixture f;
    BOOST_TEST(2 < 1, "The test unpickling_boost_property_tree is incorrect.");
}

BOOST_AUTO_TEST_SUITE_END()

