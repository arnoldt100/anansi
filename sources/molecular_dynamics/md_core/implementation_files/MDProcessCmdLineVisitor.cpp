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

MDProcessCmdLineVisitor::MDProcessCmdLineVisitor() :
    MPL::BaseVisitor(),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>()
{
    return;
}

MDProcessCmdLineVisitor::MDProcessCmdLineVisitor( MDProcessCmdLineVisitor const & other) :
    MPL::BaseVisitor(other),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>(other)
{
    if (this != &other)
    {

    }
    return;
}

MDProcessCmdLineVisitor::MDProcessCmdLineVisitor( MDProcessCmdLineVisitor && other) :
    MPL::BaseVisitor(std::move(other)),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method MDProcessCmdLineVisitor::MDProcessCmdLineVisitor  -----


MDProcessCmdLineVisitor::~MDProcessCmdLineVisitor()
{
    return;
}

//============================= ACCESSORS ====================================
void MDProcessCmdLineVisitor::visit(AnansiMolecularDynamics& a_simulation) const
{
    a_simulation.saveCommandLineOptionParameters();

    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDProcessCmdLineVisitor& MDProcessCmdLineVisitor::operator= ( const MDProcessCmdLineVisitor &other )
{
    if (this != &other)
    {
        MPL::BaseVisitor::operator=(other);
        MPL::Visitor<ANANSI::AnansiMolecularDynamics>::operator=(other);
    }
    return *this;
} // assignment operator

MDProcessCmdLineVisitor& MDProcessCmdLineVisitor::operator= ( MDProcessCmdLineVisitor && other )
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
