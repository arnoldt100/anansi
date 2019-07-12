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
#include <string>

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
            
            /*
             *--------------------------------------------------------------------------------------
             *       Class:  CommandLineArguments
             *      Method:  CommandLineArguments :: CommandLineArguments
             * Description:  Constructor
             *
             * Arguments: 
             *      argc - The number of command line arguments.
             *      argv - A array of char* that contain the command line options.
             *--------------------------------------------------------------------------------------
             */
            CommandLineArguments ( const int argc, char* const *const & argv); /* constructor      */

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
            std::size_t _numberOfArguments;
            std::vector<std::string> _commandLineArguments;

    }; /* -----  end of class CommandLineArguments  ----- */


}; /* namespace COMMANDLINE */

#endif /* COMMANDLINEARGUMENTS_INC */


