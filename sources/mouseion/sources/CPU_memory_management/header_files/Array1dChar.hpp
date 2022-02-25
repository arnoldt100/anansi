/*
 * =====================================================================================
 *
 *       Filename:  Array1dChar.hpp
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */


#ifndef  Array1dChar_INC
#define  Array1dChar_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <new>
#include <iostream>
#include <vector>
#include <memory>
#include <string>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MemoryExceptionDeletingNullPointer.hpp"
#include "ExceptionLengthOfCharPointerIsTooSmall.h"
#include "AllocatingArrayDimensionToNonPositiveSize.hpp"
#include "Array1d.hpp"
#include "PointerInitializationTraits.hpp"


namespace MEMORY_MANAGEMENT
{

/* 
 * =====================================================================================
 *        Class:  Array1d<T>
 *  Description:  The character class template full specialization of template class Array1d<T>.
 *
 * =====================================================================================
 */

template <>
class Array1d<char>
{
    public:
        // ====================  LIFECYCLE     =======================================
        Array1d<char>(); /* constructor      */

        Array1d<char>( const Array1d<char> &other )=delete; /* copy constructor */

        ~Array1d<char> (); /* destructor       */

        /* ====================  ACCESSORS     ======================================= */
        
        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array1d<char>
         *      Method:  Array1d<char> :: createArray
         * Description: Creates a pointer array of type char with "dim1" number of elements.
         *
         * Return: Char*  
         *
         * Arguments: nm_elements; type std::size_t; The number of elements in the pointer array.
         *--------------------------------------------------------------------------------------
         */
        char* createArray( std::size_t const nm_elements) const;


        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array1d<char>
         *      Method:  Array1d<char> :: createArray
         * Description:  Creates a pointer array which contents are the characters in aString. 
         *               The array is terminated by the null character '\0' .
         *
         * Return: Char*  
         *
         * Arguments: aString: type std::string; The string to be copied.
         *            aLength: type std::size_t; the aLength of the char* array. The length
         *            must be greater than the length of string aString + 1. 
         *--------------------------------------------------------------------------------------
         */
        char* createArray(std::string const aString, 
                          std::size_t const length) const;


        /*--------------------------------------------------------------------------------------
         *       Class:  Array1d
         *      Method:  destroyArray
         * Description:  Frees the memory associated with pointer "a_ptr".
         *
         * Return:  void 
         *
         * Arguments: a_ptr; type char*; a_ptr is a pointer array of type char.
         *--------------------------------------------------------------------------------------
         */
        void destroyArray( char * & a_ptr ) const;

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        Array1d<char>& operator=( const Array1d<char> &other )=delete; // assignment operator

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */
        
        /* ====================  DATA MEMBERS  ======================================= */


}; /* -----  end of template class Array1d<T>  ----- */




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


};		/* -----  end of namespace MEMORY_MANAGEMENT  ----- */

#endif   /* ----- #ifndef Array1dChar_INC  ----- */
