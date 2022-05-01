
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
    return this->status_();
}

COMMUNICATOR::RegistryAnansiMDStatus Simulation::globalStatus() const
{   
    return COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentFailed;
}

bool Simulation::isISEStatusOkay() const
{
	return this->isISEStatusOkay_();
}

bool Simulation::isISEGlobalStatusOkay() const
{   
    return this->isISEGlobalStatusOkay_();
}

bool Simulation::isIICStatusOkay() const
{
	return this->isIICStatusOkay_();
}

bool Simulation::isHelpOnCommandLine() const
{
    return this->isHelpOnCommandLine_();
}

//============================= MUTATORS =====================================

void
Simulation::enableCommunication ()
{
    this->enableCommunication_();
    return ;
}		/* -----  end of method Simulation::enableCommunication  ----- */


void Simulation::initializeSimulationEnvironment()
{
	this->initializeSimulationEnvironment_();
    return;
}       /* -----  end of method Simulation::initializeSimulationEnvironment  ----- */

void Simulation::processCommandLine() 
{
    this->processCommandLine_();
    return;
}        /* -----  end of method Simulation::processCommandLine  ----- */


void
Simulation::initializeInitialConditions ()
{
    this->initializeInitialConditions_();
    return;
}		/* -----  end of method Simulation::initializeInitialConditions  ----- */

void Simulation::performSimulation()
{
    this->performSimulation_();
    return;
}       /* -----  end of method Simulation::performSimulation  ----- */

void Simulation::terminateSimulationEnvironment(  )
{
    this->terminateSimulationEnvironment_();
    return;
}		// -----  end of method Simulation::terminateSimulationEnvironment  -----

void Simulation::setStatus(const COMMUNICATOR::RegistryAnansiMDStatus aStatus)
{
    this->setStatus_(aStatus);
}

void Simulation::setGlobalISEStatus()
{
    this->setGlobalISEStatus_();
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

COMMUNICATOR::RegistryAnansiMDStatus Simulation::status_() const
{
    return COMMUNICATOR::RegistryAnansiMDStatus::Undefined;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace ANANSI */
