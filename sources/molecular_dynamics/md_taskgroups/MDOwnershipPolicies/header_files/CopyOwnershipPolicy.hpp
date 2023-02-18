#ifndef ANANSI_CopyOwnershipPolicy_INC
#define ANANSI_CopyOwnershipPolicy_INC
//! @file CopyOwnershipPolicy.hpp
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
//        Class:  CopyOwnershipPolicy
//  Description:  
//  =====================================================================================
template <typename T>
class CopyOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<CopyOwnershipPolicy, T>
{
    public:
        // ====================  LIFECYCLE     =======================================

        CopyOwnershipPolicy ()   // constructor
        {
            return;
        }

        CopyOwnershipPolicy (const CopyOwnershipPolicy & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        CopyOwnershipPolicy (CopyOwnershipPolicy && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method CopyOwnershipPolicy::CopyOwnershipPolicy  -----

        ~CopyOwnershipPolicy ()
        {
            return;
        };  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        CopyOwnershipPolicy& operator= ( const CopyOwnershipPolicy &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator


        CopyOwnershipPolicy& operator= ( CopyOwnershipPolicy && other ) // assignment-move operator
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

}; // -----  end of class CopyOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_CopyOwnershipPolicy_INC
