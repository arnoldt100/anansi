
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

void SimulationState::execute(Simulation* const a_simulation) const
{
    this->execute_(a_simulation);
}

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
void SimulationState::execute_(Simulation* const a_simulation) const
{
    std::string message("This simulation state executes a stud command!");
    std::cout << message.c_str() << std::endl;
    return;
}

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
