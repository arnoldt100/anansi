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
#include "MDNullSimulationStateVisitor.h"
#include "MDNullSimulationState.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDNullSimulationState::MDNullSimulationState() :
    NullSimulationState()
{
    return;
}

MDNullSimulationState::MDNullSimulationState( MDNullSimulationState const & other) :
    NullSimulationState(other)
{
    return;
}

MDNullSimulationState::MDNullSimulationState( MDNullSimulationState && other) :
    NullSimulationState(std::move(other))
{
    return;
}		// -----  end of method MDNullSimulationState::MDNullSimulationState  -----


MDNullSimulationState::~MDNullSimulationState()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDNullSimulationState& MDNullSimulationState::operator= ( MDNullSimulationState const & other ) 
{
    if (this != &other)
    {
        NullSimulationState::operator=(other);
    }
    return *this;
} // assignment operator

MDNullSimulationState& MDNullSimulationState::operator= ( MDNullSimulationState && other )
{
    if (this != &other)
    {
        NullSimulationState::operator=(std::move(other));
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================
void MDNullSimulationState::Execute_(Simulation * const a_simulation) const 
{
    MDNullSimulationStateVisitor a_visitor;
    a_simulation->Accept(a_visitor);
    return;
};

void MDNullSimulationState::Execute_() const 
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
