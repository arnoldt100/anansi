/*
 * AnansiMolecularDynamics.cpp
 */

#include "AnansiMolecularDynamics.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMolecularDynamics::AnansiMolecularDynamics() : 
    MolecularDynamics(),
    _commandLineArguments(),
    _simulationParameters()
{
    // Parse the command line and store in a 
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
AnansiMolecularDynamics::_setMDState()
{
    std::cout << "State transition occurred." << std::endl;
    return;
}

//============================= OPERATORS ====================================


}; /* -----  end of namespace ANANSI  ----- */

