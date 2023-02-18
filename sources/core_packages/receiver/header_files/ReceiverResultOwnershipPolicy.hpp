#ifndef RECEIVER_ReceiverResultOwnershipPolicy_INC
#define RECEIVER_ReceiverResultOwnershipPolicy_INC

//! @file ReceiverResultOwnershipPolicy.hpp
//!
//! The interface for the ownership policies.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace RECEIVER
{

// =====================================================================================
//        Class:  ReceiverResultOwnershipPolicy
//  Description:  
//  =====================================================================================
template <template <typename T > class ConcreteResultOwnershipPolicy, class RT>
class ReceiverResultOwnershipPolicy
{
    public:
        // ====================  LIFECYCLE     =======================================

        friend ConcreteResultOwnershipPolicy<RT>;

        ReceiverResultOwnershipPolicy ()   // constructor
        {
            return;
        }

        ReceiverResultOwnershipPolicy (const ReceiverResultOwnershipPolicy & other)   // copy constructor
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

        // ====================  MUTATORS      =======================================

        auto takeOwnership ( RT & my_obj)
        {
            return asDerived_().ownObject(my_obj);
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
        // ====================  METHODS       =======================================
        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to the CRTP derived class.
        constexpr ConcreteResultOwnershipPolicy<RT> & asDerived_() 
        {
            return *static_cast<ConcreteResultOwnershipPolicy<RT> *>(this);
        }

        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to a constant CRTP derived class "Derived".
        constexpr ConcreteResultOwnershipPolicy<RT> const & asDerived_() const
        {
            return *static_cast<ConcreteResultOwnershipPolicy<RT> const*>(this);
        }

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ReceiverResultOwnershipPolicy  -----

template <template <typename T> class ConcreteResultOwnershipPolicy, class RT>
ReceiverResultOwnershipPolicy<ConcreteResultOwnershipPolicy,RT>::~ReceiverResultOwnershipPolicy()
{
    return;
}

}; // namespace RECEIVER

#endif // RECEIVER_ReceiverResultOwnershipPolicy_INC
