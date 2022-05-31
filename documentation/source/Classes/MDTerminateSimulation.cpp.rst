.. _MDTerminateSimulation class target:

.. default-domain:: cpp

.. namespace:: ANANSI

###################################
MDTerminateSimulation Documentation
###################################

The responsibilty of this class is to store the program logic to terminate
the simulation for the AnansiMolecularDynamics simulation.

Specifically, the critical function call is MDTerminate::Execute\_. When
invoked, a vistor for the AnansiMolecularDynamics object is created, the
AnansiMolecularDynamics will accept the vistor which in turn will perform the
neccesary function calls to terminate the simulation.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "TerminateSimulation.h"

===========================
Implementation Header Files
===========================

**C++ Include Files**

* #include <utility>

**External Library Files**

**Project Include Files**

* #include "MDTerminateSimulationVisitor.h"
* #include "MDTerminateSimulation.h"

========================================
MDTerminateSimulation.h Global Variables
========================================

=========================================
MDTerminateSimulation Class Documentation
=========================================

.. class:: MDTerminateSimulation : public TerminateSimulation

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: MDTerminateSimulation::MDTerminateSimulation()

   The default constructor.

.. function:: MDTerminateSimulation::MDTerminateSimulation( const MDTerminateSimulation &other )

    The copy constructor.

.. function:: MDTerminateSimulation::MDTerminateSimulation(MDTerminateSimulation && other) 

    The copy-move constructor.

.. function:: MDTerminateSimulation::~MDTerminateSimulation()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDTerminateSimulation& MDTerminateSimulation::operator=( MDTerminateSimulation const & other)

    The assignment operator.

.. function:: MDTerminateSimulation& MDTerminateSimulation::operator=( MDTerminateSimulation && other)

    The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

-----------------
Protected Members
-----------------

No protected members

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: void MDTerminateSimulation::Execute_(Simulation * const a_simulation) const final

    The responsibilty of this class is to store the program logic to terminate
    the AnansiMolecularDynamics simulation.

    Specifically, the critical function call is MDTerminateSimulation::Execute\_.
    When invoked, a vistor for the AnansiMolecularDynamics object is created,
    the AnansiMolecularDynamics will accept the vistor which in turn will
    perform the neccesary function calls to terminate the simulation.

    :param a_simulation: A simulation object.

    :rtype: void

^^^^^^^^^
Operators
^^^^^^^^^

^^^^^^^^^
Mutators
^^^^^^^^^

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^

---------------
Private Members
---------------

    No private members

.. Commented out. 
.. ^^^^^^^^^^
.. Life Cycle
.. ^^^^^^^^^^
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
