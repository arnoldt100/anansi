#ifndef ANANSI_CoreLoggingTasksTraits_INC
#define ANANSI_CoreLoggingTasksTraits_INC
//! @file CoreLoggingTasksTraits.h
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
#include "MPLAliases.hpp"
#include "WriteTextToConsoleTaskReceiver.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  CoreLoggingTasksTraits
//  Description:  
//  =====================================================================================
class CoreLoggingTasksTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        CoreLoggingTasksTraits ();   // constructor

        CoreLoggingTasksTraits (const CoreLoggingTasksTraits & other);   // copy constructor

        CoreLoggingTasksTraits (CoreLoggingTasksTraits && other);   // copy-move constructor

        ~CoreLoggingTasksTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        CoreLoggingTasksTraits& operator= ( const CoreLoggingTasksTraits &other ); // assignment operator

        CoreLoggingTasksTraits& operator= ( CoreLoggingTasksTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class CoreLoggingTasksTraits  -----


}; // namespace ANANSI

#endif // ANANSI_CoreLoggingTasksTraits_INC
