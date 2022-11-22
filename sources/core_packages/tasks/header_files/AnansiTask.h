#ifndef  ANANSI_AnansiTask_INC
#define  ANANSI_AnansiTask_INC

//! @file AnansiTask.h
//!
//! The base class for the tasks in Anansi.
//
//! This class is needed for the Abstract Factory Pattern as 
//! descriped in *Modern C++ design: Generic Programming and Design Patterns
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
class AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        AnansiTask ();   // constructor

        AnansiTask (const AnansiTask & other);   // copy constructor

        AnansiTask (AnansiTask && other);   // copy-move constructor

        virtual ~AnansiTask ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        AnansiTaskParameters::task_size_t taskIndex() const;

        // ====================  MUTATORS      =======================================
        void doAction(const std::vector<std::string> & flags ) const;
        
        void undoAction(const std::vector<std::string> & commands );



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
        
        virtual void doConcreteTaskAction(const std::vector<std::string> & commands) const= 0;
        
        virtual void undoConcreteTaskAction(const std::vector<std::string> & commands) = 0;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AnansiTask  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_AnansiTask_INC  ----- 
