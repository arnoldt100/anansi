#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__

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

namespace MPL
{

     // =====================================================================================
     //        Class:  OpNewFactoryUnit
     //  Description:  
     //  =====================================================================================
    template <typename ConcreteProduct, typename Base>
    class OpNewFactoryUnit : Base
    {

        public:
            using AbstractProduct = mpl_front<typename Base::ProductList>;

            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  OpNewFactoryUnit
            //      Method:  OpNewFactoryUnit :: OpNewFactoryUnit
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            OpNewFactoryUnit ()   // constructor
            {
                return;
            }

            OpNewFactoryUnit (const OpNewFactoryUnit & other)   // copy constructor
            {
                if (this != &other)
                {

                }
                return;
            }

            OpNewFactoryUnit (OpNewFactoryUnit && other)   // copy-move constructor
            {
                if (this != &other)
                {

                }
                return;
            }

            virtual ~OpNewFactoryUnit ()  // destructor
            {
                return;
            }

            // ====================  ACCESSORS     =======================================
            ConcreteProduct* DoCreate(mpl_type2type<AbstractProduct>) const
            {
                return new ConcreteProduct;
            }

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            OpNewFactoryUnit& operator= ( const OpNewFactoryUnit &other ) // assignment operator
            {
                if ( this != &other)
                {

                }
                return *this;
            }

            OpNewFactoryUnit& operator= ( OpNewFactoryUnit && other ) // assignment-move operator
            {
                if (this != &other)
                {

                }
                return *this;
            }

        protected:

            using ProductList = mpl_rest<typename Base::ProductList>;

            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            using BaseProductList = typename Base::ProductList;

            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class OpNewFactoryUnit  -----


}; // namespace MPL

#endif // __filepreprocessordefine__
