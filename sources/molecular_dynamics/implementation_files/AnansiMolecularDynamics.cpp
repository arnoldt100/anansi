//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiMolecularDynamics.h"
#include "AnansiMDStateIIC.h"
#include "AnansiMDStateISE.h"
#include "AnansiMDStatePCL.h"
#include "AnansiMDStatePS.h"
#include "AnansiMDStateTSE.h"
#include "Pointer.hpp"
#include "SimulationParametersFactory.h"
#include "MPICommunicatorFactory.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMolecularDynamics::AnansiMolecularDynamics() : 
    MolecularDynamics(),
    _commandLineArguments(),
    _simulationParameters(),
    _MpiWorldCommunicator(),
    _MpiEnvironment(),
    _mdState()
{
    return;
}

AnansiMolecularDynamics::~AnansiMolecularDynamics()
{
    // Disable the communication.
    this->disableCommunication();
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

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
void AnansiMolecularDynamics::_doSimulation()
{
    std::cout << "Doing AnansiMolecularDynamics simulation" << std::endl;
    return;
}

void
AnansiMolecularDynamics::_enableCommunication()
{
    COMMUNICATOR::MPICommunicatorFactory a_communicator_factory;

    this->_MpiWorldCommunicator = a_communicator_factory.createCommunicator();
    std::cout << "Enabling AnansiMolecularDynamics communication." << std::endl;
    return;
}       /* -----  end of method AnansiMolecularDynamics::_enableCommunication  ----- */

void
AnansiMolecularDynamics::_disableCommunication()
{
    this->_MpiWorldCommunicator->freeCommunicator();
    std::cout << "Disabling AnansiMolecularDynamics communication." << std::endl;
    return;
}       /* -----  end of method AnansiMolecularDynamics::_disableCommunication  ----- */

void
AnansiMolecularDynamics::_initializeSimulation(int const argc, char const *const *const & argv )
{
    this->_commandLineArguments = COMMANDLINE::CommandLineArguments(argc,argv);
    this->_simulationParameters = SimulationParametersFactory::create(this->_commandLineArguments);
    return;
}


void
AnansiMolecularDynamics::_initializeSimulationEnvironment(int const argc, char const *const *const & argv )
{
    
    // Initialize the MPI environment.
    int tmp_argc = argc;

    this->_MpiEnvironment = std::make_unique<COMMUNICATOR::MPIEnvironment>(argc,argv);

    // After successfully initializing the environment, we change the MD state to
    // AnansiMDStateIIC.
    std::unique_ptr<AnansiMDState> new_simulation_state = std::make_unique<AnansiMDStateIIC>(); 
    this->setMDState(std::move(new_simulation_state));

    return;
}

void
AnansiMolecularDynamics::_setMDState(std::unique_ptr<AnansiMDState> && a_AnansiMDState)
{
    this->_mdState = std::move(a_AnansiMDState);
    return;
}

//============================= OPERATORS ====================================


}; /* -----  end of namespace ANANSI  ----- */

