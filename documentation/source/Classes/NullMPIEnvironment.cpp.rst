.. _NullMPIEnvironment class target:

.. default-domain:: cpp

.. namespace:: COMMUNICATOR

################################
NullMPIEnvironment Documentation
################################

The resposibility of this class is to encapsulate the Null state
behavior of MPIEnvironment. The behavoir is as follows:

* Enabling a null MPI environment results in an enabled MPIEnvironment state, EnabledMPIEnvironment.
* Disabling a null MPI environment results in a null MPIEnvironment state, NullMPIEnvironment.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "MPIEnvironmentState.h"

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "NullMPIEnvironment.h"

=====================================
NullMPIEnvironment.h Global Variables
=====================================

======================================
NullMPIEnvironment Class Documentation
======================================

.. class:: NullMPIEnvironment

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: NullMPIEnvironment::NullMPIEnvironment()

   The default constructor.

.. function:: NullMPIEnvironment::NullMPIEnvironment( const NullMPIEnvironment &other )

    The copy constructor.

.. function:: NullMPIEnvironment::NullMPIEnvironment(NullMPIEnvironment && other) 

    The copy-move constructor.

.. function:: NullMPIEnvironment::~NullMPIEnvironment()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: NullMPIEnvironment& NullMPIEnvironment::operator=( NullMPIEnvironment const & other)

    The assignment operator.

.. function:: NullMPIEnvironment& NullMPIEnvironment::operator=( NullMPIEnvironment && other)

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

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

^^^^^^^^^
Accessors
^^^^^^^^^

^^^^^^^^^
Operators
^^^^^^^^^

^^^^^^^^^
Mutators
^^^^^^^^^

.. function:: void NullMPIEnvironment::enable_() override

    This results in enabling the MPIEnvironment and the
    MPI environment changes to the enabled state.

    :rtype: void

.. function:: void NullMPIEnvironment::disable_() override

    This does nothing and the MPI environment stays in the null state.

    :rtype: void

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^
