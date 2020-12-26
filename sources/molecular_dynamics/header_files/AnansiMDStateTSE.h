#ifndef  AnansiMDStateTSE_INC
#define  AnansiMDStateTSE_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiMDState.h"

namespace ANANSI
{

    class AnansiMDStateTSE final : public AnansiMDState 
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            AnansiMDStateTSE ();  /* constructor      */

            AnansiMDStateTSE (AnansiMDStateTSE const & other);   /* copy constructor */

            AnansiMDStateTSE (AnansiMDStateTSE && other);   /* copy-move constructor */

            virtual ~AnansiMDStateTSE ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMDStateTSE& operator= ( const AnansiMDStateTSE &other ); /* assignment operator */

            AnansiMDStateTSE& operator= ( AnansiMDStateTSE && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDStateTSE  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef AnansiMDStateTSE_INC  ----- */
