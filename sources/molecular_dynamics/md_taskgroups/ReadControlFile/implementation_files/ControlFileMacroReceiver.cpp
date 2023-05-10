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
#include "ControlFileMacroReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileMacroReceiver::ControlFileMacroReceiver() :
    ReceiverInterface<ControlFileMacroReceiver>(),
    results_(0),
    ownershipPolicy_()
{
    return;
}

ControlFileMacroReceiver::ControlFileMacroReceiver( ControlFileMacroReceiver && other) :
    ReceiverInterface<ControlFileMacroReceiver>(std::move(other)),
    results_(std::move(other.results_)),
    ownershipPolicy_(std::move(other.ownershipPolicy_))
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileMacroReceiver::~ControlFileMacroReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileMacroReceiver& ControlFileMacroReceiver::operator= ( ControlFileMacroReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileMacroReceiver>::operator=(std::move(other));
        this->results_ = std::move(other.results_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

ControlFileMacroReceiver::MyOwnershipImplTraits_::Copytype ControlFileMacroReceiver::receiverGetCopyOfResults_() const
{
    ControlFileMacroReceiver::MyOwnershipImplTraits_::Copytype my_ptr = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

ControlFileMacroReceiver::MyOwnershipImplTraits_::Transfertype ControlFileMacroReceiver::receiverTransferOwnershipOfResults_()
{
    ControlFileMacroReceiver::MyOwnershipImplTraits_::Transfertype my_ptr = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

ControlFileMacroReceiver::MyOwnershipImplTraits_::Sharetype ControlFileMacroReceiver::receiverShareOwnershipOfResults_()
{
    ControlFileMacroReceiver::MyOwnershipImplTraits_::Sharetype my_ptr = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_ptr;   
}

template<>
void ControlFileMacroReceiver::receiverModifyMyself_(int & alpha)
{
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
