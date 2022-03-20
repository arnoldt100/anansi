//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "anansi_main_md.h"
#include "MPIEnvironment.h"
#include "AnansiMolecularDynamics.h"
#include "AnansiMolecularDynamicsFactory.h"
#include "Pointer.hpp"
#include "CommandLineArguments.h"


int main( int argc, char** argv )
{
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Create an AnansiMolecularDynamicsFactory and instantiate a      @
    // MD object.                                                      @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    std::shared_ptr<ANANSI::MolecularDynamicsFactory> my_md_factory(new ANANSI::AnansiMolecularDynamicsFactory(argc,argv));
    std::shared_ptr<ANANSI::Simulation> md_ptr = my_md_factory->create_shared_ptr();

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Initialize the the simulation execution environment.            @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    md_ptr->initializeSimulationEnvironment();

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Process the command line and set the simulation parameters.     @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    md_ptr->processCommandLine();

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Initialize the initial condtions of the simulation.             @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    md_ptr->initializeInitialConditions();

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Perform the simulation.                                         @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    md_ptr->performSimulation();

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Terminate the simulation.                                       @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    md_ptr->terminateSimulationEnvironment();

    return EXIT_SUCCESS;
}
