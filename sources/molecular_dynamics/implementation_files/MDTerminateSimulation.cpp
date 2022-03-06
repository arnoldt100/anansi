//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MDTerminateSimulation.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDTerminateSimulation::MDTerminateSimulation() : 
    TerminateSimulation ()
{
    return;
}

MDTerminateSimulation::MDTerminateSimulation( MDTerminateSimulation const & other) :
    TerminateSimulation(other)
{
    return;
}

MDTerminateSimulation::MDTerminateSimulation( MDTerminateSimulation && other) :
    TerminateSimulation(std::move(other))
{
    return;
}		// -----  end of method MDTerminateSimulation::MDTerminateSimulation  -----


MDTerminateSimulation::~MDTerminateSimulation()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDTerminateSimulation& MDTerminateSimulation::operator= ( const MDTerminateSimulation &other )
{
    if (this != &other)
    {
        TerminateSimulation::operator=(other);
    }
    return *this;
} // assignment operator

MDTerminateSimulation& MDTerminateSimulation::operator= ( MDTerminateSimulation && other )
{
    if (this != &other)
    {
        TerminateSimulation::operator=(std::move(other));
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
