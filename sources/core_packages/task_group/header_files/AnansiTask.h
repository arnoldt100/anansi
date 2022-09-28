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

        void enable();

        void disable();

        // ====================  OPERATORS     =======================================

        AnansiTask& operator= ( const AnansiTask &other ); // assignment operator

        AnansiTask& operator= ( AnansiTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        // ====================  MUTATORS      =======================================

        virtual void enable_();

        virtual void disable_();


        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AnansiTask  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_AnansiTask_INC  ----- 
