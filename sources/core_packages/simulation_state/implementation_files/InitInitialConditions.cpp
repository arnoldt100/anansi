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
#include "InitInitialConditions.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

InitInitialConditions::InitInitialConditions() :
    SimulationState()
{
    return;
}

InitInitialConditions::InitInitialConditions( InitInitialConditions const & other) :
    SimulationState()
{
    return;
}

InitInitialConditions::InitInitialConditions( InitInitialConditions && other) :
    SimulationState(std::move(other))
{
    return;
}		// -----  end of method InitInitialConditions::InitInitialConditions  -----


InitInitialConditions::~InitInitialConditions()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

InitInitialConditions& InitInitialConditions::operator= ( InitInitialConditions const & other ) 
{
    if (this != &other)
    {
        SimulationState::operator=(other);
    }
    return *this;
} // assignment operator

InitInitialConditions& InitInitialConditions::operator= ( InitInitialConditions && other )
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
void InitInitialConditions::execute_(Simulation * const a_simulation) const
{
    this->Execute_(a_simulation);
    return;
}

void InitInitialConditions::Execute_(Simulation * const a_simulation) const 
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
