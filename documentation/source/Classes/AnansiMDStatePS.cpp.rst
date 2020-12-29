.. _AnansiMDStatePS class target:

.. default-domain:: cpp

.. namespace:: ANANSI

#############################
AnansiMDStatePS Documentation
#############################

This class is the state class for the performing the simulation.  This is class
inherits from class AnansiMDState and is final.

====================
Include Header Files
====================

**C++ Include Files**
#include <utility>

**External Library Files**

**Project Include Files**

* #include "AnansiMDState.h"

==================================
AnansiMDStatePS.h Global Variables
==================================

===================================
AnansiMDStatePS Class Documentation
===================================

.. class:: AnansiMDStatePS final : public AnansiMDState

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: AnansiMDStatePS::AnansiMDStatePS()

       The default constructor.

    .. function:: AnansiMDStatePS::AnansiMDStatePS( const AnansiMDStatePS &other )

        The copy constructor.

    .. function:: AnansiMDStatePS::AnansiMDStatePS(AnansiMDStatePS && other) 

        The copy-move constructor.

    .. function:: AnansiMDStatePS::~AnansiMDStatePS()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: AnansiMDStatePS& AnansiMDStatePS::operator=( AnansiMDStatePS const & other)

        The assignment operator.

    .. function:: AnansiMDStatePS& AnansiMDStatePS::operator=( AnansiMDStatePS && other)

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
