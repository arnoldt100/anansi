#ifndef ANANSI_ShareCopyOwnershipPolicy_INC
#define ANANSI_ShareCopyOwnershipPolicy_INC
//! @file ShareCopyOwnershipPolicy.hpp
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

//! This concrete policy class implements shared behaviours with respect to the receiver's result.
//! 
//! The ShareCopyOwnershipPolicy implements the following constraints
//! on the receiver's result:
//! no copying of receiver's result.
//! sharing 
//! no transferring ownership
//!
//! @tparam RT The underlying type of the receiver's result.
template <typename T>
class ShareCopyOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<ShareCopyOwnershipPolicy, T>
{
    public:
        using unique_type = typename RECEIVER::ReceiverResultOwnershipPolicy<ShareCopyOwnershipPolicy, T>::unique_type;
        using shared_type = typename RECEIVER::ReceiverResultOwnershipPolicy<ShareCopyOwnershipPolicy, T>::shared_type;

        // ====================  LIFECYCLE     =======================================

        ShareCopyOwnershipPolicy ()   // constructor
        {
            return;
        }

        ShareCopyOwnershipPolicy (const ShareCopyOwnershipPolicy & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ShareCopyOwnershipPolicy (ShareCopyOwnershipPolicy && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method ShareCopyOwnershipPolicy::ShareCopyOwnershipPolicy  -----

        ~ShareCopyOwnershipPolicy ()
        {
            return;
        };  // destructor

        // ====================  ACCESSORS     =======================================

        //! Returns a unique_type of the receiver results.
        //!
        //! The underlying object of the unique_type is copied to an object of
        //! unique_type and returned to the invoker.
        //!
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! returns unique_obj  A object of unique_type that is a copy a_receiver_result.
        unique_type copyResult(unique_type const & a_receiver_result) const
        {
            T* tmp_obj = new T(*a_receiver_result);
            unique_type unique_obj(tmp_obj);
            return unique_obj; 
        }

        //! Returns a unique_type of the receiver results.
        //!
        //! The underlying object of the shared_type is copied to an object of
        //! unique_type and returned to the invoker.
        //!
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! returns unique_obj  A object of unique_type that is a copy a_receiver_result.
        unique_type copyResult(shared_type const & a_receiver_result) const
        {
            T* tmp_obj = new T(*a_receiver_result);
            unique_type unique_obj(tmp_obj);
            return unique_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! Throws runtime error if invoked.
        //!
        //! The ShareCopyOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        //!
        //! @param[in] a_receiver_result The receiver result to transfer its ownership.
        //! @throws ErrorOwnershipPolicy<ShareCopyOwnershipPolicy>
        unique_type transferOwnershipOfResult(unique_type & a_receiver_result)
        {
            const std::string my_error_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<ShareCopyOwnershipPolicy>(my_error_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The ShareCopyOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        //!
        //! @param[in] a_receiver_result The receiver result to transfer its ownership.
        //! @throws ErrorOwnershipPolicy<ShareCopyOwnershipPolicy>
        unique_type transferOwnershipOfResult(shared_type & a_receiver_result)
        {
            const std::string my_error_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<ShareCopyOwnershipPolicy>(take_error_message_);
            unique_type unique_obj;
            return unique_obj; 
        }

        //! Returns a  shared_type of the receiver's result,
        //!
        //! @param[in] a_receiver_result The receiver result to be shared in its ownership.
        //! returns shared_obj  A object of shared_type that shares a_receiver_result.
        shared_type shareOwnershipReceiverResult(shared_type & a_receiver_result)
        {
            shared_type shared_obj = a_receiver_result;
            return shared_obj;
        }

        //! Throws runtime error if invoked.
        //!
        //! The ShareCopyOwnershipPolicy doesn't permit sharing of an object of
        //! unique_type.
        //!
        //! @param[in] a_receiver_result The receiver result to be shared in its
        //! ownership.
        shared_type shareOwnershipReceiverResult(unique_type & my_obj)
        {
            const std::string my_err_message(share_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<ShareCopyOwnershipPolicy>(my_err_message);
            shared_type shared_obj;
            return shared_obj;
        }


        // ====================  OPERATORS     =======================================

        ShareCopyOwnershipPolicy& operator= ( const ShareCopyOwnershipPolicy &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator


        ShareCopyOwnershipPolicy& operator= ( ShareCopyOwnershipPolicy && other ) // assignment-move operator
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
        static constexpr std::string_view share_error_message_ = 
            std::string_view("The ShareCopyOwnershipPolicy does not permit a receiver result of unique_type to be shared.");

        static constexpr std::string_view take_error_message_ = 
            std::string_view("The ShareCopyOwnershipPolicy does not permit a receiver result to be taken over.");

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ShareCopyOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_ShareCopyOwnershipPolicy_INC
