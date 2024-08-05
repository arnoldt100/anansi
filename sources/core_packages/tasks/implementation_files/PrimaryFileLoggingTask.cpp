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
#include "PrimaryFileLoggingTask.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

PrimaryFileLoggingTask::PrimaryFileLoggingTask() :
    AnansiTask()
{
    return;
}

PrimaryFileLoggingTask::PrimaryFileLoggingTask( PrimaryFileLoggingTask const & other) :
    AnansiTask(other)
{
    if (this != &other)
    {
        
    }
    return;
}

PrimaryFileLoggingTask::PrimaryFileLoggingTask( PrimaryFileLoggingTask && other) :
    AnansiTask(std::move(other))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method PrimaryFileLoggingTask::PrimaryFileLoggingTask  -----


PrimaryFileLoggingTask::~PrimaryFileLoggingTask()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

PrimaryFileLoggingTask& PrimaryFileLoggingTask::operator= ( const PrimaryFileLoggingTask &other )
{
    if (this != &other)
    {
        AnansiTask::operator=(other);
    }
    return *this;
} // assignment operator

PrimaryFileLoggingTask& PrimaryFileLoggingTask::operator= ( PrimaryFileLoggingTask && other )
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
