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
#include "WriteTextToConsoleTaskReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

WriteTextToConsoleTaskReceiver::WriteTextToConsoleTaskReceiver() :
    RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>(),
    results_(nullptr),
    ownershipPolicy_(),
    communicator_(nullptr),
    messageContainer_()
{
    this->results_ = std::make_unique<receiver_result_t>(0);
    return;
}

WriteTextToConsoleTaskReceiver::WriteTextToConsoleTaskReceiver( WriteTextToConsoleTaskReceiver && other) : 
    RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>(std::move(other)),
    results_(std::move(other.results_)),
    ownershipPolicy_(),
    communicator_(std::move(other.communicator_)),
    messageContainer_(std::move(other.messageContainer_))
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method WriteTextToConsoleTaskReceiver::WriteTextToConsoleTaskReceiver  -----


WriteTextToConsoleTaskReceiver::~WriteTextToConsoleTaskReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

WriteTextToConsoleTaskReceiver::OwnershipPolicy<WriteTextToConsoleTaskReceiver::receiver_result_t>::Transfertype WriteTextToConsoleTaskReceiver::receiverTransferOwnershipOfResults()
{
    OwnershipPolicy<receiver_result_t>::Transfertype my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

//============================= OPERATORS ====================================

WriteTextToConsoleTaskReceiver& WriteTextToConsoleTaskReceiver::operator=( WriteTextToConsoleTaskReceiver && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::operator=(std::move(other));
        this->results_ = std::move(other.results_);
        this->ownershipPolicy_ = std::move(other.ownershipPolicy_);
        this->communicator_ = std::move(other.communicator_);
        this->messageContainer_ = std::move(other.messageContainer_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

WriteTextToConsoleTaskReceiver::OwnershipPolicy<WriteTextToConsoleTaskReceiver::receiver_result_t>::Copytype WriteTextToConsoleTaskReceiver::receiverGetCopyOfResults_() const
{
    OwnershipPolicy<WriteTextToConsoleTaskReceiver::receiver_result_t>::Copytype  my_ptr = 
        this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}
//============================= MUTATORS =====================================

WriteTextToConsoleTaskReceiver::OwnershipPolicy<WriteTextToConsoleTaskReceiver::receiver_result_t>::Sharedtype WriteTextToConsoleTaskReceiver::receiverShareOwnershipOfResults_()
{
    OwnershipPolicy<receiver_result_t>::Sharedtype my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

template<>
void WriteTextToConsoleTaskReceiver::receiverModifyMyself_(
        std::unique_ptr<ConsoleMessageContainer> & message_container)
{
    this->messageContainer_ = std::move(message_container);
    return;
}


template<>
void WriteTextToConsoleTaskReceiver::receiverModifyMyself_(std::unique_ptr<COMMUNICATOR::Communicator> & arg)
{
    this->communicator_ = std::move(arg);
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
