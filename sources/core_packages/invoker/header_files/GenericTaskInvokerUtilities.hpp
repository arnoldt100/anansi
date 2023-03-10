#ifndef  ANANSI_GenericTaskInvokerUtilities_INC
#define  ANANSI_GenericTaskInvokerUtilities_INC

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
#include "AnansiTask.h"
#include "AnansiTaskUtilities.hpp"
#include "MPLAliases.hpp"
#include "ReceiverUtilities.hpp"

namespace ANANSI
{

class GenericTaskInvokerUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericTaskInvokerUtilities ()   // constructor
        {
            return;
        }

        GenericTaskInvokerUtilities (const GenericTaskInvokerUtilities & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        GenericTaskInvokerUtilities (GenericTaskInvokerUtilities && other)   // copy-move constructor
        {
            if (this != &other)
            {
        
            }
            return;
        }

        ~GenericTaskInvokerUtilities ()  // destructor
        {
            return;
        }

        // ====================  STATIC        =======================================

        //! Modifies the receiver of the concrete type located at concrete_index. 
        template<typename ConcreteTasksTypeList,
                 MPL::mpl_size_type concrete_index,
                 typename... ReceiverArgsTypes>
        static void modifyTaskReceiver( std::shared_ptr<ANANSI::AnansiTask> & task,
                                        ReceiverArgsTypes &... receiver_args)
        {
            using concrete_task_t = 
                GenericTaskInvokerUtilities::CONCRETE_TASK_TYPE_AT_INDEX_<ConcreteTasksTypeList,concrete_index>;
            std::shared_ptr<concrete_task_t> p_concrete = 
                AnansiTaskUtilities<ANANSI::AnansiTask,concrete_task_t>::asConcreteTask(task);
            p_concrete->modifyReceiver(receiver_args...);
            return;
        }

        //! Returns a copy of the result of a concrete task.
        //!
        //! @tparam A typelist of concrete task types.
        //! @tparam concrete_index The location of the concrete task type of task 
        //! @param[in,out] task The concrete task of whose results we want,
        template<typename ConcreteTasksTypeList,
                 MPL::mpl_size_type concrete_index>
        static auto getCopyOfTaskReceiverResults(std::shared_ptr<ANANSI::AnansiTask> & task)
        {
            using concrete_task_t = 
                GenericTaskInvokerUtilities::CONCRETE_TASK_TYPE_AT_INDEX_<ConcreteTasksTypeList,concrete_index>;
            std::shared_ptr<concrete_task_t> p_concrete =
                        AnansiTaskUtilities<ANANSI::AnansiTask,concrete_task_t>::asConcreteTask(task);

            auto ret_val = p_concrete->getCopyOfResults();

            return ret_val;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericTaskInvokerUtilities& operator= ( const GenericTaskInvokerUtilities &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        GenericTaskInvokerUtilities& operator= ( GenericTaskInvokerUtilities && other ) // assignment-move operator
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
        //! @tparam concrete_index The location of the concrete type in ConcreteTasksTypeList we desire
        template <typename ConcreteTasksTypeList,
                  MPL::mpl_size_type concrete_index>
        using CONCRETE_TASK_TYPE_AT_INDEX_ = MPL::mpl_at_c<ConcreteTasksTypeList,concrete_index>;

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class GenericTaskInvokerUtilities  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_GenericTaskInvokerUtilities_INC  ----- 
