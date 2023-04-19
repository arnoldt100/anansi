#ifndef  ANANSI_ConcreteTaskReceiver_INC
#define  ANANSI_ConcreteTaskReceiver_INC

//! @file ConcreteTaskReceiver.h
//!
//! Contains the declaration for ConcreteTaskReceiver.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReceiverInterface.hpp"
#include "TaskLabel.hpp"
#include "OwnershipImpl1.hpp"

// ---------------------------------------------------
// Uncomment the ownership policies as required for 
// class member ConcreteTaskReceiver::ownershipPolicy_.
// For this class we select CopyOwnershipPolicy.hpp.
// ---------------------------------------------------
// #include "NullOwnershipPolicy.hpp"
// #include "TransferOwnershipPolicy.hpp"
// #include "ShareCopyOwnershipPolicy.hpp"
// #include "TransferCopyOwnershipPolicy.hpp""
// #include "ShareOwnershipPolicy.hpp"
#include "CopyOwnershipPolicy.hpp"


namespace ANANSI
{

//! The action of the reciever is to write a message to stdout.
//! 
//! The message store in messageContainer_ is written to stdout.
class ConcreteTaskReceiver : public RECEIVER::ReceiverInterface<ConcreteTaskReceiver>
{
    public:
      // ------------- //
      //  <Edit here>  //
      // ---------------------------------------------------
      // Declare the underlying type for the reciever result.
      // ConcreteTaskReceiver::results_ is a smart pointer that
      // 'wraps' the actual result value.
      // ---------------------------------------------------
      using receiver_result_t = int;

    private:
        template<typename T>
        using OwnershipPolicy = OwnershipImpl1<T>;

        // ------------- //
        //  <Edit here>  //
        // ---------------------------------------------------
        // Define the label for the task, The label must be unique
        // between all tasks in the invoker or the wrong tasl might
        // be invoked.
        // ---------------------------------------------------
        static constexpr char tmpstr_[RECEIVER::TaskLabelTraits::MAX_NM_CHARS] = 
            {'a'};

        // ------------- //
        //  <Edit here>  //
        // ---------------------------------------------------
        // Declare the ownership policy of the receivers' result.
        // ---------------------------------------------------
        ANANSI::CopyOwnershipPolicy<receiver_result_t,OwnershipPolicy> ownershipPolicy_;

        // ------------- //
        //  <Edit here>  //
        // ---------------------------------------------------
        // Declare the results. Note that this declaration also
        // sets the ownership of the result. The ownership and the 
        // ownership policy must be compatible.
        // ---------------------------------------------------
        mutable  OwnershipPolicy<receiver_result_t>::CopyType results_;

    public:
        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<ConcreteTaskReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<ConcreteTaskReceiver>::TASK_LABEL_TYPE(ConcreteTaskReceiver::tmpstr_);

        // ====================  LIFECYCLE     =======================================

        ConcreteTaskReceiver ();   // constructor

        ConcreteTaskReceiver (const ConcreteTaskReceiver & other) = delete;   // copy constructor

        ConcreteTaskReceiver (ConcreteTaskReceiver && other);   // copy-move constructor

        ~ConcreteTaskReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        
        // ====================  OPERATORS     =======================================

        ConcreteTaskReceiver& operator= ( const ConcreteTaskReceiver &other ) = delete; // assignment operator

        ConcreteTaskReceiver& operator= ( ConcreteTaskReceiver && other ); // assignment-move operator

    protected:
        // ====================  ACCESSORS     =======================================
        template<typename... Types>
        void receiverDoAction_(Types & ... args) const;
        
        template<typename... Types>
        void receiverUndoAction_(Types & ... args) const;

        constexpr RECEIVER::ReceiverInterface<ConcreteTaskReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  ConcreteTaskReceiver::TASKLABEL;
        }

        OwnershipPolicy<receiver_result_t>::Copytype receiverGetCopyOfResults_() const;

        // ====================  MUTATORS      =======================================
        template<typename... Types>
        void disableReceiver_(Types... args);

        template<typename T>
        void enableReceiver_(T & arg);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        OwnershipPolicy<receiver_result_t>::Sharedtype receiverShareOwnershipOfResults_();

        OwnershipPolicy<receiver_result_t>::Transfertype receiverTransferOwnershipOfResults_();

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  DATA MEMBERS  =======================================
        int base_;

}; // -----  end of class ConcreteTaskReceiver  -----

// ------------- //
//  <Edit here>  //
// ---------------------------------------------------
// This method enables the receiver to do action.
// ---------------------------------------------------
template<typename T>
void ConcreteTaskReceiver::enableReceiver(T & arg)
{
    return;
}

// ------------- //
//  <Edit here>  //
// ---------------------------------------------------
// This method implements the action of the receiver.
// ---------------------------------------------------
template<typename... Types>
void ConcreteTaskReceiver::receiverDoAction_(Types & ... args) const
{
    std::cout << "Stud message for method 'ConcreteTaskReceiver::receiverDoAction_'." << std::endl;
    *(this->results_) += 1;
    return;
}

// ------------- //
//  <Edit here>  //
// ---------------------------------------------------
// This method implements the undo action of the
// receiver.
// ---------------------------------------------------
template<typename... Types>
void ConcreteTaskReceiver::receiverUndoAction_(Types & ... args) const
{
    return;
}

// ------------- //
//  <Edit here>  //
// ---------------------------------------------------
// This method enables the receiver.
// ---------------------------------------------------
template<typename T>
void ConcreteTaskReceiver::enableReceiver_( T & value)
{
    return;
}

// ------------- //
//  <Edit here>  //
// ---------------------------------------------------
// This method frees resources acquired by the  
// receiver. After the receiver is disabled, re-enabling 
// the receiver and performing actions might lead to 
// indeterminate results.
// ---------------------------------------------------
template<typename... Types>
void ConcreteTaskReceiver::disableReceiver_(Types... args)
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ConcreteTaskReceiver_INC  ----- 