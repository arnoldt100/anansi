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
#include "ControlFileCommunicator.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileCommunicator::ControlFileCommunicator() :
    AnansiTask()
{
    return;
}

ControlFileCommunicator::ControlFileCommunicator( ControlFileCommunicator const & other) :
    AnansiTask()
{
    if (this != &other)
    {
        AnansiTask::operator=(other); 
    }
    return;
}

ControlFileCommunicator::ControlFileCommunicator( ControlFileCommunicator && other) :
    AnansiTask(std::move(other))
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ControlFileCommunicator::ControlFileCommunicator  -----


ControlFileCommunicator::~ControlFileCommunicator()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileCommunicator& ControlFileCommunicator::operator= ( const ControlFileCommunicator &other )
{
    if (this != &other)
    {
        AnansiTask::operator=(other);   
    }
    return *this;
} // assignment operator

ControlFileCommunicator& ControlFileCommunicator::operator= ( ControlFileCommunicator && other )
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
