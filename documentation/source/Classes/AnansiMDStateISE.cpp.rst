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

**External Library Files**

**Interface Include Files**

**Implementation Include Files**

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "AnansiMDState.h"

==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <utility>
* #include <iostream>

**External Library Files**

**Project Include Files**

* #include "AnansiMDStateISE.h"

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

    .. function:: AnansiMDStateISE::AnansiMDStateISE()

       The default constructor.

    .. function:: AnansiMDStateISE::AnansiMDStateISE( const AnansiMDStateISE &other )

        The copy constructor.

    .. function:: AnansiMDStateISE::AnansiMDStateISE(AnansiMDStateISE && other) 

        The copy-move constructor.

    .. function:: AnansiMDStateISE::~AnansiMDStateISE()=0

        The destructor.

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: AnansiMDStateISE& AnansiMDStateISE::operator=( AnansiMDStateISE const & other)

        The assignment operator.

    .. function:: AnansiMDStateISE& AnansiMDStateISE::operator=( AnansiMDStateISE && other)

        The assignment-move operator.

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

^^^^^^^^
Mutators
^^^^^^^^

    .. function:: void AnansiMDStateISE::_initializeSimulationEnvironment() final override

        This function initializes the MD simulation environment. If
        successful, the MD state is changed to AnansiMDStateIIC.

.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^
