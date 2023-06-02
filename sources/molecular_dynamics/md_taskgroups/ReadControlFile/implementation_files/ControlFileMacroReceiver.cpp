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
#include "ControlFileMacroReceiver.h"


namespace ANANSI {

class AnansiTask;

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileMacroReceiver::ControlFileMacroReceiver() :
    ReceiverInterface<ControlFileMacroReceiver>(),
    results_(0),
    ownershipPolicy_()
{
    return;
}

ControlFileMacroReceiver::ControlFileMacroReceiver( ControlFileMacroReceiver && other) :
    ReceiverInterface<ControlFileMacroReceiver>(std::move(other)),
    results_(std::move(other.results_)),
    ownershipPolicy_(std::move(other.ownershipPolicy_))
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileMacroReceiver::~ControlFileMacroReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileMacroReceiver& ControlFileMacroReceiver::operator= ( ControlFileMacroReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileMacroReceiver>::operator=(std::move(other));
        this->results_ = std::move(other.results_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

ControlFileMacroReceiver::receiver_copy_t_ ControlFileMacroReceiver::receiverGetCopyOfResults_() const
{
    ControlFileMacroReceiver::receiver_copy_t_ my_ptr = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

ControlFileMacroReceiver::receiver_transfer_t_ ControlFileMacroReceiver::receiverTransferOwnershipOfResults_()
{
    ControlFileMacroReceiver::receiver_transfer_t_ my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

ControlFileMacroReceiver::receiver_share_t_ ControlFileMacroReceiver::receiverShareOwnershipOfResults_()
{
    ControlFileMacroReceiver::receiver_share_t_ my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

template<>
void ControlFileMacroReceiver::receiverModifyMyself_(int & alpha)
{
    return;
}

template<>
void ControlFileMacroReceiver::receiverModifyMyself_<std::shared_ptr<ANANSI::AnansiTask>>(std::shared_ptr<ANANSI::AnansiTask> & a_task)
{
    const auto task_label= a_task->taskLabel();
    this->compenentTasks_[task_label] = a_task;
    return;
}

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
