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
    ownershipPolicy_(),
    results_(nullptr)
{
    this->results_ = std::make_unique<ControlFileXMLReceiver::receiver_result_t>(0);
    return;
}

ControlFileXMLReceiver::ControlFileXMLReceiver( ControlFileXMLReceiver && other) :
    RECEIVER::ReceiverInterface<ControlFileXMLReceiver>(std::move(other)),
    ownershipPolicy_(std::move(other.ownershipPolicy_)),
    results_(std::move(other.results_))
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

ControlFileXMLReceiver::OwnershipPolicy<ControlFileXMLReceiver::receiver_result_t>::Transfertype ControlFileXMLReceiver::receiverTransferOwnershipOfResults()
{
    OwnershipPolicy<ControlFileXMLReceiver::receiver_result_t>::Transfertype my_ptr = 
        ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

//============================= OPERATORS ====================================

ControlFileXMLReceiver& ControlFileXMLReceiver::operator= ( ControlFileXMLReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileXMLReceiver>::operator=(std::move(other));
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

ControlFileXMLReceiver::OwnershipPolicy<ControlFileXMLReceiver::receiver_result_t>::Copytype ControlFileXMLReceiver::receiverGetCopyOfResults_() const
{
    OwnershipPolicy<ControlFileXMLReceiver::receiver_result_t>::Copytype  my_ptr = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}


//============================= MUTATORS =====================================

ControlFileXMLReceiver::OwnershipPolicy<ControlFileXMLReceiver::receiver_result_t>::Sharedtype ControlFileXMLReceiver::receiverShareOwnershipOfResults_()
{
    OwnershipPolicy<receiver_result_t>::Sharedtype my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
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
