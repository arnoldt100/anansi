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
#include "NodeKeysFixture.h"
#include "XMLReaderFixture.h"
#include "FilePicklerPropertyTreeMap.hpp"

namespace utf = boost::unit_test;


#endif   // ----- #ifndef test_file_parsers_core_INC  ----- 
