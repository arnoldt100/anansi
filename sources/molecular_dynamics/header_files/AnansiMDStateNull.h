#ifndef  AnansiMDStateNull
#define  AnansiMDStateNull

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiMDStateNull.h"

namespace ANANSI
{

    class AnansiMDStateNull final : public AnansiMDState
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            AnansiMDStateNull ();  /* constructor      */

            AnansiMDStateNull (AnansiMDStateNull const & other);   /* copy constructor */

            AnansiMDStateNull (AnansiMDStateNull && other);   /* copy-move constructor */

            ~AnansiMDStateNull ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMDStateNull& operator= ( const AnansiMDStateNull &other ); /* assignment operator */

            AnansiMDStateNull& operator= ( AnansiMDStateNull && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:

            /* ====================  MUTATORS      ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDStateNull  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef AnansiMDStateNull  ----- */
