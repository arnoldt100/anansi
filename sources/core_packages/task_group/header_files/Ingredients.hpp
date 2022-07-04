#ifndef  ANANSI_Ingredients_INC
#define  ANANSI_Ingredients_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include<memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

// =====================================================================================
//        Class:  Ingredients
//  Description:  
//  =====================================================================================
template <typename T>
class Ingredients
{
    public:
        // ====================  LIFECYCLE     =======================================

        Ingredients ()   // constructor
        {
            return;
        }

        Ingredients (const Ingredients & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        Ingredients (Ingredients && other)   // copy-move constructor
        {
            if (this != &other)
            {
                *this = std::move(other);
            }
            return;
        }		// -----  end of method Ingredients::Ingredients  -----

        ~Ingredients ()  // destructor
        {
            return;
        }


        // ====================  ACCESSORS     =======================================
        template <typename IngredientType>
        IngredientType getIngredient()
        {
            IngredientType x;
            return x;
        }


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        Ingredients& operator= ( const Ingredients &other ) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator


        Ingredients& operator= ( Ingredients && other ) // assignment-move operator
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
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class Ingredients  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_Ingredients_INC  ----- 
