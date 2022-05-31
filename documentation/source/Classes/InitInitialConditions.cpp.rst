.. _InitInitialConditions class target:

.. default-domain:: cpp

.. namespace:: ANANSI

###################################
InitInitialConditions Documentation
###################################

The class' responsibility is to serve as an interface for the behavior of
initializing the initial conditions of the simulation.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "SimulationState.h"

==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <utility>

**External Library Files**

**Project Include Files**

* #include "InitInitialConditions.h"

========================================
InitInitialConditions.h Global Variables
========================================

=========================================
InitInitialConditions Class Documentation
=========================================

.. class:: InitInitialConditions : public SimulationState

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

.. function:: InitInitialConditions::InitInitialConditions()

   The default constructor.

.. function:: InitInitialConditions::InitInitialConditions( const InitInitialConditions &other )

    The copy constructor.

.. function:: InitInitialConditions::InitInitialConditions(InitInitialConditions && other) 

    The copy-move constructor.

.. function:: virtual InitInitialConditions::~InitInitialConditions()=0

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: InitInitialConditions& InitInitialConditions::operator=( InitInitialConditions const & other)

    The assignment operator.

.. function:: InitInitialConditions& InitInitialConditions::operator=( InitInitialConditions && other)

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
.. function:: void InitInitialConditions::execute_(Simulation * const a_simulation) const override

    :rtype: void

.. function:: virtual void InitInitialConditions::Execute_(Simulation * const a_simulation) const

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
