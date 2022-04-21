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
#include "MDProcessCmdLineVisitor.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDProcessCmdLineVisitor::MDProcessCmdLineVisitor()
{
    return;
}

MDProcessCmdLineVisitor::MDProcessCmdLineVisitor( MDProcessCmdLineVisitor const & other)
{
    return;
}

MDProcessCmdLineVisitor::MDProcessCmdLineVisitor( MDProcessCmdLineVisitor && other)
{
    return;
}		// -----  end of method MDProcessCmdLineVisitor::MDProcessCmdLineVisitor  -----


MDProcessCmdLineVisitor::~MDProcessCmdLineVisitor()
{
    return;
}

//============================= ACCESSORS ====================================
void MDProcessCmdLineVisitor::visit(AnansiMolecularDynamics& a_sim) const
{
    std::cout << "MDProcessCmdLineVisitor::visit(AnansiMolecularDynamics& a_sim)" << std::endl;
    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDProcessCmdLineVisitor& MDProcessCmdLineVisitor::operator= ( const MDProcessCmdLineVisitor &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

MDProcessCmdLineVisitor& MDProcessCmdLineVisitor::operator= ( MDProcessCmdLineVisitor && other )
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
