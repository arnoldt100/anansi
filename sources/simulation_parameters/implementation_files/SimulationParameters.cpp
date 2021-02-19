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
#include <algorithm>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "mpi.h"

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
    this->_optionsMap =
        SimulationParameters::_parseProgramOptionsFromCommandLine(aCommandLine);

    // :TODO:01/02/2021 11:44:10 PM:: Store the values of the program options.


    return;
}

SimulationParameters::SimulationParameters(const SimulationParameters &other )
{
    return;
}

SimulationParameters::~SimulationParameters()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

SimulationParameters& SimulationParameters::operator=( const SimulationParameters &other )
{
    if (this != &other)
    {

    }
    return *this;
}

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
boost::program_options::variables_map SimulationParameters::_createBoostVariableMap(COMMANDLINE::CommandLineArguments const & aCommandLine)
{
    namespace po = boost::program_options;

    // Unpack the command line arguments;
    int argc=0;
    char** argv=nullptr;
    aCommandLine.reformCommandLineArguments(argc,argv);

    // Loop over all options and add to the boost program 
    // options_description. If the help option is present in
    // the command line arguments, then only add to the help description.
    const std::string help_long_opt("--help");
    const std::string help_short_opt("-h");
    po::options_description description;
    if (aCommandLine.findArgument(help_long_opt) || aCommandLine.findArgument(help_short_opt))
    {
        HelpOption.addBoostOption(description);
    }
    else
    {
        for (const auto & a_option : Alloptions)
        {
            a_option.addBoostOption(description);
        }
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

std::map<std::string,std::string> SimulationParameters::_transferBoostVariableMap(boost::program_options::variables_map const & vm)
{
    std::map<std::string,std::string> options_map;

    // The options_map variable is  used to store the option values instead of the boost
    // variable_map so as to modularize the option parsing functionality - we don't want to use
    // boost's variable map throughout the program.
    if ( vm.count("help") )
    {
        // Process only the help option value and transfer from the boost variable map to
        // options_map. 
        const std::vector<std::string> options_to_process = {"help"};
        for (const auto & a_option : Alloptions)
        {
            a_option.getSelectOptionsValue(options_map,vm,options_to_process);
        }
    }
    else
    {
        // Loop over all option values and transfer from the boost variable map to options_map.
        for (const auto & a_option : Alloptions)
        {
            a_option.getOptionsValue(options_map,vm);
        }
    }

    return options_map;
}

std::vector<CommandLineOptions> SimulationParameters::_parseOptionsClasses()
{
    std::vector<CommandLineOptions> my_options;
    return my_options;
}

std::map<std::string,std::string> SimulationParameters::_parseProgramOptionsFromCommandLine(COMMANDLINE::CommandLineArguments const & aCommandLine)
{
    // Create the Boost variabler map.
    const auto vm = SimulationParameters::_createBoostVariableMap(aCommandLine);

    // Transfer the Boost variabler map to options map.
    const auto options_map = SimulationParameters::_transferBoostVariableMap(vm);


    return options_map;
}


} /* namespace ANANSI */
