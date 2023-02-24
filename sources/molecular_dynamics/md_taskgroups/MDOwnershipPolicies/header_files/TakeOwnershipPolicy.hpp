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
        using top_unique_type = typename RECEIVER::ReceiverResultOwnershipPolicy<TakeOwnershipPolicy, T>::unique_type;
        using top_shared_type = typename RECEIVER::ReceiverResultOwnershipPolicy<TakeOwnershipPolicy, T>::shared_type;

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
        //! top_unique_type and returned to the invoker.
        top_unique_type getCopyOwnershipOfObject(std::unique_ptr<T> & my_obj) const
        {
            T* tmp_obj = new T(*my_obj);
            top_unique_type owned_obj(tmp_obj);
            return owned_obj; 
        }

        //! Returns a unique_ptr of the receiver results.
        //!
        //! The underlying object of the shared_ptr is copied to an object of
        //! top_unique_type and returned to the invoker.
        top_unique_type getCopyOwnershipOfObject(std::shared_ptr<T> & my_obj) const
        {
            T* tmp_obj = new T(*my_obj);
            top_unique_type owned_obj(tmp_obj);
            return owned_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! Returns a unique_ptr of the receiver results.
        //!
        //! The underlying object of the unique_ptr is taken over and moved to
        //! an  object of top_unique_type and returned to the invoker.
        top_unique_type takeOwnershipOfObject(std::unique_ptr<T> & my_obj)
        {
            top_unique_type owned_obj = std::move(my_obj);
            return owned_obj; 
        }

        //! The take ownership policy doesn't allow a shared_ptr to be taken over.
        //!
        //! An error is thrown if invoked.
        top_shared_type takeOwnershipOfObject(std::shared_ptr<T> & my_obj)
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<TakeOwnershipPolicy>(my_err_message);
            top_shared_type owned_obj;
            return owned_obj; 
        }

        //! The take ownership does not allow an object to shared.
        //!
        //! An error is thrown if invoked.
        top_shared_type shareOwnershipOfObject(std::unique_ptr<T> & my_obj) 
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<TakeOwnershipPolicy>(my_err_message);
            top_shared_type owned_obj;
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
        // ====================  STATIC       =======================================
        static constexpr std::string_view shared_error_message_ = 
            std::string_view("The TakeOwnershipPolicy does not permit the shared receiver result to be taken over.");

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TakeOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_TakeOwnershipPolicy_INC
