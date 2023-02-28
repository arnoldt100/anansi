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
#include "Ownership1.hpp"
#include "ErrorOwnershipPolicy.hpp"
#include "ReceiverResultOwnershipPolicy.hpp"

namespace ANANSI
{

//! This concrete policy class implements shared behaviours with respect to the receiver's result.
//! 
//! The ShareOwnershipPolicy implements the following constraints
//! on the receiver's result:
//! no copying of receiver's result.
//! sharing 
//! no transferring ownership
//!
//! @tparam RT The underlying type of the receiver's result.
template < typename RT,
           template <typename> typename OwnershipPolicy = Ownership1 
         >
class ShareOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<ShareOwnershipPolicy<RT,OwnershipPolicy>, OwnershipPolicy, RT>
{
    public:
        using basetype = RECEIVER::ReceiverResultOwnershipPolicy<ShareOwnershipPolicy<RT,OwnershipPolicy>, OwnershipPolicy, RT>;
        using unique_type = typename basetype::Uniquetype;
        using shared_type = typename basetype::Sharedtype;

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

        //! Throws runtime error if invoked.
        //!
        //! The SharedOwnershipPolicy doesn't allow the receiver's results to be
        //! copied.
        //!
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @throws ErrorOwnershipPolicy<ShareOwnershipPolicy>
        unique_type copyResult(unique_type & my_obj) const
        {
            const std::string my_error_message(copy_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<ShareOwnershipPolicy>(my_error_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The SharedOwnershipPolicy doesn't allow the receiver's results to be
        //! copied.
        //!
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @throws ErrorOwnershipPolicy<ShareOwnershipPolicy>
        unique_type copyResult(shared_type & my_obj) const
        {
            const std::string my_error_message(copy_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<ShareOwnershipPolicy>(my_error_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! Throws runtime error if invoked.
        //!
        //! The ShareOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        //!
        //! @param[in] a_receiver_result The receiver result to transfer its ownership.
        //! @throws ErrorOwnershipPolicy<ShareOwnershipPolicy>
        unique_type transferOwnershipOfResult(unique_type & a_receiver_result)
        {
            const std::string my_error_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<ShareOwnershipPolicy>(my_error_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The ShareOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        //!
        //! @param[in] a_receiver_result The receiver result to transfer its ownership.
        //! @throws ErrorOwnershipPolicy<ShareOwnershipPolicy>
        unique_type transferOwnershipOfResult(shared_type & a_receiver_result)
        {
            const std::string my_error_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<ShareOwnershipPolicy>(take_error_message_);
            unique_type unique_obj;
            return unique_obj; 
        }

        //! Returns a  shared_type of the receiver's result,
        //!
        //! @param[in] a_receiver_result The receiver result to be shared in its ownership.
        //! returns shared_obj  A object of shared_type that shares a_receiver_result.
        shared_type shareOwnershipReceiverResult(shared_type & a_receiver_result)
        {
            shared_type shared_obj = OwnershipPolicy<RT>::share(a_receiver_result);
            return shared_obj;
        }

        //! Throws runtime error if invoked.
        //!
        //! The ShareOwnershipPolicy doesn't permit sharing of an object of
        //! unique_type.
        //!
        //! @param[in] a_receiver_result The receiver result to be shared in its
        //! ownership.
        shared_type shareOwnershipReceiverResult(unique_type & my_obj)
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
        static constexpr std::string_view share_error_message_ = 
            std::string_view("The ShareOwnershipPolicy does not permit a receiver result of unique_type to be shared.");

        static constexpr std::string_view take_error_message_ = 
            std::string_view("The ShareOwnershipPolicy does not permit a receiver result to be taken over.");

        static constexpr std::string_view copy_error_message_ = 
            std::string_view("The ShareOwnershipPolicy does not permit a receiver result to be copied.");

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ShareOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_ShareOwnershipPolicy_INC
