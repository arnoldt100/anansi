//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <cstdlib>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIInitException.h"
#include "MPIInitializedException.h"
#include "MPIFinalizedException.h"
#include "MPIEnvironment.h"
#include "NullMPIEnvironment.h"
#include "EnabledMPIEnvironment.h"
#include "DisabledMPIEnvironment.h"
#include "Pointer2d.hpp"
#include "copy_2d_char_array.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPIEnvironment::MPIEnvironment() :
    COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>(),
    argc_ptr_(0),
    argv_ptr_(nullptr)
{
    this->changeMPIState_<ANANSI::NullMPIEnvironment>();
    return;
}

MPIEnvironment::~MPIEnvironment()
{
    if (argv_ptr_ !=nullptr)
    {
        MEMORY_MANAGEMENT::Pointer2d<char>::destroyPointer2d(argc_ptr_,argv_ptr_);
    }

    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void MPIEnvironment::enableReceiver()
{
    return;
}

void MPIEnvironment::disableReceiver()
{
    return;
}

void MPIEnvironment::enableEnvironment() 
{
    this->mpistate_->enable(this);
    return;
}

void MPIEnvironment::enableEnvironment(int const & argc, char const * const * const & argv) 
{
    this->argc_ptr_ = argc;

    this->mpistate_->enable(this,argc,argv);
    return;
}

void MPIEnvironment::disableEnvironment() 
{
    this->mpistate_->disable(this);
    return;
}
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
void MPIEnvironment::enable_(int const & argc, char const * const * const & argv) 
{

    // Verify that the MPI environment is not already initialized. If
    // the MPI environment is not initialized, the call MPI_Init.
    try
    {
        int flag;
        int mpi_return_code = MPI_Initialized( &flag );
        if (flag)
        {
            throw ANANSI::MPIInitializedException();
        }

        int tmp_argc = argc;
        char** tmp_argv = nullptr;

        STRING_UTILITIES::copy_2d_char_array(tmp_argc,argv,tmp_argv);
        mpi_return_code = MPI_Init(&tmp_argc,&tmp_argv);

        if (mpi_return_code != MPI_SUCCESS)
        {
            throw ANANSI::MPIInitException();
        }
    }
    catch(ANANSI::MPIInitializedException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch (ANANSI::MPIInitException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return;
}

void MPIEnvironment::disable_()
{
    try 
    {
        int mpi_return_code = MPI_Finalize();
        if (mpi_return_code != MPI_SUCCESS)
        {
            throw ANANSI::MPIFinalizedException();
        }
    }
    catch(ANANSI::MPIFinalizedException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return;
}

void MPIEnvironment::enable_()
{

    // Verify that the MPI environment is not already initialized. If
    // the MPI environment is not initialized, the call MPI_Init.
    try
    {
        int flag;
        int mpi_return_code = MPI_Initialized( &flag );
        if (flag)
        {
            throw ANANSI::MPIInitializedException();
        }

        int tmp_argc = 0;
        char** tmp_argv = nullptr;

        mpi_return_code = MPI_Init(&tmp_argc,&tmp_argv);

        if (mpi_return_code != MPI_SUCCESS)
        {
            throw ANANSI::MPIInitException();
        }
    }
    catch(ANANSI::MPIInitializedException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch (ANANSI::MPIInitException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return;
}


//============================= OPERATORS ====================================


} /* namespace ANANSI */
