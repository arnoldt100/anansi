//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommunicatorIngredientTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommunicatorIngredientTraits::CommunicatorIngredientTraits()
{
    return;
}

CommunicatorIngredientTraits::CommunicatorIngredientTraits( CommunicatorIngredientTraits const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

CommunicatorIngredientTraits::CommunicatorIngredientTraits( CommunicatorIngredientTraits && other)
{
    if (this != &other)
    {
        *this = std::move(other); 
    }
    return;
}       // -----  end of method CommunicatorIngredientTraits::CommunicatorIngredientTraits  -----


CommunicatorIngredientTraits::~CommunicatorIngredientTraits()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CommunicatorIngredientTraits& CommunicatorIngredientTraits::operator= ( const CommunicatorIngredientTraits &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

CommunicatorIngredientTraits& CommunicatorIngredientTraits::operator=( CommunicatorIngredientTraits && other )
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
