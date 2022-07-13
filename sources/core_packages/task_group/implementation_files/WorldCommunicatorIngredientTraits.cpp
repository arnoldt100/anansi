//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "WorldCommunicatorIngredientTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

WorldCommunicatorIngredientTraits::WorldCommunicatorIngredientTraits()
{
    return;
}

WorldCommunicatorIngredientTraits::WorldCommunicatorIngredientTraits( WorldCommunicatorIngredientTraits const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

WorldCommunicatorIngredientTraits::WorldCommunicatorIngredientTraits( WorldCommunicatorIngredientTraits && other)
{
    if (this != &other)
    {
        *this = std::move(other); 
    }
    return;
}       // -----  end of method WorldCommunicatorIngredientTraits::WorldCommunicatorIngredientTraits  -----


WorldCommunicatorIngredientTraits::~WorldCommunicatorIngredientTraits()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

WorldCommunicatorIngredientTraits& WorldCommunicatorIngredientTraits::operator= ( const WorldCommunicatorIngredientTraits &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

WorldCommunicatorIngredientTraits& WorldCommunicatorIngredientTraits::operator=( WorldCommunicatorIngredientTraits && other )
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
