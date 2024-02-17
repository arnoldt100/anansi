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
#include "PointAtomsDecomposer.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

PointAtomsDecomposer::PointAtomsDecomposer() :
    RECEIVER::ReceiverInterface<PointAtomsDecomposer>{},
    results_{PointAtomsDecomposerResultsTraits::Atoms_t()},
    ownershipPolicy_{}
{
    return;
}

PointAtomsDecomposer::PointAtomsDecomposer( PointAtomsDecomposer && other) :
    RECEIVER::ReceiverInterface<PointAtomsDecomposer>{std::move(other)},
    results_{std::move(other.results_)},
    ownershipPolicy_{std::move(other.ownershipPolicy_)}
{
    if (this != &other)
    {
        
    }
    return;
}

PointAtomsDecomposer::~PointAtomsDecomposer()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

PointAtomsDecomposer& PointAtomsDecomposer::operator= ( PointAtomsDecomposer && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<PointAtomsDecomposer>::operator=(std::move(other));
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

PointAtomsDecomposer::receiver_copy_t_ PointAtomsDecomposer::receiverGetCopyOfResults_() const
{
    PointAtomsDecomposer::receiver_copy_t_ my_copied_result  = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_copied_result;
}

//============================= MUTATORS =====================================

template<>
void PointAtomsDecomposer::receiverModifyMyself_(int & alpha)
{
    return;
}

PointAtomsDecomposer::receiver_share_t_ PointAtomsDecomposer::receiverShareOwnershipOfResults_()
{
    PointAtomsDecomposer::receiver_share_t_ my_shared_result = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_shared_result;   
}

PointAtomsDecomposer::receiver_transfer_t_ PointAtomsDecomposer::receiverTransferOwnershipOfResults_()
{
    PointAtomsDecomposer::receiver_transfer_t_ my_transfered_result = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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
