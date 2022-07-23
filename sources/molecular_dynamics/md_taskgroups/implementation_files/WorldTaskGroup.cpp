//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "WorldTaskGroup.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

WorldTaskGroup::WorldTaskGroup() :
    TaskGroup(),
    commandLineArguments_(),
    worldCommunicator_(nullptr) 
{
    return;
}


WorldTaskGroup::WorldTaskGroup( WorldTaskGroup && other) :
    TaskGroup(std::move(other)),
    commandLineArguments_(),
    worldCommunicator_(nullptr) 
{
    if (this != &other)
    {
        *this = std::move(other);
    }
    return;
}		// -----  end of method WorldTaskGroup::WorldTaskGroup  -----


WorldTaskGroup::~WorldTaskGroup()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

template <>
void WorldTaskGroup::addIngredient(WorldCommunicatorIngredientTraits::type && ingredient)
{
    this->worldCommunicator_ = std::move(ingredient);
    return;
}

template <>
void WorldTaskGroup::addIngredient(CommandLineArgumentsIngredientTraits::type && ingredient)
{
    this->commandLineArguments_ = std::move(ingredient);
    return;
}
//============================= OPERATORS ====================================

WorldTaskGroup& WorldTaskGroup::operator= ( WorldTaskGroup && other )
{
    if (this != &other)
    {
        TaskGroup::operator=(std::move(other));
        this->commandLineArguments_ = std::move(other.commandLineArguments_);
        this->worldCommunicator_ = std::move(other.worldCommunicator_);
    }
    return *this;
} // assignment-move operator

//============================= STATIC METHODS ===============================
TaskGroup* WorldTaskGroup::create()
{
    return new WorldTaskGroup;
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
template <typename IngredientType>
void obtainIngredient_( )
{
    return;
}


void WorldTaskGroup::enable_()
{
    return;
}

//============================= OPERATORS ====================================


} // namespace ANANSI
