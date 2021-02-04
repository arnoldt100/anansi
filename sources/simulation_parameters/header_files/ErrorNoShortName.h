
#ifndef  ErrorNoShortName_INC
#define  ErrorNoShortName_INC


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
     *        Class:  ErrorNoShortName
     *  Description:  
     * =====================================================================================
     */
    class ErrorNoShortName : std::exception
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            /*
             *--------------------------------------------------------------------------------------
             *       Class:  ErrorNoShortName
             *      Method:  ErrorNoShortName :: ErrorNoShortName
             * Description:  Constructor
             *
             * Arguments: 
             *
             *--------------------------------------------------------------------------------------
             */
            ErrorNoShortName ();   /* constructor      */

            ErrorNoShortName (const ErrorNoShortName & other);   /* copy constructor */

            ErrorNoShortName (ErrorNoShortName && other);   /* copy-move constructor */

            virtual ~ErrorNoShortName ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */
            const char* what() const noexcept;

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            ErrorNoShortName& operator= ( const ErrorNoShortName &other ); /* assignment operator */

            ErrorNoShortName& operator= ( ErrorNoShortName && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class ErrorNoShortName  ----- */


}; /* namespace ANANSI */

#endif   // ----- #ifndef ErrorNoShortName_INC  ----- 
