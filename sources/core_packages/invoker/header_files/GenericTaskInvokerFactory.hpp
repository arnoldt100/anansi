#ifndef  ANANSI_GenericTaskInvokerFactory_INC
#define  ANANSI_GenericTaskInvokerFactory_INC

//! @file GenericTaskInvokerFactory.hpp
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

namespace ANANSI
{

template <typename AbstractProductsTypeList,typename ConcreteProductsTypeList>
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
