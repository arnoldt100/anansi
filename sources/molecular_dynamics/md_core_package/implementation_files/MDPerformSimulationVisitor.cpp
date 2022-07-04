//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MDPerformSimulationVisitor.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDPerformSimulationVisitor::MDPerformSimulationVisitor()
{
    return;
}

MDPerformSimulationVisitor::MDPerformSimulationVisitor( MDPerformSimulationVisitor const & other)
{
    return;
}

MDPerformSimulationVisitor::MDPerformSimulationVisitor( MDPerformSimulationVisitor && other)
{
    return;
}		// -----  end of method MDPerformSimulationVisitor::MDPerformSimulationVisitor  -----


MDPerformSimulationVisitor::~MDPerformSimulationVisitor()
{
    return;
}

//============================= ACCESSORS ====================================
void MDPerformSimulationVisitor::visit(AnansiMolecularDynamics& a_sim) const
{
    std::cout << "MDPerformSimulationVisitor::visit(AnansiMolecularDynamics& a_sim)" << std::endl;
    a_sim.stud_function("Perform simulation");
    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDPerformSimulationVisitor& MDPerformSimulationVisitor::operator= ( const MDPerformSimulationVisitor &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

MDPerformSimulationVisitor& MDPerformSimulationVisitor::operator= ( MDPerformSimulationVisitor && other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

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
