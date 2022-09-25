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
#include "DefaultTasksGroup.hpp"
#include "ConsoleLogger.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

DefaultTasksGroup::DefaultTasksGroup() :
    TasksGroup(), 
    communicator_(nullptr),
    consoleLogger_(nullptr) 
{
    return;
}


DefaultTasksGroup::DefaultTasksGroup( DefaultTasksGroup && other) :
    TasksGroup(std::move(other)),
    communicator_(nullptr), 
    consoleLogger_(nullptr) 
{
    if (this != &other)
    {
        *this = std::move(other);
    }
    return;
}		// -----  end of method DefaultTasksGroup::DefaultTasksGroup  -----


DefaultTasksGroup::~DefaultTasksGroup()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

DefaultTasksGroup& DefaultTasksGroup::operator= ( DefaultTasksGroup && other )
{
    if (this != &other)
    {
        TasksGroup::operator=(std::move(other));
        this->communicator_ = std::move(other.communicator_);
        this->consoleLogger_ = std::move(other.consoleLogger_);
    }
    return *this;
} // assignment-move operator

//============================= STATIC METHODS ===============================

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

void DefaultTasksGroup::enable_()
{
    // the first task is to enable the logger.
    this->consoleLogger_ = std::make_shared<ANANSI::ConsoleLogger>();
    this->consoleLogger_->logMessage("The DefaultTasksGroup console logger is enabled.");
    return;
}

void DefaultTasksGroup::disable_()
{
    this->consoleLogger_.reset();
    this->communicator_->freeCommunicator();
    return;
}

//============================= OPERATORS ====================================


} // namespace ANANSI
