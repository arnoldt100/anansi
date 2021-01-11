##################
molecular_dynamics
##################

This following source files are use to create the library.

Header files
============

    * :ref:`anansi_main_md.h <anansi_main_md function target>`
    * :ref:`AnansiMDState.h <AnansiMDState class target>`
    * :ref:`AnansiMDStateIIC.h <AnansiMDStateIIC class target>`
    * :ref:`AnansiMDStateISE.h <AnansiMDStateISE class target>`
    * :ref:`AnansiMDStatePCL.h <AnansiMDStatePCL class target>`
    * :ref:`AnansiMDStatePS.h <AnansiMDStatePS class target>`
    * :ref:`AnansiMDStateTSE.h <AnansiMDStateTSE class target>`
    * :ref:`AnansiMolecularDynamics.h <AnansiMolecularDynamics class target>`
    * :ref:`AnansiMolecularDynamicsFactory.h <AnansiMolecularDynamicsFactory class target>`
    * :ref:`MolecularDynamics.h <MolecularDynamics class target>`
    * :ref:`MolecularDynamicsFactory.h <MolecularDynamicsFactory class target>`

Implementation files
====================

    * anansi_main_md.cpp 
    * AnansiMDState.cpp 
    * AnansiMDStateIIC.cpp
    * AnansiMDStateISE.cpp
    * AnansiMDStatePCL.cpp
    * AnansiMDStatePS.cpp
    * AnansiMDStateTSE.cpp
    * AnansiMolecularDynamics.cpp
    * AnansiMolecularDynamicsFactory.cpp
    * MolecularDynamics.cpp
    * MolecularDynamicsFactory.cpp

Class Relationships
===================

AnansiMolecularDynamics
-----------------------

The AnansiMolecularDynamics class is the top level class and is derived from
interface class MolecularDynamics.

.. image:: ../Diagrams/AnansiMolecularDynamics.jpeg

AnansiMolecularDynamics Behaviors
---------------------------------

The AnansiMolecularDynamics object behaviors are encapsulated by state clasess as
shown in the table below:

    ==============================================    =================
    Behavoirs                                         State Classes
    ==============================================    =================
    Initializing the simulation environment           AnansiMDStateISE
    Processing the command line options               AnansiMDStatePCL
    Initializing the initial conditions               AnansiMDStateIIC
    Performing the simulation                         AnansiMDStatePS
    Terminating the simulation environment            AnansiMDStateTSE
    ==============================================    =================


.. image:: ../Diagrams/AnansiMDStates.jpeg

AnansiMolecularDynamics Factory Class
-------------------------------------

AnansiMolecularDynamicsFactory class initiates a AnansiMolecularDynamics
object with its state set to AnansiMDStateISE.

.. image:: ../Diagrams/AnansiMolecularDynamicsFactory.jpeg

