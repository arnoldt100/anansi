.. _ProcessCmdLine source target:

.. default-domain:: cpp

.. namespace:: ANANSI

############################
ProcessCmdLine Documentation
############################

An abstract base class that define the interface for
for the Process Command Line state. The class is derived from
SimulationState. 

======================
Interface Header Files
======================

**C++ Include Files**

* #include <utility>

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

* #include "ProcessCmdLine.h"

=================================
ProcessCmdLine.h Global Variables
=================================

==================================
ProcessCmdLine Class Documentation
==================================

.. class:: ProcessCmdLine : public SimulationState

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

.. function:: ProcessCmdLine::ProcessCmdLine()

       The default constructor.

.. function:: ProcessCmdLine::ProcessCmdLine( const ProcessCmdLine &other )

        The copy constructor.

.. function:: ProcessCmdLine::ProcessCmdLine(ProcessCmdLine && other) 

        The copy-move constructor.

.. function:: virtual ProcessCmdLine::~ProcessCmdLine()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: ProcessCmdLine& ProcessCmdLine::operator=( ProcessCmdLine const & other)

        The assignment operator.

.. function:: ProcessCmdLine& ProcessCmdLine::operator=( ProcessCmdLine && other)

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

.. function:: void ProcessCmdLine::execute_(Simulation * const a_simulation) const override

    This methods overrides the SimulationState::execute\_.

    :param a_simulation: A simulation object

    :rtype: void

.. function:: virtual void ProcessCmdLine::Execute_(Simulation * const a_simulation) const

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
