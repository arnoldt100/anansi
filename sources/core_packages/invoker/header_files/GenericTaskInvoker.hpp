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

namespace ANANSI
{

//! The Invoker for the communication environment.
//!
//! Invoking the enable method enables the communication run-time environment.
template<typename AbstractProductsTypeList,typename ConcreteProductsTypeList>
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
        //! @return void
        void addCommand(std::string const & key,
                     std::shared_ptr<ANANSI::AnansiTask> aCommand) 
        {
        	this->commandSlots_[key] = aCommand;
            return;
        }

        //! Enables the communication run-time environment.
        //!
        //! @return void
        void doTask(std::vector<std::string> const & command_keys)
        {
            const std::vector<std::string> flags = {"default"};
            for (auto & key : command_keys)
            {
                (this->commandSlots_.at(key))->doAction(flags);
            }
            return;
        }

        //! Disables the communication run-time environment.
        //!
        //! @return void
        void undoTask(std::vector<std::string> const & command_keys) 
        {
            const std::vector<std::string> flags = {"default"};
            for (auto key : command_keys)
            {
                (this->commandSlots_.at(key))->undoAction(flags);
            }
            return;
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

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::map <std::string,std::shared_ptr<ANANSI::AnansiTask>> commandSlots_;

}; // -----  end of class GenericTaskInvoker  -----


}; // namespace ANANSI

#endif // ANANSI_GenericTaskInvoker_INC
