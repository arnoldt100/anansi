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
#include "MPIEnvReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPIEnvReceiver::MPIEnvReceiver() :
    ReceiverInterface<MPIEnvReceiver>(),
    mpiEnvironment_(nullptr)
{
    return;
}

MPIEnvReceiver::MPIEnvReceiver( MPIEnvReceiver const & other) :
    ReceiverInterface<MPIEnvReceiver>(other),
    mpiEnvironment_(other.mpiEnvironment_)
{
    if (this != &other)
    {
        
    }
    return;
}

MPIEnvReceiver::MPIEnvReceiver( MPIEnvReceiver && other) :
    ReceiverInterface<MPIEnvReceiver>(std::move(other)),
    mpiEnvironment_(std::move(other.mpiEnvironment_))
{
    if (this != &other)
    {
        
    }
    return;
}

MPIEnvReceiver::~MPIEnvReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MPIEnvReceiver& MPIEnvReceiver::operator= ( const MPIEnvReceiver &other )
{
    if (this != &other)
    {
        ReceiverInterface<MPIEnvReceiver>::operator=(other);
        this->mpiEnvironment_ = std::move(other.mpiEnvironment_);

    }
    return *this;
} // assignment operator

MPIEnvReceiver& MPIEnvReceiver::operator= ( MPIEnvReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<MPIEnvReceiver>::operator=(std::move(other));
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
template<>
void MPIEnvReceiver::enableReceiver(std::shared_ptr<ANANSI::MPIEnvironment> & arg)
{
    std::cout << "Enabling command line arguments in MPIEnvReceiver" <<  std::endl;
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
