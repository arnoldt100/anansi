.. _ConsoleLogger source target:

.. default-domain:: cpp

.. namespace:: ANANSI

###########################
ConsoleLogger Documentation
###########################

The responsibility of this class is to write messages to the console terminal.

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

* #include "ConsoleLogger.h"

================================
ConsoleLogger.h Global Variables
================================

=================================
ConsoleLogger Class Documentation
=================================

.. class:: ConsoleLogger : public ANANSI::Logger

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: ConsoleLogger::ConsoleLogger()

   The default constructor.

.. function:: ConsoleLogger::ConsoleLogger( const ConsoleLogger &other )

    The copy constructor.

.. function:: ConsoleLogger::ConsoleLogger(ConsoleLogger && other) 

    The copy-move constructor.

.. function:: ConsoleLogger::~ConsoleLogger()=0

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: ConsoleLogger& ConsoleLogger::operator=( ConsoleLogger const & other)

    The assignment operator.

    :rtype: ConsoleLogger

.. function:: ConsoleLogger& ConsoleLogger::operator=( ConsoleLogger && other)

    The assignment-move operator.

    :rtype: ConsoleLogger

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
