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
    results_(0)
{
    return;
}

DummyConcreteTask::DummyConcreteTask( DummyConcreteTask && other) :
    ReceiverInterface<DummyConcreteTask>(std::move(other)),
    results_(std::move(other.results_))
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

std::unique_ptr<DummyConcreteTask::receiver_result_t> DummyConcreteTask::receiverGetCopyOfResults() const
{
    std::unique_ptr<DummyConcreteTask::receiver_result_t> my_ptr =
        std::make_unique<DummyConcreteTask::receiver_result_t>(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

template<>
void DummyConcreteTask::enableReceiver(int & alpha)
{
    return;
}

template<>
void DummyConcreteTask::receiverModifyMyself(int & alpha)
{
    return;
}



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

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
