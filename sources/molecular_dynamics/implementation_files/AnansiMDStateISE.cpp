//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiMolecularDynamics.h"
#include "AnansiMDStateISE.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMDStateISE::AnansiMDStateISE() :
    AnansiMDState()
{
    return;
}

AnansiMDStateISE::AnansiMDStateISE( AnansiMDStateISE const & other) :
    AnansiMDState(other)
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method AnansiMDStateISE::AnansiMDStateISE  ----- */

AnansiMDStateISE::AnansiMDStateISE( AnansiMDStateISE && other) :
    AnansiMDState(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method AnansiMDStateISE::AnansiMDStateISE  ----- */


AnansiMDStateISE::~AnansiMDStateISE()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

AnansiMDStateISE& AnansiMDStateISE::operator=( const AnansiMDStateISE & other )
{
    if (this != &other)
    {
        AnansiMDState::operator=(other);
    }
    return *this;
} /* assignment operator */

AnansiMDStateISE& AnansiMDStateISE::operator= ( AnansiMDStateISE && other )
{
    if (this != &other)
    {
        AnansiMDState::operator=(std::move(other));
    }
    return *this;
} /* assignment-move operator */

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
void AnansiMDStateISE::_execute(Simulation* const aMD) const
{
    // Initialize the MPI environment.
    aMD->initializeMpiEnvironment();

    // Enable MPI communication for the aMD object.
    aMD->enableCommunication();

    // Set the ISE status of this process.
    constexpr auto my_status = COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentSucessful;
    aMD->setStatus(my_status);

    // Set the ISE global status for all processes.
    aMD->setGlobalISEStatus();

    return;
}

void AnansiMDStateISE::_initializeSimulationEnvironment(Simulation* const aMD) const
{
    // Initialize the MPI environment.
    aMD->initializeMpiEnvironment();

    // Enable MPI communication for the aMD object.
    aMD->enableCommunication();

    // Set the ISE status of this process.
    constexpr auto my_status = COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentSucessful;
    aMD->setStatus(my_status);

    // Set the ISE global status for all processes.
    aMD->setGlobalISEStatus();

    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace ANANSI */
