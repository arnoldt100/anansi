#ifndef  ErrorNoOptionAdded_INC
#define  ErrorNoOptionAdded_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

    /*
     * =====================================================================================
     *        Class:  ErrorNoOptionAdded
     *  Description:  
     * =====================================================================================
     */
    class ErrorNoOptionAdded : std::exception
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            /*
             *--------------------------------------------------------------------------------------
             *       Class:  ErrorNoOptionAdded
             *      Method:  ErrorNoOptionAdded :: ErrorNoOptionAdded
             * Description:  Constructor
             *
             * Arguments: 
             *
             *--------------------------------------------------------------------------------------
             */
            ErrorNoOptionAdded ();   /* constructor      */

            ErrorNoOptionAdded (const ErrorNoOptionAdded & other);   /* copy constructor */

            ErrorNoOptionAdded (ErrorNoOptionAdded && other);   /* copy-move constructor */

            virtual ~ErrorNoOptionAdded ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */
            const char* what() const noexcept;

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            ErrorNoOptionAdded& operator= ( const ErrorNoOptionAdded &other ); /* assignment operator */

            ErrorNoOptionAdded& operator= ( ErrorNoOptionAdded && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class ErrorNoOptionAdded  ----- */


}; /* namespace ANANSI */

#endif   // ----- #ifndef ErrorNoOptionAdded_INC  ----- 
