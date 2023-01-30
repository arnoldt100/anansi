
#ifndef  ANANSI_ControlFileMPICommReceiver_INC
#define  ANANSI_ControlFileMPICommReceiver_INC

//! @file ControlFileMPICommReceiver.h
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

class ControlFileMPICommReceiver :  public RECEIVER::ReceiverInterface<ControlFileMPICommReceiver>
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFileMPICommReceiver ();   // constructor

        ControlFileMPICommReceiver (const ControlFileMPICommReceiver & other);   // copy constructor

        ControlFileMPICommReceiver (ControlFileMPICommReceiver && other);   // copy-move constructor

        ~ControlFileMPICommReceiver ();  // destructor

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

        ControlFileMPICommReceiver& operator= ( const ControlFileMPICommReceiver &other ); // assignment operator

        ControlFileMPICommReceiver& operator= ( ControlFileMPICommReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFileMPICommReceiver  -----

template<typename... Types>
void ControlFileMPICommReceiver::disableReceiver(Types... args)
{
    return;
}

template<typename... Types>
void ControlFileMPICommReceiver::receiverDoAction(Types... args)
{
    return;
}

template<typename... Types>
void ControlFileMPICommReceiver::receiverUndoAction(Types... args)
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileMPICommReceiver_INC  ----- 
