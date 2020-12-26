.. default-domain:: cpp

######################################
MolecularDynamicsFactory Documentation
######################################

The base class for the molecular dynamics factory classes. This
class is an abstract base class, and this class is not assignable
or copyable.

.. namespace:: ANANSI

.. class:: MolecularDynamicsFactory

==============
Public Members
==============

----------
Life Cycle
----------

.. function:: MolecularDynamicsFactory::MolecularDynamicsFactory()

   The default constructor.

.. function:: MolecularDynamicsFactory::MolecularDynamicsFactory( const MolecularDynamicsFactory &other )=delete

    The copy constructor. The copy constructor is a deleted.

.. function:: virtual MolecularDynamicsFactory::~MolecularDynamicsFactory()=0

    The destructor. The destructor is a pure virtual destructor.

---------
Accessors
---------

.. function:: MolecularDynamics* MolecularDynamicsFactory::create() final 

    This function is final and serves as the public interface to create a
    MolecularDynamics object. It creates a MolecularDynamics class by means
    of the template design pattern.

---------
Operators
---------

.. function:: MolecularDynamicsFactory& MolecularDynamicsFactory::operator=( const MolecularDynamicsFactory &other )=delete

    The assignment operator. The function is deleted.

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

.. function:: virtual MolecularDynamics* MolecularDynamicsFactory::_create()=0

    This function is overriden by the derived class. The derived class is to 
    implement its implementation details of creating the MolecularDynamics
    object.

---------
Operators
---------

--------
Mutators
--------

------------
Data Members
------------
