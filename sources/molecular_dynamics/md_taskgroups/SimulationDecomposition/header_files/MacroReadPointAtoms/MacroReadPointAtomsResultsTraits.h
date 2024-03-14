#ifndef ANANSI_MacroReadPointAtomsResultsTraits_INC
#define ANANSI_MacroReadPointAtomsResultsTraits_INC
//! \file MacroReadPointAtomsResultsTraits.h
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

class MacroReadPointAtomsResultsTraits
{
    public:
        // ====================  ALIASES       =======================================
        //! \todo  Fill in the result type.
        using result_t = Atoms ;
        using Atoms_t = PointAtoms;
        using copy_result_t = result_t;
        using share_result_t = result_t;
        using transfer_result_t = result_t;

        // ====================  LIFECYCLE     =======================================

        MacroReadPointAtomsResultsTraits ();   // constructor

        MacroReadPointAtomsResultsTraits (const MacroReadPointAtomsResultsTraits & other);   // copy constructor

        MacroReadPointAtomsResultsTraits (MacroReadPointAtomsResultsTraits && other);   // copy-move constructor

        ~MacroReadPointAtomsResultsTraits ();  // destructor

        // ====================  ACCESSORS     =======================================
        MacroReadPointAtomsResultsTraits * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MacroReadPointAtomsResultsTraits& operator= ( const MacroReadPointAtomsResultsTraits &other ); // assignment operator

        MacroReadPointAtomsResultsTraits& operator= ( MacroReadPointAtomsResultsTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // ----  End of class MacroReadPointAtomsResultsTraits  -----
}; // ----- End of namespace ANANSI -----

#endif // ANANSI_MacroReadPointAtomsResultsTraits_INC
