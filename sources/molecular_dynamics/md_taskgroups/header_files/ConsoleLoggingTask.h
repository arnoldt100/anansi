#ifndef ANANSI_ConsoleLoggingTask_INC
#define ANANSI_ConsoleLoggingTask_INC
//! @file ConsoleLoggingTask.h
//!
//! Implements logging to the console (i.e. stdout).

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "LoggingTask.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  ConsoleLoggingTask
//  Description:  
//  =====================================================================================
class ConsoleLoggingTask : public LoggingTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        ConsoleLoggingTask ();   // constructor

        ConsoleLoggingTask (const ConsoleLoggingTask & other);   // copy constructor

        ConsoleLoggingTask (ConsoleLoggingTask && other);   // copy-move constructor

        virtual ~ConsoleLoggingTask ();  // destructor

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

#endif // ANANSI_ConsoleLoggingTask_INC
