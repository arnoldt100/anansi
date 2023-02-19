#ifndef ANANSI_NullOwnershipPolicy_INC
#define ANANSI_NullOwnershipPolicy_INC
//! @file NullOwnershipPolicy.hpp
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
#include "ReceiverResultOwnershipPolicy.hpp"

namespace ANANSI
{

// =====================================================================================
//        Class:  NullOwnershipPolicy
//  Description:  
//  =====================================================================================
template <typename T>
class NullOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<NullOwnershipPolicy, T>
{
    public:
        // ====================  LIFECYCLE     =======================================

        using OBJ_TYPE = T;

        using TOC_TYPE = std::unique_ptr<T>;

        NullOwnershipPolicy ()   // constructor
        {
            return;
        }

        NullOwnershipPolicy (const NullOwnershipPolicy & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        NullOwnershipPolicy (NullOwnershipPolicy && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method NullOwnershipPolicy::NullOwnershipPolicy  -----

        ~NullOwnershipPolicy ()
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

        NullOwnershipPolicy& operator= ( const NullOwnershipPolicy &other) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator


        NullOwnershipPolicy& operator= ( NullOwnershipPolicy && other ) // assignment-move operator
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

}; // -----  end of class NullOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_NullOwnershipPolicy_INC
