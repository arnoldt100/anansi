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

namespace COMMUNICATOR {

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

//============================= MUTATORS =====================================

void DisabledMPIEnvironment::enable_(MPIEnvironment* const mpi_environment)
{
    throw ErrorInvalidMPIEnvironmentChange();
    return;
}

void DisabledMPIEnvironment::enable_(MPIEnvironment* const mpi_environment, int const & argc, char const * const * const & argv)
{
    throw ErrorInvalidMPIEnvironmentChange();
    return;
}

//============================= OPERATORS ====================================


} // namespace COMMUNICATOR
