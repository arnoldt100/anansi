.. _MPIEnvironmentState class target:

.. default-domain:: cpp

.. namespace:: COMMUNICATOR

#################################
MPIEnvironmentState Documentation
#################################

This abstract class is the interface for the state of the MPIEnvironment. The MPIEnvironmentState
has 3 states:

* Null - The MPIEnvironment has not been enabled.
* Enabled - The MPIEnvironment has been enabled.
* Disabled - The MPIEnvironment has been disabled.

The MPIEnvironment can only be enabled and subsequently disabled once.
Consequently, If the MPIEnvironment is in the Null state, it can be enabled.
Disabling while in the Null state does nothing. If the MPIEnvironment is in the
enabled state, re-enabling does nothing, but disabling is allowed. Once
reaching the disabled state, no re-abling is allowed.  Enabling a disabled
state will throw an error. The state changes are summarized in the following
table:

=============   =======  =========================
Initial State   Action   Final State
=============   =======  =========================
Null            enable   Enabled
Null            disable  Null
Enabled         enable   Enabled
Enabled         disable  Disabled
Disabled        enable   Disabled (Throws Error)
Disabled        disable  Disabled
=============   =======  =========================

======================
Interface Header Files
======================

**C++ Include Files**


**External Library Files**


**Project Include Files**


===========================
Implementation Header Files
===========================

**C++ Include Files**


**External Library Files**


**Project Include Files**

* #include "MPIEnvironmentState.h"

======================================
MPIEnvironmentState.h Global Variables
======================================

=======================================
MPIEnvironmentState Class Documentation
=======================================

.. class:: MPIEnvironmentState

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: MPIEnvironmentState::MPIEnvironmentState()

   The default constructor.

.. function:: MPIEnvironmentState::MPIEnvironmentState( const MPIEnvironmentState &other )

    The copy constructor.

.. function:: MPIEnvironmentState::MPIEnvironmentState(MPIEnvironmentState && other) 

    The copy-move constructor.

.. function:: MPIEnvironmentState::~MPIEnvironmentState()=0

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MPIEnvironmentState& MPIEnvironmentState::operator=( MPIEnvironmentState const & other)

    The assignment operator.

.. function:: MPIEnvironmentState& MPIEnvironmentState::operator=( MPIEnvironmentState && other)

    The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

.. function:: void MPIEnvironmentState::enable()

    The interface for enabling the MPI environment. 

    :rtype: void

.. function:: void   MPIEnvironmentState::disable()

    The interface for disabling the MPI environment.

    :rtype: void

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

.. function:: virtual void MPIEnvironmentState::enable_()

    The implementation for enabling the MPI environment. If needed, this
    function is to be overriden by the derived MPI environment states if
    needed.

    :rtype: void

.. function:: virtual void MPIEnvironmentState::disable_()

    The implementation for disabling the MPI environment.  If needed, this
    function is to be overriden by the derived MPI environment states if
    needed.

    :rtype: void

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^
