#ifndef  ANANSI_ControlFileXML_INC
#define  ANANSI_ControlFileXML_INC

//! @file ControlFileXMLReceiver.h
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

class ControlFileXMLReceiver :  public RECEIVER::ReceiverInterface<ControlFileXMLReceiver>
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFileXMLReceiver ();   // constructor

        ControlFileXMLReceiver (const ControlFileXMLReceiver & other);   // copy constructor

        ControlFileXMLReceiver (ControlFileXMLReceiver && other);   // copy-move constructor

        ~ControlFileXMLReceiver ();  // destructor

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

        ControlFileXMLReceiver& operator= ( const ControlFileXMLReceiver &other ); // assignment operator

        ControlFileXMLReceiver& operator= ( ControlFileXMLReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFileXMLReceiver  -----

template<typename... Types>
void ControlFileXMLReceiver::disableReceiver(Types... args)
{
    return;
}

template<typename... Types>
void ControlFileXMLReceiver::receiverDoAction(Types... args)
{
    return;
}

template<typename... Types>
void ControlFileXMLReceiver::receiverUndoAction(Types... args)
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileXML_INC  ----- 
