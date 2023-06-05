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

MDNullSimulationVisitor::MDNullSimulationVisitor() :
    MPL::BaseVisitor(),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>()
{
    return;
}

MDNullSimulationVisitor::MDNullSimulationVisitor( MDNullSimulationVisitor const & other) :
    MPL::BaseVisitor(other),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>(other)
{
    if (this != &other)
    {

    }
    return;
}

MDNullSimulationVisitor::MDNullSimulationVisitor( MDNullSimulationVisitor && other) :
    MPL::BaseVisitor(std::move(other)),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>(std::move(other))

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
        MPL::BaseVisitor::operator=(other);
        MPL::Visitor<ANANSI::AnansiMolecularDynamics>::operator=(other);
    }
    return *this;
} // assignment operator

MDNullSimulationVisitor& MDNullSimulationVisitor::operator= ( MDNullSimulationVisitor && other )
{
    if (this != &other)
    {
        MPL::BaseVisitor::operator=(std::move(other));
        MPL::Visitor<ANANSI::AnansiMolecularDynamics>::operator=(std::move(other));
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
