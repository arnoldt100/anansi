//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "WorldTaskGroupEnableVisitor.h"
#include "WorldTaskGroupConvenienceFunctions.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

WorldTaskGroupConvenienceFunctions::WorldTaskGroupConvenienceFunctions()
{
    return;
}

WorldTaskGroupConvenienceFunctions::WorldTaskGroupConvenienceFunctions( WorldTaskGroupConvenienceFunctions const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

WorldTaskGroupConvenienceFunctions::WorldTaskGroupConvenienceFunctions( WorldTaskGroupConvenienceFunctions && other)
{
    if (this != &other)
    {
        
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

WorldTaskGroupConvenienceFunctions& WorldTaskGroupConvenienceFunctions::operator= ( const WorldTaskGroupConvenienceFunctions &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

WorldTaskGroupConvenienceFunctions& WorldTaskGroupConvenienceFunctions::operator= ( WorldTaskGroupConvenienceFunctions && other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment-move operator

//============================= OPERATORS ====================================

void WorldTaskGroupConvenienceFunctions::enable(std::unique_ptr<ANANSI::TaskGroup> & world_task_group,
                                                const std::unique_ptr<WorldTaskGroupIngredients> & world_task_group_ingredients)
{
    return;
}

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
