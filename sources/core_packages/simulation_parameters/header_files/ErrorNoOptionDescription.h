#ifndef  ErrorNoOptionDescription_INC
#define  ErrorNoOptionDescription_INC


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
     *        Class:  ErrorNoOptionDescription
     *  Description:  
     * =====================================================================================
     */
    class ErrorNoOptionDescription : std::exception
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            /*
             *--------------------------------------------------------------------------------------
             *       Class:  ErrorNoOptionDescription
             *      Method:  ErrorNoOptionDescription :: ErrorNoOptionDescription
             * Description:  Constructor
             *
             * Arguments: 
             *
             *--------------------------------------------------------------------------------------
             */
            ErrorNoOptionDescription ();   /* constructor      */

            ErrorNoOptionDescription (const ErrorNoOptionDescription & other);   /* copy constructor */

            ErrorNoOptionDescription (ErrorNoOptionDescription && other);   /* copy-move constructor */

            virtual ~ErrorNoOptionDescription ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */
            const char* what() const noexcept;

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            ErrorNoOptionDescription& operator= ( const ErrorNoOptionDescription &other ); /* assignment operator */

            ErrorNoOptionDescription& operator= ( ErrorNoOptionDescription && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class ErrorNoOptionDescription  ----- */


}; /* namespace ANANSI */

#endif   // ----- #ifndef ErrorNoOptionDescription_INC  ----- 
