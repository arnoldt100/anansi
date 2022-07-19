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

        template <typename ingredient_T>
        void operator()() const
        {
            // auto an_ingredient = ingredients->template giveIngredient<ingredient_T>();
            // a_task_group.addIngredient(std::move(an_ingredient));
            std::cout << "Class TransferIngredients: Transferred ingredient: " << typeid(ingredient_T).name() << std::endl;
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
