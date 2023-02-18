#ifndef RECEIVER_ReceiverResultOwnershipPolicy_INC
#define RECEIVER_ReceiverResultOwnershipPolicy_INC
//! @file ReceiverResultOwnershipPolicy.hpp
//!
//! The interface for the ownership policies of receiver's results.
//!
//! The objects we operate on with respect to 

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
template <typename ConcreteOwnershipPolicy,
          typename T>
class ReceiverResultOwnershipPolicy
{
    public:
        // ====================  LIFECYCLE     =======================================

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

        virtual ~ReceiverResultOwnershipPolicy () = 0;  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        auto takeOwnership( T & thing) 
        {
            return asDerived_().takeOwnershipOfObject(thing);
        }

        T shareOwnership( T & thing) 
        {
            return thing;
        }

        T copyOwnership( T & thing) 
        {
            return thing;
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

        //! Provides access to the CRTP derived class "ConcreteOwnershipPolicy."
        //!
        //! @return A reference to the CRTP derived class.
        constexpr ConcreteOwnershipPolicy& asDerived_() 
        {
            return *static_cast<ConcreteOwnershipPolicy*>(this);
        }

        //! Provides access to the CRTP derived class "ConcreteOwnershipPolicy."
        //!
        //! @return A reference to a constant CRTP derived class "ConcreteOwnershipPolicy".
        constexpr ConcreteOwnershipPolicy const & asDerived_() const
        {
            return *static_cast<ConcreteOwnershipPolicy const*>(this);
        }

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ReceiverResultOwnershipPolicy  -----


template <typename ConcreteOwnershipPolicy,
          typename T>
ReceiverResultOwnershipPolicy<ConcreteOwnershipPolicy,T>::~ReceiverResultOwnershipPolicy()
{
    return;
}

}; // namespace RECEIVER

#endif // RECEIVER_ReceiverResultOwnershipPolicy_INC
