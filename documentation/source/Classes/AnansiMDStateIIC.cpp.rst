.. default-domain:: cpp

.. namespace:: ANANSI

##############################
AnansiMDStateIIC Documentation
##############################

This class is the state class for the initialization of the simulation to its
initial conditions. This is class inherits from class AnansiMDState and is
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
AnansiMDStateIIC.h Global Variables
===================================

====================================
AnansiMDStateIIC Class Documentation
====================================

.. class:: AnansiMDStateIIC final : public AnansiMDState

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: AnansiMDState::IICAnansiMDStateIIC()

       The default constructor.

    .. function:: AnansiMDState::AnansiMDStateIIC( const AnansiMDStateIIC &other )

        The copy constructor.

    .. function:: AnansiMDState::AnansiMDStateIIC(AnansiMDStateIIC && other) 

        The copy-move constructor.

    .. function:: AnansiMDState::~AnansiMDStateIIC()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: AnansiMDStateIIC& AnansiMDStateIIC::operator=( AnansiMDStateIIC const & other)

        The assignment operator.

    .. function:: AnansiMDStateIIC& AnansiMDStateIIC::operator=( AnansiMDStateIIC && other)

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
