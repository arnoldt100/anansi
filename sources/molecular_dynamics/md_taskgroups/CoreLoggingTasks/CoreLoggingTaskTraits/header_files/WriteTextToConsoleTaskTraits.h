#ifndef ANANSI_WriteTextToConsoleTaskTraits_INC
#define ANANSI_WriteTextToConsoleTaskTraits_INC
//! @file WriteTextToConsoleTaskTraits.h
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
//        Class:  WriteTextToConsoleTaskTraits
//  Description:  
//  =====================================================================================
class WriteTextToConsoleTaskTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        WriteTextToConsoleTaskTraits ();   // constructor

        WriteTextToConsoleTaskTraits (const WriteTextToConsoleTaskTraits & other);   // copy constructor

        WriteTextToConsoleTaskTraits (WriteTextToConsoleTaskTraits && other);   // copy-move constructor

        ~WriteTextToConsoleTaskTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        WriteTextToConsoleTaskTraits& operator= ( const WriteTextToConsoleTaskTraits &other ); // assignment operator

        WriteTextToConsoleTaskTraits& operator= ( WriteTextToConsoleTaskTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class WriteTextToConsoleTaskTraits  -----


}; // namespace ANANSI

#endif // ANANSI_WriteTextToConsoleTaskTraits_INC
