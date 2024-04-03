#ifndef ANANSI_PrecisionPolicy_INC
#define ANANSI_PrecisionPolicy_INC
//! \file PrecisionPolicy.h
//!
//! \brief Brief description
//!
//! \details Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "LowPrecision.h"
#include "MediumPrecision.h"
#include "HighPrecision.h"

namespace ANANSI
{

class PrecisionPolicy
{
    public:
        // ====================  LIFECYCLE     =======================================

#if ANANSI_COMPUTE_PRECISION == ANANSI_LOW_PRECISION
        using Type = LowPrecision;
#elif ANANSI_COMPUTE_PRECISION == ANANSI_MEDIUM_PRECISION 
        using Type = MediumPrecision;
#elif ANANSI_COMPUTE_PRECISION == ANANSI_HIGH_PRECISION 
        using Type = HighPrecision;
#else 
    using Type = MediumPrecision;
#endif 

        //! The default constructor.
        PrecisionPolicy ();   // constructor

        //! The copy constructor.
        PrecisionPolicy (const PrecisionPolicy & other);   // copy constructor

        //! The move constructor.
        PrecisionPolicy (PrecisionPolicy && other);   // copy-move constructor

        ~PrecisionPolicy ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        PrecisionPolicy * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        PrecisionPolicy& operator= ( const PrecisionPolicy &other ); // assignment operator

        //! The move assignment operator.
        PrecisionPolicy& operator= ( PrecisionPolicy && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class PrecisionPolicy  -----


}; // End of namespace ANANSI

#endif // ANANSI_PrecisionPolicy_INC
