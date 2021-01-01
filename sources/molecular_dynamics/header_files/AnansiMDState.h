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
    class MolecularDynamics;

    class AnansiMDState
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            AnansiMDState ();   /* constructor      */

            AnansiMDState (const AnansiMDState & other);   /* copy constructor */

            AnansiMDState (AnansiMDState && other);   /* copy-move constructor */

            virtual ~AnansiMDState ()=0;  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            void initializeSimulationEnvironment(MolecularDynamics * const aMD, int const & argc, char const *const *const & argv ) const;

            void processCommandLine(MolecularDynamics * const aMD, int const & argc, char const *const *const & argv ) const;

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMDState& operator=( const AnansiMDState &other ); /* assignment operator */

            AnansiMDState& operator=( AnansiMDState && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */
            virtual void _initializeSimulationEnvironment(MolecularDynamics* const aMD, int const & argc, char const *const *const & argv) const;

            virtual void _processCommandLine(MolecularDynamics* const aMD,int const & argc, char const *const *const & argv) const;

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDState  ----- */


}; /* namespace ANANSI */


#endif   /* ----- #ifndef AnansiMDState_INC  ----- */
