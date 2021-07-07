.. _AnansiMDState class target:

.. default-domain:: cpp

.. namespace:: ANANSI

###########################
AnansiMDState Documentation
###########################

This is the State class for the AnansiMolecularDynamics. We are using the
State design pattern to implement different behaviors of AnansiMolecularDynamics.

AnansiMolecularDynamics has 5 states or behaviors:

* InitializingSimulationEnvironment

    This state controls initialzing various execution environments such as MPI,
    GPU accelerators, etc.

* ProcessingCommandLine

    This states controls processing the command line options. This state can't
    be performed unless the InitializingSimulationEnvironment is successfully
    completed.
    
* InitializingInitialCondition

    This state controls initialization of the simulation - reading various
    input files, setting up various MPI communicators, initializing the
    starting configurations, etc.  Essentially, this state gets the simulation
    to its initial starting configuration.  This state can't be performed
    unless the ProcessingCommandLine is successfully completed. 

* PerformingSimulation

    This state does the actual MD simulation. This state can't be performed
    unless the InitializingSimulationEnvironment is successfully completed.

* TerminatingSimulationEnvironmnet

    This state terminates the various execution environments such as MPI,
    GPU accelerators, etc.

====================
Include Header Files
====================

**C++ Include Files**

* #include <utility>
* #include <iostream>

**External Library Files**

**Project Include Files**
* #include "RegistryAnansiMDStatus.h"

================================
AnansiMDState.h Global Variables
================================

=================================
AnansiMDState Class Documentation
=================================

.. class:: AnansiMDState

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: AnansiMDState::AnansiMDState()

       The default constructor.

    .. function:: AnansiMDState::AnansiMDState( const AnansiMDState &other )

        The copy constructor.

        :param const AnansiMDState &other: The other MD state to copy construct from.

    .. function:: AnansiMDState::AnansiMDState(AnansiMDState && other) 

        The copy-move constructor.

        :param const AnansiMDState &other: The other MD state to copy-move construct from.

    .. function:: virtual AnansiMDState::~AnansiMDState()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    .. function:: void AnansiMDState::initializeSimulationEnvironment(MolecularDynamics * const aMD, int const & argc, char const * const * const & argv ) const

        Implements the interface for intializing the simulation environment.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 
                                              This MD object is to have its simulation environment
                                              initialized.

        :param int const & argc: The number of command line arguments.
        :param char const * const * const & argv: The command line arguments.
        :rtype: void

    .. function:: void AnansiMDState::processCommandLine(MolecularDynamics * const aMD) const

        Implements the interface for processing the command line arguments.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

    .. function:: void AnansiMDState::initializeInitialConditions(MolecularDynamics * const aMD) const 

        Implements the interface for initializing the initial condtions.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 


    .. function:: void AnansiMDState::performSimulation(MolecularDynamics * const aMD) const

        Implements the interface for performing the molecular dynamics simulation.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

    .. function:: void AnansiMDState::terminateSimulationEnvironment(MolecularDynamics * const aMD) const

        Implements the interface for terminating the simulation environment.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: AnansiMDState& AnansiMDState::operator=( AnansiMDState const & other)

        The assignment operator.

    .. function:: AnansiMDState& AnansiMDState::operator=( AnansiMDState && other)

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

.. ^^^^^^^^^
.. Lifecycle
.. ^^^^^^^^^

^^^^^^^^^
Accessors
^^^^^^^^^

    .. function:: void AnansiMDState::_initializeSimulationEnvironment(MolecularDynamics * const aMD, int const & argc, char const * const * const & argv ) const

        Implements the Non-Virtual Interface private virtual extension point
        for intializing the simulation environment.

        This function should be overriden for by all valid MD states.
        Currently only the MD state AnansiMDStateISE should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 
                                              This MD object is to have its simulation environment
                                              initialized.

        :param int const & argc: The number of command line arguments.
        :param char const * const * const & argv: The command line arguments.
        :rtype: void


    .. function:: void AnansiMDState::_processCommandLine(MolecularDynamics * const aMD) const

        Implements the Non-Virtual Interface private virtual extension point
        for processing the command line arguments.

        This function should be overriden for by all valid MD states.
        Currently only the MD state AnansiMDStatePCL should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

    .. function:: void AnansiMDState::_initializeInitialConditions(MolecularDynamics * const aMD) const 

        Implements the Non-Virtual Interface private virtual extension point
        for initializing the initial conditions.

        This function should be overriden for by all valid MD states.
        Currently only the MD state AnansiMDStateIIC should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

    .. function:: void AnansiMDState::_performSimulation(MolecularDynamics * const aMD) const

        Implements the Non-Virtual Interface private virtual extension point
        for performing the MD simulation.

        This function should be overriden for by all valid MD states.
        Currently only the MD state AnansiMDStatePS should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

    .. function:: void AnansiMDState::_terminateSimulationEnvironment(MolecularDynamics * const aMD) const

        Implements the Non-Virtual Interface private virtual extension point
        for terminating the simulation environment.

        This function should be overriden for by all valid MD states.
        Currently only the MD state AnansiMDStateTS should override this
        method.  If the function is not overriden in the derived class, the
        function simply does nothing.

        :param MolecularDynamics * const aMD: A pointer to a molecular dynamics object. 

.. 
.. ^^^^^^^^^
.. Operators
.. ^^^^^^^^^

^^^^^^^^
Mutators
^^^^^^^^


.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^
