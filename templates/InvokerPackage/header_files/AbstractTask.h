#ifndef ANANSI_LoggingTask_INC
#define ANANSI_LoggingTask_INC
//! @file AbstractTask.h
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

class AbstractTask : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        AbstractTask ();   // constructor

        AbstractTask (const AbstractTask & other);   // copy constructor

        AbstractTask (AbstractTask && other);   // copy-move constructor

        virtual ~AbstractTask ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        AbstractTask& operator= ( const AbstractTask &other ); // assignment operator

        AbstractTask& operator= ( AbstractTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AbstractTask  -----


}; // namespace ANANSI

#endif // ANANSI_LoggingTask_INC
