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
    return;
}

InitSimEnv::InitSimEnv( InitSimEnv && other) :
    SimulationState(std::move(other))
{
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
