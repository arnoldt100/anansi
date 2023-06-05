
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

bool Simulation::isHelpOnCommandLine() const
{
    return this->isHelpOnCommandLine_();
}

//============================= MUTATORS =====================================

void Simulation::initializeSimulationEnvironment()
{
	this->initializeSimulationEnvironment_();
    return;
}       /* -----  end of method Simulation::initializeSimulationEnvironment  ----- */

void Simulation::processCommandLine() 
{
    this->processCommandLine_();

    // Check for help on the command line. If help is found then print
    // the help message and terminate the simulation.
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
