//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskStatus.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

TaskStatus::TaskStatus() : 
    taskDescription_(TaskStatus::defaultDescription_)
{
    return;
}

TaskStatus::TaskStatus( TaskStatus const & other)
{
    this->taskDescription_ = other.taskDescription_;
    return;
}		// -----  end of method TaskStatus::TaskStatus  -----

TaskStatus::TaskStatus( TaskStatus && other)
{
    this->taskDescription_ = std::move(other.taskDescription_);
    other.taskDescription_ = TaskStatus::defaultDescription_;
    return;
}		// -----  end of method TaskStatus::TaskStatus  -----


TaskStatus::~TaskStatus()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

TaskStatus& TaskStatus::operator= ( const TaskStatus &other )
{
    if (this != &other)
    {
        this->taskDescription_ = other.taskDescription_;
    }
    return *this;
} // assignment operator

TaskStatus& TaskStatus::operator= ( TaskStatus && other )
{
    if (this != &other)
    {
        this->taskDescription_ = std::move(other.taskDescription_);
        other.taskDescription_ = TaskStatus::defaultDescription_;
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


} // namespace COMMUNICATOR
