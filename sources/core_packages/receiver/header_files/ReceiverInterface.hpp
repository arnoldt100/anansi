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
#include <string>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskLabel.hpp"

namespace RECEIVER
{

template<typename Derived>
class ReceiverInterface
{
    public:

        // ====================  ALiases       =======================================
        
        //! Defines the label type for the task.
        //!
        //! The label type will be the key type for the command button
        //! in the invoker.
        using TASK_LABEL_TYPE = ANANSI::TaskLabel;

        // ====================  LIFECYCLE     =======================================

        ReceiverInterface ()
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
       
        constexpr TASK_LABEL_TYPE getTaskLabel () const
        {
            return asDerived_().receiverGetTaskLabel();
        }

        void action() const
        {
            asDerived_().receiverDoAction();
            return;
        }

        void undoAction() const
        {
            asDerived_().receiverUndoAction();
            return;
        }

        auto getCopyOfResults() const
        {
            return asDerived_().receiverGetCopyOfResults();
        }

        // ====================  MUTATORS      =======================================

        void disable()
        {
            asDerived_().disableReceiver();
            return;
        }

        template<typename... T>
        void modifyReceiver(T &... args)
        {
            this->modifyReceiver_(args...);
            return;
        }

        auto shareOwnershipOfResults()
        {
            return asDerived_().receiverShareOwnershipOfResults();
        }

        auto takeOwnershipOfResults()
        {
            return asDerived_().receiverTakeOwnershipOfResults();
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
        //! @return A reference to the CRTP derived class.
        constexpr Derived& asDerived_() 
        {
            return *static_cast<Derived*>(this);
        }

        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to a constant CRTP derived class "Derived".
        constexpr Derived const & asDerived_() const
        {
            return *static_cast<Derived const*>(this);
        }

        template<typename FirstArgType, typename... Types>
        void modifyReceiver_(FirstArgType & firstArg, Types &... args)
        {
            asDerived_().receiverModifyMyself(firstArg);
            this->modifyReceiver_(args...);
        }

        void modifyReceiver_() const
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
