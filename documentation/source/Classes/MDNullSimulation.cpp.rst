.. _MDNullSimulation class target:

.. default-domain:: cpp

.. namespace:: ANANSI

##############################
MDNullSimulation Documentation
##############################

The responsibilty of this class is to store the program logic for a null
simulation state for the AnansiMolecularDynamics simulation.

Specifically, the critical function call is
MDNullSimulationVisitor::Execute\_. When invoked, a vistor for the
AnansiMolecularDynamics object is created, the AnansiMolecularDynamics will
accept the vistor which in turn will perform the neccesary function calls to
do tasks for a null simulation.

A null simulation does nothing.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "NullSimulation.h"

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "MDNullSimulationVisitor.h"
* #include "MDNullSimulation.h"

===================================
MDNullSimulation.h Global Variables
===================================

====================================
MDNullSimulation Class Documentation
====================================

.. class:: MDNullSimulation : public NullSimulation

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: MDNullSimulation::MDNullSimulation()

   The default constructor.

.. function:: MDNullSimulation::MDNullSimulation( const MDNullSimulation &other )

    The copy constructor.

.. function:: MDNullSimulation::MDNullSimulation(MDNullSimulation && other) 

    The copy-move constructor.

.. function:: MDNullSimulation::~MDNullSimulation()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDNullSimulation& MDNullSimulation::operator=( MDNullSimulation const & other)

    The assignment operator.

.. function:: MDNullSimulation& MDNullSimulation::operator=( MDNullSimulation && other)

    The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

-----------------
Protected Members
-----------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: void MDNullSimulation::Execute_(Simulation * const a_simulation) const final

    The resposibility of the function is to do null tasks
    for the object “a_simulation”. The current implementation uses the visitor
    class MDNullSimulationVisitor to accomplish this task.

    :param a_simulation:  A simulation object.
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
