#ifndef ANANSI_GenericTaskInvoker_INC
#define ANANSI_GenericTaskInvoker_INC
//! @file GenericTaskInvoker.hpp

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

//! Stores tasks.
//!
//! This non-copyable template class stores the tasks and facilitates various actions on the
//! stored tasks. These actions and a brief description are listed below:
//!
//! - addTask
//! - disableTask
//! - doTask
//! - getCopyOfTaskResults
//! - shareTaskResults
//! - modifyTask
//! - undoTask
//!
//! @tparam AbstractProductsTypeList A typelist of abstract tasks.
//! @tparam ConcreteProductsTypeList A typelist of concrete tasks.
//! @tparam LABEL_t  The type of task label (button id)
template<typename AbstractProductsTypeList,
         typename ConcreteProductsTypeList,
         typename LABEL_t=RECEIVER::TaskLabel
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
        //!
        //! @param[in] key The button id for the command.
        //! @param[in] aCommand The command/task to be added to the invoker.
        void
        addTask(LABEL_t const & key,
                std::shared_ptr<ANANSI::AnansiTask> aCommand)
        {
            this->commandSlots_[key] = aCommand;
            return;
        }

        void
        doTask(std::vector<LABEL_t> const & command_keys)
        {
            const std::vector<std::string> flags = {"default"};
            for (auto & key : command_keys)
            {
                (this->commandSlots_.at(key))->doAction(flags);
            }
            return;
        }

        void
        undoTask(std::vector<LABEL_t> const & command_keys)
        {
            const std::vector<std::string> flags = {"default"};
            for (auto key : command_keys)
            {
                (this->commandSlots_.at(key))->undoAction(flags);
            }
            return;
        }

        void
        disableTask(std::vector<LABEL_t> const & command_keys)
        {
            const std::vector<std::string> flags = {"default"};
            for (auto key : command_keys)
            {
                (this->commandSlots_.at(key))->disableTask(flags);
            }
            return;
        }

        //! Modifies the receiver of the task that corresponds to label COMMAND_KEY.
        //!
        //! @tparam COMMAND_KEY The label of the task for which we seek the results.
        //! @tparam ReceiverArgsTypes A paramater pack of types of args,
        //! @param[in,out]  args The parameter pack of arguments that used in modfying the receiver.
        template <LABEL_t COMMAND_KEY,
                  typename... ReceiverArgsTypes>
        void
        modifyTask( ReceiverArgsTypes &... args)
        {

            GenericTaskInvokerUtilities::verifyConcreteProductInTypeList<ConcreteProductsTypeList,COMMAND_KEY>();

            std::shared_ptr<ANANSI::AnansiTask> & task = this->commandSlots_.at(COMMAND_KEY);

            GenericTaskInvokerUtilities::modifyTaskReceiver<ConcreteProductsTypeList,
                                        LABEL_t,
                                        COMMAND_KEY,
                                        ReceiverArgsTypes...>(task,args...);
            return;
        }

        //! Returns a copy of the results for the task corresponding to COMMAND_KEY.
        //!
        //! @tparam COMMAND_KEY The label of the task for which we seek the results.
        template<LABEL_t COMMAND_KEY>
        auto
        getCopyOfTaskResults()
        {
            // We compute the range of concrete products in ConcreteProductsTypeList.
            constexpr auto nm_products =
                static_cast<MPL::mpl_size_type>(MPL::mpl_size<ConcreteProductsTypeList>::value);

            // This is the lcation of the corresponding concrete product in typelist
            // ConcreteProductsTypeList that has tasklabel COMMAND_KEY.
            constexpr int concrete_index =
                RECEIVER::ReceiverUtilities::getLocationInTypeList<ConcreteProductsTypeList,
                COMMAND_KEY>();

            // If the corresponding concrete product is not found then abort.
            if constexpr ( not ((0 <= concrete_index ) and (concrete_index < nm_products)) )
            {
                // :TODO:11/15/2022 10:00:29 AM:: Abort program
                // for a nonrecoverable error has occurred.
            }

            std::shared_ptr<ANANSI::AnansiTask> & task = this->commandSlots_.at(COMMAND_KEY);

            auto results = GenericTaskInvokerUtilities::getCopyOfTaskReceiverResults<ConcreteProductsTypeList,
                 concrete_index>(task);
            return results;
        }

        //! Shares the results for the task corresponding to COMMAND_KEY.
        //!
        //! @tparam COMMAND_KEY The label of the task for which we seek the results.
        template<LABEL_t COMMAND_KEY>
        auto
        shareTaskResults()
        {
            // We compute the range of concrete products in ConcreteProductsTypeList.
            constexpr auto nm_products =
                static_cast<MPL::mpl_size_type>(MPL::mpl_size<ConcreteProductsTypeList>::value);

            // This is the lcation of the corresponding concrete product in typelist
            // ConcreteProductsTypeList that has tasklabel COMMAND_KEY.
            constexpr int concrete_index =
                RECEIVER::ReceiverUtilities::getLocationInTypeList<ConcreteProductsTypeList,
                COMMAND_KEY>();

            // If the corresponding concrete product is not found then abort.
            if constexpr ( not ((0 <= concrete_index ) and (concrete_index < nm_products)) )
            {
                // :TODO:11/15/2022 10:00:29 AM:: Abort program
                // for a nonrecoverable error has occurred.
            }

            std::shared_ptr<ANANSI::AnansiTask> & task = this->commandSlots_.at(COMMAND_KEY);

            return 10;
        }


        // ====================  OPERATORS     =======================================

        GenericTaskInvoker&
        operator= ( const GenericTaskInvoker &other )=delete; // assignment operator

        GenericTaskInvoker&
        operator= ( GenericTaskInvoker && other ) // assignment-move operator
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
