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
    mpiEnvironment_(nullptr),
    results_(0)
{
    return;
}

InitMPIEnvTaskReceiver::InitMPIEnvTaskReceiver( InitMPIEnvTaskReceiver && other) :
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

InitMPIEnvTaskReceiver::MyOwnershipImplTraits_::Copytype InitMPIEnvTaskReceiver::receiverGetCopyOfResults_() const
{
    InitMPIEnvTaskReceiver::MyOwnershipImplTraits_::Copytype  my_ptr =
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

InitMPIEnvTaskReceiver::MyOwnershipImplTraits_::Sharetype InitMPIEnvTaskReceiver::receiverShareOwnershipOfResults_()
{
    InitMPIEnvTaskReceiver::MyOwnershipImplTraits_::Sharetype my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}


InitMPIEnvTaskReceiver::MyOwnershipImplTraits_::Transfertype InitMPIEnvTaskReceiver::receiverTransferOwnershipOfResults_()
{
    InitMPIEnvTaskReceiver::MyOwnershipImplTraits_::Transfertype my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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
