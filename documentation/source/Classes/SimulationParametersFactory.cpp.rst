.. default-domain:: cpp

#########################################
SimulationParametersFactory Documentation
#########################################

A factory class to build instances of SimulationParameters.

.. namespace:: ANANSI

.. class:: SimulationParametersFactory

==============
Public Members
==============

---------
Lifecycle
---------

.. function:: SimulationParametersFactory::SimulationParametersFactory()

   The default constructor.

.. function:: SimulationParametersFactory::SimulationParametersFactory( SimulationParametersFactory const & other )

    The copy constructor.
    
    :param SimulationParametersFactory const & other: The other object to be copied.

.. function:: SimulationParametersFactory::~SimulationParametersFactory()

    The destructor.

---------
Accessors
---------

---------
Operators
---------

.. function:: SimulationParametersFactory& SimulationParametersFactory::operator=( const SimulationParametersFactory &other )

    The assignment operator.

    :param SimulationParametersFactory const & other: The other object to be copied.


--------
Mutators
--------

------
Static
------

.. function:: static SimulationParameters create(COMMANDLINE::CommandLineArguments const & aCommandLine )

    Creates an instance SimulationParameters.

    :param aCommandLine const & CommandLineArguments: An object which encapsulates the command line arguments.
    
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
