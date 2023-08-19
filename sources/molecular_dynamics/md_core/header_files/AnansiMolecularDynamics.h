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

namespace ANANSI
{

//! \brief AnansiMolecularDynamics is an abstraction for the Molecular Dynamics simulation and is derived from the
//!        class Simulation. 
//!
//! The Template Pattern with the Non-Virtual Interface Idiom is employed for
//! AnansiMolecularDynamics and Simulation. The public interface is defined in
//! the public method of Simulation, and the implementation is defined in the
//! private method of AnansiMolecularDynamics. The table below lists the private
//! implementation methods of AnansiMolecularDynamics and the corrsponding
//! public interface methods in Simulation.
//!
//! | Private Implementation in Derived Class AnansiMolecularDynamics | Public Interface in Simulation       |
//! | ------------------------------------------- | -------------------------------------------------------- |
//! |AnansiMolecularDynamics::isHelpOnCommandLine_             | Simulation::isHelpOnCommandLine             |
//! |AnansiMolecularDynamics::processCommandLine_              | Simulation::processCommandLine              |
//! |AnansiMolecularDynamics::initializeSimulationEnvironment_ | Simulation::initializeSimulationEnvironment |
//! |AnansiMolecularDynamics::initializeInitialConditions_     | Simulation::initializeInitialConditions     |
//! |AnansiMolecularDynamics::performSimulation_               | Simulation::performSimulation               |
//! |AnansiMolecularDynamics::terminateSimulationEnvironment_  | Simulation::terminateSimulationEnvironment  |
//!
//! The above private methods are not documented by Doxygen and one must
//! read the header file AnansiMolecularDynamics.h for their documentation.
//!
//! The class AnansiMolecularDynamics is also visitable via the macro DEFINE_VISITABLE.
//! The root hierarchy of AnansiMolecularDynamics is the class MPL::BaseVisitable<>. See
//! Chapter 10 Visitor,  of "Modern C++ Design: Generic Programming and Design Patters" by
//! Andrei Alexandrescu for details of this generic visitor pattern.
//!
//! Finally, AnansiMolecularDynamics' copy constructor, move-copy constructor,
//! assignment operator, and move-assignment operator are deleted.
class AnansiMolecularDynamics final : public Simulation
{
    // ===============================================================================
    // ====================  Simulation Interface Implementations   ==================
    // ===============================================================================
    private:

        // These methods implement the interface for the parent class Simulation
        // private virtual methods.

        // ====================  ACCESSORS     =======================================

        //! \brief Returns true if the option "-h" or "--help" is present on the command line, otherwise
        //!        returns false.
        bool
        isHelpOnCommandLine_() const final override;

        // ====================  MUTATORS      =======================================

        //! \brief Processes the command line arguments.
        //!
        //! After this call the AnansiMolecularDynamics object contains the
        //! command line arguments.
        void
        processCommandLine_() final override;

        //! \brief Initializes the simulation environment.
        //!
        //! After this call program the runtime environments are initialized. For example,
        //! the comunnication environment is initialized (MPI is typical), the
        //! accelerator runtime environment is initialized, etc.
        void
        initializeSimulationEnvironment_() final override;

        //! \brief After this call the initial conditions of the simulation is set.
        void
        initializeInitialConditions_ () final override;

        //! \brief After this call the simulation is performed.
        void
        performSimulation_() final override;

        //! \brief After this call the simulation is terminated.
        void
        terminateSimulationEnvironment_() final override;

    // ===============================================================================
    // ====================  MPL:BaseVisitable Implementations      ==================
    // ===============================================================================
    public:

        // This macro defines the Accept member function which in conjuction
        // with MPL::BaseVisitable as the root class in the hierarchy make
        // anansi_molecular_dynamics visitable.
        DEFINE_VISITABLE()

    // ===============================================================================
    // ====================  AnansiMolecularDynamics Standard Implementations ========
    // ===============================================================================
    public:
        // ====================  LIFECYCLE     =======================================

        //! \brief The default constructor
        //!
        //! This is defined for completeness. Do not use for instantiating an
        //! AnansiMolecularDynamics object.
        AnansiMolecularDynamics(); // constructor

        //! \brief The constructor to be used to instantiate an AnansiMolecularDynamics object.
        //!
        //! \param [in] argc The number of command line arguments.
        //! \param [in] argv A character array that contains the command line arguments.
        AnansiMolecularDynamics(int const &argc,
                                char const *const *const &argv);

        ~AnansiMolecularDynamics();

        AnansiMolecularDynamics(AnansiMolecularDynamics const &other) =
            delete; // Avoid implicit of copying the
        // AnansiMolecularDynamics class.

        AnansiMolecularDynamics(AnansiMolecularDynamics && other) = delete;

        // ====================  ACCESSORS =======================================

        // ====================  MUTATORS =======================================

        //! \brief Enables the communication runtime environment.
        //!
        //! The communication runtime environment is set up. The responsibility is
        //! initializing the communication invoker object AnansiMolecularDynamics::mdCommEnvInvk_.
        //! AnansiMolecularDynamics::mdCommEnvInvk_ then invokes the task to set up communication
        //! environment. The method is called once and only once. Repeated calls results in undefined 
        //! behavoir.
        void
        enableCommunicationEnvironment();

        //! \brief Disables the communication runtime environment.
        //!
        //! The invoker object AnansiMolecularDynamics::mdCommEnvInvk_
        //! invokes the task to disable the communication environment. After the communication
        //! is disabled, no more commuication can occur and the communication environment can't be 
        //! renabled.The method is called once and only once. Repeated calls results in undefined 
        //! behavoir.
        void
        disableCommunicationEnvironment();

        //! \brief Enables the world communicator.
        //!
        //! The invoker object
        //! AnansiMolecularDynamics::mdWorldCommunicatorInvk_ invokes a task
        //! to create a world communicator. See the documentation on 
        //! RECEIVER::InitWorldCommunicatorTaskReceiver for task details.
        //! AnansiMolecularDynamics::enableWorldCommunicator must be called
        //! after the communication environment is enabled and can be called more
        //! than once.
        void
        enableWorldCommunicator();

        //! \brief Disables the world communicator.
        //!
        //! The invoker object
        //! AnansiMolecularDynamics::mdWorldCommunicatorInvk_ invokes a task
        //! to disable the world communicator. See the documentation on 
        //! RECEIVER::InitWorldCommunicatorTaskReceiver for task details. If the 
        //! the world communicator has not been enabled (via AnansiMolecularDynamics::enableWorldCommunicator)
        //! an exception is thrown. See the documentation on 
        //! RECEIVER::InitWorldCommunicatorTaskReceiver for task details.
        void
        disableWorldCommunicator();

        void
        enableCoreLoggingTasks();

        void
        disableCoreLoggingTasks();

        void
        saveCommandLineOptionParameters();

        void
        enableControlFileTasks();

        void
        disableControlFileTasks();

        // ====================  OPERATORS =======================================

        AnansiMolecularDynamics &
        operator=(AnansiMolecularDynamics const &other) = delete;

        AnansiMolecularDynamics &
        operator=(AnansiMolecularDynamics &&other) = delete;

        // ====================  STATIC =======================================

        // ====================  USING ALIASES =======================================

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  ACCESSORS     =======================================


        // ====================  MUTATORS      =======================================

        // ====================  DATA MEMBERS  =======================================
        COMMANDLINE::CommandLineArguments commandLineArguments_;
        ANANSI::SimulationParameters simulationParameters_;
        std::shared_ptr<COMMUNICATOR::Communicator> MpiWorldCommunicator_;

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

        // ====================  STATIC        =======================================

}; // -----  end of class AnansiMolecularDynamics  -----

}; // -----  end of namespace ANANSI  -----

#endif   // ----- #ifndef anansi_molecular_dynamics_INC  -----
