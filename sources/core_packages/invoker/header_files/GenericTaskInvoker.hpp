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
#include "ReceiverTypeUtilities.hpp"

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
//! @tparam ConcreteTasksTypeList A typelist of concrete tasks.
//! @tparam LABEL_t  The type of task label (button id)
template<typename AbstractProductsTypeList,
         typename ConcreteTasksTypeList,
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
        enableTask(std::vector<LABEL_t> const & command_keys)
        {
            const std::vector<std::string> flags = {"default"};
            for (auto key : command_keys)
            {
                (this->commandSlots_.at(key))->enableTask(flags);
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

        //! Modifies the receiver of the task that corresponds to label COMMAND_LABEL.
        //!
        //! @tparam COMMAND_LABEL The command 'button' label of the task for which we seek the results.
        //! @tparam ReceiverArgsTypes A paramater pack of types of args,
        //! @param[in,out]  args The parameter pack of arguments that used in modfying the receiver.
        template <LABEL_t COMMAND_LABEL,
                  typename... ReceiverArgsTypes>
        void
        modifyTask( ReceiverArgsTypes &... args)
        {

            GenericTaskInvokerUtilities::verifyConcreteProductInTypeList<ConcreteTasksTypeList,COMMAND_LABEL>();

            std::shared_ptr<ANANSI::AnansiTask> & task = this->commandSlots_.at(COMMAND_LABEL);

            GenericTaskInvokerUtilities::modifyTaskReceiver<ConcreteTasksTypeList,
                                        LABEL_t,
                                        COMMAND_LABEL,
                                        ReceiverArgsTypes...>(task,args...);
            return;
        }

        //! Returns a copy of the results for the task corresponding to COMMAND_LABEL.
        //!
        //! @tparam COMMAND_LABEL The label of the task for which we seek the results.
        template<LABEL_t COMMAND_LABEL>
        auto
        getCopyOfTaskResults()
        {
            GenericTaskInvokerUtilities::verifyConcreteProductInTypeList<ConcreteTasksTypeList,COMMAND_LABEL>();

            std::shared_ptr<ANANSI::AnansiTask> & task = this->commandSlots_.at(COMMAND_LABEL);

            auto results = 
                GenericTaskInvokerUtilities::getCopyOfTaskReceiverResults<ConcreteTasksTypeList,LABEL_t,     
                    COMMAND_LABEL>(task);
            return results;
        }

        //! Shares the results for the task corresponding to COMMAND_LABEL.
        //!
        //! @tparam COMMAND_LABEL The label of the task for which we seek the results.
        template<LABEL_t COMMAND_LABEL>
        auto
        shareTaskResults()
        {
            GenericTaskInvokerUtilities::verifyConcreteProductInTypeList<ConcreteTasksTypeList,COMMAND_LABEL>();

            std::shared_ptr<ANANSI::AnansiTask> & task = this->commandSlots_.at(COMMAND_LABEL);

            auto results = 
                GenericTaskInvokerUtilities::getShareOfTaskReceiverResults<ConcreteTasksTypeList,LABEL_t,     
                    COMMAND_LABEL>(task);

            return results;
        }

        //! Returns a 'handle' to the concrete task.
        template <LABEL_t COMMAND_LABEL>
        auto getHandleToTask()
        {
            GenericTaskInvokerUtilities::verifyConcreteProductInTypeList<ConcreteTasksTypeList,COMMAND_LABEL>();

            std::shared_ptr<ANANSI::AnansiTask> & task = this->commandSlots_.at(COMMAND_LABEL);

            return task;
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

        using concrete_products_ = ConcreteTasksTypeList;

        // ====================  MUTATORS      =======================================

        // ====================  DATA MEMBERS  =======================================
        std::map <LABEL_t,std::shared_ptr<ANANSI::AnansiTask>> commandSlots_;

}; // -----  end of class GenericTaskInvoker  -----


}; // namespace ANANSI

#endif // ANANSI_GenericTaskInvoker_INC
