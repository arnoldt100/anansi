#ifndef  AnansiMDStateISE_INC
#define  AnansiMDStateISE_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiMDState.h"

namespace ANANSI
{

    class AnansiMDStateISE final : public AnansiMDState 
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            AnansiMDStateISE ();  /* constructor      */

            AnansiMDStateISE (AnansiMDStateISE const & other);   /* copy constructor */

            AnansiMDStateISE (AnansiMDStateISE && other);   /* copy-move constructor */

            virtual ~AnansiMDStateISE ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMDStateISE& operator= ( const AnansiMDStateISE &other ); /* assignment operator */

            AnansiMDStateISE& operator= ( AnansiMDStateISE && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:

            /* ====================  MUTATORS      ======================================= */
            void _initializeSimulationEnvironment() final override
            {
                std::cout << "This state initialized the simulation Environment.";
                return;
            }

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDStateISE  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef AnansiMDStateISE_INC  ----- */
