//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/format.hpp>
#include <boost/filesystem.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "test_file_parsers_core.h"
#include "NodeKeys.h"
#include "XMLNodeKeys.h"
#include "NodeKeysFixture.h"
#include "XMLReaderFixture.h"
#include "PathToDataFilesFileParserCore.h"
#include "XMLFileReader.h"
#include "FilePicklerPropertyTreeMap.hpp"
#include "compare_pickled_files.h"
#include "compare_unpickled_files.h"

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
    // to do the pickling of property_tree to std::map<std::string,std::string>
    boost::property_tree::ptree my_ptree = my_xml_reader_fixture.getPropertyTree();
    ANANSI::FilePickler<boost::property_tree::ptree, std::map<std::string,std::string>> my_pickler;
    std::map<std::string,std::string> pickled_file = my_pickler.pickle<ANANSI::XMLNodeKeys>(my_ptree);

    // Verify the pickled xml file, pickled_file (which is a std::map), is correct
    // by comparing to the correct pickled file.
    bool xml_pickled_correctly;
    std::string message;
    std::map<std::string,std::string> correct_pickled_file = my_node_keys_fixture.getMap();
    std::tie(xml_pickled_correctly,message) = ANANSI::compare_pickled_files(correct_pickled_file,pickled_file);
    BOOST_TEST( xml_pickled_correctly, message.c_str() );
}

BOOST_AUTO_TEST_CASE( unpickling_boost_property_tree )
{
    // Unpickle the std::map in NodeKeysFixture to create a boost::ptree. This boost::ptree is the experimental
    // boost::ptree.
    ANANSI::NodeKeysFixture my_node_keys_fixture;
    std::map<std::string,std::string> tmp_map = my_node_keys_fixture.getMap();
    ANANSI::FilePickler<boost::property_tree::ptree, std::map<std::string,std::string>> my_pickler;
    boost::property_tree::ptree my_exp_ptree = my_pickler.unPickle<ANANSI::XMLNodeKeys>(tmp_map);

    // Compare the correct and test boost::ptrees. They should contain the same key-value pairs.
    bool unpickled_correctly;
    std::string message("Failure in unpickling");
    std::tie(unpickled_correctly,message) = ANANSI::compare_unpickled_files(tmp_map,my_exp_ptree);
    BOOST_TEST(unpickled_correctly, message.c_str());
}

BOOST_AUTO_TEST_SUITE_END()

