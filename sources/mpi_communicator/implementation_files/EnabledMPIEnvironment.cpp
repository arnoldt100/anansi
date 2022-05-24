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
#include "EnabledMPIEnvironment.h"
#include "MPIEnvironment.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

EnabledMPIEnvironment::EnabledMPIEnvironment()
{
    return;
}

EnabledMPIEnvironment::EnabledMPIEnvironment( EnabledMPIEnvironment const & other) :
    MPIEnvironmentState(other)
{
    if (this != &other)
    {

    }
    return;
}

EnabledMPIEnvironment::EnabledMPIEnvironment( EnabledMPIEnvironment && other) :
    MPIEnvironmentState(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method EnabledMPIEnvironment::EnabledMPIEnvironment  -----


EnabledMPIEnvironment::~EnabledMPIEnvironment()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

EnabledMPIEnvironment& EnabledMPIEnvironment::operator= ( const EnabledMPIEnvironment &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

EnabledMPIEnvironment& EnabledMPIEnvironment::operator= ( EnabledMPIEnvironment && other )
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

void EnabledMPIEnvironment::disable_(MPIEnvironment* const mpi_environment)
{
    mpi_environment->disable_();
    mpi_environment->changeMPIState_<COMMUNICATOR::DisabledMPIEnvironment>();
    return;
}
//============================= OPERATORS ====================================


} // namespace COMMUNICATOR
