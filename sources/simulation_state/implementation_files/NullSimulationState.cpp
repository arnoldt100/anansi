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

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================
void NullSimulationState::initializeSimulationEnvironment_(Simulation * const aSimulation) const
{
    SimulationState::state_misbehavior_info error_info = 
        { 
            {"simulation_state","NullSimulationState"},
            {"inappropiate_behavior","Initializing simulation environment"}
        };
    std::string error_message = this->misbehviorErrorMessage_(error_info);
    std::cout << error_message.c_str();
    return;
}

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

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
