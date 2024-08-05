#ifndef ANANSI_LoggingTask_INC
#define ANANSI_LoggingTask_INC
//! @file ConsoleLoggingTask.h
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

class ConsoleLoggingTask : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        ConsoleLoggingTask ();   // constructor

        ConsoleLoggingTask (const ConsoleLoggingTask & other);   // copy constructor

        ConsoleLoggingTask (ConsoleLoggingTask && other);   // copy-move constructor

        virtual ~ConsoleLoggingTask ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ConsoleLoggingTask& operator= ( const ConsoleLoggingTask &other ); // assignment operator

        ConsoleLoggingTask& operator= ( ConsoleLoggingTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ConsoleLoggingTask  -----


}; // namespace ANANSI

#endif // ANANSI_LoggingTask_INC
