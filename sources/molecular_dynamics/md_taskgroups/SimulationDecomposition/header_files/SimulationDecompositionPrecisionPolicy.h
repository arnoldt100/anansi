#ifndef ANANSI_SimulationDecompositionPrecisionPolicy_INC
#define ANANSI_SimulationDecompositionPrecisionPolicy_INC
//! \file SimulationDecompositionPrecisionPolicy.h
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
#include "PrecisionPolicy.h"

namespace ANANSI
{

class SimulationDecompositionPrecisionPolicy
{
    public:
        using Type = PrecisionPolicy::Type;
        
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        SimulationDecompositionPrecisionPolicy ();   // constructor

        //! The copy constructor.
        SimulationDecompositionPrecisionPolicy (const SimulationDecompositionPrecisionPolicy & other);   // copy constructor

        //! The move constructor.
        SimulationDecompositionPrecisionPolicy (SimulationDecompositionPrecisionPolicy && other);   // copy-move constructor

         ~SimulationDecompositionPrecisionPolicy ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        SimulationDecompositionPrecisionPolicy * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        SimulationDecompositionPrecisionPolicy& operator= ( const SimulationDecompositionPrecisionPolicy &other ); // assignment operator

        //! The move assignment operator.
        SimulationDecompositionPrecisionPolicy& operator= ( SimulationDecompositionPrecisionPolicy && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class SimulationDecompositionPrecisionPolicy  -----


}; // End of namespace ANANSI

#endif // ANANSI_SimulationDecompositionPrecisionPolicy_INC
