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
#include "ReadPointAtoms.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ReadPointAtoms::ReadPointAtoms() :
    RECEIVER::ReceiverInterface<ReadPointAtoms>{},
    enabledStatus_{false},
    results_{ReadPointAtomsResultsTraits::Atoms_t()},
    ownershipPolicy_{}
{
    return;
}

ReadPointAtoms::ReadPointAtoms( ReadPointAtoms && other) :
    RECEIVER::ReceiverInterface<ReadPointAtoms>{std::move(other)},
    enabledStatus_{std::move(other.enabledStatus_)},
    results_{std::move(other.results_)},
    ownershipPolicy_{std::move(other.ownershipPolicy_)}
{
    if (this != &other)
    {
        
    }
    return;
}

ReadPointAtoms::~ReadPointAtoms()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ReadPointAtoms& ReadPointAtoms::operator= ( ReadPointAtoms && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<ReadPointAtoms>::operator=(std::move(other));
        this->enabledStatus_ = std::move(other.enabledStatus_);
        this->results_ = std::move(other.results_);
        this->ownershipPolicy_ = std::move(other.ownershipPolicy_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

ReadPointAtoms::receiver_copy_t_ ReadPointAtoms::receiverGetCopyOfResults_() const
{
    ReadPointAtoms::receiver_copy_t_ my_copied_result  = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_copied_result;
}

bool ReadPointAtoms::ifEnabled_ () const
{
    return this->enabledStatus_;
}

//============================= MUTATORS =====================================

template<>
void ReadPointAtoms::receiverModifyMyself_(int & alpha)
{
    return;
}

ReadPointAtoms::receiver_share_t_ ReadPointAtoms::receiverShareOwnershipOfResults_()
{
    ReadPointAtoms::receiver_share_t_ my_shared_result = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_shared_result;   
}

ReadPointAtoms::receiver_transfer_t_ ReadPointAtoms::receiverTransferOwnershipOfResults_()
{
    ReadPointAtoms::receiver_transfer_t_ my_transfered_result = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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


}; // ----- End of namespace ANANSI -----
