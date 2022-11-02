#ifndef ANANSI_InitMPIEnvReceiver_INC
#define ANANSI_InitMPIEnvReceiver_INC

//! @file InitMPIEnvReceiver.h
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
#include "MPIEnvironment.h"

namespace ANANSI
{

class InitMPIEnvReceiver :  public RECEIVER::ReceiverInterface<InitMPIEnvReceiver>
{
    public:
        // ====================  LIFECYCLE     =======================================

        InitMPIEnvReceiver ();   // constructor

        InitMPIEnvReceiver (const InitMPIEnvReceiver & other);   // copy constructor

        InitMPIEnvReceiver (InitMPIEnvReceiver && other);   // copy-move constructor

        ~InitMPIEnvReceiver ();  // destructor

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

        InitMPIEnvReceiver& operator= ( const InitMPIEnvReceiver &other ); // assignment operator

        InitMPIEnvReceiver& operator= ( InitMPIEnvReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::shared_ptr<ANANSI::MPIEnvironment> mpiEnvironment_;

}; // -----  end of class InitMPIEnvReceiver  -----

template<typename... Types>
void InitMPIEnvReceiver::disableReceiver(Types... args)
{
    return;
}

template<typename... Types>
void InitMPIEnvReceiver::receiverDoAction(Types... args)
{
    return;
}

template<typename... Types>
void InitMPIEnvReceiver::receiverUndoAction(Types... args)
{
    this->mpiEnvironment_->disableEnvironment();
    return;
}

}; // namespace ANANSI

#endif // ANANSI_InitMPIEnvReceiver_INC
