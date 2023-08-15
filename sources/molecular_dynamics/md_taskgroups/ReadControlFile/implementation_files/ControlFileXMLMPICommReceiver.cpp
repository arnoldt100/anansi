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
    ownershipPolicy_(),
    results_()
{
    return;
}

ControlFileXMLMPICommReceiver::ControlFileXMLMPICommReceiver( ControlFileXMLMPICommReceiver && other) :
    ReceiverInterface<ControlFileXMLMPICommReceiver>(std::move(other)),
    ownershipPolicy_(std::move(other.ownershipPolicy_)),
    results_(std::move(other.results_))
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

ControlFileXMLMPICommReceiver::receiver_copy_t_ ControlFileXMLMPICommReceiver::receiverGetCopyOfResults_() const
{
    ControlFileXMLMPICommReceiver::receiver_copy_t_ my_copied_result = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_copied_result;
}

//============================= MUTATORS =====================================

template<>
void ControlFileXMLMPICommReceiver::receiverModifyMyself_(ControlFile & arg)
{
    this->results_ = arg;
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
