
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <iostream>
#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/string/trim.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFileParser.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileParser::ControlFileParser() :
    FileParser(),
    _fileName(),
    _myCommunicator(),
    _myControlFileParserStatus(ANANSI::RegistryControlFileParserStatus::Undefined),
    _initialConfiguration(),
    _timestepValue(),
    _timestepUnits(),
    _values({ {"units",""} })

{
    return;
}

ControlFileParser::ControlFileParser( ControlFileParser && other) :
    FileParser(std::move(other)),
    _fileName(std::move(other._fileName)),
    _myCommunicator(std::move(other._myCommunicator)),
    _myControlFileParserStatus(std::move(other._myControlFileParserStatus)),
    _initialConfiguration(std::move(other._initialConfiguration)),
    _timestepValue(std::move(other._timestepValue)),
    _timestepUnits(std::move(other._timestepUnits)),
    _values(std::move(other._values))
{
    return;
} // -----  end of method ControlFileParser::ControlFileParser  -----


ControlFileParser::~ControlFileParser()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


ControlFileParser& ControlFileParser::operator= ( ControlFileParser && other )
{
    if (this != &other)
    {
        FileParser::operator=(std::move(other));
        this->_fileName = std::move(other._fileName);
        this->_myCommunicator = std::move(other._myCommunicator);
        this->_myControlFileParserStatus = std::move(other._myControlFileParserStatus);
        this->_initialConfiguration = std::move(other._initialConfiguration);
        this->_timestepValue = std::move(other._timestepValue);
        this->_timestepUnits = std::move(other._timestepUnits);
        this->_values = std::move(other._values);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void ControlFileParser::_readFile()
{
    this->_myControlFileParserStatus = RegistryControlFileParserStatus::Successful;
    const auto world_rank = this->_myCommunicator->getWorldCommunicatorRank();
    switch ( world_rank )
    {
        case COMMUNICATOR::MASTER_TASK_ID :	
            this->_parseFile();
            break;

        default:	
            break;
    }				/* -----  end switch  ----- */
    this->shareData();

    return;
}   // -----  end of method ControlFileParser::readFile  ----- 


void ControlFileParser::_shareData()
{
    // First share the status of parsing the simulation control file. If parsing
    // of simulation control file is a failure, then set the control
    // file parser status to failed and return.
    const auto my_status = convertRCPS(this->_myControlFileParserStatus);

    const bool global_status = 
        COMMUNICATOR::getGlobalStatus(my_status,
                                      *(this->_myCommunicator));
    if (! global_status)
    {
        this->_myControlFileParserStatus = RegistryControlFileParserStatus::GeneralFailure; 
        return;
    }

    // Share the control file data.
    
    return;
}		// -----  end of method FileParser::shareData  ----- 


void ControlFileParser::_setFileName(const std::string file_name) 
{
    this->_fileName = file_name;
    return;
}

void ControlFileParser::_setCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator)
{
    this->_myCommunicator = std::move(a_communicator);
    return;
}

void ControlFileParser::_parseFile()
{
    namespace pt = boost::property_tree;
    namespace ba = boost::algorithm;

    // Create empty property tree object
    pt::ptree tree;

    // Parse the XML into the property tree.
    try 
    {
        pt::read_xml(this->_fileName, tree,pt::xml_parser::trim_whitespace);
    }
    catch (const std::exception & my_error )
    {
        this->_myControlFileParserStatus = 
            ANANSI::RegistryControlFileParserStatus::FailedToParseXMLFileToPropertyTree;
    }

    if (this->_myControlFileParserStatus == ANANSI::RegistryControlFileParserStatus::FailedToParseXMLFileToPropertyTree)
    {
        return;
    }

    // Use the throwing version of get to find the values for the control file.
    // If the path cannot be resolved, an exception is thrown.
    try
    {
        this->_values["units"] = tree.get<std::string>("units");
        this->_initialConfiguration = tree.get<std::string>("initial_configuration.filename");
        this->_timestepValue = tree.get<std::string>("timestep.value");
        this->_timestepUnits = tree.get<std::string>("timestep.units");
        this->_myControlFileParserStatus = 
            ANANSI::RegistryControlFileParserStatus::Successful;
    }
    catch (const std::exception & my_error )
    {
        this->_myControlFileParserStatus = 
            ANANSI::RegistryControlFileParserStatus::FailedToResolveXMLPath;
    }
    return;
}

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
