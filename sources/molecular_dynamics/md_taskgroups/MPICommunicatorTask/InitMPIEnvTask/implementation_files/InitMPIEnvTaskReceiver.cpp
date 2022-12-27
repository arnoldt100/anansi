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

    
const RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>::TASK_LABEL_TYPE InitMPIEnvTaskReceiver::TASKLABEL =
    RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>::TASK_LABEL_TYPE(InitMPIEnvTaskReceiver::tmpstr,0);

InitMPIEnvTaskReceiver::InitMPIEnvTaskReceiver() :
    ReceiverInterface<InitMPIEnvTaskReceiver>(),
    mpiEnvironment_(nullptr)
{
    return;
}

InitMPIEnvTaskReceiver::InitMPIEnvTaskReceiver( InitMPIEnvTaskReceiver const & other) :
    ReceiverInterface<InitMPIEnvTaskReceiver>(other),
    mpiEnvironment_(other.mpiEnvironment_)
{
    if (this != &other)
    {
        
    }
    return;
}

InitMPIEnvTaskReceiver::InitMPIEnvTaskReceiver( InitMPIEnvTaskReceiver && other) :
    ReceiverInterface<InitMPIEnvTaskReceiver>(std::move(other)),
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

RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>::TASK_LABEL_TYPE InitMPIEnvTaskReceiver::receiverGetTaskLabel() const
{
    return  InitMPIEnvTaskReceiver::TASKLABEL;
}

//============================= MUTATORS =====================================

template<>
void InitMPIEnvTaskReceiver::enableReceiver(std::shared_ptr<ANANSI::MPIEnvironment> & arg)
{
    this->mpiEnvironment_ = arg;
    return;
}

//============================= OPERATORS ====================================

InitMPIEnvTaskReceiver& InitMPIEnvTaskReceiver::operator= ( const InitMPIEnvTaskReceiver &other )
{
    if (this != &other)
    {
        ReceiverInterface<InitMPIEnvTaskReceiver>::operator=(other);
        this->mpiEnvironment_ = other.mpiEnvironment_;
    }
    return *this;
} // assignment operator

InitMPIEnvTaskReceiver& InitMPIEnvTaskReceiver::operator= ( InitMPIEnvTaskReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<InitMPIEnvTaskReceiver>::operator=(std::move(other));
        this->mpiEnvironment_ = std::move(other.mpiEnvironment_);
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
