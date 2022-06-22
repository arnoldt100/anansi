/*
 * =====================================================================================
 *
 *       Filename:  SimulationParameters.h
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef SIMULATIONPARAMETERS_INC
#define SIMULATIONPARAMETERS_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>
#include <map>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "boost/program_options.hpp"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

#include "OptionsParametersMap.h"
#include "CommandLineArguments.h"

namespace ANANSI
{


/*
 * =====================================================================================
 *        Class:  SimulationParameters
 *  Description:  
 * =====================================================================================
 */
class SimulationParameters
{

    public:

        /* ====================  LIFECYCLE     ======================================= */

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  SimulationParameters
         *      Method:  SimulationParameters :: SimulationParameters
         * Description:  Constructor
         *
         * Arguments: 
         *
         *--------------------------------------------------------------------------------------
         */
        SimulationParameters (); /* constructor */
        
        SimulationParameters(COMMANDLINE::CommandLineArguments const & aCommandLine); // constructor

        SimulationParameters( SimulationParameters const & other ); // copy constructor

        SimulationParameters( SimulationParameters && other);

        ~SimulationParameters(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

        //--------------------------------------------------------------------------------------
        //       Class:  SimulationParameters
        //      Method:  SimulationParameters :: isCommandLineOptionPresent
        // Description:  Inquires if an option, designated by key, is present. If the option is present
        //               then true is returned, otherwise false is returned.
        // 
        //  Parameters: key - The name of the option being inquired about.
        //
        //      Return: bool
        //--------------------------------------------------------------------------------------
        bool isCommandLineOptionPresent ( std::string const & key) const;

        //--------------------------------------------------------------------------------------
        //       Class:  SimulationParameters
        //      Method:  SimulationParameters :: getCommandLineOptionValues
        // Description:  Returns the command line option value for the corresponding key.
        // 
        //  Parameters:  key - The name of the key.
        //
        //      Return: std::string
        //--------------------------------------------------------------------------------------
        std::string getCommandLineOptionValues(std::string const & key) const;

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        SimulationParameters& operator=( const SimulationParameters &other ); // assignment operator

        SimulationParameters& operator=( SimulationParameters && other ); // assignment move operator

        /* ====================  STATIC        ======================================= */
        static const std::string OPTION_NOT_FOUND;

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  STATIC        ======================================= */

        static OPTIONS_PARAMETERS_MAP_t parseProgramOptionsFromCommandLine_(COMMANDLINE::CommandLineArguments const & aCommandLine);

        //--------------------------------------------------------------------------------------
        //       Class:  SimulationParameters
        //      Method:  SimulationParameters :: createBoostVariableMap_
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return: void
        //--------------------------------------------------------------------------------------
        static boost::program_options::variables_map createBoostVariableMap_(COMMANDLINE::CommandLineArguments const & aCommandLine);


        //--------------------------------------------------------------------------------------
        //       Class:  SimulationParameters
        //      Method:  SimulationParameters :: transferBoostVariableMap_
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return: void
        //--------------------------------------------------------------------------------------
        static OPTIONS_PARAMETERS_MAP_t transferBoostVariableMap_(boost::program_options::variables_map const & vm);

        /* ====================  DATA MEMBERS  ======================================= */
        OPTIONS_PARAMETERS_MAP_t  commandLineOptionsMap_;
        OPTIONS_PARAMETERS_MAP_t  simulationParametersMap_;

}; /* -----  end of class SimulationParameters  ----- */


}; /* namespace ANANSI */

#endif /* SIMULATIONPARAMETERS_INC */
