#ifndef  ANANSI_GenericTaskFactory_INC
#define  ANANSI_GenericTaskFactory_INC

//! @file GenericTaskFactory.hpp
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
#include "AnansiTaskUtilities.hpp"

namespace ANANSI
{

template <typename AbstractProductsTypeList,
          typename ConcreteProductsTypeList>
class GenericTaskFactory 
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericTaskFactory () :  // constructor
            mdAnansiTaskFactory_(std::make_unique<concrete_factory_>())

        {
            return;
        }

        GenericTaskFactory (const GenericTaskFactory & other) = delete;  // copy constructor

        GenericTaskFactory (GenericTaskFactory && other) = delete;  // copy-move constructor

        ~GenericTaskFactory ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        
        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericTaskFactory& operator= ( const GenericTaskFactory &other ) = delete; // assignment operator

        GenericTaskFactory& operator= ( GenericTaskFactory && other ) = delete; // assignment-move operator

    protected:
        
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  TYPE ALIASES  =======================================  

        using abstract_tasks_ = AbstractProductsTypeList; 
        using concrete_tasks_ = ConcreteProductsTypeList;

        using abstract_factory_ = MPL::AbstractFactory<abstract_tasks_>;
        using concrete_factory_ = MPL::ConcreteFactory<abstract_factory_,concrete_tasks_>;

        template <typename abstract_task_t,typename concrete_task_t>
        using ATU = ANANSI:: template AnansiTaskUtilities<abstract_task_t,concrete_task_t>;

        template<typename abstract_task_t>
        using my_concrete_task_t = 
        typename MPL::AbstractFactoryUtilities<AbstractProductsTypeList,ConcreteProductsTypeList>:: template corresponding_concrete_task<abstract_task_t>;

        // ====================  METHODS       =======================================

    public: 
        template <typename abstract_task_t, typename receiver_t>
        std::shared_ptr<AnansiTask> create_shared_ptr(receiver_t  & a_receiver) const
        {
            // The sequence index of the concrete product is the same as the sequence of
            // the abstract product.
            using concrete_index_t = MPL::mpl_find<AbstractProductsTypeList,abstract_task_t>;

            std::shared_ptr<abstract_task_t> task_ptr(this->mdAnansiTaskFactory_->template Create<abstract_task_t>());

            std::shared_ptr<abstract_task_t> p_ptr = 
                ATU<abstract_task_t,
                    my_concrete_task_t<abstract_task_t>
                   >:: template bindReceiverToTask<concrete_index_t,receiver_t>(task_ptr,a_receiver);

            return p_ptr;
        }

        template <typename abstract_task_t, typename receiver_t>
        std::unique_ptr<AnansiTask> create_unique_ptr(receiver_t & a_receiver) const
        {
            // The sequence index of the concrete product is the same as the sequence of
            // the abstract product.
            using concrete_index_t = MPL::mpl_find<AbstractProductsTypeList,abstract_task_t>;

            std::unique_ptr<abstract_task_t> task_ptr(this->mdAnansiTaskFactory_->template Create<abstract_task_t>());

            std::unique_ptr<abstract_task_t> p_ptr = 
                ATU<abstract_task_t,
                    my_concrete_task_t<abstract_task_t>
                   >:: template bindReceiverToTask<concrete_index_t,receiver_t>(task_ptr,a_receiver);

            return p_ptr;
        }

    private: 
        // ====================  DATA MEMBERS  =======================================
        std::unique_ptr<concrete_factory_> mdAnansiTaskFactory_;

}; // -----  end of class GenericTaskFactory  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_GenericTaskFactory_INC  ----- 
