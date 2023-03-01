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

//! This concrete policy class implements trasnfer behaviours with respect to the receiver's's result.
//! 
//! The TransferOwnershipPolicy implements the following constraints
//! on the receiver's result:
//! no copying
//! no sharing 
//! transferring ownership
//!
//! @tparam RT The underlying type of the receiver's result.
template < typename T,
           template <typename> typename OwnershipPolicy = OwnershipImpl1 
         >
class TransferOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<TransferOwnershipPolicy<T,OwnershipPolicy>, OwnershipPolicy, T>
{
    private:
        using basetype = RECEIVER::ReceiverResultOwnershipPolicy<TransferOwnershipPolicy<T,OwnershipPolicy>, OwnershipPolicy, T>;
        using unique_type = typename basetype::unique_type;
        using shared_type = typename basetype::shared_type;

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

        //! Throws runtime error if invoked.
        //!
        //! The TransferOwnershipPolicy doesn't allow the receiver's results to be
        //! copied.
        //!
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @throws ErrorOwnershipPolicy<TransferOwnershipPolicy>
        unique_type copyResult(unique_type const & a_receiver_result) const
        {
            const std::string my_error_message(copy_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<TransferOwnershipPolicy>(my_error_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The TransferOwnershipPolicy doesn't allow the receiver's results to be
        //! copied.
        //!
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @throws ErrorOwnershipPolicy<TransferOwnershipPolicy>
        unique_type copyResult(shared_type & my_obj) const
        {
            const std::string my_error_message(copy_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<TransferOwnershipPolicy>(my_error_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! Returns a unique_ptr of the receiver results.
        //!
        //! The underlying object of the unique_ptr is taken over and moved to
        //! an  object of unique_type and returned to the invoker.
        unique_type transferOwnershipOfResult(unique_type & my_obj)
        {
            unique_type unique_obj = std::move(OwnershipPolicy<T>::transfer(my_obj));
            return unique_obj; 
        }

        //! The transfer ownership policy doesn't allow a shared_type to be taken over.
        //!
        //! An error is thrown if invoked.
        unique_type transferOwnershipOfResult(shared_type & my_obj)
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<TransferOwnershipPolicy>(my_err_message);
            shared_type unique_obj;
            return unique_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The TransferOwnershipPolicy doesn't permit the receiver results to be
        //! shared.
        //!
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<TransferOwnershipPolicy>
        shared_type shareOwnershipReceiverResult(shared_type & my_obj) 
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<TransferOwnershipPolicy>(my_err_message);
            shared_type shared_obj;
            return shared_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The TransferOwnershipPolicy doesn't permit the receiver results to be
        //! shared.
        //!
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<TransferOwnershipPolicy>
        shared_type shareOwnershipReceiverResult(unique_type & my_obj) 
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<TransferOwnershipPolicy>(my_err_message);
            shared_type shared_obj;
            return shared_obj; 
        }

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
        // ====================  METHODS       =======================================

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

}; // -----  end of class TransferOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_TransferOwnershipPolicy_INC
