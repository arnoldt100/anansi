/*
 * =====================================================================================
 *
 *       Filename:  CommandLineArguments.h
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef COMMANDLINEARGUMENTS_INC
#define COMMANDLINEARGUMENTS_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMANDLINE
{
    /*
     * =====================================================================================
     *        Class:  CommandLineArguments
     *  Description:  
     * =====================================================================================
     */
    class CommandLineArguments
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            /*
             *--------------------------------------------------------------------------------------
             *       Class:  CommandLineArguments
             *      Method:  CommandLineArguments :: CommandLineArguments
             * Description:  Constructor
             *
             * Arguments: 
             *
             *--------------------------------------------------------------------------------------
             */
            CommandLineArguments (); /* constructor      */

            CommandLineArguments( const CommandLineArguments &other ); /* copy constructor */

            ~CommandLineArguments(); /* destructor       */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            CommandLineArguments&
            operator=( const CommandLineArguments &other ); /* assignment operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class CommandLineArguments  ----- */


}; /* namespace COMMANDLINE */

#endif /* COMMANDLINEARGUMENTS_INC */
