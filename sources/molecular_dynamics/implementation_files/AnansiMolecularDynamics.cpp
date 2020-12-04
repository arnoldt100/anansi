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
    std::cout << "Enabling AnansiMolecularDynamics communication." << std::endl;
    return;
}		/* -----  end of method AnansiMolecularDynamics::_enableCommunication  ----- */

void
AnansiMolecularDynamics::_disableCommunication()
{
    std::cout << "Disabling AnansiMolecularDynamics communication." << std::endl;
    return;
}		/* -----  end of method AnansiMolecularDynamics::_disableCommunication  ----- */

void AnansiMolecularDynamics::_initializeSimulation(int const argc, char const *const *const & argv )
{
    this->_commandLineArguments = COMMANDLINE::CommandLineArguments(argc,argv);
    this->_simulationParameters = SimulationParametersFactory::create(this->_commandLineArguments);
    return;
}
//============================= OPERATORS ====================================


}; /* -----  end of namespace ANANSI  ----- */

