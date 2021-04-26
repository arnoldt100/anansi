.. _ControlFileParser class target:

.. default-domain:: cpp

.. namespace:: ANANSI

###############################
ControlFileParser Documentation
###############################

The ControlFileParser class parses the simulation control file for its values.
The values are parsed by the master communicator and brodcasted to the
communicator ranks.

======================
Interface Header Files
======================

**C++ Include Files**

* #include <string>
* #inlcude <map>

**External Library Files**


**Project Include Files**

* #include "FileParser.h"
* #include "Communicator.h"
* #include "RegistryControlFileParserStatus.h"

==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <utility>
* #include <iostream>
* #include <exception>

**External Library Files**

* #include <boost/property_tree/ptree.hpp>
* #include <boost/property_tree/xml_parser.hpp>
* #include <boost/foreach.hpp>
* #include <boost/algorithm/string/trim.hpp>

**Project Include Files**

* #include "ControlFileParser.h"

====================================
ControlFileParser.h Global Variables
====================================

=====================================
ControlFileParser Class Documentation
=====================================

.. class:: ControlFileParser : public FileParser

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: ControlFileParser::ControlFileParser()

       The default constructor.

    .. function:: ControlFileParser::ControlFileParser( const ControlFileParser &other )=delete 

        The copy constructor is deleted.

    .. function:: ControlFileParser::ControlFileParser(ControlFileParser && other) 

        The copy-move constructor.

    .. function:: ControlFileParser::~ControlFileParser()=delete

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: ControlFileParser& operator=( ControlFileParser const & other)

        The assignment operator.

    .. function:: ControlFileParser& operator=( ControlFileParser && other)

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

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^
.. member:: std::map<std::string,std::string> ControlFileParser::_values

    Stores the values of the ControlFileParser. The values stored are the following:

        ========    ============================
        key         Description of stored value
        ========    ============================
        "units"     The units of the simulation
        ========    ============================

