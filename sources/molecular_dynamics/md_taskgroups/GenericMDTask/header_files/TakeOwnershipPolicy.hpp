#ifndef ANANSI_TakeOwnershipPolicy_INC
#define ANANSI_TakeOwnershipPolicy_INC
//! @file TakeOwnershipPolicy.hpp
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
#include "ReceiverResultOwnershipPolicy.hpp"

namespace ANANSI
{

// =====================================================================================
//        Class:  TakeOwnershipPolicy
//  Description:  
//  =====================================================================================
template <typename T>
class TakeOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<TakeOwnershipPolicy, T>
{
    public:
        // ====================  LIFECYCLE     =======================================

        TakeOwnershipPolicy ()   // constructor
        {
            return;
        }

        TakeOwnershipPolicy (const TakeOwnershipPolicy & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        TakeOwnershipPolicy (TakeOwnershipPolicy && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method TakeOwnershipPolicy::TakeOwnershipPolicy  -----

        ~TakeOwnershipPolicy ()
        {
            return;
        };  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TakeOwnershipPolicy& operator= ( const TakeOwnershipPolicy &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator


        TakeOwnershipPolicy& operator= ( TakeOwnershipPolicy && other ) // assignment-move operator
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

}; // -----  end of class TakeOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_TakeOwnershipPolicy_INC
