#ifndef  AnansiMDStatePCL_INC
#define  AnansiMDStatePCL_INC

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

    class AnansiMDStatePCL final : public AnansiMDState 
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            AnansiMDStatePCL ();  /* constructor      */

            AnansiMDStatePCL (AnansiMDStatePCL const & other);   /* copy constructor */

            AnansiMDStatePCL (AnansiMDStatePCL && other);   /* copy-move constructor */

            ~AnansiMDStatePCL ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMDStatePCL& operator= ( const AnansiMDStatePCL &other ); /* assignment operator */

            AnansiMDStatePCL& operator= ( AnansiMDStatePCL && other ); /* assignment-move operator */
            
            // ====================  STATIC DATA MEMBERS  =======================================
            constexpr static int id = 2;

            // ====================  STATIC METHOD  =======================================
            static AnansiMDState* createAnansiMDState()
            {
                return new AnansiMDStatePCL;
            }

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /*=====================  ACCESSORS     ======================================= */

            void _processCommandLine(MolecularDynamics * const aMD) const final override;

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDStatePCL  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef AnansiMDStatePCL_INC  ----- */
