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
    enabledStatus_{false},
    results_(ReadControlFileResultsTraits::ControlInputFile_t()),
    componentTasks_{},
    ownershipPolicy_()
{
    return;
}

ControlFileMacroReceiver::ControlFileMacroReceiver( ControlFileMacroReceiver && other) :
    ReceiverInterface<ControlFileMacroReceiver>(std::move(other)),
    enabledStatus_{std::move(other.enabledStatus_)},
    results_(std::move(other.results_)),
    componentTasks_{std::move(other.componentTasks_)},
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
        this->enabledStatus_ = std::move(other.enabledStatus_);
        this->results_ = std::move(other.results_);
        this->componentTasks_ = std::move(other.componentTasks_);
        this->ownershipPolicy_ = std::move(other.ownershipPolicy_);
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

bool ControlFileMacroReceiver::ifEnabled_ () const
{
    return this->enabledStatus_;
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
void ControlFileMacroReceiver::receiverModifyMyself_(CommandFiles<> & arg)
{
    this->results_ = arg;
    return;
}

template<>
void ControlFileMacroReceiver::receiverModifyMyself_<std::shared_ptr<ANANSI::AnansiTask>>(std::shared_ptr<ANANSI::AnansiTask> & a_task)
{
    const auto task_label= a_task->taskLabel();
    this->componentTasks_[task_label] = a_task;
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
