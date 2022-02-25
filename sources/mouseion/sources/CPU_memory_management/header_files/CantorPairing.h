/*
 * =====================================================================================
 *
 *       Filename:  CantorPairing.h
 *
 *    Description: In mathematics, a pairing function is a process to uniquely encode 
 *                 two natural numbers into a single natural number. 
 *                 The Cantor pairing function is defined by 
 *
 *                      P(x,y) := (1/2)(x + y)(x + y + 1) + y
 *
 *                 Let z = P(x,y). To invert so as to calculate x and y from z we do 
 *                 the following:
 *                      (1) w = floor( (sqrt(8z+1) - 1)/2 )
 *                      (2) t = (w^2 + w)/2
 *                      (3) y = z - t
 *                      (4) x = w - y
 *
 *                 Referenced from https://en.wikipedia.org/wiki/Pairing_function
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef  CantorPairing_INC
#define  CantorPairing_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cmath>
#include <tuple>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

/*
 * =====================================================================================
 *        Class:  CantorPairing
 *  Description:  
 * =====================================================================================
 */


namespace MEMORY_MANAGEMENT
{
    class CantorPairing
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */
            CantorPairing(); /* constructor      */

            CantorPairing( const CantorPairing &other ); /* copy constructor */

            ~CantorPairing(); /* destructor       */

            /* ====================  ACCESSORS     ======================================= */


            /*
             *--------------------------------------------------------------------------------------
             *       Class:  CantorPairing
             *      Method:  CantorPairing :: calculatePairValue
             * Description:  Calculates the Cantor Pair value for natural numbers x and y.
             *              
             *
             * Return: std::size_t
             *
             * Arguments: x; type std::size_t; The first half of the pair of natural numbers.
             *          : y; type std::size_t; The second half of the pair of natural numbers.
             *          : For the algorithm to work x >=0 and y >=0 - No negative numbers!
             *--------------------------------------------------------------------------------------
             */
            std::size_t  calculatePairValue(std::size_t const x, 
                                            std::size_t const y) const;

            
            /*
             *--------------------------------------------------------------------------------------
             *       Class:  CantorPairing
             *      Method:  CantorPairing :: calculateInverse
             * Description:  Calculates the pair of natural numbers x and y the generate the value z = P(x,y).
             *               The function returns the tuple (x,y).
             *
             * Return: std::tuple<std::size_t,std::size_t>
             * 
             * Arguments: z; std::size_t, The cantor pairing value.
             *--------------------------------------------------------------------------------------
             */
            std::tuple<std::size_t,std::size_t> calculateInverse ( const std::size_t w );


            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            CantorPairing& operator=( const CantorPairing &other ); /* assignment operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class CantorPairing  ----- */
}; /* -----  end of namespace MEMORY_MANAGEMENT  ----- */

#endif   /* ----- #ifndef CantorPairing_INC  ----- */
