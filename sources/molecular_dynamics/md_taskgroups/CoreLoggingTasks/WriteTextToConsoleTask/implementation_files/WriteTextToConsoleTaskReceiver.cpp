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
    communicator_(nullptr),
    messageContainer_(),
    results_(nullptr)
{
    this->results_ = std::make_unique<receiver_result_t>(0);
    return;
}

WriteTextToConsoleTaskReceiver::WriteTextToConsoleTaskReceiver( WriteTextToConsoleTaskReceiver && other) : 
    RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>(std::move(other)),
    communicator_(std::move(other.communicator_)),
    messageContainer_(std::move(other.messageContainer_)),
    results_(std::move(other.results_))
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

std::unique_ptr<WriteTextToConsoleTaskReceiver::receiver_result_t> WriteTextToConsoleTaskReceiver::receiverGetCopyOfResults() const
{
    std::unique_ptr<WriteTextToConsoleTaskReceiver::receiver_result_t> my_ptr =
        std::make_unique<WriteTextToConsoleTaskReceiver::receiver_result_t>(*(this->results_));
    return my_ptr;
}

//============================= MUTATORS =====================================

template<>
void WriteTextToConsoleTaskReceiver::receiverModifyMyself(
        std::unique_ptr<ConsoleMessageContainer> & message_container)
{
    this->messageContainer_ = std::move(message_container);
    return;
}

template<>
void WriteTextToConsoleTaskReceiver::receiverModifyMyself(std::unique_ptr<COMMUNICATOR::Communicator> & arg)
{
    this->communicator_ = std::move(arg);
    return;
}

//============================= OPERATORS ====================================

WriteTextToConsoleTaskReceiver& WriteTextToConsoleTaskReceiver::operator=( WriteTextToConsoleTaskReceiver && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::operator=(std::move(other));
        this->communicator_ = std::move(other.communicator_);
        this->messageContainer_ = std::move(other.messageContainer_);
        this->results_ = std::move(other.results_);
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
