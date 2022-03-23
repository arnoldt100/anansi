.. _NullSimulationState class target:

.. default-domain:: cpp

.. namespace:: ANANSI

################################
NullSimulationSate Documentation
################################

This is an interface class for the null simulation behavior. This
does nothing.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "SimulationSate.h"

==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <iostream>

**External Library Files**


**Project Include Files**

* #include "NullSimulationSate.h"

======================================
NullSimulationState.h Global Variables
======================================

=======================================
NullSimulationState Class Documentation
=======================================

.. class:: NullSimulationState

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: NullSimulationState::NullSimulationState()

       The default constructor.

    .. function:: NullSimulationState::NullSimulationState( const NullSimulationState &other )

        The copy constructor.

        :param const NullSimulationState &other: The other simulation state to copy construct from.

    .. function:: NullSimulationState::NullSimulationState(NullSimulationState && other) 

        The copy-move constructor.

        :param const NullSimulationState &other: The other simulation state to copy-move construct from.

    .. function:: virtual NullSimulationState::~NullSimulationState()

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: NullSimulationState& NullSimulationState::operator=( NullSimulationState const & other)

        The assignment operator.

    .. function:: NullSimulationState& NullSimulationState::operator=( NullSimulationState && other)

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

    .. function:: void NullSimulationState::_initializeSimulationEnvironment(Simulation * const aSimulation) const

        Implements the non-virtual interface private virtual
        for intializing the simulation environment.

        This function should be overriden for by all valid NullSimulationState states.

        :param Simulation* const aSimulation: A pointer to a simulation object. 
                                              This simulation object is to have its simulation environment
                                              initialized.

        :rtype: void


    .. function:: void NullSimulationState::_processCommandLine(Simulation * const aSimulation) const

        Implements the non-virtual interface private virtual
        for processing the command line arguments.

        :param Simulation* const aSimulation: A pointer to a simulation object. 

        :rtype: void

    .. function:: void NullSimulationState::_initializeInitialConditions(Simulation* const aSimulation) const 

        Implements the non-virtual interface private virtual 
        for initializing the initial conditions.

        :param Simulation* const aSimulation: A pointer to a simulation object. 

        :rtype: void

    .. function:: void NullSimulationState::_performSimulation(Simulation* const aSimulation) const

        Implements the non-virtual interface private virtual extension
        for performing the simulation.

        :param Simulation* const aSimulation: A pointer to a simulation object. 

        :rtype: void

    .. function:: void NullSimulationState::_terminateSimulationEnvironment(Simulation* const aSimulation) const

        Implements the Non-Virtual Interface private virtual extension point
        for terminating the simulation environment.

        :param Simulation* const aSimulation: A pointer to a simulation object. 

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
