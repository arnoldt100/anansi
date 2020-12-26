#ifndef  AnansiMDStatePS_INC
#define  AnansiMDStatePS_INC

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

    class AnansiMDStatePS final : public AnansiMDState 
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            AnansiMDStatePS ();  /* constructor      */

            AnansiMDStatePS (AnansiMDStatePS const & other);   /* copy constructor */

            AnansiMDStatePS (AnansiMDStatePS && other);   /* copy-move constructor */

            virtual ~AnansiMDStatePS ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMDStatePS& operator= ( const AnansiMDStatePS &other ); /* assignment operator */

            AnansiMDStatePS& operator= ( AnansiMDStatePS && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDStatePS  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef AnansiMDStatePS_INC  ----- */
