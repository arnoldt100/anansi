#ifndef  AnansiMDStateIIC_INC
#define  AnansiMDStateIIC_INC

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

    class AnansiMDStateIIC final : public AnansiMDState 
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            AnansiMDStateIIC ();  /* constructor      */

            AnansiMDStateIIC (AnansiMDStateIIC const & other);   /* copy constructor */

            AnansiMDStateIIC (AnansiMDStateIIC && other);   /* copy-move constructor */

            ~AnansiMDStateIIC ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMDStateIIC& operator= ( const AnansiMDStateIIC &other ); /* assignment operator */

            AnansiMDStateIIC& operator= ( AnansiMDStateIIC && other ); /* assignment-move operator */

            // ====================  STATIC DATA MEMBERS  =======================================
            constexpr static int id = 3;

            // ====================  STATIC METHOD  =======================================
            static AnansiMDState* createAnansiMDState()
            {
                return new AnansiMDStateIIC;
            }

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            void _initializeInitialConditions (MolecularDynamics * const aMD) const final override;

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDStateIIC  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef AnansiMDStateIIC_INC  ----- */
