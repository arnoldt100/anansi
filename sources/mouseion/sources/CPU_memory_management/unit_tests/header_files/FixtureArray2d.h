/*
 * =====================================================================================
 *
 *       Filename:  FixtureArray2d.h
 *
 *    Description:  The class is a fixture for the boost unit tests. This fixture
 *                  genreates matrices for given sizes and assigns their elements
 *                  values values based on the Cantor pairing function.
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef  FixtureArray2d_INC
#define  FixtureArray2d_INC

// System includes.
#include <functional>

// Local includes.
#include "ArrayLayoutType.h"
#include "Array2d.hpp"
#include "CantorPairing.h"


/*
 * =====================================================================================
 *        Class:  FixtureArray2d
 *  Description:  
 * =====================================================================================
 */
class FixtureArray2d
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        FixtureArray2d (std::size_t const row_size,
                        std::size_t const column_size,
                        ArrayLayoutType const layout,
                        const std::function<std::size_t(std::size_t,std::size_t)> & pairing_function); /* constructor      */

        FixtureArray2d ( const FixtureArray2d &other )=delete;   /* copy constructor */

        ~FixtureArray2d ();                            /* destructor       */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */
        FixtureArray2d& operator= ( const FixtureArray2d &other )=delete; /* assignment operator */

        /* ====================  DATA MEMBERS  ======================================= */
        ArrayLayoutType arrayLayoutType;
        std::size_t rowSize;
        std::size_t columnSize;
        std::size_t** array2d_ptr;

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class FixtureArray2d  ----- */


#endif   /* ----- #ifndef FixtureArray2d_INC  ----- */

