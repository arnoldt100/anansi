#ifndef ANANSI_SimulationDecompositionResultsTraits_INC
#define ANANSI_SimulationDecompositionResultsTraits_INC
//! \file SimulationDecompositionResultsTraits.h
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
#include "Atoms.h"

namespace ANANSI
{

class SimulationDecompositionResultsTraits
{
    public:
        // ====================  ALIASES       =======================================
        
        //! A type erasure for the physical atoms of the system.
        using result_t = Atoms<>;

        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        SimulationDecompositionResultsTraits ();   // constructor

        //! The copy constructor.
        SimulationDecompositionResultsTraits (const SimulationDecompositionResultsTraits & other);   // copy constructor

        //! The move constructor.
        SimulationDecompositionResultsTraits (SimulationDecompositionResultsTraits && other);   // copy-move constructor

        //! The destructor.
        ~SimulationDecompositionResultsTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        SimulationDecompositionResultsTraits * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        SimulationDecompositionResultsTraits& operator= ( const SimulationDecompositionResultsTraits &other ); // assignment operator

        //! The move assignment operator.
        SimulationDecompositionResultsTraits& operator= ( SimulationDecompositionResultsTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class SimulationDecompositionResultsTraits  -----


}; // End of namespace ANANSI

#endif // ANANSI_SimulationDecompositionResultsTraits_INC
