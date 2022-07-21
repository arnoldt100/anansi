#ifndef  ANANSI_TransferIngredient_INC
#define  ANANSI_TransferIngredient_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <iostream>
#include <typeinfo>
#include <cassert>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"

namespace ANANSI
{

// =====================================================================================
//        Class:  TransferIngredients
//  Description:  
//  =====================================================================================
class TransferIngredients
{
    public:
        // ====================  LIFECYCLE     =======================================

        // TransferIngredients ()   // constructor
        // {
        //     return;
        // }

        // TransferIngredients (const TransferIngredients & other)   // copy constructor
        // {
        //     if ( this != &other )
        //     {

        //     }
        //     return;
        // }

        // TransferIngredients (TransferIngredients && other)   // copy-move constructor
        // {
        //     if ( this != &other )
        //     {

        //     }
        //     return;
        // }

        // ~TransferIngredients ()  // destructor
        // {
        //     return;
        // }
        
        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        template <
            typename ingredient_t,
            typename taskgroup_t,
            typename ingredients_t>
        void operator()(std::shared_ptr<typename taskgroup_t::baseclass> a_taskgroup,
                       const std::unique_ptr<ingredients_t> & ingredients) const
        {

            // Assert that the taskgroup and ingredients are not a nullptrs.
            assert(a_taskgroup != nullptr);
            assert(ingredients != nullptr);

            auto an_ingredient = ingredients-> template giveIngredient<ingredient_t>();
            auto derived_taskgroup = std::dynamic_pointer_cast<taskgroup_t>(a_taskgroup);
            derived_taskgroup-> template addIngredient< ingredient_t>(std::move(an_ingredient));
            return;
        }

        TransferIngredients& operator= ( const TransferIngredients &other ) // assignment operator
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
        
}; // -----  end of class TransferIngredients  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_TransferIngredient_INC  ----- 
