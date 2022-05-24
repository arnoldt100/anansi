//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIEnvironmentState.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPIEnvironmentState::MPIEnvironmentState()
{
    return;
}

MPIEnvironmentState::MPIEnvironmentState( MPIEnvironmentState const & other)
{
    return;
}

MPIEnvironmentState::MPIEnvironmentState( MPIEnvironmentState && other)
{
    return;
}		// -----  end of method MPIEnvironmentState::MPIEnvironmentState  -----


MPIEnvironmentState::~MPIEnvironmentState()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void MPIEnvironmentState::enable(MPIEnvironment* const mpi_environment)
{
    this->enable_(mpi_environment);
    return;
}

void MPIEnvironmentState::enable(MPIEnvironment* const mpi_environment, int const & argc, char const * const * const & argv)
{
    this->enable_(mpi_environment,argc,argv);
    return;
}

void MPIEnvironmentState::disable(MPIEnvironment* const mpi_environment)
{
    this->disable_(mpi_environment);
    return;
}


//============================= OPERATORS ====================================

MPIEnvironmentState& MPIEnvironmentState::operator= ( const MPIEnvironmentState &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

MPIEnvironmentState& MPIEnvironmentState::operator= ( MPIEnvironmentState && other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment-move operator

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

void MPIEnvironmentState::enable_(MPIEnvironment* const mpi_environment)
{
    return;
}

void MPIEnvironmentState::enable_(MPIEnvironment* const mpi_environment, int const & argc, char const * const * const & argv)
{
    return;
}

void MPIEnvironmentState::disable_(MPIEnvironment* const mpi_environment)
{
    return;
}


//============================= OPERATORS ====================================


} // namespace COMMUNICATOR
