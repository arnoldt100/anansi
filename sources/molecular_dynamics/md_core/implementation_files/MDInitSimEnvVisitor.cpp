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
    if (this != &other)
    {

    }
    return;
}

MDInitSimEnvVisitor::MDInitSimEnvVisitor( MDInitSimEnvVisitor && other)
{
    if (this != &other)
    {

    }
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

    // ---------------------------------------------------
    // The comunication environment must be first enabled for many other tasks
    // are dependent on the communication environment.  
    // ---------------------------------------------------
    a_sim.enableCommunicationEnvironment();
    
    // ---------------------------------------------------
    // The world communicator task object is now enabled.
    // ---------------------------------------------------
    a_sim.enableWorldCommunicator();

    // ---------------------------------------------------
    // The core logging tasks are enabled.
    // 
    // ---------------------------------------------------
    a_sim.enableCoreLoggingTasks();

    // ---------------------------------------------------
    // The read control file invoker is enabaled.
    // ---------------------------------------------------
    a_sim.enableControlFile();

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
