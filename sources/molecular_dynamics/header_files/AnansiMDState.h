#ifndef  AnansiMDState_INC
#define  AnansiMDState_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{
    class AnansiMDState
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            AnansiMDState ();   /* constructor      */

            AnansiMDState (const AnansiMDState & other);   /* copy constructor */

            AnansiMDState (AnansiMDState && other);   /* copy-move constructor */

            virtual ~AnansiMDState ()=0;  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */
            void initializeSimulationEnvironment(int const argc, char const *const *const & argv );

            /* ====================  OPERATORS     ======================================= */

            AnansiMDState& operator=( const AnansiMDState &other ); /* assignment operator */

            AnansiMDState& operator=( AnansiMDState && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */
            virtual void _initializeSimulationEnvironment(int const argc, char const *const *const & argv);

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDState  ----- */


}; /* namespace ANANSI */


#endif   /* ----- #ifndef AnansiMDState_INC  ----- */
