//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <iostream>
#include <typeinfo>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "InitSimEnv.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

InitSimEnv::InitSimEnv() :
    SimulationState()
{
    return;
}

InitSimEnv::InitSimEnv( InitSimEnv const & other) :
    SimulationState()
{
    if (this != &other)
    {

    }
    return;
}

InitSimEnv::InitSimEnv( InitSimEnv && other) :
    SimulationState(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method InitSimEnv::InitSimEnv  -----


InitSimEnv::~InitSimEnv()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

InitSimEnv& InitSimEnv::operator= ( InitSimEnv const & other ) 
{
    if (this != &other)
    {
        SimulationState::operator=(other);
    }
    return *this;
} // assignment operator

InitSimEnv& InitSimEnv::operator= ( InitSimEnv && other )
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
void InitSimEnv::execute_(Simulation * const a_simulation) const
{
    this->Execute_(a_simulation);
    return;
}

void InitSimEnv::Execute_(Simulation * const a_simulation) const 
{
    return;
    std::string message("This InitSimEnv::Execute executes a stud command! \n"); 
    message += "The simulation is type: ";
    message += typeid(a_simulation).name(); 
    std::cout << message.c_str() << std::endl << std::flush;
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
