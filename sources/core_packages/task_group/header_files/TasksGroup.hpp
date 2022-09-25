#ifndef  ANANSI_TasksGroup_INC
#define  ANANSI_TasksGroup_INC
//! @file TasksGroup.hpp
//!
//! The file contains the interface for the task groups.
//! 
//! All Anansi's task groups use class TaskGroup as the base class.  This class and
//! all derived classes can't be copied or assigned, but move-assignments or
//! move-copies are permitted.
//! 
//! TaskGroup and its derived classes use "The Curiously Recurring Template
//! Pattern" (CRTP) to achieve inheritance.

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

template<typename Derived>
class TasksGroup
{
    public:
        // ====================  LIFECYCLE     =======================================

        TasksGroup ()   // constructor
        {
            return;
        }

        TasksGroup (const TasksGroup & other)=0;   // copy constructor

        TasksGroup (TasksGroup && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method TasksGroup::TasksGroup  -----

        virtual ~TasksGroup ()=0; // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TasksGroup& operator= ( const TasksGroup &other )=0; // assignment operator

        TasksGroup& operator= ( TasksGroup && other ) // assignment-move operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment-move operator


    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================
        Derived& asDerived()
        {
            return *static_cast<Derived*>(this);
        }

        Derived const & asDerived() const
        {
            return *static_cast<Derived const*>(this);
        }

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TasksGroup  -----

template<typename Derived>
TasksGroup<Derived>::~TasksGroup()  // destructor
{
    return;
}


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_TasksGroup_INC  ----- 
