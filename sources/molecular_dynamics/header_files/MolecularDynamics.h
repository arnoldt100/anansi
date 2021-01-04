/*
 * =====================================================================================
 *        Class:  MolecularDynamics
 *  Description:  
 * =====================================================================================
 */

// System includes
#include <iostream>
#include <memory>

// Local incudes
#include "AnansiMDState.h"


#ifndef  MolecularDynamics_INC
#define  MolecularDynamics_INC

namespace ANANSI
{

class MolecularDynamics
{

    public:
        /* ====================  LIFECYCLE     ======================================= */
        MolecularDynamics();

        virtual ~MolecularDynamics()=0;

        MolecularDynamics(MolecularDynamics const & other) = delete;

        MolecularDynamics(MolecularDynamics && other) = delete;

        /* ====================  ACCESSORS     ======================================= */

        void stud_function(std::string const & message) const;

        /* ====================  MUTATORS      ======================================= */

        void disableCommunication();

        // This group of functions initializes the simulation environment.
        void initializeSimulationEnvironment( int const & argc, char const *const *const & argv );

        void saveCommandLineArguments (int const & argc, char const *const *const & argv);

        void initializeMpiEnvironment(int const & argc, char const *const *const & argv);

        void enableCommunication();

        // This group of functions processes the comamand line and sets the
        // simulation parameters.
        void processCommandLine(); 

        void saveSimulationParameters();

        // This group of functions initializes the initial conditions of the 
        // simulation.
        void initializeInitialConditions();

        // This group of functions performs the MD simulation.
        void performSimulation();

        // This group of functions terminates the simulation environment.
        void terminateSimulationEnvironment();

        void setMDState(std::unique_ptr<AnansiMDState> && a_AnansiMDState);

        /* ====================  OPERATORS     ======================================= */

        MolecularDynamics&                                                 
        operator=(MolecularDynamics const & other) = delete;

        MolecularDynamics&                                                 
        operator=(MolecularDynamics && other) = delete; 

    protected:
        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

    private:
        /* ====================  MUTATORS      ======================================= */


        virtual void _disableCommunication()=0;

        // This group of functions initializes the simulation environment.
        virtual void _initializeSimulationEnvironment( int const & argc, char const *const *const & argv )=0;

        virtual void _saveCommandLineArguments( int const & argc, char const *const *const & argv)=0;

        virtual void _initializeMpiEnvironment( int const & argc, char const *const *const & argv )=0;

        virtual void _enableCommunication()=0;

        // This group of functions processes the command line and sets the
        // simulation parameters.
        virtual void _processCommandLine()=0; 

        virtual void _saveSimulationParameters()=0;

        // This group of functions initializes the initial conditions of the 
        // simulation.
        virtual void _initializeInitialConditions()=0;

        // This group of functions performs the MD simulation.
        virtual void _performSimulation()=0;

        // This group of functions terminates the simulation environment.
        virtual void _terminateSimulationEnvironment()=0;

        virtual void _setMDState(std::unique_ptr<AnansiMDState> && a_AnansiMDState)=0;

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class MolecularDynamics  ----- */

}; /* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef MolecularDynamics_INC  ----- */

