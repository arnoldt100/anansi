.. _MDInitSimEnvVisitor source target:

.. default-domain:: cpp

.. namespace:: ANANSI

#################################
MDInitSimEnvVisitor Documentation
#################################

This is the MDInitSimEnv visitor class that visits
the AnansiMolecularDynamics class. The resposibilities
of this class is to initialize the AnansiMolecularDynamics simulation
environment by

* Enabling MPI

======================
Interface Header Files
======================

**C++ Include Files**

* #include <memory>
* #include <functional>
* #include <map>


**External Library Files**

**Project Include Files**

* #include "BaseVisitor.h"
* #include "Visitor.hpp"
* #include "AnansiMolecularDynamics.h"

==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <iostream>


**External Library Files**


**Project Include Files**

* #include "MDInitSimEnvVisitor.h"
* #include "MDInitSimEnv.h"


======================================
MDInitSimEnvVisitor.h Global Variables
======================================

=======================================
MDInitSimEnvVisitor Class Documentation
=======================================

.. class:: MDInitSimEnvVisitor : public MPL::BaseVisitor, public MPL::Visitor<AnansiMolecularDynamics>

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: MDInitSimEnvVisitor::MDInitSimEnvVisitor()

        The default constructor.

    .. function:: MDInitSimEnvVisitor::MDInitSimEnvVisitor( const MDInitSimEnvVisitor &other )

        The copy constructor.

    .. function:: MDInitSimEnvVisitor::MDInitSimEnvVisitor(MDInitSimEnvVisitor && other) 

        The copy-move constructor.

    .. function:: virtual MDInitSimEnvVisitor::~MDInitSimEnvVisitor()

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    .. function:: void MDInitSimEnvVisitor::visit(AnansiMolecularDynamics& a_sim) const

        Invoking visit will enable the simulation environment for thr AnansiMolecularDynamics object a_sim.
        This means the MPI environment will be initiated.  

        :param a_sim: A simulation object.

        :rtype: void 

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: MDInitSimEnvVisitor& operator=( MDInitSimEnvVisitor const & other)

        The assignment operator.

    .. function:: MDInitSimEnvVisitor& operator=( MDInitSimEnvVisitor && other)

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
