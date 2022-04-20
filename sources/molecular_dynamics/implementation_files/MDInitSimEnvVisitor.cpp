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
#include "MDInitSimEnvVisitor.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDInitSimEnvVisitor::MDInitSimEnvVisitor()
{
    return;
}

MDInitSimEnvVisitor::MDInitSimEnvVisitor( MDInitSimEnvVisitor const & other)
{
    return;
}

MDInitSimEnvVisitor::MDInitSimEnvVisitor( MDInitSimEnvVisitor && other)
{
    return;
}		// -----  end of method MDInitSimEnvVisitor::MDInitSimEnvVisitor  -----


MDInitSimEnvVisitor::~MDInitSimEnvVisitor()
{
    return;
}

//============================= ACCESSORS ====================================
void MDInitSimEnvVisitor::visit(AnansiMolecularDynamics& a_sim) const
{
    std::cout << "Visit(AnansiMolecularDynamics&)" << std::endl;

    // Initializing the MPI environment.
    a_sim.initializeMpiEnvironment();

    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDInitSimEnvVisitor& MDInitSimEnvVisitor::operator= ( const MDInitSimEnvVisitor &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

MDInitSimEnvVisitor& MDInitSimEnvVisitor::operator= ( MDInitSimEnvVisitor && other )
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
