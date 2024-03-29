/*
 * SimulationParameters.cpp
 *
 *         Author:  Arnold N. Tharrington, arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 */

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <utility>
#include <algorithm>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationParameters.h"
#include "AllOptions.h"


namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

SimulationParameters::SimulationParameters()
{
    return;
}

SimulationParameters::SimulationParameters(COMMANDLINE::CommandLineArguments const & aCommandLine)
{

    // Use the Boost program options library to parse the command line.
    this->commandLineOptionsMap_ =
        SimulationParameters::parseProgramOptionsFromCommandLine_(aCommandLine);

    return;
}

SimulationParameters::SimulationParameters(const SimulationParameters &other ) :
    commandLineOptionsMap_(other.commandLineOptionsMap_),
    simulationParametersMap_(other.simulationParametersMap_)
{
    return;
}

SimulationParameters::SimulationParameters( SimulationParameters && other)
{
    this->commandLineOptionsMap_ = std::move(other.commandLineOptionsMap_);
    this->simulationParametersMap_ = std::move(other.simulationParametersMap_);
    return;
}		// -----  end of method SimulationParameters::SimulationParameters  -----

SimulationParameters::~SimulationParameters()
{
    return;
}

//============================= ACCESSORS ====================================

bool SimulationParameters::isCommandLineOptionPresent ( std::string const & key) const
{
    // We count the number of elements with key "key". If the 
    // count is > 0, then the option is present. Otherwise the option
    // is not present.
    const auto count = this->commandLineOptionsMap_.count(key);
    const auto found_option = (count > 0) ? true : false;
    return found_option;
}		// -----  end of method SimulationParameters::isCommandLineOptionPresent  ----- 

std::string SimulationParameters::getCommandLineOptionValues (std::string const & key) const
{
    const auto search = this->commandLineOptionsMap_.find(key);
    const auto my_value = ( search != this->commandLineOptionsMap_.end()) ? this->commandLineOptionsMap_.at(key) : SimulationParameters::OPTION_NOT_FOUND;
    return my_value;
}		// -----  end of method SimulationParameters::getCommandLineOptionValues  ----- 


//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

SimulationParameters& SimulationParameters::operator=( const SimulationParameters &other )
{
    if (this != &other)
    {
        this->commandLineOptionsMap_ = other.commandLineOptionsMap_;
    }
    return *this;
}

SimulationParameters& SimulationParameters::operator= ( SimulationParameters && other )
{
    if (this != &other)
    {
        this->commandLineOptionsMap_ = std::move(other.commandLineOptionsMap_);
        this->simulationParametersMap_ = std::move(other.simulationParametersMap_);

    }
    return *this;
}       // ----- end of assignment-move operator -----

// ============================  STATIC        ===============================

const std::string SimulationParameters::OPTION_NOT_FOUND="option_not_found";

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//============================= STATIC    ====================================
boost::program_options::variables_map SimulationParameters::createBoostVariableMap_(COMMANDLINE::CommandLineArguments const & aCommandLine)
{
    namespace po = boost::program_options;

    // Unpack the command line arguments;
    int argc=0;
    char** argv=nullptr;
    aCommandLine.reformCommandLineArguments(argc,argv);

    // Loop over all options and add to the boost program 
    // options_description. If the help option is present in
    // the command line arguments, then only add to the help description.
    po::options_description description;
    for (const auto & a_option : Alloptions)
    {
        a_option.addBoostOption(description);
    }

    // Parse and store the option values in the boost variable map.
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, description), vm);
    po::notify(vm);    

    if (argv != nullptr)
    {
        MEMORY_MANAGEMENT::Pointer2d<char>::destroyPointer2d(argc,argv);
    }
    return vm;
}

OPTIONS_PARAMETERS_MAP_t SimulationParameters::transferBoostVariableMap_(boost::program_options::variables_map const & vm)
{
    OPTIONS_PARAMETERS_MAP_t options_map;

    // Loop over all option values and transfer from the boost variable map to options_map.
    for (const auto & a_option : Alloptions)
    {
        a_option.getOptionsValue(options_map,vm);
    }

    return options_map;
}

OPTIONS_PARAMETERS_MAP_t SimulationParameters::parseProgramOptionsFromCommandLine_(COMMANDLINE::CommandLineArguments const & aCommandLine)
{
    // Create the Boost variabler map.
    const auto vm = SimulationParameters::createBoostVariableMap_(aCommandLine);

    // Transfer the Boost variabler map to options map.
    const OPTIONS_PARAMETERS_MAP_t options_map = SimulationParameters::transferBoostVariableMap_(vm);

    return options_map;
}


} /* namespace ANANSI */
