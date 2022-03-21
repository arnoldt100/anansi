.. _Simulation class target:

.. default-domain:: cpp

.. namespace:: ANANSI

########################
Simulation Documentation
########################

This is an interface class for the various simulation states. We are using the
State design pattern to implement concrete simulation behavoirs,

AnansiMolecularDynamics has 5 states or behaviors:

* InitSimEnv

    This state controls the behavoir for initialzing various execution
    environments such as MPI, GPU accelerators, etc.

* ProcessCmdLine

    This states controls the behavior processing the command line options. This
    state can't be performed unless the InitSimEnv is
    successfully completed.
    
* InitInitialConditions

    This state controls the behavoir for initialization of the simulation -
    reading various input files, setting up various MPI communicators,
    initializing the starting configurations, etc.  Essentially, this state
    gets the simulation to its initial starting configuration.  This state
    can't be performed unless the ProcessCmdLine is successfully
    completed. 

* PerformSimulation

    This state controls the behavior of the actual simulation. This state can't
    be performed unless the InitSimEnv is successfully completed.

* TerminatingSimulation

    This state controls the termination of various execution environments such as MPI,
    GPU accelerators, etc. This state can be performed at any time.

====================
Include Header Files
====================

**C++ Include Files**

* #include <utility>
* #include <iostream>

**External Library Files**

**Project Include Files**

================================
Simulation.h Global Variables
================================

=================================
Simulation Class Documentation
=================================

.. class:: Simulation

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: Simulation::Simulation()

       The default constructor.

    .. function:: Simulation::Simulation( const Simulation &other )

        The copy constructor.

        :param const Simulation &other: The other MD state to copy construct from.

    .. function:: Simulation::Simulation(Simulation && other) 

        The copy-move constructor.

        :param const Simulation &other: The other MD state to copy-move construct from.

    .. function:: virtual Simulation::~Simulation()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    .. function:: void Simulation::initializeSimulationEnvironment(MolecularDynamics * const aMD, int const & argc, char const * const * const & argv ) const

        Implements the interface for intializing the simulation environment.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 
                                              This MD object is to have its simulation environment
                                              initialized.

        :param int const & argc: The number of command line arguments.
        :param char const * const * const & argv: The command line arguments.
        :rtype: void

    .. function:: void Simulation::processCommandLine(MolecularDynamics * const aMD) const

        Implements the interface for processing the command line arguments.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

    .. function:: void Simulation::initializeInitialConditions(MolecularDynamics * const aMD) const 

        Implements the interface for initializing the initial condtions.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 


    .. function:: void Simulation::performSimulation(MolecularDynamics * const aMD) const

        Implements the interface for performing the molecular dynamics simulation.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

    .. function:: void Simulation::terminateSimulationEnvironment(MolecularDynamics * const aMD) const

        Implements the interface for terminating the simulation environment.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: Simulation& Simulation::operator=( Simulation const & other)

        The assignment operator.

    .. function:: Simulation& Simulation::operator=( Simulation && other)

        The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^



-----------------
Protected Members
-----------------

    No protected members

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
.. Lifecycle
.. ^^^^^^^^^

^^^^^^^^^
Accessors
^^^^^^^^^

    .. function:: void Simulation::_initializeSimulationEnvironment(MolecularDynamics * const aMD, int const & argc, char const * const * const & argv ) const

        Implements the Non-Virtual Interface private virtual extension point
        for intializing the simulation environment.

        This function should be overriden for by all valid MD states.
        Currently only the MD state SimulationISE should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 
                                              This MD object is to have its simulation environment
                                              initialized.

        :param int const & argc: The number of command line arguments.
        :param char const * const * const & argv: The command line arguments.
        :rtype: void


    .. function:: void Simulation::_processCommandLine(MolecularDynamics * const aMD) const

        Implements the Non-Virtual Interface private virtual extension point
        for processing the command line arguments.

        This function should be overriden for by all valid MD states.
        Currently only the MD state SimulationPCL should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

    .. function:: void Simulation::_initializeInitialConditions(MolecularDynamics * const aMD) const 

        Implements the Non-Virtual Interface private virtual extension point
        for initializing the initial conditions.

        This function should be overriden for by all valid MD states.
        Currently only the MD state SimulationIIC should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

    .. function:: void Simulation::_performSimulation(MolecularDynamics * const aMD) const

        Implements the Non-Virtual Interface private virtual extension point
        for performing the MD simulation.

        This function should be overriden for by all valid MD states.
        Currently only the MD state SimulationPS should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

    .. function:: void Simulation::_terminateSimulationEnvironment(MolecularDynamics * const aMD) const

        Implements the Non-Virtual Interface private virtual extension point
        for terminating the simulation environment.

        This function should be overriden for by all valid MD states.
        Currently only the MD state SimulationTS should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

.. 
.. ^^^^^^^^^
.. Operators
.. ^^^^^^^^^

^^^^^^^^
Mutators
^^^^^^^^


.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^
