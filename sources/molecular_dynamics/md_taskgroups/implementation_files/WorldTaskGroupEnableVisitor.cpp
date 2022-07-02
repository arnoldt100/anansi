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

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

WorldTaskGroupEnableVisitor::WorldTaskGroupEnableVisitor() :
    ingredients_()
{
    return;
}

WorldTaskGroupEnableVisitor::WorldTaskGroupEnableVisitor (WorldTaskGroupIngredients & world_task_group_ingredients) :
    ingredients_(world_task_group_ingredients)
{
    return;
}

WorldTaskGroupEnableVisitor::WorldTaskGroupEnableVisitor( WorldTaskGroupEnableVisitor const & other)
{
    if (this != &other)
    {
        this->ingredients_ = other.ingredients_;
    }
    return;
}

WorldTaskGroupEnableVisitor::WorldTaskGroupEnableVisitor( WorldTaskGroupEnableVisitor && other)
{
    if (this != &other)
    {
        *this = std::move(other);
    }
    return;
}		// -----  end of method WorldTaskGroupEnableVisitor::WorldTaskGroupEnableVisitor  -----


WorldTaskGroupEnableVisitor::~WorldTaskGroupEnableVisitor()
{
    return;
}

//============================= ACCESSORS ====================================
void WorldTaskGroupEnableVisitor::visit(WorldTaskGroup & a_task_group) const
{
    a_task_group.addCommandLineArguments();
    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

WorldTaskGroupEnableVisitor& WorldTaskGroupEnableVisitor::operator= ( const WorldTaskGroupEnableVisitor &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

WorldTaskGroupEnableVisitor& WorldTaskGroupEnableVisitor::operator= ( WorldTaskGroupEnableVisitor && other )
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
