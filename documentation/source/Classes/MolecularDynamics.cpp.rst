.. _MolecularDynamics class target:

.. default-domain:: cpp

.. namespace:: ANANSI

###############################
MolecularDynamics Documentation
###############################

The base class for the MolecularDynamics classes. This
class is an abstract base class, and it is not copyable
assignable, copy movebale, or assignment moveable. 

==============================
Interface Header File Includes
==============================

**C++ Include Files**

* #include <iostream>
* #include <memory>

**External Library Files**

* #include <boost/program_options.hpp>

**Project Include Files**

* #include "AnansiMDState.h"

==================================
Implementaion Header File Includes
==================================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "MolecularDynamics.h"


====================================
MolecularDynamics.h Global Variables
====================================

=====================================
MolecularDynamics Class Documentation
=====================================

.. class:: MolecularDynamics

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: MolecularDynamics::MolecularDynamics()

       The default constructor.

    .. function:: MolecularDynamics::MolecularDynamics( MolecularDynamics const &other ) = delete

        The copy constructor. This function is deleted.

        :param MolecularDynamics const & other: The other object to be copied.

    .. function:: MolecularDynamics::MolecularDynamics( MolecularDynamics &&other )=delete

        The copy move constructor. This function is deleted.

        :param MolecularDynamics const & other: The other object to be copied.

    .. function:: virtual MolecularDynamics::~MolecularDynamics()=0

        The destructor. This is a pure virtual destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    .. function:: bool isISEStatusOkay() const

        Implements the interface for checking if the ISEState of the MD object is
        in a satisfactory status. If the MD state is in a satisfactory status then
        true is returned, otherwise false is returned.
        
        :rtype: bool

    ..function:: bool isISEGloalStatusOkay() const

        Implements the interface for checking if the global status of the ISEState of the MD object
        is in a satisfactory status. If the MD state is in a satisfactory status then true is
        returned, otherwise false is returned.
        
        :rtype: bool

    .. function:: bool isIICStatusOkay() const

        Implements the interface for checking if the IICState of the MD object is
        in a satisfactory status. If the MD state is ina satisfactory status then
        true is returned, otherwise false is returned.
        
        :rtype: bool

    .. function:: ANANSI::RegistryAnansiMDStatus status() const

        Returns the status of the MD object

        :rtype: ANANSI::RegistryAnansiMDStatus

    .. function:: ANANSI::RegistryAnansiMDStatus globalStatus() const

        Returns the global status of the MD objects in the communicator group.

        :rtype: ANANSI::RegistryAnansiMDStatus

    .. function:: bool isHelpOnCommandLine() const

        If the help option in ont the command line, then true is returned. Otherwise
        false is returned.

        :rtype: bool

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: MolecularDynamics& MolecularDynamics::operator=(MolecularDynamics const & other) = delete 

        The assingment operator. This function is deleted.

    .. function:: MolecularDynamics& MolecularDynamics::operator=(MolecularDynamics && other) = delete 

        The assingment move operator. This function is deleted.

^^^^^^^^
Mutators
^^^^^^^^

**Only** :cpp:any:`main <main>` **calls these functions.**


    .. function:: void MolecularDynamics::initializeSimulationEnvironment( int const argc, char const * const * const & argv )

        Initializes the simulation execution environmnet. This function is the public
        interface of the template design pattern for intializing the simulation. The
        derived class is to provide the implementation. The main program creates a MD object
        which makes this call. The MD object then uses is state object to call the state object's 
        member function initializeSimulationEnvironment.

        :param int const & argc: The number of command line arguments
        :param char const * const * const &argv: Contains the command line arguments.
        :rtype: void

    .. function:: void processCommandLine() 

        This function is invoked only by the main program, it stores the command line arguments in
        the MD object.

        :rtype: void

    .. function:: void initializeInitialConditions()

        This function is invoked only by the main program, and it initiates initializing the
        initial conditions of the MD object.

        :rtype: void

    .. function:: void performSimulation()

        This function is invoked only by the main program, and it initiates the
        actual MD simulation steps.

        :rtype: void


    .. function void terminateSimulationEnvironment()

        This function is invoked only by the main program, and it initiates the
        termination of the simulation.

        :rtype: void


**Only** :cpp:class:`AnansiMDStateISE <AnansiMDStateISE>` **calls these functions.**

    .. function:: void saveCommandLineArguments (int const & argc, char const *const *const & argv)

        This function stores the command line arguments in the MD object. If called multiple times,
        the previous stored command line information will be overwriten and lost.

        :param int const & argc: The number of command line arguments
        :param char const * const * const &argv: Contains the command line arguments.
        :rtype: void

    .. function:: void MolecularDynamics::doSimulation() 

        Performs the simulation. The function is final and serves as the public
        interface of the template design pattern. The derived class is to provide 
        its implementation for performaing the simulation.


    .. function:: void MolecularDynamics::disableCommunication()

        Disables MPI execution environment. This function is the public
        interface of the template design pattern for disabling the communication. The
        derived class is to provide the implementation.

    Only the :cpp:class:`AnansiMDStateISE <AnansiMDStateISE>` object calls these functions to initialize the simulation environment.

    .. function:: void MolecularDynamics::saveCommandLineArguments (int const & argc, char const *const *const & argv)

        This function is the interface for saving the command line argc and argv to the MD object. If
        this functions fails to store argc and argv in the MD object, then the program will have
        undefined behavior and must be aborted. 

        :param int const & argc: The number of command line arguments
        :param char const * const * const &argv: Contains the command line arguments.
        :rtype: void

    .. function:: void MolecularDynamics::initializeMpiEnvironment(int const & argc, char const *const *const & argv)

        Initializes the MPI enviroment. This is function is the public interface for initializing the
        MPI environment. All processes are to make this call, and after it's successful completion
        the MPI runtime environment is enabled.

        :param int const & argc: The number of command line arguments
        :param char const * const * const &argv: Contains the command line arguments.
        :rtype: void

    .. function:: void MolecularDynamics::enableCommunication()

        Enables MPI execution environment. This function is the public interface of the template
        design pattern for enabling the MPI communication among all processs. In other words,
        MPI_COMM_WORLD is duplicated and the stored in the MD object. The derived class
        provides the implementation. 

        :rtype: void

    Only the :cpp:class:`AnansiMDStateIIC <AnansiMDStateIIC>` object calls these functions to
    initialize the simulation initial conditions.

    .. function:: void readInitialConfiguration()

        This functions reads the initial configuration of the MD sumulation. This function is the
        public interface. The initial configuration is read and stored in the MD object. 

        :rtype: void

    **These group of functions change the state of the MD object.**

    .. function:: void changeMDStateToISE()

        This function changes the MD object state to :cpp:class:`AnansiMDStateISE`.
        This function is a public interface and the derived class provides the implementation.

        :rtype: void

    .. function:: void changeMDStateToPCL()

        This function changes the MD object state to :cpp:class:`AnansiMDStatePCL`.
        This function is a public interface and the derived class provides the implementation.

        :rtype: void

    .. function:: void changeMDStateToIIC()

        This function changes the MD object state to :cpp:class:`AnansiMDStateIIC`.
        This function is a public interface and the derived class provides the implementation.

        :rtype: void

    .. function:: void changeMDStateToPS()

        This function changes the MD object state to :cpp:class:`AnansiMDStatePS`.
        This function is a public interface and the derived class provides the implementation.

        :rtype: void


    .. function:: void changeMDStateToTSE()

        This function changes the MD object state to :cpp:class:`AnansiMDStateTSE`.
        This function is a public interface and the derived class provides the implementation.

        :rtype: void

    **These function change the status of the MD object.**

    .. function:: void MolecularDynamics::setStatus(const RegistryAnansiMDStatus aStatus)

        Changes the status of the MD simulation. The derived class provides the implementation.

        :param const RegistryAnansiMDStatus & aStatus: The new status to set the simulation to.
        :rtype: void

    .. function:: void MolecularDynamics::setGlobalISEStatus()

        Changes the global status of the MD simulation. All processes in the communication group
        must call this method. The status of each MD object is globally reduced, and the result of
        the reduction is distributed to all processes. If any MD object has an ISE status of failed,
        then all objects are set to a global status of ISE fail.  

.. -----------------
.. Protected Members
.. -----------------
.. 
..     No protected members
.. 
.. Commented out. 
.. ^^^^^^^^^
.. Lifecycle
.. ^^^^^^^^^
..
.. ^^^^^^^^^
.. Accessors
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^
.. Operators
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^
.. Mutators
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^

---------------
Private Members
---------------

.. ^^^^^^^^^
.. Accessors
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^
.. Operators
.. ^^^^^^^^^

^^^^^^^^
Mutators
^^^^^^^^

    .. function:: virtual void MolecularDynamics::_doSimulation()=0

        Performs the MD simulation. This function must be overriden in the derived class
        or a compile time error will occur.

    .. function:: virtual void MolecularDynamics::_enableCommunication()=0

        Enables the MPI communication. This function must be overriden in the derived class or a
        compile time error will occur.

    .. function:: virtual void MolecularDynamics::_disableCommunication()=0

        Disables the MPI communication. This function must be overriden in the derived class or a
        compile time error will occur.

    .. function:: virtual void MolecularDynamics::_initializeSimulationEnvironment( int const argc, char const * const * const & argv )=0

        Initializes the simulation execution environment. This function must be overriden in the
        derived class or a compile time error will occur.

    .. function:: virtual void MolecularDynamics::_initializeSimulation( int const argc, char const * const * const & argv )=0

        Initializes the simulation to its initial conditions. This function must be overriden in the
        derived class or a compile time error will occur.

    .. function:: virtual void MolecularDynamics::MolecularDynamics::_setMDState(std::unique_ptr && a_AnansiMDState)=0

        Changes the state of the MD simulation. This function must be overriden in the derived class
        or a compile time error will occur.

        :param std::unique_ptr && a_AnansiMDState: The state to change the simulation to.

.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^
