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
        
        SimulationParameters(COMMANDLINE::CommandLineArguments const & aCommandLine); /* constructor */

        SimulationParameters( const SimulationParameters &other ); /* copy constructor */

        ~SimulationParameters(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        SimulationParameters& operator=( const SimulationParameters &other ); /* assignment operator */

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
