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
#include "BaseReceiverResultOwnershipPolicy.hpp"
#include "OwnershipTypes.hpp"

namespace ANANSI
{

//! This concrete policy class implements null behaviours with respect to the receiver's's result.
//! 
//! The NullOwnershipPolicy implements the following constraints
//! on the receiver's result:
//! * no copying
//! * no sharing 
//! * no transferring ownership
//!
//! @tparam OwnershipImpl The implementation of copying, sharing and transferring the receiver's result.
template < typename OwnershipImpl >
class NullOwnershipPolicy : public RECEIVER::BaseReceiverResultOwnershipPolicy< NullOwnershipPolicy<OwnershipImpl>,
                                                                                OwnershipImpl>
{
    private : 

        // ====================  TYPEDEF ALIASES =====================================

        using MyReceiverOwnershipImplementationTraits_ = typename OwnershipImpl::ReceiverOwnershipImplementationTraits; 

        template<RECEIVER::OwnershipTypes Q>
        using MyReceiverOwnershipTypes_ = RECEIVER::ReceiverOwnershipType<Q,MyReceiverOwnershipImplementationTraits_>;

        using copy_type_ = typename MyReceiverOwnershipTypes_<RECEIVER::OwnershipTypes::COPYTYPE>::TYPE;
        using shared_type_ = typename MyReceiverOwnershipTypes_<RECEIVER::OwnershipTypes::SHARETYPE>::TYPE;
        using transfer_type_ = typename MyReceiverOwnershipTypes_<RECEIVER::OwnershipTypes::TRANSFERTYPE>::TYPE;


    public:
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
        
        // ====================  MUTATORS      =======================================

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
        // ====================  MUTATORS      =======================================

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! shared.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to share its ownership.
        //! @throws ErrorOwnershipPolicy<NullOwnershipPolicy>
        template<typename W>
        shared_type_ shareOwnershipOfResult_(W & a_receiver_result)
        {
            const std::string my_error_message(shared_error_message_);
            shared_type_ tmp_obj = OwnershipImpl::throwSharingError(my_error_message);
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
        transfer_type_ transferOwnershipOfResult_(W & a_receiver_result)
        {
            const std::string my_error_message(take_error_message_);
            transfer_type_ tmp_obj = OwnershipImpl::throwTransferringError(my_error_message);
            return tmp_obj; 
        }


        // ====================  ACCESSORS     =======================================

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver's results to be
        //! copied.
        //!
        //! @tparam W The type of the receiver's result.
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @throws ErrorOwnershipPolicy<NullOwnershipPolicy>
        template<typename W>
        copy_type_ copyResult_(W const & a_receiver_result) const
        {
            const std::string my_error_message(copy_error_message_);
            copy_type_ tmp_obj = OwnershipImpl::throwCopyingError(my_error_message);
            return tmp_obj; 
        }

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
        OwnershipImpl myImpl_;

}; // -----  end of class NullOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_NullOwnershipPolicy_INC
