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

namespace ANANSI
{

//! This class contains the typelists of receivers needed to
//! do the simulation decomposition tasks.
//!
//! The following tasks need to be performed:
//! | Task                                                        | Receiver                      | Result                    |
//! | ----------------------------------------------------------- | ------------------------------|-------------------------- |
//! | Read the atoms from the input file.                         | ReadAtomicCoordinatesReceiver | Atoms                     |
//! | Partition atoms with the appropiate decomposition algorithm | AtomDecomposerReceiver        | Atoms                     |
//! | Communicate the atoms to the appropiate spatial domains     | AtomCommunicatorReceiver      | Atoms                     |

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

        //! The destructor.
        ~SimulationDecompositionTaskTraits ();  // destructor

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
