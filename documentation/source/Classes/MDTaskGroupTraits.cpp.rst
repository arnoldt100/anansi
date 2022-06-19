.. _MDTaskGroupTraits class target:

.. default-domain:: cpp

.. namespace:: ANANSI

###############################
MDTaskGroupTraits Documentation
###############################

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

* MDTaskGroupTraits.h

====================================
MDTaskGroupTraits.h Global Variables
====================================

=====================================
MDTaskGroupTraits Class Documentation
=====================================

.. class:: MDTaskGroupTraits final

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: MDTaskGroupTraits::MDTaskGroupTraits()

   The default constructor.

.. function:: MDTaskGroupTraits::MDTaskGroupTraits( const MDTaskGroupTraits &other )

    The copy constructor.

.. function:: MDTaskGroupTraits::MDTaskGroupTraits(MDTaskGroupTraits && other) 

    The copy-move constructor.

.. function:: MDTaskGroupTraits::~MDTaskGroupTraits()

    The destructor.


^^^^^^
Static
^^^^^^

    .. type:: ConcreteTypes = MPL::mpl_typelist<DefaultTaskGroup>

        This typdef aliases a typelist which stores the concrete types
        that are derived from TaskGroup.

    .. type:: AbstractProduct = ANANSI::TaskGroup

        This typedef alaises the base class of the derived TaskGroups.

    .. type:: IDType = int

        This typedef aliases the the ID type for registering an object with the TaskGroup
        generic object factory.

    .. member:: static const int MAX_TASKGROUPFACTORY_INSTANCES = 1

        The maximum number of instances of the MDTaskGroupFactory that can simultaneously
        exist. We specify 1 due to requiring that we register the derived TaskGroups only
        once.


^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDTaskGroupTraits& MDTaskGroupTraits::operator=( MDTaskGroupTraits const & other)

    The assignment operator.

.. function:: MDTaskGroupTraits& MDTaskGroupTraits::operator=( MDTaskGroupTraits && other)

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
