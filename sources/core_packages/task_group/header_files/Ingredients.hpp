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
class Ingredients
{
    public:
        // ====================  LIFECYCLE     =======================================

        Ingredients ();   // constructor

        Ingredients (const Ingredients & other);   // copy constructor

        Ingredients (Ingredients && other);   // copy-move constructor

        ~Ingredients ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        Ingredients& operator= ( const Ingredients &other ); // assignment operator

        Ingredients& operator= ( Ingredients && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class Ingredients  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_Ingredients_INC  ----- 
