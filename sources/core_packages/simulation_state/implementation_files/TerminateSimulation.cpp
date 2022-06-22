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
#include "TerminateSimulation.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

TerminateSimulation::TerminateSimulation() :
    SimulationState()
{
    return;
}

TerminateSimulation::TerminateSimulation( TerminateSimulation const & other) :
    SimulationState()
{
    return;
}

TerminateSimulation::TerminateSimulation( TerminateSimulation && other) :
    SimulationState(std::move(other))
{
    return;
}		// -----  end of method TerminateSimulation::TerminateSimulation  -----


TerminateSimulation::~TerminateSimulation()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

TerminateSimulation& TerminateSimulation::operator= ( TerminateSimulation const & other ) 
{
    if (this != &other)
    {
        SimulationState::operator=(other);
    }
    return *this;
} // assignment operator

TerminateSimulation& TerminateSimulation::operator= ( TerminateSimulation && other )
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
void TerminateSimulation::execute_(Simulation * const a_simulation) const
{
    this->Execute_(a_simulation);
    return;
}

void TerminateSimulation::Execute_(Simulation * const a_simulation) const 
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
