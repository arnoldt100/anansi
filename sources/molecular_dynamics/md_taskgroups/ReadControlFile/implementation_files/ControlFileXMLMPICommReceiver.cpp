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
#include "ControlFileXMLMPICommReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileXMLMPICommReceiver::ControlFileXMLMPICommReceiver() :
    ReceiverInterface<ControlFileXMLMPICommReceiver>(),
    results_()
{
    return;
}

ControlFileXMLMPICommReceiver::ControlFileXMLMPICommReceiver( ControlFileXMLMPICommReceiver && other) :
    ReceiverInterface<ControlFileXMLMPICommReceiver>(std::move(other)),
    results_(std::move(other.results_))
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileXMLMPICommReceiver::~ControlFileXMLMPICommReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileXMLMPICommReceiver& ControlFileXMLMPICommReceiver::operator= ( ControlFileXMLMPICommReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileXMLMPICommReceiver>::operator=(std::move(other));
        this->results_ = std::move(other.results_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

ControlFileXMLMPICommReceiver::OwnershipPolicy<ControlFileXMLMPICommReceiver::receiver_result_t>::Copytype 
ControlFileXMLMPICommReceiver::receiverGetCopyOfResults_() const
{
    OwnershipPolicy<ControlFileXMLMPICommReceiver::receiver_result_t>::Copytype my_ptr =
        ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

ControlFileXMLMPICommReceiver::OwnershipPolicy<ControlFileXMLMPICommReceiver::receiver_result_t>::Sharedtype ControlFileXMLMPICommReceiver::receiverShareOwnershipOfResults_()
{
    OwnershipPolicy<ControlFileXMLMPICommReceiver::receiver_result_t>::Sharedtype my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
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
