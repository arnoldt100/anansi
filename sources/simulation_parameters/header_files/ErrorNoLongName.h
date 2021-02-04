
#ifndef  ErrorNoLongName_INC
#define  ErrorNoLongName_INC


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
     *        Class:  ErrorNoLongName
     *  Description:  
     * =====================================================================================
     */
    class ErrorNoLongName : std::exception
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            /*
             *--------------------------------------------------------------------------------------
             *       Class:  ErrorNoLongName
             *      Method:  ErrorNoLongName :: ErrorNoLongName
             * Description:  Constructor
             *
             * Arguments: 
             *
             *--------------------------------------------------------------------------------------
             */
            ErrorNoLongName ();   /* constructor      */

            ErrorNoLongName (const ErrorNoLongName & other);   /* copy constructor */

            ErrorNoLongName (ErrorNoLongName && other);   /* copy-move constructor */

            virtual ~ErrorNoLongName ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */
            const char* what() const noexcept;

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            ErrorNoLongName& operator= ( const ErrorNoLongName &other ); /* assignment operator */

            ErrorNoLongName& operator= ( ErrorNoLongName && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class ErrorNoLongName  ----- */


}; /* namespace ANANSI */

#endif   // ----- #ifndef ErrorNoLongName_INC  ----- 
