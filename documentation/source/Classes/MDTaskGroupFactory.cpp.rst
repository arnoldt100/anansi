.. _MDTaskGroupFactory class target:

.. default-domain:: cpp

.. namespace:: ANANSI

################################
MDTaskGroupFactory Documentation
################################

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

* #include <string>
* #include <map>

**External Library Files**

**Project Include Files**

* #include "MDTaskGroupTraits.h"
* #include "ClassInstanceLimiter.hpp"
* #include "TaskGroup.h"
* #include "DefaultTaskGroup.h"
* #include "Factory.hpp"
* #include "MPLAliases.hpp"
* #include "RegisterObjectFactories.hpp"

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "MDTaskGroupFactory.h"

=======================================
MDTaskGroupFactory.h Global Definitions
=======================================

======================================
MDTaskGroupFactory Class Documentation
======================================

.. class:: template <class Traits=MDTaskGroupTraits> \
           MDTaskGroupFactory final : private COUNTERCLASSES::ClassInstanceLimiter<MDTaskGroupFactory<Traits>,Traits::MAX_TASKGROUPFACTORY_INSTANCES>

    :tparam Traits: The traits of the concrete TaskGroups.

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: MDTaskGroupFactory::MDTaskGroupFactory()

   The default constructor.

.. function:: MDTaskGroupFactory::MDTaskGroupFactory( const MDTaskGroupFactory &other ) = delete

    The copy constructor.

.. function:: MDTaskGroupFactory::MDTaskGroupFactory(MDTaskGroupFactory && other) = delete

    The copy-move constructor.

.. function:: MDTaskGroupFactory::~MDTaskGroupFactory()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^
.. function:: std::unique_ptr<typename Traits::BaseClassType> buildWorldTaskGroup() const

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDTaskGroupFactory& MDTaskGroupFactory::operator=( MDTaskGroupFactory const & other) = delete

    The assignment operator.

.. function:: MDTaskGroupFactory& MDTaskGroupFactory::operator=( MDTaskGroupFactory && other) = delete

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
