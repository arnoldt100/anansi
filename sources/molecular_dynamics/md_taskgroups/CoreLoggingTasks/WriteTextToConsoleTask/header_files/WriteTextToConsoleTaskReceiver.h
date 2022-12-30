#ifndef  ANANSI_WriteTextToConsoleTaskReceiver_INC
#define  ANANSI_WriteTextToConsoleTaskReceiver_INC

//! @file WriteTextToConsoleTaskReceiver.h
//!
//! Brief description
//!
//! Detailed description

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

namespace ANANSI
{

class WriteTextToConsoleTaskReceiver : public RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>
{
    public:
        
        // ====================  STATIC       =======================================

        static constexpr char tmpstr[TaskLabelTraits::MAX_NM_CHARS] = 
            {'w','r','i', 't', 'e', '_', 't', 'e', 'x', 't', '_', 't', 'o', '_', 'c','o', 'n', 's', 'o', 'l', 'e'};

        static const 
        RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::TASK_LABEL_TYPE TASKLABEL;

        // ====================  LIFECYCLE     =======================================

        WriteTextToConsoleTaskReceiver ();   // constructor

        WriteTextToConsoleTaskReceiver (const WriteTextToConsoleTaskReceiver & other) = delete;   // copy constructor

        WriteTextToConsoleTaskReceiver (WriteTextToConsoleTaskReceiver && other);   // copy-move constructor

        ~WriteTextToConsoleTaskReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel() const;

        template<typename... Types>
        void receiverDoAction(Types & ... args) const;

        template<typename... Types>
        void receiverUndoAction(Types & ... args) const;

        // ====================  MUTATORS      =======================================
        
        template<typename T>
        void enableReceiver(T & arg);

        template<typename... Types>
        void disableReceiver(Types... args);

        template<typename T>
        void receiverModifyMyself(T & arg);

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

}; // -----  end of class WriteTextToConsoleTaskReceiver  -----

template<typename... Types>
void WriteTextToConsoleTaskReceiver::receiverDoAction(Types & ... args) const
{
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
