#ifndef  anansi_molecular_dynamics_INC
#define  anansi_molecular_dynamics_INC

// System includes
#include <boost/program_options.hpp>
#include <memory>

// Package includes
#include "MPIEnvironment.h"
#include "Simulation.h"
#include "CommandLineArguments.h"
#include "SimulationParameters.h"
#include "Communicator.h"
#include "RegistryAnansiMDStatus.h"
#include "Factory.hpp"
#include "MDSimulationStateFactory.h"

namespace ANANSI {

class AnansiMolecularDynamics final : public Simulation
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

        COMMUNICATOR::RegistryAnansiMDStatus status_() const final override;

        bool isHelpOnCommandLine_() const final override;

        bool isISEStatusOkay_() const final override;

        bool isISEGlobalStatusOkay_() const final override;

        bool isIICStatusOkay_() const final override;

        /* ====================  MUTATORS      ======================================= */

        void 
        disableCommunication_() final override;

        // This group of functions initializes the simulation environment.
        void 
        initializeSimulationEnvironment_() final override;

        void 
        initializeMpiEnvironment_() final override;

        void 
        enableCommunication_() final override;

        // This group of functions processes the command line and sets the
        // simulation parameters.
        void processCommandLine_() final override; 

        void saveCommandLineOptionParameters_() final override;

        // This group of functions initializes the initial conditions of the 
        // simulation.
        void initializeInitialConditions_ () final override;

        void inputSimulationControlFile_ () final override;

        void readInitialConfiguration_ () final override;

        // This group of functions performs the MD simulation.
        void
        performSimulation_() final override;

        // This group of functions terminates the simulation environment.
        void terminateSimulationEnvironment_() final override;
        
        void setStatus_(const COMMUNICATOR::RegistryAnansiMDStatus aStatus) final override;
        void setGlobalISEStatus_() final override;

        /* ====================  DATA MEMBERS  ======================================= */
        COMMANDLINE::CommandLineArguments commandLineArguments_;
        ANANSI::SimulationParameters simulationParameters_;
        std::unique_ptr<COMMUNICATOR::Communicator> MpiWorldCommunicator_;
        std::unique_ptr<COMMUNICATOR::MPIEnvironment> MpiEnvironment_;
        std::unique_ptr<ANANSI::MDSimulationStateFactory> mdStateFactory_;

        std::unique_ptr<ANANSI::SimulationState> mdState_;

        COMMUNICATOR::RegistryAnansiMDStatus mdStatus_;
        COMMUNICATOR::RegistryAnansiMDStatus mdGlobalStatus_;

        /* ====================  STATIC        ======================================= */

}; /* -----  end of class AnansiMolecularDynamics  ----- */

}; /* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef anansi_molecular_dynamics_INC  ----- */
