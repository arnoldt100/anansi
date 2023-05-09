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
#include "DummyConcreteTask.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

DummyConcreteTask::DummyConcreteTask() :
    ReceiverInterface<DummyConcreteTask>(),
    results_(0),
    ownershipPolicy_()
{
    return;
}

DummyConcreteTask::DummyConcreteTask( DummyConcreteTask && other) :
    ReceiverInterface<DummyConcreteTask>(std::move(other)),
    results_(std::move(other.results_)),
    ownershipPolicy_(std::move(other.ownershipPolicy_))
{
    if (this != &other)
    {
        
    }
    return;
}

DummyConcreteTask::~DummyConcreteTask()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

DummyConcreteTask& DummyConcreteTask::operator= ( DummyConcreteTask && other )
{
    if (this != &other)
    {
        ReceiverInterface<DummyConcreteTask>::operator=(std::move(other));
        this->results_ = std::move(other.results_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

DummyConcreteTask::MyOwnershipImplTraits_::Copytype DummyConcreteTask::receiverGetCopyOfResults_() const
{
    DummyConcreteTask::MyOwnershipImplTraits_::Copytype my_ptr = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

DummyConcreteTask::MyOwnershipImplTraits_::Transfertype DummyConcreteTask::receiverTransferOwnershipOfResults_()
{
    DummyConcreteTask::MyOwnershipImplTraits_::Transfertype my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

DummyConcreteTask::MyOwnershipImplTraits_::Sharetype DummyConcreteTask::receiverShareOwnershipOfResults_()
{
    DummyConcreteTask::MyOwnershipImplTraits_::Sharetype my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

template<>
void DummyConcreteTask::receiverModifyMyself_(int & alpha)
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
