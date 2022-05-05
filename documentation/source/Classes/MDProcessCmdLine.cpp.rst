.. _MDProcessCmdLine source target:

.. default-domain:: cpp

.. namespace:: ANANSI

##############################
MDProcessCmdLine Documentation
##############################

The responsibilty of this class is to store the program logic to 
process the command line arguments for the AnansiMolecularDynamics
simulation.

Specifically, the critical function call is MDProcessCmdLine::Execute\_. When
invoked, a vistor for the AnansiMolecularDynamics object is created, the
AnansiMolecularDynamics will accept the vistor which in turn will perform the neccesary
function calls to store the command line arguments.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "ProcessCmdLine.h"

==========================
Implementaion Header Files
==========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "MDProcessCmdLineVisitor.h"
* #include "MDProcessCmdLine.h"

===================================
MDProcessCmdLine.h Global Variables
===================================

====================================
MDProcessCmdLine Class Documentation
====================================

.. class:: MDProcessCmdLine : ProcessCmdLine

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

.. function:: MDProcessCmdLine::MDProcessCmdLine()

   The default constructor.

.. function:: MDProcessCmdLine::MDProcessCmdLine( const MDProcessCmdLine &other )

    The copy constructor.

.. function:: MDProcessCmdLine::MDProcessCmdLine(MDProcessCmdLine && other) 

    The copy-move constructor.

.. function:: MDProcessCmdLine::~MDProcessCmdLine()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDProcessCmdLine& MDProcessCmdLine::operator=( MDProcessCmdLine const & other)

    The assignment operator.

.. function:: MDProcessCmdLine& MDProcessCmdLine::operator=( MDProcessCmdLine && other)

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

.. function:: void MDProcessCmdLine::Execute_(Simulation * const a_simulation) const 

    This function provides an implementation for processing the command line
    arguments for the AnansiMolecularDynamics simulation object. A visitor 
    design pattern is used to acomplish this task.

    :param a_simulation: A pointer to a simulation object.

    :rtype void:

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
