.. _MolecularDynamicsTypeLists class target:

.. default-domain:: cpp

.. namespace:: ANANSI

########################################
MolecularDynamicsTypeLists Documentation
########################################

The base class for the molecular dynamics factory classes. This
class is an abstract base class. 

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "MPLAliases.hpp"
* #include "AnansiMolecularDynamics.h" 

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "MolecularDynamicsTypeLists.h"

=============================================
MolecularDynamicsTypeLists.h Global Variables
=============================================

==============================================
MolecularDynamicsTypeLists Class Documentation
==============================================

.. class:: MolecularDynamicsTypeLists final

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: MolecularDynamicsTypeLists::MolecularDynamicsTypeLists()

   The default constructor.

.. function:: MolecularDynamicsTypeLists::MolecularDynamicsTypeLists( const MolecularDynamicsTypeLists &other )

    The copy constructor.

.. function:: MolecularDynamicsTypeLists::MolecularDynamicsTypeLists(MolecularDynamicsTypeLists && other) 

    The copy-move constructor.

.. function:: MolecularDynamicsTypeLists::~MolecularDynamicsTypeLists()

    The destructor.

^^^^^^^
ALIASES
^^^^^^^

.. type:: TypeList = MPL::mpl_typelist<ANANSI::AnansiMolecularDynamics>

^^^^^^^^^
Accessors
^^^^^^^^^

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MolecularDynamicsTypeLists& MolecularDynamicsTypeLists::operator=( MolecularDynamicsTypeLists const & other)

    The assignment operator.

.. function:: MolecularDynamicsTypeLists& MolecularDynamicsTypeLists::operator=( MolecularDynamicsTypeLists && other)

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
