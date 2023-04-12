//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "DisabledMPIEnvironment.h"
#include "MPIEnvironment.h"
#include "ErrorInvalidMPIEnvironmentChange.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

DisabledMPIEnvironment::DisabledMPIEnvironment()
{
    return;
}

DisabledMPIEnvironment::DisabledMPIEnvironment( DisabledMPIEnvironment const & other) :
    MPIEnvironmentState(other)
{
    if (this != &other)
    {

    }
    return;
}

DisabledMPIEnvironment::DisabledMPIEnvironment( DisabledMPIEnvironment && other) :
    MPIEnvironmentState(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method DisabledMPIEnvironment::DisabledMPIEnvironment  -----


DisabledMPIEnvironment::~DisabledMPIEnvironment()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

DisabledMPIEnvironment& DisabledMPIEnvironment::operator= ( const DisabledMPIEnvironment &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

DisabledMPIEnvironment& DisabledMPIEnvironment::operator= ( DisabledMPIEnvironment && other )
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

std::string DisabledMPIEnvironment::currentState_() const
{
    return std::string(this->stateid_);
}

//============================= MUTATORS =====================================

void DisabledMPIEnvironment::enable_(MPIEnvironment* const mpi_environment)
{
    std::string_view const original_state(mpi_environment->currentMPIEnvironmentState().c_str());
    std::string_view const action{"'Enable MPI Environment'"};
    throw ErrorInvalidMPIEnvironmentChange(original_state,action);
    return;
}

void DisabledMPIEnvironment::disable_(MPIEnvironment* const mpi_environment)
{
    std::string_view const original_state(mpi_environment->currentMPIEnvironmentState().c_str());
    std::string_view const action{"'Disable MPI Environment'"};
    throw ErrorInvalidMPIEnvironmentChange(original_state,action);
    return;
}

//============================= OPERATORS ====================================


} // namespace ANANSI
