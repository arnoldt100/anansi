/*
 * =====================================================================================
 *
 *       Filename:  Array2d.hpp
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef  Array2d_INC
#define  Array2d_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <new>
#include <iostream>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Array1d.hpp"
#include "MemoryExceptionDeletingNullPointer.hpp"
#include "AllocatingArrayDimensionToNonPositiveSize.hpp"

namespace MEMORY_MANAGEMENT
{

/*
 * =====================================================================================
 *        Class:  Array2d
 *  Description:  
 * =====================================================================================
 */
template<typename T>
class Array2d
{
    public:
        /* ====================  LIFECYCLE     ======================================= */
        Array2d() /* constructor */
        {
            return;
        };

        Array2d( const Array2d &other )=delete;   /* copy constructor */

        ~Array2d() /* destructor       */
        {
            return;
        };

        /* ====================  ACCESSORS     ======================================= */


        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array2d
         *      Method:  Array2d :: computeRowMajorIndex
         * Description: For a row major matrix, computes the displacement of the matrix element
         *              at row_index and column_index location.
         *
         * Return: std::size_t 
         *
         * Arguments: matrix_row_size; type std::size_t, The size of the matrix row.
         *          : matrix_column_size; type std::size_t, The size of the matirix column
         *          : row_index; type std::size_t, The row index of the pertitnent element. 
         *          : column_index; type std::size_t, The column index of the pertitnent element. 
         *
         *--------------------------------------------------------------------------------------
         */
        std::size_t computeRowMajorIndex(std::size_t const & matrix_row_size,
                                         std::size_t const & matrix_column_size,
                                         std::size_t const row_index,
                                         std::size_t const column_index) const
        {
            std::size_t const displacement = matrix_column_size*row_index + column_index;
            return displacement;
        } /* end of computeRowMajorIndex */

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array2d
         *      Method:  Array2d :: computeColumnMajorIndex
         * Description: For a column major matrix, computes the displacement of the matrix element
         *              at row_index and column_index location.
         *
         * Return: std::size_t 
         *
         * Arguments: matrix_row_size; type std::size_t, The size of the matrix row.
         *          : matrix_column_size; type std::size_t, The size of the matirix column
         *          : row_index; type std::size_t, The row index of the pertitnent element. 
         *          : column_index; type std::size_t, The column index of the pertitnent element. 
         *
         *--------------------------------------------------------------------------------------
         */
        std::size_t computeColumnMajorIndex(std::size_t const & matrix_row_size,
                                            std::size_t const & matrix_column_size,
                                            std::size_t const row_index,
                                            std::size_t const column_index) const
        {
            std::size_t const displacemenet = matrix_row_size*column_index + row_index;
            return displacemenet;
        } /*  end of computeColumnMajorIndex */


        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array2d
         *      Method:  Array2d :: createRowMajorPointerArray
         * Description:  Create a 2D array in row major layout.
         *
         * Return: T**
         *
         * Arguments: matrix_row_size; type std::size_t; The size of the matrix row.
         *          : matrix_column_size; type std::size_t; The size of the matrix column.
         *
         *--------------------------------------------------------------------------------------
         */
        T** createRowMajorPointerArray( std::size_t const & matrix_row_size,
                                        std::size_t const & matrix_column_size) const;

        /*--------------------------------------------------------------------------------------
         *       Class:  Array2d
         *      Method:  Array2d :: createColumnMajorPointerArray
         * Description:  Create a 2D array in column major layout.
         *
         * Return: T**
         *
         * Arguments: matrix_row_size; type std::size_t; The size of the matrix row.
         *          : matrix_column_size; type std::size_t; The size of the matrix column.
         *
         *--------------------------------------------------------------------------------------
         */
        T** createColumnMajorPointerArray( std::size_t const & matrix_row_size,
                                           std::size_t const & matrix_column_size) const;

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array2d<T>
         *      Method:  Array2d<T> :: copyColumnMajorArray
         * Description:  Copies a column major 2d array and returns the copy.
         *
         * Return: T**
         *
         * Arguments: number_rows; type std::size_t; The number of rows of the array.
         *          : number_columns; type std::size_t; The number of columns of the array.
         *          : in_ptr; type T**; The array to be copied.
         *
         *--------------------------------------------------------------------------------------
         */
         T** copyColumnMajorArray(std::size_t const & number_rows,
                                  std::size_t const & number_columns,
                                  T const * const * const & in_ptr) const;

        /*--------------------------------------------------------------------------------------
         *       Class:  Array2d<T>
         *      Method:  Array2d<T> :: copyRowMajorArray
         * Description:  Copies a row major 2d array and returns the copy.
         *
         * Return: T**
         *
         * Arguments: number_rows; type std::size_t; The number of rows of the array.
         *          : number_columns; type std::size_t; The number of columns of the array.
         *          : in_ptr; type T**; The array to be copied.
         *
         *--------------------------------------------------------------------------------------
         */
        T**  copyRowMajorArray(std::size_t const & number_rows,
                               std::size_t const & number_columns,
                               T const * const * const & in_ptr) const;

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array2d
         *      Method:  Array2d :: copyColumnMajorArrayTo1dArray
         * Description:  Copies a column major array to a flat 1d array.
         *
         * Return: T*
         *
         * Arguments: number_rows; type std::size_t; The number of rows of the array.
         *          : number_columns; type std::size_t; The number of columns of the array.
         *          : in_ptr; type T**; The array to be copied.
         *
         *--------------------------------------------------------------------------------------
         */
        T* copyColumnMajorArrayTo1dArray (std::size_t const & number_rows,
                                          std::size_t const & number_columns,
                                          T const * const * const & in_ptr) const;


        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array2d<T>
         *      Method:  Array2d<T> :: copyRowMajorArrayTo1dArray
         * Description:  Copies a row major array to a flat 1d array.
         *
         * Return: T*
         *
         * Arguments: number_rows; type std::size_t; The number of rows of the array.
         *          : number_columns; type std::size_t; The number of columns of the array.
         *          : in_ptr; type T**; The array to be copied.
         *
         *--------------------------------------------------------------------------------------
         */
        T* copyRowMajorArrayTo1dArray (std::size_t const & number_rows,
                                       std::size_t const & number_columns,
                                       T const * const * const & in_ptr) const;

        /*--------------------------------------------------------------------------------------
         *       Class:  Array2d
         *      Method:  Array2d :: destroyRowMajorArray
         * Description:  Deallocates memory allocated for 2d row major array.
         *
         * Return: void
         *
         * Arguments: number_rows; std::size_t; The number of rows of the 2d matrix.
         *          : number_columns; std::size_t; The number of columns of the 2d matrix.
         *--------------------------------------------------------------------------------------
         */
        void destroyRowMajorArray (std::size_t const & number_rows,
                                   std::size_t const & number_columns,
                                   T** & in_ptr) const;

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array2d
         *      Method:  Array2d :: destroyColumnMajorArray
         * Description:  Deallocates memory allocated for 2d column major array.
         *
         * Return: void
         *
         * Arguments: number_rows; std::size_t; The number of rows of the 2d matrix.
         *          : number_columns; std::size_t; The number of columns of the 2d matrix.
         *--------------------------------------------------------------------------------------
         */
        void destroyColumnMajorArray (std::size_t const & number_rows,
                                      std::size_t const & number_columns,
                                      T** & in_ptr) const;

         /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        Array2d& operator=( const Array2d &other )=delete; /* assignment operator */

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class Array2d  ----- */


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================
template<typename T>
T** Array2d<T>::createRowMajorPointerArray( std::size_t const & matrix_row_size,
                                            std::size_t const & matrix_column_size) const
{
    const Array1d<T> array_factory_1d;
    const Array1d<T*> array_of_pointers_factory_1d;

    T** a_ptr=nullptr;

    try
    {
        // Check if the array dimensions are positive.
        if (matrix_row_size <= 0)
        {
            std::string error_message("Error in function Array2d<T>::createRowMajorPointerArray");
            throw MEMORY_MANAGEMENT::AllocatingArrayDimensionToNonPositiveSize<T>(error_message);
        }

        if (matrix_column_size <= 0)
        {
            std::string error_message("Error in function Array2d<T>::createRowMajorPointerArray");
            throw MEMORY_MANAGEMENT::AllocatingArrayDimensionToNonPositiveSize<T>(error_message);
        }

        // Allocate an array of type T* with dim1 number of elements.
        a_ptr = array_of_pointers_factory_1d.createArray(matrix_row_size);

        // Allocate an array of type T with dim1*dim2 number of elements
        // to contain the, and let a_ptr[0] point to the starting
        // address of that memory.
        const std::size_t number_elements = matrix_row_size*matrix_column_size;
        a_ptr[0] = array_factory_1d.createArray(number_elements);


        // We now let the array of T* pointers point to the
        // correct memory locations of the a_ptr[0] array. In other
        // words, we do the pointer array indexing math for the
        // client of the T** 2d array.
        for (std::size_t ip=0; ip < matrix_row_size; ++ip)
        {
            a_ptr[ip]= &(a_ptr[0][ip*matrix_column_size]);
        }
    }
    catch(MEMORY_MANAGEMENT::AllocatingArrayDimensionToNonPositiveSize<T>const & exception_object)
    {
        std::cout << exception_object.what() << std::endl;
        std::abort();
    }

    return a_ptr;

} /* -----  end of method Array2d<T>::createRowMajorPointerArray  ----- */

template < typename T >
T** Array2d<T>::createColumnMajorPointerArray ( std::size_t const & matrix_row_size,
                                                std::size_t const & matrix_column_size ) const
{
    const Array1d<T*> array_of_pointers_factory_1d;
    const Array1d<T> array_factory_1d;

    T** a_ptr=nullptr;
    try
    {
        // Check if the array dimensions are positive.
        if (matrix_row_size <= 0)
        {
            std::string error_message("Error in function Array2d<T>::createColumnMajorPointerArray");
            throw MEMORY_MANAGEMENT::AllocatingArrayDimensionToNonPositiveSize<T>(error_message);
        }

        if (matrix_column_size <= 0)
        {
            std::string error_message("Error in function Array2d<T>::createColumnMajorPointerArray");
            throw MEMORY_MANAGEMENT::AllocatingArrayDimensionToNonPositiveSize<T>(error_message);
        }

        // Allocate an array of type T* with dim1 number of elements.
        a_ptr = array_of_pointers_factory_1d.createArray(matrix_column_size);
        
        // Allocate an array of type T with dim1*dim2 number of elements
        // to contain the, and let a_ptr[0] point to the starting
        // address of that memory.
        const std::size_t number_elements = matrix_row_size*matrix_column_size;
        a_ptr[0] = array_factory_1d.createArray(number_elements);

        // We now let the array of T* pointers point to the
        // correct memory locations of the a_ptr[0] array. In other
        // words, we do the pointer array indexing math for the
        // client of the T** 2d array.
        for (std::size_t ip=0; ip < matrix_column_size; ++ip)
        {
            a_ptr[ip]= &(a_ptr[0][ip*matrix_row_size]);
        }

    }
    catch(MEMORY_MANAGEMENT::AllocatingArrayDimensionToNonPositiveSize<T> const & exception_object)
    {
        std::cout << exception_object.what() << std::endl;
        std::abort();
    }
    return a_ptr;
} /* -----  end of method Array2d<T>::createColumnMajorPointerArray  ----- */



template < typename T >
T** Array2d<T>::copyColumnMajorArray (std::size_t const & number_rows,
                                      std::size_t const & number_columns,
                                      T const * const * const & in_ptr) const
{
    T** out_ptr = this->createColumnMajorPointerArray(number_rows,
                                                      number_columns);
   
    // Get the address of the initial elements for in_ptr and out_ptr.
    T const * const in_initial_address = &(in_ptr[0][0]);
    T * const out_initial_address = &(out_ptr[0][0]);
    
    // The variable "disp" counts the displacment from the [0][0]
    // elements of arrays in_ptr and out_ptr.
    std::size_t disp=0; 

    // We loop over the elements in matrix in_ptr and
    // assign to out_ptr. Note the inner loop is over
    // the rows due to the column major layout.
    for(std::size_t jp=0; jp < number_columns; ++jp)
    {
         for (std::size_t ip=0; ip < number_rows; ++ip)
         {
            *(out_initial_address + disp) = *(in_initial_address + disp);
            ++disp;
         }
    }
    
    return out_ptr;
} /* -----  end of method Array2d<T>::copyColumnMajorArray  ----- */


template < typename T >
T**  Array2d<T>::copyRowMajorArray (std::size_t const & number_rows,
                                    std::size_t const & number_columns,
                                    T const * const * const & in_ptr) const
{
    T** out_ptr = this->createRowMajorPointerArray(number_rows,
                                                   number_columns);
   
    // Get the address of the initial elements for in_ptr and out_ptr.
    T const * const in_initial_address = &(in_ptr[0][0]);
    T * const out_initial_address = &(out_ptr[0][0]);
    
    // The variable "disp" counts the displacment from the [0][0]
    // elements of arrays in_ptr and out_ptr.
    std::size_t disp=0; 

    // We loop over the elements in matrix in_ptr and
    // assign to out_ptr. Note the inner loop is over
    // the columns due to the row major layout.
    for (std::size_t ip=0; ip < number_rows; ++ip)
    {
        for(std::size_t jp=0; jp < number_columns; ++jp)
         {
            *(out_initial_address + disp) = *(in_initial_address + disp);
            ++disp;
         }
    }
    
    return out_ptr;
} /* -----  end of method Array2d<T>::copyRowMajorArray  ----- */



template < typename T >
T* Array2d<T>::copyColumnMajorArrayTo1dArray (std::size_t const & number_rows,
                                              std::size_t const & number_columns,
                                              T const * const * const & in_ptr) const
{
    // Compute the number of elements in matrix "in_ptr" and
    // create a flat 1d array with the same number of elements.
    const std::size_t number_elements = number_rows*number_columns;
    const Array1d<T> array_factory_1d;
    T* out_ptr = array_factory_1d.createArray(number_elements);

    // Get the address of the initial elements for  matrices
    // "in_ptr" and "out_ptr".
    T const * const in_initial_address = &(in_ptr[0][0]);
    T * const out_initial_address = &(out_ptr[0]);

    // The variable "disp" counts the displacment from the [0][0]
    // element of array in_ptr and the [0] element of out_ptr.
    std::size_t disp = 0;

    // We loop over the elements in matrix in_ptr and
    // assign to out_ptr. Note the inner loop is over
    // the rows due to the column major layout.
    for(std::size_t jp=0; jp < number_columns; ++jp)
    {
        for(std::size_t ip=0; ip < number_rows; ++ip)
        {
            *(out_initial_address + disp) = *(in_initial_address + disp);
            ++disp;
        }
    }
    return out_ptr;
} /* -----  end of method Array2d<T>::copyColumnMajorArrayTo1dArray  ----- */


template < typename T >
T* Array2d<T>::copyRowMajorArrayTo1dArray (std::size_t const & number_rows,
                                           std::size_t const & number_columns,
                                           T const * const * const & in_ptr) const
{
    // Compute the number of elements in matrix "in_ptr" and
    // create a flat 1d array with the same number of elements.
    const std::size_t number_elements = number_rows*number_columns;
    const Array1d<T> array_factory_1d;
    T* out_ptr = array_factory_1d.createArray(number_elements);

    // Get the address of the initial elements for  matrices
    // "in_ptr" and "out_ptr".
    T const * const in_initial_address = &(in_ptr[0][0]);
    T * const out_initial_address = &(out_ptr[0]);

    // The variable "disp" counts the displacment from the [0][0]
    // element of array in_ptr and the [0] element of out_ptr.
    std::size_t disp = 0;

    // We loop over the elements in matrix in_ptr and
    // assign to out_ptr. Note the inner loop is over
    // the columns due to the row major layout.
    for(std::size_t ip=0; ip < number_rows; ++ip)
    {
        for(std::size_t jp=0; jp < number_columns; ++jp)
        {
            *(out_ptr + disp) = *(in_ptr + disp);
            ++disp;
        }
    }
    return out_ptr;
} /* -----  end of method Array2d<T>::copyRowMajorArrayTo1dArray  ----- */


template < typename T >
void Array2d<T>::destroyColumnMajorArray (std::size_t const & number_rows,
                                          std::size_t const & number_columns,
                                          T** & in_ptr) const
{
    const Array1d<T> array_factory_1d;
    array_factory_1d.destroyArray(in_ptr[0]);

    const Array1d<T*> array_of_pointers_factory_1d;
    array_of_pointers_factory_1d.destroyArray(in_ptr);

    return;
} /* -----  end of method Array2d<T>::destroyColumnMajorArray  ----- */


template < typename T >
void Array2d<T>::destroyRowMajorArray (std::size_t const & number_rows,
                                       std::size_t const & number_columns,
                                       T** & in_ptr) const
{
    const Array1d<T> array_factory_1d;
    array_factory_1d.destroyArray(in_ptr[0]);

    const Array1d<T*> array_of_pointers_factory_1d;
    array_of_pointers_factory_1d.destroyArray(in_ptr);

    return;
} /* -----  end of method Array2d<T>::destroyRowMajorArray  ----- */

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



} /* -----  end of namespace MEMORY_MANAGEMENT  ----- */





#endif   /* ----- #ifndef Array2d_INC  ----- */
