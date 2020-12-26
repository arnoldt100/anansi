.. default-domain:: cpp

.. namespace:: ANANSI

##############################
AnansiMDStateISE Documentation
##############################

This class is the state class for the initialization of the simulation
execution environment.  This is class inherits from class AnansiMDState and is
final.

====================
Include Header Files
====================

**C++ Include Files**
#include <utility>

**External Library Files**

**Project Include Files**

* #include "AnansiMDState.h"

===================================
AnansiMDStateISE.h Global Variables
===================================

====================================
AnansiMDStateISE Class Documentation
====================================

.. class:: AnansiMDStateISE final : public AnansiMDState

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: AnansiMDStateISE()

       The default constructor.

    .. function:: AnansiMDStateISE( const AnansiMDStateISE &other )

        The copy constructor.

    .. function:: AnansiMDStateISE(AnansiMDStateISE && other) 

        The copy-move constructor.

    .. function:: ~AnansiMDStateISE()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: AnansiMDStateISE& AnansiMDStateISE::operator=( AnansiMDStateISE const & other)

        The assignment operator.

    .. function:: AnansiMDStateISE& AnansiMDStateISE::operator=( AnansiMDStateISE && other)

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
