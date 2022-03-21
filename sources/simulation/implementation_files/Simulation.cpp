
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Simulation.h"

namespace ANANSI {

//============================= LIFECYCLE ====================================


/*
 *--------------------------------------------------------------------------------------
 *       Class:  Simulation
 *      Method:  Simulation
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
Simulation::Simulation()
{
    return;
}  /* -----  end of method Simulation::Simulation  (constructor)  ----- */


/*--------------------------------------------------------------------------------------
 *       Class:  Simulation
 *      Method:  Simulation
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
Simulation::~Simulation()
{
    return ;
}		/* -----  end of method Simulation::~Simulation  ----- */

//============================= ACCESSORS ====================================

void Simulation::stud_function(std::string const & message) const
{
    std::cout << "Stud function: " << message << std::endl;
}

COMMUNICATOR::RegistryAnansiMDStatus Simulation::status() const
{   
    return this->_status();
}

COMMUNICATOR::RegistryAnansiMDStatus Simulation::globalStatus() const
{   
    return COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentFailed;
}

bool Simulation::isISEStatusOkay() const
{
	return this->_isISEStatusOkay();
}

bool Simulation::isISEGlobalStatusOkay() const
{   
    return this->_isISEGlobalStatusOkay();
}

bool Simulation::isIICStatusOkay() const
{
	return this->_isIICStatusOkay();
}

bool Simulation::isHelpOnCommandLine() const
{
    return this->_isHelpOnCommandLine();
}

//============================= MUTATORS =====================================

void
Simulation::enableCommunication ()
{
    this->_enableCommunication();
    return ;
}		/* -----  end of method Simulation::enableCommunication  ----- */


void
Simulation::disableCommunication()
{
    this->_disableCommunication();
    return ;
}		/* -----  end of method Simulation::disableCommunication  ----- */


void Simulation::initializeSimulationEnvironment()
{
	this->_initializeSimulationEnvironment();
    return;
}       /* -----  end of method Simulation::initializeSimulationEnvironment  ----- */


void Simulation::initializeMpiEnvironment()
{
    this->_initializeMpiEnvironment();
    return;
}       /* -----  end of method Simulation::initializeMpiEnvironment  ----- */


void Simulation::processCommandLine() 
{
    this->_processCommandLine();
    return;
}        /* -----  end of method Simulation::processCommandLine  ----- */


void
Simulation::saveCommandLineOptionsValues()
{
    this->_saveCommandLineOptionParameters();
    return;
}		/* -----  end of method Simulation::saveCommandLineOptionsValues  ----- */


void
Simulation::initializeInitialConditions ()
{
    this->_initializeInitialConditions();
    return;
}		/* -----  end of method Simulation::initializeInitialConditions  ----- */

void Simulation::readInitialConfiguration ()
{
	this->_readInitialConfiguration();
	return;
}

void Simulation::inputSimulationControlFile()
{
    this->_inputSimulationControlFile();
    return;
}   /* -----  end of method Simulation::inputSimulationControlFile  ----- */

void Simulation::performSimulation()
{
    this->_performSimulation();
    return;
}       /* -----  end of method Simulation::performSimulation  ----- */

void Simulation::terminateSimulationEnvironment(  )
{
    this->_terminateSimulationEnvironment();
    return;
}		// -----  end of method Simulation::terminateSimulationEnvironment  -----


void Simulation::changeMDStateToPCL()
{
    this->_changeMDStateToPCL();
}

void Simulation::changeMDStateToIIC()
{
    this->_changeMDStateToIIC();
}

void Simulation::changeMDStateToPS()
{
    this->_changeMDStateToPS();
}

void Simulation::changeMDStateToTSE()
{
    this->_changeMDStateToTSE();
}

void Simulation::changeMDState()
{
    this->_changeMDState();
}

void Simulation::setStatus(const COMMUNICATOR::RegistryAnansiMDStatus aStatus)
{
    this->_setStatus(aStatus);
}

void Simulation::setGlobalISEStatus()
{
    this->_setGlobalISEStatus();
}
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

COMMUNICATOR::RegistryAnansiMDStatus Simulation::_status() const
{
    return COMMUNICATOR::RegistryAnansiMDStatus::Undefined;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace ANANSI */
