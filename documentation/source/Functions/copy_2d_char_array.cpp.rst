.. _copy_2d_char_array function target:

.. default-domain:: cpp

.. namespace:: STRING_UTILITIES

################################
copy_2d_char_array Documentation
################################

This function copies a 2d char const * const * array
to a 2d char * * array.

======================
Interface Header Files
======================

**C++ Include Files**

* #include <cstddef>


**External Library Files**


**Project Include Files**


==========================
Implementaion Header Files
==========================

**C++ Include Files**


**External Library Files**


**Project Include Files**

* #include "copy_2d_char_array.h"
* #include "Array1d.hpp"

.. =====================================
.. copy_2d_char_array.h Global Variables
.. =====================================

=========================================
copy_2d_char_array Function Documentation
=========================================

.. function:: copy_2d_char_array( std::size_t const dim1, char * const * const source_ptr, char** & destination_ptr )

    This function copies the from source to destination a 2d char array. The
    source array is source_ptr, and the destination array is destination_ptr.

    Parameter dim1 must be a positive integer.
    Parameter destination_ptr must initially be a null pointer to avoid a memory leak.  

    :param std::size_t dim1: The size of the first dimension of the 2d char array.
    :param char * const * const  source_ptr: The source 2d char array (to be copied from).
    :param char** & destination_ptr: The destination 2d char array to be copied. Upon function start, it must be a null pointer.
