//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ConcreteTaskTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ConcreteTaskTraits::ConcreteTaskTraits()
{
    return;
}

ConcreteTaskTraits::ConcreteTaskTraits( ConcreteTaskTraits const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

ConcreteTaskTraits::ConcreteTaskTraits( ConcreteTaskTraits && other)
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method ConcreteTaskTraits::ConcreteTaskTraits  -----


ConcreteTaskTraits::~ConcreteTaskTraits()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ConcreteTaskTraits& ConcreteTaskTraits::operator= ( const ConcreteTaskTraits &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

ConcreteTaskTraits& ConcreteTaskTraits::operator= ( ConcreteTaskTraits && other )
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
