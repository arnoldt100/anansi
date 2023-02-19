#ifndef ANANSI_NullOwnershipPolicy_INC
#define ANANSI_NullOwnershipPolicy_INC
//! @file NullOwnershipPolicy.hpp
//!
//! Contains the declaration for class NullOwnershipPolicy.

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

//! This class provides methods for implementing null actions receiver results.
template <typename T>
class NullOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<NullOwnershipPolicy, T>
{
    public:
        // ====================  LIFECYCLE     =======================================

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

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        std::unique_ptr<T> takeOwnershipOfObject(T & my_obj)
        {
            throw ANANSI::ErrorOwnershipPolicy<NullOwnershipPolicy>();
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! shared.
        std::unique_ptr<T> shareOwnershipOfObject(T & my_obj)
        {
            throw ANANSI::ErrorOwnershipPolicy<NullOwnershipPolicy>();
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }
        
        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! copied.
        std::unique_ptr<T> copyOwnershipOfObject(T & my_obj)
        {
            throw ANANSI::ErrorOwnershipPolicy<NullOwnershipPolicy>();
            std::unique_ptr<T> owned_obj;
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
