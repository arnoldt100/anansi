.. _TaskStatus source target:

.. default-domain:: cpp

.. namespace:: COMMUNICATOR

########################
TaskStatus Documentation
########################

The base class for abstraction of the status of various MD tasks. 
This class is an interface class.

======================
Interface Header Files
======================

**C++ Include Files**

* No files

**External Library Files**

* No files

**Project Include Files**

* No files

==========================
Implementaion Header Files
==========================

**C++ Include Files**

* No files

**External Library Files**

* No files

**Project Include Files**

* #include "TaskStatus.h"

=============================
TaskStatus.h Global Variables
=============================

==============================
TaskStatus Class Documentation
==============================

.. class:: TaskStatus

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: TaskStatus()

       The default constructor.

    .. function:: TaskStatus( const TaskStatus &other )

        The copy constructor.

    .. function:: TaskStatus(TaskStatus && other) 

        The copy-move constructor.

    .. function:: ~TaskStatus()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: TaskStatus& operator=( TaskStatus const & other)

        The assignment operator.

    .. function:: TaskStatus& operator=( TaskStatus && other)

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
