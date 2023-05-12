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
#include "ControlFileXMLReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileXMLReceiver::ControlFileXMLReceiver() :
    RECEIVER::ReceiverInterface<ControlFileXMLReceiver>(),
    controlFileName_(),
    masterProcess_(),
    results_(0),
    ownershipPolicy_()
{
    return;
}

ControlFileXMLReceiver::ControlFileXMLReceiver( ControlFileXMLReceiver && other) :
    RECEIVER::ReceiverInterface<ControlFileXMLReceiver>(std::move(other)),
    controlFileName_(std::move(other.controlFileName_)),
    masterProcess_(std::move(other.masterProcess_)),
    results_(std::move(other.results_)),
    ownershipPolicy_(std::move(other.ownershipPolicy_))
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileXMLReceiver::~ControlFileXMLReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileXMLReceiver& ControlFileXMLReceiver::operator= ( ControlFileXMLReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileXMLReceiver>::operator=(std::move(other));
        this->controlFileName_ = std::move(other.controlFileName_);
        this->masterProcess_ = std::move(other.masterProcess_);
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

ControlFileXMLReceiver::receiver_copy_t ControlFileXMLReceiver::receiverGetCopyOfResults_() const
{
    ControlFileXMLReceiver::receiver_copy_t my_ptr = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

template<>
void ControlFileXMLReceiver::receiverModifyMyself_(int & arg)
{
    this->results_ = arg;
    return;
}

template<>
void ControlFileXMLReceiver::receiverModifyMyself_(ControlFileName & arg)
{
    this->controlFileName_ = arg;
    return;
}

template<>
void ControlFileXMLReceiver::receiverModifyMyself_(MasterProcess & arg)
{
    this->masterProcess_ = arg;
    return;
}

ControlFileXMLReceiver::receiver_share_t ControlFileXMLReceiver::receiverShareOwnershipOfResults_()
{
    ControlFileXMLReceiver::receiver_share_t my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

ControlFileXMLReceiver::receiver_transfer_t ControlFileXMLReceiver::receiverTransferOwnershipOfResults_()
{
    ControlFileXMLReceiver::receiver_transfer_t my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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
