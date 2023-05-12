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
    results_(0),
    communicator_(nullptr),
    messageContainer_(),
    ownershipPolicy_()
{
    return;
}

WriteTextToConsoleTaskReceiver::WriteTextToConsoleTaskReceiver( WriteTextToConsoleTaskReceiver && other) : 
    RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>(std::move(other)),
    results_(0),
    communicator_(std::move(other.communicator_)),
    messageContainer_(std::move(other.messageContainer_)),
    ownershipPolicy_()
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

WriteTextToConsoleTaskReceiver::receiver_copy_t WriteTextToConsoleTaskReceiver::receiverGetCopyOfResults_() const
{
    WriteTextToConsoleTaskReceiver::receiver_copy_t my_ptr =
        this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

WriteTextToConsoleTaskReceiver::receiver_share_t WriteTextToConsoleTaskReceiver::receiverShareOwnershipOfResults_()
{
    WriteTextToConsoleTaskReceiver::receiver_share_t my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

WriteTextToConsoleTaskReceiver::receiver_transfer_t WriteTextToConsoleTaskReceiver::receiverTransferOwnershipOfResults_()
{
    WriteTextToConsoleTaskReceiver::receiver_transfer_t my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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
