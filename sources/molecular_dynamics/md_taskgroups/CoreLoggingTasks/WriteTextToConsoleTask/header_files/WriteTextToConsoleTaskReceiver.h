#ifndef  ANANSI_WriteTextToConsoleTaskReceiver_INC
#define  ANANSI_WriteTextToConsoleTaskReceiver_INC

//! @file WriteTextToConsoleTaskReceiver.h
//!
//! Contains the declaration for WriteTextToConsoleTaskReceiver.

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
#include "Communicator.h"
#include "ReceiverInterface.hpp"
#include "ConsoleMessageContainer.h"
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
class WriteTextToConsoleTaskReceiver : public RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>
{
    public:
       
        //! The object type the smart pointer will manage,
        using receiver_result_t = int;

    private:
        template<typename T>
        using OwnershipPolicy = OwnershipImpl1<T>;

        ANANSI::CopyOwnershipPolicy<receiver_result_t,OwnershipPolicy> ownershipPolicy_;

        static constexpr char tmpstr_[RECEIVER::TaskLabelTraits::MAX_NM_CHARS] = 
            {'w','r','i', 't', 'e','_',
             't', 'e', 'x', 't', '_',
             't', 'o', '_',
             'c','o', 'n', 's', 'o', 'l', 'e'};

        mutable  OwnershipPolicy<receiver_result_t>::Copytype results_;



    public:
        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::TASK_LABEL_TYPE(WriteTextToConsoleTaskReceiver::tmpstr_);

        // ====================  LIFECYCLE     =======================================

        WriteTextToConsoleTaskReceiver ();   // constructor

        WriteTextToConsoleTaskReceiver (const WriteTextToConsoleTaskReceiver & other) = delete;   // copy constructor

        WriteTextToConsoleTaskReceiver (WriteTextToConsoleTaskReceiver && other);   // copy-move constructor

        ~WriteTextToConsoleTaskReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        WriteTextToConsoleTaskReceiver& operator= ( const WriteTextToConsoleTaskReceiver &other ) = delete; // assignment operator

        WriteTextToConsoleTaskReceiver& operator= ( WriteTextToConsoleTaskReceiver && other ); // assignment-move operator

    protected:

        // ====================  ACCESSORS     =======================================

        template<typename... Types>
        void receiverDoAction_(Types &... args) const;

        template<typename... Types>
        void receiverUndoAction_(Types & ... args) const;

        constexpr RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  WriteTextToConsoleTaskReceiver::TASKLABEL;
        }

        OwnershipPolicy<receiver_result_t>::Copytype receiverGetCopyOfResults_() const;

        // ====================  MUTATORS      =======================================

        template<typename T>
        void enableReceiver_(T & arg);

        template<typename... Types>
        void disableReceiver_(Types ...  args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        OwnershipPolicy<receiver_result_t>::Sharedtype receiverShareOwnershipOfResults_();

        OwnershipPolicy<receiver_result_t>::Transfertype receiverTransferOwnershipOfResults_();

        // ====================  DATA MEMBERS  =======================================

    private:

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable std::unique_ptr<COMMUNICATOR::Communicator> communicator_;
	    mutable std::unique_ptr<ConsoleMessageContainer> messageContainer_;

}; // -----  end of class WriteTextToConsoleTaskReceiver  -----

template<typename... Types>
void WriteTextToConsoleTaskReceiver::receiverDoAction_(Types & ... args) const
{
    const auto message = this->messageContainer_->getMessage();
    std::cout << message << std::endl;
    *(this->results_) += 1;
    return;
}

template<typename... Types>
void WriteTextToConsoleTaskReceiver::receiverUndoAction_(Types & ... args) const
{
    return;
}

template<typename T>
void WriteTextToConsoleTaskReceiver::enableReceiver_(T & arg)
{
    return;
}

template<typename... Types>
void WriteTextToConsoleTaskReceiver::disableReceiver_(Types... args)
{
    // Disable the communicator.
    this->communicator_->freeCommunicator();
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_WriteTextToConsoleTaskReceiver_INC  ----- 
