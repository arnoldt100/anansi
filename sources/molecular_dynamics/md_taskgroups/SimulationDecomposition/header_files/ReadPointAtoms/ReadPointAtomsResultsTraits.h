#ifndef ANANSI_ReadPointAtomsResultsTraits_INC
#define ANANSI_ReadPointAtomsResultsTraits_INC
//! \file ReadPointAtomsResultsTraits.h
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

namespace ANANSI
{

class ReadPointAtomsResultsTraits
{
    public:
        // ====================  ALIASES       =======================================
        //! \brief 
        using result_t = Atoms;

        // ====================  LIFECYCLE     =======================================

        ReadPointAtomsResultsTraits ();   // constructor

        ReadPointAtomsResultsTraits (const ReadPointAtomsResultsTraits & other);   // copy constructor

        ReadPointAtomsResultsTraits (ReadPointAtomsResultsTraits && other);   // copy-move constructor

        ~ReadPointAtomsResultsTraits ();  // destructor

        // ====================  ACCESSORS     =======================================
        ReadPointAtomsResultsTraits * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ReadPointAtomsResultsTraits& operator= ( const ReadPointAtomsResultsTraits &other ); // assignment operator

        ReadPointAtomsResultsTraits& operator= ( ReadPointAtomsResultsTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // ----  End of class ReadPointAtomsResultsTraits  -----
}; // ----- End of namespace ANANSI -----

#endif // ANANSI_ReadPointAtomsResultsTraits_INC
