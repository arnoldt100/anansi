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
#include "AnansiMDStateISE.h"
#include "AnansiMDStatePCL.h"
#include "AnansiMDStateIIC.h"
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
    std::unique_ptr<ANANSI::AnansiMDState> new_md_state = std::make_unique<AnansiMDStateISE>();
    this->setMDState(std::move(new_md_state));
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
void
AnansiMolecularDynamics::_disableCommunication()
{
    this->_MpiWorldCommunicator->freeCommunicator();
    std::cout << "Disabling AnansiMolecularDynamics communication." << std::endl;
    return;
}       /* -----  end of method AnansiMolecularDynamics::_disableCommunication  ----- */

void
AnansiMolecularDynamics::_initializeSimulationEnvironment(int const & argc, char const *const *const & argv )
{
	this->_mdState->initializeSimulationEnvironment(this,argc,argv);
    return;
}

void AnansiMolecularDynamics::_saveCommandLineArguments(int const & argc, char const *const *const & argv)
{
    this->_commandLineArguments = COMMANDLINE::CommandLineArguments(argc,argv);
    return ;
}		/* -----  end of method AnansiMolecularDynamics::_saveCommandLineArguments  ----- */

void AnansiMolecularDynamics::_initializeMpiEnvironment(int const & argc, char const * const * const & argv)
{
    this->_MpiEnvironment = std::make_unique<COMMUNICATOR::MPIEnvironment>(argc,argv);
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

void AnansiMolecularDynamics::_processCommandLine()
{
    this->_mdState->processCommandLine(this);

    // If successful processing of command line options, then change state to AnansiMDStateIIC.
    // Otherwise change state to AnansiMDStateTSE.
    std::unique_ptr<ANANSI::AnansiMDState> new_md_state = std::make_unique<AnansiMDStateIIC>();
    this->setMDState(std::move(new_md_state));
    return;
}


void
AnansiMolecularDynamics::_saveSimulationParameters()
{
    this->_simulationParameters = SimulationParametersFactory::create(this->_commandLineArguments);
    return ;
}		/* -----  end of method AnansiMolecularDynamics::_saveSimulationParameters  ----- */


void
AnansiMolecularDynamics::_initializeInitialConditions()
{
    this->_mdState->initializeInitialConditions(this);

    // If successful initializing the initial conditions, then change state to AnansiMDStatePS.
    // Otherwise change state to AnansiMDStateTSE.
    std::unique_ptr<ANANSI::AnansiMDState> new_md_state = std::make_unique<AnansiMDStatePS>();
    this->setMDState(std::move(new_md_state));
    return;
}        // -----  end of method AnansiMolecularDynamics::_initializeInitialConditions  -----

void AnansiMolecularDynamics::_performSimulation()
{
    this->_mdState->performSimulation(this);

    // If successful performing the simulation, then change state to AnansiMDStateTSE.
    // Otherwise change state to AnansiMDStateTSE.
    std::unique_ptr<ANANSI::AnansiMDState> new_md_state = std::make_unique<AnansiMDStateTSE>();
    this->setMDState(std::move(new_md_state));
    return;
}        // -----  end of method AnansiMolecularDynamics::_performSimulation  -----

void AnansiMolecularDynamics::_terminateSimulationEnvironment()
{
    this->_mdState->terminateSimulationEnvironment(this);
    return;
}		// -----  end of method AnansiMolecularDynamics::_terminateSimulationEnvironment  -----

void
AnansiMolecularDynamics::_setMDState(std::unique_ptr<AnansiMDState> && a_AnansiMDState)
{
    this->_mdState = std::move(a_AnansiMDState);
    return;
}

//============================= OPERATORS ====================================


}; /* -----  end of namespace ANANSI  ----- */

