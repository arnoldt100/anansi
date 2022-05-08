.. _PerformSimulation source target:

.. default-domain:: cpp

.. namespace:: ANANSI

###############################
PerformSimulation Documentation
###############################

This class' responsibility is to serve as an interface for the behavior for
performing the simulation.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

====================================
PerformSimulation.h Global Variables
====================================

=====================================
PerformSimulation Class Documentation
=====================================

.. class:: PerformSimulation : public SimulationState

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

.. function:: PerformSimulation::PerformSimulation()

   The default constructor.

.. function:: PerformSimulation::PerformSimulation( const PerformSimulation &other )

    The copy constructor.

.. function:: PerformSimulation::PerformSimulation(PerformSimulation && other) 

    The copy-move constructor.

.. function:: virtual PerformSimulation::~PerformSimulation()=0

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: PerformSimulation& PerformSimulation::operator=( PerformSimulation const & other)

    The assignment operator.

.. function:: PerformSimulation& PerformSimulation::operator=( PerformSimulation && other)

    The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

-----------------
Protected Members
-----------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: void PerformSimulation::execute_(Simulation * const a_simulation) const override

    This method overrides SimulationState::execute\_, and it's provides an
    interface for the deriving concrete class. Currently the method invokes the
    virtual function PerformSimulation::Execute\_.

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
