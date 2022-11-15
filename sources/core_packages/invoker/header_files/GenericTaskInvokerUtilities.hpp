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

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
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
                 typename index_t = MPL::mpl_size_type>
        static void castAbstractTaskToConcreteTask( const index_t concrete_index)
        {
            using mx_elements = MPL::mpl_size<ConcreteTasksTypeList>; 
            using zero_t = MPL::mpl_size<MPL::mpl_typelist<>>;
            constexpr auto next_alpha = alpha + 1;
            if constexpr ( (zero_t::value <= alpha) and (alpha < mx_elements::value) )
            {
                if (alpha == concrete_index)
                {
                    std::cout << "Casting abstract task to concrete task at index " << alpha << "." << std::endl;
                }
                else
                {
                    GenericTaskInvokerUtilities::castAbstractTaskToConcreteTask<ConcreteTasksTypeList,
                                                                                next_alpha>(concrete_index);
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
