//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "DefaultTaskGroup.h"
#include "TaskGroupFactory.h"

namespace ANANSI
{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

TaskGroupFactory::TaskGroupFactory() :
    COUNTERCLASSES::ClassInstanceLimiter<TaskGroupFactory,MAX_TASKGROUPFACTORY_INSTANCES>()
{
    // Register all TaskGroups.
    const int defaulttaskgroupid=1; // ID
    myFactory_.registerFactory(defaulttaskgroupid,DefaultTaskGroup::createTaskGroup);

    return;
}


TaskGroupFactory::~TaskGroupFactory()
{
    return;
}

//============================= ACCESSORS ====================================
std::unique_ptr<ANANSI::TaskGroup> TaskGroupFactory::buildWorldTaskGroup() const
{
    std::unique_ptr<TaskGroup> task_group = std::move(std::make_unique<DefaultTaskGroup>() );
    return task_group;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

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
