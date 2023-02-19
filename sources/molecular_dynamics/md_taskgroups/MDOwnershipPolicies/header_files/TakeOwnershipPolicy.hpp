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
#include <memory>

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
//        Class:  TakeOwnershipPolicy
//  Description:  
//  =====================================================================================
template <typename T>
class TakeOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<TakeOwnershipPolicy, T>
{
    public:
        // ====================  LIFECYCLE     =======================================

        using OBJ_TYPE = T;

        using TOC_TYPE = std::unique_ptr<T>;

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

        std::unique_ptr<T> takeOwnershipOfObject( T & my_obj)
        {
            std::unique_ptr<T> owned_obj = std::move(my_obj);
            return owned_obj; 
        }

        // ====================  OPERATORS     =======================================

        TakeOwnershipPolicy& operator= ( const TakeOwnershipPolicy &other) // assignment operator
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
