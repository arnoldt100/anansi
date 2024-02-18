#ifndef ANANSI_PointAtomsCommunicatorResultsTraits_INC
#define ANANSI_PointAtomsCommunicatorResultsTraits_INC
//! \file PointAtomsCommunicatorResultsTraits.h
//!
//! \brief Brief description
//!
//! \details  Detailed description

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

class PointAtomsCommunicatorResultsTraits
{
    public:
        // ====================  ALIASES       =======================================
        using result_t = Atoms;
        using Atoms_t = PointAtoms;
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
