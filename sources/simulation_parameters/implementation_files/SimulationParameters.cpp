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
    namespace po = boost::program_options;

    // Unpack the command line arguments;
    int argc=0;
    char** argv=nullptr;
    aCommandLine.reformCommandLineArguments(argc,argv);

    po::options_description description;
    description.add_options()("help", "Produce the help message.");

    boost::optional<std::string> controlfile;
    description.add_options()("control-file", po::value(&controlfile), "The name of the control file.");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, description), vm);
    po::notify(vm);    

    // If the help option is present, then print help message and return.
    // Only the the "world parent process" should print the help message.
    if ( vm.count("help") )
    {
        std::cout << description << std::endl;
    }

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
