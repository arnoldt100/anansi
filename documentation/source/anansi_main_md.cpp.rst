.. _anansi_main_md function target:

.. default-domain:: cpp

#################################
Anansi Main Program Documentation
#################################

    .. function:: int main( int argc, char** argv )

        :param int argc: The number of command line arguments
        :param char** argv: An array of char*. The array size is argc.
        :return: The program's exit status.
        :rtype: int

        The main program serves as driver to run the Anansi
        molecular dynamics simulation. In brief the following tasks
        are performed:
        
        * An ANANSI::MolecularDynamics object, md_ptr, is instantiated. md_ptr 
          is a shared pointer.

        * The first task is to initialized the simulation runtime environment.
          For example, the MPI environment is initialized. Note, not all
          runtime environments need to be initialized at this juncture. The call

          ``md_ptr->initializeSimulationEnvironment()``

          initiates this task.

        * The second task is to process the command line arguments. The call

           ``md_ptr->processCommandLine()``

          initiates this task.

        * The third task is to initialize the initial conditions of the simulation. The
          call 

          ``md_ptr->initializeInitialConditions()``

          initiates this task.

        * The fourth task is to perform the simulation. The call 

          ``md_ptr->performSimulation()`` 

          initates this task.

        * The last task is to terminate the simulation. All runtime
          environments are terminated, computer resources are
          properly freed, etc. The call 

          ``md_ptr->terminateSimulationEnvironment()``

          initiates this task.

          The tasks or calls must be performed in the above order or the program may 
          enter a indeterminate state. 
