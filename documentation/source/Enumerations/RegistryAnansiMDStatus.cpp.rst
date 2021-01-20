.. default-domain:: cpp

.. namespace:: ANANSI

####################################
RegistryAnansiMDStatus Documentation
####################################

This scoped enum enumerates the status of the Anansi MD instance.

* InitializingSimulationEnvironmentInProgess
* InitializingSimulationEnvironmentSucessful
* InitializingSimulationEnvironmentFail
* ProcessingCommandLineInProgress
* ProcessingCommandLineSuccessful
* ProcessingCommandLineFailed
* InitializingInitialConditionInProgress
* InitializingInitialConditionSuccessful
* InitializingInitialConditionFailed
* PerfomingSimulationInProgress
* PerfomingSimulationSuccessful
* PerfomingSimulationFailed
* TerminatingSimulationEnvironmentInProgress
* TerminatingSimulationEnvironmentSuccessful
* TerminatingSimulationEnvironmentFailed

==========================================
RegistryAnansiMDStates Class Documentation
==========================================


.. enum:: RegistryAnansiMDStatus : int

    A scoped enum that enumerates the states of the Anansi MD simulation.

    .. member:: int InitializingSimulationEnvironmentInProgess

        The status of initializing the simulation environment in progress.

    .. member:: int InitializingSimulationEnvironmentSucessful

        The status of initializing the simulation environment is successful.

    .. member:: int InitializingSimulationEnvironmentFail

        The status of initializing the simulation environment is unsucessful.

    .. member:: int ProcessingCommandLineInProgress

        The status of processing and saving the command line options is in progress.

    .. member:: int ProcessingCommandLineSuccessful

        The status of processing and saving the command line options is successful.

    .. member:: int ProcessingCommandLineFailed

        The status of processing and saving the command line options failed.

    .. member:: int InitializingInitialConditionInProgress

        The status of initializing the simulation initial conditions is in progress.

    .. member:: int InitializingInitialConditionSuccessful

        The status of initializing the simulation initial conditions is successful.

    .. member:: int InitializingInitialConditionFailed

        The status of initializing the simulation initial conditions failed.

    .. member:: int PerfomingSimulationInProgress

        The status of doing the simulation is in progress.

    .. member:: int PerfomingSimulationSuccessful

        The status of doing the simulation is successful.

    .. member:: int PerfomingSimulationFailed

        The status of doing the simulation is failed.

    .. member:: int terminatingSimulationEnvironmentInProgress

        The status of terminating the simulation environmnet is in progress.

    .. member:: int TerminatingSimulationEnvironmentSuccessful

        The status of terminating the simulation environment is successful.

    .. member:: int TerminatingSimulationEnvironmentFailed

        The status of terminating the simulation environmnet is failed.

