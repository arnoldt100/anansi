//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPICommunicatorTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPICommunicatorTraits::MPICommunicatorTraits()
{
    return;
}

MPICommunicatorTraits::MPICommunicatorTraits( MPICommunicatorTraits const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

MPICommunicatorTraits::MPICommunicatorTraits( MPICommunicatorTraits && other)
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method MPICommunicatorTraits::MPICommunicatorTraits  -----


MPICommunicatorTraits::~MPICommunicatorTraits()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MPICommunicatorTraits& MPICommunicatorTraits::operator= ( const MPICommunicatorTraits &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

MPICommunicatorTraits& MPICommunicatorTraits::operator= ( MPICommunicatorTraits && other )
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
