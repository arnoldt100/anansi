.. _MDInitInitialConditionsVisitor class target:

.. default-domain:: cpp

.. namespace:: ANANSI

############################################
MDInitInitialConditionsVisitor Documentation
############################################

The base class for the molecular dynamics factory classes. This
class is an abstract base class. 

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

* #include "MDInitInitialConditionsVisitor.h"

=================================================
MDInitInitialConditionsVisitor.h Global Variables
=================================================

==================================================
MDInitInitialConditionsVisitor Class Documentation
==================================================

.. class:: MDInitInitialConditionsVisitor : public MPL::BaseVisitor, public MPL::Visitor<AnansiMolecularDynamics>


--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

.. function:: MDInitInitialConditionsVisitor::MDInitInitialConditionsVisitor()

   The default constructor.

.. function:: MDInitInitialConditionsVisitor::MDInitInitialConditionsVisitor( const MDInitInitialConditionsVisitor &other )

    The copy constructor.

.. function:: MDInitInitialConditionsVisitor::MDInitInitialConditionsVisitor(MDInitInitialConditionsVisitor && other) 

    The copy-move constructor.

.. function:: MDInitInitialConditionsVisitor::~MDInitInitialConditionsVisitor()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: void MDInitInitialConditionsVisitor::visit(AnansiMolecularDynamics& a_simulation) const

    On invocation of this method, the
    initial conditions (or configuration) of the
    a_simulation object will be set.

    :param a_simulation: An AnansiMolecularDynamics simulation object that is
                         being visited. 
                         

    :rtype: void

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDInitInitialConditionsVisitor& MDInitInitialConditionsVisitor::operator=( MDInitInitialConditionsVisitor const & other)

    The assignment operator.

.. function:: MDInitInitialConditionsVisitor& MDInitInitialConditionsVisitor::operator=( MDInitInitialConditionsVisitor && other)

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
