#ifndef  AnansiMDStateTSE_INC
#define  AnansiMDStateTSE_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

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

            ~AnansiMDStateTSE ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMDStateTSE& operator=( const AnansiMDStateTSE &other ); /* assignment operator */

            AnansiMDStateTSE& operator=( AnansiMDStateTSE && other ); /* assignment-move operator */

            // ====================  STATIC DATA MEMBERS  =======================================
            constexpr static int id = 5;

            // ====================  STATIC METHOD  =======================================
            static AnansiMDState* createAnansiMDState()
            {
                return new AnansiMDStateTSE;
            }

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  ACCESSORS     ======================================= */
            void _terminateSimulationEnvironment(MolecularDynamics * const aMD) const final override ;

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDStateTSE  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef AnansiMDStateTSE_INC  ----- */
