#include "MPIEnvironment.h"
#include "Pointer2d.hpp"
#include "copy_2d_char_array.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPIEnvironment::MPIEnvironment(int const & argc, char const * const * const & argv) :
    COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>()
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
    
        // 
        std::unique_ptr<MEMORY_MANAGEMENT::Pointer2d<char> >a_pointer_factory(new MEMORY_MANAGEMENT::Pointer2d<char>()); 

        int tmp_argc = argc;
        char** tmp_argv = nullptr;

        STRING_UTILITIES::copy_2d_char_array(tmp_argc,argv,tmp_argv);
        mpi_return_code = MPI_Init(&tmp_argc,&tmp_argv);

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
