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
#include "ControlFileXMLMPICommReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileXMLMPICommReceiver::ControlFileXMLMPICommReceiver() :
    ReceiverInterface<ControlFileXMLMPICommReceiver>(),
    communicator_(),
    ownershipPolicy_()
{
    return;
}

ControlFileXMLMPICommReceiver::ControlFileXMLMPICommReceiver( ControlFileXMLMPICommReceiver && other) :
    ReceiverInterface<ControlFileXMLMPICommReceiver>(std::move(other)),
    results_(std::move(other.results_)),
    communicator_(std::move(other.communicator_)),
    ownershipPolicy_(std::move(other.ownershipPolicy_))
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileXMLMPICommReceiver::~ControlFileXMLMPICommReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileXMLMPICommReceiver& ControlFileXMLMPICommReceiver::operator= ( ControlFileXMLMPICommReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileXMLMPICommReceiver>::operator=(std::move(other));
        this->results_ = std::move(other.results_);
        this->communicator_ = std::move(other.communicator_);
        this->ownershipPolicy_ = std::move(other.ownershipPolicy_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

ControlFileXMLMPICommReceiver::receiver_copy_t_ ControlFileXMLMPICommReceiver::receiverGetCopyOfResults_() const
{
    ControlFileXMLMPICommReceiver::receiver_copy_t_ my_copied_result = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_copied_result;
}

//============================= MUTATORS =====================================

template<>
void ControlFileXMLMPICommReceiver::receiverModifyMyself_(CommandFiles & arg)
{
    this->results_ = arg;
    return;
}

template<>
void ControlFileXMLMPICommReceiver::receiverModifyMyself_(std::unique_ptr<COMMUNICATOR::Communicator> & arg)
{
    this->communicator_ = std::move(arg);
    return;
}
ControlFileXMLMPICommReceiver::receiver_share_t_ ControlFileXMLMPICommReceiver::receiverShareOwnershipOfResults_()
{
    ControlFileXMLMPICommReceiver::receiver_share_t_ my_shared_result = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_shared_result;   
}

ControlFileXMLMPICommReceiver::receiver_transfer_t_ ControlFileXMLMPICommReceiver::receiverTransferOwnershipOfResults_()
{
    ControlFileXMLMPICommReceiver::receiver_transfer_t_ my_tranfered_result = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
    return my_tranfered_result;   
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
