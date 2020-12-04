/*
 * =====================================================================================
 *        Class:  AnansiMolecularDynamics
 *  Description:  
 * =====================================================================================
 */

#ifndef  anansi_molecular_dynamics_INC
#define  anansi_molecular_dynamics_INC

// System includes
#include <boost/program_options.hpp>

// Local includes
#include "Pointer.hpp"
#include "MolecularDynamics.h"
#include "CommandLineArguments.h"
#include "SimulationParametersFactory.h"
#include "MPICommunicatorFactory.h"

namespace ANANSI {

class AnansiMolecularDynamics final : public MolecularDynamics
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        AnansiMolecularDynamics ();  /* constructor */

        ~AnansiMolecularDynamics (); /* destructor */

        AnansiMolecularDynamics(AnansiMolecularDynamics const & other) = delete; // Avoid implicit of copying the
                                                                                 // AnansiMolecularDynamics class.

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        AnansiMolecularDynamics&                                                 
        operator=(AnansiMolecularDynamics const & other) = delete; // Avoid implicit copy assignment of
                                                                   // AnansiMolecularDynamics class.

        /* ====================  STATIC        ======================================= */

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        void _doSimulation() override;

        void _enableCommunication() override;

        void _disableCommunication() override;

        void _initializeSimulation(int const argc, char const *const *const & argv ) override;

        /* ====================  DATA MEMBERS  ======================================= */
        COMMANDLINE::CommandLineArguments _commandLineArguments;
        ANANSI::SimulationParameters _simulationParameters;
        std::unique_ptr<COMMUNICATOR::MPICommunicator> _MpiWorldCommunicator;

        /* ====================  STATIC        ======================================= */

}; /* -----  end of class AnansiMolecularDynamics  ----- */

}; /* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef anansi_molecular_dynamics_INC  ----- */
