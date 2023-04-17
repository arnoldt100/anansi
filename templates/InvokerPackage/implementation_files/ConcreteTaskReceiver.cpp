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
#include "ConcreteTaskReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ConcreteTaskReceiver::ConcreteTaskReceiver() :
    RECEIVER::ReceiverInterface<ConcreteTaskReceiver>(),
    ownershipPolicy_(),
    results_(nullptr),
    base_(0)
{
    this->results_ = std::make_unique<receiver_result_t>(0);
    return;
}

ConcreteTaskReceiver::ConcreteTaskReceiver( ConcreteTaskReceiver && other) : 
    RECEIVER::ReceiverInterface<ConcreteTaskReceiver>(std::move(other)),
    ownershipPolicy_(std::move(other.ownershipPolicy_)),
    results_(std::move(other.results_)),
    base_(std::move(base_))
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ConcreteTaskReceiver::ConcreteTaskReceiver  -----


ConcreteTaskReceiver::~ConcreteTaskReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

ConcreteTaskReceiver::OwnershipPolicy<ConcreteTaskReceiver::receiver_result_t>::Sharedtype ConcreteTaskReceiver::receiverShareOwnershipOfResults()
{
    OwnershipPolicy<receiver_result_t>::Sharedtype my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

ConcreteTaskReceiver::OwnershipPolicy<ConcreteTaskReceiver::receiver_result_t>::Transfertype ConcreteTaskReceiver::receiverTransferOwnershipOfResults()
{
    OwnershipPolicy<receiver_result_t>::Transfertype my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

//============================= OPERATORS ====================================

ConcreteTaskReceiver& ConcreteTaskReceiver::operator=( ConcreteTaskReceiver && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<ConcreteTaskReceiver>::operator=(std::move(other));
        this->ownershipPolicy_ = std::move(other.ownershipPolicy_);
        this->results_ = std::move(other.results_);
        this->base_ = std::move(other.base_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

ConcreteTaskReceiver::OwnershipPolicy<ConcreteTaskReceiver::receiver_result_t>::Copytype ConcreteTaskReceiver::receiverGetCopyOfResults_() const
{
    OwnershipPolicy<receiver_result_t>::Copytype  my_ptr = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

// ------------- //
//  <Edit here>  //
// ---------------------------------------------------
// Specializtion for modifying the ConcreteTaskReceiver::base_ data member.
// ---------------------------------------------------
template<>
void ConcreteTaskReceiver::receiverModifyMyself( int & value)
{
    this->base_ = value;
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
