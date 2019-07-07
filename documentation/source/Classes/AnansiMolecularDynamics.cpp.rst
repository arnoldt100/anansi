.. default-domain:: cpp

#####################################
AnansiMolecularDynamics Documentation
#####################################

This class responsibility is to perform the molecular dynanics simulation.
It a derived class whose base is ANANSI::MolecularDynamics. AnansiMolecularDynamics
is marked as final.


.. namespace:: ANANSI

.. class:: AnansiMolecularDynamics : public MolecularDynamics

==============
Public Members
==============

---------
Lifecycle
---------

.. function:: AnansiMolecularDynamics()

   The default constructor.

.. function:: AnansiMolecularDynamics( const AnansiMolecularDynamics &other )=delete

    The copy constructor. It is deleted.

.. function:: ~AnansiMolecularDynamics()=0

    The destructor.

---------
Accessors
---------

---------
Operators
---------

.. function:: AnansiMolecularDynamics& operator=(AnansiMolecularDynamics const & other) = delete
    
    The assignment operator. It is deleted.

--------
Mutators
--------

=================
Protected Members
=================

===============
Private Members
===============

---------
Accessors
---------

---------
Operators
---------

--------
Mutators
--------

.. function:: void _doSimulation() override

.. function:: void _doInitialization( int const argc, char const \*const \*const argv ) override

------------
Data Members
------------
