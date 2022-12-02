#ifndef  anansi_molecular_dynamics_INC
#define  anansi_molecular_dynamics_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

// This include is for deriving from the Simulation class.
#include "Simulation.h"

// This include is for making the AnansiMolecularDynamics a visitable class.
#include "DefineVisitableMacro.h"
#include "BaseVisitable.hpp"
#include "MPIEnvironment.h"
#include "InitMPIEnvTaskTraits.h"
#include "InitWorldCommunicatorTaskReceiver.h"
#include "InitWorldCommunicatorTaskTraits.h"
#include "CoreLoggingTasksTraits.h"
#include "WriteTextToConsoleTaskReceiver.h"
#include "CommandLineArguments.h"
#include "SimulationParameters.h"
#include "Communicator.h"
#include "RegistryAnansiMDStatus.h"
#include "SimulationState.h"
#include "MDAnansiTaskFactory.hpp"
#include "AnansiTask.h"

// Includes for invoking the communication environment.
#include "GenericTaskInvoker.hpp"

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
        
        // This macro defines the Accept member function.
        DEFINE_VISITABLE()

        void enableCommunicationEnvironment();
        void disableCommunicationEnvironment();

        void enableWorldCommunicator();
        void disableWorldCommunicator();

        void enableCoreLoggingTasks();
        void disableCoreLoggingTasks();

        void saveCommandLineOptionParameters();

        void readSimulationControlFile();

        void readInitialConfiguration();


        /* ====================  OPERATORS     ======================================= */

        AnansiMolecularDynamics&
        operator=(AnansiMolecularDynamics const & other) = delete; // Avoid implicit copy assignment of
                                                                   // AnansiMolecularDynamics class.

        AnansiMolecularDynamics&
        operator=(AnansiMolecularDynamics && other) = delete;

        /* ====================  STATIC        ======================================= */

        // ====================  USING ALIASES =======================================

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

        // This group of functions initializes the simulation environment.
        void
        initializeSimulationEnvironment_() final override;

        // This group of functions processes the command line and sets the
        // simulation parameters.
        void processCommandLine_() final override; 

        // This group of functions initializes the initial conditions of the 
        // simulation.
        void initializeInitialConditions_ () final override;

        // This group of functions performs the MD simulation.
        void performSimulation_() final override;

        // This group of functions terminates the simulation environment.
        void terminateSimulationEnvironment_() final override;

        // To be depracated.
        void setStatus_(const COMMUNICATOR::RegistryAnansiMDStatus aStatus) final override;

        // To be depracated.
        void setGlobalISEStatus_() final override;

        template<typename Label_t,
                 typename abstract_products_typelist,
                 typename concrete_products_typelist>
        void enableConsoleLoggingTask_( std::shared_ptr<ANANSI::GenericTaskInvoker<abstract_products_typelist,
                                                                                   concrete_products_typelist>
                                                       > & core_logging_invoker,
                                        std::unique_ptr<COMMUNICATOR::Communicator> & a_communicator );

        /* ====================  DATA MEMBERS  ======================================= */
        COMMANDLINE::CommandLineArguments commandLineArguments_;
        ANANSI::SimulationParameters simulationParameters_;
        std::shared_ptr<COMMUNICATOR::Communicator> MpiWorldCommunicator_;


        std::shared_ptr<ANANSI::GenericTaskInvoker<InitMPIEnvTaskTraits::abstract_products,
                                                   InitMPIEnvTaskTraits::concrete_products>
                       > mdCommEnvInvk_;

        std::shared_ptr<ANANSI::GenericTaskInvoker<InitWorldCommunicatorTaskTraits::abstract_products,
                                                   InitWorldCommunicatorTaskTraits::concrete_products>

                       > mdWorldCommunicatorInvk_;

        std::shared_ptr<ANANSI::GenericTaskInvoker<CoreLoggingTasksTraits::abstract_products,
                                                   CoreLoggingTasksTraits::concrete_products>
                       > mdCoreLoggingInvk_;

        // These are the state objects for the MD simulation.
        std::shared_ptr<ANANSI::SimulationState> mdState_;
        std::shared_ptr<ANANSI::SimulationState> mdNullSimulationState_;
        std::shared_ptr<ANANSI::SimulationState> mdInitSimEnv_;
        std::shared_ptr<ANANSI::SimulationState> mdProcessCmdLine_;
        std::shared_ptr<ANANSI::SimulationState> mdInitInitialConditions_;
        std::shared_ptr<ANANSI::SimulationState> mdPerformSimulation_;
        std::shared_ptr<ANANSI::SimulationState> mdTerminateSimulation_;


        // These are the factories for various task objects.
        std::shared_ptr<MDAnansiTaskFactory<InitMPIEnvTaskTraits::abstract_products,
                                            InitMPIEnvTaskTraits::concrete_products>
                       >mdAnansiMPIEnvTaskFactory_;

        std::shared_ptr<MDAnansiTaskFactory<InitWorldCommunicatorTaskTraits::abstract_products,
                                            InitWorldCommunicatorTaskTraits::concrete_products>
                       > mdAnansiInitWorldCommunicatorTaskFactory_;

        std::shared_ptr<MDAnansiTaskFactory<CoreLoggingTasksTraits::abstract_products,
                                            CoreLoggingTasksTraits::concrete_products>
                       > mdAnansiCoreLoggingTaskFactory_;

        // :TODO:09/27/2022 02:38:21 PM:: To be deprecated.
        COMMUNICATOR::RegistryAnansiMDStatus mdStatus_;
        
        // :TODO:09/27/2022 02:39:21 PM:: To be deprecated.
        COMMUNICATOR::RegistryAnansiMDStatus mdGlobalStatus_;

       /* ====================  STATIC        ======================================= */

}; /* -----  end of class AnansiMolecularDynamics  ----- */

}; /* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef anansi_molecular_dynamics_INC  ----- */
