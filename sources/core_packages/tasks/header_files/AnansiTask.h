#ifndef  ANANSI_AnansiTask_INC
#define  ANANSI_AnansiTask_INC

//! @file AnansiTask.h
//!
//! This file contains the declaration for the class AnansiTask.
//!
//! Class AnansiTask is needed for the Abstract Factory Pattern as 
//! described in *Modern C++ design: Generic Programming and Design Patterns
//! Applied* by Andrei Alexandrescu.


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiTaskParameters.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  AnansiTask
//  Description:  
//  =====================================================================================

//! The base class for the tasks in Anansi.
class AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        AnansiTask ();   // constructor

        AnansiTask (const AnansiTask & other);   // copy constructor

        AnansiTask (AnansiTask && other);   // copy-move constructor

        virtual ~AnansiTask ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        //! Returns the location of concrete task with respect to the concrete typelist.
        AnansiTaskParameters::task_size_t taskIndex() const;

        // ====================  MUTATORS      =======================================
        
        //! Executes the task.
        //!
        //! The flags parameter can be used for any purpose in the derived classes.
        //! 
        //! @param [in] flags  A list of string flags.
        void doAction(const std::vector<std::string> & flags ) const;
        
        //! Undoes the task execution.
        //!
        //! Some tasks actions can't be undone and such tasks 
        //! will simply execute empty function calls in the derived classes.
        //! The flags parameter can be used for any purpose in the derived classes.
        //! 
        //! @param [in] flags  A list of string flags.
        void undoAction(const std::vector<std::string> & flags );

        void disableTask(const std::vector<std::string> & flags);

        // ====================  OPERATORS     =======================================

        AnansiTask& operator= ( const AnansiTask &other ); // assignment operator

        AnansiTask& operator= ( AnansiTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  ACCESSORS     =======================================
        
        virtual AnansiTaskParameters::task_size_t taskIndex_() const = 0;

        // ====================  MUTATORS      =======================================
        
        virtual void doConcreteTaskAction(const std::vector<std::string> & flags) const = 0;
        
        virtual void undoConcreteTaskAction(const std::vector<std::string> & flags) = 0;

        virtual void disableConcreteTask(const std::vector<std::string> & flags) =0;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AnansiTask  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_AnansiTask_INC  ----- 
