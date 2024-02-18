#ifndef ANANSI_SimulationDecompositionTaskTraits_INC
#define ANANSI_SimulationDecompositionTaskTraits_INC
//! \file SimulationDecompositionTaskTraits.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"
#include "GenericMDTask.hpp"

// Includes for abstract tasks.
#include "AtomsCommunicator.h"
#include "AtomsDecomposer.h"
#include "ReadAtoms.h"
#include "MacroCommand.hpp"


namespace ANANSI
{

class SimulationDecompositionTaskTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        SimulationDecompositionTaskTraits ();   // constructor

        //! The copy constructor.
        SimulationDecompositionTaskTraits (const SimulationDecompositionTaskTraits & other);   // copy constructor

        //! The move constructor.
        SimulationDecompositionTaskTraits (SimulationDecompositionTaskTraits && other);   // copy-move constructor

        virtual ~SimulationDecompositionTaskTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        SimulationDecompositionTaskTraits * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        SimulationDecompositionTaskTraits& operator= ( const SimulationDecompositionTaskTraits &other ); // assignment operator

        //! The move assignment operator.
        SimulationDecompositionTaskTraits& operator= ( SimulationDecompositionTaskTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class SimulationDecompositionTaskTraits  -----


}; // End of namespace ANANSI

#endif // ANANSI_SimulationDecompositionTaskTraits_INC
