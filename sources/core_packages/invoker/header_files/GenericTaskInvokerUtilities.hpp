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
        static void castAbstractTaskToConcreteTask( const MPL::mpl_size_type concrete_index,
                                                    std::shared_ptr<ANANSI::AnansiTask> & abstract_task,
                                                    ReceiverArgsTypes &... receiver_args)
        {
            constexpr auto mx_elements = MPL::mpl_size<ConcreteTasksTypeList>::value; 
            constexpr auto zero = static_cast<MPL::mpl_size_type>( 0 );
            constexpr auto next_alpha = alpha + 1;
            if constexpr ( (zero <= alpha) and (alpha < mx_elements) )
            {
                if (alpha == concrete_index)
                {
                    std::cout << "Casting abstract task to concrete task at index " << alpha << "." << std::endl;
                }
                else
                {
                    GenericTaskInvokerUtilities::castAbstractTaskToConcreteTask<ConcreteTasksTypeList,
                                                                                next_alpha,
                                                                                ReceiverArgsTypes...>(concrete_index,
                                                                                                      abstract_task,
                                                                                                      receiver_args...);
                }     
            }

            return;
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
