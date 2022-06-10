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

        // ====================  OPERATORS     =======================================

        TaskGroup& operator=( const TaskGroup &other ) = delete; // assignment operator

        TaskGroup& operator=( TaskGroup && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskGroup  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_TaskGroup_INC  ----- */