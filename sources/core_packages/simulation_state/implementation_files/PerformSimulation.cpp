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
#include "PerformSimulation.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

PerformSimulation::PerformSimulation() :
    SimulationState()
{
    return;
}

PerformSimulation::PerformSimulation( PerformSimulation const & other) :
    SimulationState()
{
    return;
}

PerformSimulation::PerformSimulation( PerformSimulation && other) :
    SimulationState(std::move(other))
{
    return;
}		// -----  end of method PerformSimulation::PerformSimulation  -----


PerformSimulation::~PerformSimulation()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

PerformSimulation& PerformSimulation::operator= ( PerformSimulation const & other ) 
{
    if (this != &other)
    {
        SimulationState::operator=(other);
    }
    return *this;
} // assignment operator

PerformSimulation& PerformSimulation::operator= ( PerformSimulation && other )
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
void PerformSimulation::execute_(Simulation * const a_simulation) const
{
    this->Execute_(a_simulation);
    return;
}

void PerformSimulation::Execute_(Simulation * const a_simulation) const 
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
