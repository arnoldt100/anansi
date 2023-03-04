#ifndef ANANSI_TransferCopyOwnershipPolicy_INC
#define ANANSI_TransferCopyOwnershipPolicy_INC
//! @file TransferCopyOwnershipPolicy.hpp
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
#include "OwnershipImpl1.hpp"
#include "ErrorOwnershipPolicy.hpp"
#include "ReceiverResultOwnershipPolicy.hpp"
#include "TransferCopyOwnershipPolicyConcepts.hpp"

namespace ANANSI
{

//! This concrete policy class implements trasnfer behaviours with respect to the receiver's's result.
//! 
//! The TransferCopyOwnershipPolicy implements the following constraints
//! on the receiver's result:
//! copying
//! no sharing 
//! transferring ownership
//!
//! @tparam RT The underlying type of the receiver's result.
template < typename T,
           template <typename> typename OwnershipPolicy = OwnershipImpl1 
         >
class TransferCopyOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<TransferCopyOwnershipPolicy<T,OwnershipPolicy>, OwnershipPolicy, T>
{
    public:
        using basetype = RECEIVER::ReceiverResultOwnershipPolicy<TransferCopyOwnershipPolicy<T,OwnershipPolicy>, OwnershipPolicy, T>;
        using copy_type = typename basetype::copy_type;
        using transfer_type = typename basetype::transfer_type;
        using shared_type = typename basetype::shared_type;

        // ====================  LIFECYCLE     =======================================

        TransferCopyOwnershipPolicy ()   // constructor
        {
            return;
        }

        TransferCopyOwnershipPolicy (const TransferCopyOwnershipPolicy & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        TransferCopyOwnershipPolicy (TransferCopyOwnershipPolicy && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method TransferCopyOwnershipPolicy::TransferCopyOwnershipPolicy  -----

        ~TransferCopyOwnershipPolicy ()
        {
            return;
        };  // destructor

        // ====================  ACCESSORS     =======================================

        //! Returns a copy_type of the receiver results.
        //!
        //! The underlying object of the copy_type is copied to an object of
        //! copy_type and returned to the invoker.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @throws ErrorOwnershipPolicy<TransferCopyOwnershipPolicy>
        template<typename W>
        copy_type copyResult(W const & a_receiver_result) const
        {
            copy_type tmp_obj = std::move(OwnershipPolicy<T>::copy(a_receiver_result));
            return tmp_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! Returns a transfer_type of the receiver results.
        //!
        //! The TransferCopyOwnershipPolicy only permits transfer_type ot be transferred.
        //!
        //! @tparam W The type of the receiver's result.
        //! The underlying object of the unique_ptr is taken over and moved to
        //! an  object of transfer_type and returned to the invoker.
        template<typename W>
        requires TransferCopyOwnershipPolicyTransferable<W,transfer_type,copy_type>
        transfer_type transferOwnershipOfResult(W & a_receiver_result)
        {
            transfer_type tmp_obj = std::move(OwnershipPolicy<T>::transfer(a_receiver_result));
            return tmp_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The TransferCopyOwnershipPolicy doesn't permit the receiver results to be
        //! shared.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<TransferCopyOwnershipPolicy>
        template <typename W>
        shared_type shareOwnershipReceiverResult(W & my_obj) 
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<TransferCopyOwnershipPolicy>(my_err_message);
            shared_type shared_obj;
            return shared_obj; 
        }

        // ====================  OPERATORS     =======================================

        TransferCopyOwnershipPolicy& operator= ( const TransferCopyOwnershipPolicy &other) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator


        TransferCopyOwnershipPolicy& operator= ( TransferCopyOwnershipPolicy && other ) // assignment-move operator
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
            std::string_view("The TransferCopyOwnershipPolicy does not permit sharing of a receiver result.");

        static constexpr std::string_view take_error_message_ = 
            std::string_view("The TransferCopyOwnershipPolicy does not permit a shared_type receiver result to be taken over.");

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TransferCopyOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_TransferCopyOwnershipPolicy_INC
