.. default-domain:: cpp

.. namespace:: ANANSI

######################################
AnansiMDState Documentation
######################################

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
    
* InitializingSimulation

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

* #include <dummy1>
* #include <dummy2>

**External Library Files**

* #include "dummy3"

**Project Include Files**

* #include "dummy4"
* #include "dummy5"

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

    .. function:: AnansiMDState()

       The default constructor.

    .. function:: AnansiMDState( const AnansiMDState &other )

        The copy constructor.

    .. function:: AnansiMDState(AnansiMDState && other) 

        The copy-move constructor.

    .. function:: ~AnansiMDState()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: AnansiMDState& operator=( AnansiMDState const & other)

        The assignment operator.

    .. function:: AnansiMDState& operator=( AnansiMDState && other)

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
.. 
.. ^^^^^^^^^
.. Mutators
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^
