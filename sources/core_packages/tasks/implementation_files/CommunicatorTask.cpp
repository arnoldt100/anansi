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
#include "CommunicatorTask.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommunicatorTask::CommunicatorTask() :
    AnansiTask()
{
    return;
}

CommunicatorTask::CommunicatorTask( CommunicatorTask const & other) :
    AnansiTask(other)
{
    if (this != &other)
    {
        
    }
    return;
}

CommunicatorTask::CommunicatorTask( CommunicatorTask && other) :
    AnansiTask(std::move(other))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method CommunicatorTask::CommunicatorTask  -----


CommunicatorTask::~CommunicatorTask()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CommunicatorTask& CommunicatorTask::operator= ( const CommunicatorTask &other )
{
    if (this != &other)
    {
        AnansiTask::operator=(other);
    }
    return *this;
} // assignment operator

CommunicatorTask& CommunicatorTask::operator= ( CommunicatorTask && other )
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