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

**External Library Files**

**Project Include Files**

* #include "TaskGroup.h"
* #include "MDTaskGroup.h"
* #include "ClassInstanceLimiter.hpp"
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

* #include "MDFactory.h"

=======================================
MDTaskGroupFactory.h Global Definitions
=======================================

.. var:: constexpr auto MAX_MDTASKGROUPFACTORY_INSTANCES = 1

    Sets the maximum number of instances of the class MDTaskGroupFactory.  We
    specify 1 due to only requiring that we register the derived TaskGroups
    only once.

.. type:: MDTaskGroupTypeList = MPL::mpl_typelist<DefaultTaskGroup>

    The list of TaskGroups that are instatantiated with the MDTaskGroupFactory.

.. type:: template <class BaseClassType,typename IDType> \
          TGObjectFactoryType = MPL::Factory<BaseClassType,IDType>

    A typedef for easing the calling of MPL::Factory class.

    :tparam BaseClassType: The type of base class of the set of derived MDs.
    :tparam IDType: The type of the class identifier for registering the derived
                    TaskGroups.

====================================
MDFactory Class Documentation
====================================

.. class:: MDTaskGroupFactory final

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: MDTaskGroupFactory::MDTaskGroupFactory()

   The default constructor.

.. function:: MDTaskGroupFactory::MDTaskGroupFactory( const MDTaskGroupFactory &other )

    The copy constructor.

.. function:: MDTaskGroupFactory::MDTaskGroupFactory(MDTaskGroupFactory && other) 

    The copy-move constructor.

.. function:: MDTaskGroupFactory::~MDTaskGroupFactory()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDTaskGroupFactory& MDTaskGroupFactory::operator=( MDTaskGroupFactory const & other)

    The assignment operator.

.. function:: MDTaskGroupFactory& MDTaskGroupFactory::operator=( MDTaskGroupFactory && other)

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
