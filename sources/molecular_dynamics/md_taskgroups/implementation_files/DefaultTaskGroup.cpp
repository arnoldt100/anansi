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
#include "DefaultTaskGroup.h"
#include "ConsoleLogger.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

DefaultTaskGroup::DefaultTaskGroup() :
   TaskGroup(), 
    communicator_(nullptr),
    consoleLogger_(nullptr) 
{
    return;
}


DefaultTaskGroup::DefaultTaskGroup( DefaultTaskGroup && other) :
    TaskGroup(std::move(other)),
    communicator_(nullptr), 
    consoleLogger_(nullptr) 
{
    if (this != &other)
    {
        *this = std::move(other);
    }
    return;
}		// -----  end of method DefaultTaskGroup::DefaultTaskGroup  -----


DefaultTaskGroup::~DefaultTaskGroup()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

template <>
void DefaultTaskGroup::addIngredient(CommunicatorIngredientTraits::type && ingredient)
{
    this->communicator_ = std::move(ingredient);
    return;
}

//============================= OPERATORS ====================================

DefaultTaskGroup& DefaultTaskGroup::operator= ( DefaultTaskGroup && other )
{
    if (this != &other)
    {
        TaskGroup::operator=(std::move(other));
        this->communicator_ = std::move(other.communicator_);
        this->consoleLogger_ = std::move(other.consoleLogger_);
    }
    return *this;
} // assignment-move operator

//============================= STATIC METHODS ===============================
TaskGroup* DefaultTaskGroup::create()
{
    return new DefaultTaskGroup;
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

void DefaultTaskGroup::enable_()
{
    // the first task is to enable the logger.
    this->consoleLogger_ = std::make_shared<ANANSI::ConsoleLogger>();
    this->consoleLogger_->logMessage("The DefaultTaskGroup console logger is enabled.");
    return;
}

void DefaultTaskGroup::disable_()
{
    this->consoleLogger_.reset();
    this->communicator_->freeCommunicator();
    return;
}
//============================= OPERATORS ====================================


} // namespace ANANSI
