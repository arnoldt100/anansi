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
#include "InterProcessCommEnv.h"
#include "MPLAliases.hpp"
#include "AbstractFactory.hpp"
#include "ConcreteFactory.hpp"
#include "GenericMDTask.hpp"
#include "DefaultFunctorImpl.h"
#include "MPIEnvReceiver.h"
#include "MPIEnvironmentTraits.h"

namespace ANANSI
{

template <typename AbstractProductsTypeList,typename ConcreteProductsTypeList>
class MDAnansiTaskFactory 
{
    private :
        using abstract_products_ = AbstractProductsTypeList; // MPIEnvironmentTraits::abstract_products;

        using concrete_products_ = ConcreteProductsTypeList; // MPIEnvironmentTraits::concrete_products;

        template<std::size_t T>
        using abstract_product_at_ = MPL::mpl_at_c<abstract_products_,T>;

        template<std::size_t T>
        using concrete_product_at_ = MPL::mpl_at_c<concrete_products_,T>;

    public:
        // ====================  LIFECYCLE     =======================================

        MDAnansiTaskFactory () :  // constructor
            mdAnansiTaskFactory_(std::make_unique<concrete_factory_>())
        {
            return;
        }

        MDAnansiTaskFactory (const MDAnansiTaskFactory & other) :  // copy constructor
            mdAnansiTaskFactory_(std::make_unique<concrete_factory_>())
        {
            if (this != &other)
            {
                
            }
            return;
        }

        MDAnansiTaskFactory (MDAnansiTaskFactory && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method MDAnansiTaskFactory::MDAnansiTaskFactory  -----

        ~MDAnansiTaskFactory ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        template <typename T, typename... Types>
        std::shared_ptr<AnansiTask> create_shared_ptr(Types &... args) const
        {
            constexpr auto index = MDAnansiTaskFactory::findIndex_<T>();
            using abstract_product_t = abstract_product_at_<index>;
            using concrete_product_t = concrete_product_at_<index>;

            std::shared_ptr<abstract_product_t> product_ptr(this->mdAnansiTaskFactory_->Create<abstract_product_t>());

            std::shared_ptr<abstract_product_t> p_ptr = 
                this->bindReceivers_<concrete_product_t,abstract_product_t,Types...>(product_ptr, args...);

            return p_ptr;
        }

        template <typename T, typename... Types>
        std::unique_ptr<AnansiTask> create_unique_ptr(Types &... args) const
        {
            constexpr auto index = MDAnansiTaskFactory::findIndex_<T>();
            using abstract_product_t = abstract_product_at_<index>;
            using concrete_product_t = concrete_product_at_<index>;

            std::unique_ptr<abstract_product_t> product_ptr(this->mdAnansiTaskFactory_->Create<abstract_product_t>());

            std::unique_ptr<abstract_product_t> p_ptr = 
                this->bindReceivers_<concrete_product_t,abstract_product_t,Types...>(product_ptr, args...);

            return p_ptr;
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDAnansiTaskFactory& operator= ( const MDAnansiTaskFactory &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator


        MDAnansiTaskFactory& operator= ( MDAnansiTaskFactory && other ) // assignment-move operator
        {
            if (this != &other)
            {
                mdAnansiTaskFactory_ = std::move(other.mdAnansiTaskFactory_);
            }
            return *this;
        } // assignment-move operator


    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
            // ====================  TYPE ALIASES  =======================================  

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

         // :TODO:10/11/2022 05:05:10 PM:: These asConcreteTask_ and asAbstractTask_ should
         // be in another package as utilities. 
        template<typename concrete_task_t, typename abstract_task_t>
        std::shared_ptr<concrete_task_t> asConcreteTask_(std::shared_ptr<abstract_task_t> aTask) const
        {
            return std::static_pointer_cast<concrete_task_t>(aTask);
        }

        template<typename concrete_task_t, typename abstract_task_t>
        std::unique_ptr<concrete_task_t> asConcreteTask_(std::unique_ptr<abstract_task_t> aTask) const
        {
            concrete_task_t* tmp_ptr = dynamic_cast<concrete_task_t*>(aTask.get());
            std::unique_ptr<concrete_task_t> p_ptr(nullptr);
            if ( tmp_ptr != nullptr)
            {
                aTask.release();
                p_ptr.reset(tmp_ptr);
            }
            return p_ptr;
        }

        template<typename concrete_task_t, typename abstract_task_t>
        std::shared_ptr<abstract_task_t> asAbstractTask_(std::shared_ptr<concrete_task_t> aTask) const
        {
            return std::static_pointer_cast<abstract_task_t>(aTask);
        }
        
        template<typename concrete_task_t, typename abstract_task_t>
        std::unique_ptr<abstract_task_t> asAbstractTask_(std::unique_ptr<concrete_task_t> aTask) const
        {
            abstract_task_t* tmp_ptr = dynamic_cast<concrete_task_t*>(aTask.get());
            std::unique_ptr<abstract_task_t> p_ptr(nullptr);
            if ( tmp_ptr != nullptr)
            {
                aTask.release();
                p_ptr.reset(tmp_ptr);
            }
            return p_ptr;
        }


        // :TODO:10/11/2022 05:07:01 PM::  These bindReceivers_ should be in another pacakge.
        template<typename concrete_task_t, typename abstract_task_t,typename... Types>
        std::shared_ptr<abstract_task_t> bindReceivers_(std::shared_ptr<abstract_task_t> & product, Types &... args) const
        {
            std::shared_ptr<concrete_task_t> p_concrete = this->asConcreteTask_<concrete_task_t,abstract_task_t>(product);
            p_concrete->bindReceivers(args...);
            std::shared_ptr<abstract_task_t> p_abstract = this->asAbstractTask_<concrete_task_t,abstract_task_t>(p_concrete);
            return p_abstract;
        }

        template<typename concrete_task_t, typename abstract_task_t,typename... Types>
        std::unique_ptr<abstract_task_t> bindReceivers_(std::unique_ptr<abstract_task_t> & product, Types &... args) const
        {
            std::unique_ptr<concrete_task_t> p_concrete = this->asConcreteTask_<concrete_task_t,abstract_task_t>(product);
            p_concrete->bindReceivers(args...);
            std::unique_ptr<abstract_task_t> p_abstract = this->asAbstractTask_<concrete_task_t,abstract_task_t>(p_concrete);
            return p_abstract;
        }


        // ====================  DATA MEMBERS  =======================================
        std::unique_ptr<concrete_factory_> mdAnansiTaskFactory_;

}; // -----  end of class MDAnansiTaskFactory  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_MDAnansiTaskFactory_INC  ----- 
