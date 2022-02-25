#ifndef  AnansiMDStateNull_INC
#define  AnansiMDStateNull_INC

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

            // ====================  STATIC DATA MEMBERS  =======================================
            constexpr static int id = 0;

            // ====================  STATIC METHOD  =======================================
            static AnansiMDState* createAnansiMDState()
            {
                return new AnansiMDStateNull;
            }

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:

            /* ====================  MUTATORS      ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDStateNull  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef AnansiMDStateNull_INC  ----- */
