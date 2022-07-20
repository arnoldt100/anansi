#ifndef  ANANSI_TransferIngredient_INC
#define  ANANSI_TransferIngredient_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <iostream>
#include <typeinfo>

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

            auto downcastedPtr = std::dynamic_pointer_cast<taskgroup_t>(a_taskgroup);
            MPL::mpl_typelist<ingredient_t> dummy_t;
            // auto an_ingredient = ingredients->giveIngredient__(dummy_t);
            auto an_ingredient = ingredients-> template giveIngredient<ingredient_t>();
            downcastedPtr-> template addIngredient<ingredient_t>(std::move(an_ingredient));
            std::cout << "Class TransferIngredients: Transferred ingredient: " << typeid(ingredient_t).name() << std::endl;
            return;
        }

        TransferIngredients& operator= ( const TransferIngredients &other ) // assignment operator
        { 
            if ( this != &other )
            {

            }
            return *this;
        }

        // TransferIngredients& operator=( TransferIngredients && other ) // assignment-move operator
        // {
        //     if ( this != &other ) 
        //     {

        //     }
        //     return *this;
        // }


    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        
}; // -----  end of class TransferIngredients  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_TransferIngredient_INC  ----- 
