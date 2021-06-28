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
        
        * An ANANSI::MolecularDynamics object, md_ptr, is instantiated
        * md_ptr is initialized
        * md_ptr does the simulation
        * All allocated memory and resources are freed.

