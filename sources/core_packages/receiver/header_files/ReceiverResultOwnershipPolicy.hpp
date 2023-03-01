#ifndef RECEIVER_ReceiverResultOwnershipPolicy_INC
#define RECEIVER_ReceiverResultOwnershipPolicy_INC

//! @file ReceiverResultOwnershipPolicy.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace RECEIVER
{

//! The interface class for the class policies that copy, share, and transfer of the receiver's result.
//!
//! This class uses the CRTP design pattern for implementing the interface of
//! the receiver's result ownership policies. The derived class is 
//! ConcreteResultOwnershipPolicy<UT>. There are a some class methods that are not sensible, but
//! we let the concrete class make these methods illegal.
//! 
//! @tparam UT The underlying type of the receiver's result.
//! @tparam ConcreteResultOwnershipPolicy<UT> The concrete ownership policy of the recievers result.
template <typename ConcreteResultOwnershipPolicy, 
          template <typename> typename OwnernshipPolicy, 
          class UT >
class ReceiverResultOwnershipPolicy
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The definition of a shared receiver's result.
        using shared_type = typename OwnernshipPolicy<UT>::Sharedtype;
        using unique_type = typename OwnernshipPolicy<UT>::Uniquetype;
        using transfer_type = typename OwnernshipPolicy<UT>::Transfertype;

        ReceiverResultOwnershipPolicy (const ReceiverResultOwnershipPolicy & other)  // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ReceiverResultOwnershipPolicy (ReceiverResultOwnershipPolicy && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method ReceiverResultOwnershipPolicy::ReceiverResultOwnershipPolicy  -----

        virtual ~ReceiverResultOwnershipPolicy ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        //! The copy interface definition for a unique_type receiver's result.
        //!
        //! The underlying object in a_receiver_result is to be copied.
        //!
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @return A unique_type obtained by copying the underlying object in a_receiver_result.
        unique_type copyReceiverResult ( unique_type const & a_receiver_result) const
        {
            return asDerived_().copyResult(a_receiver_result);
        }

        //! The copy interface definition for a shared_type receiver's result.
        //!
        //! The underlying object in a_receiver_result is to be copied.
        //!
        //! @param[in] a_receiver_result The receiver result to be copied.
        //! @return A unique_type obtained by copying the underlying object in a_receiver_result.
        unique_type copyReceiverResult(shared_type const & a_receiver_result) const
        {
            return asDerived_().copyResult(a_receiver_result);
        }

        // ====================  MUTATORS      =======================================

        //! The transfer ownership interface definition for a unique_type receiver's result.
        //!
        //! @param[in] a_receiver_result The receiver result to trasnfer ownership.
        //! @return A unique_type obtained by transferring ownership of the underlying object in a_receiver_result.
        unique_type transferOwnershipOfReceiverResult(unique_type & a_receiver_result)
        {
            return asDerived_().transferOwnershipOfResult(a_receiver_result);
        }

        //! The transfer ownership interface definition for a shared_type receiver's result.
        //!
        //! @param[in] a_receiver_result The receiver result to trasnfer ownership.
        //! @return A unique_type obtained by transferring ownership of the underlying object in a_receiver_result.
        unique_type transferOwnershipOfReceiverResult(shared_type & a_receiver_result)
        {
            return asDerived_().transferOwnershipOfResult(a_receiver_result);
        }

        //! The share ownership interface definition for a unique_type receiver's result.
        //!
        //! @param[in] a_receiver_result The receiver result to share ownership. 
        //! @return A shared_type obtained by transferring ownership of the underlying object in a_receiver_result.
        shared_type shareOwnershipOfReceiverResult ( unique_type & a_receiver_result)
        {
            return asDerived_().shareOwnershipOfResult(a_receiver_result);
        }

        //! The share ownership interface definition for a shared_type receiver's result.
        //!
        //! @param[in] a_receiver_result The receiver result to share ownership. 
        //! @return A shared_type obtained by transferring ownership of the underlying object in a_receiver_result.
        shared_type shareOwnershipOfReceiverResult ( shared_type & a_receiver_result)
        {
            return asDerived_().shareOwnershipOfResult(a_receiver_result);
        }

        // ====================  OPERATORS     =======================================

        ReceiverResultOwnershipPolicy& operator= ( const ReceiverResultOwnershipPolicy &other ) // assignment operator
        {
            if (this != &other)
            {
                
            }
            return *this;
        }

        ReceiverResultOwnershipPolicy& operator= ( ReceiverResultOwnershipPolicy && other ) // assignment-move operator
        {
            if (this != &other)
            {
                
            }
            return *this;
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        //! The following ensures that the CRTP doesn't use the wrong class.
        //!
        //! Only friends of this class can invoke the private  base class
        //! constructor, Therefore incorrect code like 
        //!   * class Derived1 : public Base<Derived2>
        //! won't compile.
        friend ConcreteResultOwnershipPolicy;
        ReceiverResultOwnershipPolicy() // constructor
        {
            return;
        }

        // ====================  METHODS       =======================================
        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to the CRTP derived class.
        constexpr ConcreteResultOwnershipPolicy & asDerived_() 
        {
            return *static_cast<ConcreteResultOwnershipPolicy *>(this);
        }

        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to a constant CRTP derived class "Derived".
        constexpr ConcreteResultOwnershipPolicy const & asDerived_() const
        {
            return *static_cast<ConcreteResultOwnershipPolicy const*>(this);
        }

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ReceiverResultOwnershipPolicy  -----

template <class ConcreteResultOwnershipPolicy, 
          template <typename> typename OwnernshipPolicy, 
          class UT >
ReceiverResultOwnershipPolicy<ConcreteResultOwnershipPolicy,OwnernshipPolicy,UT>::~ReceiverResultOwnershipPolicy()
{
    return;
}

}; // namespace RECEIVER

#endif // RECEIVER_ReceiverResultOwnershipPolicy_INC
