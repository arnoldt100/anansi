#ifndef ANANSI_ErrorMissingSimulationWorkloadDecompositionParameters_INC
#define ANANSI_ErrorMissingSimulationWorkloadDecompositionParameters_INC
//! \file ErrorMissingSimulationWorkloadDecompositionParameters.h

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

class ErrorMissingSimulationWorkloadDecompositionParameters : MOUSEION::BaseException
{
    public:
        // ====================  LIFECYCLE     =======================================

        ErrorMissingSimulationWorkloadDecompositionParameters ();   // constructor

        ErrorMissingSimulationWorkloadDecompositionParameters (const std::string message);   // constructor

        ErrorMissingSimulationWorkloadDecompositionParameters (const ErrorMissingSimulationWorkloadDecompositionParameters & other);   // copy constructor

        ErrorMissingSimulationWorkloadDecompositionParameters (ErrorMissingSimulationWorkloadDecompositionParameters && other);   // copy-move constructor

        ~ErrorMissingSimulationWorkloadDecompositionParameters ();  // destructor

        // ====================  ACCESSORS     =======================================

        const char* what () const noexcept;

        ErrorMissingSimulationWorkloadDecompositionParameters * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ErrorMissingSimulationWorkloadDecompositionParameters& operator= ( const ErrorMissingSimulationWorkloadDecompositionParameters &other ); // assignment operator

        ErrorMissingSimulationWorkloadDecompositionParameters& operator= ( ErrorMissingSimulationWorkloadDecompositionParameters && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::string errorMessage_;

}; // -----  end of class ErrorMissingSimulationWorkloadDecompositionParameters  -----


}; // namespace ANANSI

#endif // ANANSI_ErrorMissingSimulationWorkloadDecompositionParameters_INC
