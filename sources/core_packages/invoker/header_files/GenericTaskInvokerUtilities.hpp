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

        //! An alias for the concrete task type.
        //!
        //! @tparam ConcreteTasksTypeList A typelist of concrete task types.
        //! @tparam concrete_index The location of the concrete type in ConcreteTasksTypeList we desire
        template <typename ConcreteTasksTypeList,
                  MPL::mpl_size_type concrete_index>
        using CONCRETE_TASK_T = MPL::mpl_at_c<ConcreteTasksTypeList,concrete_index>;

        //! An alias for the concrete task result type.
        //!
        //! @tparam ConcreteTasksTypeList A typelist of concrete task types.
        //! @tparam concrete_index The location of the concrete type in ConcreteTasksTypeList we desire.
        template <typename ConcreteTasksTypeList,
                  MPL::mpl_size_type concrete_index>
        using CONCRETE_TASK_RESULT_T = CONCRETE_TASK_T<ConcreteTasksTypeList,concrete_index>::task_result_t;

        //! Modifies the receiver of the concrete type located at concrete_index. 
        template<typename ConcreteTasksTypeList,
                 MPL::mpl_size_type alpha,
                 typename... ReceiverArgsTypes>
        static void modifyTaskReceiver( const MPL::mpl_size_type concrete_index,
                                        std::shared_ptr<ANANSI::AnansiTask> & task,
                                        ReceiverArgsTypes &... receiver_args)
        {
            constexpr auto mx_elements = MPL::mpl_size<ConcreteTasksTypeList>::value; 
            constexpr auto zero = static_cast<MPL::mpl_size_type>( 0 );
            constexpr auto next_alpha = alpha + 1;

            if constexpr ( (zero <= alpha) and (alpha < mx_elements) )
            {
                if (alpha == concrete_index)
                {
                    using concrete_task_t = MPL::mpl_at_c<ConcreteTasksTypeList,alpha>;
                    std::shared_ptr<concrete_task_t> p_concrete = 
                        AnansiTaskUtilities<ANANSI::AnansiTask,concrete_task_t>::asConcreteTask(task);
                    p_concrete->modifyReceiver(receiver_args...);
                }
                else
                {
                    GenericTaskInvokerUtilities::modifyTaskReceiver<ConcreteTasksTypeList,
                                                                    next_alpha,
                                                                    ReceiverArgsTypes...>(concrete_index,
                                                                                          task,
                                                                                          receiver_args...);
                }     
            }

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
            using concrete_task_t = MPL::mpl_at_c<ConcreteTasksTypeList,concrete_index>;

            using return_t = concrete_task_t::task_result_t;

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
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class GenericTaskInvokerUtilities  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_GenericTaskInvokerUtilities_INC  ----- 
