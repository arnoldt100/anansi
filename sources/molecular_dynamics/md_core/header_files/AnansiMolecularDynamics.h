#ifndef  anansi_molecular_dynamics_INC
#define  anansi_molecular_dynamics_INC

//! \file AnansiMolecularDynamics.h

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
#include "WriteTextToConsoleTaskReceiver.h"
#include "InitWorldCommunicatorTaskReceiver.h"
#include "ReadControlFileTraits.h"
#include "InitWorldCommunicatorTaskTraits.h"
#include "WriteTextToConsoleTaskTraits.h"
#include "CommandLineArguments.h"
#include "SimulationParameters.h"
#include "Communicator.h"
#include "SimulationState.h"
#include "GenericTaskFactory.hpp"
#include "AnansiTask.h"

// Includes for invoking the communication environment.
#include "GenericTaskInvoker.hpp"

namespace ANANSI {

//! \brief AnansiMolecularDynamics is the encapsulates the Molecular Dynamics simulation.
//! and is derived from the parent abstract class Simulation.
//! 
//! Anansi implements the following
//! private methods to implement the Simulation interface:
//!  - AnansiMolecularDynamics::isHelpOnCommandLine_
//!  - AnansiMolecularDynamics::initializeSimulationEnvironment_
//!  - AnansiMolecularDynamics::processCommandLine_
//!  - AnansiMolecularDynamics::initializeInitialConditions_
//!  - AnansiMolecularDynamics::performSimulation_
//!  - AnansiMolecularDynamics::terminateSimulationEnvironment_
//! 
class AnansiMolecularDynamics final : public Simulation
{
    // These methods implement the parent classs Simulation private virtual methods.
    private:

        //! \brief Returns true if the option "-h" or "--help" is present on the command line, otherwise
        //!        returns false.
        bool isHelpOnCommandLine_() const final override;

        //! \brief Processes the command line arguments.
        //!
        //! After this call the AnansiMolecularDynamics object contains the
        // command line arguments.
        void processCommandLine_() final override; 

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

        void enableControlFileTasks();
        void disableControlFileTasks();

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


        /* ====================  MUTATORS      ======================================= */

        // This group of functions initializes the simulation environment.
        void
        initializeSimulationEnvironment_() final override;

        // This group of functions initializes the initial conditions of the 
        // simulation.
        void initializeInitialConditions_ () final override;

        // This group of functions performs the MD simulation.
        void performSimulation_() final override;

        // This group of functions terminates the simulation environment.
        void terminateSimulationEnvironment_() final override;

        /* ====================  DATA MEMBERS  ======================================= */
        COMMANDLINE::CommandLineArguments commandLineArguments_;
        ANANSI::SimulationParameters simulationParameters_;
        std::shared_ptr<COMMUNICATOR::Communicator> MpiWorldCommunicator_;

        template<typename abstract_products_typelist,
                 typename concrete_products_typelist>
        void enableConsoleLoggingTask_( std::shared_ptr<ANANSI::GenericTaskInvoker<abstract_products_typelist,
                                                                                   concrete_products_typelist>
                                                       > & core_logging_invoker,
                                        std::unique_ptr<COMMUNICATOR::Communicator> & a_communicator );

        std::shared_ptr<ANANSI::GenericTaskInvoker<InitMPIEnvTaskTraits::abstract_products,
                                                   InitMPIEnvTaskTraits::concrete_products>
                       > mdCommEnvInvk_;

        std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                   ReadControlFileTraits::concrete_products>
                       > mdControlFileInvk_;

        std::shared_ptr<ANANSI::GenericTaskInvoker<InitWorldCommunicatorTaskTraits::abstract_products,
                                                   InitWorldCommunicatorTaskTraits::concrete_products>

                       > mdWorldCommunicatorInvk_;

        std::shared_ptr<ANANSI::GenericTaskInvoker<WriteTextToConsoleTaskTraits::abstract_products,
                                                   WriteTextToConsoleTaskTraits::concrete_products>
                       > mdCoreLoggingInvk_;



        // These are the state objects for the MD simulation.
        std::shared_ptr<ANANSI::SimulationState> mdState_;
        std::shared_ptr<ANANSI::SimulationState> mdNullSimulationState_;
        std::shared_ptr<ANANSI::SimulationState> mdInitSimEnv_;
        std::shared_ptr<ANANSI::SimulationState> mdProcessCmdLine_;
        std::shared_ptr<ANANSI::SimulationState> mdInitInitialConditions_;
        std::shared_ptr<ANANSI::SimulationState> mdPerformSimulation_;
        std::shared_ptr<ANANSI::SimulationState> mdTerminateSimulation_;


        // To be removed.
        // These are the task factories for various invoker objects.
        std::shared_ptr<GenericTaskFactory<InitMPIEnvTaskTraits::abstract_products,
                                           InitMPIEnvTaskTraits::concrete_products>
                       >mdAnansiMPIEnvTaskFactory_;

        std::shared_ptr<GenericTaskFactory<InitWorldCommunicatorTaskTraits::abstract_products,
                                               InitWorldCommunicatorTaskTraits::concrete_products>
                       > mdAnansiInitWorldCommunicatorTaskFactory_;

        std::shared_ptr<GenericTaskFactory<WriteTextToConsoleTaskTraits::abstract_products,
                                               WriteTextToConsoleTaskTraits::concrete_products>
                       > mdAnansiCoreLoggingTaskFactory_;

        std::shared_ptr<GenericTaskFactory<ReadControlFileTraits::abstract_products,
                                           ReadControlFileTraits::concrete_products>
                       > mdAnansiControlFileTaskFactory_;


       /* ====================  STATIC        ======================================= */

}; /* -----  end of class AnansiMolecularDynamics  ----- */

}; /* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef anansi_molecular_dynamics_INC  ----- */
