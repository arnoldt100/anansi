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

        //! Returns the result of a concrete task.
        //!
        //! @tparam A typelist of concrete task types.
        //! @tparam concrete_index The location of the concrete task type of task 
        //! @param[in,out] task The concrete task of whose results we want,
        template<typename ConcreteTasksTypeList,
                 MPL::mpl_size_type concrete_index>
        static auto getTaskReceiverResults(std::shared_ptr<ANANSI::AnansiTask> & task)
        {
            // Bookmark - stopping here -
            using concrete_task_t = MPL::mpl_at_c<ConcreteTasksTypeList,concrete_index>;

            using return_t = concrete_task_t::task_result_t;

            std::shared_ptr<concrete_task_t> p_concrete =
                        AnansiTaskUtilities<ANANSI::AnansiTask,concrete_task_t>::asConcreteTask(task);

           int ret_val = concrete_index;

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
