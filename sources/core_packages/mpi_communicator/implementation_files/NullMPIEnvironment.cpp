//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "NullMPIEnvironment.h"
#include "EnabledMPIEnvironment.h"
#include "DisabledMPIEnvironment.h"
#include "MPIEnvironment.h"
#include "ErrorInvalidMPIEnvironmentChange.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

NullMPIEnvironment::NullMPIEnvironment() :
    MPIEnvironmentState()
{
    return;
}

NullMPIEnvironment::NullMPIEnvironment( NullMPIEnvironment const & other) :
    MPIEnvironmentState(other)
{
    if (this != &other)
    {

    }
    return;
}

NullMPIEnvironment::NullMPIEnvironment( NullMPIEnvironment && other) :
    MPIEnvironmentState(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method NullMPIEnvironment::NullMPIEnvironment  -----


NullMPIEnvironment::~NullMPIEnvironment()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

NullMPIEnvironment& NullMPIEnvironment::operator=( const NullMPIEnvironment &other )
{
    if (this != &other)
    {
        MPIEnvironmentState::operator=(other);
    }
    return *this;
} // assignment operator

NullMPIEnvironment& NullMPIEnvironment::operator=( NullMPIEnvironment && other )
{
    if (this != &other)
    {
        MPIEnvironmentState::operator=(std::move(other));
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
std::string NullMPIEnvironment::currentState_() const
{
    return std::string(this->stateid_);
}

//============================= MUTATORS =====================================

void NullMPIEnvironment::enable_(MPIEnvironment* const mpi_environment)
{
    mpi_environment->enable_();
    mpi_environment->changeMPIState_<ANANSI::EnabledMPIEnvironment>();
    return;
}

void NullMPIEnvironment::disable_(MPIEnvironment* const mpi_environment)
{
    std::string_view const original_state(mpi_environment->currentMPIEnvironmentState().c_str());
    std::string_view const action{"'Disable MPI Environment'"};
    throw ErrorInvalidMPIEnvironmentChange(original_state,action);
    return;
}
//============================= OPERATORS ====================================


} // namespace ANANSI
