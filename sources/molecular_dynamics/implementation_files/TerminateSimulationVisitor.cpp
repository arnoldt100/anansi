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
#include "TerminateSimulationVisitor.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

TerminateSimulationVisitor::TerminateSimulationVisitor()
{
    return;
}

TerminateSimulationVisitor::TerminateSimulationVisitor( TerminateSimulationVisitor const & other)
{
    return;
}

TerminateSimulationVisitor::TerminateSimulationVisitor( TerminateSimulationVisitor && other)
{
    return;
}		// -----  end of method TerminateSimulationVisitor::TerminateSimulationVisitor  -----


TerminateSimulationVisitor::~TerminateSimulationVisitor()
{
    return;
}

//============================= ACCESSORS ====================================
void TerminateSimulationVisitor::visit(AnansiMolecularDynamics& a_sim) const
{
    std::cout << "TerminateSimulationVisitor::visit(AnansiMolecularDynamics& a_sim)" << std::endl;
    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

TerminateSimulationVisitor& TerminateSimulationVisitor::operator= ( const TerminateSimulationVisitor &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

TerminateSimulationVisitor& TerminateSimulationVisitor::operator= ( TerminateSimulationVisitor && other )
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
