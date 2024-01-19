#ifndef ANANSI_MasterControlInputFileParameters_INC
#define ANANSI_MasterControlInputFileParameters_INC
//! \file MasterControlInputFileParameters.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationDecompositionParameters.h"

namespace ANANSI
{

//! \brief Utility helper class for returning parameters of Master Control Input File.
class MasterControlInputFileParameters
{
    public:
        // ====================  LIFECYCLE     =======================================

        MasterControlInputFileParameters ();   // constructor

        MasterControlInputFileParameters (const MasterControlInputFileParameters & other);   // copy constructor

        MasterControlInputFileParameters (MasterControlInputFileParameters && other);   // copy-move constructor

        ~MasterControlInputFileParameters ();  // destructor

        // ====================  ACCESSORS     =======================================
        MasterControlInputFileParameters * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MasterControlInputFileParameters& operator= ( const MasterControlInputFileParameters &other ); // assignment operator

        MasterControlInputFileParameters& operator= ( MasterControlInputFileParameters && other ); // assignment-move operator

        // ====================  STATIC        =======================================
        SimulationControlParameters static GetWorkLoad();

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MasterControlInputFileParameters  -----


}; // namespace ANANSI

#endif // ANANSI_MasterControlInputFileParameters_INC
