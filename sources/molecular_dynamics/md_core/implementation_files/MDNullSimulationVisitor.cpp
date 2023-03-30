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
#include "MDNullSimulationVisitor.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDNullSimulationVisitor::MDNullSimulationVisitor()
{
    return;
}

MDNullSimulationVisitor::MDNullSimulationVisitor( MDNullSimulationVisitor const & other)
{
    if (this != &other)
    {

    }
    return;
}

MDNullSimulationVisitor::MDNullSimulationVisitor( MDNullSimulationVisitor && other)
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method MDNullSimulationVisitor::MDNullSimulationVisitor  -----


MDNullSimulationVisitor::~MDNullSimulationVisitor()
{
    return;
}

//============================= ACCESSORS ====================================
void MDNullSimulationVisitor::visit(AnansiMolecularDynamics& a_sim) const
{
    std::cout << "MDNullSimulationVisitor::visit(AnansiMolecularDynamics& a_sim)" << std::endl;
    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDNullSimulationVisitor& MDNullSimulationVisitor::operator= ( const MDNullSimulationVisitor &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

MDNullSimulationVisitor& MDNullSimulationVisitor::operator= ( MDNullSimulationVisitor && other )
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
