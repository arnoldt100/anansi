//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiMDState.h"
#include "RegistryAnansiMDStatus.h"
#include "MolecularDynamics.h"

namespace ANANSI {

class AnansiMDStatePCL;
class AnansiMDStateTSE;

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMDState::AnansiMDState()
{
    return;
} /* -----  end of method AnansiMDState::AnansiMDState  ----- */

AnansiMDState::AnansiMDState( AnansiMDState const & other)
{
    if (this != &other)
    {

    }
    return;
} /* -----  end of method AnansiMDState::AnansiMDState  ----- */

AnansiMDState::AnansiMDState( AnansiMDState && other)
{
    if (this != &other)
    {

    }
    return;
} /* -----  end of method AnansiMDState::AnansiMDState  ----- */


AnansiMDState::~AnansiMDState()
{
    return;
} /* -----  end of method AnansiMDState::~AnansiMDState  ----- */

//============================= ACCESSORS ====================================
void AnansiMDState::execute(MolecularDynamics * const aMD ) const
{
    return;
}

void AnansiMDState::initializeSimulationEnvironment(MolecularDynamics* aMD) const
{
    // Here we create aliases simply for coding format convenience.
    constexpr auto in_progress = COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentInProgess;

    // Set the status of the MD object to "in_progress" for initializing the
    // simulation environment.
    aMD->setStatus(in_progress);

    // Initialize the simulation environment.
    this->_initializeSimulationEnvironment(aMD);

    // We now query the status of initializing the simulation environment.
    // If the status if initialized simulation environment is okay then change the MD object state
    // to process command line, otherwise change state to terminating simulation environment.
    if ( aMD->isISEStatusOkay() )
    {
        // :TODO:12/23/2021 10:11:05 AM:: Fix the incomplete type ‘ANANSI::AnansiMDStatePCL::id 
        // aMD->changeMDState(AnansiMDStatePCL::id);
        // std::cout << "The program has successfully initialized the simulation environment." << std::endl;
    }
    else
    {
        // :TODO:12/23/2021 10:11:05 AM:: Fix the incomplete type ‘ANANSI::AnansiMDStateTSE::id 
        // aMD->changeMDState(AnansiMDStateTSE::id);
        // std::cout << "The program has unsuccessfully initialized the simulation environment." << std::endl;
    }

    // We now query the global status of initializing the simulation environment,
    // If the status if initialized simulation environment is not okay then change the MD object state
    // change state to terminating simulation environment.
    if ( ! aMD->isISEGlobalStatusOkay() )
    {
        // :TODO:12/23/2021 10:11:05 AM:: Fix the incomplete type ‘ANANSI::AnansiMDStateTSE::id 
        // aMD->changeMDState(AnansiMDStateTSE::id);
        // std::cout << "Some of the other processes aren't in a satisfactory state." << std::endl;
    }
    return;
}


void AnansiMDState::processCommandLine(MolecularDynamics* aMD) const
{
    // Here we create aliases simply for coding format convenience.
    constexpr auto in_progress = COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentInProgess;
    constexpr auto success = COMMUNICATOR::RegistryAnansiMDStatus::ProcessingCommandLineSuccessful;
    constexpr auto fail = COMMUNICATOR::RegistryAnansiMDStatus::ProcessingCommandLineFailed;
    constexpr auto tse = COMMUNICATOR::RegistryAnansiMDStatus::TerminatingSimulationEnvironmentInProgress;

    this->_processCommandLine(aMD);

    const auto md_status = aMD->status();
    switch ( md_status )
    {
        // Case for successful completion of processing the command line arguments.
        case success :
            aMD->changeMDStateToIIC();
            std::cout << "The program has successfully processed the commandline environment." << std::endl;
            break;

        // Case for unsuccessful processing of command line arguments.
        // We change the state to terminating the simulation environment.
        case fail :
            aMD->changeMDStateToTSE();
            std::cout << "The program has unsuccessfully processed the commandline environment." << std::endl;
            break;

        // Case for processing the command line arguments, but the command line
        // arguments are such that we are forced to terminate the simulation.
        // For example, the help option is found on the command line, or we
        // have incompatible arguments. We change the state to terminating the
        // simulation environment.
        case tse :
            aMD->changeMDStateToTSE();
            std::cout << "The program has successfully processed the commandline environment" << std::endl;
            std::cout << "but the command line has errors or the help option is present." << std::endl;
            break;

        // Case for undefined behavior of processing the command line arguments.
        // We change the state to terminating the simulation environment.
        default :
            aMD->changeMDStateToTSE();
            std::cout << "The program has undetermined behavior in processing the commandline environment" << std::endl;
            break;
    }

    // TO BE IMPLEMENTED
    // Query the status of the other processes. If any other processes have failed, then
    // set this process to fail and change state the terminate simulation environment.

    return;
}


void AnansiMDState::initializeInitialConditions(MolecularDynamics * const aMD) const
{
    // Here we create aliases simply for coding format convenience.
    constexpr auto in_progress = COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentInProgess;
    constexpr auto success = COMMUNICATOR::RegistryAnansiMDStatus::InitializingInitialConditionSuccessful;
    constexpr auto fail = COMMUNICATOR::RegistryAnansiMDStatus::InitializingInitialConditionFailed;
    constexpr auto tse = COMMUNICATOR::RegistryAnansiMDStatus::TerminatingSimulationEnvironmentInProgress;

    // Set the status of the MD object to "in_progress" for initializing the
    // simulation environment.
    aMD->setStatus(in_progress);

    this->_initializeInitialConditions(aMD);

    const auto md_status = aMD->status();
    switch ( md_status )
    {
        // Case for successful initialization of the initial conditions.
        case success :
            aMD->changeMDStateToPS();
            std::cout << "This state has successfully initialized the simulation initial conditions environment." << std::endl;
            break;

        // Case for unsuccessful initialization of the initial conditions.
        // We change the state to terminating the simulation environment.
        case fail :
            aMD->changeMDStateToTSE();
            std::cout << "This state has unsuccessfully initialized the simulation initial conditions environment." << std::endl;
            break;

        // Case for undefined behavior of initialization of the initial conditions.
        // We change the state to terminating the simulation environment.
        default :
            aMD->changeMDStateToTSE();
            std::cout << "This state has undefined behavior in initialization the simulation initial conditions environment." << std::endl;
            break;
    }
    
    // TO BE IMPLEMENTED
    // Query the status of the other processes. If any other processes have failed, then
    // set this process to fail and change state the terminate simulation environment.

    return;
}        // -----  end of method AnansiMDState::initializeInitialConditions  -----

void AnansiMDState::performSimulation(MolecularDynamics * const aMD) const
{
    // Here we create aliases simply for coding format convenience.
    constexpr auto in_progress = COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentInProgess;
    constexpr auto success = COMMUNICATOR::RegistryAnansiMDStatus::PerfomingSimulationSuccessful;
    constexpr auto fail = COMMUNICATOR::RegistryAnansiMDStatus::PerfomingSimulationFailed;
    constexpr auto tse = COMMUNICATOR::RegistryAnansiMDStatus::TerminatingSimulationEnvironmentInProgress;

    // Set the status of the MD object to "in_progress" for initializing the
    // simulation environment.
    aMD->setStatus(in_progress);

    this->_performSimulation(aMD);
    
    const auto md_status = aMD->status();
    switch ( md_status )
    {
        // Case for successful perform of simulation.
        case success :
            aMD->changeMDStateToTSE();
            std::cout << "This state has successfully performed the simulation environment." << std::endl;
            break;

        // Case for unsuccessful perform of simulation.
        // We change the state to terminating the simulation environment.
        case fail :
            aMD->changeMDStateToTSE();
            std::cout << "This state has unsuccessfully performed the simulation environment." << std::endl;
            break;

        // Case for undefined behavoir of performing the simulation.
        // We change the state to terminating the simulation environment.
        default :
            aMD->changeMDStateToTSE();
            std::cout << "This state has undefined behavoir in performed the simulation environment." << std::endl;
            break;
    }
    
    // TO BE IMPLEMENTED
    // Query the status of the other processes. If any other processes have failed, then
    // set this process to fail and change state the terminate simulation environment.

    return;
}        // -----  end of method AnansiMDState::performSimulation  -----

void AnansiMDState::terminateSimulationEnvironment(MolecularDynamics * const aMD) const
{
    this->_terminateSimulationEnvironment(aMD);
    std::cout << "The program has successfully terminated the simulation environment." << std::endl;
    return;
}		// -----  end of method AnansiMDState::terminateSimulationEnvironment  -----

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

AnansiMDState& AnansiMDState::operator=( const AnansiMDState &other )
{
    if (this != &other)
    {

    }
    return *this;
} /* end of assignment operator */

AnansiMDState& AnansiMDState::operator=( AnansiMDState && other )
{
    if (this != &other)
    {

    }
    return *this;
} /* end of assignment-move operator */

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

void AnansiMDState::_execute(MolecularDynamics * const aMD) const
{
    std::cout << "Error: This state can't execute the command." << std::endl;
    return;
}

void AnansiMDState::_initializeSimulationEnvironment(MolecularDynamics * const aMD) const
{
    std::cout << "Error: This state can't 'initialize the simulation environment'." << std::endl;
    return;
}

void AnansiMDState::_processCommandLine(MolecularDynamics * const aMD) const
{
    std::cout << "Error: This state can't 'process the command line environment'." << std::endl;
    return;
}

void
AnansiMDState::_initializeInitialConditions(MolecularDynamics * const aMD) const
{
    std::cout << "Error: This state can't 'initialize the initial conditions environment'." << std::endl;
    return ;
}        // -----  end of method AnansiMDState::_initializeInitialConditions  -----

void
AnansiMDState::_performSimulation(MolecularDynamics * const aMD) const
{
    std::cout << "Error: This state can't 'perform the simulation environment'." << std::endl;
    return ;
}        // -----  end of method AnansiMDState::_performSimulation  -----

void
AnansiMDState::_terminateSimulationEnvironment(MolecularDynamics * const aMD) const
{
    std::cout << "Error: This state can't 'terminate the simulation environment'." << std::endl;
    return;
}		// -----  end of method AnansiMDState::_terminateSimulationEnvironment  -----

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace ANANSI */
