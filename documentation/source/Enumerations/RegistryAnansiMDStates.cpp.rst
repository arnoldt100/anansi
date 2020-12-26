.. default-domain:: cpp

.. namespace:: ANANSI

####################################
RegistryAnansiMDStates Documentation
####################################

This scoped enum enumerates the states of the Anansi MD simulation. There are
currently 5 states :

* InitializingSimulationEnvironment
* ProcessingCommandLine
* InitializingInitialCondition
* PerfomingSimulation
* TerminatingSimulationEnvironment

==========================================
RegistryAnansiMDStates Class Documentation
==========================================


.. enum:: RegistryAnansiMDStates : int

    A scoped enum that enumerates the states of the Anansi MD simulation.

    .. member:: int initializingSimulationEnvironment

        The state of initializing the simulation environment.

    .. member:: int processingCommandLine

        The state of processing and saving the command line options.

    .. member:: int initializingInitialCondition

        The state of initializing the simulation initial conditions. 

    .. member:: int perfomingSimulation

        The state of doing the simulation.

    .. member:: int terminatingSimulationEnvironment

        The state of terminating the simulation environmnet.
