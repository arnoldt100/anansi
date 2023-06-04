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
#include "ControlFileTask.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileTask::ControlFileTask() :
    AnansiTask()
{
    return;
}

ControlFileTask::ControlFileTask( ControlFileTask const & other) :
    AnansiTask(other)
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileTask::ControlFileTask( ControlFileTask && other) :
    AnansiTask(std::move(other))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method ControlFileTask::ControlFileTask  -----


ControlFileTask::~ControlFileTask()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileTask& ControlFileTask::operator= ( const ControlFileTask &other )
{
    if (this != &other)
    {
        AnansiTask::operator=(other);
    }
    return *this;
} // assignment operator

ControlFileTask& ControlFileTask::operator= ( ControlFileTask && other )
{
    if (this != &other)
    {
        AnansiTask::operator=(std::move(other));
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