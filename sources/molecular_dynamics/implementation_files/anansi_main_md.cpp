#include "anansi_main_md.h"

int main( int argc, char** argv )
{
    // Initialize the MPI environment.
    COMMUNICATOR::MPIEnvironment* mpi_environment_ptr = new COMMUNICATOR::MPIEnvironment;

    // Create an AnansiMolecularDynamicsFactory and instantiate a MD object.
    ANANSI::MolecularDynamicsFactory* my_md_factory_ptr = new ANANSI::AnansiMolecularDynamicsFactory;
    ANANSI::MolecularDynamics* md_ptr = my_md_factory_ptr->create();

    // Initialize the simulation.
    md_ptr->initializeSimulation(argc,argv);

    // Do md simulation.
    md_ptr->doSimulation();

    // Free the md_ptr.
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

    // Finalize the MPI environment.
    if (mpi_environment_ptr != nullptr)
    {
        delete mpi_environment_ptr;
        mpi_environment_ptr = nullptr;
    }

    return 0;
}
