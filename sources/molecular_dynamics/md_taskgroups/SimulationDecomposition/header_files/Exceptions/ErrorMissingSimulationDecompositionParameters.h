#ifndef ANANSI_ErrorMissingSimulationDecompositionParameters_INC
#define ANANSI_ErrorMissingSimulationDecompositionParameters_INC
//! \file ErrorMissingSimulationDecompositionParameters.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BaseException.h"

namespace ANANSI
{

class ErrorMissingSimulationDecompositionParameters : MOUSEION::BaseException
{
    public:
        // ====================  LIFECYCLE     =======================================

        ErrorMissingSimulationDecompositionParameters ();   // constructor

        ErrorMissingSimulationDecompositionParameters (const std::string message);   // constructor

        ErrorMissingSimulationDecompositionParameters (const ErrorMissingSimulationDecompositionParameters & other);   // copy constructor

        ErrorMissingSimulationDecompositionParameters (ErrorMissingSimulationDecompositionParameters && other);   // copy-move constructor

        ~ErrorMissingSimulationDecompositionParameters ();  // destructor

        // ====================  ACCESSORS     =======================================

        const char* what () const noexcept;

        ErrorMissingSimulationDecompositionParameters * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ErrorMissingSimulationDecompositionParameters& operator= ( const ErrorMissingSimulationDecompositionParameters &other ); // assignment operator

        ErrorMissingSimulationDecompositionParameters& operator= ( ErrorMissingSimulationDecompositionParameters && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::string errorMessage_;

}; // -----  end of class ErrorMissingSimulationDecompositionParameters  -----


}; // namespace ANANSI

#endif // ANANSI_ErrorMissingSimulationDecompositionParameters_INC
