.. _Logger source target:

.. default-domain:: cpp

.. namespace:: ANANSI

####################
Logger Documentation
####################

The base class for the derived Logging classes. This class provides the
interface for the derived logging classes.

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

* #include "Logger.h"

=========================
Logger.h Global Variables
=========================

==========================
Logger Class Documentation
==========================

.. class:: Logger

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: Logger::Logger()

   The default constructor.

.. function:: Logger::Logger( const Logger &other )

    The copy constructor.

.. function:: Logger::Logger(Logger && other) 

    The copy-move constructor.

.. function:: virtual Logger::~Logger()=0

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: Logger& Logger::operator=( Logger const & other)

    The assignment operator.

    :rtype: Logger::Logger

.. function:: Logger& Logger::operator=( Logger && other)

    The assignment-move operator.

    :rtype: Logger::Logger

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
