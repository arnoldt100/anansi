//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MDSimulationStateFactory.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDSimulationStateFactory::MDSimulationStateFactory()
{
    return;
}

MDSimulationStateFactory::MDSimulationStateFactory( MDSimulationStateFactory const & other)
{
    return;
}

MDSimulationStateFactory::MDSimulationStateFactory( MDSimulationStateFactory && other)
{
    return;
}		// -----  end of method MDSimulationStateFactory::MDSimulationStateFactory  -----


MDSimulationStateFactory::~MDSimulationStateFactory()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDSimulationStateFactory& MDSimulationStateFactory::operator= ( const MDSimulationStateFactory &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

MDSimulationStateFactory& MDSimulationStateFactory::operator= ( MDSimulationStateFactory && other )
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
