#ifndef  ANANSI_TaskGroupFactory_INC
#define  ANANSI_TaskGroupFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

#include "TaskGroup.h"
#include "Factory.hpp"

namespace ANANSI
{

// =====================================================================================
//        Class:  TaskGroupFactory
//  Description:  
//  =====================================================================================
class TaskGroupFactory
{
    public:
        // ====================  LIFECYCLE     =======================================

        TaskGroupFactory ();   // constructor

        TaskGroupFactory (const TaskGroupFactory & other);   // copy constructor

        TaskGroupFactory (TaskGroupFactory && other);   // copy-move constructor

        ~TaskGroupFactory ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TaskGroupFactory& operator= ( const TaskGroupFactory &other ); // assignment operator

        TaskGroupFactory& operator= ( TaskGroupFactory && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================
        MPL::Factory<ANANSI::TaskGroup,int> myFactory_;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskGroupFactory  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_TaskGroupFactory_INC  ----- */
