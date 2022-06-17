.. _TaskGroupTraits class target:

.. default-domain:: cpp

.. namespace:: ANANSI

#############################
TaskGroupTraits Documentation
#############################

===========
UML Diagram
===========

.. image ../Diagrams/StudClass.png

==============
Class Overview
==============

The responsibility of this class is to store the
traits of the concrete classes derived from TaskGroup.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "MPLAliases.hpp"
* #include "DefaultTaskGroup.h"


===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* TaskGroupTraits.h

==================================
TaskGroupTraits.h Global Variables
==================================

===================================
TaskGroupTraits Class Documentation
===================================

.. class:: TaskGroupTraits

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: TaskGroupTraits::TaskGroupTraits()

   The default constructor.

.. function:: TaskGroupTraits::TaskGroupTraits( const TaskGroupTraits &other )

    The copy constructor.

.. function:: TaskGroupTraits::TaskGroupTraits(TaskGroupTraits && other) 

    The copy-move constructor.

.. function:: TaskGroupTraits::~TaskGroupTraits()

    The destructor.


^^^^^^
Static
^^^^^^

    .. type:: ConcreteTypes = MPL::mpl_typelist<DefaultTaskGroup>

        This typdef aliases a typelist which stores the concrete types
        that are derived from TaskGroup.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: TaskGroupTraits& TaskGroupTraits::operator=( TaskGroupTraits const & other)

    The assignment operator.

.. function:: TaskGroupTraits& TaskGroupTraits::operator=( TaskGroupTraits && other)

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
