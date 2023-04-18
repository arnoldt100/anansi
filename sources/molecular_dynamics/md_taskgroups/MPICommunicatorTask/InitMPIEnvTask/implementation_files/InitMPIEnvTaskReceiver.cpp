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
    ReceiverInterface<InitMPIEnvTaskReceiver>(),
    mpiEnvironment_(nullptr),
    results_(0)
{
    return;
}

InitMPIEnvTaskReceiver::InitMPIEnvTaskReceiver( InitMPIEnvTaskReceiver && other) :
    ReceiverInterface<InitMPIEnvTaskReceiver>(std::move(other)),
    mpiEnvironment_(std::move(other.mpiEnvironment_)),
    results_(std::move(other.results_))
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
        this->mpiEnvironment_ = std::move(other.mpiEnvironment_);
        this->results_ = std::move(other.results_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

InitMPIEnvTaskReceiver::OwnershipPolicy<InitMPIEnvTaskReceiver::receiver_result_t>::Copytype InitMPIEnvTaskReceiver::receiverGetCopyOfResults_() const
{
    OwnershipPolicy<InitMPIEnvTaskReceiver::receiver_result_t>::Copytype  my_ptr = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}


//============================= MUTATORS =====================================

template<>
void InitMPIEnvTaskReceiver::receiverModifyMyself_(std::shared_ptr<ANANSI::MPIEnvironment> & arg)
{
    this->mpiEnvironment_ = arg;
    return;
}

InitMPIEnvTaskReceiver::OwnershipPolicy<InitMPIEnvTaskReceiver::receiver_result_t>::Sharedtype InitMPIEnvTaskReceiver::receiverShareOwnershipOfResults_()
{
    OwnershipPolicy<InitMPIEnvTaskReceiver::receiver_result_t>::Sharedtype my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}


InitMPIEnvTaskReceiver::OwnershipPolicy<InitMPIEnvTaskReceiver::receiver_result_t>::Transfertype InitMPIEnvTaskReceiver::receiverTransferOwnershipOfResults_()
{
    OwnershipPolicy<InitMPIEnvTaskReceiver::receiver_result_t>::Transfertype my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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
