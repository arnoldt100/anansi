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
#include <iostream>
#include "mpi.h"
#include <vector>
#include "boost/optional.hpp"
#include "boost/program_options.hpp"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AllOptions.h"
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

        static void _parseProgramOptionsFromCommandLine(COMMANDLINE::CommandLineArguments const & aCommandLine);


        /* ====================  DATA MEMBERS  ======================================= */
        std::vector<CommandLineOptions> _options;

}; /* -----  end of class SimulationParameters  ----- */


}; /* namespace ANANSI */

#endif /* SIMULATIONPARAMETERS_INC */
