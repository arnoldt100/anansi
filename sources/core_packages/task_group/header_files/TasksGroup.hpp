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

        TasksGroup (const TasksGroup & other)=delete;   // copy constructor

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
        
        //! Enables the task group.
        void enable()
        {
            asDerived().enableTaskGroup();
            return;
        }

        //! Disables the task group.
        void disable()
        {
            asDerived().disenableTaskGroup();
            return;
        }

        // ====================  OPERATORS     =======================================

        TasksGroup& operator= ( const TasksGroup &other )=delete; // assignment operator

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

        // ====================  ACCESSORS     =======================================

        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to a constant CRTP derived class "Derived".
        Derived const & asDerived() const
        {
            return *static_cast<Derived const*>(this);
        }

        // ====================  MUTATORS      =======================================
        
        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to the CRTP derived class.
        Derived& asDerived()
        {
            return *static_cast<Derived*>(this);
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
