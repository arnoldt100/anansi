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
#include "ReceiverInterface.hpp"
#include "TaskLabel.hpp"
#include "ReceiverResultTraits.hpp"
#include "WriteTextToConsoleTaskOwnershipImpl.hpp"
#include "Communicator.h"
#include "ConsoleMessageContainer.h"
#include "OwnershipTypes.hpp"

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
    private:

        static constexpr char tmpstr_[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'w','r','i', 't', 'e','_',
             't', 'e', 'x', 't', '_',
             't', 'o', '_',
             'c','o', 'n', 's', 'o', 'l', 'e'};

        using my_result_type_ = int;
        using my_copy_type_ = int;
        using my_share_type_ = int;
        using my_transfer_type_ = int;
        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                     my_copy_type_,
                                                                     my_share_type_,
                                                                     my_transfer_type_>;
        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes_ = RECEIVER::ReceiverOwnershipType<Q,MyOwnershipImplTraits_>;

        using MyOwnershipImpl_ = WriteTextToConsoleTaskOwnershipImpl<MyOwnershipImplTraits_>;
        using MyOwnershipPolicy_ = ANANSI::CopyOwnershipPolicy<MyOwnershipImpl_>;
    public:
       
        using receiver_result_t = MyOwnershipImplTraits_::Resulttype;
        using receiver_copy_t = MyOwnershipTypes_<RECEIVER::OwnershipTypes::COPYTYPE>::TYPE;
        using receiver_share_t = MyOwnershipTypes_<RECEIVER::OwnershipTypes::SHARETYPE>::TYPE;
        using receiver_transfer_t = MyOwnershipTypes_<RECEIVER::OwnershipTypes::TRANSFERTYPE>::TYPE;

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

        WriteTextToConsoleTaskReceiver::receiver_copy_t receiverGetCopyOfResults_() const;

        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void enableReceiver_(Types &... args);

        template<typename... Types>
        void disableReceiver_(Types ...  args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        WriteTextToConsoleTaskReceiver::receiver_transfer_t receiverTransferOwnershipOfResults_();

        WriteTextToConsoleTaskReceiver::receiver_share_t receiverShareOwnershipOfResults_();

        // ====================  DATA MEMBERS  =======================================

    private:

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable receiver_result_t results_;
        mutable std::unique_ptr<COMMUNICATOR::Communicator> communicator_;
	    mutable std::unique_ptr<ConsoleMessageContainer> messageContainer_;
        MyOwnershipPolicy_ ownershipPolicy_;

}; // -----  end of class WriteTextToConsoleTaskReceiver  -----

template<typename... Types>
void WriteTextToConsoleTaskReceiver::receiverDoAction_(Types & ... args) const
{
    const auto message = this->messageContainer_->getMessage();
    std::cout << message << std::endl;
    this->results_ += 1;
    return;
}

template<typename... Types>
void WriteTextToConsoleTaskReceiver::receiverUndoAction_(Types & ... args) const
{
    return;
}

template<typename... Types>
void WriteTextToConsoleTaskReceiver::enableReceiver_(Types & ... args)
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
