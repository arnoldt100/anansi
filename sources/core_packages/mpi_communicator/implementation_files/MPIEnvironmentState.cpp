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

namespace ANANSI {

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
    if (this != &other)
    {

    }
    return;
}

MPIEnvironmentState::MPIEnvironmentState( MPIEnvironmentState && other)
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method MPIEnvironmentState::MPIEnvironmentState  -----


MPIEnvironmentState::~MPIEnvironmentState()
{
    return;
}

//============================= ACCESSORS ====================================

std::string MPIEnvironmentState::currentState() const 
{
    return this->currentState_();
}

//============================= MUTATORS =====================================
void MPIEnvironmentState::enable(MPIEnvironment* const mpi_environment)
{
    this->enable_(mpi_environment);
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

//============================= OPERATORS ====================================


} // namespace ANANSI
