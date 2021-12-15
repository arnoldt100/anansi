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
    AnansiMDState(),
    taskStatus_()
{
    return;
}

AnansiMDStateISE::AnansiMDStateISE( AnansiMDStateISE const & other) :
    AnansiMDState(other),
    taskStatus_(other.taskStatus_)
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method AnansiMDStateISE::AnansiMDStateISE  ----- */

AnansiMDStateISE::AnansiMDStateISE( AnansiMDStateISE && other) :
    AnansiMDState(std::move(other)),
    taskStatus_(std::move(other.taskStatus_))
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
        this->taskStatus_ = other.taskStatus_;
    }
    return *this;
} /* assignment operator */

AnansiMDStateISE& AnansiMDStateISE::operator= ( AnansiMDStateISE && other )
{
    if (this != &other)
    {
        AnansiMDState::operator=(std::move(other));
        this->taskStatus_ = std::move(other.taskStatus_);
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

void AnansiMDStateISE::_initializeSimulationEnvironment(MolecularDynamics* const aMD) const
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
