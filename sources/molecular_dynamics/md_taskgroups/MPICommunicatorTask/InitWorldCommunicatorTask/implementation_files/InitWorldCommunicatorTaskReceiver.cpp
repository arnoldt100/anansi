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


const RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::TASK_LABEL_TYPE TASKLABEL =
  RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::TASK_LABEL_TYPE(InitWorldCommunicatorTaskReceiver::tmpstr,0);

InitWorldCommunicatorTaskReceiver::InitWorldCommunicatorTaskReceiver() :
    RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>(),
    communicator_(nullptr)
{
    return;
}

InitWorldCommunicatorTaskReceiver::InitWorldCommunicatorTaskReceiver( InitWorldCommunicatorTaskReceiver const & other) :
    RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>(other),
    communicator_(other.communicator_)
{
    if (this != &other)
    {
        
    }
    return;
}

InitWorldCommunicatorTaskReceiver::InitWorldCommunicatorTaskReceiver( InitWorldCommunicatorTaskReceiver && other) :
    RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>(std::move(other)),
    communicator_(std::move(other.communicator_))
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
RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::TASK_LABEL_TYPE InitWorldCommunicatorTaskReceiver::receiverGetTaskLabel() const
{
    return  InitWorldCommunicatorTaskReceiver::TASKLABEL;
}

//============================= MUTATORS =====================================

template<>
void InitWorldCommunicatorTaskReceiver::receiverModifyMyself(std::shared_ptr<COMMUNICATOR::Communicator> & arg) 
{
    // We need to modify the undelying resource
    *(this->communicator_) = std::move(*arg);
    return;
}

//============================= OPERATORS ====================================

InitWorldCommunicatorTaskReceiver& InitWorldCommunicatorTaskReceiver::operator= ( const InitWorldCommunicatorTaskReceiver &other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::operator=(other);
        this->communicator_ = other.communicator_;
    }
    return *this;
} // assignment operator

InitWorldCommunicatorTaskReceiver& InitWorldCommunicatorTaskReceiver::operator= ( InitWorldCommunicatorTaskReceiver && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::operator=(std::move(other));
        this->communicator_ = std::move(other.communicator_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

template<>
void InitWorldCommunicatorTaskReceiver::enableReceiver(std::shared_ptr<COMMUNICATOR::Communicator> & arg) 
{
    this->communicator_ = arg;
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
