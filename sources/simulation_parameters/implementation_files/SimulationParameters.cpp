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

std::vector<CommandLineOptions> SimulationParameters::_parseOptionsClasses()
{
    std::vector<CommandLineOptions> my_options;
    return my_options;
}

std::map<std::string,std::string> SimulationParameters::_parseProgramOptionsFromCommandLine(COMMANDLINE::CommandLineArguments const & aCommandLine)
{
    namespace po = boost::program_options;

    // Unpack the command line arguments;
    int argc=0;
    char** argv=nullptr;
    aCommandLine.reformCommandLineArguments(argc,argv);

    // Loop over all options and add to the boost program 
    // options_description.
    po::options_description description;
    for (const auto & a_option : Alloptions)
    {
        a_option.addBoostOption(description);
    }

    // Parse and store the option values in the boost variable map.
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, description), vm);
    po::notify(vm);    


    // If the help option is present, then print help message and return.
    // Only the the "world parent process" should print the help message.
    // :TODO:02/12/2021 11:36:08 AM:: Move this outside this function. 
    // Printing the help message is not the responsibilty of this function. 
    if ( vm.count("help") )
    {
        std::cout << description << std::endl;
    }

    // Loop over all option values and transfer from the boost variable map to options_map. The
    // options_map variable is to store the option values instead of the boost variable_map to
    // modularize the option parsing functionality - we don't want to use boost's variable map
    // throughout the program.
    std::map<std::string,std::string> options_map;
    for (const auto & a_option : Alloptions)
    {
        a_option.getOptionsValue(options_map);
    }

    // Delete the nonuniform 2d char array.
    if (argv != nullptr)
    {
        MEMORY_MANAGEMENT::Pointer2d<char>::destroyPointer2d(argc,argv);
    }

    return options_map;
}


} /* namespace ANANSI */
