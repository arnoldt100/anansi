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
#include "InitWorldCommunicatorTaskReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//============================= LIFECYCLE ====================================

InitWorldCommunicatorTaskReceiver::InitWorldCommunicatorTaskReceiver() :
    RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>(),
    ownershipPolicy_(),
    results_(nullptr)
{
    return;
}

InitWorldCommunicatorTaskReceiver::InitWorldCommunicatorTaskReceiver( InitWorldCommunicatorTaskReceiver && other) :
    RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>(std::move(other)),
    ownershipPolicy_(std::move(other.ownershipPolicy_)),
    results_(std::move(other.results_))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method InitWorldCommunicatorTaskReceiver::InitWorldCommunicatorTaskReceiver  -----


InitWorldCommunicatorTaskReceiver::~InitWorldCommunicatorTaskReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

InitWorldCommunicatorTaskReceiver& InitWorldCommunicatorTaskReceiver::operator= ( InitWorldCommunicatorTaskReceiver && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::operator=(std::move(other));
        this->ownershipPolicy_ = std::move(other.ownershipPolicy_);
        this->results_ = std::move(other.results_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

InitWorldCommunicatorTaskReceiver::receiver_copy_t ::TYPE InitWorldCommunicatorTaskReceiver::receiverGetCopyOfResults_() const
{
    InitWorldCommunicatorTaskReceiver::receiver_copy_t  my_ptr = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

template<>
void InitWorldCommunicatorTaskReceiver::receiverModifyMyself_(std::unique_ptr<COMMUNICATOR::Communicator> & arg) 
{
    (this->results_) = std::move(arg);
    return;
}

InitWorldCommunicatorTaskReceiver::receiver_share_t InitWorldCommunicatorTaskReceiver::receiverShareOwnershipOfResults_()
{
    InitWorldCommunicatorTaskReceiver::receiver_share_t my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

InitWorldCommunicatorTaskReceiver::receiver_transfer_t InitWorldCommunicatorTaskReceiver::receiverTransferOwnershipOfResults_()
{
    InitWorldCommunicatorTaskReceiver::receiver_transfer_t my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
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
