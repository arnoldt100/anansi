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
    commandLineArguments_()
{
    return;
}

MPIEnvReceiver::MPIEnvReceiver( MPIEnvReceiver const & other) :
    ReceiverInterface<MPIEnvReceiver>(other),
    commandLineArguments_(other.commandLineArguments_)
{
    if (this != &other)
    {
        
    }
    return;
}

MPIEnvReceiver::MPIEnvReceiver( MPIEnvReceiver && other) :
    ReceiverInterface<MPIEnvReceiver>(std::move(other)),
    commandLineArguments_(std::move(other.commandLineArguments_))
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
        this->commandLineArguments_ = std::move(other.commandLineArguments_);

    }
    return *this;
} // assignment operator

MPIEnvReceiver& MPIEnvReceiver::operator= ( MPIEnvReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<MPIEnvReceiver>::operator=(std::move(other));
        this->commandLineArguments_ = std::move(other.commandLineArguments_);
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
