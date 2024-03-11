#ifndef ANANSI_PointAtomsCommunicatorResultsTraits_INC
#define ANANSI_PointAtomsCommunicatorResultsTraits_INC
//! \file PointAtomsCommunicatorResultsTraits.h
//!
//! \brief Contains traits class for PointAtomsCommunicator result..

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
#include "PointAtoms.h"

namespace ANANSI
{

//! \brief The traits class for the PointAtomsCommunicator result.
class PointAtomsCommunicatorResultsTraits
{
    public:
        // ====================  ALIASES       =======================================
        using Atoms_t = PointAtoms;
        using result_t = Atoms;
        using copy_result_t = result_t;
        using share_result_t = result_t;
        using transfer_result_t = result_t;

        // ====================  LIFECYCLE     =======================================

        PointAtomsCommunicatorResultsTraits ();   // constructor

        PointAtomsCommunicatorResultsTraits (const PointAtomsCommunicatorResultsTraits & other);   // copy constructor

        PointAtomsCommunicatorResultsTraits (PointAtomsCommunicatorResultsTraits && other);   // copy-move constructor

        ~PointAtomsCommunicatorResultsTraits ();  // destructor

        // ====================  ACCESSORS     =======================================
        PointAtomsCommunicatorResultsTraits * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        PointAtomsCommunicatorResultsTraits& operator= ( const PointAtomsCommunicatorResultsTraits &other ); // assignment operator

        PointAtomsCommunicatorResultsTraits& operator= ( PointAtomsCommunicatorResultsTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // ----  End of class PointAtomsCommunicatorResultsTraits  -----
}; // ----- End of namespace ANANSI -----

#endif // ANANSI_PointAtomsCommunicatorResultsTraits_INC
