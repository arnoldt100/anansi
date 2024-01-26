#ifndef ANANSI_ErrorInvalidSimulationDecompositionValue_INC
#define ANANSI_ErrorInvalidSimulationDecompositionValue_INC
//! \file ErrorInvalidSimulationDecompositionValue.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class ErrorInvalidSimulationDecompositionValue : public std::exception
{
    public:
        // ====================  LIFECYCLE     =======================================

        ErrorInvalidSimulationDecompositionValue ();   // constructor

        ErrorInvalidSimulationDecompositionValue (const ErrorInvalidSimulationDecompositionValue & other);   // copy constructor

        ErrorInvalidSimulationDecompositionValue (ErrorInvalidSimulationDecompositionValue && other);   // copy-move constructor

        virtual ~ErrorInvalidSimulationDecompositionValue ();  // destructor

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

}; // -----  end of class ErrorInvalidSimulationDecompositionValue  -----


}; // namespace ANANSI

#endif // ANANSI_ErrorInvalidSimulationDecompositionValue_INC
