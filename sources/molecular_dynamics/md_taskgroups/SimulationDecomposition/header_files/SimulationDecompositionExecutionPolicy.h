#ifndef ANANSI_SimulationDecompositionExecutionPolicy_INC
#define ANANSI_SimulationDecompositionExecutionPolicy_INC
//! \file SimulationDecompositionExecutionPolicy.h
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
#include "DataStoragePolicy.h"
#include "PrecisionPolicy.h"

namespace ANANSI
{

class SimulationDecompositionExecutionPolicy
{
    public:
        using DATA_STORAGE_POLICY = DataStoragePolicy;
        using DATA_PRECISION_POLICY = PrecisionPolicy;

        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        SimulationDecompositionExecutionPolicy ();   // constructor

        //! The copy constructor.
        SimulationDecompositionExecutionPolicy (const SimulationDecompositionExecutionPolicy & other);   // copy constructor

        //! The move constructor.
        SimulationDecompositionExecutionPolicy (SimulationDecompositionExecutionPolicy && other);   // copy-move constructor

        ~SimulationDecompositionExecutionPolicy ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        SimulationDecompositionExecutionPolicy * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        SimulationDecompositionExecutionPolicy& operator= ( const SimulationDecompositionExecutionPolicy &other ); // assignment operator

        //! The move assignment operator.
        SimulationDecompositionExecutionPolicy& operator= ( SimulationDecompositionExecutionPolicy && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class SimulationDecompositionExecutionPolicy  -----


}; // End of namespace ANANSI

#endif // ANANSI_SimulationDecompositionExecutionPolicy_INC
