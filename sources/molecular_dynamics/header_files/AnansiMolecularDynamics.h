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
        _doSimulation() final override;

        void 
        _enableCommunication() final override;

        void 
        _disableCommunication() final override;

        void 
        _initializeSimulation(int const argc, char const *const *const & argv ) final override;

        void 
        _initializeSimulationEnvironment(int const argc, char const *const *const & argv ) final override;

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
