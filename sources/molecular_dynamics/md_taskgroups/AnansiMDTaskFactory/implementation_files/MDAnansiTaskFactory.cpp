//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MDAnansiTaskFactory.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDAnansiTaskFactory::MDAnansiTaskFactory() : 
    mdAnansiTaskFactory_(std::make_unique<concrete_factory_>())

{
    return;
}

MDAnansiTaskFactory::MDAnansiTaskFactory( MDAnansiTaskFactory const & other) :
    mdAnansiTaskFactory_(std::make_unique<concrete_factory_>())
{
    if (this != &other)
    {
        
    }
    return;
}

MDAnansiTaskFactory::MDAnansiTaskFactory( MDAnansiTaskFactory && other)
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method MDAnansiTaskFactory::MDAnansiTaskFactory  -----


MDAnansiTaskFactory::~MDAnansiTaskFactory()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDAnansiTaskFactory& MDAnansiTaskFactory::operator= ( const MDAnansiTaskFactory &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

MDAnansiTaskFactory& MDAnansiTaskFactory::operator= ( MDAnansiTaskFactory && other )
{
    if (this != &other)
    {
        mdAnansiTaskFactory_ = std::move(other.mdAnansiTaskFactory_);
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