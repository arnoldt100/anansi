//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <typeinfo>
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
    if (this != &other)
    {

    }
    return;
}

PerformSimulation::PerformSimulation( PerformSimulation && other) :
    SimulationState(std::move(other))
{
    if (this != &other)
    {

    }
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
    std::string message("This PerformSimulation::Execute executes a stud command! \n"); 
    message += "The simulation is type: ";
    message += typeid(a_simulation).name(); 
    std::cout << message.c_str() << std::endl << std::flush;
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
