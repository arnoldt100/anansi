#ifndef ANANSI_MDSimulationStateFactory_INC
#define ANANSI_MDSimulationStateFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

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
#include "AbstractFactory.hpp"
#include "ConcreteFactory.hpp"

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

            MDSimulationStateFactory (const MDSimulationStateFactory & other);   // deleted copy constructor

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

            using abstract_factory_ = MPL::AbstractFactory<abstract_products_>;

            using concrete_factory_ = MPL::ConcreteFactory<abstract_factory_,concrete_products_>;

            // ====================  METHODS       =======================================
            
            // ====================  DATA MEMBERS  =======================================
            std::unique_ptr<concrete_factory_> mdSimStateFactory_;

    }; // -----  end of class MDSimulationStateFactory  -----


}; // namespace ANANSI

#endif // ANANSI_MDSimulationStateFactory_INC
