#ifndef ANANSI_NullOwnershipPolicyVersion2_INC
#define ANANSI_NullOwnershipPolicyVersion2_INC
//! @file NullOwnershipPolicyVersion2.hpp

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
#include "BaseOwnershipImplementation.h"

namespace ANANSI
{

//! This concrete policy class implements null behaviours with respect to the receiver's's result.
//! 
//! The NullOwnershipPolicyVersion2 implements the following constraints
//! on the receiver's result:
//! * no copying
//! * no sharing 
//! * no transferring ownership
//!
//! @tparam RT The underlying type of the receiver's result.
//! @tparam OwnershipImpl The implementation of copying, sharing and transferring the receiver's result.
template <typename RT,
          typename OwnershipImpl
         >
class NullOwnershipPolicyVersion2 : public RECEIVER::BaseReceiverResultOwnershipPolicy<RT,
                                                                                       NullOwnershipPolicyVersion2<RT,OwnershipImpl>,
                                                                                       OwnershipImpl>
{
    public:

        using copy_type = typename OwnershipImpl::Copytype;
        using shared_type = typename OwnershipImpl::Sharetype;
        using transfer_type = typename OwnershipImpl::Transfertype;

        // ====================  LIFECYCLE     =======================================

        NullOwnershipPolicyVersion2 ()   // constructor
        {
            return;
        }

        NullOwnershipPolicyVersion2 (const NullOwnershipPolicyVersion2 & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        NullOwnershipPolicyVersion2 (NullOwnershipPolicyVersion2 && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method NullOwnershipPolicyVersion2::NullOwnershipPolicyVersion2  -----

        ~NullOwnershipPolicyVersion2 ()
        {
            return;
        };  // destructor

        // ====================  ACCESSORS     =======================================
        
        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicyVersion2 doesn't allow the receiver's results to be
        //! copied.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @throws ErrorOwnershipPolicy<NullOwnershipPolicyVersion2>
        template<typename W>
        copy_type copyResult(W const & a_receiver_result) const
        {
            const std::string my_error_message(copy_error_message_);
            copy_type tmp_obj = OwnershipImpl::throwCopyingError(my_error_message);
            return tmp_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicyVersion2 doesn't allow the receiver results to be
        //! taken over.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to transfer its ownership.
        //! @throws ErrorOwnershipPolicy<NullOwnershipPolicyVersion2>
        template<typename W>
        transfer_type transferOwnershipOfResult(W & a_receiver_result)
        {
            const std::string my_error_message(take_error_message_);
            transfer_type tmp_obj = OwnershipImpl::throwTransferringError(my_error_message);
            return tmp_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicyVersion2 doesn't allow the receiver results to be
        //! shared.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<NullOwnershipPolicyVersion2>
        template<typename W>
        shared_type shareOwnershipOfResult(W & a_receiver_result)
        {
            const std::string my_error_message(shared_error_message_);
            shared_type tmp_obj = OwnershipImpl::throwSharingError(my_error_message);
            return tmp_obj; 
        }

        // ====================  OPERATORS     =======================================

        NullOwnershipPolicyVersion2& operator= ( const NullOwnershipPolicyVersion2 &other) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        NullOwnershipPolicyVersion2& operator= ( NullOwnershipPolicyVersion2 && other ) // assignment-move operator
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
            std::string_view("The NullOwnershipPolicyVersion2 does not permit the receiver result to be shared.");

        static constexpr std::string_view take_error_message_ = 
            std::string_view("The NullOwnershipPolicyVersion2 does not permit the receiver result to be taken over.");

        static constexpr std::string_view copy_error_message_ = 
            std::string_view("The NullOwnershipPolicyVersion2 does not permit the receiver result to be copied.");


        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class NullOwnershipPolicyVersion2  -----


}; // namespace ANANSI

#endif // ANANSI_NullOwnershipPolicyVersion2_INC
