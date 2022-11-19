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
#include "MPICommunicatorFactory.h"
#include "ReceiverInterface.hpp"

namespace ANANSI
{

class InitWorldCommunicatorTaskReceiver:  public RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>
{
    public:
        // ====================  STATIC       =======================================

        inline static const RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::TASK_LABEL_TYPE TASKLABEL =
            "mpi_world_communicator";

        // ====================  LIFECYCLE     =======================================

        InitWorldCommunicatorTaskReceiver ();   // constructor

        InitWorldCommunicatorTaskReceiver (const InitWorldCommunicatorTaskReceiver & other);   // copy constructor

        InitWorldCommunicatorTaskReceiver (InitWorldCommunicatorTaskReceiver && other);   // copy-move constructor

        ~InitWorldCommunicatorTaskReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel() const;

        // ====================  MUTATORS      =======================================
        
        template<typename T>
        void enableReceiver(T & arg);

        template<typename... Types>
        void disableReceiver(Types... args);

        template<typename... Types>
        void receiverDoAction(Types... args);

        template<typename... Types>
        void receiverUndoAction(Types... args);

        template<typename T>
        void receiverModifyMyself(T & arg);

        // ====================  OPERATORS     =======================================

        InitWorldCommunicatorTaskReceiver& operator= ( const InitWorldCommunicatorTaskReceiver &other ); // assignment operator

        InitWorldCommunicatorTaskReceiver& operator= ( InitWorldCommunicatorTaskReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::shared_ptr<COMMUNICATOR::Communicator> communicator_;

}; // -----  end of class InitWorldCommunicatorTaskReceiver  -----

template<typename... Types>
void InitWorldCommunicatorTaskReceiver::receiverDoAction(Types... args)
{
    ANANSI::MPICommunicatorFactory a_communicator_factory;
    std::shared_ptr<COMMUNICATOR::Communicator> tmp_comm = a_communicator_factory.createWorldCommunicator();
    this->receiverModifyMyself(tmp_comm);
    return;
}

template<typename... Types>
void InitWorldCommunicatorTaskReceiver::receiverUndoAction(Types... args)
{
    this->communicator_->freeCommunicator();
    this->communicator_.reset();
    return;
}

template<typename... Types>
void InitWorldCommunicatorTaskReceiver::disableReceiver(Types... args)
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitWorldCommunicatorTaskReceiver_INC  ----- 
