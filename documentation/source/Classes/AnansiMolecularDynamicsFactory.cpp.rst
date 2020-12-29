.. _AnansiMolecularDynamicsFactory class target:

.. default-domain:: cpp

.. namespace:: Anansi

############################################
AnansiMolecularDynamicsFactory Documentation
############################################

This is the factory class for AnansiMolecularDynamics. This class
is not copyable or moveable.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "AnansiMolecularDynamics.h"
* #include "MolecularDynamicsFactory.h"

==========================
Implementaion Header Files
==========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "AnansiMolecularDynamicsFactory.h"
* #include "Pointer.hpp"

=================================================
AnansiMolecularDynamicsFactory.h Global Variables
=================================================

==================================================
AnansiMolecularDynamicsFactory Class Documentation
==================================================

    .. class:: AnansiMolecularDynamicsFactory final : MolecularDynamicsFactory

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: AnansiMolecularDynamicsFactory::AnansiMolecularDynamicsFactory()

       The default constructor.

    .. function:: AnansiMolecularDynamicsFactory::AnansiMolecularDynamicsFactory( const AnansiMolecularDynamicsFactory &other )=delete

        The copy constructor.

    .. function:: AnansiMolecularDynamicsFactory::AnansiMolecularDynamicsFactory(AnansiMolecularDynamicsFactory && other)=delete

        The copy-move constructor.

    .. function:: AnansiMolecularDynamicsFactory::~AnansiMolecularDynamicsFactory()

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: AnansiMolecularDynamicsFactory& AnansiMolecularDynamicsFactory::operator=( AnansiMolecularDynamicsFactory const & other)=delete

        The assignment operator.

    .. function:: AnansiMolecularDynamicsFactory& AnansiMolecularDynamicsFactory::operator=( AnansiMolecularDynamicsFactory && other)=delete

        The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

    No public mutators

-----------------
Protected Members
-----------------

    No public protected members

---------------
Private Members
---------------

^^^^^^^^^
Accessors
^^^^^^^^^

    .. function:: MolecularDynamics* AnansiMolecularDynamicsFactory::_create() final override

        Creates a AnansiMolecularDynamics object.

        :return: Returns a AnansiMolecularDynamics object 
        :rtype: MolecularDynamics*

