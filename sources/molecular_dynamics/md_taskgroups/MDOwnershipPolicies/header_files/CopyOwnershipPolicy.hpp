#ifndef ANANSI_CopyOwnershipPolicy_INC
#define ANANSI_CopyOwnershipPolicy_INC
//! @file CopyOwnershipPolicy.hpp

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

namespace ANANSI
{

//! This concrete policy class implements copy behaviours with respect to the receiver's's result.
//! 
//! The CopyOwnershipPolicy implements the following constraints
//! on the receiver's result:
//! * copying of receiver's result
//! * no sharing of ownership
//! * no transferring ownership
//! @tparam OwnershipImpl The implementation of copying, sharing and transferring the receiver's result.
template < typename OwnershipImpl >
class CopyOwnershipPolicy : public RECEIVER::BaseReceiverResultOwnershipPolicy<CopyOwnershipPolicy<OwnershipImpl>, 
                                                                               OwnershipImpl>
{
    public:
        using copy_type = typename OwnershipImpl::Copytype;
        using shared_type = typename OwnershipImpl::Sharetype;
        using transfer_type = typename OwnershipImpl::Transfertype;

        // ====================  LIFECYCLE     =======================================

        CopyOwnershipPolicy ()   // constructor
        {
            return;
        }

        CopyOwnershipPolicy (const CopyOwnershipPolicy & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        CopyOwnershipPolicy (CopyOwnershipPolicy && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method CopyOwnershipPolicy::CopyOwnershipPolicy  -----

        ~CopyOwnershipPolicy ()
        {
            return;
        };  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        CopyOwnershipPolicy& operator= ( const CopyOwnershipPolicy &other ) // assignment operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator


        CopyOwnershipPolicy& operator= ( CopyOwnershipPolicy && other ) // assignment-move operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment-move operator

    protected:
        // ====================  ACCESSORS     =======================================

        //! Returns a copy_type of the receiver results.
        //!
        //! The underlying object of the copy_type is copied to an object of
        //! copy_type and returned to the invoker.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! returns unique_obj  A object of copy_type that is a copy a_receiver_result.
        template<typename W>
        copy_type copyResult_(W const & a_receiver_result) const
        {
            copy_type tmp_obj = std::move(this->myImpl_.copy(a_receiver_result));
            return tmp_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! Throws runtime error if invoked.
        //!
        //! The CopyOwnershipPolicy doesn't allow the receiver results to be
        //! shared.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<CopyOwnershipPolicy>
        template<typename W>
        shared_type shareOwnershipOfResult_(W & a_receiver_result)
        {
            const std::string my_error_message(shared_error_message_);
            shared_type tmp_obj = OwnershipImpl::throwSharingError(my_error_message);
            return tmp_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The CopyOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to transfer its ownership.
        //! @throws ErrorOwnershipPolicy<CopyOwnershipPolicy>
        template<typename W>
        transfer_type transferOwnershipOfResult_(W & a_receiver_result)
        {
            const std::string my_error_message(take_error_message_);
            transfer_type tmp_obj = OwnershipImpl::throwTransferringError(my_error_message);
            return tmp_obj; 
        }

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  STATIC       =======================================
        static constexpr std::string_view shared_error_message_ = 
            std::string_view("The CopyOwnershipPolicy does not permit the receiver result to be shared.");

        static constexpr std::string_view take_error_message_ = 
            std::string_view("The CopyOwnershipPolicy does not permit the receiver result to be taken over.");

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        OwnershipImpl myImpl_;

}; // -----  end of class CopyOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_CopyOwnershipPolicy_INC
