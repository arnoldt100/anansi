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

* #include "TaskGroupFactory.h"

=====================================
TaskGroupFactory.h Global Definitions
=====================================

.. var:: constexpr auto MAX_TASKGROUPFACTORY_INSTANCES = 1

    Sets the maximum number of instances of the class TaskGroupFactory.  We
    specify 1 due to only requiring that we register the derived TaskGroups
    only once.

.. type:: TaskGroupsTypeList = MPL::mpl_typelist<DefaultTaskGroup>

    The list of TaskGroups that are instatantiated with the TaskGroupFactory.

.. type:: template <class BaseClassType,typename IDType> \
           TGObjectFactoryType = MPL::Factory<BaseClassType,IDType>

    A typedef for easing the calling of MPL::Factory class.

    :tparam BaseClassType: The type of base class of the set of derived TaskGroups.
    :tparam IDType: The type of the class identifier for registering the derived
               TaskGroups.

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
