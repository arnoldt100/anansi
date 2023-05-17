#ifndef ANANSI_GenericTaskInvokerUtilities_INC
#define ANANSI_GenericTaskInvokerUtilities_INC

//! @file GenericTaskInvokerUtilities.hpp
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskLabel.hpp"
#include "AnansiTask.h"
#include "AnansiTaskUtilities.hpp"
#include "MPLAliases.hpp"
#include "ReceiverUtilities.hpp"
#include "OwnershipTypes.hpp"
#include "ReceiverTypeUtilities.hpp"

namespace ANANSI
{

class GenericTaskInvokerUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericTaskInvokerUtilities() // constructor
        {
            return;
        }

        GenericTaskInvokerUtilities(
            const GenericTaskInvokerUtilities &other) // copy constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        GenericTaskInvokerUtilities(
            GenericTaskInvokerUtilities &&other) // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~GenericTaskInvokerUtilities() // destructor
        {
            return;
        }

        // ====================  STATIC        =======================================

        //! Modifies the receiver of the concrete type located at concrete_index.
        template <typename ConcreteTasksTypeList,
                  typename LABEL_t, 
                  LABEL_t COMMAND_LABEL,
                  typename... ReceiverArgsTypes>
        static void
        modifyTaskReceiver(std::shared_ptr<ANANSI::AnansiTask> &task,
                           ReceiverArgsTypes &...receiver_args)
        {
            using concrete_task_type = 
                typename  ConcreteTypeForCorrespondingLabel<ConcreteTasksTypeList,LABEL_t,COMMAND_LABEL>::concrete_type;

            std::shared_ptr<concrete_task_type> concrete_task =
                AnansiTaskUtilities<ANANSI::AnansiTask,concrete_task_type>::asConcreteTask(task);
            concrete_task->modifyReceiver(receiver_args...);

            return;
        }

        //! Returns a copy of the result of a concrete task.
        //!
        //! @tparam A typelist of concrete task types.
        //! @param[in,out] task The concrete task of whose results we want,
        template <typename ConcreteTasksTypeList,
                  typename LABEL_t,
                  LABEL_t COMMAND_LABEL>
        static auto
        getCopyOfTaskReceiverResults(std::shared_ptr<ANANSI::AnansiTask> &task)
        {
            using concrete_task_type = 
                typename  ConcreteTypeForCorrespondingLabel<ConcreteTasksTypeList,LABEL_t,COMMAND_LABEL>::concrete_type;

            using receiver_copy_t = 
                typename concrete_task_type:: template MyOwnershipTypes<RECEIVER::OwnershipTypes::COPYTYPE>::TYPE;

            std::shared_ptr<concrete_task_type> concrete_task =
                AnansiTaskUtilities<ANANSI::AnansiTask,concrete_task_type>::asConcreteTask(task);

            receiver_copy_t ret_val = concrete_task->getCopyOfResults();

            return ret_val;
        }


        //! Returns a shared type of the result of a concrete task.
        //!
        //! @tparam A typelist of concrete task types.
        //! @param[in,out] task The concrete task of whose results we want,
        template <typename ConcreteTasksTypeList,
                  typename LABEL_t,
                  LABEL_t COMMAND_LABEL>
        static auto
        getShareOfTaskReceiverResults(std::shared_ptr<ANANSI::AnansiTask> &task)
        {
            using concrete_task_type = 
                typename  ConcreteTypeForCorrespondingLabel<ConcreteTasksTypeList,LABEL_t,COMMAND_LABEL>::concrete_type;

            using receiver_share_t = 
                typename concrete_task_type:: template MyOwnershipTypes<RECEIVER::OwnershipTypes::SHARETYPE>::TYPE;

            std::shared_ptr<concrete_task_type> concrete_task =
                AnansiTaskUtilities<ANANSI::AnansiTask,concrete_task_type>::asConcreteTask(task);

            receiver_share_t ret_val = concrete_task->shareOwnershipOfResults();

            return ret_val;
        }

        //! Returns a trasfer type of the result of a concrete task.
        //!
        //! @tparam A typelist of concrete task types.
        //! @param[in,out] task The concrete task of whose results we want,
        template <typename ConcreteTasksTypeList,
                  typename LABEL_t,
                  LABEL_t COMMAND_LABEL>
        static auto
        transferTaskReceiverResults(std::shared_ptr<ANANSI::AnansiTask> &task)
        {
            using concrete_task_type = 
                typename  ConcreteTypeForCorrespondingLabel<ConcreteTasksTypeList,LABEL_t,COMMAND_LABEL>::concrete_type;

            using receiver_transfer_t = 
                typename concrete_task_type:: template MyOwnershipTypes<RECEIVER::OwnershipTypes::TRANSFERTYPE>::TYPE;

            std::shared_ptr<concrete_task_type> concrete_task =
                AnansiTaskUtilities<ANANSI::AnansiTask,concrete_task_type>::asConcreteTask(task);

            receiver_transfer_t  ret_val = concrete_task->takeOwnershipOfResults();

            return ret_val;
        }


        template <typename ConcreteTasksTypeList, ANANSI::TaskLabel COMMAND_LABEL>
        static void
        verifyConcreteProductInTypeList()
        {

            // We compute the range of concrete products in ConcreteTasksTypeList.
            constexpr auto nm_products =
                static_cast<MPL::mpl_size_type>(MPL::mpl_size<ConcreteTasksTypeList>::value);

            // This is the lcation of the corresponding concrete product in typelist
            // ConcreteTasksTypeList that has tasklabel COMMAND_LABEL.
            constexpr int concrete_index =
                ANANSI::ReceiverUtilities::getLocationInTypeList<ConcreteTasksTypeList,
                COMMAND_LABEL>();

            // If the corresponding concrete product is not found then abort.
            if constexpr ( not ((0 <= concrete_index ) and (concrete_index < nm_products)) )
            {
                // :TODO:11/15/2022 10:00:29 AM:: Abort program
                // for a nonrecoverable error has occurred.
            }

        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericTaskInvokerUtilities &
        operator=(const GenericTaskInvokerUtilities &other) // assignment operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator

        GenericTaskInvokerUtilities &
        operator=(GenericTaskInvokerUtilities &&other) // assignment-move operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        //! An alias for the concrete task type located at position index.
        //!
        //! @tparam ConcreteTasksTypeList A typelist of concrete task types.
        //! @tparam concrete_index The location of the concrete type in
        //! ConcreteTasksTypeList we desire
        template <typename ConcreteTasksTypeList, MPL::mpl_size_type concrete_index>
        using CONCRETE_TASK_TYPE_AT_INDEX_ =
            MPL::mpl_at_c<ConcreteTasksTypeList,concrete_index>;

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class GenericTaskInvokerUtilities  -----

}; // namespace ANANSI

#endif // ----- #ifndef ANANSI_GenericTaskInvokerUtilities_INC  -----
