
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationState.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

SimulationState::SimulationState()
{
    return;
}

SimulationState::SimulationState( SimulationState const & other)
{
    return;
}		// -----  end of method SimulationState::SimulationState  -----

SimulationState::SimulationState( SimulationState && other)
{
    return;
}		// -----  end of method SimulationState::SimulationState  -----


SimulationState::~SimulationState()
{
    return;
}

//============================= ACCESSORS ====================================
void SimulationState::initializeSimulationEnvironment(Simulation* const a_simulation) const
{
    this->initializeSimulationEnvironment_(a_simulation);
}

void SimulationState::processCommandLine(Simulation* const a_simulation) const
{
    this->processCommandLine_(a_simulation);
}

void SimulationState::initializeInitialCondition (Simulation * const a_simulation ) const
{
    this->initializeInitialCondition_(a_simulation);
    return ;
}		/* -----  end of method SimulationState::initializeInitialCondition  ----- */

void SimulationState::performSimulation (Simulation * const a_simulation ) const
{
    this->performSimulation_(a_simulation);
    return ;
}		/* -----  end of method SimulationState::performSimulation  ----- */

void SimulationState::terminateSimulation (Simulation * const a_simulation ) const
{
    this->terminateSmulation_(a_simulation);
    return ;
}		/* -----  end of method SimulationState::terminateSmulation  ----- */

void SimulationState::who_am_i() const
{
    std::cout << "I'm a SimulationState" << std::endl;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

SimulationState& SimulationState::operator= ( const SimulationState &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

SimulationState& SimulationState::operator= ( SimulationState && other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

std::string SimulationState::misbehviorErrorMessage_(state_misbehavior_info const & error_info) const
{
    std::string error_message;
    error_message += "Warining! The simulation state ";
    error_message += error_info.at("simulation_state");
    error_message += " is doing an inappropiate behavior: \n";
    error_message += error_info.at("inappropiate_behavior");
    error_message += "\n";
    return error_message;
}

void SimulationState::initializeSimulationEnvironment_(Simulation* const a_simulation) const
{
    std::string message("This simulation state can't initialize the simulation environment.");
    std::cout << message.c_str() << std::endl;
    return;
}		/* -----  end of method SimulationState::initializeSimulationEnvironment_  ----- */

void SimulationState::processCommandLine_( Simulation* const a_simulation ) const 
{
    std::string message("This simulation state can't process the command line.");
    std::cout << message.c_str() << std::endl;
    return;
}		/* -----  end of method SimulationState::processCommandLine  ----- */

void SimulationState::initializeInitialCondition_ (Simulation * const a_simulation ) const
{
    std::string message("This simulation state can't initialize the initial conditions of the simulation.");
    std::cout << message.c_str() << std::endl;
    return ;
}		/* -----  end of method SimulationState::initializeInitialCondition_  ----- */

void SimulationState::performSimulation_ (Simulation * const a_simulation ) const
{
    std::string message("This simulation state can't perform the simulation.");
    std::cout << message.c_str() << std::endl;
    return ;
}		/* -----  end of method SimulationState::performSimulation_  ----- */

void SimulationState::terminateSimulation_ (Simulation * const a_simulation ) const
{
    std::string message("This simulation state can't terminate the simulation.");
    std::cout << message.c_str() << std::endl;
    return ;
}		/* -----  end of method SimulationState::terminateSmulation_  ----- */


//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
