.. _MPIBroadcast source target:

.. default-domain:: cpp

.. namespace:: COMMUNICATOR

##########################
MPIBroadcast Documentation
##########################

This class provides an interface to the MPI broadcast calls.

======================
Interface Header Files
======================

**C++ Include Files**

None

**External Library Files**

* #include "mpi.h"

**Project Include Files**



==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include <cstring>

**External Library Files**

None

**Project Include Files**

* #include "Array1dChar.hpp"
* #include "Array1d.hpp"
* #include "ErrorMPIBroadcast.h"
* #include "MPIBroadcast.h"

===============================
MPIBroadcast.h Global Variables
===============================

=====================================================
template<typename T> MPIBroadcast Class Documentation
=====================================================


.. class:: template<typename T> MPIBroadcast

    The  generic template class to broadcast data. This
    class is not defined.

================================================
template<> MPIBroadcast<int> Class Documentation
================================================

.. class:: template<> MPIBroadcast<int>

    The specialization to broadcast a single integer.

--------------
Public Members
--------------

^^^^^^^^^^^^^^^^
Static Functions
^^^^^^^^^^^^^^^^

    .. function:: static int MPIBroadcast::Broadcast(const int data_to_broadcast, const MPI_Comm mpi_comm, const std::size_t bcast_rank)

        Broadcasts a single integer to all other ranks in communicator *mpi_comm*.
        
        :param int data_to_broadcast: The data to be broadcasted.
        :param MPI_Comm mpi_comm: The MPI communicator handle.
        :param std::size_t bcast_rank: The rank of communicator doing the broadcasting.
        :return: The broadcasted data.
        :rtype: int
        :throw ErrorMPIBroadcast: If broadcast of int fails.

========================================================
template<> MPIBroadcast<std::string> Class Documentation
========================================================

.. class:: template<> MPIBroadcast<std::string>

    The specialization to broadcast a std::string

--------------
Public Members
--------------

^^^^^^^^^^^^^^^^
Static Functions
^^^^^^^^^^^^^^^^

    .. function:: static std::string MPIBroadcast::Broadcast(const std::string data_to_broadcast, const std::size_t bcast_str_len, const MPI_Comm mpi_comm, const std::size_t bcast_rank)

        Broadcasts a single std::string to all other ranks in communicator *mpi_comm*. The return value
        of this function is the broadcasted std::string.
        
        :param std::string data_to_broadcast: The data to be broadcasted. This variable is useful only for the brodcasting communicator rank.
        :param const std::size_t bcast_str_len: The length of the string to be broadcasted. Ths variable is useful only for the brodcasting communicator rank.
        :param MPI_Comm mpi_comm: The MPI communicator handle.
        :param std::size_t bcast_rank: The rank of communicator doing the broadcasting.
        :return: The broadcasted data.
        :rtype: std::string
        :throw ErrorMPIBroadcast: If broadcast of std::string fails.
