#ifndef ANANSI_ShareOwnershipPolicy_INC
#define ANANSI_ShareOwnershipPolicy_INC
//! @file ShareOwnershipPolicy.hpp
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
#include "ErrorOwnershipPolicy.hpp"
#include "ReceiverResultOwnershipPolicy.hpp"

namespace ANANSI
{

// =====================================================================================
//        Class:  ShareOwnershipPolicy
//  Description:  
//  =====================================================================================
template <typename T>
class ShareOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<ShareOwnershipPolicy, T>
{
    public:
        // ====================  LIFECYCLE     =======================================

        ShareOwnershipPolicy ()   // constructor
        {
            return;
        }

        ShareOwnershipPolicy (const ShareOwnershipPolicy & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ShareOwnershipPolicy (ShareOwnershipPolicy && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method ShareOwnershipPolicy::ShareOwnershipPolicy  -----

        ~ShareOwnershipPolicy ()
        {
            return;
        };  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ShareOwnershipPolicy& operator= ( const ShareOwnershipPolicy &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator


        ShareOwnershipPolicy& operator= ( ShareOwnershipPolicy && other ) // assignment-move operator
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

}; // -----  end of class ShareOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_ShareOwnershipPolicy_INC
