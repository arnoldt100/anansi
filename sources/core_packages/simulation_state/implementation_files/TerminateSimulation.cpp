//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <utility>
#include <typeinfo>

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
    if (this != &other)
    {

    }
    return;
}

TerminateSimulation::TerminateSimulation( TerminateSimulation && other) :
    SimulationState(std::move(other))
{
    if (this != &other)
    {

    }
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
    std::string message("This TerminateSimulation::Execute executes a stud command! \n"); 
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
