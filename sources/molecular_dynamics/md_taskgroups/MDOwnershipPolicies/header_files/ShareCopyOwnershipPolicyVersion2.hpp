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
#include "BaseReceiverResultOwnershipPolicy.hpp"

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
           typename OwnershipImpl
         >
class ShareCopyOwnershipPolicy : public RECEIVER::BaseReceiverResultOwnershipPolicy<RT,
                                                                                    ShareCopyOwnershipPolicy<RT,OwnershipImpl>, 
                                                                                    OwnershipImpl>
{
    public:
        using copy_type = typename OwnershipImpl::Copytype;
        using shared_type = typename OwnershipImpl::Sharetype;
        using transfer_type = typename OwnershipImpl::Transfertype;

        // ====================  LIFECYCLE     =======================================

        ShareCopyOwnershipPolicy () 
            // constructor
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
        //! The underlying object of the is copied to an object of
        //! copy_type and returned to the invoker.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! returns unique_obj  A object of unique_type that is a copy a_receiver_result.
        template<typename W>
        copy_type copyResult(W const & a_receiver_result) const
        {
            copy_type tmp_obj = std::move(this->myImpl_.copy(a_receiver_result));
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
            transfer_type tmp_obj = OwnershipImpl::throwTransferringError(my_error_message);
            return tmp_obj; 
        }

        //! Returns a  shared_type of the receiver's result,
        //!
        //! The template concept shareOwnershipReceiverResult 
        //! only permits trnasfers of shared_type.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to be shared in its ownership.
        //! returns shared_obj  A object of shared_type that shares a_receiver_result.
        template<typename W>
        shared_type shareOwnershipOfResult(W & a_receiver_result)
        {
            shared_type shared_obj = this->myImpl_.share(a_receiver_result);
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
        OwnershipImpl myImpl_;
}; // -----  end of class ShareCopyOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_ShareCopyOwnershipPolicy_INC
