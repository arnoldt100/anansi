#ifndef ANANSI_TaskInterface_INC
#define ANANSI_TaskInterface_INC
//! @file TaskInterface.hpp
//!
//! Brief description
//!
//! Detailed description

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
//        Class:  TaskInterface
//  Description:  
//  =====================================================================================
class TaskInterface
{
    public:
        // ====================  LIFECYCLE     =======================================

        TaskInterface ();   // constructor

        TaskInterface (const TaskInterface & other);   // copy constructor

        TaskInterface (TaskInterface && other);   // copy-move constructor

        virtual ~TaskInterface ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TaskInterface& operator= ( const TaskInterface &other ); // assignment operator

        TaskInterface& operator= ( TaskInterface && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskInterface  -----


}; // namespace ANANSI

#endif // ANANSI_TaskInterface_INC
