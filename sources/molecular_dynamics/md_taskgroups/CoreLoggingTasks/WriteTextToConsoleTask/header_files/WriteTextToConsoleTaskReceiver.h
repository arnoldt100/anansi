#ifndef  ANANSI_WriteTextToConsoleTaskReceiver_INC
#define  ANANSI_WriteTextToConsoleTaskReceiver_INC

//! @file WriteTextToConsoleTaskReceiver.h
//!
//! Contains the declaration for WriteTextToConsoleTaskReceiver.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <memory>

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
#include "CopyOwnershipPolicy.hpp"

namespace ANANSI
{

//! The action of the reciever is to write a message to stdout.
//! 
//! The message store in messageContainer_ is written to stdout. There are no
//! results stored in the class and therfore all copying, sharing and
//! trasferring of results will result in an exception being thrown.
class WriteTextToConsoleTaskReceiver : public RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>
{
    public:
       
        //! The object type the smart pointer will manage,
        using receiver_result_t = int;

        template<typename T>
        using OwnershipPolicy = OwnershipImpl1<T>;

        //! The type of smart pointer that manages the receiver's result.
        using receiver_result_smart_pointer_t = std::unique_ptr<receiver_result_t>;

        // ====================  STATIC       =======================================

        static constexpr char tmpstr[RECEIVER::TaskLabelTraits::MAX_NM_CHARS] = 
            {'w','r','i', 't', 'e','_',
             't', 'e', 'x', 't', '_',
             't', 'o', '_',
             'c','o', 'n', 's', 'o', 'l', 'e'};

        static constexpr 
        RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::TASK_LABEL_TYPE(WriteTextToConsoleTaskReceiver::tmpstr);

        // ====================  LIFECYCLE     =======================================

        WriteTextToConsoleTaskReceiver ();   // constructor

        WriteTextToConsoleTaskReceiver (const WriteTextToConsoleTaskReceiver & other) = delete;   // copy constructor

        WriteTextToConsoleTaskReceiver (WriteTextToConsoleTaskReceiver && other);   // copy-move constructor

        ~WriteTextToConsoleTaskReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        constexpr RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel() const
        {
            return  WriteTextToConsoleTaskReceiver::TASKLABEL;
        }

        template<typename... Types>
        void receiverDoAction(Types & ... args) const;

        template<typename... Types>
        void receiverUndoAction(Types & ... args) const;

        OwnershipPolicy<receiver_result_t>::Copytype receiverGetCopyOfResults() const;

        // ====================  MUTATORS      =======================================
        
        template<typename... Types>
        void disableReceiver(Types... args);

        template<typename T>
        void receiverModifyMyself(T & arg);

        OwnershipPolicy<receiver_result_t>::Sharedtype receiverShareOwnershipOfResults();

        OwnershipPolicy<receiver_result_t>::Transfertype receiverTransferOwnershipOfResults();

        // ====================  OPERATORS     =======================================

        WriteTextToConsoleTaskReceiver& operator= ( const WriteTextToConsoleTaskReceiver &other ) = delete; // assignment operator

        WriteTextToConsoleTaskReceiver& operator= ( WriteTextToConsoleTaskReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable std::unique_ptr<COMMUNICATOR::Communicator> communicator_;
	    mutable std::unique_ptr<ConsoleMessageContainer> messageContainer_;
        ANANSI::CopyOwnershipPolicy<receiver_result_t,OwnershipPolicy> ownershipPolicy_;


        // mutable std::unique_ptr<receiver_result_t> results_;
        mutable  OwnershipPolicy<receiver_result_t>::Transfertype results_;

}; // -----  end of class WriteTextToConsoleTaskReceiver  -----

template<typename... Types>
void WriteTextToConsoleTaskReceiver::receiverDoAction(Types & ... args) const
{
    const auto message = this->messageContainer_->getMessage();
    std::cout << message << std::endl;
    *(this->results_) += 1;
    return;
}

template<typename... Types>
void WriteTextToConsoleTaskReceiver::receiverUndoAction(Types & ... args) const
{
    return;
}

template<typename... Types>
void WriteTextToConsoleTaskReceiver::disableReceiver(Types... args)
{
    // Disable the communicator.
    this->communicator_->freeCommunicator();
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_WriteTextToConsoleTaskReceiver_INC  ----- 
