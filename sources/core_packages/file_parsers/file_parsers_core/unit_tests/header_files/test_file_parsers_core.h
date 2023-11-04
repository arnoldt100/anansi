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

class FileParsersCoreFixture
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
            // Initialize the keys that are in the test XML input data file.
            keys.clear();
            keys.push_back("title");
            keys.push_back("units");
            keys.push_back("processor-topology");
            keys.push_back("processor-topology.lattice-type");
            keys.push_back("processor-topology.mpi-spatial-decompositionce-type");
            keys.push_back("processor-topology.compute-units-per-spatial-domain");
            keys.push_back("initial-configuration");
            keys.push_back("initial-configuration.filename");
            keys.push_back("molecular-topology");
            keys.push_back("molecular-topology.filename");
            keys.push_back("hamiltonian");
            keys.push_back("hamiltonian.filename");
            keys.push_back("time-step");
            keys.push_back("time-step.value");
            keys.push_back("time-step.units");
            keys.push_back("time-step.number-time-steps");
            keys.push_back("integration-methodology");
            keys.push_back("integration-methodology.ensemble");

            std::cout << "setup of FileParsersCoreFixture." << std::endl;

            // Read the xml file and assign to a property tree.

        }

        void teardown()
        {
            std::cout << "teardown of FileParsersCoreFixture." << std::endl;
        }

        // ====================  DATA MEMBERS  =======================================

        std::vector<std::string> keys;
        ANANSI::NodeKeys nodeKeys;
        ANANSI::FilePickler<boost::property_tree::ptree,std::map<std::string,std::string>> pickler;
        boost::property_tree::ptree ptree;

};

#endif   // ----- #ifndef test_file_parsers_core_INC  ----- 
