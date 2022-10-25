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

        // ====================  MUTATORS      =======================================
        void doAction(const std::vector<std::string> & commands );
        
        void undoAction(const std::vector<std::string> & commands );

        // ====================  OPERATORS     =======================================

        AnansiTask& operator= ( const AnansiTask &other ); // assignment operator

        AnansiTask& operator= ( AnansiTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        // ====================  MUTATORS      =======================================
        virtual void doAction_(const std::vector<std::string> & commands) = 0;
        
        virtual void undoAction_(const std::vector<std::string> & commands) = 0;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AnansiTask  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_AnansiTask_INC  ----- 
