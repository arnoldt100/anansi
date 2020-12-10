#include "MPIEnvironment.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPIEnvironment::MPIEnvironment(int argc, char** argv)
{
    // Verify that the MPI environment is not already initialized. If
    // the MPI environment is not initialized, the call MPI_Init.
    try
    {
        int flag;
        int mpi_return_code = MPI_Initialized( &flag ); 
        if (flag)
        {
            throw COMMUNICATOR::MPIInitializedException();       
        }
    
        mpi_return_code = MPI_Init(&argc,&argv);
        if (mpi_return_code != MPI_SUCCESS)
        {
            throw COMMUNICATOR::MPIInitException();       
        }
    }
    catch(COMMUNICATOR::MPIInitializedException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch (COMMUNICATOR::MPIInitException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return;
}

MPIEnvironment::~MPIEnvironment()
{
    try 
    {
        int mpi_return_code = MPI_Finalize();
        if (mpi_return_code != MPI_SUCCESS)
        {
            throw COMMUNICATOR::MPIFinalizedException();
        }
    }
    catch(COMMUNICATOR::MPIFinalizedException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//============================= STATIC =======================================

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


} /* namespace COMMUNICATOR */
