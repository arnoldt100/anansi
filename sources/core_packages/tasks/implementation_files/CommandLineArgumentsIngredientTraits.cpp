//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandLineArgumentsIngredientTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommandLineArgumentsIngredientTraits::CommandLineArgumentsIngredientTraits()
{
    return;
}

CommandLineArgumentsIngredientTraits::CommandLineArgumentsIngredientTraits( CommandLineArgumentsIngredientTraits const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

CommandLineArgumentsIngredientTraits::CommandLineArgumentsIngredientTraits( CommandLineArgumentsIngredientTraits && other)
{
    if (this != &other)
    {
        *this = std::move(other); 
    }
    return;
}       // -----  end of method CommandLineArgumentsIngredientTraits::CommandLineArgumentsIngredientTraits  -----


CommandLineArgumentsIngredientTraits::~CommandLineArgumentsIngredientTraits()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CommandLineArgumentsIngredientTraits& CommandLineArgumentsIngredientTraits::operator= ( const CommandLineArgumentsIngredientTraits &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

CommandLineArgumentsIngredientTraits& CommandLineArgumentsIngredientTraits::operator=( CommandLineArgumentsIngredientTraits && other )
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
