#ifndef ANANSI_GenericTaskInvoker_INC
#define ANANSI_GenericTaskInvoker_INC
//! @file GenericTaskInvoker.hpp
//!
//! The command (or task) invoker for the communication environment.
//!
//! The only tasks invoked are 
//! * enable - enabling in communication environment
//! * disable - disabling the communication environment

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <utility>


//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiTask.h"
#include "GenericTaskInvokerUtilities.hpp"
#include "MPLAliases.hpp"
#include "TaskLabel.hpp" 
#include "ReceiverUtilities.hpp"

namespace ANANSI
{

//! The Invoker for the communication environment.
//!
//! Brief description
//!
//! Detailed description

template<typename AbstractProductsTypeList,
         typename ConcreteProductsTypeList, 
         typename LABEL_t=ANANSI::TaskLabel
        >
class GenericTaskInvoker
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericTaskInvoker () :  // constructor
            commandSlots_()
        {
            return;
        }

        GenericTaskInvoker (const GenericTaskInvoker & other)=delete;   // copy constructor

        GenericTaskInvoker (GenericTaskInvoker && other) :  // copy-move constructor
            commandSlots_(std::move(other.commandSlots_))
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method GenericTaskInvoker::GenericTaskInvoker  -----

        ~GenericTaskInvoker ()  // destructor
        {
            this->commandSlots_.clear();
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        //! Adds a task to the invoker.
        void addCommand(LABEL_t const & key,
                        std::shared_ptr<ANANSI::AnansiTask> aCommand)
        {
        	this->commandSlots_[key] = aCommand;
            return;
        }

        void doTask(std::vector<LABEL_t> const & command_keys)
        {
            const std::vector<std::string> flags = {"default"};
            for (auto & key : command_keys)
            {
                (this->commandSlots_.at(key))->doAction(flags);
            }
            return;
        }

        void undoTask(std::vector<LABEL_t> const & command_keys) 
        {
            const std::vector<std::string> flags = {"default"};
            for (auto key : command_keys)
            {
                (this->commandSlots_.at(key))->undoAction(flags);
            }
            return;
        }

        void disableTask(std::vector<LABEL_t> const & command_keys)
        {
            const std::vector<std::string> flags = {"default"};
            for (auto key : command_keys)
            {
                (this->commandSlots_.at(key))->disableTask(flags);
            }
            return;
        }

        template <typename... ReceiverArgsTypes>
        void modifyTask(const LABEL_t & command_key, ReceiverArgsTypes &... args)
        {
            
            constexpr auto zero = static_cast<MPL::mpl_size_type>( 0 );

            const auto concrete_index = 
                static_cast<MPL::mpl_size_type>(this->commandSlots_.at(command_key)->taskIndex());

            constexpr auto nm_products = 
                static_cast<MPL::mpl_size_type>(MPL::mpl_size<ConcreteProductsTypeList>::value);

            std::shared_ptr<ANANSI::AnansiTask> & task = this->commandSlots_.at(command_key);

            if ( not ((0 <= concrete_index ) and (concrete_index < nm_products)) )
            {
                 // :TODO:11/15/2022 10:00:29 AM:: Abort program
                 // for a nonrecoverable error has occurred.
            }

            GenericTaskInvokerUtilities::modifyTaskReceiver<ConcreteProductsTypeList,
                                                            zero,
                                                            ReceiverArgsTypes...>(concrete_index,
                                                                                  task,
                                                                                  args...);
            return;
        }

        template<LABEL_t COMMAND_KEY>
        auto getTaskResults1()
        {
            auto my_tmp_ru = RECEIVER::ReceiverUtilities();
            auto tmp_rt = my_tmp_ru.foo<ConcreteProductsTypeList,COMMAND_KEY>();

            // We compute the range of concrete products in ConcreteProductsTypeList.
            constexpr auto zero = static_cast<MPL::mpl_size_type>( 0 );
            constexpr auto nm_products = 
                static_cast<MPL::mpl_size_type>(MPL::mpl_size<ConcreteProductsTypeList>::value);

            // This is the lcation of the corresponding concrete product in typelist 
            // ConcreteProductsTypeList that has tasklabel COMMAND_KEY.
            constexpr int concrete_index = 
                RECEIVER::ReceiverUtilities::foo<ConcreteProductsTypeList,COMMAND_KEY>();

            // If the corresponding concrete product is not found then abort.
            if ( not ((0 <= concrete_index ) and (concrete_index < nm_products)) )
            {
                 // :TODO:11/15/2022 10:00:29 AM:: Abort program
                 // for a nonrecoverable error has occurred.
            }

            std::shared_ptr<ANANSI::AnansiTask> & task = this->commandSlots_.at(COMMAND_KEY);
            
            GenericTaskInvokerUtilities::getTaskReceiverResults<ConcreteProductsTypeList,
                                                                zero>(concrete_index,
                                                                      task);

            // TODO :: Fri 13 Jan 2023 06:28:24 PM EST :: Replace this with call that will get return
            // type for corresponding receiver of the COMMAND_KEY.
            // using return_t = std::remove_reference<decltype(this->commandSlots_[COMMAND_KEY])>::type;
            using return_t = std::remove_reference<decltype(RECEIVER::ReceiverUtilities::foo<ConcreteProductsTypeList,COMMAND_KEY>())>::type;


            return concrete_index;
        }

        // ====================  OPERATORS     =======================================

        GenericTaskInvoker& operator= ( const GenericTaskInvoker &other )=delete; // assignment operator

        GenericTaskInvoker& operator= ( GenericTaskInvoker && other ) // assignment-move operator
        {
            if (this != &other)
            {
                this->commandSlots_ = std::move(other.commandSlots_); 
            }
            return *this;
        } // assignment-move operator


    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        // ====================  TYPE ALIASES  =======================================  

        using abstract_products_ = AbstractProductsTypeList; 

        using concrete_products_ = ConcreteProductsTypeList;

        // ====================  MUTATORS      =======================================
       
        // ====================  DATA MEMBERS  =======================================
        std::map <LABEL_t,std::shared_ptr<ANANSI::AnansiTask>> commandSlots_;

}; // -----  end of class GenericTaskInvoker  -----


}; // namespace ANANSI

#endif // ANANSI_GenericTaskInvoker_INC
