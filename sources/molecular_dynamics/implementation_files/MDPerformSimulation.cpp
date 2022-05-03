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
#include "MDPerformSimulationVisitor.h"
#include "MDPerformSimulation.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDPerformSimulation::MDPerformSimulation() :
    PerformSimulation()
{
    return;
}

MDPerformSimulation::MDPerformSimulation( MDPerformSimulation const & other) :
    PerformSimulation(other)
{
    return;
}

MDPerformSimulation::MDPerformSimulation( MDPerformSimulation && other) :
    PerformSimulation(std::move(other))
{
    return;
}		// -----  end of method MDPerformSimulation::MDPerformSimulation  -----


MDPerformSimulation::~MDPerformSimulation()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDPerformSimulation& MDPerformSimulation::operator= ( const MDPerformSimulation &other )
{
    if (this != &other)
    {
        PerformSimulation::operator=(other);
    }
    return *this;
} // assignment operator

MDPerformSimulation& MDPerformSimulation::operator= ( MDPerformSimulation && other )
{
    if (this != &other)
    {
        PerformSimulation::operator=(std::move(other));
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

void MDPerformSimulation::Execute_(Simulation * const a_simulation) const 
{
    MDPerformSimulationVisitor a_visitor;
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
