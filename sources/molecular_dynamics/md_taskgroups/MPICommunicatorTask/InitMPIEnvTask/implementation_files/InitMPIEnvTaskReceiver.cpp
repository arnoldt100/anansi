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
#include "InitMPIEnvTaskReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

InitMPIEnvTaskReceiver::InitMPIEnvTaskReceiver() :
    RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>(),
    results_(0),
    mpiEnvironment_(nullptr),
    ownershipPolicy_()
{
    return;
}

InitMPIEnvTaskReceiver::InitMPIEnvTaskReceiver( InitMPIEnvTaskReceiver && other) :
    RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>(std::move(other)),
    results_(std::move(other.results_)),
    mpiEnvironment_(std::move(other.mpiEnvironment_)),
    ownershipPolicy_(std::move(other.ownershipPolicy_))
{
    if (this != &other)
    {
        
    }
    return;
}

InitMPIEnvTaskReceiver::~InitMPIEnvTaskReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

InitMPIEnvTaskReceiver& InitMPIEnvTaskReceiver::operator= ( InitMPIEnvTaskReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<InitMPIEnvTaskReceiver>::operator=(std::move(other));
        this->results_ = std::move(other.results_);
        this->mpiEnvironment_ = std::move(other.mpiEnvironment_);
        this->ownershipPolicy_ = std::move(other.ownershipPolicy_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

InitMPIEnvTaskReceiver::receiver_copy_t InitMPIEnvTaskReceiver::receiverGetCopyOfResults_() const
{
    InitMPIEnvTaskReceiver::receiver_copy_t  my_ptr =
        this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}


//============================= MUTATORS =====================================

template<>
void InitMPIEnvTaskReceiver::receiverModifyMyself_(std::shared_ptr<ANANSI::MPIEnvironment> & arg)
{
    this->mpiEnvironment_ = arg;
    return;
}

InitMPIEnvTaskReceiver::receiver_share_t InitMPIEnvTaskReceiver::receiverShareOwnershipOfResults_()
{
    InitMPIEnvTaskReceiver::receiver_share_t my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}


InitMPIEnvTaskReceiver::receiver_transfer_t InitMPIEnvTaskReceiver::receiverTransferOwnershipOfResults_()
{
    InitMPIEnvTaskReceiver::receiver_transfer_t my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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
