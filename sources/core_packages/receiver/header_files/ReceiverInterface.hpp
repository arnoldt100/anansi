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
//! - **doAction** Invokes the action command on the concrete receiver.
//! - **undoAction** Invokes the undo action command on the concrete receiver.
//! - **getCopyOfResults** Returns a copy of the results of the action of of the concrete receiver
//! - **shareOwnershipOfResults** Shares ownership of results of the action of of the concrete receiver
//! - **transferOwnershipOfResults** Transfers sole ownership of results of the action of of the concrete receiver
//! - **enable** (To be described later.)
//! - **disable** After this is called, all other comamnds have an indeterminate effect.
//! - **modifyReceiver** Modifies the concrete receiver.
//!
//! Some methods have const qualifiers so as to limit the methods side effects.

//! @tparam The derived class of the CRTP. The derived classes are the concrete receivers. 
template<typename Derived>
class ReceiverInterface
{
    public : 
        //! Defines the label type for the task.
        //!
        //! The label type will be the key type for the command button
        //! in the invoker.
        using TASK_LABEL_TYPE = ANANSI::TaskLabel;

    private:
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

        //! Provides access to the CRTP derived class member methods.
        //!
        //! The goal of this stucture is to better encapsulate (i.e. hide) the
        //! concrete CRTP receivers implementation details. The receievers
        //! implement protected member functions as in ConcretReceiver::foo_. A
        //! function pointer to the address derived pointer member function is
        //! ConcretReceiver::foo_ is formed so that we can indirectly call
        //! ConcretReceiver::foo_.
        struct Accessor_ : public Derived
        {
            template<typename... Types>
            static void do_action(const Derived & derived, Types... args)
            {
                void (Derived::*fn)(Types... args) const = &Accessor_::receiverDoAction_;
                return (derived.*fn)(args...);
            };

            template<typename... Types>
            static void undo_action(const Derived & derived, Types... args)
            {
                void (Derived::*fn)(Types... args) const = &Accessor_::receiverUndoAction_;
                return (derived.*fn)(args...);
            }

            //! Returns the task label of the receiver.
            constexpr static TASK_LABEL_TYPE get_task_label (const Derived & derived)
            {
                constexpr TASK_LABEL_TYPE (Derived::*fn)() const = &Accessor_::receiverGetTaskLabel_;
                return (derived.*fn)();
            }

            //! Provides access to the receiver member receiverGetCopyOfResults_.
            static auto get_copy_of_results(const Derived & derived)
            {
                auto (Derived::*fn)() const = &Accessor_::receiverGetCopyOfResults_;
                return (derived.*fn)();
            }

            static auto get_share_of_results(const Derived & derived)
            {
                auto (Derived::*fn)() const = &Accessor_::receiverShareOwnershipOfResults_;
                return (derived.*fn)();
            }

            static auto transfer_ownership_of_results(const Derived & derived)
            {
                auto (Derived::*fn)() const = &Accessor_::receiverTransferOwnershipOfResults_;
                return (derived.*fn)();
            }

            template<typename... Types>
            static void disable_receiver(Derived & derived, Types... args)
            {
                void (Derived::*fn)(Types... args) = &Accessor_::disableReceiver_;
                return (derived.*fn)(args...);
            }

            template<typename T>
            static void receiver_modify_myself(Derived & derived, T & arg)
            {
                void (Derived::*fn)(T&) = &Accessor_::receiverModifyMyself_;
                return (derived.*fn)(arg);
            }

            template<typename T>
            static void enable_receiver(Derived & derived, T & arg)
            {
                void (Derived::*fn)(T&) = &Accessor_::enableReceiver_;
                return (derived.*fn)(arg);
            }
        };

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
        
        //! Interface for the call executing the receivers' action.
        void doAction() const
        { 
            return Accessor_::do_action(this->asDerived_());
        }
       
        //! Interface for call executing the receivers' undo action.
        //!
        //! Some receivers might have a null undo action.
        void undoAction() const
        {
            return Accessor_::undo_action(this->asDerived_());
        }

        //! Returns the task label.
        constexpr TASK_LABEL_TYPE getTaskLabel () const
        {
           return Accessor_::get_task_label(this->asDerived_());
        }
        
        //! Returns a copy/clone of the action results.
        //!
        //! The results are copied/clone and the result of the concrete 
        //! reciever are not modified. If the results are not allowed to be 
        //! copied, an execption is thrown and a default copy of the receiver
        //! results is returned.
        auto getCopyOfResults() const
        {
            return Accessor_::get_copy_of_results(this->asDerived_());
        }

        // ====================  MUTATORS      =======================================

        //! Disables the concrete receiver.
        //!
        //! If action is called on a disabled receiver an error
        //! is thrown. In addition, acquired resources of the concrete receiver 
        //! are freed. Once a receiver is disabled it can't be renabled.
        void disable()
        {
            return Accessor_::disable_receiver(this->asDerived_());
        }

        //! Modifies the concrete reciever.
        template<typename... T>
        void modifyReceiver(T &... args)
        {
            this->modifyReceiver_(args...);
            return;
        }

        //! Enables the concrete receiver.
        //!
        //! An enabled reciever can perform actions.
        template<typename T>
        void enable(T & arg)
        {
            return Accessor_::enable_receiver(this->asDerived_());
        }

        //! Returns a shared ownership of the action results.
        //!
        //! The results are shared
        //! If the results are not allowed to be shared,
        //! an execption is thrown and a default instance of the receiver
        //! results  is returned.
        auto shareOwnershipOfResults()
        {
            return Accessor_::get_share_of_results(this->asDerived_());
        }

        //! Transfers ownership of the action results.
        //!
        //! The results are transferred (take ownership) and
        //! the concrete result receiver results are set to a default value. If
        //! the results are not allowed to be transferred, an execption is
        //! thrown and a default instance of the receiver results  is returned.
        auto transferOwnershipOfResults()
        {
            return Accessor_::transfer_ownership_of_results(this->asDerived_());
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
        // ====================  ACCESSORS     =======================================

        void modifyReceiver_() const
        {
            return;
        }

        // ====================  MUTATORS      =======================================
        
        template<typename FirstArgType, typename... Types>
        void modifyReceiver_(FirstArgType & firstArg, Types &... args)
        {
            Accessor_::receiver_modify_myself(this->asDerived_(),firstArg);
            this->modifyReceiver_(args...);
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
