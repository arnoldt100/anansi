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

MDTerminateSimulationVisitor::MDTerminateSimulationVisitor() :
    MPL::BaseVisitor(),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>()
{
    return;
}

MDTerminateSimulationVisitor::MDTerminateSimulationVisitor( MDTerminateSimulationVisitor const & other) :
    MPL::BaseVisitor(other),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>(other)
{
    if (this != &other)
    {

    }
    return;
}

MDTerminateSimulationVisitor::MDTerminateSimulationVisitor( MDTerminateSimulationVisitor && other) :
    MPL::BaseVisitor(std::move(other)),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>(std::move(other))
{
    return;
    if (this != &other)
    {

    }
}		// -----  end of method MDTerminateSimulationVisitor::MDTerminateSimulationVisitor  -----


MDTerminateSimulationVisitor::~MDTerminateSimulationVisitor()
{
    return;
}

//============================= ACCESSORS ====================================
void MDTerminateSimulationVisitor::visit(AnansiMolecularDynamics& a_sim) const
{
    // ---------------------------------------------------
    // The control file invoker is disabled
    // 
    // ---------------------------------------------------
    a_sim.disableControlFileTasks();

    // ---------------------------------------------------
    // The core logging tasks are disabled.
    // 
    // ---------------------------------------------------
    a_sim.disableCoreLoggingTasks();

    // ---------------------------------------------------
    // The world communicator task object is now disabled.
    // ---------------------------------------------------
    a_sim.disableWorldCommunicator();
    
    // ---------------------------------------------------
    // The communication environment must be disabled last for many other tasks
    // are dependent on the communication environment.  
    // ---------------------------------------------------
    a_sim.disableCommunicationEnvironment();

    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDTerminateSimulationVisitor& MDTerminateSimulationVisitor::operator= ( const MDTerminateSimulationVisitor &other )
{
    if (this != &other)
    {
        MPL::BaseVisitor::operator=(other);
        MPL::Visitor<ANANSI::AnansiMolecularDynamics>::operator=(other);
    }
    return *this;
} // assignment operator

MDTerminateSimulationVisitor& MDTerminateSimulationVisitor::operator= ( MDTerminateSimulationVisitor && other )
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
