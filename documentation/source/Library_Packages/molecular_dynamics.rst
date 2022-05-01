##################
molecular_dynamics
##################

This following source files are use to create the library.

Header files
============

    * :ref:`anansi_main_md.h <anansi_main_md function target>`

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

The AnansiMolecularDynamics class is the subclass and is derived from interface
superclass MolecularDynamics. The MD objects are of type
AnansiMolecularDynamics. The behavior of the MD object is controlled by the
member attribute :cpp:member:`_mdState<AnansiMolecularDynamics::_mdState>`.

.. image:: ../Diagrams/AnansiMolecularDynamics.jpeg

AnansiMolecularDynamics Behaviors
---------------------------------

The AnansiMolecularDynamics object behaviors are encapsulated by state clasess as
shown in the table below:

    ================= ==============================================    
    State Classes     Behavoirs                                         
    ================= ==============================================    
    AnansiMDStateISE  Initializing the simulation environment           
    AnansiMDStatePCL  Processing the command line options               
    AnansiMDStateIIC  Initializing the initial conditions               
    AnansiMDStatePS   Performing the simulation                         
    AnansiMDStateTSE  Terminating the simulation environment            
    ================= ==============================================    


.. image:: ../Diagrams/AnansiMDStates.jpeg

AnansiMolecularDynamics Factory Class
-------------------------------------

AnansiMolecularDynamicsFactory class initiates a AnansiMolecularDynamics
object with its state set to AnansiMDStateISE.

.. image:: ../Diagrams/AnansiMolecularDynamicsFactory.jpeg

