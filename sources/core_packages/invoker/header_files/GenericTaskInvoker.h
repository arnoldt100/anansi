#ifndef ANANSI_GenericTaskInvoker_INC
#define ANANSI_GenericTaskInvoker_INC
//! @file GenericTaskInvoker.h
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
class GenericTaskInvoker
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericTaskInvoker ();   // constructor

        GenericTaskInvoker (const GenericTaskInvoker & other)=delete;   // copy constructor

        GenericTaskInvoker (GenericTaskInvoker && other);   // copy-move constructor

        ~GenericTaskInvoker ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        //! Adds a task to the invoker.
        //!
        //! @return void
        void addCommand(std::string const & key,
                     std::shared_ptr<ANANSI::AnansiTask> aCommand); 

        //! Enables the communication run-time environment.
        //!
        //! @return void
        void doTask(std::string const & command_key);

        //! Disables the communication run-time environment.
        //!
        //! @return void
        void undoTask(std::string const & command_key); 

        // ====================  OPERATORS     =======================================

        GenericTaskInvoker& operator= ( const GenericTaskInvoker &other )=delete; // assignment operator

        GenericTaskInvoker& operator= ( GenericTaskInvoker && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::map <std::string,std::shared_ptr<ANANSI::AnansiTask>> commandSlots_;

}; // -----  end of class GenericTaskInvoker  -----


}; // namespace ANANSI

#endif // ANANSI_GenericTaskInvoker_INC
