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
#include "NullSimulation.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

NullSimulation::NullSimulation() :
    SimulationState()
{
    return;
}

NullSimulation::NullSimulation( NullSimulation const & other) :
    SimulationState()
{
    if (this != &other)
    {

    }
    return;
}

NullSimulation::NullSimulation( NullSimulation && other) :
    SimulationState(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method NullSimulation::NullSimulation  -----


NullSimulation::~NullSimulation()
{
    return;
}

//============================= ACCESSORS ====================================
void NullSimulation::who_am_i() const
{
    std::cout << "I'm a NullSimulation" << std::endl;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

NullSimulation& NullSimulation::operator= ( NullSimulation const & other ) 
{
    if (this != &other)
    {
        SimulationState::operator=(other);
    }
    return *this;
} // assignment operator

NullSimulation& NullSimulation::operator= ( NullSimulation && other )
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
// void NullSimulation::processCommandLine_(Simulation * const aSimulation) const
// {
//     SimulationState::state_misbehavior_info error_info = 
//         { 
//             {"simulation_state","NullSimulation"},
//             {"inappropiate_behavior","Processing command line"}
//         };
//     std::string error_message = this->misbehviorErrorMessage_(error_info);
//     std::cout << error_message.c_str();
//     return;
// }

void NullSimulation::execute_(Simulation * const a_simulation) const
{
    this->Execute_(a_simulation);
    return;
}

void NullSimulation::Execute_(Simulation * const a_simulation) const 
{
    std::string message("This Simulation::Execute executes a stud command! \n"); 
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
