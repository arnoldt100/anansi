.. _FileParser source target:

.. default-domain:: cpp

.. namespace:: ANANSI

########################
FileParser Documentation
########################

The base class for the parsing files. This class is an abstract base class. 

======================
Interface Header Files
======================

**C++ Include Files**

* #include <memory>
* #include <string>

**External Library Files**

No external library include files

**Project Include Files**

* #include "Communicator.h"

==========================
Implementaion Header Files
==========================

**C++ Include Files**

No C++ system include files

**External Library Files**

No external library include files

**Project Include Files**

* #include "FileParser.h"

=============================
FileParser.h Global Variables
=============================

==============================
FileParser Class Documentation
==============================

.. class:: FileParser

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: FileParser::FileParser()

       The default constructor.

    .. function:: FileParser::FileParser( const FileParser &other )

        The copy constructor.

    .. function:: FileParser::FileParser(FileParser && other) 

        The copy-move constructor.

    .. function:: FileParser::~FileParser()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: FileParser& FileParser::operator=( FileParser const & other)

        The assignment operator.

    .. function:: FileParser& FileParser::operator=( FileParser && other)

        The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

    .. function:: void FileParser::readFile()

        An interface fuction that reads the file to be be parsed.

        :returns: void

    .. function:: void FileParser::shareData()

        An interface fuction that shares the file data within the communcator ranks.

        :returns: void

    .. function:: void FileParser::setFileName( const std::string file_name)

        An interface fuction that sets the file name that is to be read.

        :param std::string file_name: The name of the file to be read.
        :returns: void
 

    .. function:: void FileParser::setCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator)

        An interface fuction that sets the communicator of the FileParser

        :param std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator: The communicator to be set in the FileParser.
        :returns: void

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

    No private members

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
