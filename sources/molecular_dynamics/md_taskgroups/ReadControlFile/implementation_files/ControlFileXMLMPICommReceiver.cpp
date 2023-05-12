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
    results_(0)
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

ControlFileXMLMPICommReceiver::receiver_copy_t ControlFileXMLMPICommReceiver::receiverGetCopyOfResults_() const
{
    ControlFileXMLMPICommReceiver::receiver_copy_t my_ptr = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

template<>
void ControlFileXMLMPICommReceiver::receiverModifyMyself_(int & arg)
{
    this->results_ = arg;
    return;
}

ControlFileXMLMPICommReceiver::receiver_share_t ControlFileXMLMPICommReceiver::receiverShareOwnershipOfResults_()
{
    ControlFileXMLMPICommReceiver::receiver_share_t my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

ControlFileXMLMPICommReceiver::receiver_transfer_t ControlFileXMLMPICommReceiver::receiverTransferOwnershipOfResults_()
{
    ControlFileXMLMPICommReceiver::receiver_transfer_t my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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
