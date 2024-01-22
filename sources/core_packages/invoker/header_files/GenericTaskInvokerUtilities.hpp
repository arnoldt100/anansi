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
#include "GenericTaskUtilities.hpp"
#include "OwnershipTypes.hpp"

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
                typename  ConcreteTypeForCorrespondingLabel<ConcreteTasksTypeList,LABEL_t,COMMAND_LABEL>::TYPE;

            using receiver_copy_t = typename  GenericTaskInvokerOwnershipTypes<RECEIVER::OwnershipTypes::COPYTYPE,
                                                                               LABEL_t,
                                                                               COMMAND_LABEL,
                                                                               ConcreteTasksTypeList>::TYPE;

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
                typename  ConcreteTypeForCorrespondingLabel<ConcreteTasksTypeList,LABEL_t,COMMAND_LABEL>::TYPE;

            using receiver_share_t =
                typename  GenericTaskInvokerOwnershipTypes<RECEIVER::OwnershipTypes::SHARETYPE,
                                                           LABEL_t,
                                                           COMMAND_LABEL,
                                                           ConcreteTasksTypeList>::TYPE;



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
                typename ConcreteTypeForCorrespondingLabel<ConcreteTasksTypeList,LABEL_t,COMMAND_LABEL>::TYPE;

            using receiver_transfer_t = 
                typename  GenericTaskInvokerOwnershipTypes<RECEIVER::OwnershipTypes::TRANSFERTYPE,
                                                           LABEL_t,
                                                           COMMAND_LABEL,
                                                           ConcreteTasksTypeList>::TYPE;

            std::shared_ptr<concrete_task_type> concrete_task =
                AnansiTaskUtilities<ANANSI::AnansiTask,concrete_task_type>::asConcreteTask(task);

            receiver_transfer_t  ret_val = concrete_task->takeOwnershipOfResults();

            return ret_val;
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
