#ifndef RECEIVER_ReceiverInterface_INC
#define RECEIVER_ReceiverInterface_INC
//! @file ReceiverInterface.hpp
//!
//! An abstract base class that provides the interface for receiver objects.
//!
//! ReceiverInterface provides the interface for all receiver objects
//! as found in the Command pattern.

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

template<typename Derived>
class ReceiverInterface
{
    public:
        // ====================  LIFECYCLE     =======================================

        ReceiverInterface ()   // constructor
        {
            return;
        }

        ReceiverInterface (const ReceiverInterface & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ReceiverInterface (ReceiverInterface && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method ReceiverInterface::ReceiverInterface  -----

        virtual ~ReceiverInterface ()=0;  // destructor

        // ====================  ACCESSORS     =======================================
        
        // ====================  MUTATORS      =======================================

        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to the CRTP derived class.
        Derived& asDerived_()
        {
            return *static_cast<Derived*>(this);
        }

        template<typename... Types>
        void enable(Types &... args)
        {
            this->enable_(args...);
        }

        void disable()
        {
            asDerived_().disableReceiver();
        }

        void action()
        {
            asDerived_().receiverDoAction();
        }

        void undoAction()
        {
            asDerived_().receiverUndoAction();
        }

        // ====================  OPERATORS     =======================================

        ReceiverInterface& operator= ( const ReceiverInterface &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        ReceiverInterface& operator= ( ReceiverInterface && other ) // assignment-move operator
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
        // ====================  METHODS       =======================================
        
        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to a constant CRTP derived class "Derived".
        Derived const & asDerived_() const
        {
            return *static_cast<Derived const*>(this);
        }
        
        
        template<typename FirstArgType, typename... Types>
        void enable_(FirstArgType & firstArg, Types &... args)
        {
            asDerived_().enableReceiver(firstArg);
            this->enable_(args...);
        }

        void enable_()
        {
            return;
        }

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ReceiverInterface  -----

template <typename Derived>
ReceiverInterface<Derived>::~ReceiverInterface ()  // destructor
{
    return;
}

}; // namespace RECEIVER

#endif // RECEIVER_ReceiverInterface_INC
