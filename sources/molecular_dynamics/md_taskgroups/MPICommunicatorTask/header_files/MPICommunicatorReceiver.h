#ifndef ANANSI_MPICommunicatorReceiver_INC
#define ANANSI_MPICommunicatorReceiver_INC

//! @file MPICommunicatorReceiver.h
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReceiverInterface.hpp"
#include "Communicator.h"

namespace ANANSI
{

class MPICommunicatorReceiver :  public RECEIVER::ReceiverInterface<MPICommunicatorReceiver>
{
    public:
        // ====================  LIFECYCLE     =======================================

        MPICommunicatorReceiver ();   // constructor

        MPICommunicatorReceiver (const MPICommunicatorReceiver & other);   // copy constructor

        MPICommunicatorReceiver (MPICommunicatorReceiver && other);   // copy-move constructor

        ~MPICommunicatorReceiver ();  // destructor

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

        MPICommunicatorReceiver& operator= ( const MPICommunicatorReceiver &other ); // assignment operator

        MPICommunicatorReceiver& operator= ( MPICommunicatorReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::shared_ptr<COMMUNICATOR::Communicator> communicator_;

}; // -----  end of class MPICommunicatorReceiver  -----

template<typename... Types>
void MPICommunicatorReceiver::disableReceiver(Types... args)
{
    return;
}

template<typename... Types>
void MPICommunicatorReceiver::receiverDoAction(Types... args)
{
    return;
}

template<typename... Types>
void MPICommunicatorReceiver::receiverUndoAction(Types... args)
{
    return;
}

}; // namespace ANANSI

#endif // ANANSI_MPICommunicatorReceiver_INC
