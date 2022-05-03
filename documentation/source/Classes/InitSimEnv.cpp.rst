.. _InitSimEnv source target:

.. default-domain:: cpp

.. namespace:: ANANSI

########################
InitSimEnv Documentation
########################

The base class for the molecular dynamics factory classes. This
class is an abstract base class. 

======================
Interface Header Files
======================

**C++ Include Files**

* #include <dummy1>

**External Library Files**

* #include "dummy3"

**Project Include Files**

* #include "dummy5"

==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <dummy1>

**External Library Files**

* #include "dummy3"

**Project Include Files**

* #include "dummy5"

=============================
InitSimEnv.h Global Variables
=============================

=============================
InitSimEnv Class Documentation
=============================

.. class:: InitSimEnv : public SimulationState

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: InitSimEnv::InitSimEnv()

       The default constructor.

    .. function:: InitSimEnv::InitSimEnv( const InitSimEnv &other )

        The copy constructor.

    .. function:: InitSimEnv::InitSimEnv(InitSimEnv && other) 

        The copy-move constructor.

    .. function:: InitSimEnv::~InitSimEnv()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: InitSimEnv& InitSimEnv::operator=( InitSimEnv const & other)

        The assignment operator.

    .. function:: InitSimEnv& InitSimEnv::operator=( InitSimEnv && other)

        The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

-----------------
Protected Members
-----------------

^^^^^^^^^
Accessors
^^^^^^^^^
.. function:: void InitSimEnv::execute_(Simulation * const a_simulation) const override

    This methods overrides the SimulationState::execute_. 

    :param a_simulation: A simulation object

    :rtype: void

.. function:: virtual void InitSimEnv::Execute_(Simulation * const a_simulation) const

    :param a_simulation: A simulation object

    :rtype: void

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
