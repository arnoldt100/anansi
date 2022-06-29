#ifndef  ANANSI_TaskGroup_INC
#define  ANANSI_TaskGroup_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "DefineVisitableMacro.h"
#include "BaseVisitable.hpp"

namespace ANANSI
{

// =====================================================================================
//        Class:  TaskGroup
//  Description:  
//  =====================================================================================
class TaskGroup : public  MPL::BaseVisitable<>
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
        DEFINE_VISITABLE()

        void addCommunicator();
        void addLogger();

        // ====================  OPERATORS     =======================================

        TaskGroup& operator=( const TaskGroup &other ) = delete; // assignment operator

        TaskGroup& operator=( TaskGroup && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================
        
        // ====================  MUTATORS      =======================================
        virtual void addCommunicator_()=0;
        virtual void addLogger_()=0;


        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskGroup  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_TaskGroup_INC  ----- */
