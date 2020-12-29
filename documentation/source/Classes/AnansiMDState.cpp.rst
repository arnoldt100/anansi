.. _AnansiMDState class target:

.. default-domain:: cpp

.. namespace:: ANANSI

###########################
AnansiMDState Documentation
###########################

This is the State class for the AnansiMolecularDynamics. We are using the
State design pattern to implement different behavoirs of AnansiMolecularDynamics.

AnansiMolecularDynamics has 5 states or beahvoirs:

* InitializingSimulationEnvironment

    This state controls initialzing various execution environments such as MPI,
    GPU accelerators, etc.

* ProcessingCommandLine

    This states controls processing the command line options. This state can't
    be performed unless the InitializingSimulationEnvironment is successfully
    completed.
    
* InitializingInitialCondition

    This state controls initialization of the simulation - reading various
    input files, setting up various MPI communicators, initializing the
    starting configurations, etc.  Essentially, this state gets the simulation
    to its initial starting configuration.  This state can't be performed
    unless the ProcessingCommandLine is successfully completed. 

* PerformingSimulation

    This state does the actual MD simulation. This state can't be performed
    unless the InitializingSimulationEnvironment is successfully completed.

* TerminatingSimulationEnvironmnet

    This state controls terminates various execution environments such as MPI,
    GPU accelerators, etc.

====================
Include Header Files
====================

**C++ Include Files**

* #include <utility>
* #include <iostream>

**External Library Files**

**Project Include Files**

================================
AnansiMDState.h Global Variables
================================

=================================
AnansiMDState Class Documentation
=================================

.. class:: AnansiMDState

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: AnansiMDState::AnansiMDState()

       The default constructor.

    .. function:: AnansiMDState::AnansiMDState( const AnansiMDState &other )

        The copy constructor.

    .. function:: AnansiMDState::AnansiMDState(AnansiMDState && other) 

        The copy-move constructor.

    .. function:: AnansiMDState::~AnansiMDState()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: AnansiMDState& AnansiMDState::operator=( AnansiMDState const & other)

        The assignment operator.

    .. function:: AnansiMDState& AnansiMDState::operator=( AnansiMDState && other)

        The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

    .. function:: void AnansiMDState::initializeSimulationEnvironment()

        Initializes the simulation environment.

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

    No private members

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

^^^^^^^^
Mutators
^^^^^^^^

    .. function virtual void _initializeSimulationEnvironment()

        This function should be overriden for by all valid MD states. If not
        overriden, then this base method is called and a error is thrown.
        Curremtly only the MD state AnansiMDStateISE should override this
        method.

.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^
