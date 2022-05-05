.. _MDInitSimEnv source target:

.. default-domain:: cpp

.. namespace:: ANANSI

##########################
MDInitSimEnv Documentation
##########################

The base class for the molecular dynamics factory classes. This
class is an abstract base class. 

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "InitSimEnv.h"

==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <utility>

**External Library Files**

**Project Include Files**

* #include "MDInitSimEnvVisitor.h"
* #include "MDInitSimEnv.h"

===============================
MDInitSimEnv.h Global Variables
===============================

================================
MDInitSimEnv Class Documentation
================================

.. class:: MDInitSimEnv

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: MDInitSimEnv::MDInitSimEnv()

       The default constructor.

    .. function:: MDInitSimEnv::MDInitSimEnv( const MDInitSimEnv &other )

        The copy constructor.

    .. function:: MDInitSimEnv::MDInitSimEnv(MDInitSimEnv && other) 

        The copy-move constructor.

    .. function:: MDInitSimEnv::~MDInitSimEnv()

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: MDInitSimEnv& MDInitSimEnv::operator=( MDInitSimEnv const & other)

        The assignment operator.

    .. function:: MDInitSimEnv& MDInitSimEnv::operator=( MDInitSimEnv && other)

        The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

-----------------
Protected Members
-----------------

    No protected members

^^^^^^^^^
Lifecycle
^^^^^^^^^

^^^^^^^^^
Accessors
^^^^^^^^^
    .. function:: void MDInitSimEnv::Execute_(Simulation * const a_simulation) const final
    
        The resposibility of the function is to initialize the simulation runtime
        environment for the object "a_simulation". The current implementation
        uses the visitor class MDInitSimEnvVisitor to accomplish this task.

        :param a_simulation: A simulation object.

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
