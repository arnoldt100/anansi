.. default-domain:: cpp

###############################
MolecularDynamics Documentation
###############################

The base class for the MolecularDynamics classes. This
class is an abstract base class, and it is not copyable
or assignable.

.. namespace:: ANANSI

.. class:: MolecularDynamics

==============
Public Members
==============

---------
Lifecycle
---------

.. function:: MolecularDynamics()

   The default constructor.

.. function:: MolecularDynamics( MolecularDynamics const &other ) = delete

    The copy constructor. This function is deleted.

    :param MolecularDynamics const & other: The other object to be copied.

.. function:: ~MolecularDynamics()=0

    The destructor. This is a pure virtual destructor.

---------
Accessors
---------

---------
Operators
---------

.. function:: MolecularDynamics& operator=(MolecularDynamics const & other) = delete 

    The assingment operator. This function is deleted.

--------
Mutators
--------

.. function:: void doSimulation() final

    Performs the simulation. The function is final and serves as the public
    interface of the template design pattern. The derived class is to provide 
    its implementation for performaing the simulation.

.. function:: void initializeSimulation( int const argc, char const \*const \*const & argv ) final

    Performs the simulation. The function is final and serves as the public
    interface of the template design pattern for performing the simulation. The
    derived class is to provide its implementation for initializing the simulation.

    :param int const argc: The size of the array argv.
    :param char const \*const \*const &argv: Contains the command line options.

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

------------
Data Members
------------
