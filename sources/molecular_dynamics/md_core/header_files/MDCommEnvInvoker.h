#ifndef ANANSI_MDCommEnvInvoker_INC
#define ANANSI_MDCommEnvInvoker_INC
//! @file MDCommEnvInvoker.h
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
class MDCommEnvInvoker
{
    public:
        // ====================  LIFECYCLE     =======================================

        MDCommEnvInvoker ();   // constructor

        MDCommEnvInvoker (const MDCommEnvInvoker & other)=delete;   // copy constructor

        MDCommEnvInvoker (MDCommEnvInvoker && other);   // copy-move constructor

        ~MDCommEnvInvoker ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! Enables the communication run-time environment.
        //!
        //! @return void
        void doTask() const;

        //! Disables the communication run-time environment.
        //!
        //! @return void
        void undoTask() const;

        // ====================  MUTATORS      =======================================

        //! Adds a task to the invoker.
        //!
        //! @return void
        void addSlot(std::string const & key, 
                     std::shared_ptr<ANANSI::AnansiTask> aCommand); 

        // ====================  OPERATORS     =======================================

        MDCommEnvInvoker& operator= ( const MDCommEnvInvoker &other )=delete; // assignment operator

        MDCommEnvInvoker& operator= ( MDCommEnvInvoker && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::map <std::string,std::shared_ptr<ANANSI::AnansiTask>> _commands;

}; // -----  end of class MDCommEnvInvoker  -----


}; // namespace ANANSI

#endif // ANANSI_MDCommEnvInvoker_INC
