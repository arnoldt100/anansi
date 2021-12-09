.. _ISEStatus source target:

.. default-domain:: cpp

.. namespace:: ANANSI

#######################
ISEStatus Documentation
#######################

This class encapsulates the status of Initialization the Simulation Environment.

======================
Interface Header Files
======================

**C++ Include Files**

* No files

**External Library Files**

* #include "TaskStatus.h"

**Project Include Files**

* No files


==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <utility>

**External Library Files**

* No files

**Project Include Files**

* #include "ISEStatus.h"

============================
ISEStatus.h Global Variables
============================

=============================
ISEStatus Class Documentation
=============================

.. class:: ISEStatus final : public TaskStatus

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: ISEStatus()

       The default constructor.

    .. function:: ISEStatus( const ISEStatus &other )

        The copy constructor.

    .. function:: ISEStatus(ISEStatus && other) 

        The copy-move constructor.

    .. function:: ~ISEStatus()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: ISEStatus& operator=( ISEStatus const & other)

        The assignment operator.

    .. function:: ISEStatus& operator=( ISEStatus && other)

        The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

-----------------
Protected Members
-----------------

    No protected members

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
