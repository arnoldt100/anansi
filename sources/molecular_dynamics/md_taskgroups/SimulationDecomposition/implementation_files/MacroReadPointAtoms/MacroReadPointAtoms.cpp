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
#include "MacroReadPointAtoms.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MacroReadPointAtoms::MacroReadPointAtoms() :
    RECEIVER::ReceiverInterface<MacroReadPointAtoms>{},
    results_{MacroReadPointAtomsResultsTraits::Atoms_t()},
    componentTasks_{},
    ownershipPolicy_{}
   
{
    return;
}

MacroReadPointAtoms::MacroReadPointAtoms( MacroReadPointAtoms && other) :
    RECEIVER::ReceiverInterface<MacroReadPointAtoms>{std::move(other)},
    results_(std::move(other.results_)),
    componentTasks_{std::move(other.componentTasks_)},
    ownershipPolicy_{std::move(other.ownershipPolicy_)}
{
    if (this != &other)
    {
        
    }
    return;
}

MacroReadPointAtoms::~MacroReadPointAtoms()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MacroReadPointAtoms& MacroReadPointAtoms::operator= ( MacroReadPointAtoms && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<MacroReadPointAtoms>::operator=(std::move(other));
        this->results_ = std::move(other.results_);
        this->componentTasks_ = std::move(other.componentTasks_);
        this->ownershipPolicy_ = std::move(other.ownershipPolicy_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

MacroReadPointAtoms::receiver_copy_t_ MacroReadPointAtoms::receiverGetCopyOfResults_() const
{
    MacroReadPointAtoms::receiver_copy_t_ my_copied_result  = this->ownershipPolicy_.copyReceiverResult(this->results_);
    return my_copied_result;
}

//============================= MUTATORS =====================================

template<>
void MacroReadPointAtoms::receiverModifyMyself_<std::shared_ptr<ANANSI::AnansiTask>>(std::shared_ptr<ANANSI::AnansiTask> & a_task)
{
    const auto task_label= a_task->taskLabel();
    this->componentTasks_[task_label] = a_task;
    return;
}

MacroReadPointAtoms::receiver_share_t_ MacroReadPointAtoms::receiverShareOwnershipOfResults_()
{
    MacroReadPointAtoms::receiver_share_t_ my_shared_result = ownershipPolicy_.shareOwnershipOfReceiverResult(this->results_);
    return my_shared_result;   
}

MacroReadPointAtoms::receiver_transfer_t_ MacroReadPointAtoms::receiverTransferOwnershipOfResults_()
{
    MacroReadPointAtoms::receiver_transfer_t_ my_transfered_result = ownershipPolicy_.transferOwnershipOfReceiverResult(this->results_);
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


} // namespace ANANSI
