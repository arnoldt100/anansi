#ifndef ANANSI_NullOwnershipPolicy_INC
#define ANANSI_NullOwnershipPolicy_INC
//! @file NullOwnershipPolicy.hpp

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
#include "ReceiverResultOwnershipPolicy.hpp"
#include "OwnershipImpl1.hpp"

namespace ANANSI
{

//! This concrete policy class implements null behaviours with respect to the receiver's's result.
//! 
//! The NullOwnershipPolicy implements the following constraints
//! on the receiver's result:
//! no copying
//! no sharing 
//! no transferring ownership
//!
//! @tparam RT The underlying type of the receiver's result.
//! @tparam OwnershipPolicy The implementation of copying, sharing and transferring the receiver's result.
template <typename RT,
           template <typename> typename OwnershipPolicy = OwnershipImpl1 
         >
class NullOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<NullOwnershipPolicy<RT,OwnershipPolicy>, OwnershipPolicy, RT>
{
    public:
        using basetype = RECEIVER::ReceiverResultOwnershipPolicy<NullOwnershipPolicy<RT,OwnershipPolicy>, OwnershipPolicy, RT>;
        using unique_type = typename basetype::unique_type;
        using shared_type = typename basetype::shared_type;

        // ====================  LIFECYCLE     =======================================

        NullOwnershipPolicy ()   // constructor
        {
            return;
        }

        NullOwnershipPolicy (const NullOwnershipPolicy & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        NullOwnershipPolicy (NullOwnershipPolicy && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method NullOwnershipPolicy::NullOwnershipPolicy  -----

        ~NullOwnershipPolicy ()
        {
            return;
        };  // destructor

        // ====================  ACCESSORS     =======================================
        
        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver's results to be
        //! copied.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @throws ErrorOwnershipPolicy<NullOwnershipPolicy>
        template< typename W>
        unique_type copyResult(W const & a_receiver_result) const
        {
            const std::string my_error_message(copy_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<NullOwnershipPolicy>(my_error_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to transfer its ownership.
        //! @throws ErrorOwnershipPolicy<NullOwnershipPolicy>
        template<typename W>
        unique_type transferOwnershipOfResult(W & a_receiver_result)
        {
            const std::string my_error_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<NullOwnershipPolicy>(my_error_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! shared.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<NullOwnershipPolicy>
        template<typename W>
        shared_type shareOwnershipOfResult(W & a_receiver_result)
        {
            const std::string my_error_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<NullOwnershipPolicy>(my_error_message);
            shared_type shared_obj;
            return shared_obj; 
        }

        // ====================  OPERATORS     =======================================

        NullOwnershipPolicy& operator= ( const NullOwnershipPolicy &other) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        NullOwnershipPolicy& operator= ( NullOwnershipPolicy && other ) // assignment-move operator
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
            std::string_view("The NullOwnershipPolicy does not permit the receiver result to be shared.");

        static constexpr std::string_view take_error_message_ = 
            std::string_view("The NullOwnershipPolicy does not permit the receiver result to be taken over.");

        static constexpr std::string_view copy_error_message_ = 
            std::string_view("The NullOwnershipPolicy does not permit the receiver result to be copied.");


        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class NullOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_NullOwnershipPolicy_INC
