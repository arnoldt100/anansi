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
#include "DummyConcreteTaskReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

DummyConcreteTaskReceiver::DummyConcreteTaskReceiver() :
    ReceiverInterface<DummyConcreteTaskReceiver>(),
    ownershipPolicy_(),
    results_(0),
{
    return;
}

DummyConcreteTaskReceiver::DummyConcreteTaskReceiver( DummyConcreteTaskReceiver && other) :
    ReceiverInterface<DummyConcreteTaskReceiver>(std::move(other)),
    ownershipPolicy_(std::move(other.ownershipPolicy_)),
    results_(std::move(other.results_))
{
    if (this != &other)
    {
        
    }
    return;
}

DummyConcreteTaskReceiver::~DummyConcreteTaskReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

DummyConcreteTaskReceiver& DummyConcreteTaskReceiver::operator= ( DummyConcreteTaskReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<DummyConcreteTaskReceiver>::operator=(std::move(other));
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

DummyConcreteTaskReceiver::receiver_copy_t_ DummyConcreteTaskReceiver::receiverGetCopyOfResults_() const
{
    DummyConcreteTaskReceiver::receiver_copy_t_ my_copied_result  = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_copied_result;
}

//============================= MUTATORS =====================================

template<>
void DummyConcreteTaskReceiver::receiverModifyMyself_(int & alpha)
{
    return;
}

DummyConcreteTaskReceiver::receiver_share_t_ DummyConcreteTaskReceiver::receiverShareOwnershipOfResults_()
{
    DummyConcreteTaskReceiver::receiver_share_t_ my_shared_result = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_shared_result;   
}

DummyConcreteTaskReceiver::receiver_transfer_t_ DummyConcreteTaskReceiver::receiverTransferOwnershipOfResults_()
{
    DummyConcreteTaskReceiver::receiver_transfer_t_ my_transfered_result = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
    return my_transfered_result;   
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
