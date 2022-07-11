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

WorldTaskGroupEnableVisitor::WorldTaskGroupEnableVisitor (const std::unique_ptr<ANANSI::WorldTaskGroupIngredients> & world_task_group_ingredients)
{
    std::unique_ptr<ANANSI::WorldTaskGroupIngredients> tmp_ingredients(world_task_group_ingredients->clone());
    this->ingredients_ = std::move(tmp_ingredients);
    return;
}

WorldTaskGroupEnableVisitor::WorldTaskGroupEnableVisitor( WorldTaskGroupEnableVisitor const & other)
{
    if (this != &other)
    {
        *this = other;
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
        std::unique_ptr<ANANSI::WorldTaskGroupIngredients> tmp_ingredients((*other.ingredients_).clone());
        this->ingredients_ = std::move(tmp_ingredients);
    }
    return *this;
} // assignment operator

WorldTaskGroupEnableVisitor& WorldTaskGroupEnableVisitor::operator= ( WorldTaskGroupEnableVisitor && other )
{
    if (this != &other)
    {
        this->ingredients_ = std::move(other.ingredients_);
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
