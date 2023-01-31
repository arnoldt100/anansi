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
#include "MDInitInitialConditionsVisitor.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDInitInitialConditionsVisitor::MDInitInitialConditionsVisitor()
{
    return;
}

MDInitInitialConditionsVisitor::MDInitInitialConditionsVisitor( MDInitInitialConditionsVisitor const & other)
{
    return;
}

MDInitInitialConditionsVisitor::MDInitInitialConditionsVisitor( MDInitInitialConditionsVisitor && other)
{
    return;
}		// -----  end of method MDInitInitialConditionsVisitor::MDInitInitialConditionsVisitor  -----


MDInitInitialConditionsVisitor::~MDInitInitialConditionsVisitor()
{
    return;
}

//============================= ACCESSORS ====================================
void MDInitInitialConditionsVisitor::visit(AnansiMolecularDynamics& a_sim) const
{
    std::cout << "MDInitInitialConditionsVisitor::visit(AnansiMolecularDynamics& a_sim)" << std::endl;
    a_sim.readInitialConfiguration(); 
    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDInitInitialConditionsVisitor& MDInitInitialConditionsVisitor::operator= ( const MDInitInitialConditionsVisitor &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

MDInitInitialConditionsVisitor& MDInitInitialConditionsVisitor::operator= ( MDInitInitialConditionsVisitor && other )
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
