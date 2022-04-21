//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "NullSimulationState.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

NullSimulationState::NullSimulationState() :
    SimulationState()
{
    return;
}

NullSimulationState::NullSimulationState( NullSimulationState const & other) :
    SimulationState()
{
    return;
}

NullSimulationState::NullSimulationState( NullSimulationState && other) :
    SimulationState(std::move(other))
{
    return;
}		// -----  end of method NullSimulationState::NullSimulationState  -----


NullSimulationState::~NullSimulationState()
{
    return;
}

//============================= ACCESSORS ====================================
void NullSimulationState::who_am_i() const
{
    std::cout << "I'm a NullSimulationState" << std::endl;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

NullSimulationState& NullSimulationState::operator= ( NullSimulationState const & other ) 
{
    if (this != &other)
    {
        SimulationState::operator=(other);
    }
    return *this;
} // assignment operator

NullSimulationState& NullSimulationState::operator= ( NullSimulationState && other )
{
    if (this != &other)
    {
        SimulationState::operator=(std::move(other));
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================
void NullSimulationState::processCommandLine_(Simulation * const aSimulation) const
{
    SimulationState::state_misbehavior_info error_info = 
        { 
            {"simulation_state","NullSimulationState"},
            {"inappropiate_behavior","Processing command line"}
        };
    std::string error_message = this->misbehviorErrorMessage_(error_info);
    std::cout << error_message.c_str();
    return;
}

void NullSimulationState::execute_(Simulation * const a_simulation) const
{
    this->Execute_(a_simulation);
    return;
}

void NullSimulationState::execute_() const
{
    this->Execute_();
    return;
}

void NullSimulationState::Execute_(Simulation * const a_simulation) const 
{
    return;
};

void NullSimulationState::Execute_() const 
{
    return;
};

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
