//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MDInitInitialConditionsVisitor.h"
#include "SimulationDecompositionParameters.h"
#include "GenericErrorClass.hpp"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDInitInitialConditionsVisitor::MDInitInitialConditionsVisitor() :
    MPL::BaseVisitor(),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>()
{
    return;
}

MDInitInitialConditionsVisitor::MDInitInitialConditionsVisitor( MDInitInitialConditionsVisitor const & other) :
    MPL::BaseVisitor(other),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>(other)
{
    if (this != &other)
    {

    }
    return;
}

MDInitInitialConditionsVisitor::MDInitInitialConditionsVisitor( MDInitInitialConditionsVisitor && other) :
    MPL::BaseVisitor(std::move(other)),
    MPL::Visitor<ANANSI::AnansiMolecularDynamics>(std::move(other))
{
    return;
    if (this != &other)
    {

    }
}		// -----  end of method MDInitInitialConditionsVisitor::MDInitInitialConditionsVisitor  -----


MDInitInitialConditionsVisitor::~MDInitInitialConditionsVisitor()
{
    return;
}

//============================= ACCESSORS ====================================
void MDInitInitialConditionsVisitor::visit(AnansiMolecularDynamics& a_sim) const
{
    std::cout << "MDInitInitialConditionsVisitor::visit(AnansiMolecularDynamics& a_sim)" << std::endl;

    // ---------------------------------------------------
    // The first step is to enable the simulation decomposition.
    // ---------------------------------------------------
    try 
    {
        a_sim.enableSimulationDecomposition();
    }
    catch (const MOUSEION::GenericErrorClass<SimulationDecompositionParameters> & my_error) 
    {
    	std::string message{my_error.what()};
        throw MOUSEION::GenericErrorClass<AnansiMolecularDynamics>(message);
    }

    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDInitInitialConditionsVisitor& MDInitInitialConditionsVisitor::operator= ( const MDInitInitialConditionsVisitor &other )
{
    if (this != &other)
    {
        MPL::BaseVisitor::operator=(other);
        MPL::Visitor<ANANSI::AnansiMolecularDynamics>::operator=(other);
    }
    return *this;
} // assignment operator

MDInitInitialConditionsVisitor& MDInitInitialConditionsVisitor::operator= ( MDInitInitialConditionsVisitor && other )
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
