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
#include "GenericTaskUtilities.hpp"

namespace ANANSI
{
    namespace PRIVATE_NAMESPACE_
    {
        template < typename LABEL_t,
                   LABEL_t COMMAND_LABEL,
                   typename ConcreteTasksTypeList>
        struct GenericTaskInvokerOwnershipConcreteType
        {
            public:
                using TYPE = 
                    typename ConcreteTypeForCorrespondingLabel<ConcreteTasksTypeList,LABEL_t,COMMAND_LABEL>::TYPE;
        };
    };

template <typename LABEL_t,LABEL_t COMMAND_LABEL,typename ConcreteTasksTypeList>
struct GenericTaskInvokerOwnershipTypes<RECEIVER::OwnershipTypes::COPYTYPE,LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList> 
{
    private:
        using concrete_task_type_ = 
            typename PRIVATE_NAMESPACE_::GenericTaskInvokerOwnershipConcreteType<LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList>::TYPE;

    public:
        using TYPE = 
            typename concrete_task_type_:: template MyOwnershipTypes<RECEIVER::OwnershipTypes::COPYTYPE>::TYPE;
};

template <typename LABEL_t,LABEL_t COMMAND_LABEL,typename ConcreteTasksTypeList>
struct GenericTaskInvokerOwnershipTypes<RECEIVER::OwnershipTypes::SHARETYPE,LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList> 
{
    private:
        using concrete_task_type_ = 
            typename PRIVATE_NAMESPACE_::GenericTaskInvokerOwnershipConcreteType<LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList>::TYPE;

    public:
        using TYPE = 
            typename concrete_task_type_:: template MyOwnershipTypes<RECEIVER::OwnershipTypes::SHARETYPE>::TYPE;
};

template <typename LABEL_t,LABEL_t COMMAND_LABEL,typename ConcreteTasksTypeList>
struct GenericTaskInvokerOwnershipTypes<RECEIVER::OwnershipTypes::TRANSFERTYPE,LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList> 
{
    private:
        using concrete_task_type_ = 
            typename PRIVATE_NAMESPACE_::GenericTaskInvokerOwnershipConcreteType<LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList>::TYPE;

    public:
        using TYPE = 
            typename concrete_task_type_:: template MyOwnershipTypes<RECEIVER::OwnershipTypes::TRANSFERTYPE>::TYPE;
};

}; // namespace ANANSI

#endif // ANANSI_ReceiverTypeUtilities_INC
