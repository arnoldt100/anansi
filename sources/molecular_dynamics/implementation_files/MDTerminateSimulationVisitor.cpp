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
#include "MDTerminateSimulationVisitor.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDTerminateSimulationVisitor::MDTerminateSimulationVisitor()
{
    return;
}

MDTerminateSimulationVisitor::MDTerminateSimulationVisitor( MDTerminateSimulationVisitor const & other)
{
    return;
}

MDTerminateSimulationVisitor::MDTerminateSimulationVisitor( MDTerminateSimulationVisitor && other)
{
    return;
}		// -----  end of method MDTerminateSimulationVisitor::MDTerminateSimulationVisitor  -----


MDTerminateSimulationVisitor::~MDTerminateSimulationVisitor()
{
    return;
}

//============================= ACCESSORS ====================================
void MDTerminateSimulationVisitor::visit(AnansiMolecularDynamics& a_sim) const
{
    std::cout << "MDTerminateSimulationVisitor::visit(AnansiMolecularDynamics& a_sim)" << std::endl;
    a_sim.disableCommunicationEnvironment();
    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDTerminateSimulationVisitor& MDTerminateSimulationVisitor::operator= ( const MDTerminateSimulationVisitor &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

MDTerminateSimulationVisitor& MDTerminateSimulationVisitor::operator= ( MDTerminateSimulationVisitor && other )
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
