.. default-domain:: cpp

##################################
SimulationParameters Documentation
##################################

This class encapsulates the parameters of the simulation.

.. namespace:: ANANSI

.. class:: SimulationParameters

The responsibility of SimulationParameters is ton store the paramters of the simulation.
It doesn't store atom positions, velocities, etc. It stores information such as the simulation
temperature, pressure, methodology, restart file names, etc. This information will later be used 
to initialize the simulation initial conditions and perform the simulation.

The command line options are parsed and checked for correctness by using the Boost program options library.
From the command line options, the appropiate contolfile file is parsed and the simulation parameters are stored
in class SimulationParamters.

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

* #include "CommandLineArguments.h"
* #include "CommandLineOptions.h"

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

.. function:: SimulationParameters::~SimulationParameters()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

^^^^^^^^^
Operators
^^^^^^^^^

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

^^^^^^
Static
^^^^^^

.. function:: static SimulationParameters::_parseProgramOptionsFromCommandLine()

    Parses the program options from the command line.

