#ifndef ANANSI_MDSimulationStateFactory_INC
#define ANANSI_MDSimulationStateFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <iostream>
#include <typeinfo>
#include <utility>

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
            template <typename T>
            std::unique_ptr<SimulationState> create() const
            {
                // Loop over abstact prodict list. If type can be 
                // can be cast to product list type, then create pointer.
                // Else throw error and stop.

                this->findIndex_<T>();

                std::unique_ptr<NullSimulationState> product_ptr(this->mdSimStateFactory_->Create<NullSimulationState>());

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
            // TYPE ALIASES
            using abstract_products_ = MPL::mpl_typelist<
                                                          NullSimulationState,
                                                          InitSimEnv,
                                                          ProcessCmdLine,
                                                          InitInitialConditions,
                                                          PerformSimulation,
                                                          TerminateSimulation
                                                        >;

            using concrete_products_ = MPL::mpl_typelist<
                                                          MDNullSimulationState,
                                                          MDInitSimEnv,
                                                          MDProcessCmdLine,
                                                          MDInitInitialConditions,
                                                          MDPerformSimulation,
                                                          MDTerminateSimulation
                                                        >;

            using abstract_factory_ = MPL::AbstractFactory<abstract_products_>;

            using concrete_factory_ = MPL::ConcreteFactory<abstract_factory_,concrete_products_>;

            template<class Base,class Derived>
            using my_is_base_of = boost::mp11::mp_bool< std::is_base_of_v<Base,Derived> >;
            // std::is_base_of<Base,Derived>
            // ====================  METHODS       =======================================
            template <typename T>
            void findIndex_() const
            {
                using nm_elements = MPL::mpl_size<abstract_products_>; 

                using list_base = boost::mp11::mp_repeat_c<MPL::mpl_typelist<T>, 
                                                           MPL::mpl_size<abstract_products_>::value >;

                using R = boost::mp11::mp_transform<my_is_base_of,abstract_products_,list_base>;

                using R0 = boost::mp11::mp_at_c<R,0>;
                using R1 = boost::mp11::mp_at_c<R,1>;
                using R2 = boost::mp11::mp_at_c<R,2>;

                std::cout << "nm_elements : " << nm_elements::value << std::endl;

                std::cout << "list_base size: " << MPL::mpl_size<list_base>::value << std::endl;

                std::cout << "R size: " << MPL::mpl_size<R>::value << std::endl;

                std::cout << "R[0] is: " <<  typeid(R0).name() << std::endl;
                std::cout << "R[0] is: " <<  R0::value << std::endl;


                std::cout << "R[1] is: " <<  typeid(R1).name() << std::endl;
                std::cout << "R[1] is: " <<  R1::value << std::endl;

                std::cout << "R[2] is: " <<  typeid(R2).name() << std::endl;
                std::cout << "R[2] is: " <<  R2::value << std::endl;

                return;
            } 

            // ====================  DATA MEMBERS  =======================================
            std::unique_ptr<concrete_factory_> mdSimStateFactory_;

    }; // -----  end of class MDSimulationStateFactory  -----


}; // namespace ANANSI

#endif // ANANSI_MDSimulationStateFactory_INC
