.. _SimulationState class target:

.. default-domain:: cpp

.. namespace:: ANANSI

##############################
Simulation State Documentation
##############################

This is an interface class for the various simulation states. We are using the
State design pattern to implement concrete simulation behavoirs,

All simulations have 5 states or behaviors:

* InitSimEnv

    This state controls the behavoir for initializing various execution
    environments such as MPI, GPU accelerators, etc.

* ProcessCmdLine

    This state controls the behavior processing the command line options. This
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

    This state controls the behavior of the performing simulation. This state
    can't be performed unless the InitInitialConditions is successfully
    completed.

* TerminateSimulation

    This state controls the termination of various execution environments such
    as MPI, GPU accelerators, etc. This state can be performed at any time.

====================
Include Header Files
====================

**C++ Include Files**

* #include <utility>
* #include <iostream>

**External Library Files**

**Project Include Files**

==================================
SimulationState.h Global Variables
==================================

===================================
SimulationState Class Documentation
===================================

.. class:: SimulationState

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

        :param const Simulation &other: The other simulation state to copy construct from.

    .. function:: Simulation::Simulation(Simulation && other) 

        The copy-move constructor.

        :param const Simulation &other: The other simulation state to copy-move construct from.

    .. function:: virtual Simulation::~Simulation()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    .. function:: void SimulationState::initializeSimulationEnvironment(Simulation * const aSimulation) const

        Implements the interface for intializing the simulation environment.

        :param Simulation * const aSimulation: A pointer to a simulation object. 

    .. function:: void Simulation::processCommandLine(Simulation * const aSimulation) const

        Implements the interface for processing the command line arguments.

        :param Simulation * const aSimulation: A pointer to a simulation object. 

    .. function:: void Simulation::initializeInitialConditions(Simulation * const aSimulation) const 

        Implements the interface for initializing the initial condtions.

        :param Simulation * const aSimulation: A pointer to a simulation object. 


    .. function:: void Simulation::performSimulation(Simulation * const aSimulation) const

        Implements the interface for performing the simulation simulation.

        :param Simulation * const aSimulation: A pointer to a simulation object. 

    .. function:: void Simulation::terminateSimulationEnvironment(Simulation * const aSimulation) const

        Implements the interface for terminating the simulation environment.

        :param Simulation * const aSimulation: A pointer to a simulation object. 

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

    .. function:: void Simulation::_initializeSimulationEnvironment(Simulation * const aSimulation) const

        Implements the non-virtual interface private virtual extension point
        for intializing the simulation environment.

        This function should be overriden for by all valid Simulation states.

        :param Simulation * const aSimulation: A pointer to a simulation object. 
                                                      This simulation object is to have its simulation environment
                                                      initialized.

        :rtype: void


    .. function:: void Simulation::_processCommandLine(Simulation * const aSimulation) const

        Implements the Non-Virtual Interface private virtual extension point
        for processing the command line arguments.

        This function should be overriden for by all valid simulation states.
        Currently only the simulation state PerformSimulation should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param Simulation * const aSimulation: A pointer to a simulation object. 

        :rtype: void

    .. function:: void Simulation::_initializeInitialConditions(Simulation * const aSimulation) const 

        Implements the non-virtual interface private virtual 
        for initializing the initial conditions.

        This function should be overriden for by all valid simulation states.
        Currently only the simulation  state InitInitialConditions should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param Simulation * const aSimulation: A pointer to a simulation object. 

        :rtype: void

    .. function:: void Simulation::_performSimulation(Simulation * const aSimulation) const

        Implements the non-virtual interface private virtual extension
        for performing the simulation.

        This function should be overriden for by all valid simulation  states.
        Currently only the simulation  state PerformSimulation should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param Simulation * const aSimulation: A pointer to a simulation object. 

        :rtype: void

    .. function:: void Simulation::_terminateSimulationEnvironment(Simulation * const aSimulation) const

        Implements the Non-Virtual Interface private virtual extension point
        for terminating the simulation environment.

        This function should be overriden for by all valid simulation  states.
        Currently only the simulation state TerminateSimulation should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param Simulation * const aSimulation: A pointer to a simulation object. 

        :rtype: void

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
