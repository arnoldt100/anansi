.. _DefaultTaskGroup class target:

.. default-domain:: cpp

.. namespace:: ANANSI

##############################
DefaultTaskGroup Documentation
##############################

===========
UML Diagram
===========

.. image ../Diagrams/StudClass.png

==============
Class Overview
==============

Stud text for class overview

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

* #include <memory>

**External Library Files**

**Project Include Files**

* #include "DefaultTaskGroup.h"

===================================
DefaultTaskGroup.h Global Variables
===================================

====================================
DefaultTaskGroup Class Documentation
====================================

.. class:: DefaultTaskGroup final : public TaskGroup

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: DefaultTaskGroup::DefaultTaskGroup()

   The default constructor.

.. function:: DefaultTaskGroup::DefaultTaskGroup( const DefaultTaskGroup &other ) = delete

    The copy constructor.

.. function:: DefaultTaskGroup::DefaultTaskGroup(DefaultTaskGroup && other) 

    The copy-move constructor.

.. function:: DefaultTaskGroup::~DefaultTaskGroup()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: DefaultTaskGroup& DefaultTaskGroup::operator=( DefaultTaskGroup const & other) = delete

    The assignment operator.

.. function:: DefaultTaskGroup& DefaultTaskGroup::operator=( DefaultTaskGroup && other)

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
