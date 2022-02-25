#ifndef  MOUSEION_ConcreteFactory_INC
#define  MOUSEION_ConcreteFactory_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"
#include "GenerateLinearHierarchy.hpp"
#include "OpNewFactoryUnit.hpp"

namespace MPL {

// =====================================================================================
//        Class:  ConcreteFactory
//  Description:  
//  =====================================================================================
template< typename AbstractFact,
          typename TypeList,
          template <typename,typename> typename Creator = OpNewFactoryUnit
        >
class ConcreteFactory : public GenerateLinearHierarchy<Creator,
                                                       mpl_size<mpl_reverse<TypeList>>,
                                                       mpl_reverse<TypeList>,
                                                       AbstractFact>
{ 
    public:
        using ProductList = typename AbstractFact::ProductList;
        using ConcreteProductList = TypeList;

        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  ConcreteFactory
        //      Method:  ConcreteFactory :: ConcreteFactory
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        ConcreteFactory () // constructor
        {
            return;
        }

        ConcreteFactory (const ConcreteFactory & other) // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        ConcreteFactory (ConcreteFactory && other) // copy-move constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        virtual ~ConcreteFactory () // destructor
        {
           return; 
        }


        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ConcreteFactory& operator= ( const ConcreteFactory &other ) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        }


        ConcreteFactory& operator= ( ConcreteFactory && other ) // assignment-move operator
        {
            if (this != &other)
            {

            }
            return *this;
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ConcreteFactory  -----

}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_ConcreteFactory_INC  ----- 
