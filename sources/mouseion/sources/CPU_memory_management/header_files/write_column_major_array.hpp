#ifndef  write_column_major_array_INC
#define  write_column_major_array_INC

// =====================================================================================
//
//       Filename:  write_column_major_array.hpp
//
//    Description:  
//
//         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
//   Organization:  ORNL-National Center of Computational Sciences
//
// =====================================================================================


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <fstream>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include <boost/format.hpp>
#include "Array1d.hpp"
#include "Array2d.hpp"


namespace MEMORY_MANAGEMENT 
{
    /*
     *--------------------------------------------------------------------------------------
     *       Class:  Array2d<T>
     *      Method:  Array2d<T> :: writeColumnMajorArray
     * Description: Writes the column major array to an output stream.
     *
     * Arguments: fileObj; type std::ofstream; The output stream the matrix is written to.
     *          : precision; type std::size_t; The number of decimal digits.
     *          : width; type std::size_t; The number of digits.
     *          : number_rows: type std::size_t; The number of rows of the matrix
     *          : number_columns; type std::size_t; The number of columns of the array.
     *          : in_ptr; type T**; The array to be written to the out stream..
     *          : matrix_name; type std::string; The name, id, etc. of the matrix.
     *
     *--------------------------------------------------------------------------------------
     */
    template < typename T >
    void writeColumnMajorArray (std::ofstream & fileObj,
                                std::size_t const precision,
                                std::size_t const width,
                                std::size_t const number_rows,
                                std::size_t const number_cols,
                                T const * const * const in_ptr,
                                std::string const & matrix_name)
    {
        // We define a lambda to write a string of spaces that will serve as a column separator.
        auto col_sep = [](std::size_t const nm_spaces)->std::string 
        {
            std::string tmp_string(nm_spaces,' '); 
            return tmp_string;
        };

        // Define the number of spaces to separate the columns
        std::size_t column_separation_width=1;

        // Define a lambda to generate the spec for the array element.
        std::string array_element_spec = "%|-" + std::to_string(width) + "i|" + col_sep(column_separation_width) + 
                                         "%|-" + std::to_string(width) + "i|" + col_sep(column_separation_width) + 
                                         "%|-" + std::to_string(width) + "." + std::to_string(precision) + "e|"; 

        auto my_format = boost::format(array_element_spec);
        fileObj << matrix_name << std::endl;
        fileObj << "Number of row: " << std::to_string(number_rows) << std::endl; 
        fileObj << "Number of columns: " << std::to_string(number_cols) << std::endl; 
        for (std::size_t ip=0; ip < number_rows; ++ip)
        {
            for (std::size_t jp=0; jp < number_cols; ++jp)
            {
                fileObj << str(my_format % ip % jp % in_ptr[jp][ip]) << std::endl;
            }
        }
        fileObj << "End of " << matrix_name << std::endl << std::endl;
        
        return;
    }		/* -----  end of function writeColumnMajorArray<T>  ----- */


}; /* namespace MEMORY_MANAGEMENT */

#endif   // ----- #ifndef write_column_major_array_INC  ----- 
