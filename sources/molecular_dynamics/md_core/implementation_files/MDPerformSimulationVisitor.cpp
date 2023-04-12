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

MDPerformSimulationVisitor::MDPerformSimulationVisitor() :
    MPL::BaseVisitor(),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>()
{
    return;
}

MDPerformSimulationVisitor::MDPerformSimulationVisitor( MDPerformSimulationVisitor const & other) :
    MPL::BaseVisitor(other),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>(other)
{
    if (this != &other)
    {

    }
    return;
}

MDPerformSimulationVisitor::MDPerformSimulationVisitor( MDPerformSimulationVisitor && other) :
    MPL::BaseVisitor(std::move(other)),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>(std::move(other))
{
    if (this != &other)
    {

    }
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
        MPL::BaseVisitor::operator=(other);
        MPL::Visitor<ANANSI::AnansiMolecularDynamics>::operator=(other);
    }
    return *this;
} // assignment operator

MDPerformSimulationVisitor& MDPerformSimulationVisitor::operator=( MDPerformSimulationVisitor && other )
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
