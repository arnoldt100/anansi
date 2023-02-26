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
#include "ErrorOwnershipPolicy.hpp"
#include "ReceiverResultOwnershipPolicy.hpp"

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
template <typename T>
class TransferCopyOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<TransferCopyOwnershipPolicy, T>
{
    public:
        using unique_type = typename RECEIVER::ReceiverResultOwnershipPolicy<TransferCopyOwnershipPolicy, T>::unique_type;
        using shared_type = typename RECEIVER::ReceiverResultOwnershipPolicy<TransferCopyOwnershipPolicy, T>::shared_type;

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

        //! Returns a unique_type of the receiver results.
        //!
        //! The underlying object of the unique_type is copied to an object of
        //! unique_type and returned to the invoker.
        //!
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @throws ErrorOwnershipPolicy<TransferCopyOwnershipPolicy>
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

        //! Returns a unique_ptr of the receiver results.
        //!
        //! The underlying object of the unique_ptr is taken over and moved to
        //! an  object of unique_type and returned to the invoker.
        unique_type transferOwnershipOfResult(unique_type & my_obj)
        {
            unique_type unique_obj = std::move(my_obj);
            return unique_obj; 
        }

        //! The transfer ownership policy doesn't allow a shared_type to be taken over.
        //!
        //! An error is thrown if invoked.
        unique_type transferOwnershipOfResult(shared_type & my_obj)
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<TransferCopyOwnershipPolicy>(my_err_message);
            shared_type unique_obj;
            return unique_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The TransferCopyOwnershipPolicy doesn't permit the receiver results to be
        //! shared.
        //!
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<TransferCopyOwnershipPolicy>
        shared_type shareOwnershipReceiverResult(shared_type & my_obj) 
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<TransferCopyOwnershipPolicy>(my_err_message);
            shared_type shared_obj;
            return shared_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The TransferCopyOwnershipPolicy doesn't permit the receiver results to be
        //! shared.
        //!
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<TransferCopyOwnershipPolicy>
        shared_type shareOwnershipReceiverResult(unique_type & my_obj) 
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
