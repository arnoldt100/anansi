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


void AnansiMDState::initializeSimulationEnvironment(MolecularDynamics* aMD, int const & argc, char const *const *const & argv ) const
{
    // Here we create aliases simply for coding format convenience.
    constexpr auto success =
        ANANSI::RegistryAnansiMDStatus::InitializingSimulationEnvironmentSucessful;
    constexpr auto fail =
        ANANSI::RegistryAnansiMDStatus::InitializingSimulationEnvironmentFail;

    // Initialize the simualtion environment.
    this->_initializeSimulationEnvironment(aMD,argc,argv);

    // We now query the status of initializing the simulation environment,
    // We use a switch statement controlled by the status to appropiately
    // change the MD object state.
    const auto md_status = aMD->status();
    switch ( md_status )
    {
        // Case for successful completion of initializing the simulation environment.
        // case ANANSI::RegistryAnansiMDStatus::InitializingSimulationEnvironmentSucessful :
        case success :
            aMD->changeMDStateToPCL();
            break;

        // Case for unsuccessful completion of initializing the simulation environment.
        // We change the state to terminating the simulation environment.
        case fail :
            aMD->changeMDStateToTSE();
            break;

        // Case for undefined behavoir of initializing the simulation environment.
        // We change the state to terminating the simulation environment.
            aMD->changeMDStateToTSE();
            break;
    }
    return;
}


void AnansiMDState::processCommandLine(MolecularDynamics* aMD) const
{
    this->_processCommandLine(aMD);
    return;
}


void AnansiMDState::initializeInitialConditions(MolecularDynamics * const aMD) const
{
    this->_initializeInitialConditions(aMD);
    return;
}        // -----  end of method AnansiMDState::initializeInitialConditions  -----

void AnansiMDState::performSimulation(MolecularDynamics * const aMD) const
{
    this->_performSimulation(aMD);
    return;
}        // -----  end of method AnansiMDState::performSimulation  -----

void AnansiMDState::terminateSimulationEnvironment(MolecularDynamics * const aMD) const
{
    this->_terminateSimulationEnvironment(aMD);
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

void AnansiMDState::_initializeSimulationEnvironment(MolecularDynamics * const aMD,int const & argc, char const *const *const & argv) const
{
    std::cout << "Error: This state can't 'initialize the simulation environment'.";
    return;
}

void AnansiMDState::_processCommandLine(MolecularDynamics * const aMD) const
{
    std::cout << "Error: This state can't 'process the command line environment'.";
    return;
}

void
AnansiMDState::_initializeInitialConditions(MolecularDynamics * const aMD) const
{
    std::cout << "Error: This state can't 'initialize the initial conditions environment'.";
    return ;
}        // -----  end of method AnansiMDState::_initializeInitialConditions  -----

void
AnansiMDState::_performSimulation(MolecularDynamics * const aMD) const
{
    std::cout << "Error: This state can't 'perform the simulation environment'.";
    return ;
}        // -----  end of method AnansiMDState::_performSimulation  -----

void
AnansiMDState::_terminateSimulationEnvironment(MolecularDynamics * const aMD) const
{
    std::cout << "Error: This state can't 'terminate the simulation environment'.";
    return;
}		// -----  end of method AnansiMDState::_terminateSimulationEnvironment  -----

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace ANANSI */
