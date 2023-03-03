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
#include "OwnershipImpl1.hpp"
#include "ErrorOwnershipPolicy.hpp"
#include "ReceiverResultOwnershipPolicy.hpp"

namespace ANANSI
{

//! This concrete policy class implements shared behaviours with respect to the receiver's result.
//! 
//! The ShareCopyOwnershipPolicy implements the following constraints
//! on the receiver's result:
//! copying of receiver's result.
//! sharing of receiver's result.
//! no transferring ownership
//!
//! @tparam RT The underlying type of the receiver's result.
template < typename RT,
           template <typename> typename OwnershipImpl = OwnershipImpl1 
         >
class ShareCopyOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<ShareCopyOwnershipPolicy<RT,OwnershipImpl>, OwnershipImpl, RT>
{
    public:
        using basetype = RECEIVER::ReceiverResultOwnershipPolicy<ShareCopyOwnershipPolicy<RT,OwnershipImpl>, OwnershipImpl, RT>;
        using copy_type = typename basetype::copy_type;
        using shared_type = typename basetype::shared_type;
        using transfer_type = typename basetype::transfer_type;
        using is_share_copy_type_same = typename std::is_same<shared_type,copy_type>::value;
        using is_share_transfer_type_same = typename std::is_same<shared_type,transfer_type>::value;
        using is_copy_transfer_type_same = typename std::is_same<copy_type,transfer_type>::value;

        // ====================  LIFECYCLE     =======================================

        ShareCopyOwnershipPolicy () // constructor
        {
            return;
        }

        ShareCopyOwnershipPolicy (const ShareCopyOwnershipPolicy & other) // copy constructor
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
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! returns unique_obj  A object of unique_type that is a copy a_receiver_result.
        template<typename W>
        copy_type copyResult(W const & a_receiver_result) const
        {
            copy_type tmp_obj = std::move(OwnershipImpl<RT>::copy(a_receiver_result));
            return tmp_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! Throws runtime error if invoked.
        //!
        //! The ShareCopyOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to transfer its ownership.
        //! @throws ErrorOwnershipPolicy<ShareCopyOwnershipPolicy>
        template<typename W>
        transfer_type transferOwnershipOfResult(W & a_receiver_result)
        {
            const std::string my_error_message(take_error_message_);
            transfer_type tmp_obj = OwnershipImpl<RT>:: template throwTransferringError<ShareCopyOwnershipPolicy>(my_error_message);
            return tmp_obj; 
        }

        //! Returns a  shared_type of the receiver's result,
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to be shared in its ownership.
        //! returns shared_obj  A object of shared_type that shares a_receiver_result.
        shared_type shareOwnershipReceiverResult(shared_type & a_receiver_result)
        {
            shared_type shared_obj = a_receiver_result;
            return shared_obj;
        }

        //! Throws runtime error if invoked.
        //!
        //! The ShareCopyOwnershipPolicy doesn't permit sharing of an reciever result of
        //! copy_type or transfer_type.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to be shared in its
        //! ownership.
        template<typename W,
                 typename = std::enable_if< std::is_same<W,copy_type>::value || std::is_same<W,transfer_type>::value> 
                >
        shared_type shareOwnershipReceiverResult(W & my_obj)
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
