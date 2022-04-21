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
#include "MDNullSimulationStateVisitor.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDNullSimulationStateVisitor::MDNullSimulationStateVisitor()
{
    return;
}

MDNullSimulationStateVisitor::MDNullSimulationStateVisitor( MDNullSimulationStateVisitor const & other)
{
    return;
}

MDNullSimulationStateVisitor::MDNullSimulationStateVisitor( MDNullSimulationStateVisitor && other)
{
    return;
}		// -----  end of method MDNullSimulationStateVisitor::MDNullSimulationStateVisitor  -----


MDNullSimulationStateVisitor::~MDNullSimulationStateVisitor()
{
    return;
}

//============================= ACCESSORS ====================================
void MDNullSimulationStateVisitor::visit(AnansiMolecularDynamics& a_sim) const
{
    std::cout << "MDNullSimulationStateVisitor::visit(AnansiMolecularDynamics& a_sim)" << std::endl;
    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDNullSimulationStateVisitor& MDNullSimulationStateVisitor::operator= ( const MDNullSimulationStateVisitor &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

MDNullSimulationStateVisitor& MDNullSimulationStateVisitor::operator= ( MDNullSimulationStateVisitor && other )
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
