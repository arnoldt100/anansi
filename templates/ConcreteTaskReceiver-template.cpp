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
#include "__header_filename__"

namespace __NAMESPACE__ {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

__classname__::__classname__() :
    RECEIVER::ReceiverInterface<__classname__>{},
    ownershipPolicy_{},
    results_{},
{
    return;
}

__classname__::__classname__( __classname__ && other) :
    RECEIVER::ReceiverInterface<__classname__>{std::move(other)},
    ownershipPolicy_{std::move(other.ownershipPolicy_)},
    results_{std::move(other.results_)}
{
    if (this != &other)
    {
        
    }
    return;
}

__classname__::~__classname__()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

__classname__& __classname__::operator= ( __classname__ && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<__classname__>::operator=(std::move(other));
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

__classname__::receiver_copy_t_ __classname__::receiverGetCopyOfResults_() const
{
    __classname__::receiver_copy_t_ my_copied_result  = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_copied_result;
}

//============================= MUTATORS =====================================

template<>
void __classname__::receiverModifyMyself_(int & alpha)
{
    return;
}

__classname__::receiver_share_t_ __classname__::receiverShareOwnershipOfResults_()
{
    __classname__::receiver_share_t_ my_shared_result = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_shared_result;   
}

__classname__::receiver_transfer_t_ __classname__::receiverTransferOwnershipOfResults_()
{
    __classname__::receiver_transfer_t_ my_transfered_result = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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


}; // ----- End of namespace __NAMESPACE__ -----
