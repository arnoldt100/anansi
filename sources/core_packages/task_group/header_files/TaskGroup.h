#ifndef  ANANSI_TaskGroup_INC
#define  ANANSI_TaskGroup_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  TaskGroup
//  Description:  
//  =====================================================================================
class TaskGroup
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  TaskGroup
        //      Method:  TaskGroup :: TaskGroup
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        TaskGroup();   // constructor

        TaskGroup(const TaskGroup & other) = delete; // copy constructor

        TaskGroup(TaskGroup && other); // copy-move constructor

        virtual ~TaskGroup()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        void enable();

        void disable();

        // ====================  OPERATORS     =======================================

        TaskGroup& operator=( const TaskGroup &other ) = delete; // assignment operator

        TaskGroup& operator=( TaskGroup && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================
        
        // ====================  MUTATORS      =======================================
        virtual void enable_()=0;

        virtual void disable_()=0;


        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskGroup  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_TaskGroup_INC  ----- */
