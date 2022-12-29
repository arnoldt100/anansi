#ifndef  ANANSI_GenericTaskInvokerFactory_INC
#define  ANANSI_GenericTaskInvokerFactory_INC

//! @file GenericTaskInvokerFactory.hpp
//!
//! A factory class for building GenericTaskInvoker.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "GenericTaskInvoker.hpp"
#include "TaskLabel.hpp"

namespace ANANSI
{

template <typename AbstractProductsTypeList,
          typename ConcreteProductsTypeList,
          typename LABEL_t = ANANSI::TaskLabel<>
         > 
class GenericTaskInvokerFactory
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericTaskInvokerFactory ()   // constructor
        {
            return;
        }

        GenericTaskInvokerFactory (const GenericTaskInvokerFactory & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        GenericTaskInvokerFactory (GenericTaskInvokerFactory && other)    // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ~GenericTaskInvokerFactory ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        template < typename... Types>
        std::shared_ptr<GenericTaskInvoker<AbstractProductsTypeList,
                        ConcreteProductsTypeList,
                        LABEL_t
                       >
        > create_shared_ptr(Types &... args) const
        {
            std::shared_ptr<GenericTaskInvoker<AbstractProductsTypeList,
                                               ConcreteProductsTypeList,
                                               LABEL_t>
                           > p_ptr = 
                std::make_shared<GenericTaskInvoker<AbstractProductsTypeList,
                                                    ConcreteProductsTypeList,
                                                    LABEL_t>
                                >(args...);
            return p_ptr;
        }

        template <typename... Types>
        std::unique_ptr<GenericTaskInvoker<AbstractProductsTypeList,
                                           ConcreteProductsTypeList,
                                           LABEL_t>
                       > create_unique_ptr(Types &... args) const
        {
            std::unique_ptr<GenericTaskInvoker<AbstractProductsTypeList,
                                               ConcreteProductsTypeList,
                                               LABEL_t>
                           > p_ptr = 
                std::make_unique<GenericTaskInvoker<AbstractProductsTypeList,
                                                    ConcreteProductsTypeList,
                                                    LABEL_t>
                                >(args...);
            return p_ptr;
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericTaskInvokerFactory& operator= ( const GenericTaskInvokerFactory &other ) // assignment operator
        {
            if (this != &other)
            {
                 
            }
            return *this;
        } // assignment operator

        GenericTaskInvokerFactory& operator= ( GenericTaskInvokerFactory && other ) // assignment-move operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        
        // ====================  TYPE ALIASES  =======================================  

        using abstract_products_ = AbstractProductsTypeList; 

        using concrete_products_ = ConcreteProductsTypeList;

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class GenericTaskInvokerFactory  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_GenericTaskInvokerFactory_INC  ----- 
