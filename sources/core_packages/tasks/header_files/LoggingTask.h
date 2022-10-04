#ifndef ANANSI_LoggingTask_INC
#define ANANSI_LoggingTask_INC
//! @file LoggingTask.h
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

class LoggingTask : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        LoggingTask ();   // constructor

        LoggingTask (const LoggingTask & other);   // copy constructor

        LoggingTask (LoggingTask && other);   // copy-move constructor

        virtual ~LoggingTask ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        LoggingTask& operator= ( const LoggingTask &other ); // assignment operator

        LoggingTask& operator= ( LoggingTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        void enable_() override;
        
        void disable_() override;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class LoggingTask  -----


}; // namespace ANANSI

#endif // ANANSI_LoggingTask_INC
