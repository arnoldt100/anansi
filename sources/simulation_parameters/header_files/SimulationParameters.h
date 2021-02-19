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
#include "CommandLineArguments.h"
#include "CommandLineOptions.h"

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
        
        SimulationParameters( SimulationParameters && other);

        SimulationParameters(COMMANDLINE::CommandLineArguments const & aCommandLine); // constructor

        SimulationParameters( SimulationParameters const & other ); // copy constructor

        ~SimulationParameters(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

         

        //--------------------------------------------------------------------------------------
        //       Class:  SimulationParameters
        //      Method:  SimulationParameters :: isOptionPresent
        // Description:  Inquires if an option, designated by key, is present. If the option is present
        //               then true is returned, otherwise false is returned.
        // 
        //  Parameters: key - The name of the option being inquired about.
        //
        //      Return: bool
        //--------------------------------------------------------------------------------------
        bool isOptionPresent ( std::string const & key) const;

        //--------------------------------------------------------------------------------------
        //       Class:  SimulationParameters
        //      Method:  SimulationParameters :: getOptionValues
        // Description:  Returns the command line option value for the corresponding key.
        // 
        //  Parameters:  key - The name of the key.
        //
        //      Return: std::string
        //--------------------------------------------------------------------------------------
        std::string getOptionValues(std::string const & key) const;

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        SimulationParameters& operator=( const SimulationParameters &other ); // assignment operator

        SimulationParameters& operator=( SimulationParameters && other ); // assignment move operator

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  STATIC        ======================================= */

        static std::vector<CommandLineOptions> _parseOptionsClasses();

        static std::map<std::string,std::string> _parseProgramOptionsFromCommandLine(COMMANDLINE::CommandLineArguments const & aCommandLine);

        //--------------------------------------------------------------------------------------
        //       Class:  SimulationParameters
        //      Method:  SimulationParameters :: _createBoostVariableMap
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return: void
        //--------------------------------------------------------------------------------------
        static boost::program_options::variables_map _createBoostVariableMap(COMMANDLINE::CommandLineArguments const & aCommandLine);


        //--------------------------------------------------------------------------------------
        //       Class:  SimulationParameters
        //      Method:  SimulationParameters :: _transferBoostVariableMap
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return: void
        //--------------------------------------------------------------------------------------
        static std::map<std::string,std::string> _transferBoostVariableMap(boost::program_options::variables_map const & vm);

        /* ====================  DATA MEMBERS  ======================================= */
        std::map<std::string,std::string> _optionsMap;

}; /* -----  end of class SimulationParameters  ----- */


}; /* namespace ANANSI */

#endif /* SIMULATIONPARAMETERS_INC */
