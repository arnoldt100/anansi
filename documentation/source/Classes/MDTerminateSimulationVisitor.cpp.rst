.. _MDTerminateSimulationVisitor class target:

.. default-domain:: cpp

.. namespace:: ANANSI

##########################################
MDTerminateSimulationVisitor Documentation
##########################################

The base class for the molecular dynamics factory classes. This
class is an abstract base class. 

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

===============================================
MDTerminateSimulationVisitor.h Global Variables
===============================================

================================================
MDTerminateSimulationVisitor Class Documentation
================================================

.. class:: MDTerminateSimulationVisitor : public MPL::BaseVisitor, public MPL::Visitor<ANANSI::AnansiMolecularDynamics>

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: MDTerminateSimulationVisitor::MDTerminateSimulationVisitor()

   The default constructor.

.. function:: MDTerminateSimulationVisitor::MDTerminateSimulationVisitor( const MDTerminateSimulationVisitor &other )

    The copy constructor.

.. function:: MDTerminateSimulationVisitor::MDTerminateSimulationVisitor(MDTerminateSimulationVisitor && other) 

    The copy-move constructor.

.. function:: MDTerminateSimulationVisitor::~MDTerminateSimulationVisitor()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: void MDTerminateSimulationVisitor::visit(AnansiMolecularDynamics& a_simulation) const

    :param a_simulation: A simulation object

    :rtype: void

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDTerminateSimulationVisitor& MDTerminateSimulationVisitor::operator=( MDTerminateSimulationVisitor const & other)

    The assignment operator.

.. function:: MDTerminateSimulationVisitor& MDTerminateSimulationVisitor::operator=( MDTerminateSimulationVisitor && other)

    The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

-----------------
Protected Members
-----------------

No protected members

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
