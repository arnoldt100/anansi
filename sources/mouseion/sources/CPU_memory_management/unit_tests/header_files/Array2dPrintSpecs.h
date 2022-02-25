// =====================================================================================
//
//       Filename:  Array2dPrintSpecs.h
//
//    Description:  
//
//         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
//   Organization:  ORNL-National Center of Computational Sciences
//
// =====================================================================================



#ifndef Array2dPrintSpecs_INC
#define Array2dPrintSpecs_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "boost/format.hpp"
#include <string>
#include <iostream>
#include <fstream>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ArrayLayoutType.h"

    /*
     * =====================================================================================
     *        Class:  Array2dPrintSpecs
     *  Description:  
     * =====================================================================================
     */
class Array2dPrintSpecs
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  Array2dPrintSpecs
         *      Method:  Array2dPrintSpecs :: Array2dPrintSpecs
         * Description:  Constructor
         *
         * Arguments: layout_type; type an enum ArrayLayoutType; Indicates whether the array is 
         *            in column or row major layout.
         *          : title; type std::string; The title of the output.
         *          : row_size; type std::size_t; The number of rows.
         *          : column_size; type std::size_t; The number of columns.
         *
         *--------------------------------------------------------------------------------------
         */
        Array2dPrintSpecs (ArrayLayoutType const layout_type, 
                           std::string const title,
                           std::size_t const row_size,
                           std::size_t const column_size);/* constructor      */


        Array2dPrintSpecs ( const Array2dPrintSpecs &other );   /* copy constructor */

        ~Array2dPrintSpecs ();                            /* destructor       */

        /* ====================  ACCESSORS     ======================================= */


        //--------------------------------------------------------------------------------------
        //       Class:  Array2dPrintSpecs
        //      Method:  Array2dPrintSpecs :: printHeaders
        // Description: Prints the table headers for the erroneous array elements.
        //
        // Return: void
        //
        // Arguments: fileObj; type std::ofstream; A output file stream object that is opened for writing.
        //
        //--------------------------------------------------------------------------------------
        void printHeaders(std::ofstream & fileObj) const;


        //--------------------------------------------------------------------------------------
        //       Class:  Array2dPrintSpecs
        //      Method:  Array2dPrintSpecs :: printErrorneousElement
        // Description:  Writes the errorneous matrix element to file.
        //
        // Return: void
        //
        // Arguments: row_index; type std::size_t; The row index of the matrix.
        //            column_index; type std::size_t; The column index of the matrix.
        //            displacement; type std::size_t; The pointer displacment to the beginning 
        //                                            of the memory location.
        //            value_pma; type std::size_t; The value obtaned by pointer arithmetic.
        //            value_poa; type std::size_t; The value obtained by pointer array access.
        //
        //--------------------------------------------------------------------------------------
        void printErroneousElement(std::ofstream & fileObj,
                                   const std::size_t row_index, 
                                   const std::size_t column_index,
                                   const std::size_t displacement,
                                   const std::size_t value_pma,
                                   const std::size_t value_poa) const;

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */
        Array2dPrintSpecs& operator= ( const Array2dPrintSpecs &other ); /* assignment operator */

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  ACCESSORS     ======================================= */

        //--------------------------------------------------------------------------------------
        //       Class:  Array2dPrintSpecs
        //      Method:  Array2dPrintSpecs :: _columnSeparatorSpec
        // Description:  Returns a string with "nm_spaces" spaces.
        //
        // Return: std::string 
        //
        // Arguments: nm_spaces; type std::size_t; The number of spaces in the retuned string.
        //
        //--------------------------------------------------------------------------------------
        std::string
        _columnSeparatorSpec(std::size_t const nm_spaces) const;

        
        //--------------------------------------------------------------------------------------
        //       Class:  Array2dPrintSpecs
        //      Method:  Array2dPrintSpecs :: _headerForPOA
        // Description:  Returns the table header for the pointer array operator
        //               access value.
        //
        // Return: std::string 
        //
        // Arguments: array_layout; type enum ArrayLayoutType; 
        //
        //--------------------------------------------------------------------------------------
        std::string
        _headerForPOA( enum ArrayLayoutType const &  array_layout) const;

        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */
        ArrayLayoutType _layoutType;
        std::string _title;
        std::size_t _rowSize;
        std::size_t _columnSize;
        std::string _indicesColumnHeader;
        std::size_t _widthIndicesColumnHeader;
        std::size_t _widthDisplacement;
        std::size_t _widthColumnSeparator;
        std::size_t _widthPMA;
        std::size_t _widthPOA;
        std::string _indicesColumnHeaderSpec;
        std::string _displacementSpec;
        std::string _pmaSpec;
        std::string _poaSpec;

}; /* -----  end of class Array2dPrintSpecs  ----- */



#endif /* Array2dPrintSpecs_INC */
