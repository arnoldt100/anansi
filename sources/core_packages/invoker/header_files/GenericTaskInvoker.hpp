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
#include "MPLAliases.hpp"

namespace ANANSI
{

//! The Invoker for the communication environment.
//!
//! Brief description
//!
//! Detailed description

template<typename AbstractProductsTypeList,
         typename ConcreteProductsTypeList, 
         typename LABEL_t=std::string>
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

        template <typename... T>
        void modifyTask(LABEL_t & command_key, T &... args)
        {
            // Get the concrete task index of the command that corrsponds ot key.
            const auto concrete_index = (this->commandSlots_.at(command_key))->taskIndex();

            auto abstract_task = this->commandSlots_.at(command_key);

            using nm_products_t = MPL::mpl_size<ConcreteProductsTypeList>;

            if ( not (0 <= concrete_index <= nm_products_t::value-1 ) )
            {
                 // :TODO:11/15/2022 10:00:29 AM:: Abort program
                 // for a nonrecoverable error has occured. 
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

        // ====================  MUTATORS      =======================================
       
        //PickUpHere//
        // Create a genric for loop.
        
        // ====================  DATA MEMBERS  =======================================
        std::map <LABEL_t,std::shared_ptr<ANANSI::AnansiTask>> commandSlots_;

}; // -----  end of class GenericTaskInvoker  -----


}; // namespace ANANSI

#endif // ANANSI_GenericTaskInvoker_INC
