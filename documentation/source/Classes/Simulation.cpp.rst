.. _Simulation class target:

.. default-domain:: cpp

.. namespace:: ANANSI

########################
Simulation Documentation
########################

An abstract base class that functions as the interface for all derived
simulations, e.g. MolecularDynamics. This abstact base class is visitable all
classes in the derived hierarchy must insert DEFINE_VISITABLE to be visitable.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "DefineVisitableMacro.h"
* #include "BaseVisitable.hpp"


==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <iostream>
* #include <memory>

**External Library Files**

**Project Include Files**

* #include "Simulation.h"

=============================
Simulation.h Global Variables
=============================

==============================
Simulation Class Documentation
==============================

.. class:: Simulation : public MPL::BaseVisitable<>

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: Simulation::Simulation()

       The default constructor.

    .. function:: Simulation::Simulation( const Simulation &other ) = delete

        The copy constructor.

    .. function:: Simulation::Simulation(Simulation && other) = delete

        The copy-move constructor.

    .. function:: virtual Simulation::~Simulation()=0

        The destructor.

    ..  function:: Simulation::DEFINE_VISITABLE()

        Gives the class vistor propereties. 

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: Simulation& Simulation::operator=( Simulation const & other)

        The assignment operator.

    .. function:: Simulation& Simulation::operator=( Simulation && other)

        The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

    .. function:: void Simulation::initializeSimulationEnvironment()

        The method defines the interface for initializing the simulation
        environment. As described by template design pattern, the method
        provides the skeleton from which all derived simulation classes are to
        extend the implementation.

        :rtype: void

    .. function:: void Simulation::processCommandLine() 

        The method defines the interface for processing the command line. As
        described by template design pattern, the method provides the skeleton
        from which  all derived simulation classes are to extend the
        implementation.
    
        :rtype: void

    .. function:: void Simulation::initializeInitialConditions()

        The method defines the interface for initializing the initial
        conditions of the simulation. As described by template design pattern,
        the method provides the skeleton from which all derived simulation
        classes are to extend the implementation.
    
        :rtype: void

    .. function:: void Simulation::performSimulation()

        The method defines the interface for performing the simulation.  As
        described by template design pattern, the method provides the skeleton
        from which all derived simulation classes are to extend the
        implementation.

        :rtype: void

    .. function:: void Simulation::terminateSimulationEnvironment()
        
        The method defines the interface for termintaing the simulation. As
        described by template design pattern, the method provides the skeleton
        from which all derived simulation classes are to extend the
        implementation.

        :rtype: void


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
.. 

^^^^^^^^^
Mutators
^^^^^^^^^

The private methods below delegate customizable work to the derived classes. Please read
Herb Sutter's article on virtuality [#fsuttervirtuality]_.

    .. function:: virtual void Simulation::initializeSimulationEnvironment_()=0

        :rtype: void

    .. function:: virtual void Simulation::processCommandLine_()=0 

        :rtype: void

    .. function:: virtual void Simulation::initializeInitialConditions_()=0

        :rtype: void

    .. function:: virtual void Simulation::performSimulation_()=0

        :rtype: void

    .. function:: virtual void Simulation::terminateSimulationEnvironment_()=0

        :rtype: void

.. 
.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^


.. [#fsuttervirtuality] C/C++ Users Journal, 19(9), September 2001
