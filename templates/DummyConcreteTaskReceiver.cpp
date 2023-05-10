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
    results_(0),
    ownershipPolicy_()
{
    return;
}

DummyConcreteTaskReceiver::DummyConcreteTaskReceiver( DummyConcreteTaskReceiver && other) :
    ReceiverInterface<DummyConcreteTaskReceiver>(std::move(other)),
    results_(std::move(other.results_)),
    ownershipPolicy_(std::move(other.ownershipPolicy_))
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
        this->results_ = std::move(other.results_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

DummyConcreteTaskReceiver::MyOwnershipImplTraits_::Copytype DummyConcreteTaskReceiver::receiverGetCopyOfResults_() const
{
    DummyConcreteTaskReceiver::MyOwnershipImplTraits_::Copytype my_ptr = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

DummyConcreteTaskReceiver::MyOwnershipImplTraits_::Transfertype DummyConcreteTaskReceiver::receiverTransferOwnershipOfResults_()
{
    DummyConcreteTaskReceiver::MyOwnershipImplTraits_::Transfertype my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

DummyConcreteTaskReceiver::MyOwnershipImplTraits_::Sharetype DummyConcreteTaskReceiver::receiverShareOwnershipOfResults_()
{
    DummyConcreteTaskReceiver::MyOwnershipImplTraits_::Sharetype my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

template<>
void DummyConcreteTaskReceiver::receiverModifyMyself_(int & alpha)
{
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
