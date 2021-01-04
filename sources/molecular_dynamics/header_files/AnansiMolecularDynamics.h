#ifndef  anansi_molecular_dynamics_INC
#define  anansi_molecular_dynamics_INC

// System includes
#include <boost/program_options.hpp>
#include <memory>

// Package includes
#include "MPIEnvironment.h"
#include "MolecularDynamics.h"
#include "CommandLineArguments.h"
#include "SimulationParameters.h"
#include "Communicator.h"

namespace ANANSI {

class AnansiMolecularDynamics final : public MolecularDynamics
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        AnansiMolecularDynamics ();  /* constructor */

        ~AnansiMolecularDynamics (); /* destructor */

        AnansiMolecularDynamics(AnansiMolecularDynamics const & other) = delete; // Avoid implicit of copying the
                                                                                 // AnansiMolecularDynamics class.

        AnansiMolecularDynamics(AnansiMolecularDynamics && other) = delete;

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        AnansiMolecularDynamics&                                                 
        operator=(AnansiMolecularDynamics const & other) = delete; // Avoid implicit copy assignment of
                                                                   // AnansiMolecularDynamics class.

        AnansiMolecularDynamics&                                                 
        operator=(AnansiMolecularDynamics && other) = delete;

        /* ====================  STATIC        ======================================= */

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  MUTATORS      ======================================= */

        void 
        _disableCommunication() final override;


        // This group of functions initializes the simulation environment.
        void 
        _initializeSimulationEnvironment(int const & argc, char const *const *const & argv ) final override;

        void 
        _saveCommandLineArguments( int const & argc, char const *const *const & argv) final override;

        void 
        _initializeMpiEnvironment(int const & argc, char const *const *const & argv) final override;

        void 
        _enableCommunication() final override;

        // This group of functions processes the comamand line and sets the
        // simulation parameters.
        void _processCommandLine() final override; 

        void _saveSimulationParameters() final override;

        // This group of functions initializes the initial conditions of the 
        // simulation.
        void _initializeInitialConditions () final override;

        // This group of functions performs the MD simulation.
        void
        _performSimulation() final override;

        // This group of functions terminates the simulation environment.
        void _terminateSimulationEnvironment() final override;
        
        void _setMDState(std::unique_ptr<AnansiMDState> && a_AnansiMDState) final override;

        /* ====================  DATA MEMBERS  ======================================= */
        COMMANDLINE::CommandLineArguments _commandLineArguments;
        ANANSI::SimulationParameters _simulationParameters;
        std::unique_ptr<COMMUNICATOR::Communicator> _MpiWorldCommunicator;
        std::unique_ptr<COMMUNICATOR::MPIEnvironment> _MpiEnvironment;
        std::unique_ptr<ANANSI::AnansiMDState> _mdState;

        /* ====================  STATIC        ======================================= */

}; /* -----  end of class AnansiMolecularDynamics  ----- */

}; /* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef anansi_molecular_dynamics_INC  ----- */
