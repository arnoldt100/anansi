#ifndef  CommandLineOptions_INC
#define  CommandLineOptions_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

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
     *        Class:  CommandLineOptions
     *  Description:  
     * =====================================================================================
     */
    class CommandLineOptions
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            /*
             *--------------------------------------------------------------------------------------
             *       Class:  CommandLineOptions
             *      Method:  CommandLineOptions :: CommandLineOptions
             * Description:  Constructor
             *
             * Arguments: 
             *
             *--------------------------------------------------------------------------------------
             */
            CommandLineOptions ();   /* constructor      */

            CommandLineOptions (const CommandLineOptions & other);   /* copy constructor */

            CommandLineOptions (CommandLineOptions && other);   /* copy-move constructor */

            virtual ~CommandLineOptions ();  /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            CommandLineOptions& operator= ( const CommandLineOptions &other ); /* assignment operator */

            CommandLineOptions& operator= ( CommandLineOptions && other ); /* assignment-move operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class CommandLineOptions  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef CommandLineOptions_INC  ----- */
