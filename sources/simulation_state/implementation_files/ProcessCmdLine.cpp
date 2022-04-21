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
#include "ProcessCmdLine.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ProcessCmdLine::ProcessCmdLine() :
    SimulationState()
{
    return;
}

ProcessCmdLine::ProcessCmdLine( ProcessCmdLine const & other) :
    SimulationState()
{
    return;
}

ProcessCmdLine::ProcessCmdLine( ProcessCmdLine && other) :
    SimulationState(std::move(other))
{
    return;
}		// -----  end of method ProcessCmdLine::ProcessCmdLine  -----


ProcessCmdLine::~ProcessCmdLine()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ProcessCmdLine& ProcessCmdLine::operator= ( ProcessCmdLine const & other ) 
{
    if (this != &other)
    {
        SimulationState::operator=(other);
    }
    return *this;
} // assignment operator

ProcessCmdLine& ProcessCmdLine::operator= ( ProcessCmdLine && other )
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
void ProcessCmdLine::execute_(Simulation * const a_simulation) const
{
    this->Execute_(a_simulation);
    return;
}

void ProcessCmdLine::execute_() const
{
    this->Execute_();
    return;
}

void ProcessCmdLine::Execute_(Simulation * const a_simulation) const 
{
    return;
};

void ProcessCmdLine::Execute_() const 
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
