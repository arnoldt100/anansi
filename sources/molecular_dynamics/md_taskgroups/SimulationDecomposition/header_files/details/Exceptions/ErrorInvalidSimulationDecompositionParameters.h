#ifndef ANANSI_ErrorInvalidSimulationDecompositionParameters_INC
#define ANANSI_ErrorInvalidSimulationDecompositionParameters_INC
//! \file ErrorInvalidSimulationDecompositionParameters.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BaseException.h"

namespace ANANSI
{

class ErrorInvalidSimulationDecompositionParameters : public MOUSEION::BaseException
{
    public:
        // ====================  LIFECYCLE     =======================================

        ErrorInvalidSimulationDecompositionParameters ();   // constructor

        ErrorInvalidSimulationDecompositionParameters (const std::string message);   // constructor

        ErrorInvalidSimulationDecompositionParameters (const ErrorInvalidSimulationDecompositionParameters & other);   // copy constructor

        ErrorInvalidSimulationDecompositionParameters (ErrorInvalidSimulationDecompositionParameters && other);   // copy-move constructor

        ~ErrorInvalidSimulationDecompositionParameters ();  // destructor

        // ====================  ACCESSORS     =======================================
        const char* what() const noexcept;

        ErrorInvalidSimulationDecompositionParameters * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ErrorInvalidSimulationDecompositionParameters& operator= ( const ErrorInvalidSimulationDecompositionParameters &other ); // assignment operator

        ErrorInvalidSimulationDecompositionParameters& operator= ( ErrorInvalidSimulationDecompositionParameters && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::string errorMessage_;

}; // -----  end of class ErrorInvalidSimulationDecompositionParameters  -----


}; // namespace ANANSI

#endif // ANANSI_ErrorInvalidSimulationDecompositionParameters_INC
