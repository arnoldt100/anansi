#ifndef ANANSI_ErrorInvalidWorkloadDecompositionType_INC
#define ANANSI_ErrorInvalidWorkloadDecompositionType_INC
//! \file ErrorInvalidWorkloadDecompositionType.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BaseException.h"

namespace ANANSI
{

class ErrorInvalidWorkloadDecompositionType : MOUSEION::BaseException
{
    public:
        // ====================  LIFECYCLE     =======================================

        ErrorInvalidWorkloadDecompositionType ();   // constructor

        ErrorInvalidWorkloadDecompositionType (const ErrorInvalidWorkloadDecompositionType & other);   // copy constructor

        ErrorInvalidWorkloadDecompositionType (ErrorInvalidWorkloadDecompositionType && other);   // copy-move constructor

        virtual ~ErrorInvalidWorkloadDecompositionType ();  // destructor

        // ====================  ACCESSORS     =======================================
        const char* what() const noexcept; 

        ErrorInvalidWorkloadDecompositionType * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ErrorInvalidWorkloadDecompositionType& operator= ( const ErrorInvalidWorkloadDecompositionType &other ); // assignment operator

        ErrorInvalidWorkloadDecompositionType& operator= ( ErrorInvalidWorkloadDecompositionType && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ErrorInvalidWorkloadDecompositionType  -----


}; // namespace ANANSI

#endif // ANANSI_ErrorInvalidWorkloadDecompositionType_INC
