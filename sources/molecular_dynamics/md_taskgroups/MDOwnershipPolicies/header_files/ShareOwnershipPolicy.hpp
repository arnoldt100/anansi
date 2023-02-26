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
#include <string.h>
#include <utility>
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

//! This class provides methods for implementing share actions receiver results.
template <typename T>
class ShareOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<ShareOwnershipPolicy, T>
{
    private:
        using unique_type = typename RECEIVER::ReceiverResultOwnershipPolicy<ShareOwnershipPolicy, T>::unique_type;
        using shared_type = typename RECEIVER::ReceiverResultOwnershipPolicy<ShareOwnershipPolicy, T>::shared_type;

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

        //! Returns a unique_ptr of the receiver results.
        //!
        //! The underlying object of the unique_ptr is copied to an object of
        //! cop_unique_type and returned to the invoker.
        unique_type getCopyOwnershipOfObject(std::unique_ptr<T> & my_obj) const
        {
            T* tmp_obj = new T(*my_obj);
            unique_type unique_obj(tmp_obj);
            return unique_obj; 
        }

        //! Returns a unique_ptr of the receiver results.
        //!
        //! The underlying object of the shared_ptr is copied to an object of
        //! cop_unique_type and returned to the invoker.
        unique_type getCopyOwnershipOfObject(std::shared_ptr<T> & my_obj) const
        {
            T* tmp_obj = new T(*my_obj);
            unique_type unique_obj(tmp_obj);
            return unique_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! The share ownership policy does not allow an object to taken over.
        //!
        //! An error is thrown if invoked.
        unique_type takeOwnershipOfObject(std::unique_ptr<T> & my_obj)
        {
            const std::string my_err_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<ShareOwnershipPolicy>(my_err_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        //! The share ownership policy does not allow an object to taken over.
        //!
        //! An error is thrown if invoked.
        unique_type takeOwnershipOfObject(std::shared_ptr<T> & my_obj)
        {
            const std::string my_err_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<ShareOwnershipPolicy>(my_err_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        shared_type shareOwnershipPolicy(shared_type & my_obj)
        {
            shared_type shared_obj = my_obj;
            return shared_obj;
        }

        shared_type shareOwnershipPolicy(unique_type & my_obj)
        {
            const std::string my_err_message(share_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<ShareOwnershipPolicy>(my_err_message);
            shared_type shared_obj;
            return shared_obj;
        }


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
        // ====================  STATIC       =======================================
        static constexpr std::string_view take_error_message_ = 
            std::string_view("The ShareOwnershipPolicy does not permit a receiver result to be taken over.");

        static constexpr std::string_view share_error_message_ = 
            std::string_view("The ShareOwnershipPolicy does not permit a unique receiver result to be shared.");

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ShareOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_ShareOwnershipPolicy_INC
