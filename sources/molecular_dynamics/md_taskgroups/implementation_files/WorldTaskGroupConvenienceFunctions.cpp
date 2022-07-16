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
#include "WorldTaskGroupConvenienceFunctions.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

WorldTaskGroupConvenienceFunctions::WorldTaskGroupConvenienceFunctions() :
    TaskGroupConvenienceFunctions<WorldTaskGroupConvenienceFunctions>()
{
    return;
}

WorldTaskGroupConvenienceFunctions::WorldTaskGroupConvenienceFunctions( WorldTaskGroupConvenienceFunctions const & other)
{
    if (this != &other)
    {
       *this = other; 
    }
    return;
}

WorldTaskGroupConvenienceFunctions::WorldTaskGroupConvenienceFunctions( WorldTaskGroupConvenienceFunctions && other)
{
    if (this != &other)
    {
       *this = std::move(other); 
    }
    return;
}		// -----  end of method WorldTaskGroupConvenienceFunctions::WorldTaskGroupConvenienceFunctions  -----


WorldTaskGroupConvenienceFunctions::~WorldTaskGroupConvenienceFunctions()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

WorldTaskGroupConvenienceFunctions& WorldTaskGroupConvenienceFunctions::operator=( const WorldTaskGroupConvenienceFunctions &other )
{
    if (this != &other)
    {
        TaskGroupConvenienceFunctions<WorldTaskGroupConvenienceFunctions>::operator=(other);
    }
    return *this;
} // assignment operator

WorldTaskGroupConvenienceFunctions& WorldTaskGroupConvenienceFunctions::operator=( WorldTaskGroupConvenienceFunctions && other )
{
    if (this != &other)
    {
        TaskGroupConvenienceFunctions<WorldTaskGroupConvenienceFunctions>::operator=(std::move(other));
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
