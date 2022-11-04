
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
#include "InitCommunicatorTaskReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

InitCommunicatorTaskReceiver::InitCommunicatorTaskReceiver() :
    ReceiverInterface<InitCommunicatorTaskReceiver>(),
    communicator_(nullptr)
{
    return;
}

InitCommunicatorTaskReceiver::InitCommunicatorTaskReceiver( InitCommunicatorTaskReceiver const & other) :
    ReceiverInterface<InitCommunicatorTaskReceiver>(other),
    communicator_(other.communicator_)
{
    if (this != &other)
    {
        
    }
    return;
}

InitCommunicatorTaskReceiver::InitCommunicatorTaskReceiver( InitCommunicatorTaskReceiver && other) :
    ReceiverInterface<InitCommunicatorTaskReceiver>(std::move(other)),
    communicator_(std::move(other.communicator_))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method InitCommunicatorTaskReceiver::InitCommunicatorTaskReceiver  -----


InitCommunicatorTaskReceiver::~InitCommunicatorTaskReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

InitCommunicatorTaskReceiver& InitCommunicatorTaskReceiver::operator= ( const InitCommunicatorTaskReceiver &other )
{
    if (this != &other)
    {
        ReceiverInterface<InitCommunicatorTaskReceiver>::operator=(other);
        this->communicator_ = other.communicator_;
    }
    return *this;
} // assignment operator

InitCommunicatorTaskReceiver& InitCommunicatorTaskReceiver::operator= ( InitCommunicatorTaskReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<InitCommunicatorTaskReceiver>::operator=(std::move(other));
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

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
template<>
void InitCommunicatorTaskReceiver::enableReceiver(std::shared_ptr<COMMUNICATOR::Communicator> & arg)
{
    this->communicator_ = arg;
    return;
}

//============================= OPERATORS ====================================


} // namespace ANANSI
