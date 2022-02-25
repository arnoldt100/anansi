#ifndef  MOUSEION_AbstractFactory_INC
#define  MOUSEION_AbstractFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "GenerateScatteredHierarchy.hpp"
#include "AbstractFactoryUnit.hpp"

namespace MPL
{

// =====================================================================================
//        Class:  AbstractFactory
//  Description:  
//  =====================================================================================
template <
           typename L,
           template<typename> typename Unit=AbstractFactoryUnit
         >
class AbstractFactory : public GenerateScatteredHierarchy<Unit, mpl_size<L>,L>
{
    using ProductList = L;

    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  AbstractFactory
        //      Method:  AbstractFactory :: AbstractFactory
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        AbstractFactory () // constructor
        {
            return;
        }

        AbstractFactory (const AbstractFactory & other) // copy constructor
        {
            return;
        }

        AbstractFactory (AbstractFactory && other)  // copy-move constructor
        {
            return;
        }

        virtual ~AbstractFactory () // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        template <typename T2> 
        T2* Create()
        {
            Unit<T2> & unit = *this;
            return unit.DoCreate(mpl_type2type<T2>());
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        AbstractFactory& operator= ( const AbstractFactory &other ) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator


        AbstractFactory& operator= ( AbstractFactory && other ) // assignment-move operator
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

}; // -----  end of class AbstractFactory  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_AbstractFactory_INC  ----- 
