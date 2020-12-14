
#ifndef  TooManyInstancesError_INC
#define  TooManyInstancesError_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COUNTERCLASS
{

    /*
     * =====================================================================================
     *        Class:  TooManyInstancesError
     *  Description:  
     * =====================================================================================
     */
    template <typename T, int MAX_INSTANCES>
    class TooManyInstancesError : std::exception
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            TooManyInstancesError ()
            {
                return;
            }

            ~TooManyInstancesError ()
            {
                return;
            }

            /* ====================  ACCESSORS     ======================================= */
            const char* 
            what() const throw()
            {
                return "Too many instances of a class.";
            }

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class TooManyInstancesError  ----- */


}; /* namespace COUNTERCLASS */

#endif   /* ----- #ifndef TooManyInstancesError_INC  ----- */
