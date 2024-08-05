#ifndef ANANSI_ReadAtoms_INC
#define ANANSI_ReadAtoms_INC
//! \file ReadAtoms.h
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

class ReadAtoms : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        ReadAtoms ();   // constructor

        ReadAtoms (const ReadAtoms & other);   // copy constructor

        ReadAtoms (ReadAtoms && other);   // copy-move constructor

        virtual ~ReadAtoms ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ReadAtoms& operator= ( const ReadAtoms &other ); // assignment operator

        ReadAtoms& operator= ( ReadAtoms && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // ----- End of class ReadAtoms  -----
}; // ----- End of namespace ANANSI -----
#endif // ANANSI_ReadAtoms_INC
