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
#include "RegistryAnansiMDStatus.h"
#include "Factory.hpp"
#include "MDSimulationStateFactory.h"

namespace ANANSI {

class AnansiMolecularDynamics final : public MolecularDynamics
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        AnansiMolecularDynamics ();  /* constructor */

        AnansiMolecularDynamics (int const & argc, char const *const *const & argv);  /* constructor */

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
        /* ====================  ACCESSORS     ======================================= */

        COMMUNICATOR::RegistryAnansiMDStatus _status() const final override;

        bool _isHelpOnCommandLine() const final override;

        bool _isISEStatusOkay() const final override;

        bool _isISEGlobalStatusOkay() const final override;

        bool _isIICStatusOkay() const final override;

        /* ====================  MUTATORS      ======================================= */

        void 
        _disableCommunication() final override;

        // This group of functions initializes the simulation environment.
        void 
        _initializeSimulationEnvironment() final override;

        void 
        _initializeMpiEnvironment() final override;

        void 
        _enableCommunication() final override;

        // This group of functions processes the command line and sets the
        // simulation parameters.
        void _processCommandLine() final override; 

        void _saveCommandLineOptionParameters() final override;

        // This group of functions initializes the initial conditions of the 
        // simulation.
        void _initializeInitialConditions () final override;

        void _inputSimulationControlFile () final override;

        void _readInitialConfiguration () final override;

        // This group of functions performs the MD simulation.
        void
        _performSimulation() final override;

        // This group of functions terminates the simulation environment.
        void _terminateSimulationEnvironment() final override;
        
        // This group of functions changes the state of the MD object.
        void _setMDState(std::unique_ptr<AnansiMDState> && a_AnansiMDState) final override;
        void _changeMDStateToPCL() final override;
        void _changeMDStateToIIC() final override;
        void _changeMDStateToPS() final override;
        void _changeMDStateToTSE() final override;
        void _changeMDState(int const id) final override;

        void _setStatus(const COMMUNICATOR::RegistryAnansiMDStatus aStatus) final override;
        void _setGlobalISEStatus() final override;

        /* ====================  DATA MEMBERS  ======================================= */
        COMMANDLINE::CommandLineArguments _commandLineArguments;
        ANANSI::SimulationParameters _simulationParameters;
        std::unique_ptr<COMMUNICATOR::Communicator> _MpiWorldCommunicator;
        std::unique_ptr<COMMUNICATOR::MPIEnvironment> _MpiEnvironment;
        std::unique_ptr<MPL::Factory<ANANSI::AnansiMDState,int>> _mdStateFactory;
        std::unique_ptr<ANANSI::MDSimulationStateFactory> mdStateFactory_;
        std::unique_ptr<ANANSI::AnansiMDState> _mdState;
        COMMUNICATOR::RegistryAnansiMDStatus _mdStatus;
        COMMUNICATOR::RegistryAnansiMDStatus _mdGlobalStatus;

        /* ====================  STATIC        ======================================= */

}; /* -----  end of class AnansiMolecularDynamics  ----- */

}; /* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef anansi_molecular_dynamics_INC  ----- */
