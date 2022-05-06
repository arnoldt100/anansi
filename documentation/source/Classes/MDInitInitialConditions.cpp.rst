.. _MDInitInitialConditions source target:

.. default-domain:: cpp

.. namespace:: ANANSI

#####################################
MDInitInitialConditions Documentation
#####################################

The responsibilty of this class is to store the program logic to initialize the
initial conditions for the AnansiMolecularDynamics simulation.

Specifically, the critical function call is
MDInitInitialConditionsVisitor::Execute\_. When invoked, a vistor for the
AnansiMolecularDynamics object is created, the AnansiMolecularDynamics will
accept the vistor which in turn will perform the neccesary function calls to
initialize the initial conditions.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "InitInitialConditions.h"

==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <utility>

**External Library Files**

**Project Include Files**

* #include "MDInitInitialConditionsVisitor.h"

* #include "MDInitInitialConditions.h"

==========================================
MDInitInitialConditions.h Global Variables
==========================================

===========================================
MDInitInitialConditions Class Documentation
===========================================

.. class:: MDInitInitialConditions : public InitInitialConditions

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

.. function:: MDInitInitialConditions::MDInitInitialConditions()

   The default constructor.

.. function:: MDInitInitialConditions::MDInitInitialConditions( const MDInitInitialConditions &other )

    The copy constructor.

.. function:: MDInitInitialConditions::MDInitInitialConditions(MDInitInitialConditions && other) 

    The copy-move constructor.

.. function:: MDInitInitialConditions::~MDInitInitialConditions()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDInitInitialConditions& MDInitInitialConditions::operator=( MDInitInitialConditions const & other)

    The assignment operator.

.. function:: MDInitInitialConditions& MDInitInitialConditions::operator=( MDInitInitialConditions && other)

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

.. function:: void MDInitInitialConditions::Execute_(Simulation * const a_simulation) const 

    The resposibility of the function is to initialize the initial 
    conditions for the object “a_simulation”. The current implementation uses
    the visitor class MDInitInitialConditionsVisitor to accomplish this task.

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
