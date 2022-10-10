#ifndef ANANSI_MPIEnvReceiver_INC
#define ANANSI_MPIEnvReceiver_INC
//! @file MPIEnvReceiver
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

namespace ANANSI
{

class MPIEnvReceiver :  public RECEIVER::ReceiverInterface<MPIEnvReceiver>
{
    public:
        // ====================  LIFECYCLE     =======================================

        MPIEnvReceiver ();   // constructor

        MPIEnvReceiver (const MPIEnvReceiver & other);   // copy constructor

        MPIEnvReceiver (MPIEnvReceiver && other);   // copy-move constructor

        ~MPIEnvReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        template<typename... Types>
        void enableReceiver(Types... args);

        template<typename... Types>
        void disableReceiver(Types... args);

        template<typename... Types>
        void receiverDoAction(Types... args);

        template<typename... Types>
        void receiverUndoAction(Types... args);

        // ====================  OPERATORS     =======================================

        MPIEnvReceiver& operator= ( const MPIEnvReceiver &other ); // assignment operator

        MPIEnvReceiver& operator= ( MPIEnvReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MPIEnvReceiver  -----

template<typename... Types>
void MPIEnvReceiver::enableReceiver(Types... args)
{
    return;
}

template<typename... Types>
void MPIEnvReceiver::disableReceiver(Types... args)
{
    return;
}

template<typename... Types>
void MPIEnvReceiver::receiverDoAction(Types... args)
{
    return;
}

template<typename... Types>
void MPIEnvReceiver::receiverUndoAction(Types... args)
{
    return;
}

}; // namespace ANANSI

#endif // ANANSI_MPIEnvReceiver_INC
