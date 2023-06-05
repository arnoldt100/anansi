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
//! The TransferCopyOwnershipPolicy implements the following constraints
//! on the receiver's result:
//! copying
//! no sharing 
//! transferring ownership
//!
//! @tparam RT The underlying type of the receiver's result.
template < typename OwnershipImpl >
class TransferCopyOwnershipPolicy : public RECEIVER::BaseReceiverResultOwnershipPolicy< TransferCopyOwnershipPolicy<OwnershipImpl>,
                                                                                        OwnershipImpl
                                                                                       >
{
    public:

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

        // ====================  MUTATORS      =======================================

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

    private:
        // ====================  TYPEDEF ALIASES =====================================

        using copy_type_ = 
            typename RECEIVER::ReceiverResultOwnershipType<RECEIVER::OwnershipTypes::COPYTYPE,
                                                           OwnershipImpl>::TYPE;

        using shared_type_ = 
            typename  RECEIVER::ReceiverResultOwnershipType<RECEIVER::OwnershipTypes::SHARETYPE,
                                                           OwnershipImpl>::TYPE;

         using transfer_type_ = 
             typename RECEIVER::ReceiverResultOwnershipType<RECEIVER::OwnershipTypes::TRANSFERTYPE,
                                                           OwnershipImpl>::TYPE;
    protected:
        // ====================  ACCESSORS     =======================================

        //! Returns a copy_type_ of the receiver results.
        //!
        //! The underlying object of the copy_type_ is copied to an object of
        //! copy_type_ and returned to the invoker.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @throws ErrorOwnershipPolicy<TransferCopyOwnershipPolicy>
        template<typename W>
        copy_type_ copyResult_(W const & a_receiver_result) const
        {
            copy_type_ tmp_obj = std::move(this->myImpl_.copy(a_receiver_result));
            return tmp_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! Throws runtime error if invoked.
        //!
        //! The TransferCopyOwnershipPolicy doesn't permit the receiver results to be
        //! shared.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<TransferCopyOwnershipPolicy>
        template <typename W>
        shared_type_ shareOwnershipResult_(W & my_obj) 
        {
            const std::string my_error_message(shared_error_message_);
            shared_type_ tmp_obj =  OwnershipImpl::throwSharingError(my_error_message);
            return tmp_obj;
        }
        
        //! Returns a transfer_type_ of the receiver results.
        //!
        //! The TransferCopyOwnershipPolicy only permits transfer_type_ ot be transferred.
        //!
        //! @tparam W The type of the receiver's result.
        //! The underlying object of the unique_ptr is taken over and moved to
        //! an  object of transfer_type_ and returned to the invoker.
        template<typename W>
        transfer_type_ transferOwnershipOfResult_(W & a_receiver_result)
        {
            transfer_type_ tmp_obj = this->myImpl_.transfer(a_receiver_result);
            return tmp_obj; 
        }

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  STATIC       =======================================
        static constexpr std::string_view shared_error_message_ = 
            std::string_view("The TransferCopyOwnershipPolicy does not permit sharing of a receiver result.");

        static constexpr std::string_view take_error_message_ = 
            std::string_view("The TransferCopyOwnershipPolicy does not permit a shared_type_ receiver result to be taken over.");

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        OwnershipImpl myImpl_;

}; // -----  end of class TransferCopyOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_TransferCopyOwnershipPolicy_INC
