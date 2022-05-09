.. _NullSimulation class target:

.. default-domain:: cpp

.. namespace:: ANANSI

############################
NullSimulation Documentation
############################

This is an interface class for the null simulation behavior. This
does nothing.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "SimulationState.h"

==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <iostream>

**External Library Files**


**Project Include Files**

* #include "NullSimulation.h"

======================================
NullSimulation.h Global Variables
======================================

=======================================
NullSimulation Class Documentation
=======================================

.. class:: NullSimulation : public SimulationState

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: NullSimulation::NullSimulation()

       The default constructor.

    .. function:: NullSimulation::NullSimulation( const NullSimulation &other )

        The copy constructor.

        :param const NullSimulation &other: The other simulation state to copy construct from.

    .. function:: NullSimulation::NullSimulation(NullSimulation && other) 

        The copy-move constructor.

        :param const NullSimulation &other: The other simulation state to copy-move construct from.

    .. function:: virtual NullSimulation::~NullSimulation() = 0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: NullSimulation& NullSimulation::operator=( NullSimulation const & other)

        The assignment operator.

    .. function:: NullSimulation& NullSimulation::operator=( NullSimulation && other)

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

    .. function:: void NullSimulation::_initializeSimulationEnvironment(Simulation * const a_simulation) const

        Implements the non-virtual interface private virtual
        for intializing the simulation environment.

        This function should be overriden for by all valid NullSimulation states.

        :param a_simulation: A pointer to a simulation object. 
                                              This simulation object is to have its simulation environment
                                              initialized.

        :rtype: void


    .. function:: void NullSimulation::_processCommandLine(Simulation * const a_simulation) const

        Implements the non-virtual interface private virtual
        for processing the command line arguments.

        :param a_simulation: A pointer to a simulation object. 

        :rtype: void

    .. function:: void NullSimulation::_initializeInitialConditions(Simulation* const a_simulation) const 

        Implements the non-virtual interface private virtual 
        for initializing the initial conditions.

        :param a_simulation: A pointer to a simulation object. 

        :rtype: void

    .. function:: void NullSimulation::_performSimulation(Simulation* const a_simulation) const

        Implements the non-virtual interface private virtual extension
        for performing the simulation.

        :param a_simulation: A pointer to a simulation object. 

        :rtype: void

    .. function:: void NullSimulation::_terminateSimulationEnvironment(Simulation* const a_simulation) const

        Implements the Non-Virtual Interface private virtual extension point
        for terminating the simulation environment.

        :param a_simulation: A pointer to a simulation object. 

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
