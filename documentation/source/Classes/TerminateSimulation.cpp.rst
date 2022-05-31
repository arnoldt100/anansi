.. _TerminateSimulation class target:

.. default-domain:: cpp

.. namespace:: ANANSI

#################################
TerminateSimulation Documentation
#################################

This class' responsibility is to serve as an interface for the behavior for
terminating the simulation.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "SimulationState.h"

===========================
Implementation Header Files
===========================

**C++ Include Files**

* #include <utility>

**External Library Files**

**Project Include Files**

* #include "TerminateSimulation.h"

======================================
TerminateSimulation.h Global Variables
======================================

=======================================
TerminateSimulation Class Documentation
=======================================

.. class:: TerminateSimulation : public SimulationState

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: TerminateSimulation::TerminateSimulation()

   The default constructor.

.. function:: TerminateSimulation::TerminateSimulation( const TerminateSimulation &other )

    The copy constructor.

.. function:: TerminateSimulation::TerminateSimulation(TerminateSimulation && other) 

    The copy-move constructor.

.. function:: virtual TerminateSimulation::~TerminateSimulation()=0

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: TerminateSimulation& TerminateSimulation::operator=( TerminateSimulation const & other)

    The assignment operator.

.. function:: TerminateSimulation& TerminateSimulation::operator=( TerminateSimulation && other)

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

.. function:: void TerminateSimulation::execute_(Simulation * const a_simulation) const override

    This method overrides SimulationState::execute\_, and it's provides an
    interface for the deriving concrete class. Currently the method invokes the
    virtual function TerminateSimulation::Execute\_.

    :param a_simulation: A simulation object
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
