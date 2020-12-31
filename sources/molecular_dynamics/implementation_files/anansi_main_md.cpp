#include "anansi_main_md.h"

int main( int argc, char** argv )
{
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Create an AnansiMolecularDynamicsFactory and instantiate a      @
    // MD object.                                                      @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    ANANSI::MolecularDynamicsFactory* my_md_factory_ptr = 
        new ANANSI::AnansiMolecularDynamicsFactory;

    ANANSI::MolecularDynamics* md_ptr = my_md_factory_ptr->create();

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Initialize the the simulation execution environment.            @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    md_ptr->initializeSimulationEnvironment(argc,argv);

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Process the command line and set the simulation parameters.     @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    md_ptr->processCommandLine(argc,argv);

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Initialize the initial condtions of the simulation.             @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Do simulation.                                                  @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // md_ptr->doSimulation();

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Free the resources used by the simulation.                      @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    if (md_ptr != nullptr)
    {
        delete md_ptr;
        md_ptr=nullptr;
    }

    if (my_md_factory_ptr != nullptr)
    {
        delete my_md_factory_ptr;
        my_md_factory_ptr=nullptr;
    }

    return EXIT_SUCCESS;
}
