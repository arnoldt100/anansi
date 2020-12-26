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

.. function:: CommandLineArguments::CommandLineArguments()

   The default constructor.

.. function:: CommandLineArguments::CommandLineArguments( int const argc, char const * const * const & argv)
    
    The preferred constructor.

    :param int const argc: The size of the array char* argv[].
    :param char const * const * const & argv: Contains the command line options.
    
.. function:: CommandLineArguments::CommandLineArguments( const CommandLineArguments &other )

    The copy constructor.
    
    :param CommandLineArguments other: The other object to be copied.

.. function:: CommandLineArguments::~CommandLineArguments()

    The destructor.

---------
Accessors
---------

---------
Operators
---------

.. function:: CommandLineArguments& CommandLineArguments::operator=( CommandLineArguments const &other )

    The assignment operator.

    :param CommandLineArguments const & other: The other object to be copied.
    :return: Returns a copy of other.
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
