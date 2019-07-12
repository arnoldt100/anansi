#include "anansi_main_md.h"

int main( int argc, char** argv )
{
    // Store the command line arguments.
    COMMANDLINE::CommandLineArguments aCommandLine(argc,argv);

    // Create an AnansiMolecularDynamicsFactory and instantiate a MD object.
    ANANSI::MolecularDynamicsFactory* my_md_factory_ptr = new ANANSI::AnansiMolecularDynamicsFactory;
    ANANSI::MolecularDynamics * md_ptr = my_md_factory_ptr->create();

    // Initialize the simulation.
    md_ptr->initializeSimulation(argc,argv);

    // Do md simulation.
    md_ptr->doSimulation();

    // Free all memory.
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

    return 0;
}
