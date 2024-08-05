/*
 * =====================================================================================
 *
 *       Filename:  SimulationParametersFactory.h
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef SimulationParametersFactory_INC
#define SimulationParametersFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "SimulationParameters.h"
#include "CommandLineArguments.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

/*
 * =====================================================================================
 *        Class:  SimulationParametersFactory
 *  Description:  
 * =====================================================================================
 */
class SimulationParametersFactory
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  SimulationParametersFactory
         *      Method:  SimulationParametersFactory :: SimulationParametersFactory
         * Description:  Constructor
         *
         * Arguments: 
         *
         *--------------------------------------------------------------------------------------
         */
        SimulationParametersFactory();                             /* constructor      */

        SimulationParametersFactory( const SimulationParametersFactory &other );   /* copy constructor */

        ~SimulationParametersFactory();                            /* destructor       */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        SimulationParametersFactory& operator=( const SimulationParametersFactory &other ); /* assignment operator */

        /* ====================  STATIC        ======================================= */

        static SimulationParameters create(COMMANDLINE::CommandLineArguments const & aCommandLine );

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class SimulationParametersFactory  ----- */


}; /* namespace ANANSI */

#endif /* SimulationParametersFactory_INC */
