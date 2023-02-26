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
#include <string.h>
#include <memory>
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

//! This class provides methods for implementing take actions receiver results.
template <typename T>
class TakeOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<TakeOwnershipPolicy, T>
{
    private:
        using unique_type = typename RECEIVER::ReceiverResultOwnershipPolicy<TakeOwnershipPolicy, T>::unique_type;
        using shared_type = typename RECEIVER::ReceiverResultOwnershipPolicy<TakeOwnershipPolicy, T>::shared_type;

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

        //! Returns a unique_ptr of the receiver results.
        //!
        //! The underlying object of the unique_ptr is copied to an object of
        //! unique_type and returned to the invoker.
        unique_type getCopyOwnershipOfObject(unique_type & my_obj) const
        {
            T* tmp_obj = new T(*my_obj);
            unique_type unique_obj(tmp_obj);
            return unique_obj; 
        }

        //! Returns a unique_ptr of the receiver results.
        //!
        //! The underlying object of the shared_ptr is copied to an object of
        //! unique_type and returned to the invoker.
        unique_type getCopyOwnershipOfObject(shared_type & my_obj) const
        {
            T* tmp_obj = new T(*my_obj);
            unique_type unique_obj(tmp_obj);
            return unique_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! Returns a unique_ptr of the receiver results.
        //!
        //! The underlying object of the unique_ptr is taken over and moved to
        //! an  object of unique_type and returned to the invoker.
        unique_type takeOwnershipOfObject(unique_type & my_obj)
        {
            unique_type unique_obj = std::move(my_obj);
            return unique_obj; 
        }

        //! The take ownership policy doesn't allow a shared_type to be taken over.
        //!
        //! An error is thrown if invoked.
        unique_type takeOwnershipOfObject(shared_type & my_obj)
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<TakeOwnershipPolicy>(my_err_message);
            shared_type unique_obj;
            return unique_obj; 
        }

        //! The take ownership does not allow a unique result to be shared.
        //!
        //! An error is thrown if invoked.
        shared_type shareOwnershipOfObject(unique_type & my_obj) 
        {
            const std::string my_err_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<TakeOwnershipPolicy>(my_err_message);
            shared_type shared_obj;
            return shared_obj; 
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
        // ====================  STATIC       =======================================
        static constexpr std::string_view shared_error_message_ = 
            std::string_view("The TakeOwnershipPolicy does not permit a shared receiver result to be taken over.");

        static constexpr std::string_view take_error_message_ = 
            std::string_view("The TakeOwnershipPolicy does not permit a unique receiver result to be shared.");

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TakeOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_TakeOwnershipPolicy_INC
