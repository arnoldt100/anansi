/*
 * =====================================================================================
 *
 *       Filename:  Array1dChar.cpp
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#include "Array1dChar.hpp"


namespace MEMORY_MANAGEMENT {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================


Array1d<char>::Array1d() 
{
    return;
}  /* -----  end of method Array1d<char>::Array1d  (constructor)  ----- */

Array1d<char>::~Array1d ()
{
    return;
}  /* -----  end of method Array1d<char>::~Array1d  (destructor)  ----- */

//============================= ACCESSORS ====================================


char* 
Array1d<char>::createArray (std::size_t const number_characters ) const
{
    char* a_ptr=nullptr;
    try 
    {
        if (number_characters <= 0)
        {
            std::string error_message("Error in function Array2d<char>::createArray");
            throw MEMORY_MANAGEMENT::AllocatingArrayDimensionToNonPositiveSize<char>(error_message);
        }

        a_ptr = new (std::nothrow) char [number_characters];

        if (a_ptr == nullptr)
        {
            throw std::bad_alloc();
        }

        for (std::size_t ip=0; ip < number_characters -1; ++ip)
        {
            a_ptr[ip] = MEMORY_MANAGEMENT::PointerArrayInitializationTraits<char>::zero; 
        }
        a_ptr[number_characters-1] = '\0';
    }
    catch (std::bad_alloc const & my_exception)
    {
       std::cout << my_exception.what() << std::endl;
       std::abort();
    }
    catch(MEMORY_MANAGEMENT::AllocatingArrayDimensionToNonPositiveSize<char> const & my_exception)
    {
        std::cout << my_exception.what() << std::endl;
        std::abort();
    }

    return a_ptr;
}		/* -----  end of method Array1d<char><T>::createArray  ----- */


char* 
Array1d<char>::createArray(std::string const aString, 
                           std::size_t const length) const
{
    char* a_ptr=nullptr;

    try
    {
        // Verify that the length of the pointer is sufficient to hold string. 
        // We add 1 to string_length to account for the null char '\0'.
        auto string_length = aString.size();
        if ( (string_length + 1) > length  ) 
        {
            std::string message("In Array1d<char>::createArray.");
            throw MEMORY_MANAGEMENT::ExceptionLengthOfCharPointerIsTooSmall(message);
        }

        // Allocate a char array of length number of elements.
        a_ptr = new (std::nothrow) char [length]; 
        if (a_ptr == nullptr)
        {
            throw std::bad_alloc();
        }

        // Initialize the string to contain all null characters.
        for (std::size_t ip=0; ip < length; ++ip)
        {
            a_ptr[ip] = MEMORY_MANAGEMENT::PointerArrayInitializationTraits<char>::nullchar;
        }

        // Now fill the character array with the characters from the string.
        for (std::size_t ip=0; ip < string_length ; ++ip)
        {
            a_ptr[ip] = aString[ip];
        }
    }
    catch(std::bad_alloc const & my_exception)
    {
    	std::cout << my_exception.what() << std::endl;
    	std::abort();
    }
    catch (MEMORY_MANAGEMENT::ExceptionLengthOfCharPointerIsTooSmall const & my_exception)
    {
    	std::cout << my_exception.what() << std::endl;
    	std::abort();
    }

    return a_ptr;
}

void 
Array1d<char>::destroyArray( char * & a_ptr ) const
{
    try 
    {
        if (a_ptr == nullptr)
        {
            std::string error_message("Error in function Array1d<char>::destroyArray.");
            throw MEMORY_MANAGEMENT::MemoryExceptionDeletingNullPointer<char>(error_message);
        }
        delete [] a_ptr;
    }
    catch ( MEMORY_MANAGEMENT::MemoryExceptionDeletingNullPointer<char> const & ExceptObj ) 
    {
        std::cout << ExceptObj.what() << std::endl;
    }
    a_ptr=nullptr;
    return;
} /* -----  end of method destroyArray  ----- */

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


} /* end of namespace MEMORY_MANAGEMENT */
