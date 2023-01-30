#ifndef ANANSI_ControlFileCommunicator_INC
#define ANANSI_ControlFileCommunicator_INC
//! @file ControlFileCommunicator.h
//!
//! The base class for the control file communicator task.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "AnansiTask.h"

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class ControlFileCommunicator : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFileCommunicator ();   // constructor

        ControlFileCommunicator (const ControlFileCommunicator & other);   // copy constructor

        ControlFileCommunicator (ControlFileCommunicator && other);   // copy-move constructor

        virtual ~ControlFileCommunicator ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileCommunicator& operator= ( const ControlFileCommunicator &other ); // assignment operator

        ControlFileCommunicator& operator= ( ControlFileCommunicator && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFileCommunicator  -----


}; // namespace ANANSI

#endif // ANANSI_ControlFileCommunicator_INC
