//! @file anansi_main_md.cpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "anansi_main_md.h"
#include "AnansiMolecularDynamics.h"
#include "AnansiMolecularDynamicsFactory.h"


int
main( int argc, char** argv )
{
    auto exit_status = EXIT_SUCCESS;

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Create an AnansiMolecularDynamicsFactory and instantiate a      @
    // MD object.                                                      @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    std::shared_ptr<ANANSI::SimulationFactory> my_md_factory(new ANANSI::AnansiMolecularDynamicsFactory(argc,argv));
    std::shared_ptr<ANANSI::Simulation> md_ptr = my_md_factory->create_shared_ptr();

    try 
    {
        //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        //                                                                 @
        // Process the command line.                                       @
        //                                                                 @
        //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        md_ptr->processCommandLine();

        //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        //                                                                 @
        // Initialize the the simulation execution environment.            @
        //                                                                 @
        //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        md_ptr->initializeSimulationEnvironment();

        //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        //                                                                 @
        // Initialize the initial conditions of the simulation.            @
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

    }
    catch (const std::exception&) 
    {
    	// Catch error for one of the above steps.
        md_ptr->terminateSimulationEnvironment();
        exit_status = EXIT_FAILURE; 
    }

    return exit_status;
}
