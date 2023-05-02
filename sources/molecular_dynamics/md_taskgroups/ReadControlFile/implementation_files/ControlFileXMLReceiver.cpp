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
#include "ControlFileXMLReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileXMLReceiver::ControlFileXMLReceiver() :
    RECEIVER::ReceiverInterface<ControlFileXMLReceiver>(),
    ownershipPolicy_(),
    results_(0)
{
    return;
}

ControlFileXMLReceiver::ControlFileXMLReceiver( ControlFileXMLReceiver && other) :
    RECEIVER::ReceiverInterface<ControlFileXMLReceiver>(std::move(other)),
    ownershipPolicy_(std::move(other.ownershipPolicy_)),
    results_(std::move(other.results_))
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileXMLReceiver::~ControlFileXMLReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileXMLReceiver& ControlFileXMLReceiver::operator= ( ControlFileXMLReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileXMLReceiver>::operator=(std::move(other));
        this->ownershipPolicy_ = std::move(other.ownershipPolicy_);
        this->results_ = std::move(other.results_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

ControlFileXMLReceiver::MyOwnershipImplTraits_::Copytype ControlFileXMLReceiver::receiverGetCopyOfResults_() const
{
    ControlFileXMLReceiver::MyOwnershipImplTraits_::Copytype my_ptr = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

template<>
void ControlFileXMLReceiver::receiverModifyMyself_(int & arg)
{
    this->results_ = arg;
    return;
}

template<>
void ControlFileXMLReceiver::receiverModifyMyself_(ControlFileName & arg)
{
    this->controlFileName_ = arg;
    return;
}

ControlFileXMLReceiver::MyOwnershipImplTraits_::Sharetype ControlFileXMLReceiver::receiverShareOwnershipOfResults_()
{
    ControlFileXMLReceiver::MyOwnershipImplTraits_::Sharetype my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

ControlFileXMLReceiver::MyOwnershipImplTraits_::Transfertype ControlFileXMLReceiver::receiverTransferOwnershipOfResults_()
{
    ControlFileXMLReceiver::MyOwnershipImplTraits_::Transfertype my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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
