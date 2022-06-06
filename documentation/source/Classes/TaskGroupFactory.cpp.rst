.. _TaskGroupFactory class target:

.. default-domain:: cpp

.. namespace:: ANANSI

##############################
TaskGroupFactory Documentation
##############################

===========
UML Diagram
===========

.. image ../Diagrams/StudClass.png

==============
Class Overview
==============

The responsibility of this class is to create the TaskGroups.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "TaskGroup.h"

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "TaskGroupFactory.h"

===================================
TaskGroupFactory.h Global Variables
===================================

====================================
TaskGroupFactory Class Documentation
====================================

.. class:: TaskGroupFactory

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: TaskGroupFactory::TaskGroupFactory()

   The default constructor.

.. function:: TaskGroupFactory::TaskGroupFactory( const TaskGroupFactory &other )

    The copy constructor.

.. function:: TaskGroupFactory::TaskGroupFactory(TaskGroupFactory && other) 

    The copy-move constructor.

.. function:: TaskGroupFactory::~TaskGroupFactory()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: TaskGroupFactory& TaskGroupFactory::operator=( TaskGroupFactory const & other)

    The assignment operator.

.. function:: TaskGroupFactory& TaskGroupFactory::operator=( TaskGroupFactory && other)

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
