.. _MDPerformSimulation source target:

.. default-domain:: cpp

.. namespace:: ANANSI

#################################
MDPerformSimulation Documentation
#################################


The responsibilty of this class is to store the program logic to perform
the simulation for the AnansiMolecularDynamics object.

Specifically, the critical function call is MDPerformSimulation::Execute\_. When
invoked, a vistor for the AnansiMolecularDynamics object is created, the
AnansiMolecularDynamics will accept the vistor which in turn will perform the
neccesary function calls to perform the simulation.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "PerformSimulation.h"

===========================
Implementation Header Files
===========================

**C++ Include Files**

* #include <utility>

**External Library Files**

**Project Include Files**

* #include "MDPerformSimulationVisitor.h"
* #include "MDPerformSimulation.h"

======================================
MDPerformSimulation.h Global Variables
======================================

=======================================
MDPerformSimulation Class Documentation
=======================================

.. class:: MDPerformSimulation : public PerformSimulation

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: MDPerformSimulation::MDPerformSimulation()

   The default constructor.

.. function:: MDPerformSimulation::MDPerformSimulation( const MDPerformSimulation &other )

    The copy constructor.

.. function:: MDPerformSimulation::MDPerformSimulation(MDPerformSimulation && other) 

    The copy-move constructor.

.. function:: MDPerformSimulation::~MDPerformSimulation()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDPerformSimulation& MDPerformSimulation::operator=( MDPerformSimulation const & other)

    The assignment operator.

.. function:: MDPerformSimulation& MDPerformSimulation::operator=( MDPerformSimulation && other)

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

.. function:: void Execute_(Simulation * const a_simulation) const final

    The resposibility of the function is to perform the simulation for
    the object “a_simulation”. The current implementation uses the visitor class
    MDPerformSimulationVisitor to accomplish this task.

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
