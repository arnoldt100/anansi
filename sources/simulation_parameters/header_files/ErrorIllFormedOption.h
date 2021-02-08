#ifndef  ErrorIllFormedOption_INC
#define  ErrorIllFormedOption_INC


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
     *        Class:  ErrorIllFormedOption
     *  Description:  
     * =====================================================================================
     */
    class ErrorIllFormedOption : std::exception
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            /*
             *--------------------------------------------------------------------------------------
             *       Class:  ErrorIllFormedOption
             *      Method:  ErrorIllFormedOption :: ErrorIllFormedOption
             * Description:  Constructor
             *
             * Arguments: 
             *
             *--------------------------------------------------------------------------------------
             */
            ErrorIllFormedOption ();   /* constructor      */

            ErrorIllFormedOption (const ErrorIllFormedOption & other);   /* copy constructor */

            ErrorIllFormedOption (ErrorIllFormedOption && other);   /* copy-move constructor */

            virtual ~ErrorIllFormedOption();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */
            const char* what() const noexcept;

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            ErrorIllFormedOption& operator= ( const ErrorIllFormedOption &other ); /* assignment operator */

            ErrorIllFormedOption& operator= ( ErrorIllFormedOption && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class ErrorIllFormedOption  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef ErrorIllFormedOption_INC  ----- */
