#ifndef  MOUSEION_GenerateScatteredHierarchy_INC
#define  MOUSEION_GenerateScatteredHierarchy_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <typeinfo>

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
    //        Class:  GenerateScatteredHierarchy
    //  Description:  Primary template.
    //  =====================================================================================
    template
    <
        template<typename> typename Unit, 
        typename TypeListSize,
        typename L
    >
    class GenerateScatteredHierarchy : public Unit<mpl_front<L>>,
                                       public mpl_size<L>,
                                       public GenerateScatteredHierarchy<Unit,mpl_rest_size<L>,mpl_rest<L>> 
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  GenerateScatteredHierarchy
            //      Method:  GenerateScatteredHierarchy :: GenerateScatteredHierarchy
            // 
            //--------------------------------------------------------------------------------------
            GenerateScatteredHierarchy ()
            {
                return;
            }   // constructor

            GenerateScatteredHierarchy (const GenerateScatteredHierarchy & other)   // copy constructor
            {
                return;
            }

            GenerateScatteredHierarchy (GenerateScatteredHierarchy && other)   // copy-move constructor
            {
                return;
            }

            virtual ~GenerateScatteredHierarchy ()  // destructor
            {
                return;
            }

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            GenerateScatteredHierarchy& operator= ( const GenerateScatteredHierarchy &other ) // assignment operator
            {
                if ( this != &other )
                {

                }
                return *this;
            }

            GenerateScatteredHierarchy& operator= ( GenerateScatteredHierarchy && other ) // assignment-move operator
            {
                if ( this != &other )
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
            L my_typelist_;

    }; // -----  end of class GenerateScatteredHierarchy  -----


    template
    <
        template<typename> typename Unit, 
        typename L
    >
    class GenerateScatteredHierarchy<Unit,mpl_size_0, L> 
    {
        public: 
            GenerateScatteredHierarchy ()
            {
                return;
            }   // constructor

    };

}; // namespace MPL


#endif   // ----- #ifndef MOUSEION_GenerateScatteredHierarchy_INC  ----- 
