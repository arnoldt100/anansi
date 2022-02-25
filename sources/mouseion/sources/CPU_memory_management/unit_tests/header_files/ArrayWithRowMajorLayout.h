/*
 * =====================================================================================
 *
 *       Filename:  ArrayWithRowMajorLayout.h
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
 *        Class:  ArrayWithRowMajorLayout
 *  Description:  
 * =====================================================================================
 */
class ArrayWithRowMajorLayout
{
    public:
        /* ====================  LIFECYCLE     ======================================= */
        ArrayWithRowMajorLayout ();                             /* constructor      */

        ArrayWithRowMajorLayout ( const ArrayWithRowMajorLayout &other )=delete;   /* copy constructor */

        ~ArrayWithRowMajorLayout ();                            /* destructor       */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        ArrayWithRowMajorLayout& operator=( const ArrayWithRowMajorLayout &other )=delete; /* assignment operator */

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */
        std::size_t _rowSize;
        std::size_t _columnSize;
        int* _array_ptr;

}; /* -----  end of class ArrayWithRowMajorLayout  ----- */

