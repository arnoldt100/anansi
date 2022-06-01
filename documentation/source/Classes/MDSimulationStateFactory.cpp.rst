.. _MDSimulationStateFactory class target:

.. default-domain:: cpp

.. namespace:: ANANSI

######################################
MDSimulationStateFactory Documentation
######################################

The factory for building the AnansiMolecularDynamics state objects. The key
members of this class are the private type aliases abstract_products\_ and
concrete_products\_. Each alias in abstract_products\_ must have one and only
one corresponding located derived type in concrete_products\_.  For example,
ProcessCmdLine, array index 2, is the abstract type and the derived
corresponding type is MDProcessCmdLine, array index 2.

======================
Interface Header Files
======================

**C++ Include Files**

* #include <memory>
* #include <utility>


**External Library Files**

**Project Include Files**

* #include "MDNullSimulation.h"
* #include "MDProcessCmdLine.h"
* #include "MDInitSimEnv.h"
* #include "MDInitInitialConditions.h"
* #include "MDPerformSimulation.h"
* #include "MDTerminateSimulation.h"
* #include "MPLAliases.hpp"
* #include "AbstractFactory.hpp"
* #include "ConcreteFactory.hpp"

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "MDSimulationStateFactory.h"

===========================================
MDSimulationStateFactory.h Global Variables
===========================================

============================================
MDSimulationStateFactory Class Documentation
============================================

.. class:: MDSimulationStateFactory final

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: MDSimulationStateFactory::MDSimulationStateFactory()

   The default constructor.

.. function:: MDSimulationStateFactory::MDSimulationStateFactory( const MDSimulationStateFactory &other )

    The copy constructor.

.. function:: MDSimulationStateFactory::MDSimulationStateFactory(MDSimulationStateFactory && other) 

    The copy-move constructor.

.. function:: MDSimulationStateFactory::~MDSimulationStateFactory()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: template <typename T> \
    std::unique_ptr<SimulationState> create() const

    Creates and return a unique_ptr of MDSimulationState of type T. The type T is the 

    :rtype: std::unique_ptr<SimulationState>

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MDSimulationStateFactory& MDSimulationStateFactory::operator=( MDSimulationStateFactory const & other)

    The assignment operator.

.. function:: MDSimulationStateFactory& MDSimulationStateFactory::operator=( MDSimulationStateFactory && other)

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

^^^^^^^^^^^^^
TYPE ALAIASES
^^^^^^^^^^^^^

.. type:: abstract_products_ = MPL::mpl_typelist<NullSimulation, \
                                                 InitSimEnv, \
                                                 ProcessCmdLine, \
                                                 InitInitialConditions, \
                                                 PerformSimulation, \
                                                 TerminateSimulation>

    A zero based list of abstract products.

.. type:: concrete_products_ = MPL::mpl_typelist<MDNullSimulation, \
                                                 MDInitSimEnv, \
                                                 MDProcessCmdLine, \
                                                 MDInitInitialConditions, \
                                                 MDPerformSimulation, \
                                                 MDTerminateSimulation>

    A zero based list of concrete products.

.. type:: template<std::size_t T> abstract_product_at_ = MPL::mpl_at_c<abstract_products_,T>

.. type:: abstract_factory_ = MPL::AbstractFactory<abstract_products_>

.. type:: concrete_factory_ = MPL::ConcreteFactory<abstract_factory_,concrete_products_>

.. type:: template<class Base,class Derived> my_is_base_of_ = typename MPL::mpl_bool< MPL::mpl_is_base_of<Base,Derived>::value >;

^^^^^^^^^^^^^^
Static Methods
^^^^^^^^^^^^^^

.. function:: template <typename T> static constexpr std::size_t findIndex_()

    Returns the location in the MPL::concrete_products\_ of the corresponding
    concrete product type with respect to abstract product type T. For example,
    if T is of abstract product type ProcessCmdLine, then the index 2 is
    returned for MDProcessCmdLine is the 2nd element in the concrete product
    type list.

    :rtype: std::size_t

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^

.. member:: std::unique_ptr<concrete_factory_> mdSimStateFactory_

    The concrete MDSimulationState factory.
