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
#include "LoggingTask.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

LoggingTask::LoggingTask() :
    AnansiTask()
{
    return;
}

LoggingTask::LoggingTask( LoggingTask const & other) :
    AnansiTask(other)
{
    if (this != &other)
    {
        
    }
    return;
}

LoggingTask::LoggingTask( LoggingTask && other) :
    AnansiTask(std::move(other))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method LoggingTask::LoggingTask  -----


LoggingTask::~LoggingTask()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

LoggingTask& LoggingTask::operator= ( const LoggingTask &other )
{
    if (this != &other)
    {
        AnansiTask::operator=(other);
    }
    return *this;
} // assignment operator

LoggingTask& LoggingTask::operator= ( LoggingTask && other )
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
