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
#include "InitWorldCommunicatorTaskReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//============================= LIFECYCLE ====================================

InitWorldCommunicatorTaskReceiver::InitWorldCommunicatorTaskReceiver() :
    RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>(),
    results_(nullptr)
{
    return;
}

InitWorldCommunicatorTaskReceiver::InitWorldCommunicatorTaskReceiver( InitWorldCommunicatorTaskReceiver && other) :
    RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>(std::move(other)),
    results_(std::move(other.results_))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method InitWorldCommunicatorTaskReceiver::InitWorldCommunicatorTaskReceiver  -----


InitWorldCommunicatorTaskReceiver::~InitWorldCommunicatorTaskReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

template<>
void InitWorldCommunicatorTaskReceiver::receiverModifyMyself(std::unique_ptr<COMMUNICATOR::Communicator> & arg) 
{
    (this->results_) = std::move(arg);
    return;
}

//============================= OPERATORS ====================================

InitWorldCommunicatorTaskReceiver& InitWorldCommunicatorTaskReceiver::operator= ( InitWorldCommunicatorTaskReceiver && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::operator=(std::move(other));
        this->results_ = std::move(other.results_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

// TO DO: For now we return a null pointer.
InitWorldCommunicatorTaskReceiver::OwnershipPolicy<InitWorldCommunicatorTaskReceiver::receiver_result_t>::Copytype InitWorldCommunicatorTaskReceiver::receiverGetCopyOfResults_() const
{
    InitWorldCommunicatorTaskReceiver::OwnershipPolicy<InitWorldCommunicatorTaskReceiver::receiver_result_t>::Copytype my_ptr;
    return my_ptr;
}

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
