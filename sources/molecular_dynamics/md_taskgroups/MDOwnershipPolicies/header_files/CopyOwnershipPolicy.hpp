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
#include "Ownership1.hpp"
#include "ErrorOwnershipPolicy.hpp"
#include "ReceiverResultOwnershipPolicy.hpp"

namespace ANANSI
{

//! This concrete policy class implements copy behaviours with respect to the receiver's's result.
//! 
//! The CopyOwnershipPolicy implements the following constraints
//! on the receiver's result:
//! copying of receiver's result
//! no sharing of ownership
//! no transferring ownership
template < typename T,
           template <typename> typename OwnershipPolicy = Ownership1 
         >
class CopyOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<CopyOwnershipPolicy<T,OwnershipPolicy>, OwnershipPolicy, T>
{
    public:
        using basetype = RECEIVER::ReceiverResultOwnershipPolicy<CopyOwnershipPolicy<T,OwnershipPolicy>, OwnershipPolicy, T>;
        using unique_type = typename basetype::unique_type;
        using shared_type = typename basetype::shared_type;

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

        //! Returns a unique_type of the receiver results.
        //!
        //! The underlying object of the unique_type is copied to an object of
        //! unique_type and returned to the invoker.
        //!
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! returns unique_obj  A object of unique_type that is a copy a_receiver_result.
        unique_type copyResult(unique_type const & a_receiver_result) const
        {
            unique_type tmp_obj = std::move(OwnershipPolicy<T>::copy(a_receiver_result));
            return tmp_obj;
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
            unique_type tmp_obj = std::move(OwnershipPolicy<T>::copy(a_receiver_result));
            return tmp_obj;
        }

        // // ====================  MUTATORS      =======================================

        //! Throws runtime error if invoked.
        //!
        //! The CopyOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        //!
        //! @param[in] a_receiver_result The receiver result to transfer its ownership.
        //! @throws ErrorOwnershipPolicy<CopyOwnershipPolicy>
        unique_type transferOwnershipOfResult(unique_type & a_receiver_result)
        {
            const std::string my_err_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<CopyOwnershipPolicy>(my_err_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The CopyOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        //!
        //! @param[in] a_receiver_result The receiver result to transfer its ownership.
        //! @throws ErrorOwnershipPolicy<CopyOwnershipPolicy>
        unique_type transferOwnershipOfResult(shared_type & a_receiver_result)
        {
            const std::string my_err_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<CopyOwnershipPolicy>(my_err_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The CopyOwnershipPolicy doesn't allow the receiver results to be
        //! shared.
        //!
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<CopyOwnershipPolicy>
        shared_type shareOwnershipOfResult(unique_type & a_receiver_result) 
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<CopyOwnershipPolicy>(my_err_message);
            shared_type shared_obj;
            return shared_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The CopyOwnershipPolicy doesn't allow the receiver results to be
        //! shared.
        //!
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<CopyOwnershipPolicy>
        shared_type shareOwnershipOfResult(shared_type & a_receiver_result)
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<CopyOwnershipPolicy>(shared_error_message_);
            shared_type shared_obj;
            return shared_obj; 
        }

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
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  STATIC       =======================================
        static constexpr std::string_view shared_error_message_ = 
            std::string_view("The CopyOwnershipPolicy does not permit the receiver result to be shared.");

        static constexpr std::string_view take_error_message_ = 
            std::string_view("The CopyOwnershipPolicy does not permit the receiver result to be taken over.");

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class CopyOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_CopyOwnershipPolicy_INC
