#ifndef ANANSI_CoreLoggingTaskTraits_INC
#define ANANSI_CoreLoggingTaskTraits_INC
//! @file CoreLoggingTaskTraits.h
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
//        Class:  CoreLoggingTaskTraits
//  Description:  
//  =====================================================================================
class CoreLoggingTaskTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        CoreLoggingTaskTraits ();   // constructor

        CoreLoggingTaskTraits (const CoreLoggingTaskTraits & other);   // copy constructor

        CoreLoggingTaskTraits (CoreLoggingTaskTraits && other);   // copy-move constructor

        ~CoreLoggingTaskTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        CoreLoggingTaskTraits& operator= ( const CoreLoggingTaskTraits &other ); // assignment operator

        CoreLoggingTaskTraits& operator= ( CoreLoggingTaskTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class CoreLoggingTaskTraits  -----


}; // namespace ANANSI

#endif // ANANSI_CoreLoggingTaskTraits_INC
