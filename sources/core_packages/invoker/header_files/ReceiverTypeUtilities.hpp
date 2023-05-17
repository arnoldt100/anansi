#ifndef ANANSI_ReceiverTypeUtilities_INC
#define ANANSI_ReceiverTypeUtilities_INC
//! @file ReceiverTypeUtilities.hpp
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "OwnershipTypes.hpp"
#include "TaskLabel.hpp"
#include "ReceiverUtilities.hpp"

namespace ANANSI
{

template <RECEIVER::OwnershipTypes T,
         typename LABEL_t,
         LABEL_t COMMAND_LABEL,
         typename ConcreteTasksTypeList>
struct GenericTaskInvokerOwnershipTypes; 

template <typename LABEL_t,LABEL_t COMMAND_LABEL,typename ConcreteTasksTypeList>
struct GenericTaskInvokerOwnershipTypes<RECEIVER::OwnershipTypes::COPYTYPE,LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList> 
{
    private:
        using concrete_task_type_ = 
            typename ConcreteTypeForCorrespondingLabel<ConcreteTasksTypeList,LABEL_t,COMMAND_LABEL>::concrete_type;

    public:
        using TYPE = 
            typename concrete_task_type_:: template MyOwnershipTypes<RECEIVER::OwnershipTypes::COPYTYPE>::TYPE;
};


}; // namespace ANANSI

#endif // ANANSI_ReceiverTypeUtilities_INC
