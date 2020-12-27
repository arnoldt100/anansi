#ifndef  AnansiMDStatePCL_INC
#define  AnansiMDStatePCL_INC

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

    class AnansiMDStatePCL final : public AnansiMDState 
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            AnansiMDStatePCL ();  /* constructor      */

            AnansiMDStatePCL (AnansiMDStatePCL const & other);   /* copy constructor */

            AnansiMDStatePCL (AnansiMDStatePCL && other);   /* copy-move constructor */

            virtual ~AnansiMDStatePCL ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMDStatePCL& operator= ( const AnansiMDStatePCL &other ); /* assignment operator */

            AnansiMDStatePCL& operator= ( AnansiMDStatePCL && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDStatePCL  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef AnansiMDStatePCL_INC  ----- */