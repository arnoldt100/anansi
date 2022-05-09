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
#include "MDNullSimulationVisitor.h"
#include "MDNullSimulation.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDNullSimulation::MDNullSimulation() :
    NullSimulation()
{
    return;
}

MDNullSimulation::MDNullSimulation( MDNullSimulation const & other) :
    NullSimulation(other)
{
    return;
}

MDNullSimulation::MDNullSimulation( MDNullSimulation && other) :
    NullSimulation(std::move(other))
{
    return;
}		// -----  end of method MDNullSimulation::MDNullSimulation  -----


MDNullSimulation::~MDNullSimulation()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDNullSimulation& MDNullSimulation::operator= ( MDNullSimulation const & other ) 
{
    if (this != &other)
    {
        NullSimulation::operator=(other);
    }
    return *this;
} // assignment operator

MDNullSimulation& MDNullSimulation::operator= ( MDNullSimulation && other )
{
    if (this != &other)
    {
        NullSimulation::operator=(std::move(other));
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================
void MDNullSimulation::Execute_(Simulation * const a_simulation) const 
{
    MDNullSimulationVisitor a_visitor;
    a_simulation->Accept(a_visitor);
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
