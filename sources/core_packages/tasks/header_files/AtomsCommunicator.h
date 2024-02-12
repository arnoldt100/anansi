#ifndef ANANSI_AtomsCommunicator_INC
#define ANANSI_AtomsCommunicator_INC
//! \file AtomsCommunicator.h
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

class AtomsCommunicator : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        AtomsCommunicator ();   // constructor

        AtomsCommunicator (const AtomsCommunicator & other);   // copy constructor

        AtomsCommunicator (AtomsCommunicator && other);   // copy-move constructor

        virtual ~AtomsCommunicator ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        AtomsCommunicator& operator= ( const AtomsCommunicator &other ); // assignment operator

        AtomsCommunicator& operator= ( AtomsCommunicator && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // ----- End of class AtomsCommunicator  -----
}; // ----- End of namespace ANANSI -----
#endif // ANANSI_AtomsCommunicator_INC
