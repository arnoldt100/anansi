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

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPIEnvironment::MPIEnvironment() :
    COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>(),
    cmdLineArgs_(),
    mpistate_(nullptr)
{
    this->changeMPIState_<ANANSI::NullMPIEnvironment>();
    return;
}

MPIEnvironment::MPIEnvironment(COMMANDLINE::CommandLineArguments & cmd_line_args) :
    COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>(),
    cmdLineArgs_(),
    mpistate_(nullptr)
{
    this->cmdLineArgs_ = cmd_line_args;
    this->changeMPIState_<ANANSI::NullMPIEnvironment>();
    return;
}

MPIEnvironment::~MPIEnvironment()
{
    return;
}

//============================= ACCESSORS ====================================
std::string MPIEnvironment::currentMPIEnvironmentState() const
{
    return this->mpistate_->currentState();
}

//============================= MUTATORS =====================================
template <>
void MPIEnvironment::addMember(const COMMANDLINE::CommandLineArguments & cmd_line_args)
{
    this->cmdLineArgs_ = cmd_line_args;
    return;
}

void MPIEnvironment::enableEnvironment() 
{
    this->mpistate_->enable(this);
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

        int tmp_argc=0;
        char** tmp_argv = nullptr;
        this->cmdLineArgs_.reformCommandLineArguments(tmp_argc,tmp_argv);

        mpi_return_code = MPI_Init(&tmp_argc,&tmp_argv);

        if (mpi_return_code != MPI_SUCCESS)
        {
            throw ANANSI::MPIInitException();
        }
        std::cout << "Enabled the MPI environment." << std::endl;
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
        std::cout << "Disabled the MPI environment." << std::endl;
    }
    catch(ANANSI::MPIFinalizedException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return;
}


//============================= OPERATORS ====================================


} /* namespace ANANSI */
