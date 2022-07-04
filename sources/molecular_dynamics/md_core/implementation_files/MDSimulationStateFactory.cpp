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

MDSimulationStateFactory::MDSimulationStateFactory() :
    mdSimStateFactory_(std::make_unique<concrete_factory_>())
{
    return;
}

MDSimulationStateFactory::MDSimulationStateFactory( MDSimulationStateFactory const & other) :
    mdSimStateFactory_(std::make_unique<concrete_factory_>())
{
    return;
}		// -----  end of method MDSimulationStateFactory::MDSimulationStateFactory  -----

MDSimulationStateFactory::MDSimulationStateFactory( MDSimulationStateFactory && other) :
    mdSimStateFactory_(std::move(mdSimStateFactory_))
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

MDSimulationStateFactory& MDSimulationStateFactory::operator= ( MDSimulationStateFactory const & other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment-move operator

MDSimulationStateFactory& MDSimulationStateFactory::operator= ( MDSimulationStateFactory && other )
{
    if (this != &other)
    {
        mdSimStateFactory_ = std::move(other.mdSimStateFactory_);
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
