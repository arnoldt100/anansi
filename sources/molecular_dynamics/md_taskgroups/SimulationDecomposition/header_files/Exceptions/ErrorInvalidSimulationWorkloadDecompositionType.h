#ifndef ANANSI_ErrorInvalidSimulationWorkloadDecompositionType_INC
#define ANANSI_ErrorInvalidSimulationWorkloadDecompositionType_INC
//! \file ErrorInvalidSimulationWorkloadDecompositionType.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
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

class ErrorInvalidSimulationWorkloadDecompositionType : MOUSEION::BaseException 
{
    public:
        // ====================  LIFECYCLE     =======================================

        ErrorInvalidSimulationWorkloadDecompositionType ();   // constructor

        ErrorInvalidSimulationWorkloadDecompositionType ( const std::string message);   // constructor

        ErrorInvalidSimulationWorkloadDecompositionType (const ErrorInvalidSimulationWorkloadDecompositionType & other);   // copy constructor

        ErrorInvalidSimulationWorkloadDecompositionType (ErrorInvalidSimulationWorkloadDecompositionType && other);   // copy-move constructor

        ~ErrorInvalidSimulationWorkloadDecompositionType ();  // destructor

        // ====================  ACCESSORS     =======================================
        const char* what() const noexcept; 

        ErrorInvalidSimulationWorkloadDecompositionType * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ErrorInvalidSimulationWorkloadDecompositionType& operator= ( const ErrorInvalidSimulationWorkloadDecompositionType &other ); // assignment operator

        ErrorInvalidSimulationWorkloadDecompositionType& operator= ( ErrorInvalidSimulationWorkloadDecompositionType && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::string errorMessage_;

}; // -----  end of class ErrorInvalidSimulationWorkloadDecompositionType  -----


}; // namespace ANANSI

#endif // ANANSI_ErrorInvalidSimulationWorkloadDecompositionType_INC
