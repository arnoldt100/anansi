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

    // Forward declaration
    class MolecularDynamics;

    class AnansiMDState
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  AnansiMDState
            //      Method:  AnansiMDState :: AnansiMDState
            // Description:  The default constructor.
            //
            //--------------------------------------------------------------------------------------
            AnansiMDState();

            //--------------------------------------------------------------------------------------
            //       Class:  AnansiMDState
            //      Method:  AnansiMDState :: AnansiMDState
            // Description:  The copy constructor.
            // 
            //  Parameters:
            //      other : The object to be copied.
            //
            //-------------------------------------------------------------------------------------
            AnansiMDState (const AnansiMDState & other);

            //--------------------------------------------------------------------------------------
            //       Class:  AnansiMDState
            //      Method:  AnansiMDState :: AnansiMDState
            // Description:  The copy move constructor.
            // 
            //  Parameters:
            //      other : The object to be copied.
            //
            //--------------------------------------------------------------------------------------
            AnansiMDState (AnansiMDState && other);

            //--------------------------------------------------------------------------------------
            //       Class:  AnansiMDState
            //      Method:  AnansiMDState :: ~AnansiMDState
            // Description:  The destructor.
            // 
            //--------------------------------------------------------------------------------------
            virtual ~AnansiMDState ()=0;

            // ====================  ACCESSORS     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  AnansiMDState
            //      Method:  AnansiMDState :: initializeSimulationEnvironment
            // Description:  This function makes a request to the aMD object to initialize the 
            //               simulation environment.
            //
            //  Parameters:
            //        aMD : The object the request is made to.
            //
            //--------------------------------------------------------------------------------------
            void initializeSimulationEnvironment(MolecularDynamics * const aMD ) const;

            //--------------------------------------------------------------------------------------
            //       Class:  AnansiMDState
            //      Method:  AnansiMDState :: processCommandLine
            // Description:  This function makes a request to the aMD object to process
            //               the command line arguments.
            //
            // Parameters:
            //       aMD : The object the request is made to.
            //
            //--------------------------------------------------------------------------------------
            void processCommandLine(MolecularDynamics * const aMD) const;

            //--------------------------------------------------------------------------------------
            //       Class:  AnansiMDState
            //      Method:  AnansiMDState :: initializeInitialConditions
            // Description:  This function makes a request to the aMD object to initialize
            //               the initial conditions.
            //
            // Parameters:
            //       aMD : The object the request is made to.
            //
            //--------------------------------------------------------------------------------------
            void initializeInitialConditions(MolecularDynamics * const aMD) const;

            //--------------------------------------------------------------------------------------
            //       Class:  AnansiMDState
            //      Method:  AnansiMDState :: performSimulation
            // Description:  
            // 
            //  Parameters: 
            //        aMD : The object the request is made to.
            //--------------------------------------------------------------------------------------
            void performSimulation(MolecularDynamics * const aMD) const;

            //--------------------------------------------------------------------------------------
            //       Class:  AnansiMDState
            //      Method:  AnansiMDState :: terminateSimulationEnvironment
            // Description:  This function makes a request to the aMD object to
            //               terminate the simulation environment.
            // 
            //  Parameters: 
            //        aMD : The object the request is made to.
            //
            //--------------------------------------------------------------------------------------
            void terminateSimulationEnvironment(MolecularDynamics * const aMD) const ;

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            //--------------------------------------------------------------------------------------
            //       Class:  AnansiMDState
            //      Method:  AnansiMDState :: AnansiMDState
            // Description:  The copy assignment operator.
            // 
            //  Parameters: 
            //      other : The object to be copied.
            //--------------------------------------------------------------------------------------
            AnansiMDState& operator=( const AnansiMDState &other ); /* assignment operator */

            //--------------------------------------------------------------------------------------
            //       Class:  AnansiMDState
            //      Method:  AnansiMDState :: AnansiMDState
            // Description:  The move assignment operator.
            // 
            //  Parameters: 
            //      other : The object to be move assigned.
            //--------------------------------------------------------------------------------------
            AnansiMDState& operator=( AnansiMDState && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  ACCESSORS     ======================================= */
            virtual void _initializeSimulationEnvironment(MolecularDynamics* const aMD) const;

            virtual void _processCommandLine(MolecularDynamics* const aMD) const;

            virtual void _initializeInitialConditions(MolecularDynamics * const aMD) const;

            virtual void _performSimulation(MolecularDynamics * const aMD) const;

            virtual void _terminateSimulationEnvironment(MolecularDynamics * const aMD) const;

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMDState  ----- */


}; /* namespace ANANSI */


#endif   /* ----- #ifndef AnansiMDState_INC  ----- */
