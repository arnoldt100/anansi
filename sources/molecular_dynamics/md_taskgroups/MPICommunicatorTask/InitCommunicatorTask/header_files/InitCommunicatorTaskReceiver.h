#ifndef  ANANSI_InitCommunicatorTaskReceiver_INC
#define  ANANSI_InitCommunicatorTaskReceiver_INC

//! @file __filename__
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

namespace ANANSI
{

class InitCommunicatorTaskReceiver:  public RECEIVER::ReceiverInterface<InitCommunicatorTaskReceiver>
{
    public:
        // ====================  LIFECYCLE     =======================================

        InitCommunicatorTaskReceiver ();   // constructor

        InitCommunicatorTaskReceiver (const InitCommunicatorTaskReceiver & other);   // copy constructor

        InitCommunicatorTaskReceiver (InitCommunicatorTaskReceiver && other);   // copy-move constructor

        ~InitCommunicatorTaskReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        template<typename T>
        void enableReceiver(T & arg);

        template<typename... Types>
        void disableReceiver(Types... args);

        template<typename... Types>
        void receiverDoAction(Types... args);

        template<typename... Types>
        void receiverUndoAction(Types... args);

        // ====================  OPERATORS     =======================================

        InitCommunicatorTaskReceiver& operator= ( const InitCommunicatorTaskReceiver &other ); // assignment operator

        InitCommunicatorTaskReceiver& operator= ( InitCommunicatorTaskReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::shared_ptr<COMMUNICATOR::Communicator> communicator_;

}; // -----  end of class InitCommunicatorTaskReceiver  -----

template<typename... Types>
void InitCommunicatorTaskReceiver::disableReceiver(Types... args)
{
    return;
}

template<typename... Types>
void InitCommunicatorTaskReceiver::receiverDoAction(Types... args)
{
    return;
}

template<typename... Types>
void InitCommunicatorTaskReceiver::receiverUndoAction(Types... args)
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitCommunicatorTaskReceiver_INC  ----- 
