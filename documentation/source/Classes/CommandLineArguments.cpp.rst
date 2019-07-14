.. default-domain:: cpp

######################################
CommandLineArguments Documentation
######################################

This responsibilty of this class is to store and provide an encapusulation of the command line arguments. 

namespace COMMANDLINE

.. namespace:: COMMANDLINE

.. class:: CommandLineArguments

==============
Public Members
==============

---------
Lifecycle
---------

.. function:: CommandLineArguments()

   The default constructor.

.. function:: CommandLineArguments( const int argc, char**  & argv)
    
    The preferred constructor.

    :param argc int: The size of the array char* argv[].
    :param argv char const \*const \*const \&: Contains the command line options.
    
.. function:: CommandLineArguments( const CommandLineArguments &other )

    The copy constructor.
    
    :param CommandLineArguments other: The other object to be copied.

.. function:: ~CommandLineArguments()

    The destructor.

---------
Accessors
---------

---------
Operators
---------

.. function:: CommandLineArguments& operator=( const CommandLineArguments &other )

    The assignment operator.

    :param CommandLineArguments other: The other object to be copied.
    :return:  Returns a copy of other.
    :rtype: CommandLineArguments

--------
Mutators
--------

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
.. member:: std::size_t CommandLineArguments::_numberOfArguments

    The number of command line arguments.

.. member:: std::vector<std::string> CommandLineArguments::_commandLineArguments

    A string array of the command line arguments.
