#ifndef  AnansiMDStatePS_INC
#define  AnansiMDStatePS_INC

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

    class AnansiMDStatePS final : public AnansiMDState 
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            AnansiMDStatePS ();  /* constructor      */

            AnansiMDStatePS (AnansiMDStatePS const & other);   /* copy constructor */

            AnansiMDStatePS (AnansiMDStatePS && other);   /* copy-move constructor */

            ~AnansiMDStatePS ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMDStatePS& operator= ( const AnansiMDStatePS &other ); /* assignment operator */

            AnansiMDStatePS& operator= ( AnansiMDStatePS && other ); /* assignment-move operator */

            // ====================  STATIC DATA MEMBERS  =======================================
            constexpr static int id = 4;

            // ====================  STATIC METHOD  =======================================
            static AnansiMDState* createAnansiMDState()
            {
                return new AnansiMDStatePS;
            }
        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            void _performSimulation(Simulation * const aMD) const final override;

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDStatePS  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef AnansiMDStatePS_INC  ----- */
