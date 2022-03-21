//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
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
void NullSimulationState::_initializeSimulationEnvironment(Simulation * const aSimulation) const
{
    std::cout << "Error: The NullSimulationState state can't 'initialize the simulation environment'." << std::endl;
    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
