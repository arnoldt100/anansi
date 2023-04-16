#ifndef  ANANSI_InitWorldCommunicatorTaskReceiver_INC
#define  ANANSI_InitWorldCommunicatorTaskReceiver_INC

//! @file InitWorldCommunicatorTaskReceiver.h

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
#include "MPICommunicatorFactory.h"
#include "TaskLabel.hpp"
#include "TaskLabelTraits.hpp"


namespace ANANSI
{

//! InitWorldCommunicatorTaskReceiver creates a world communicator.
//!
//! Below is a summary of the critical methods of InitWorldCommunicatorTaskReceiver.
//!
//! This class is non-copyable for we need the communicator resource created by
//! the class to be solely owned by the object.
//!
//! The method receiverModifyMyself modifies the data members of
//! InitWorldCommunicatorTaskReceiver.
//!
//! The result of method receiverdoAction_ is the creation of the resource world
//! communicator which the receiver owns by means of a unique_ptr. Invoking
//! method receiverGetCopyOfResults returns a smart pointer that is a duplicate
//! of the original world communicator resource.
//!
//! The result of method receiverUndoAction undoes the action of
//! receiverdoAction. For actions that can't be undone this is null action,
//! however in this case the world communicator is destroyed.
//!
//! Invoking method receiverGetCopyOfResults returns a smart pointer that is a
//! duplicate of the original world communicator resource.
//!
//! Invoking method disableReceiver results in the destruction of the world
//! communicator resource. After this call, all other calls will result in 
//! an error being thrown.
class InitWorldCommunicatorTaskReceiver:  public RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>
{
    private: 
        using COMMUNICATOR_t = COMMUNICATOR::Communicator;

    public:
        //! The type of the data member results_.
        using receiver_result_t = std::unique_ptr<COMMUNICATOR_t>;

        // ====================  STATIC       =======================================

        static constexpr char tmpstr[RECEIVER::TaskLabelTraits::MAX_NM_CHARS] = 
          {'m','p','i','_', 
           'w', 'o', 'r', 'l', 'd', '_', 
           'c', 'o','m', 'm', 'u', 'n', 'i', 'c', 'a', 't', 'o', 'r'};

        static constexpr RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::TASK_LABEL_TYPE(InitWorldCommunicatorTaskReceiver::tmpstr);

        // ====================  LIFECYCLE     =======================================

        InitWorldCommunicatorTaskReceiver ();   // constructor

        InitWorldCommunicatorTaskReceiver (const InitWorldCommunicatorTaskReceiver & other) = delete;   // copy constructor

        InitWorldCommunicatorTaskReceiver (InitWorldCommunicatorTaskReceiver && other);   // copy-move constructor

        ~InitWorldCommunicatorTaskReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel() const;

        template<typename... Types>
        void receiverUndoAction(Types &... args) const;

        std::unique_ptr<receiver_result_t> receiverGetCopyOfResults() const;

        // ====================  MUTATORS      =======================================
        
        template<typename... Types>
        void disableReceiver(Types &...  args);

        template<typename T>
        void receiverModifyMyself(T & arg);

        // ====================  OPERATORS     =======================================

        InitWorldCommunicatorTaskReceiver& operator= ( const InitWorldCommunicatorTaskReceiver &other ) = delete; // assignment operator

        InitWorldCommunicatorTaskReceiver& operator= ( InitWorldCommunicatorTaskReceiver && other ); // assignment-move operator

    protected:

        // ====================  ACCESSORS     =======================================
        template<typename... Types>
        void receiverDoAction_(Types & ...  args) const;

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable receiver_result_t results_;

}; // -----  end of class InitWorldCommunicatorTaskReceiver  -----

template<typename... Types>
void InitWorldCommunicatorTaskReceiver::receiverDoAction_(Types &...  args) const
{
    // This class doesn't have a do action implemented.
    return;
}

template<typename... Types>
void InitWorldCommunicatorTaskReceiver::receiverUndoAction(Types &... args) const
{
    // This class doesn't have an undo action.
    return;
}

template<typename... Types>
void InitWorldCommunicatorTaskReceiver::disableReceiver(Types &...  args) 
{
    this->results_->freeCommunicator();
    this->results_.reset();
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitWorldCommunicatorTaskReceiver_INC  ----- 
