.. default-domain:: cpp

##################################
SimulationParameters Documentation
##################################

This class encapsulates the parameters of the simulation.

.. namespace:: ANANSI

.. class:: SimulationParameters

The responsibility of SimulationParameters is to store the parameters of the simulation.
It doesn't store atom positions, velocities, etc. It stores information such as the simulation
temperature, pressure, methodology, restart file names, etc. This information will later be used 
to initialize the simulation initial conditions and perform the simulation.

The command line options are parsed and checked for correctness by using the Boost program options library.
From the command line options, the appropriate controlfile file is parsed and the simulation parameters are stored
in class SimulationParameters.

======================
Interface Header Files
======================

**C++ Include Files**

* #include <vector>
* #include <map>
* #include <string>

**External Library Files**

* #include "boost/program_options.hpp"

**Project Include Files**

* #include "OptionsParametersMap.h"
* #include "CommandLineArguments.h"

===========================
Implementation Header Files
===========================

**C++ Include Files**

* #include <iostream>
* #include <utility>
* #include <algorithm>

**External Library Files**

**Project Include Files**

* #include "SimulationParameters.h"
* #include "AllOptions.h"


=======================================
SimulationParameters.h Global Variables
=======================================

========================================
SimulationParameters Class Documentation
========================================

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: SimulationParameters::SimulationParameters()

   The default constructor.

.. function:: SimulationParameters::SimulationParameters( SimulationParameters const & other )

    The copy constructor.

    :param  other: The object to copy.

.. function:: SimulationParameters::SimulationParameters( SimulationParameters && other)

    :param other: The object to move-copy from.

.. function:: SimulationParameters::~SimulationParameters()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: bool SimulationParameters::isCommandLineOptionPresent (std::string const & key) const

    Inquires if an option, designated by key, is present on the command line. If the option is present
    then true is returned, otherwise false is returned.
    
    :param key: The string name of the option to be inquired about
    :rtype: bool

.. function:: std::string SimulationParameters::getCommandLineOptionValues(std::string const & key) const

    Returns the command line option value for the corresponding key. If the option is not found then
    the value SimulationParameters::OPTION_NOT_FOUND is returned.
    
    :param key: The string name of the option to be inquired about
    :rtype: string

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: SimulationParameters& SimulationParameters::operator=( const SimulationParameters &other )

    The assignment operator.

.. function:: SimulationParameters& SimulationParameters::operator=( SimulationParameters && other )

    The assignment move operator.

^^^^^^^^
Mutators
^^^^^^^^

^^^^^^
Static
^^^^^^

.. member:: static const std::string SimulationParameters::OPTION_NOT_FOUND

    A string flag that is used ot indicate commnd line option
    is not found. The value of this variable must be unique with respect
    to all other command line options or the program may have undefined behavior.

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

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

^^^^^^^^^
Accessors
^^^^^^^^^

^^^^^^^^^
Operators
^^^^^^^^^

^^^^^^^^^
Mutators
^^^^^^^^^

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^

^^^^^^
Static
^^^^^^

.. function:: static ANANSI::OPTIONS_PARAMETERS_MAP_t  SimulationParameters::parseProgramOptionsFromCommandLine_(COMMANDLINE::CommandLineArguments const & aCommandLine)

    Parses the program options from the command line object and stores in a
    ANANSI::OPTIONS_PARAMETERS_MAP_t object which is returned.

    :param aCommandLine: Contains the command line arguments.

    :rtype: ANANSI::OPTIONS_PARAMETERS_MAP_t

