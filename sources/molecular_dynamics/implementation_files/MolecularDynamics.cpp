/*
 * MolecularDynamics.cpp
 */

#include "MolecularDynamics.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================


/*
 *--------------------------------------------------------------------------------------
 *       Class:  MolecularDynamics
 *      Method:  MolecularDynamics
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
MolecularDynamics::MolecularDynamics()
{
    return;
}  /* -----  end of method MolecularDynamics::MolecularDynamics  (constructor)  ----- */


/*--------------------------------------------------------------------------------------
 *       Class:  MolecularDynamics
 *      Method:  MolecularDynamics
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
MolecularDynamics::~MolecularDynamics()
{
    return ;
}		/* -----  end of method MolecularDynamics::~MolecularDynamics  ----- */

//============================= ACCESSORS ====================================

void MolecularDynamics::stud_function(std::string const & message) const
{
    std::cout << "Stud function: " << message << std::endl;
}

//============================= MUTATORS =====================================

void
MolecularDynamics::enableCommunication ()
{
    this->_enableCommunication();
    return ;
}		/* -----  end of method MolecularDynamics::enableCommunication  ----- */

void
MolecularDynamics::disableCommunication()
{
    this->_disableCommunication();
    return ;
}		/* -----  end of method MolecularDynamics::disableCommunication  ----- */


void MolecularDynamics::initializeSimulationEnvironment( int const & argc, char const *const *const & argv )
{
	this->_initializeSimulationEnvironment(argc,argv);
    return;
}       /* -----  end of method MolecularDynamics::initializeSimulationEnvironment  ----- */


void MolecularDynamics::saveCommandLineArguments ( int const & argc, char const *const *const & argv)
{
    this->_saveCommandLineArguments(argc,argv);
    return;
}		/* -----  end of method MolecularDynamics::saveCommandLineArguments  ----- */

void MolecularDynamics::initializeMpiEnvironment(int const & argc, char const *const *const & argv)
{
    this->_initializeMpiEnvironment(argc,argv);
    return;
}       /* -----  end of method MolecularDynamics::initializeMpiEnvironment  ----- */


void MolecularDynamics::processCommandLine() 
{
    this->_processCommandLine();
    return;
}        /* -----  end of method MolecularDynamics::processCommandLine  ----- */


void
MolecularDynamics::saveSimulationParameters()
{
    this->_saveSimulationParameters();
    return ;
}		/* -----  end of method MolecularDynamics::saveSimulationParameters  ----- */


void
MolecularDynamics::initializeInitialConditions ()
{
    this->_initializeInitialConditions();
    return ;
}		/* -----  end of method MolecularDynamics::initializeInitialConditions  ----- */

void MolecularDynamics::performSimulation()
{
    this->_performSimulation();
    return;
}       /* -----  end of method MolecularDynamics::performSimulation  ----- */

void MolecularDynamics::terminateSimulationEnvironment(  )
{
    this->_terminateSimulationEnvironment();
    return;
}		// -----  end of method MolecularDynamics::terminateSimulationEnvironment  -----

void
MolecularDynamics::setMDState(std::unique_ptr<AnansiMDState> && a_AnansiMDState)
{
    this->_setMDState(std::move(a_AnansiMDState));
	return;
}       /* -----  end of method MolecularDynamics::setMDState  ----- */

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

//============================= OPERATORS ====================================


} /* namespace ANANSI */
