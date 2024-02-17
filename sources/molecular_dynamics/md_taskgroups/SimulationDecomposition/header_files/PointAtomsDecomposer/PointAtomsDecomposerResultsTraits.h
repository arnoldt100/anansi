#ifndef ANANSI_PointAtomsDecomposerResultsTraits_INC
#define ANANSI_PointAtomsDecomposerResultsTraits_INC
//! \file PointAtomsDecomposerResultsTraits.h
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

class PointAtomsDecomposerResultsTraits
{
    public:
        // ====================  ALIASES       =======================================
        //! \todo  Fill in the result type.
        using result_t = Atoms;
        using Atoms_t = PointAtoms;
        using copy_result_t = result_t;
        using share_result_t = result_t;
        using transfer_result_t = result_t;

        // ====================  LIFECYCLE     =======================================

        PointAtomsDecomposerResultsTraits ();   // constructor

        PointAtomsDecomposerResultsTraits (const PointAtomsDecomposerResultsTraits & other);   // copy constructor

        PointAtomsDecomposerResultsTraits (PointAtomsDecomposerResultsTraits && other);   // copy-move constructor

        ~PointAtomsDecomposerResultsTraits ();  // destructor

        // ====================  ACCESSORS     =======================================
        PointAtomsDecomposerResultsTraits * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        PointAtomsDecomposerResultsTraits& operator= ( const PointAtomsDecomposerResultsTraits &other ); // assignment operator

        PointAtomsDecomposerResultsTraits& operator= ( PointAtomsDecomposerResultsTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // ----  End of class PointAtomsDecomposerResultsTraits  -----
}; // ----- End of namespace ANANSI -----

#endif // ANANSI_PointAtomsDecomposerResultsTraits_INC
