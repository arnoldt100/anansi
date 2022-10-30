#ifndef  ANANSI_ControlFileMPIXMLReceiver_INC
#define  ANANSI_ControlFileMPIXMLReceiver_INC

//! @file ControlFileMPIXMLReceiver.h
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

class ControlFileMPIXMLReceiver :  public RECEIVER::ReceiverInterface<ControlFileMPIXMLReceiver>
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFileMPIXMLReceiver ();   // constructor

        ControlFileMPIXMLReceiver (const ControlFileMPIXMLReceiver & other);   // copy constructor

        ControlFileMPIXMLReceiver (ControlFileMPIXMLReceiver && other);   // copy-move constructor

        ~ControlFileMPIXMLReceiver ();  // destructor

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

        ControlFileMPIXMLReceiver& operator= ( const ControlFileMPIXMLReceiver &other ); // assignment operator

        ControlFileMPIXMLReceiver& operator= ( ControlFileMPIXMLReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFileMPIXMLReceiver  -----

template<typename... Types>
void ControlFileMPIXMLReceiver::disableReceiver(Types... args)
{
    return;
}

template<typename... Types>
void ControlFileMPIXMLReceiver::receiverDoAction(Types... args)
{
    return;
}

template<typename... Types>
void ControlFileMPIXMLReceiver::receiverUndoAction(Types... args)
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileMPIXMLReceiver_INC  ----- 
