#ifndef RECEIVER_DefaultOwnershipMethods_INC
#define RECEIVER_DefaultOwnershipMethods_INC
//! @file __filename__
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace RECEIVER
{

// =====================================================================================
//        Class:  DefaultOwnershipMethods
//  Description:  
//  =====================================================================================
class DefaultOwnershipMethods
{
    public:
        // ====================  LIFECYCLE     =======================================

        DefaultOwnershipMethods ();   // constructor

        DefaultOwnershipMethods (const DefaultOwnershipMethods & other);   // copy constructor

        DefaultOwnershipMethods (DefaultOwnershipMethods && other);   // copy-move constructor

        ~DefaultOwnershipMethods ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        DefaultOwnershipMethods& operator= ( const DefaultOwnershipMethods &other ); // assignment operator

        DefaultOwnershipMethods& operator= ( DefaultOwnershipMethods && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class DefaultOwnershipMethods  -----


}; // namespace RECEIVER

#endif // RECEIVER_DefaultOwnershipMethods_INC
