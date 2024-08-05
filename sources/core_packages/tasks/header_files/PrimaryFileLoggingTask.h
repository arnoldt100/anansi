#ifndef ANANSI_LoggingTask_INC
#define ANANSI_LoggingTask_INC
//! @file PrimaryFileLoggingTask.h
//!
//! The base class for the logging tasks. 

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiTask.h"

namespace ANANSI
{

class PrimaryFileLoggingTask : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        PrimaryFileLoggingTask ();   // constructor

        PrimaryFileLoggingTask (const PrimaryFileLoggingTask & other);   // copy constructor

        PrimaryFileLoggingTask (PrimaryFileLoggingTask && other);   // copy-move constructor

        virtual ~PrimaryFileLoggingTask ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        PrimaryFileLoggingTask& operator= ( const PrimaryFileLoggingTask &other ); // assignment operator

        PrimaryFileLoggingTask& operator= ( PrimaryFileLoggingTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class PrimaryFileLoggingTask  -----


}; // namespace ANANSI

#endif // ANANSI_LoggingTask_INC
