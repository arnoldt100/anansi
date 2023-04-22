//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BaseOwnershipImplementation.h"

namespace RECEIVER {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

BaseOwnershipImplementation::BaseOwnershipImplementation()
{
    return;
}

BaseOwnershipImplementation::BaseOwnershipImplementation( BaseOwnershipImplementation const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

BaseOwnershipImplementation::BaseOwnershipImplementation( BaseOwnershipImplementation && other)
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method BaseOwnershipImplementation::BaseOwnershipImplementation  -----


BaseOwnershipImplementation::~BaseOwnershipImplementation()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

BaseOwnershipImplementation& BaseOwnershipImplementation::operator= ( const BaseOwnershipImplementation &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

BaseOwnershipImplementation& BaseOwnershipImplementation::operator= ( BaseOwnershipImplementation && other )
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


} // namespace RECEIVER
