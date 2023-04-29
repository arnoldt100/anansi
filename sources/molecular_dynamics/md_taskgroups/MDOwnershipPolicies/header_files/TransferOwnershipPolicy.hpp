#ifndef ANANSI_TransferOwnershipPolicy_INC
#define ANANSI_TransferOwnershipPolicy_INC
//! @file TransferOwnershipPolicy.hpp
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string.h>
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

//! This concrete policy class implements trasnfer behaviours with respect to the receiver's's result.
//! 
//! The TransferOwnershipPolicy implements the following constraints
//! on the receiver's result:
//! no copying
//! no sharing 
//! transferring ownership
//!
//! @tparam RT The underlying type of the receiver's result.
template < typename OwnershipImpl >
class TransferOwnershipPolicy : public RECEIVER::BaseReceiverResultOwnershipPolicy<TransferOwnershipPolicy<OwnershipImpl>,
                                                                                   OwnershipImpl
                                                                                   >
{
    private:
        using copy_type = typename OwnershipImpl::Copytype;
        using shared_type = typename OwnershipImpl::Sharetype;
        using transfer_type = typename OwnershipImpl::Transfertype;

    public:
        // ====================  LIFECYCLE     =======================================

        TransferOwnershipPolicy ()   // constructor
        {
            return;
        }

        TransferOwnershipPolicy (const TransferOwnershipPolicy & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        TransferOwnershipPolicy (TransferOwnershipPolicy && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method TransferOwnershipPolicy::TransferOwnershipPolicy  -----

        ~TransferOwnershipPolicy ()
        {
            return;
        };  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TransferOwnershipPolicy& operator= ( const TransferOwnershipPolicy &other) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator


        TransferOwnershipPolicy& operator= ( TransferOwnershipPolicy && other ) // assignment-move operator
        {
            if (this != &other)
            {
        
            }
            return *this;
       } // assignment-move operator

    protected:
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
        copy_type copyResult_(W & a_receiver_result) const
        {
            const std::string my_error_message(copy_error_message_);
            copy_type tmp_obj =  OwnershipImpl::throwCopyingError(my_error_message);
            return tmp_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to transfer its ownership.
        //! @throws ErrorOwnershipPolicy<NullOwnershipPolicy>
        template<typename W>
        transfer_type transferOwnershipOfResult_(W & a_receiver_result)
        {
            const std::string my_error_message(take_error_message_);
            transfer_type tmp_obj = OwnershipImpl::throwTransferringError(my_error_message);
            return tmp_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! Throws runtime error if invoked.
        //!
        //! The TransferOwnershipPolicy doesn't permit the receiver results to be
        //! shared.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<TransferOwnershipPolicy>
        template<typename W>
        shared_type shareOwnershipOfResult_(W & a_receiver_result)
        {
            const std::string my_error_message(shared_error_message_);
            shared_type tmp_obj =  OwnershipImpl::throwSharingError(my_error_message);
            return tmp_obj;
        }


        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  STATIC       =======================================
        static constexpr std::string_view copy_error_message_ = 
            std::string_view("The TransferOwnershipPolicy does not permit copying a receiver's result.");

        static constexpr std::string_view shared_error_message_ = 
            std::string_view("The TransferOwnershipPolicy does not permit sharing of a receiver result.");

        static constexpr std::string_view take_error_message_ = 
            std::string_view("The TransferOwnershipPolicy does not permit a shared_type receiver result to be taken over.");

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        OwnershipImpl myImpl_;

}; // -----  end of class TransferOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_TransferOwnershipPolicy_INC
