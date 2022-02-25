#ifndef  Mouseion_TaskStatus_INC
#define  Mouseion_TaskStatus_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR
{

     // =====================================================================================
     //        Class:  TaskStatus
     //  Description:  
     //  =====================================================================================
    class TaskStatus
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  TaskStatus
            //      Method:  TaskStatus :: TaskStatus
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            TaskStatus ();   // constructor

            TaskStatus (const TaskStatus & other);   // copy constructor

            TaskStatus (TaskStatus && other);   // copy-move constructor

            ~TaskStatus ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            TaskStatus& operator= ( const TaskStatus &other ); // assignment operator

            TaskStatus& operator= ( TaskStatus && other ); // assignment-move operator

            // ====================  DATA MEMBERS  =======================================

            using Value = enum struct stateTaskSatus {null, in_progress, failed, successful};

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            static constexpr auto defaultDescription_ = "No description.";
            std::string taskDescription_;

            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class TaskStatus  -----


}; // namespace COMMUNICATOR

#endif   // ----- #ifndef Mouseion_TaskStatus_INC  ----- 
