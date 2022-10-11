#ifndef  ANANSI_MDAnansiTaskFactory_INC
#define  ANANSI_MDAnansiTaskFactory_INC

//! @file MDAnansiTaskFactory.h
//!
//! This files implements the Anansi task factory. The factory
//! use the object factory design pattern.

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
#include "ConsoleLoggingTask.h"
#include "MPIEnvTask.h"
#include "MPLAliases.hpp"
#include "AbstractFactory.hpp"
#include "ConcreteFactory.hpp"
#include "GenericMDTask.hpp"
#include "DefaultFunctorImpl.h"
#include "MPIEnvReceiver.h"

namespace ANANSI
{

class MDAnansiTaskFactory final
{
    public:
        // ====================  LIFECYCLE     =======================================

        MDAnansiTaskFactory ();   // constructor

        MDAnansiTaskFactory (const MDAnansiTaskFactory & other);   // copy constructor

        MDAnansiTaskFactory (MDAnansiTaskFactory && other);   // copy-move constructor

        ~MDAnansiTaskFactory ();  // destructor

        // ====================  ACCESSORS     =======================================
        template <typename T>
        std::shared_ptr<AnansiTask> create_shared_ptr() const
        {
            constexpr auto index = MDAnansiTaskFactory::findIndex_<T>();
            std::shared_ptr<abstract_product_at_<index> > product_ptr(this->mdAnansiTaskFactory_->Create<abstract_product_at_<index>>());
            return product_ptr;
        }

        template <typename T>
        std::unique_ptr<AnansiTask> create_unique_ptr() const
        {
            constexpr auto index = MDAnansiTaskFactory::findIndex_<T>();
            std::unique_ptr<abstract_product_at_<index> > product_ptr(this->mdAnansiTaskFactory_->Create<abstract_product_at_<index>>());
            return product_ptr;
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDAnansiTaskFactory& operator= ( const MDAnansiTaskFactory &other ); // assignment operator

        MDAnansiTaskFactory& operator= ( MDAnansiTaskFactory && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
            // ====================  TYPE ALIASES  =======================================  
            using abstract_products_ = MPL::mpl_typelist<
                                                          LoggingTask,
                                                          InterProcessCommEnv
                                                        >;

            using concrete_products_ = MPL::mpl_typelist<
                                                          ConsoleLoggingTask,
                                                          GenericMDTask<InterProcessCommEnv,MPIEnvReceiver>
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
                using list_base = MPL::mpl_repeat_c<MPL::mpl_typelist<T>, 
                                                    MPL::mpl_size<abstract_products_>::value>;

                using R = MPL::mpl_transform<my_is_base_of_,abstract_products_,list_base>;
                
                using my_index = MPL::mpl_find<R,MPL::mpl_true_type>;

                return my_index::value;
            } 


        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::unique_ptr<concrete_factory_> mdAnansiTaskFactory_;

}; // -----  end of class MDAnansiTaskFactory  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_MDAnansiTaskFactory_INC  ----- 
