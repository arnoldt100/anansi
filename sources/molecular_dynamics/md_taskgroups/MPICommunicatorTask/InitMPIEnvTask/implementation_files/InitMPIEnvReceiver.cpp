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
#include "InitMPIEnvReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

InitMPIEnvReceiver::InitMPIEnvReceiver() :
    ReceiverInterface<InitMPIEnvReceiver>(),
    mpiEnvironment_(nullptr)

{
    return;
}

InitMPIEnvReceiver::InitMPIEnvReceiver( InitMPIEnvReceiver const & other) :
    ReceiverInterface<InitMPIEnvReceiver>(other),
    mpiEnvironment_(other.mpiEnvironment_)
{
    if (this != &other)
    {
        
    }
    return;
}

InitMPIEnvReceiver::InitMPIEnvReceiver( InitMPIEnvReceiver && other) :
    ReceiverInterface<InitMPIEnvReceiver>(std::move(other)),
    mpiEnvironment_(std::move(other.mpiEnvironment_))
{
    if (this != &other)
    {
        
    }
    return;
}

InitMPIEnvReceiver::~InitMPIEnvReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

InitMPIEnvReceiver& InitMPIEnvReceiver::operator= ( const InitMPIEnvReceiver &other )
{
    if (this != &other)
    {
        ReceiverInterface<InitMPIEnvReceiver>::operator=(other);
        this->mpiEnvironment_ = std::move(other.mpiEnvironment_);
    }
    return *this;
} // assignment operator

InitMPIEnvReceiver& InitMPIEnvReceiver::operator= ( InitMPIEnvReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<InitMPIEnvReceiver>::operator=(std::move(other));
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
template<>
void InitMPIEnvReceiver::enableReceiver(std::shared_ptr<ANANSI::MPIEnvironment> & arg)
{
    this->mpiEnvironment_ = arg;
    return;
}

//============================= OPERATORS ====================================


} // namespace ANANSI
