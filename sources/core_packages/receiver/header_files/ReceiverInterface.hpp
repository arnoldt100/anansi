#ifndef RECEIVER_ReceiverInterface_INC
#define RECEIVER_ReceiverInterface_INC

//! @file ReceiverInterface.hpp

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

//! An abstract base class that provides the interface for concrete receiver objects.
//!
//! ReceiverInterface provides the interface for all concrete receiver objects
//! via the Curiously Recurring Template Pattern (CRTP). The class defines the 
//! following public methods:
//! - **getTaskLabel** Returns the task label of the concrete receiver.
//! - **action** Invokes the action command on the concrete receiver.
//! - **undoAction** Invokes the undo action command on the concrete receiver.
//! - **getCopyOfResults** Returns a copy of the results of the action of of the concrete receiver
//! - **shareOwnershipOfResults** Shares ownership of results of the action of of the concrete receiver
//! - **transferOwnershipOfResults** Transfers sole ownership of results of the action of of the concrete receiver
//! - **disable** After this is called, all other comamnds have an indeterminate effect.
//! - **modifyReceiver** Modifies the concrete receiver.
template<typename Derived>
class ReceiverInterface
{
    public : 
        //! Defines the label type for the task.
        //!
        //! The label type will be the key type for the command button
        //! in the invoker.
        using TASK_LABEL_TYPE = RECEIVER::TaskLabel;

        struct accessor : public Derived
        {
            template<typename... Types>
            static void do_action(const Derived & derived, Types... args)
            {
                void (Derived::*fn)(Types... args) const = &accessor::receiverDoAction_;
                return (derived.*fn)(args...);
            };

            //! Returns the task label of the receiver.
            constexpr static TASK_LABEL_TYPE get_task_label (const Derived & derived)
            {
                constexpr TASK_LABEL_TYPE (Derived::*fn)() const = &accessor::receiverGetTaskLabel;
                return (derived.*fn)();
            }
        };

       void doAction() const
       { 
           return accessor::do_action(this->asDerived_());
       }

        constexpr TASK_LABEL_TYPE getTaskLabel () const
        {
           return accessor::get_task_label(this->asDerived_());
        }
        

    public:

        // ====================  ALiases       =======================================
        
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
       
        // constexpr TASK_LABEL_TYPE getTaskLabel () const
        // {
        //     return asDerived_().receiverGetTaskLabel();
        // }

        void undoAction() const
        {
            asDerived_().receiverUndoAction();
            return;
        }

        //! Returns a copy/clone of the action results.
        //!
        //! The results are copied/clone to and unique_ptr and the results of the concrete 
        //! reciever are not modified. If the results are not allowed to be 
        //! copied, an execption is thrown and a default copy of the receiver
        //! results is returned.
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

        template<typename T>
        void enable(T & arg)
        {
            this->enable_(arg);
        }

        //! Returns a shared ownership of the action results.
        //!
        //! The results are shared via a shared_ptr.
        //! If the results are not allowed to be shared,
        //! an execption is thrown and a default instance of the receiver results  is
        //! returned.
        auto shareOwnershipOfResults()
        {
            return asDerived_().receiverShareOwnershipOfResults();
        }

        //! Transfers ownership of the action results.
        //!
        //! The results are transferred (take ownership) via a uniqe_ptr, and
        //! the concrete result receiver results are set to a default value. If
        //! the results are not allowed to be transferred, an execption is
        //! thrown and a default instance of the receiver results  is returned.
        auto transferOwnershipOfResults()
        {
            return asDerived_().receiverTransferOwnershipOfResults();
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

    private : 
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

    private:
        // ====================  ACCESSORS     =======================================

        void modifyReceiver_() const
        {
            return;
        }

        // ====================  MUTATORS      =======================================
        
        template<typename FirstArgType, typename... Types>
        void modifyReceiver_(FirstArgType & firstArg, Types &... args)
        {
            asDerived_().receiverModifyMyself(firstArg);
            this->modifyReceiver_(args...);
            return;
        }

        template<typename T>
        void enable_(T & arg)
        {
            this->enableReceiver(arg);
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
