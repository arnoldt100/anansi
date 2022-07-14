#ifndef  ANANSI_TransferIngredient_INC
#define  ANANSI_TransferIngredient_INC

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

// =====================================================================================
//        Class:  TransferIngredient
//  Description:  
//  =====================================================================================
class TransferIngredient
{
    public:
        // ====================  LIFECYCLE     =======================================

        TransferIngredient ();   // constructor

        TransferIngredient (const TransferIngredient & other);   // copy constructor

        TransferIngredient (TransferIngredient && other);   // copy-move constructor

        ~TransferIngredient ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TransferIngredient& operator= ( const TransferIngredient &other ); // assignment operator

        TransferIngredient& operator= ( TransferIngredient && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TransferIngredient  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_TransferIngredient_INC  ----- 
