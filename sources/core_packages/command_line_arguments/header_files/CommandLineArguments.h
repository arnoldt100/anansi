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
#include <utility>
#include <new>
#include <cstring>
#include <string>
#include <vector>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Pointer2d.hpp"

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
        CommandLineArguments(); /* constructor      */
        
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
        CommandLineArguments( const int argc, char const * const *const & argv); /* Constructor */

        CommandLineArguments( const CommandLineArguments &other ); /* Copy constructor */

        CommandLineArguments( CommandLineArguments && other ); /* Move-Copy constructor */

        ~CommandLineArguments(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */
        void reformCommandLineArguments(int & argc, char** & argv) const;


        //--------------------------------------------------------------------------------------
        //       Class:  CommandLineArguments
        //      Method:  CommandLineArguments :: findArgument
        // Description:  Returns true if string "str" is found, otherwise return false. 
        // 
        //  Parameters: str - The string to be searched for.
        //
        //      Return: bool
        //--------------------------------------------------------------------------------------
        bool findArgument( const std::string & str ) const;

        /* ====================  MUTATORS      ======================================= */

        void reset();

        /* ====================  OPERATORS     ======================================= */

        CommandLineArguments&
        operator=( const CommandLineArguments &other ); /* Assignment operator */

        CommandLineArguments&
        operator=(  CommandLineArguments && other ); /* Move-Assignment operator */

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


