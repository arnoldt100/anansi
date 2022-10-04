#ifndef ANANSI_ConsoleLoggingTask_INC
#define ANANSI_ConsoleLoggingTask_INC
//! @file ConsoleLoggingTask.h
//!
//! Implements logging to the console (i.e. stdout).

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskInterface.hpp"
#include "LoggingTask.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  ConsoleLoggingTask
//  Description:  
//  =====================================================================================
class ConsoleLoggingTask final : public TaskInterface<ConsoleLoggingTask >,
                                 public LoggingTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        ConsoleLoggingTask ();   // constructor

        ConsoleLoggingTask (const ConsoleLoggingTask & other);   // copy constructor

        ConsoleLoggingTask (ConsoleLoggingTask && other);   // copy-move constructor

        virtual ~ConsoleLoggingTask ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        void enableConcreteTask()
        {
            std::cout << "Enabling concrete task ConsoleLoggingTask." << std::endl;
        }

        void disableConcreteTask()
        {
            std::cout << "Disabling concrete task ConsoleLoggingTask." << std::endl;
        }

        void executeConcreteTask()
        {
            std::cout << "Executing concrete task ConsoleLoggingTask." << std::endl;
        }

        // ====================  OPERATORS     =======================================

        ConsoleLoggingTask& operator= ( const ConsoleLoggingTask &other ); // assignment operator

        ConsoleLoggingTask& operator= ( ConsoleLoggingTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================
        void enable_() override;

        void disable_() override;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ConsoleLoggingTask  -----


}; // namespace ANANSI

#endif // ANANSI_ConsoleLoggingTask_INC
