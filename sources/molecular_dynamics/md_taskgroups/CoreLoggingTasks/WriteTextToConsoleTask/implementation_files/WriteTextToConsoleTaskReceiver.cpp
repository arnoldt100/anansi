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
    messageContainer_()
{
    return;
}


WriteTextToConsoleTaskReceiver::WriteTextToConsoleTaskReceiver( WriteTextToConsoleTaskReceiver && other) : 
    RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>(std::move(other)),
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

RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::TASK_LABEL_TYPE WriteTextToConsoleTaskReceiver::receiverGetTaskLabel() const
{
    return  WriteTextToConsoleTaskReceiver::TASKLABEL;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

WriteTextToConsoleTaskReceiver& WriteTextToConsoleTaskReceiver::operator=( WriteTextToConsoleTaskReceiver && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::operator=(std::move(other));
        this->communicator_ = std::move(other.communicator_);
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

template<>
void WriteTextToConsoleTaskReceiver::enableReceiver(std::unique_ptr<COMMUNICATOR::Communicator> & arg)
{
    this->communicator_ = std::move(arg);
    return;
}

//============================= OPERATORS ====================================


} // namespace ANANSI
