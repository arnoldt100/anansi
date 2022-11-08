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
#include "MPLAliases.hpp"
#include "AbstractFactoryUtilities.hpp"
#include "AbstractFactory.hpp"
#include "ConcreteFactory.hpp"
#include "AnansiTask.h"

namespace ANANSI
{

template <typename AbstractProductsTypeList,typename ConcreteProductsTypeList>
class MDAnansiTaskFactory 
{
    public:
        // ====================  LIFECYCLE     =======================================

        MDAnansiTaskFactory () :  // constructor
            mdAnansiTaskFactory_(std::make_unique<concrete_factory_>())

        {
            return;
        }

        MDAnansiTaskFactory (const MDAnansiTaskFactory & other) = delete;  // copy constructor

        MDAnansiTaskFactory (MDAnansiTaskFactory && other) = delete;  // copy-move constructor

        ~MDAnansiTaskFactory ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        
        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDAnansiTaskFactory& operator= ( const MDAnansiTaskFactory &other ) = delete; // assignment operator

        MDAnansiTaskFactory& operator= ( MDAnansiTaskFactory && other ) = delete; // assignment-move operator

    protected:
        
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  TYPE ALIASES  =======================================  

        using abstract_tasks_ = AbstractProductsTypeList; 
        using concrete_tasks_ = ConcreteProductsTypeList;


        template<std::size_t T>
        using abstract_task_at_ = MPL::mpl_at_c<abstract_tasks_,T>;

        template<std::size_t T>
        using concrete_task_at_ = MPL::mpl_at_c<concrete_tasks_,T>;

        using abstract_factory_ = MPL::AbstractFactory<abstract_tasks_>;

        using concrete_factory_ = MPL::ConcreteFactory<abstract_factory_,concrete_tasks_>;

        template<class Base,class Derived>
        using my_is_base_of_ = typename MPL::mpl_bool< MPL::mpl_is_base_of<Base,Derived>::value >;

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


    public: 
        template <typename abstract_task_t, typename receiver_t>
        std::shared_ptr<AnansiTask> create_shared_ptr(receiver_t  & a_receiver) const
        {
            constexpr auto index = MPL::AbstractFactoryUtilities<AbstractProductsTypeList,ConcreteProductsTypeList>:: template findIndex<abstract_task_t>();
            using concrete_task_t = concrete_task_at_<index>;

            std::shared_ptr<abstract_task_t> task_ptr(this->mdAnansiTaskFactory_->template Create<abstract_task_t>());

            std::shared_ptr<abstract_task_t> p_ptr = 
                this->bindReceivers_<concrete_task_t,abstract_task_t,receiver_t>(task_ptr, a_receiver);

            return p_ptr;
        }

        template <typename abstract_task_t, typename receiver_t>
        std::unique_ptr<AnansiTask> create_unique_ptr(receiver_t & a_receiver) const
        {
            constexpr auto index = MPL::AbstractFactoryUtilities<AbstractProductsTypeList,ConcreteProductsTypeList>:: template findIndex<abstract_task_t>();
            using concrete_task_t = concrete_task_at_<index>;

            std::unique_ptr<abstract_task_t> task_ptr(this->mdAnansiTaskFactory_->template Create<abstract_task_t>());

            std::unique_ptr<abstract_task_t> p_ptr = 
                this->bindReceivers_<concrete_task_t,abstract_task_t,receiver_t>(task_ptr, a_receiver);

            return p_ptr;
        }

    private: 
        // ====================  DATA MEMBERS  =======================================
        std::unique_ptr<concrete_factory_> mdAnansiTaskFactory_;

}; // -----  end of class MDAnansiTaskFactory  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_MDAnansiTaskFactory_INC  ----- 
