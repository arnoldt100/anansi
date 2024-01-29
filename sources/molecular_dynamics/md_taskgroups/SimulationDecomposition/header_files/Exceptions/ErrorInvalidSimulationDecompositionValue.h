#ifndef ANANSI_ErrorInvalidSimulationDecompositionValue_INC
#define ANANSI_ErrorInvalidSimulationDecompositionValue_INC
//! \file ErrorInvalidSimulationDecompositionValue.h

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

class ErrorInvalidSimulationDecompositionValue : public MOUSEION::BaseException
{
    public:
        // ====================  LIFECYCLE     =======================================

        ErrorInvalidSimulationDecompositionValue ();   // constructor

        ErrorInvalidSimulationDecompositionValue (const std::string message);   // constructor

        ErrorInvalidSimulationDecompositionValue (const ErrorInvalidSimulationDecompositionValue & other);   // copy constructor

        ErrorInvalidSimulationDecompositionValue (ErrorInvalidSimulationDecompositionValue && other);   // copy-move constructor

        ~ErrorInvalidSimulationDecompositionValue ();  // destructor

        // ====================  ACCESSORS     =======================================
        const char* what() const noexcept;

        ErrorInvalidSimulationDecompositionValue * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ErrorInvalidSimulationDecompositionValue& operator= ( const ErrorInvalidSimulationDecompositionValue &other ); // assignment operator

        ErrorInvalidSimulationDecompositionValue& operator= ( ErrorInvalidSimulationDecompositionValue && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::string errorMessage_;

}; // -----  end of class ErrorInvalidSimulationDecompositionValue  -----


}; // namespace ANANSI

#endif // ANANSI_ErrorInvalidSimulationDecompositionValue_INC
