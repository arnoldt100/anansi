.. _MDProcessCmdLineVisitor class target:

.. default-domain:: cpp

.. namespace:: ANANSI

#####################################
MDProcessCmdLineVisitor Documentation
#####################################

The responsibility of this class is to visit a AnansiMolecularDynamics
simulation object and invoke the appropriate simulation object methods that
will process the command line option of the main program.

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

* #include "MDProcessCmdLineVisitor.h"

==========================================
MDProcessCmdLineVisitor.h Global Variables
==========================================

===========================================
MDProcessCmdLineVisitor Class Documentation
===========================================

.. class:: MDProcessCmdLineVisitor : public MPL::BaseVisitor, public MPL::Visitor<ANANSI::AnansiMolecularDynamics>

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

.. function:: MDProcessCmdLineVisitor::MDProcessCmdLineVisitor()

   The default constructor.

.. function:: MDProcessCmdLineVisitor::MDProcessCmdLineVisitor( const MDProcessCmdLineVisitor &other )

    The copy constructor.

.. function:: MDProcessCmdLineVisitor::MDProcessCmdLineVisitor(MDProcessCmdLineVisitor && other) 

    The copy-move constructor.

.. function:: MDProcessCmdLineVisitor::~MDProcessCmdLineVisitor()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: void MDProcessCmdLineVisitor::visit(AnansiMolecularDynamics& a_simulation) const

    :param  a_simulation: A simulation object. 

    :rtype: void


^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDProcessCmdLineVisitor& MDProcessCmdLineVisitor::operator=( MDProcessCmdLineVisitor const & other)

    The assignment operator.

.. function:: MDProcessCmdLineVisitor& MDProcessCmdLineVisitor::operator=( MDProcessCmdLineVisitor && other)

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
