#ifndef ANANSI_MDSimulationStateFactory_INC
#define ANANSI_MDSimulationStateFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MDNullSimulationState.h"
#include "MDInitSimEnv.h"
#include "MDProcessCmdLine.h"
#include "MDInitInitialConditions.h"
#include "MDPerformSimulation.h"
#include "MDTerminateSimulation.h"
#include "MPLAliases.hpp"

namespace ANANSI
{

     // =====================================================================================
     //        Class:  MDSimulationStateFactory
     //  Description:  
     //  =====================================================================================
    class MDSimulationStateFactory
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  MDSimulationStateFactory
            //      Method:  MDSimulationStateFactory :: MDSimulationStateFactory
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            MDSimulationStateFactory ();   // constructor

            MDSimulationStateFactory (const MDSimulationStateFactory & other);   // copy constructor

            MDSimulationStateFactory (MDSimulationStateFactory && other);   // copy-move constructor

            ~MDSimulationStateFactory ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            MDSimulationStateFactory& operator= ( const MDSimulationStateFactory &other ); // assignment operator

            MDSimulationStateFactory& operator= ( MDSimulationStateFactory && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // TYPE ALIASES
            using abstract_products_ = MPL::mpl_typelist<
                                                          NullSimulationState,
                                                          InitSimEnv,
                                                          ProcessCmdLine,
                                                          InitInitialConditions,
                                                          PerformSimulation,
                                                          TerminateSimulation
                                                        > ;

            using concrete_products_ = MPL::mpl_typelist<
                                                          MDNullSimulationState,
                                                          MDInitSimEnv,
                                                          MDProcessCmdLine,
                                                          MDInitInitialConditions,
                                                          MDPerformSimulation,
                                                          MDTerminateSimulation
                                                        > ;
            // ====================  METHODS       =======================================
            
            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class MDSimulationStateFactory  -----


}; // namespace ANANSI

#endif // ANANSI_MDSimulationStateFactory_INC
