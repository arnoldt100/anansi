#ifndef ANANSI_MDSimulationStateFactory_INC
#define ANANSI_MDSimulationStateFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MDNullSimulation.h"
#include "MDProcessCmdLine.h"
#include "MDInitSimEnv.h"
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
    class MDSimulationStateFactory final
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
            template <typename T>
            std::unique_ptr<SimulationState> create() const
            {
                constexpr auto index = MDSimulationStateFactory::findIndex_<T>();
                std::unique_ptr<abstract_product_at_<index> > product_ptr(this->mdSimStateFactory_->Create<abstract_product_at_<index>>());
                return product_ptr;

            }

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            MDSimulationStateFactory& operator= ( const MDSimulationStateFactory &other ); // assignment operator

            MDSimulationStateFactory& operator= ( MDSimulationStateFactory && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  TYPE ALIASES  =======================================  
            using abstract_products_ = MPL::mpl_typelist<
                                                          NullSimulation,
                                                          InitSimEnv,
                                                          ProcessCmdLine,
                                                          InitInitialConditions,
                                                          PerformSimulation,
                                                          TerminateSimulation
                                                        >;

            using concrete_products_ = MPL::mpl_typelist<
                                                          MDNullSimulation,
                                                          MDInitSimEnv,
                                                          MDProcessCmdLine,
                                                          MDInitInitialConditions,
                                                          MDPerformSimulation,
                                                          MDTerminateSimulation
                                                        >;

            template<std::size_t T>
            using abstract_product_at_ = MPL::mpl_at_c<abstract_products_,T>;

            using abstract_factory_ = MPL::AbstractFactory<abstract_products_>;

            using concrete_factory_ = MPL::ConcreteFactory<abstract_factory_,concrete_products_>;

            template<class Base,class Derived>
            using my_is_base_of_ = typename MPL::mpl_bool< MPL::mpl_is_base_of<Base,Derived>::value >;

            // ====================  STATIC METHODS       ================================
            template <typename T>
            static constexpr std::size_t findIndex_()
            {
                using nm_elements = MPL::mpl_size<abstract_products_>; 

                using list_base = MPL::mpl_repeat_c<MPL::mpl_typelist<T>, 
                                                    MPL::mpl_size<abstract_products_>::value>;

                using R = MPL::mpl_transform<my_is_base_of_,abstract_products_,list_base>;
                
                using my_index = MPL::mpl_find<R,MPL::mpl_true_type>;

                return my_index::value;
            } 

            // ====================  DATA MEMBERS  =======================================
            std::unique_ptr<concrete_factory_> mdSimStateFactory_;

    }; // -----  end of class MDSimulationStateFactory  -----


}; // namespace ANANSI

#endif // ANANSI_MDSimulationStateFactory_INC
