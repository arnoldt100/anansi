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
#include "MPICommunicatorReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPICommunicatorReceiver::MPICommunicatorReceiver() :
    ReceiverInterface<MPICommunicatorReceiver>(),
    communicator_()
{
    return;
}

MPICommunicatorReceiver::MPICommunicatorReceiver( MPICommunicatorReceiver const & other) :
    ReceiverInterface<MPICommunicatorReceiver>(other),
    communicator_(other.communicator_)
{
    if (this != &other)
    {
        
    }
    return;
}

MPICommunicatorReceiver::MPICommunicatorReceiver( MPICommunicatorReceiver && other) :
    ReceiverInterface<MPICommunicatorReceiver>(std::move(other)),
    communicator_(std::move(other.communicator_))
{
    if (this != &other)
    {
        
    }
    return;
}

MPICommunicatorReceiver::~MPICommunicatorReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MPICommunicatorReceiver& MPICommunicatorReceiver::operator= ( const MPICommunicatorReceiver &other )
{
    if (this != &other)
    {
        ReceiverInterface<MPICommunicatorReceiver>::operator=(other);
        this->communicator_ = other.communicator_;

    }
    return *this;
} // assignment operator

MPICommunicatorReceiver& MPICommunicatorReceiver::operator= ( MPICommunicatorReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<MPICommunicatorReceiver>::operator=(std::move(other));
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
void MPICommunicatorReceiver::enableReceiver(std::shared_ptr<COMMUNICATOR::Communicator> & arg)
{
    this->communicator_ = arg;
    return;
}

//============================= OPERATORS ====================================


} // namespace ANANSI
