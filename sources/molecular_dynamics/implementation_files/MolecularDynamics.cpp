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

COMMUNICATOR::RegistryAnansiMDStatus MolecularDynamics::status() const
{   
    return this->_status();
}

COMMUNICATOR::RegistryAnansiMDStatus MolecularDynamics::globalStatus() const
{   
    return COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentFailed;
}

bool MolecularDynamics::isISEStatusOkay() const
{
	return this->_isISEStatusOkay();
}

bool MolecularDynamics::isISEGlobalStatusOkay() const
{   
    return this->_isISEGlobalStatusOkay();
}

bool MolecularDynamics::isIICStatusOkay() const
{
	return this->_isIICStatusOkay();
}

bool MolecularDynamics::isHelpOnCommandLine() const
{
    return this->_isHelpOnCommandLine();
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


void MolecularDynamics::initializeSimulationEnvironment()
{
	this->_initializeSimulationEnvironment();
    return;
}       /* -----  end of method MolecularDynamics::initializeSimulationEnvironment  ----- */


void MolecularDynamics::initializeMpiEnvironment()
{
    this->_initializeMpiEnvironment();
    return;
}       /* -----  end of method MolecularDynamics::initializeMpiEnvironment  ----- */


void MolecularDynamics::processCommandLine() 
{
    this->_processCommandLine();
    return;
}        /* -----  end of method MolecularDynamics::processCommandLine  ----- */


void
MolecularDynamics::saveCommandLineOptionsValues()
{
    this->_saveCommandLineOptionParameters();
    return;
}		/* -----  end of method MolecularDynamics::saveCommandLineOptionsValues  ----- */


void
MolecularDynamics::initializeInitialConditions ()
{
    this->_initializeInitialConditions();
    return;
}		/* -----  end of method MolecularDynamics::initializeInitialConditions  ----- */

void MolecularDynamics::readInitialConfiguration ()
{
	this->_readInitialConfiguration();
	return;
}

void MolecularDynamics::inputSimulationControlFile()
{
    this->_inputSimulationControlFile();
    return;
}   /* -----  end of method MolecularDynamics::inputSimulationControlFile  ----- */

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


void MolecularDynamics::changeMDStateToNull()
{
    this->_changeMDStateToNull();
}

void MolecularDynamics::changeMDStateToISE()
{
    this->_changeMDStateToISE();
}

void MolecularDynamics::changeMDStateToPCL()
{
    this->_changeMDStateToPCL();
}

void MolecularDynamics::changeMDStateToIIC()
{
    this->_changeMDStateToIIC();
}

void MolecularDynamics::changeMDStateToPS()
{
    this->_changeMDStateToPS();
}

void MolecularDynamics::changeMDStateToTSE()
{
    this->_changeMDStateToTSE();
}

void MolecularDynamics::setStatus(const COMMUNICATOR::RegistryAnansiMDStatus aStatus)
{
    this->_setStatus(aStatus);
}

void MolecularDynamics::setGlobalISEStatus()
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

COMMUNICATOR::RegistryAnansiMDStatus MolecularDynamics::_status() const
{
    return COMMUNICATOR::RegistryAnansiMDStatus::Undefined;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace ANANSI */
