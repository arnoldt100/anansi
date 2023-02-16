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
template <template <typename T > class ConcretePolicy, class RT>
class ReceiverResultOwnershipPolicy
{
    public:
        // ====================  LIFECYCLE     =======================================

        friend ConcretePolicy<RT>;

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

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ReceiverResultOwnershipPolicy  -----

template <template <typename T> class ConcretePolicy, class RT>
ReceiverResultOwnershipPolicy<ConcretePolicy,RT>::~ReceiverResultOwnershipPolicy()
{
    return;
}

}; // namespace RECEIVER

#endif // RECEIVER_ReceiverResultOwnershipPolicy_INC
