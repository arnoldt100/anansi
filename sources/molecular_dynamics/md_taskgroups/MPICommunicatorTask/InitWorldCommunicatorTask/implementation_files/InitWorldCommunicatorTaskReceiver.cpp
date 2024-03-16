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
    enabledStatus_{false},
    results_(nullptr),
    ownershipPolicy_()
{
    return;
}

InitWorldCommunicatorTaskReceiver::InitWorldCommunicatorTaskReceiver( InitWorldCommunicatorTaskReceiver && other) :
    RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>(std::move(other)),
    enabledStatus_{std::move(other.enabledStatus_)},
    results_(std::move(other.results_)),
    ownershipPolicy_(std::move(other.ownershipPolicy_))
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
        this->enabledStatus_ = std::move(other.enabledStatus_);
        this->results_ = std::move(other.results_);
        this->ownershipPolicy_ = std::move(other.ownershipPolicy_);

    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

InitWorldCommunicatorTaskReceiver::receiver_copy_t_ InitWorldCommunicatorTaskReceiver::receiverGetCopyOfResults_() const
{
    InitWorldCommunicatorTaskReceiver::receiver_copy_t_  my_copied_result = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_copied_result;
}

bool InitWorldCommunicatorTaskReceiver::ifEnabled_ () const
{
    return this->enabledStatus_;
}

//============================= MUTATORS =====================================

template<>
void InitWorldCommunicatorTaskReceiver::receiverModifyMyself_(std::unique_ptr<COMMUNICATOR::Communicator> & arg) 
{
    (this->results_) = std::move(arg);
    return;
}

InitWorldCommunicatorTaskReceiver::receiver_share_t_ InitWorldCommunicatorTaskReceiver::receiverShareOwnershipOfResults_()
{
    InitWorldCommunicatorTaskReceiver::receiver_share_t_ my_shared_result = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_shared_result;   
}

InitWorldCommunicatorTaskReceiver::receiver_transfer_t_ InitWorldCommunicatorTaskReceiver::receiverTransferOwnershipOfResults_()
{
    InitWorldCommunicatorTaskReceiver::receiver_transfer_t_ my_transfer_result = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
    return my_transfer_result;   
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
