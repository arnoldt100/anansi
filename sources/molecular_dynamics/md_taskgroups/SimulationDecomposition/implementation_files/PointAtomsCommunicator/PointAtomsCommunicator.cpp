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
#include "PointAtomsCommunicator.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

PointAtomsCommunicator::PointAtomsCommunicator() :
    RECEIVER::ReceiverInterface<PointAtomsCommunicator>{},
    results_{PointAtomsCommunicatorResultsTraits::Atoms_t()},
    communicator_{},
    ownershipPolicy_{}
{
    return;
}

PointAtomsCommunicator::PointAtomsCommunicator( PointAtomsCommunicator && other) :
    RECEIVER::ReceiverInterface<PointAtomsCommunicator>{std::move(other)},
    results_{std::move(other.results_)},
    communicator_{std::move(other.communicator_)},
    ownershipPolicy_{std::move(other.ownershipPolicy_)}
{
    if (this != &other)
    {
        
    }
    return;
}

PointAtomsCommunicator::~PointAtomsCommunicator()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

PointAtomsCommunicator& PointAtomsCommunicator::operator= ( PointAtomsCommunicator && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<PointAtomsCommunicator>::operator=(std::move(other));
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

PointAtomsCommunicator::receiver_copy_t_ PointAtomsCommunicator::receiverGetCopyOfResults_() const
{
    PointAtomsCommunicator::receiver_copy_t_ my_copied_result  = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_copied_result;
}

//============================= MUTATORS =====================================

template<>
void PointAtomsCommunicator::receiverModifyMyself_(std::unique_ptr<COMMUNICATOR::Communicator> & arg)
{
    this->communicator_ = std::move(arg);
    return;
}

PointAtomsCommunicator::receiver_share_t_ PointAtomsCommunicator::receiverShareOwnershipOfResults_()
{
    PointAtomsCommunicator::receiver_share_t_ my_shared_result = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_shared_result;   
}

PointAtomsCommunicator::receiver_transfer_t_ PointAtomsCommunicator::receiverTransferOwnershipOfResults_()
{
    PointAtomsCommunicator::receiver_transfer_t_ my_transfered_result = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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
