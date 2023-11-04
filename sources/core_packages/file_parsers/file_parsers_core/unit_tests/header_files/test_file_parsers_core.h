#ifndef  test_file_parsers_core_INC
#define  test_file_parsers_core_INC

#define BOOST_TEST_MODULE File Parsers Core

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
#include <boost/test/included/unit_test.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "NodeKeys.h"
#include "XMLNodeKeys.h"
#include "FilePicklerPropertyTreeMap.hpp"

namespace utf = boost::unit_test;

class FileParsersCoreFixture:
{
    public:
        FileParsersCoreFixture() :
            nodeKeys(ANANSI::XMLNodeKeys())
        {
           return; 
        }

        ~FileParsersCoreFixture()
        {
           return; 
        }

        void setup()
        {
            std::cout << "setup of FileParsersCoreFixture." << std::endl;

            // Read the xml file and assign to a property tree.

        }

        void teardown()
        {
            std::cout << "teardown of FileParsersCoreFixture." << std::endl;
        }

        // ====================  DATA MEMBERS  =======================================

        ANANSI::NodeKeys nodeKeys;
        ANANSI::FilePickler<boost::property_tree::ptree,std::map<std::string,std::string>> pickler;
        boost::property_tree::ptree ptree;

};

#endif   // ----- #ifndef test_file_parsers_core_INC  ----- 
