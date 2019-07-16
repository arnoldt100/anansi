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

void AnansiMolecularDynamics::_doInitialization(int const argc, char const *const *const & argv )
{
    this->_commandLineArguments = COMMANDLINE::CommandLineArguments(argc,argv);

    this->_simulationParameters = SimulationParametersFactory::create(this->_commandLineArguments);


    return;
}
//============================= OPERATORS ====================================


}; /* -----  end of namespace ANANSI  ----- */

