/*
 * SimulationParameters.cpp
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 */

#include "SimulationParameters.h"

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
    SimulationParameters::_parseProgramOptionsFromCommandLine(aCommandLine);

    // Add the program options to this SimulationParameters class.
    // TO BE IMPLEMENTED


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
void SimulationParameters::_parseProgramOptionsFromCommandLine(COMMANDLINE::CommandLineArguments const & aCommandLine)
{
    // Unpack the command line arguments;
    int argc=0;
    char** argv=nullptr;
    aCommandLine.reformCommandLineArguments(argc,argv);

    boost::program_options::options_description description;
    // description.add_options()("help", "Produce the help message.");
    // description.add_options()("control_file", po::value<std::string>(), "The name of the control file.");
    // po::variables_map vm;
    // po::store(po::parse_command_line(argc, argv, description), vm);
    // po::notify(vm);    

    // Delete the nonuniform 2d char array.
    if (argv != nullptr)
    {
        for (int ip=0; ip < argc; ++ip)
        {
            if ( argv[ip] != nullptr)
            {
                delete argv[ip];
            }
        }
        delete [] argv;
    }
    return;
}

} /* namespace ANANSI */