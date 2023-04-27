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
#include "BaseReceiverResultOwnershipPolicy.hpp"
#include "OwnershipImpl1.hpp"

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
           typename OwnershipImpl
         >
class ShareOwnershipPolicy : public RECEIVER::BaseReceiverResultOwnershipPolicy<RT,
                                                                                ShareOwnershipPolicy<RT,OwnershipImpl>,
                                                                                OwnershipImpl>
{
    public:
        using copy_type = typename OwnershipImpl::Copytype;
        using shared_type = typename OwnershipImpl::Sharetype;
        using transfer_type = typename OwnershipImpl::Transfertype;

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
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @throws ErrorOwnershipPolicy<ShareOwnershipPolicy>
        template<typename W>
        copy_type copyResult(W & a_receiver_result) const
        {
            const std::string my_error_message(copy_error_message_);
            copy_type tmp_obj =  OwnershipImpl::throwTransferringError(my_error_message)(my_error_message);
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
        OwnershipImpl myImpl_;

}; // -----  end of class ShareOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_ShareOwnershipPolicy_INC
