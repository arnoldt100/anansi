#ifndef  ANANSI_InitWorldCommunicatorTaskReceiver_INC
#define  ANANSI_InitWorldCommunicatorTaskReceiver_INC

//! @file InitWorldCommunicatorTaskReceiver.h
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
#include "MPICommunicatorFactory.h"
#include "TaskLabel.hpp"
#include "TaskLabelTraits.hpp"


namespace ANANSI
{

class InitWorldCommunicatorTaskReceiver:  public RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>
{
    public:
        using receiver_result_t = int;

        // ====================  STATIC       =======================================

        static constexpr char tmpstr[TaskLabelTraits::MAX_NM_CHARS] = 
          {'m','p','i','_', 'w', 'o', 'r', 'l', 'd', '_', 'c', 'o','m', 'm', 'u', 'n', 'i', 'c', 'a', 't', 'o', 'r'};

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
        void receiverDoAction(Types & ...  args) const;

        template<typename... Types>
        void receiverUndoAction(Types &... args) const;

        // ====================  MUTATORS      =======================================
        
        template<typename T>
        void enableReceiver(T & arg);

        template<typename... Types>
        void disableReceiver(Types &...  args);

        template<typename T>
        void receiverModifyMyself(T & arg);

        // ====================  OPERATORS     =======================================

        InitWorldCommunicatorTaskReceiver& operator= ( const InitWorldCommunicatorTaskReceiver &other ) = delete; // assignment operator

        InitWorldCommunicatorTaskReceiver& operator= ( InitWorldCommunicatorTaskReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable std::shared_ptr<COMMUNICATOR::Communicator> communicator_;
        mutable receiver_result_t results_;

}; // -----  end of class InitWorldCommunicatorTaskReceiver  -----

template<typename... Types>
void InitWorldCommunicatorTaskReceiver::receiverDoAction(Types &...  args) const
{
    ANANSI::MPICommunicatorFactory a_communicator_factory;
    std::shared_ptr<COMMUNICATOR::Communicator> tmp_comm = a_communicator_factory.createWorldCommunicator();
    *(this->communicator_) = std::move(*tmp_comm);
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
    this->communicator_->freeCommunicator();
    this->communicator_.reset();
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitWorldCommunicatorTaskReceiver_INC  ----- 
