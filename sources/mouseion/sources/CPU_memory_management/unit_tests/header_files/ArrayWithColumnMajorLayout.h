/*
 * =====================================================================================
 *
 *       Filename:  ArrayWithColumnMajorLayout.h
 *
 *    Description: A boost fixture class to create arrays with 
 *                 column major layout.
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */



#include "Array2d.hpp"

/*
 * =====================================================================================
 *        Class:  ArrayWithColumnMajorLayout
 *  Description:  
 * =====================================================================================
 */
class ArrayWithColumnMajorLayout
{
    public:
        /* ====================  LIFECYCLE     ======================================= */
        ArrayWithColumnMajorLayout ();                             /* constructor      */

        ArrayWithColumnMajorLayout ( const ArrayWithColumnMajorLayout &other )=delete;   /* copy constructor */

        ~ArrayWithColumnMajorLayout ();                            /* destructor       */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        ArrayWithColumnMajorLayout& operator=( const ArrayWithColumnMajorLayout &other )=delete; /* assignment operator */

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */
        std::size_t _rowSize;
        std::size_t _columnSize;
        int* _array_ptr;

}; /* -----  end of class ArrayWithColumnMajorLayout  ----- */

