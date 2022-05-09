.. _MDNullSimulationVisitor source target:

.. default-domain:: cpp

.. namespace:: ANANSI

#####################################
MDNullSimulationVisitor Documentation
#####################################

The responsibility of this class is to visit a AnansiMolecularDynamics
simulation object and invoke the appropriate simulation object methods that
will process null tasks of the main program.

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

* #include "MDNullSimulationVisitor.h"

==========================================
MDNullSimulationVisitor.h Global Variables
==========================================

===========================================
MDNullSimulationVisitor Class Documentation
===========================================

.. class:: MDNullSimulationVisitor : public MPL::BaseVisitor, public MPL::Visitor<ANANSI::AnansiMolecularDynamics>

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

.. function:: MDNullSimulationVisitor::MDNullSimulationVisitor()

   The default constructor.

.. function:: MDNullSimulationVisitor::MDNullSimulationVisitor( const MDNullSimulationVisitor &other )

    The copy constructor.

.. function:: MDNullSimulationVisitor::MDNullSimulationVisitor(MDNullSimulationVisitor && other) 

    The copy-move constructor.

.. function:: MDNullSimulationVisitor::~MDNullSimulationVisitor()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: void MDNullSimulationVisitor::visit(AnansiMolecularDynamics& a_simulation) const

    :param  a_simulation: A simulation object. 

    :rtype: void


^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDNullSimulationVisitor& MDNullSimulationVisitor::operator=( MDNullSimulationVisitor const & other)

    The assignment operator.

.. function:: MDNullSimulationVisitor& MDNullSimulationVisitor::operator=( MDNullSimulationVisitor && other)

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
