.. _MDPerformSimulationVisitor source target:

.. default-domain:: cpp

.. namespace:: ANANSI

########################################
MDPerformSimulationVisitor Documentation
########################################

The responsibility of this class is to visit a AnansiMolecularDynamics
simulation object and invoke the appropriate simulation object methods that
will perform the AnansiMolecularDynamics simulation.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "BaseVisitor.h"
* #include "Visitor.hpp"
* #include "AnansiMolecularDynamics.h"


==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <iostream>

**External Library Files**

**Project Include Files**

* #include "MDPerformSimulationVisitor.h"

=============================================
MDPerformSimulationVisitor.h Global Variables
=============================================

==============================================
MDPerformSimulationVisitor Class Documentation
==============================================

.. class:: MDPerformSimulationVisitor : public MPL::BaseVisitor, public MPL::Visitor<ANANSI::AnansiMolecularDynamics>

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

.. function:: MDPerformSimulationVisitor::MDPerformSimulationVisitor()

   The default constructor.

.. function:: MDPerformSimulationVisitor::MDPerformSimulationVisitor( const MDPerformSimulationVisitor &other )

    The copy constructor.

.. function:: MDPerformSimulationVisitor::MDPerformSimulationVisitor(MDPerformSimulationVisitor && other) 

    The copy-move constructor.

.. function:: MDPerformSimulationVisitor::~MDPerformSimulationVisitor()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: void MDPerformSimulationVisitor::visit(AnansiMolecularDynamics& a_simulation) const

    :param  a_simulation: A simulation object. 

    :rtype: void


^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDPerformSimulationVisitor& MDPerformSimulationVisitor::operator=( MDPerformSimulationVisitor const & other)

    The assignment operator.

.. function:: MDPerformSimulationVisitor& MDPerformSimulationVisitor::operator=( MDPerformSimulationVisitor && other)

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
