#ifndef ANANSI_AtomsDecomposer_INC
#define ANANSI_AtomsDecomposer_INC
//! \file AtomsDecomposer.h
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiTask.h"

namespace ANANSI
{

class AtomsDecomposer : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        AtomsDecomposer ();   // constructor

        AtomsDecomposer (const AtomsDecomposer & other);   // copy constructor

        AtomsDecomposer (AtomsDecomposer && other);   // copy-move constructor

        virtual ~AtomsDecomposer ();  // destructor

        // ====================  ACCESSORS     =======================================

        AtomsDecomposer * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        AtomsDecomposer& operator= ( const AtomsDecomposer &other ); // assignment operator

        AtomsDecomposer& operator= ( AtomsDecomposer && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // ----- End of class AtomsDecomposer  -----
}; // ----- End of namespace ANANSI -----
#endif // ANANSI_AtomsDecomposer_INC
