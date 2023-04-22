#ifndef RECEIVER_BaseOwnershipImplementation_INC
#define RECEIVER_BaseOwnershipImplementation_INC
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
//        Class:  BaseOwnershipImplementation
//  Description:  
//  =====================================================================================
class BaseOwnershipImplementation
{
    public:
        
        // ====================  STATIC        =======================================

        // ====================  LIFECYCLE     =======================================

        BaseOwnershipImplementation ();   // constructor

        BaseOwnershipImplementation (const BaseOwnershipImplementation & other);   // copy constructor

        BaseOwnershipImplementation (BaseOwnershipImplementation && other);   // copy-move constructor

        ~BaseOwnershipImplementation ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        BaseOwnershipImplementation& operator= ( const BaseOwnershipImplementation &other ); // assignment operator

        BaseOwnershipImplementation& operator= ( BaseOwnershipImplementation && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class BaseOwnershipImplementation  -----


}; // namespace RECEIVER

#endif // RECEIVER_BaseOwnershipImplementation_INC
