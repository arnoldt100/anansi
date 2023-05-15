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
    ownershipPolicy_(),
    mpiEnvironment_(nullptr)
{
    return;
}

InitMPIEnvTaskReceiver::InitMPIEnvTaskReceiver( InitMPIEnvTaskReceiver && other) :
    RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>(std::move(other)),
    results_(std::move(other.results_)),
    ownershipPolicy_(std::move(other.ownershipPolicy_)),
    mpiEnvironment_(std::move(other.mpiEnvironment_))
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

InitMPIEnvTaskReceiver::receiver_copy_t_ InitMPIEnvTaskReceiver::receiverGetCopyOfResults_() const
{
    InitMPIEnvTaskReceiver::receiver_copy_t_  my_copied_result =
        this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_copied_result;
}


//============================= MUTATORS =====================================

template<>
void InitMPIEnvTaskReceiver::receiverModifyMyself_(std::shared_ptr<ANANSI::MPIEnvironment> & arg)
{
    this->mpiEnvironment_ = arg;
    return;
}

InitMPIEnvTaskReceiver::receiver_share_t_ InitMPIEnvTaskReceiver::receiverShareOwnershipOfResults_()
{
    InitMPIEnvTaskReceiver::receiver_share_t_ my_shared_result = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_shared_result;   
}


InitMPIEnvTaskReceiver::receiver_transfer_t_ InitMPIEnvTaskReceiver::receiverTransferOwnershipOfResults_()
{
    InitMPIEnvTaskReceiver::receiver_transfer_t_ my_transfered_result = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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
