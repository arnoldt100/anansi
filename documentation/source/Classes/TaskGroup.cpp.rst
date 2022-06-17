.. _TaskGroup class target:

.. default-domain:: cpp

.. namespace:: ANANSI

#######################
TaskGroup Documentation
#######################


This class provides the interface for the classes that perform various tasks
to accomplish the simulation.


======================
Interface Header Files
======================

**C++ Include Files**

* #include <memory>

**External Library Files**

**Project Include Files**

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "TaskGroup.h"

============================
TaskGroup.h Global Variables
============================

=============================
TaskGroup Class Documentation
=============================

.. class:: TaskGroup

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: TaskGroup::TaskGroup()

   The default constructor.

.. function:: TaskGroup::TaskGroup( const TaskGroup &other ) = delete

    The copy constructor.

.. function:: TaskGroup::TaskGroup(TaskGroup && other) 

    The copy-move constructor.

.. function:: virtual TaskGroup::~TaskGroup()=0

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: TaskGroup& TaskGroup::operator=( TaskGroup const & other) = delete

    The assignment operator.

.. function:: TaskGroup& TaskGroup::operator=( TaskGroup && other)

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
